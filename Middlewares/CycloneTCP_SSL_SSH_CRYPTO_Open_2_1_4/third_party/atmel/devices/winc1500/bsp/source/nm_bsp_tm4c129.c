/**
 * @file nm_bsp_tm4c129.c
 * @brief BSP for TM4C129 microcontrollers
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2022 Oryx Embedded SARL. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.1.4
 **/

//TM4C1294NCPDT device?
#if defined(PART_TM4C1294NCPDT)
   #include "tm4c1294ncpdt.h"
//TM4C129XNCZAD device?
#elif defined(PART_TM4C129XNCZAD)
   #include "tm4c129xnczad.h"
#endif

//Dependencies
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "bsp/include/nm_bsp.h"
#include "common/include/nm_common.h"
#include "core/net.h"
#include "drivers/wifi/winc1500_driver.h"

//IRQ handler
static tpfNmBspIsr gpfIsr;


/**
 * @brief GPIO initialization
 **/

static void init_chip_pins(void)
{
   //Enable GPIO clocks
   SysCtlPeripheralEnable(CONF_WINC_RST_PERIPH);
   SysCtlPeripheralEnable(CONF_WINC_CE_PERIPH);
   SysCtlPeripheralEnable(CONF_WINC_WAKE_PERIPH);
   SysCtlPeripheralEnable(CONF_WINC_CS_PERIPH);
   SysCtlPeripheralEnable(CONF_WINC_IRQ_PERIPH);

   //Configure RST pin
   GPIOPinTypeGPIOOutput(CONF_WINC_RST_PORT, CONF_WINC_RST_PIN);

   GPIOPadConfigSet(CONF_WINC_RST_PORT, CONF_WINC_RST_PIN,
      CONF_WINC_RST_STRENGTH, GPIO_PIN_TYPE_STD);

   GPIOPinWrite(CONF_WINC_RST_PORT, CONF_WINC_RST_PIN, 0);

   //Configure CE pin
   GPIOPinTypeGPIOOutput(CONF_WINC_CE_PORT, CONF_WINC_CE_PIN);

   GPIOPadConfigSet(CONF_WINC_CE_PORT, CONF_WINC_CE_PIN,
      CONF_WINC_CE_STRENGTH, GPIO_PIN_TYPE_STD);

   GPIOPinWrite(CONF_WINC_CE_PORT, CONF_WINC_CE_PIN, 0);

   //Configure WAKE pin
   GPIOPinTypeGPIOOutput(CONF_WINC_WAKE_PORT, CONF_WINC_WAKE_PIN);

   GPIOPadConfigSet(CONF_WINC_WAKE_PORT, CONF_WINC_WAKE_PIN,
      CONF_WINC_WAKE_STRENGTH, GPIO_PIN_TYPE_STD);

   GPIOPinWrite(CONF_WINC_WAKE_PORT, CONF_WINC_WAKE_PIN, 0);

   //Configure CS pin
   GPIOPinTypeGPIOOutput(CONF_WINC_CS_PORT, CONF_WINC_CS_PIN);

   GPIOPadConfigSet(CONF_WINC_CS_PORT, CONF_WINC_CS_PIN,
      CONF_WINC_CS_STRENGTH, GPIO_PIN_TYPE_STD);

   GPIOPinWrite(CONF_WINC_CS_PORT, CONF_WINC_CS_PIN, CONF_WINC_CS_PIN);

   //Configure IRQ pin
   GPIOPinTypeGPIOInput(CONF_WINC_IRQ_PORT, CONF_WINC_IRQ_PIN);

   GPIOPadConfigSet(CONF_WINC_IRQ_PORT, CONF_WINC_IRQ_PIN,
      CONF_WINC_IRQ_STRENGTH, GPIO_PIN_TYPE_STD_WPU);
}


/**
 * @brief BSP initialization
 * @return Status code
 **/

sint8 nm_bsp_init(void)
{
   //Initialize IRQ handler
   gpfIsr = NULL;

   //Initialize WINC1500 pins
   init_chip_pins();

   //Reset WINC1500 chip
   nm_bsp_reset();

   //No error to report
   return M2M_SUCCESS;
}


/**
 * @brief Reset chip
 **/

void nm_bsp_reset(void)
{
   //Debug message
   M2M_PRINT("nm_bsp_reset\r\n");

   //Set CE and RST pins low
   GPIOPinWrite(CONF_WINC_CE_PORT, CONF_WINC_CE_PIN, 0);
   GPIOPinWrite(CONF_WINC_RST_PORT, CONF_WINC_RST_PIN, 0);
   nm_bsp_sleep(100);

   //Set CE pin high
   GPIOPinWrite(CONF_WINC_CE_PORT, CONF_WINC_CE_PIN, CONF_WINC_CE_PIN);
   nm_bsp_sleep(100);

   //Set RST pin high
   GPIOPinWrite(CONF_WINC_RST_PORT, CONF_WINC_RST_PIN, CONF_WINC_RST_PIN);
   nm_bsp_sleep(100);
}


/**
 * @brief Delay routine
 * @param[in] u32TimeMsec Time interval in milliseconds
 **/

void nm_bsp_sleep(uint32 u32TimeMsec)
{
   while(u32TimeMsec--)
   {
      sleep(1);
   }
}

/**
 * @brief Register interrupt service routine
 * @param[in] pfIsr ISR handler
 **/

void nm_bsp_register_isr(tpfNmBspIsr pfIsr)
{
   //Save ISR handler
   gpfIsr = pfIsr;

#if defined(NM_EDGE_INTERRUPT)
   //Enable falling edge detection
   GPIOIntTypeSet(CONF_WINC_IRQ_PORT, CONF_WINC_IRQ_INT_PIN,
      GPIO_FALLING_EDGE);
#elif defined(NM_LEVEL_INTERRUPT)
   //Enable low level detection
   GPIOIntTypeSet(CONF_WINC_IRQ_PORT, CONF_WINC_IRQ_INT_PIN,
      GPIO_LOW_LEVEL);
#endif

   //Enable interrupts for the IRQ pin
   GPIOIntEnable(CONF_WINC_IRQ_PORT, CONF_WINC_IRQ_INT_PIN);

   //Set priority grouping
   IntPriorityGroupingSet(CONF_WINC_IRQ_PRIORITY_GROUPING);

   //Configure external interrupt priority
   IntPrioritySet(CONF_WINC_IRQn, CONF_WINC_IRQ_PRIORITY);

   //Enable external interrupt
   IntEnable(CONF_WINC_IRQn);
   IntPendSet(CONF_WINC_IRQn);
}


/**
 * @brief Enable/disable interrupts
 * @param[in] u8Enable Interrupt enable state
 **/

void nm_bsp_interrupt_ctrl(uint8 u8Enable)
{
   if(u8Enable)
   {
      //Enable external interrupt
      IntEnable(CONF_WINC_IRQn);
   }
   else
   {
      //Disable external interrupt
      IntDisable(CONF_WINC_IRQn);
   }
}


/**
 * @brief IRQ handler
 **/

void CONF_WINC_IRQHandler(void)
{
   bool_t flag;
   uint32_t status;

   //Enter interrupt service routine
   osEnterIsr();

   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Get interrupt status
   status = GPIOIntStatus(CONF_WINC_IRQ_PORT, true);

   //Check interrupt status
   if((status & CONF_WINC_IRQ_INT_PIN) != 0)
   {
      //Clear interrupt flag
      GPIOIntClear(CONF_WINC_IRQ_PORT, CONF_WINC_IRQ_INT_PIN);

      //WINC1500 interrupt processing
      if(gpfIsr != NULL)
         gpfIsr();

      //Call interrupt handler
      flag = winc1500IrqHandler();
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
