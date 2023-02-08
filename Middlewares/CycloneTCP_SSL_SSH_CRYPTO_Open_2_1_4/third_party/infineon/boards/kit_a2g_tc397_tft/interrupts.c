/*====================================================================
* Project:  Board Support Package (BSP)
* Function: Handling of interrupts on TC39x
*
* Copyright HighTec EDV-Systeme GmbH 1982-2019
*====================================================================*/

#include <machine/wdtcon.h>
#include <machine/intrinsics.h>

#include "tc_inc_path.h"

#include TC_INCLUDE(TCPATH/IfxCpu_reg.h)
#include TC_INCLUDE(TCPATH/IfxCpu_bf.h)
#include TC_INCLUDE(TCPATH/IfxSrc_reg.h)

#include "cint.h"
#include "interrupts.h"

/* short form for marking data as not small addressable */
#ifndef _FARDATA
#define _FARDATA	__attribute__ ((fardata))
#endif /* _FARDATA */


/* Service Request Control register */
typedef union _Ifx_SRC_t
{
	volatile unsigned int R;
	struct _bits
	{
		volatile unsigned int SRPN   : 8;	/* [7:0] Service Request Priority Number (rw) */
		volatile unsigned int        : 2;
		volatile unsigned int SRE    : 1;	/* [10:10] Service Request Enable (rw) */
		volatile unsigned int TOS    : 3;	/* [13:11] Type of Service Control (rw) */
		volatile unsigned int        : 2;
		volatile unsigned int ECC    : 5;	/* [20:16] ECC (rwh) */
		volatile unsigned int        : 3;
		volatile unsigned int SRR    : 1;	/* [24:24] Service Request Flag (rh) */
		volatile unsigned int CLRR   : 1;	/* [25:25] Request Clear Bit (w) */
		volatile unsigned int SETR   : 1;	/* [26:26] Request Set Bit (w) */
		volatile unsigned int IOV    : 1;	/* [27:27] Interrupt Trigger Overflow Bit (rh) */
		volatile unsigned int IOVCLR : 1;	/* [28:28] Interrupt Trigger Overflow Clear Bit (w) */
		volatile unsigned int SWS    : 1;	/* [29:29] SW Sticky Bit (rh) */
		volatile unsigned int SWSCLR : 1;	/* [30:30] SW Sticky Clear Bit (w) */
		volatile unsigned int        : 1;
	} B;
} Ifx_SRC_t;


static Ifx_SRC_t * const tabSRC = (Ifx_SRC_t *)&MODULE_SRC;

#ifdef __TC39XX__
/* remark: CPU5 uses CORE_ID 6 !! */
#define MAX_CORES		(6 + 1)
#endif /* __TC39XX__ */

/* table for mapping CORE_IDs to TOS service providers */
static const _FARDATA int CoreTOSTab[MAX_CORES] =
{
	TOS_CPU0,	/* 0: CPU 0 */
	TOS_CPU1,	/* 1: CPU 1 */
	TOS_CPU2,	/* 2: CPU 2 */
	TOS_CPU3,	/* 3: CPU 3 */
	TOS_CPU4,	/* 4: CPU 4 */
	TOS_MAX,	/* 5: not used */
	TOS_CPU5,	/* 6: CPU 5 */
};


/*---------------------------------------------------------------------
	Function:	InterruptInit
	Purpose:	Initialisation of interrupt handling
	Arguments:	void
	Return:		void
---------------------------------------------------------------------*/
void InterruptInit(void)
{
	/* basic initialisation of vector tables */
	_init_vectab();
	/* enable external interrupts */
	_enable();
}

/*---------------------------------------------------------------------
	Function:	InterruptInstall
	Purpose:	Install a service handler for an interrupt
				(TOS field set to ID of caller CPU)
	Arguments:	int irqNum       - number of interrupt
				isrhnd_t isrProc - pointer to service routine
				int prio         - priority (1-255)
				int arg          - argument for service routine
	Return:		void
---------------------------------------------------------------------*/
void InterruptInstall(int irqNum, isrhnd_t isrProc, int prio, int arg)
{
	unsigned int coreId = _mfcr(CPU_CORE_ID) & IFX_CPU_CORE_ID_CORE_ID_MSK;

	InterruptInstallTOS(irqNum, isrProc, prio, CoreTOSTab[coreId], arg);
}

/*---------------------------------------------------------------------
	Function:	InterruptInstallTOS
	Purpose:	Install a service handler for an interrupt
	Arguments:	int irqNum       - number of interrupt
				isrhnd_t isrProc - pointer to service routine
				int prio         - priority (1-255) or DMA channel
				int tos	         - type of service (0-7)
				int arg          - argument for service routine
	Return:		void
---------------------------------------------------------------------*/
void InterruptInstallTOS(int irqNum, isrhnd_t isrProc, int prio, int tos, int arg)
{
	if ((irqNum < 0) || (IRQ_ID_MAX_NUM <= irqNum))
	{
		return;
	}

	/* check for CPU<n> as service provider */
	if ((tos <= MAX_CORES) && (tos != TOS_DMA))
	{
		/* install the service routine */
		_install_int_handler(prio, isrProc, arg);
		/* set processor and priority values */
		tabSRC[irqNum].B.TOS  = tos;
		tabSRC[irqNum].B.SRPN = prio;
	}
}

void InterruptEnable(int irqNum)
{
	tabSRC[irqNum].B.SRE = 1;
}

void InterruptDisable(int irqNum)
{
	tabSRC[irqNum].B.SRE = 0;
}
