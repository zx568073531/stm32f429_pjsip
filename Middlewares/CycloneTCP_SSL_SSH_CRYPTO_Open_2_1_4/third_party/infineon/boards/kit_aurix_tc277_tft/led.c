/*====================================================================
* Project:  Board Support Package (BSP)
* Function: LEDs
*
* Copyright HighTec EDV-Systeme GmbH 1982-2019
*====================================================================*/

#include "tc_inc_path.h"
#include TC_INCLUDE(TCPATH/Ifx_reg.h)
#include "led.h"

#define LED0_MASK (1 << 0)
#define LED1_MASK (1 << 1)
#define LED2_MASK (1 << 2)
#define LED3_MASK (1 << 3)

void LED_Init(int nr)
{
	if(nr == 0)
	{
		MODULE_P13.IOCR0.B.PC0 = 16;
	}
	else if(nr == 1)
	{
		MODULE_P13.IOCR0.B.PC1 = 16;
	}
	else if(nr == 2)
	{
		MODULE_P13.IOCR0.B.PC2 = 16;
	}
	else if(nr == 3)
	{
		MODULE_P13.IOCR0.B.PC3 = 16;
	}
	else
	{
	}
}

void LED_On(int nr)
{
	if(nr == 0)
	{
		MODULE_P13.OMR.U = LED0_MASK << 16;
	}
	else if(nr == 1)
	{
		MODULE_P13.OMR.U = LED1_MASK << 16;
	}
	else if(nr == 2)
	{
		MODULE_P13.OMR.U = LED2_MASK << 16;
	}
	else if(nr == 3)
	{
		MODULE_P13.OMR.U = LED3_MASK << 16;
	}
	else
	{
	}
}

void LED_Off(int nr)
{
	if(nr == 0)
	{
		MODULE_P13.OMR.U = LED0_MASK;
	}
	else if(nr == 1)
	{
		MODULE_P13.OMR.U = LED1_MASK;
	}
	else if(nr == 2)
	{
		MODULE_P13.OMR.U = LED2_MASK;
	}
	else if(nr == 3)
	{
		MODULE_P13.OMR.U = LED3_MASK;
	}
	else
	{
	}
}

void LED_Toggle(int nr)
{
	if(nr == 0)
	{
		MODULE_P13.OMR.U = LED0_MASK | (LED0_MASK << 16);
	}
	else if(nr == 1)
	{
		MODULE_P13.OMR.U = LED1_MASK | (LED1_MASK << 16);
	}
	else if(nr == 2)
	{
		MODULE_P13.OMR.U = LED2_MASK | (LED2_MASK << 16);
	}
	else if(nr == 3)
	{
		MODULE_P13.OMR.U = LED3_MASK | (LED3_MASK << 16);
	}
	else
	{
	}
}
