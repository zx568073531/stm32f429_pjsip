/*====================================================================
* Project:  Board Support Package (BSP)
* Function: LEDs
*
* Copyright HighTec EDV-Systeme GmbH 1982-2019
*====================================================================*/

#include "tc_inc_path.h"
#include TC_INCLUDE(TCPATH/Ifx_reg.h)
#include "led.h"

#define LED0_MASK (1 << 6)
#define LED1_MASK (1 << 7)
#define LED2_MASK (1 << 8)
#define LED3_MASK (1 << 9)
#define LED4_MASK (1 << 10)
#define LED5_MASK (1 << 11)
#define LED6_MASK (1 << 12)
#define LED7_MASK (1 << 13)

void LED_Init(int nr)
{
	if(nr == 0)
	{
		MODULE_P33.IOCR4.B.PC6 = 16;
	}
	else if(nr == 1)
	{
		MODULE_P33.IOCR4.B.PC7 = 16;
	}
	else if(nr == 2)
	{
		MODULE_P33.IOCR8.B.PC8 = 16;
	}
	else if(nr == 3)
	{
		MODULE_P33.IOCR8.B.PC9 = 16;
	}
	else if(nr == 4)
	{
		MODULE_P33.IOCR8.B.PC10 = 16;
	}
	else if(nr == 5)
	{
		MODULE_P33.IOCR8.B.PC11 = 16;
	}
	else if(nr == 6)
	{
		MODULE_P33.IOCR12.B.PC12 = 16;
	}
	else if(nr == 7)
	{
		MODULE_P33.IOCR12.B.PC13 = 16;
	}
	else
	{
	}
}

void LED_On(int nr)
{
	if(nr == 0)
	{
		MODULE_P33.OMR.U = LED0_MASK << 16;
	}
	else if(nr == 1)
	{
		MODULE_P33.OMR.U = LED1_MASK << 16;
	}
	else if(nr == 2)
	{
		MODULE_P33.OMR.U = LED2_MASK << 16;
	}
	else if(nr == 3)
	{
		MODULE_P33.OMR.U = LED3_MASK << 16;
	}
	else if(nr == 4)
	{
		MODULE_P33.OMR.U = LED4_MASK << 16;
	}
	else if(nr == 5)
	{
		MODULE_P33.OMR.U = LED5_MASK << 16;
	}
	else if(nr == 6)
	{
		MODULE_P33.OMR.U = LED6_MASK << 16;
	}
	else if(nr == 7)
	{
		MODULE_P33.OMR.U = LED7_MASK << 16;
	}
	else
	{
	}
}

void LED_Off(int nr)
{
	if(nr == 0)
	{
		MODULE_P33.OMR.U = LED0_MASK;
	}
	else if(nr == 1)
	{
		MODULE_P33.OMR.U = LED1_MASK;
	}
	else if(nr == 2)
	{
		MODULE_P33.OMR.U = LED2_MASK;
	}
	else if(nr == 3)
	{
		MODULE_P33.OMR.U = LED3_MASK;
	}
	else if(nr == 4)
	{
		MODULE_P33.OMR.U = LED4_MASK;
	}
	else if(nr == 5)
	{
		MODULE_P33.OMR.U = LED5_MASK;
	}
	else if(nr == 6)
	{
		MODULE_P33.OMR.U = LED6_MASK;
	}
	else if(nr == 7)
	{
		MODULE_P33.OMR.U = LED7_MASK;
	}
	else
	{
	}
}

void LED_Toggle(int nr)
{
	if(nr == 0)
	{
		MODULE_P33.OMR.U = LED0_MASK | (LED0_MASK << 16);
	}
	else if(nr == 1)
	{
		MODULE_P33.OMR.U = LED1_MASK | (LED1_MASK << 16);
	}
	else if(nr == 2)
	{
		MODULE_P33.OMR.U = LED2_MASK | (LED2_MASK << 16);
	}
	else if(nr == 3)
	{
		MODULE_P33.OMR.U = LED3_MASK | (LED3_MASK << 16);
	}
	else if(nr == 4)
	{
		MODULE_P33.OMR.U = LED4_MASK | (LED4_MASK << 16);
	}
	else if(nr == 5)
	{
		MODULE_P33.OMR.U = LED5_MASK | (LED5_MASK << 16);
	}
	else if(nr == 6)
	{
		MODULE_P33.OMR.U = LED6_MASK | (LED6_MASK << 16);
	}
	else if(nr == 7)
	{
		MODULE_P33.OMR.U = LED7_MASK | (LED7_MASK << 16);
	}
	else
	{
	}
}
