/**
 * @file nm_bus_wrapper_tm4c129.c
 * @brief SPI bus wrapper for TM4C129 microcontrollers
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
#include "driverlib/ssi.h"
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
   uint32_t data;

   //Pull the CS pin low
   GPIOPinWrite(CONF_WINC_CS_PORT, CONF_WINC_CS_PIN, 0);

   //Perform SPI transfer
   for(i = 0; i < u16Sz; i++)
   {
      //Full-duplex transfer?
      if(pu8Mosi != NULL)
         data = pu8Mosi[i];
      else
         data = 0x00;

      //Write character
      SSIDataPut(CONF_WINC_SSI, data);
      //Read character
      SSIDataGet(CONF_WINC_SSI, &data);

      //Save the received character
      if(pu8Miso != NULL)
         pu8Miso[i] = (uint8_t) data;
   }

   //CS hold time
   usleep(1);
   //Terminate the operation by raising the CS pin
   GPIOPinWrite(CONF_WINC_CS_PORT, CONF_WINC_CS_PIN, CONF_WINC_CS_PIN);

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
   //Enable GPIO clocks
   SysCtlPeripheralEnable(CONF_WINC_SCK_PERIPH);
   SysCtlPeripheralEnable(CONF_WINC_MOSI_PERIPH);
   SysCtlPeripheralEnable(CONF_WINC_MISO_PERIPH);

   //Enable SSI clock
   SysCtlPeripheralEnable(CONF_WINC_SSI_PERIPH);

   //Select the relevant alternate function for PA0 and PA1
   GPIOPinConfigure(CONF_WINC_SCK_CONFIG);
   GPIOPinConfigure(CONF_WINC_MOSI_CONFIG);
   GPIOPinConfigure(CONF_WINC_MISO_CONFIG);

   //Configure SCK
   GPIOPinTypeSSI(CONF_WINC_SCK_PORT, CONF_WINC_SCK_PIN);

   GPIOPadConfigSet(CONF_WINC_SCK_PORT, CONF_WINC_SCK_PIN,
      CONF_WINC_SCK_STRENGTH, GPIO_PIN_TYPE_STD);

   //Configure MOSI
   GPIOPinTypeSSI(CONF_WINC_MOSI_PORT, CONF_WINC_MOSI_PIN);

   GPIOPadConfigSet(CONF_WINC_MOSI_PORT, CONF_WINC_MOSI_PIN,
      CONF_WINC_MOSI_STRENGTH, GPIO_PIN_TYPE_STD);

   //Configure MISO
   GPIOPinTypeSSI(CONF_WINC_MISO_PORT, CONF_WINC_MISO_PIN);

   GPIOPadConfigSet(CONF_WINC_MISO_PORT, CONF_WINC_MISO_PIN,
      CONF_WINC_MISO_STRENGTH, GPIO_PIN_TYPE_STD_WPU);

   //Configure SSI module
   SSIConfigSetExpClk(CONF_WINC_SSI, SystemCoreClock,
      SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, CONF_WINC_SPI_CLOCK, 8);

   //Enable SSI module
   SSIEnable(CONF_WINC_SSI);

   //Reset WINC1500
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
#ifdef CONF_WINC_USE_SPI
   tstrNmSpiRw *spiRwParams;
#endif

   //Check commande opcode
   switch(u8Cmd)
   {
#ifdef CONF_WINC_USE_SPI
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
