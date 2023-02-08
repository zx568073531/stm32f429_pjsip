/**
 * @file nm_bsp_samd51.c
 * @brief BSP for SAMD51 microcontrollers
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

//Dependencies
#include "samd51.h"
#include "bsp/include/nm_bsp.h"
#include "common/include/nm_common.h"
#include "core/net.h"
#include "drivers/wifi/wilc1000_driver.h"

//IRQ handler
static tpfNmBspIsr gpfIsr;


/**
 * @brief GPIO initialization
 **/

static void init_chip_pins(void)
{
   //Enable PORT bus clock (CLK_PORT_APB)
   MCLK->APBBMASK.bit.PORT_ = 1;

   //Configure RST pin
   PORT->Group[CONF_WILC_RST_PIN / 32].DIRSET.reg = CONF_WILC_RST_MASK;
   PORT->Group[CONF_WILC_RST_PIN / 32].OUTCLR.reg = CONF_WILC_RST_MASK;

   //Configure CE pin
   PORT->Group[CONF_WILC_CE_PIN / 32].DIRSET.reg = CONF_WILC_CE_MASK;
   PORT->Group[CONF_WILC_CE_PIN / 32].OUTCLR.reg = CONF_WILC_CE_MASK;

   //Configure WAKE pin
   PORT->Group[CONF_WILC_WAKE_PIN / 32].DIRSET.reg = CONF_WILC_WAKE_MASK;
   PORT->Group[CONF_WILC_WAKE_PIN / 32].OUTCLR.reg = CONF_WILC_WAKE_MASK;

   //Configure CS pin
   PORT->Group[CONF_WILC_CS_PIN / 32].DIRSET.reg = CONF_WILC_CS_MASK;
   PORT->Group[CONF_WILC_CS_PIN / 32].OUTSET.reg = CONF_WILC_CS_MASK;
   PORT->Group[CONF_WILC_CS_PIN / 32].PINCFG[CONF_WILC_CS_PIN % 32].bit.DRVSTR = 1;

   //Configure IRQ pin
   PORT->Group[CONF_WILC_IRQ_PIN / 32].DIRCLR.reg = CONF_WILC_IRQ_MASK;
   PORT->Group[CONF_WILC_IRQ_PIN / 32].OUTSET.reg = CONF_WILC_IRQ_MASK;
   PORT->Group[CONF_WILC_IRQ_PIN / 32].PINCFG[CONF_WILC_IRQ_PIN % 32].bit.PULLEN = 1;
   PORT->Group[CONF_WILC_IRQ_PIN / 32].PINCFG[CONF_WILC_IRQ_PIN % 32].bit.INEN = 1;
   PORT->Group[CONF_WILC_IRQ_PIN / 32].PINCFG[CONF_WILC_IRQ_PIN % 32].bit.PMUXEN = 1;
   CONF_WILC_IRQ_MUX();
}


/**
 * @brief BSP initialization
 * @return Status code
 **/

sint8 nm_bsp_init(void)
{
   //Initialize IRQ handler
   gpfIsr = NULL;

   //Initialize WILC1000 pins
   init_chip_pins();

   //Reset WILC1000 chip
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
   PORT->Group[CONF_WILC_CE_PIN / 32].OUTCLR.reg = CONF_WILC_CE_MASK;
   PORT->Group[CONF_WILC_RST_PIN / 32].OUTCLR.reg = CONF_WILC_RST_MASK;
   nm_bsp_sleep(100);

   //Set CE pin high
   PORT->Group[CONF_WILC_CE_PIN / 32].OUTSET.reg = CONF_WILC_CE_MASK;
   nm_bsp_sleep(100);

   //Set RST pin high
   PORT->Group[CONF_WILC_RST_PIN / 32].OUTSET.reg = CONF_WILC_RST_MASK;
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

   //Enable EIC core clock
   GCLK->PCHCTRL[EIC_GCLK_ID].reg = GCLK_PCHCTRL_GEN_GCLK0 | GCLK_PCHCTRL_CHEN;

   //Enable EIC bus clock (CLK_EIC_APB)
   MCLK->APBAMASK.bit.EIC_ = 1;

   //Configure the EIC input sense and filtering
   CONF_WILC_IRQ_CONFIG();

   //Enable the EIC
   EIC->CTRLA.bit.ENABLE = 1;

   //Enabling and disabling the EIC requires synchronization
   while(EIC->SYNCBUSY.bit.ENABLE);

   //Enable external interrupts
   EIC->INTENSET.reg = CONF_WILC_IRQ_MASK;

   //Set priority grouping
   NVIC_SetPriorityGrouping(CONF_WILC_IRQ_PRIORITY_GROUPING);

   //Configure EIC interrupt priority
   NVIC_SetPriority(CONF_WILC_IRQn, NVIC_EncodePriority(CONF_WILC_IRQ_PRIORITY_GROUPING,
      CONF_WILC_IRQ_GROUP_PRIORITY, CONF_WILC_IRQ_SUB_PRIORITY));

   //Enable EIC interrupt
   NVIC_EnableIRQ(CONF_WILC_IRQn);
   NVIC_SetPendingIRQ(CONF_WILC_IRQn);
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
      NVIC_EnableIRQ(CONF_WILC_IRQn);
   }
   else
   {
      //Disable external interrupt
      NVIC_DisableIRQ(CONF_WILC_IRQn);
   }
}


/**
 * @brief IRQ handler
 **/

void CONF_WILC_IRQHandler(void)
{
   bool_t flag;

   //Enter interrupt service routine
   osEnterIsr();

   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Clear interrupt flag
   EIC->INTFLAG.reg = CONF_WILC_IRQ_MASK;

   //Ensure the IRQ pin is asserted
   if(!(PORT->Group[CONF_WILC_IRQ_PIN / 32].IN.reg & CONF_WILC_IRQ_MASK))
   {
      //WILC1000 interrupt processing
      if(gpfIsr != NULL)
         gpfIsr();

      //Call interrupt handler
      flag = wilc1000IrqHandler();
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
