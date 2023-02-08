/*====================================================================
* Project:  Board Support Package (BSP)
* Function: Extended system control API implementation for TC39x
*           (based on PLS original sources)
*           (adapted by HighTec for correct frequency up stepping)
*
* Copyright HighTec EDV-Systeme GmbH 1982-2019
*====================================================================*/

#include <machine/intrinsics.h>
#include <machine/wdtcon.h>
#ifdef USE_IRQ
#include "interrupts.h"
#endif /* USE_IRQ */

#include "system_tc3x.h"

#include "tc_inc_path.h"

#include TC_INCLUDE(TCPATH/IfxScu_reg.h)
#include TC_INCLUDE(TCPATH/IfxScu_bf.h)
#include TC_INCLUDE(TCPATH/IfxCpu_reg.h)
#include TC_INCLUDE(TCPATH/IfxCpu_bf.h)
#include TC_INCLUDE(TCPATH/IfxStm_reg.h)
#include TC_INCLUDE(TCPATH/IfxStm_bf.h)
#include TC_INCLUDE(TCPATH/IfxDmu_reg.h)

#if (RUN_ON_APPKIT == 0)
# if (RUN_ON_PHYCORE == 0)
/* Workaround for TLF35584 on TriBoard-TC3xx */
#  define USE_DISABLE_EXT_WDT		1
# endif /* RUN_ON_PHYCORE == 0 */
#else
/* AppKit-TC397: TLF35584 or TLF30682 (ADAS) is disabled (per default) */
# define USE_DISABLE_EXT_WDT		0
#endif /* RUN_ON_APPKIT == 0 */

#if (USE_DISABLE_EXT_WDT == 1)
# include TC_INCLUDE(TCPATH/IfxPort_reg.h)
# include TC_INCLUDE(TCPATH/IfxQspi_reg.h)
#endif /* USE_DISABLE_EXT_WDT */

#ifdef __TC39XX__
/* remark: CPU5 uses CORE_ID 6 !! */
# define MAX_CORES		(6 + 1)
#endif /* __TC39XX__ */


typedef struct _PllInitValue_t
{
	unsigned int valOSCCON;
	unsigned int valSYSPLLCON0;
	unsigned int valSYSPLLCON1;	/* first step K dividers */
	unsigned int valCCUCON0;
	unsigned int valCCUCON1;
	unsigned int valCCUCON2;
	unsigned int finalK;		/* final K2DIV value */
	unsigned int valPERPLLCON0;
	unsigned int valPERPLLCON1;
} PllInitValue_t;

static const PllInitValue_t g_PllInitValue_300_100;
#define PLL_VALUE_300_100 ((const PllInitValue_t *)(&g_PllInitValue_300_100))

static const PllInitValue_t g_PllInitValue_200_100;
#define PLL_VALUE_200_100 ((const PllInitValue_t *)(&g_PllInitValue_200_100))

static const PllInitValue_t g_PllInitValue_100_50;
#define PLL_VALUE_100_50  ((const PllInitValue_t *)(&g_PllInitValue_100_50))


#ifndef DEFAULT_PLL_VALUE
# define DEFAULT_PLL_VALUE		PLL_VALUE_200_100
#endif

#ifndef EXTCLK
# define EXTCLK		(20000000)	/* external oscillator clock (20MHz) */
#endif



#pragma section ".rodata"
/* PLL settings for 20MHz ext. clock */
#if (20000000 == EXTCLK)

/* 300/100 MHz @ 20MHz ext. clock */
static const PllInitValue_t g_PllInitValue_300_100 =
{
	/* OSCCON,	SYSPLLCON0,	SYSPLLCON1,	CCUCON0,	CCUCON1,	CCUCON2,    finalK,	PERPLLCON0,	PERPLLCON1 */
	0x0005001C, 0x41057600, 0x00000005, 0x17230133, 0x21120013, 0x00001201, 1,		0x00053E00,	0x00000101
};

/* 200/100 MHz @ 20MHz ext. clock */
static const PllInitValue_t g_PllInitValue_200_100 =
{
	/* OSCCON,	SYSPLLCON0,	SYSPLLCON1,	CCUCON0,	CCUCON1,	CCUCON2,    finalK,	PERPLLCON0,	PERPLLCON1 */
	0x0005001C, 0x41057600, 0x00000005, 0x16220122, 0x21120012, 0x00001201, 2,		0x00053E00,	0x00000101
};

/* 100/50 MHz @ 20MHz ext. clock */
static const PllInitValue_t g_PllInitValue_100_50 =
{
	/* OSCCON,	SYSPLLCON0,	SYSPLLCON1,	CCUCON0,	CCUCON1,	CCUCON2,    finalK,	PERPLLCON0,	PERPLLCON1 */
	0x0005001C, 0x41058a00, 0x00000006, 0x16220122, 0x21120011, 0x00001201, 6,		0x00053E00,	0x00000101
};
#else
#error "ERROR: UNSUPPORTED EXTERNAL CLOCK!"
#endif /* PLL settings for 20MHz ext. clock */
#pragma section


static Ifx_SCU * const pSCU = (Ifx_SCU *)&MODULE_SCU;


#if (USE_DISABLE_EXT_WDT == 1)

#define WDT_CMD_SIZE			10

static void disable_external_watchdog(void)
{
	int i;

	/* command sequence for disabling external watchdog */
	const unsigned short wdtdiscmd[WDT_CMD_SIZE] =
	{
		0x8756, 0x87de, 0x86ad, 0x8625,		/* unprotect register (PROTCFG) */
		0x8d27,								/* disable window watchdog */
		0x8A01,								/* disable err pin monitor */
		0x87be, 0x8668, 0x877d, 0x8795		/* protect register (PROTCFG) */
	};

	/* check that this disabling has not been already done (e.g. by the debugger) */
	if (QSPI2_GLOBALCON.B.EN)
	{
		/* don't do it again */
		return;
	}

	/* initialise QSPI2 interface */
	unlock_wdtcon();				/* remove ENDINIT protection */
	QSPI2_CLC.U = 0x8;				/* activate module, disable sleep mode */
	(void)QSPI2_CLC.U;				/* read back to get effective */
	P15_PDR0.U = 0x00000000;		/* fast speed (all pins) */
	P14_PDR0.U = 0x00000000;		/* fast speed (all pins) */
	QSPI2_PISEL.U = 1;				/* MRIS=1 ==> use MRST2B pin */
	lock_wdtcon();					/* re-enable ENDINIT protection */

	/* configure port pins */
	P14_IOCR0.B.PC2 = 0x13;			/* SLSO21 */
	P15_IOCR0.B.PC3 = 0x13;			/* SCLK2 */
	P15_IOCR4.B.PC6 = 0x13;			/* MTSR2 */
	P15_IOCR4.B.PC7 = 0x02;			/* MRST2B */

	/* program QSPI2 parameters */
	QSPI2_GLOBALCON.U = 0x60003C04;	/* RESETS=1,CLKSEL=fPER,EXPECT=15,SI=0, TQ=4 */
	QSPI2_GLOBALCON1.U = 0x14000000;/* RXFM=1,TXFM=1 (Single Move Mode for RX/TX) */
	QSPI2_SSOC.U = 0x00020000;		/* enable SLSO21, low active */
	QSPI2_ECON1.U = 0x501;			/* Q=1,A=0,B=1,C=1 */

	do
	{
		QSPI2_FLAGSCLEAR.U = 0xFFF;	/* PT2F,PT1F,RXF,TXF,ERRORFLAGS */
	} while (QSPI2_STATUS.U & 0xFFF);

	/* prepare data transfer format */
	QSPI2_BACONENTRY.U = 0x17A10001;	/* CS=1,DL=15,MSB=1,TRAIL=1,LAST=1 */

	QSPI2_GLOBALCON.B.EN = 1;		/* ... and enable the module */

	/* transfer all data */
	for (i = 0; i < WDT_CMD_SIZE; ++i)
	{
		/* clear TX flag (before writing) */
		QSPI2_FLAGSCLEAR.U = 1 << 9;
		/* write new data */
		QSPI2_DATAENTRY0.U = (unsigned int)wdtdiscmd[i];
		/* wait until transfer is complete */
		while (!QSPI2_STATUS.B.TXF)
			;
		/* wait for receive is finished */
		while (!QSPI2_STATUS.B.RXF)
			;
		/* clear RX flag */
		QSPI2_FLAGSCLEAR.U = 1 << 10;
		/* read and discard value */
		(void)QSPI2_RXEXIT.U;
	}
}
#endif /* USE_DISABLE_EXT_WDT */

#ifndef SYSTEM_DONT_SET_PLL

/* STM time scaling (for avoiding overflow) */
#define TIME_SCALE_DN		1000
#define TIME_SCALE_UP		(1000000 / TIME_SCALE_DN)

/* wait for <time> micro seconds */
/* beware of overflows: 100 us at (>=)43 MHz will overflow (if not scaled before multiplying) */
static void wait(unsigned int time)
{
	unsigned int fSTM = (unsigned int)SYSTEM_GetStmClock();
	unsigned int stmWaitCount = (fSTM / TIME_SCALE_DN) * time / TIME_SCALE_UP;

	/* prepare compare register */
	STM0_CMP0.U = STM0_TIM0.U + stmWaitCount;
	STM0_CMCON.U = 31;
	/* Attention: keep this order, otherwise first match will trigger too soon */
	/* reset interrupt flag */
	STM0_ISCR.U = (IFX_STM_ISCR_CMP0IRR_MSK << IFX_STM_ISCR_CMP0IRR_OFF);
	/* enable compare match */
	STM0_ICR.B.CMP0EN = 1;
	/* wait for compare match */
	while (0 == STM0_ICR.B.CMP0IR)
		;
	STM0_ICR.B.CMP0EN = 0;
}

static void system_set_pll(const PllInitValue_t *pPllInitValue)
{
	unsigned int k;

#if 0 /* we are currently using the default settings */
	/* ToDo: adapt the correct values for TC3x */
	/* prepare flash waitstates */
	if (pPllInitValue == PLL_VALUE_300_100)
	{
		unlock_wdtcon();
		DMU_HF_PWAIT.B.RECC = (3 - 1);		/* 3 WS for ECC */
		DMU_HF_PWAIT.B.RFLASH = (9 - 1);	/* 9 WS for Flash */
		lock_wdtcon();
	}
	else if (pPllInitValue == PLL_VALUE_200_100)
	{
		unlock_wdtcon();
		DMU_HF_PWAIT.B.RECC = (2 - 1);		/* 2 WS for ECC */
		DMU_HF_PWAIT.B.RFLASH = (6 - 1);	/* 6 WS for Flash */
		lock_wdtcon();
	}
#endif

	unlock_safety_wdtcon();

	/* check whether we are running from backup clock (if not force it to this clock) */
	if (0 != pSCU->CCUCON0.B.CLKSEL)
	{
		Ifx_SCU_CCUCON0 ccucon0 = pSCU->CCUCON0;
		ccucon0.B.CLKSEL	= 0;	/* Select the EVR as fsource0/1/2 for the clock distribution */
		ccucon0.B.UP		= 1;	/* Update the ccucon0 register */

		while (pSCU->CCUCON0.B.LCK)
			;

		pSCU->CCUCON0.U = ccucon0.U;

		while (pSCU->CCUCON0.B.LCK)
			;
	}

	/* check: SYSPLL and PERPLL in powerdown mode; force it */
	if (0 == pSCU->SYSPLLSTAT.B.PWDSTAT)
	{
		/* power down (avoid glitches during update) */
		pSCU->SYSPLLCON0.B.PLLPWD = 0;
		/* wait until power down mode reached */
		while (0 == pSCU->SYSPLLSTAT.B.PWDSTAT)
			;
	}
	if (0 == pSCU->PERPLLSTAT.B.PWDSTAT)
	{
		/* power down (avoid glitches during update) */
		pSCU->PERPLLCON0.B.PLLPWD = 0;
		/* wait until power down mode reached */
		while (0 == pSCU->PERPLLSTAT.B.PWDSTAT)
			;
	}

	/* setup the oscillator */
	pSCU->OSCCON.U = pPllInitValue->valOSCCON;

	lock_safety_wdtcon();

	/* we need some delay here (Ifx sources use 5 ms) */
	/* without this delay startup on TriBoard-TC3x7 is not reliable */
	wait(5000);

	/* wait until PLLLV and PLLHV flags are set */
	while ((pSCU->OSCCON.B.PLLLV == 0) || (pSCU->OSCCON.B.PLLHV == 0))
		;

	unlock_safety_wdtcon();
	/* setup SYSPLL (incl. power up) */
	pSCU->SYSPLLCON0.U = pPllInitValue->valSYSPLLCON0;				/* set P,N divider */
	/* setup PERPLL (incl. power up) */
	pSCU->PERPLLCON0.U = pPllInitValue->valPERPLLCON0;				/* set P,N divider */
	/* wait until power up is finished */
	while ((1 == pSCU->SYSPLLSTAT.B.PWDSTAT) || (1 == pSCU->PERPLLSTAT.B.PWDSTAT))
		;

	/* wait until SYSPLL K2 operation is stable */
	while (0 == pSCU->SYSPLLSTAT.B.K2RDY)
		;
	pSCU->SYSPLLCON1.U =  pPllInitValue->valSYSPLLCON1;				/* set K2 divider */
	/* wait until SYSPLL K2 operation is stable */
	while (0 == pSCU->SYSPLLSTAT.B.K2RDY)
		;

	/* wait until PERPLL K2 and K3 operation is stable */
	while ((0 == pSCU->PERPLLSTAT.B.K2RDY) || (0 == pSCU->PERPLLSTAT.B.K3RDY))
		;
	pSCU->PERPLLCON1.U = pPllInitValue->valPERPLLCON1;				/* set K2,K3 divider */
	/* wait until PERPLL K2 and K3 operation is stable */
	while ((0 == pSCU->PERPLLSTAT.B.K2RDY) || (0 == pSCU->PERPLLSTAT.B.K3RDY))
		;

	/* restart SYSPLL and PERPLL locking (with latest settings) */
	pSCU->SYSPLLCON0.B.RESLD = 1;
	pSCU->PERPLLCON0.B.RESLD = 1;
	/* wait for SYSPLL and PERPLL locked */
	while ((0 == pSCU->SYSPLLSTAT.B.LOCK) || (0 == pSCU->PERPLLSTAT.B.LOCK))
		;

	/* setup CCU dividers */
	while (pSCU->CCUCON1.B.LCK)
		;
	pSCU->CCUCON1.U = pPllInitValue->valCCUCON1;

	while (pSCU->CCUCON2.B.LCK)
		;
	pSCU->CCUCON2.U = pPllInitValue->valCCUCON2;

	while (pSCU->CCUCON0.B.LCK)
		;
	pSCU->CCUCON0.U =  pPllInitValue->valCCUCON0 | (1 << IFX_SCU_CCUCON0_UP_OFF);

	lock_safety_wdtcon();

	/* wait for SYSPLL locked */
	while ((0 == pSCU->SYSPLLSTAT.B.LOCK))
		;

	/* update K dividers for stepping up to final clock */
	k = pSCU->SYSPLLCON1.B.K2DIV;
	/* wait some time (100 us) */
	wait(100);
	while (k > pPllInitValue->finalK)
	{
		Ifx_SCU_SYSPLLCON1 pllcon1 = pSCU->SYSPLLCON1;

		--k;
		/* prepare value to write */
		pllcon1.B.K2DIV = k;
		/* wait until K2 operation is stable */
		while (0 == pSCU->SYSPLLSTAT.B.K2RDY)
			;
		unlock_safety_wdtcon();
		pSCU->SYSPLLCON1 = pllcon1;
		lock_safety_wdtcon();
		/* wait some time (100 us) */
		wait(100);
	}
}
#endif

/*! \brief System initialisation
 *  \param pPllInitValue ... address of PLL initialisation struct
 */
static void SYSTEM_InitExt(const PllInitValue_t *pPllInitValue)
{
#ifndef SYSTEM_DONT_SET_PLL
	/* initialise PLL (only done by CPU0) */
	if (0 == (_mfcr(CPU_CORE_ID) & IFX_CPU_CORE_ID_CORE_ID_MSK))
		system_set_pll(pPllInitValue);
#endif

#ifdef USE_IRQ
	/* activate interrupt system */
	InterruptInit();
#endif /* USE_IRQ */
}

void SYSTEM_Init(void)
{
	SYSTEM_InitExt(DEFAULT_PLL_VALUE);

#if (USE_DISABLE_EXT_WDT == 1)
	disable_external_watchdog();
#endif /* USE_DISABLE_EXT_WDT */
}

unsigned long SYSTEM_GetExtClock(void)
{
	return EXTCLK;
}

static unsigned long system_GetPllClock(void)
{
	unsigned int frequency = EXTCLK;	/* fOSC */

	Ifx_SCU_SYSPLLCON0 pllcon0 = pSCU->SYSPLLCON0;
	Ifx_SCU_SYSPLLCON1 pllcon1 = pSCU->SYSPLLCON1;

#if (RUN_ON_TC39XA == 1)
	if (0 == (pSCU->SYSPLLSTAT.B.BY))
#else
	if (1)
#endif /* RUN_ON_TC39XA == 1 */
	{
		/* normal mode */
		frequency *= (pllcon0.B.NDIV + 1);		/* fOSC*N */
		frequency /= (pllcon0.B.PDIV + 1);		/* .../P  */
		frequency /= (pllcon1.B.K2DIV + 1);		/* .../K2 */
	}

	return (unsigned long)frequency;
}

static unsigned long system_GetIntClock(void)
{
	unsigned long frequency = 0;
	switch (pSCU->CCUCON0.B.CLKSEL)
	{
		default:
		case 0:  /* back-up clock (typ. 100 MHz) */
			frequency = 100000000ul;
			break;
		case 1:	 /* fPLL */
			frequency = system_GetPllClock();
			break;
	}
	return frequency;
}

unsigned long SYSTEM_GetCpuClock(void)
{
	unsigned long frequency = system_GetIntClock();
	/* fCPU = fSRI */
	unsigned long divider = pSCU->CCUCON0.B.SRIDIV;
	unsigned long cpudiv = 0;
	if (0 == divider)
		return 0;
	frequency /= divider;

	/* determine correct CPU<n>DIV field */
	switch ((_mfcr(CPU_CORE_ID) & IFX_CPU_CORE_ID_CORE_ID_MSK))
	{
		case 0 : cpudiv = pSCU->CCUCON6.B.CPU0DIV; break;
		case 1 : cpudiv = pSCU->CCUCON7.B.CPU1DIV; break;
		case 2 : cpudiv = pSCU->CCUCON8.B.CPU2DIV; break;
		case 3 : cpudiv = pSCU->CCUCON9.B.CPU3DIV; break;
		case 4 : cpudiv = pSCU->CCUCON10.B.CPU4DIV; break;
		case 6 : cpudiv = pSCU->CCUCON11.B.CPU5DIV; break;
	}

	if (cpudiv != 0)
	{
		frequency *= (64 - cpudiv);
		frequency /= 64;
	}

	return frequency;
}

unsigned long SYSTEM_GetSysClock(void)
{
	unsigned long frequency = system_GetIntClock();
	unsigned long divider = pSCU->CCUCON0.B.SPBDIV;
	if (0 == divider)
		return 0;
	return (frequency / divider);
}

unsigned long SYSTEM_GetStmClock(void)
{
	unsigned long frequency = system_GetIntClock();
	unsigned long divider = pSCU->CCUCON0.B.STMDIV;
	if (0 == divider)
		return 0;
	return (frequency / divider);
}

unsigned long SYSTEM_GetCanClock(void)
{
	unsigned long frequency = system_GetIntClock();
	unsigned long divider = pSCU->CCUCON1.B.MCANDIV;
	if (0 == divider)
		return 0;
	return (frequency / divider);
}

void SYSTEM_EnableInterrupts(void)
{
	_enable();
}

void SYSTEM_DisableInterrupts(void)
{
	_disable();
}

void SYSTEM_EnableProtection(void)
{
	lock_wdtcon();
}

void SYSTEM_DisableProtection(void)
{
	unlock_wdtcon();
}

void SYSTEM_EnableProtectionExt(int Sel)
{
	if (Sel < MAX_CORES)
		lock_wdtcon();			/* CPU watchdog */
	else
		lock_safety_wdtcon();	/* safety watchdog */
}

void SYSTEM_DisableProtectionExt(int Sel)
{
	if (Sel < MAX_CORES)
		unlock_wdtcon();		/* CPU watchdog */
	else
		unlock_safety_wdtcon();	/* safety watchdog */
}

void SYSTEM_EnableSecProtection(void)
{
	lock_safety_wdtcon();
}

void SYSTEM_DisableSecProtection(void)
{
	unlock_safety_wdtcon();
}


int SYSTEM_Reset(void)
{
	/* AURIX 2G: SCU_SWRSTCON is NOT SE (ONLY E) protected (!?) */
	unlock_wdtcon();
	pSCU->SWRSTCON.B.SWRSTREQ = 1;
	while (1)
		;
	return 0;
}


int SYSTEM_IdleExt(int CoreId)
{
#if (RUN_ON_TC39XA == 1)
	/* order of these register is inverted: 3,4,5 is in front of 0,1,2 */
	int index;

	switch (CoreId)
	{
		case 0 :
		case 1 :
		case 2 :
			index = CoreId + 3;
			break;
		case 3 :
		case 4 :
			index = CoreId - 3;
			break;
		case 6 :
			index = 2;
			break;

		default:
			return 0;
	}

	unlock_wdtcon();
	pSCU->PMCSR[index].U = 1;	/* request CPU idle mode */
	lock_wdtcon();
#else
	Ifx_SCU_PMCSR0 *pmcsr = (Ifx_SCU_PMCSR0 *)&pSCU->PMCSR0;
	int index = (CoreId == 6) ? 5 : CoreId;

	unlock_wdtcon();
	pmcsr[index].U = 1;			/* request CPU idle mode */
	lock_wdtcon();
#endif /* RUN_ON_TC39XA */

	return 0;
}

int SYSTEM_Idle(void)
{
	return SYSTEM_IdleExt(_mfcr(CPU_CORE_ID) & IFX_CPU_CORE_ID_CORE_ID_MSK);
}

int SYSTEM_Sleep(void)
{
	int CoreId = _mfcr(CPU_CORE_ID) & IFX_CPU_CORE_ID_CORE_ID_MSK;
#if (RUN_ON_TC39XA == 1)
	/* order of these register is inverted: 3,4,5 is in front of 0,1,2 */
	int index;

	switch (CoreId)
	{
		case 0 :
		case 1 :
		case 2 :
			index = CoreId + 3;
			break;
		case 3 :
		case 4 :
			index = CoreId - 3;
			break;
		case 6 :
			index = 2;
			break;

		default:
			return 0;
	}

	unlock_wdtcon();
	pSCU->PMCSR[index].U = 2;	/* request system sleep mode */
	lock_wdtcon();
#else
	Ifx_SCU_PMCSR0 *pmcsr = (Ifx_SCU_PMCSR0 *)&pSCU->PMCSR0;
	int index = (CoreId == 6) ? 5 : CoreId;

	unlock_wdtcon();
	pmcsr[index].U = 2;		/* request system sleep mode */
	lock_wdtcon();
#endif /* RUN_ON_TC39XA */

	return 0;
}


int SYSTEM_IsCacheEnabled(void)
{
	unsigned int ui = _mfcr(CPU_PCON0);
	if (ui & 2)
		return 0;	/* Cache is in bypass mode */
	ui = _mfcr(CPU_PCON2);
	if (0 == (ui & (IFX_CPU_PCON2_PCACHE_SZE_MSK << IFX_CPU_PCON2_PCACHE_SZE_OFF)))
		return 0;	/* Cache size is 0 */
	return 1;
}

void SYSTEM_EnaDisCache(int Enable)
{
	unlock_wdtcon();
	if (Enable)
	{
		_mtcr(CPU_PCON0, 0);
		_mtcr(CPU_DCON0, 0);
	}
	else	/* disable */
	{
		_mtcr(CPU_PCON0, 2);
		_mtcr(CPU_PCON1, 3);
		_mtcr(CPU_DCON0, 2);
	}
	lock_wdtcon();
}

void SYSTEM_DbgBreak(void)
{
#ifdef DEBUG
	__asm volatile ("debug");
#else
	while (1)
		;
#endif
}
