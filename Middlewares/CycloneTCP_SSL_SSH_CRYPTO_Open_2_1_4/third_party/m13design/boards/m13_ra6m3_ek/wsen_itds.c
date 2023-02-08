/**
 * @file wsen_itds.c
 * @brief Wurth Elektronik WSEN-ITDS 3-axis acceleration sensor
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
#include <stdint.h>
#include <stdbool.h>
#include "bsp_api.h"
#include "wsen_itds.h"
#include "error.h"
#include "debug.h"

//I2C slave address
#define WSEN_ITDS_SLAVE_ADDR_W 0x32
#define WSEN_ITDS_SLAVE_ADDR_R 0x33

//SCL pin (P2_4)
#define SCL_MASK (1 << 4)
#define SCL_PORT R_PORT2
#define SCL_PFS PORT[2].PIN[4].PmnPFS

//SDA pin (P4_7)
#define SDA_MASK (1 << 7)
#define SDA_PORT R_PORT4
#define SDA_PFS PORT[4].PIN[7].PmnPFS

//Macros
#define SCL_OUT(a) SCL_PORT->PCNTR3 = SCL_MASK << ((a) ? 0 : R_PORT0_PCNTR3_PORR_Pos)
#define SDA_OUT(a) SDA_PORT->PCNTR3 = SDA_MASK << ((a) ? 0 : R_PORT0_PCNTR3_PORR_Pos)
#define SDA_IN() ((SDA_PORT->PCNTR2 & SDA_MASK) ? 1 : 0)


/**
 * @brief WSEN-ITDS initialization
 * @return Error code (see #ErrorCode enumeration)
 **/

error_t wsenItdsInit(void)
{
   error_t error;
   uint8_t value;

   //Debug message
   TRACE_INFO("Initializing WSEN-ITDS...\r\n");

   //I2C initialization
   i2cInit();

   //Read DEVICE_ID register
   error = wsenItdsReadReg(WSEN_ITDS_DEVICE_ID, &value);
   //Any error to report?
   if(error)
      return error;

   //Verify device identifier
   if(value != WSEN_ITDS_DEVICE_ID_DEFAULT)
      return ERROR_INVALID_VERSION;

   //Set normal operation mode
   error = wsenItdsWriteReg(WSEN_ITDS_CTRL_1, WSEN_ITDS_CTRL_1_ODR_400_HZ |
      WSEN_ITDS_CTRL_1_MODE_NORMAL | WSEN_ITDS_CTRL_1_LP_MODE_NORMAL);
   //Any error to report?
   if(error)
      return error;

   //Enable block data update and address auto increment
   error = wsenItdsWriteReg(WSEN_ITDS_CTRL_2, WSEN_ITDS_CTRL_2_BDU |
      WSEN_ITDS_CTRL_2_IF_ADD_INC);
   //Any error to report?
   if(error)
      return error;

   //Select bandwidth and full scale
   error = wsenItdsWriteReg(WSEN_ITDS_CTRL_6, WSEN_ITDS_CTRL_6_BW_FILT_ODR_DIV_2 |
      WSEN_ITDS_CTRL_6_FS_2G);
   //Any error to report?
   if(error)
      return error;

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Get acceleration data
 * @param[out] ax Acceleration value (X axis)
 * @param[out] ay Acceleration value (Y axis)
 * @param[out] az Acceleration value (Z axis)
 * @param[in] data Register value
 * @return Error code (see #ErrorCode enumeration)
 **/

error_t wsenItdsGetAcc(int8_t *ax, int8_t *ay, int8_t *az)
{
   error_t error;

   //Issue a start condition
   i2cStart();

   //Send I2C slave address
   error = i2cWrite(WSEN_ITDS_SLAVE_ADDR_W);

   //Check status code
   if(!error)
   {
      //Write register address
      error = i2cWrite(WSEN_ITDS_X_OUT_L);
   }

   //Check status code
   if(!error)
   {
      //Issue a repeated start condition
      i2cRepeatedStart();

      //Send I2C slave address
      error = i2cWrite(WSEN_ITDS_SLAVE_ADDR_R);

      //Check status code
      if(!error)
      {
         //Read X-axis acceleration value (LSB)
         i2cRead(TRUE);
         //Read X-axis acceleration value (MSB)
         *ax = (int8_t) i2cRead(TRUE);

         //Read Y-axis acceleration value (LSB)
         i2cRead(TRUE);
         //Read Y-axis acceleration value (MSB)
         *ay = (int8_t) i2cRead(TRUE);

         //Read Z-axis acceleration value (LSB)
         i2cRead(TRUE);
         //Read Z-axis acceleration value (MSB)
         *az = (int8_t) i2cRead(FALSE);
      }
   }

   //Issue a stop condition
   i2cStop();

   //Return status code
   return error;
}


/**
 * @brief Write WSEN-ITDS register
 * @param[in] address Register address
 * @param[in] data Register value
 * @return Error code (see #ErrorCode enumeration)
 **/

error_t wsenItdsWriteReg(uint8_t address, uint8_t data)
{
   error_t error;

   //Issue a start condition
   i2cStart();

   //Send I2C slave address
   error = i2cWrite(WSEN_ITDS_SLAVE_ADDR_W);

   //Check status code
   if(!error)
   {
      //Write register address
      error = i2cWrite(address);
   }

   //Check status code
   if(!error)
   {
      //Write register value
      error = i2cWrite(data);
   }

   //Issue a stop condition
   i2cStop();

   //Return status code
   return error;
}


/**
 * @brief Read WSEN-ITDS register
 * @param[in] address Register address
 * @param[out] data Register value
 * @return Error code (see #ErrorCode enumeration)
 **/

error_t wsenItdsReadReg(uint8_t address, uint8_t *data)
{
   error_t error;

   //Issue a start condition
   i2cStart();

   //Send I2C slave address
   error = i2cWrite(WSEN_ITDS_SLAVE_ADDR_W);

   //Check status code
   if(!error)
   {
      //Write register address
      error = i2cWrite(address);
   }

   //Check status code
   if(!error)
   {
      //Issue a repeated start condition
      i2cRepeatedStart();

      //Send I2C slave address
      error = i2cWrite(WSEN_ITDS_SLAVE_ADDR_R);

      //Check status code
      if(!error)
      {
         //Read register value
         *data = i2cRead(FALSE);
      }
   }

   //Issue a stop condition
   i2cStop();

   //Return status code
   return error;
}


/**
 * @brief I2C initialization
 **/

void i2cInit(void)
{
   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure SCL pin
   R_PFS->SCL_PFS = R_PFS_PORT_PIN_PmnPFS_NCODR_Msk |
      R_PFS_PORT_PIN_PmnPFS_PDR_Msk | R_PFS_PORT_PIN_PmnPFS_PODR_Msk;

   //Configure SDA pin
   R_PFS->SDA_PFS = R_PFS_PORT_PIN_PmnPFS_NCODR_Msk |
      R_PFS_PORT_PIN_PmnPFS_PDR_Msk | R_PFS_PORT_PIN_PmnPFS_PODR_Msk;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;
}


/**
 * @brief I2C delay
 **/

void i2cDelay(void)
{
   volatile uint_t delay;

   //Delay loop
   for(delay = 0; delay < 500; delay++)
   {
   }
}


/**
 * @brief I2C start condition
 **/

void i2cStart(void)
{
   SDA_OUT(1);
   SCL_OUT(1);
   i2cDelay();

   //Pull SDA to low level
   SDA_OUT(0);
   i2cDelay();

   //Pull SCL to low level
   SCL_OUT(0);
   i2cDelay();
}


/**
 * @brief I2C stop condition
 **/

void i2cStop(void)
{
   SDA_OUT(0);
   i2cDelay();

   //Release SCL
   SCL_OUT(1);
   i2cDelay();

   //Release SDA
   SDA_OUT(1);
   i2cDelay();
}


/**
 * @brief I2C repeated start condition
 **/

void i2cRepeatedStart(void)
{
   //Release SDA
   SDA_OUT(1);
   i2cDelay();

   //Release SCL
   SCL_OUT(1);
   i2cDelay();

   //Pull SDA to low level
   SDA_OUT(0);
   i2cDelay();

   //Pull SCL to low level
   SCL_OUT(0);
   i2cDelay();
}


/**
 * @brief I2C write operation
 * @param[in] data Data byte to be written
 * @return Error code
 **/

error_t i2cWrite(uint8_t data)
{
   error_t error;
   uint_t i;

   //Iterate 8 times
   for(i = 0; i < 8; i++)
   {
      //Set SDA state
      if(data & 0x80)
      {
         SDA_OUT(1);
      }
      else
      {
         SDA_OUT(0);
      }

      //Pulse SCL
      i2cDelay();
      SCL_OUT(1);
      i2cDelay();
      SCL_OUT(0);
      i2cDelay();

      //Shift data byte
      data <<= 1;
   }

   //Release SDA in order to read ACK bit
   SDA_OUT(1);
   i2cDelay();

   //Set SCL to high level
   SCL_OUT(1);
   i2cDelay();

   //Retrieve ACK value
   if(SDA_IN())
   {
      error = ERROR_FAILURE;
   }
   else
   {
      error = NO_ERROR;
   }

   //Pull SCL to low level
   SCL_OUT(0);
   i2cDelay();

   //Return status code
   return error;
}


/**
 * @brief I2C read operation
 * @param[out] ack ACK value
 * @return Data byte resulting from the read operation
 **/

uint8_t i2cRead(bool_t ack)
{
   uint_t i;
   uint8_t data;

   //Clear data
   data = 0;

   //Release SDA
   SDA_OUT(1);
   i2cDelay();

   //Iterate 8 times
   for(i = 0; i < 8; i++)
   {
      //Shift data byte
      data <<= 1;

      //Set SCL to high level
      SCL_OUT(1);
      i2cDelay();

      //Retrieve bit value
      if(SDA_IN())
      {
         data |= 1;
      }

      //Pull SCL to low level
      SCL_OUT(0);
      i2cDelay();
   }

   //Write ACK bit
   if(ack)
   {
      SDA_OUT(0);
   }
   else
   {
      SDA_OUT(1);
   }

   //Pulse SCL
   i2cDelay();
   SCL_OUT(1);
   i2cDelay();
   SCL_OUT(0);
   i2cDelay();

   //Return data byte
   return data;
}
