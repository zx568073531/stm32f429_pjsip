/**
 * @file nm_bus_wrapper_samd51.c
 * @brief SPI bus wrapper for SAMD51 microcontrollers
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
#include <stdio.h>
#include "samd51.h"
#include "bsp/include/nm_bsp.h"
#include "common/include/nm_common.h"
#include "bus_wrapper/include/nm_bus_wrapper.h"

//Maximum transfer size
#define NM_BUS_MAX_TRX_SZ 4096


/**
 * @brief Bus capabilities information
 **/

tstrNmBusCapabilities egstrNmBusCapabilities =
{
   NM_BUS_MAX_TRX_SZ
};


/**
 * @brief SPI transfer
 * @param[in] pu8Mosi The data to be written to the slave device
 * @param[out] pu8Miso The data received from the slave device
 * @param[in] u16Sz Number of bytes to be transferred
 * @return Status code (M2M_SUCCESS or M2M_ERR_BUS_FAIL)
 **/

static sint8 spi_rw(uint8 *pu8Mosi, uint8 *pu8Miso, uint16 u16Sz)
{
   uint16_t i;
   uint8_t data;

   //Pull the CS pin low
   PORT->Group[CONF_WILC_CS_PIN / 32].OUTCLR.reg = CONF_WILC_CS_MASK;

   //Perform SPI transfer
   for(i = 0; i < u16Sz; i++)
   {
      //Full-duplex transfer?
      if(pu8Mosi != NULL)
         data = pu8Mosi[i];
      else
         data = 0x00;

      //Ensure the TX buffer is empty
      while(!CONF_WILC_SERCOM->SPI.INTFLAG.bit.DRE);
      //Write character
      CONF_WILC_SERCOM->SPI.DATA.bit.DATA = data;
      //Wait for the operation to complete
      while(!CONF_WILC_SERCOM->SPI.INTFLAG.bit.RXC);
      //Read character
      data = CONF_WILC_SERCOM->SPI.DATA.bit.DATA;

      //Save the received character
      if(pu8Miso != NULL)
         pu8Miso[i] = data;
   }

   //Terminate the operation by raising the CS pin
   PORT->Group[CONF_WILC_CS_PIN / 32].OUTSET.reg = CONF_WILC_CS_MASK;

   //Successful operation
   return M2M_SUCCESS;
}


/**
 * @brief SPI bus initialization
 * @param[in] pvinit Unused parameter
 * @return Status code (M2M_SUCCESS or M2M_ERR_BUS_FAIL)
 **/

sint8 nm_bus_init(void *pvinit)
{
   //Enable SERCOM core clock
   GCLK->PCHCTRL[CONF_WILC_SERCOM_GCLK_ID_CORE].reg = GCLK_PCHCTRL_GEN_GCLK0 |
      GCLK_PCHCTRL_CHEN;

   //Enable PORT bus clock (CLK_PORT_APB)
   MCLK->APBBMASK.bit.PORT_ = 1;
   //Enable SERCOM bus clock (CLK_SERCOM_APB)
   CONF_WILC_SERCOM_APB_CLK_EN();

   //Configure SCK pin
   PORT->Group[CONF_WILC_SCK_PIN / 32].PINCFG[CONF_WILC_SCK_PIN % 32].bit.DRVSTR = 1;
   PORT->Group[CONF_WILC_SCK_PIN / 32].PINCFG[CONF_WILC_SCK_PIN % 32].bit.PMUXEN = 1;
   CONF_WILC_SCK_MUX();

   //Configure MOSI pin
   PORT->Group[CONF_WILC_MOSI_PIN / 32].PINCFG[CONF_WILC_MOSI_PIN % 32].bit.DRVSTR = 1;
   PORT->Group[CONF_WILC_MOSI_PIN / 32].PINCFG[CONF_WILC_MOSI_PIN % 32].bit.PMUXEN = 1;
   CONF_WILC_MOSI_MUX();

   //Configure MISO pin
   PORT->Group[CONF_WILC_MISO_PIN / 32].PINCFG[CONF_WILC_MISO_PIN % 32].bit.DRVSTR = 1;
   PORT->Group[CONF_WILC_MISO_PIN / 32].PINCFG[CONF_WILC_MISO_PIN % 32].bit.PMUXEN = 1;
   CONF_WILC_MISO_MUX();

   //Perform software reset
   CONF_WILC_SERCOM->SPI.CTRLA.reg = SERCOM_SPI_CTRLA_SWRST;

   //Resetting the SERCOM (CTRLA.SWRST) requires synchronization
   while(CONF_WILC_SERCOM->SPI.SYNCBUSY.reg & SERCOM_SPI_SYNCBUSY_SWRST);

   //Select master mode operation
   CONF_WILC_SERCOM->SPI.CTRLA.reg = SERCOM_SPI_CTRLA_DIPO(CONF_WILC_SERCOM_DIPO) |
      SERCOM_SPI_CTRLA_DOPO(CONF_WILC_SERCOM_DOPO) | SERCOM_SPI_CTRLA_MODE(3);

   //Configure clock divider
   CONF_WILC_SERCOM->SPI.BAUD.reg = SystemCoreClock / (2 * CONF_WILC_SPI_CLOCK) - 1;

   //Enable the receiver
   CONF_WILC_SERCOM->SPI.CTRLB.reg = SERCOM_SPI_CTRLB_RXEN;

   //Writing to the CTRLB register when the SERCOM is enabled requires
   //synchronization
   while(CONF_WILC_SERCOM->USART.SYNCBUSY.reg & SERCOM_USART_SYNCBUSY_CTRLB);

   //Enable SERCOM
   CONF_WILC_SERCOM->SPI.CTRLA.reg |= SERCOM_SPI_CTRLA_ENABLE;

   //Enabling and disabling the SERCOM requires synchronization
   while(CONF_WILC_SERCOM->SPI.SYNCBUSY.reg & SERCOM_SPI_SYNCBUSY_ENABLE);

   //Reset WILC1000
   nm_bsp_reset();

   //Successful operation
   return M2M_SUCCESS;
}


/**
 * @brief IOCTL command processing
 * @param[in] u8Cmd Command opcode
 * @param[in] pvParameter Command parameters
 * @return Status code (M2M_SUCCESS or M2M_ERR_BUS_FAIL)
 **/

sint8 nm_bus_ioctl(uint8 u8Cmd, void *pvParameter)
{
   sint8 ret;
#ifdef CONF_WILC_USE_SPI
   tstrNmSpiRw *spiRwParams;
#endif

   //Check commande opcode
   switch(u8Cmd)
   {
#ifdef CONF_WILC_USE_SPI
   //Read/write command?
   case NM_BUS_IOCTL_RW:
      //Retrieve command parameters
      spiRwParams = (tstrNmSpiRw *) pvParameter;
      //Perform SPI transfer
      ret = spi_rw(spiRwParams->pu8InBuf, spiRwParams->pu8OutBuf, spiRwParams->u16Sz);
      break;
#endif
   //Invalid command?
   default:
      //Debug message
      M2M_ERR("Invalid IOCTL command!\r\n");
      //Report an error
      ret = M2M_ERR_BUS_FAIL;
      break;
   }

   //Return status code
   return ret;
}


/**
 * @brief SPI bus deinitialization
 * @param[in] pvinit Unused parameter
 * @return Status code (M2M_SUCCESS or M2M_ERR_BUS_FAIL)
 **/

sint8 nm_bus_deinit(void)
{
   //Not implemented
   return M2M_SUCCESS;
}
