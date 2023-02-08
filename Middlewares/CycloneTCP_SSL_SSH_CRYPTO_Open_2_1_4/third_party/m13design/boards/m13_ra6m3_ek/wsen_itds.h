/**
 * @file wsen_itds.h
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

#ifndef _WSEN_ITDS_H
#define _WSEN_ITDS_H

//Dependencies
#include "os_port.h"
#include "error.h"

//WSEN-ITDS registers
#define WSEN_ITDS_T_OUT_L                       0x0D
#define WSEN_ITDS_T_OUT_H                       0x0E
#define WSEN_ITDS_DEVICE_ID                     0x0F
#define WSEN_ITDS_CTRL_1                        0x20
#define WSEN_ITDS_CTRL_2                        0x21
#define WSEN_ITDS_CTRL_3                        0x22
#define WSEN_ITDS_CTRL_4                        0x23
#define WSEN_ITDS_CTRL_5                        0x24
#define WSEN_ITDS_CTRL_6                        0x25
#define WSEN_ITDS_T_OUT                         0x26
#define WSEN_ITDS_STATUS                        0x27
#define WSEN_ITDS_X_OUT_L                       0x28
#define WSEN_ITDS_X_OUT_H                       0x29
#define WSEN_ITDS_Y_OUT_L                       0x2A
#define WSEN_ITDS_Y_OUT_H                       0x2B
#define WSEN_ITDS_Z_OUT_L                       0x2C
#define WSEN_ITDS_Z_OUT_H                       0x2D
#define WSEN_ITDS_FIFO_CTRL                     0x2E
#define WSEN_ITDS_FIFO_SAMPLES                  0x2F
#define WSEN_ITDS_TAP_X_TH                      0x30
#define WSEN_ITDS_TAP_Y_TH                      0x31
#define WSEN_ITDS_TAP_Z_TH                      0x32
#define WSEN_ITDS_INT_DUR                       0x33
#define WSEN_ITDS_WAKE_UP_TH                    0x34
#define WSEN_ITDS_WAKE_UP_DUR                   0x35
#define WSEN_ITDS_FREE_FALL                     0x36
#define WSEN_ITDS_STATUS_DETECT                 0x37
#define WSEN_ITDS_WAKE_UP_EVENT                 0x38
#define WSEN_ITDS_TAP_EVENT                     0x39
#define WSEN_ITDS_6D_EVENT                      0x3A
#define WSEN_ITDS_ALL_INT_EVENT                 0x3B
#define WSEN_ITDS_X_OFS_USR                     0x3C
#define WSEN_ITDS_Y_OFS_USR                     0x3D
#define WSEN_ITDS_Z_OFS_USR                     0x3E
#define WSEN_ITDS_CTRL_7                        0x3F

//T_OUT_L register
#define WSEN_ITDS_T_OUT_L_TEMP                  0xF0

//T_OUT_H register
#define WSEN_ITDS_T_OUT_H_TEMP                  0xFF

//DEVICE_ID register
#define WSEN_ITDS_DEVICE_ID_DEFAULT             0x44

//CTRL_1 register
#define WSEN_ITDS_CTRL_1_ODR                    0xF0
#define WSEN_ITDS_CTRL_1_ODR_POWER_DOWN         0x00
#define WSEN_ITDS_CTRL_1_ODR_1_6_HZ             0x10
#define WSEN_ITDS_CTRL_1_ODR_12_5_HZ            0x20
#define WSEN_ITDS_CTRL_1_ODR_25_HZ              0x30
#define WSEN_ITDS_CTRL_1_ODR_50_HZ              0x40
#define WSEN_ITDS_CTRL_1_ODR_100_HZ             0x50
#define WSEN_ITDS_CTRL_1_ODR_200_HZ             0x60
#define WSEN_ITDS_CTRL_1_ODR_400_HZ             0x70
#define WSEN_ITDS_CTRL_1_ODR_800_HZ             0x80
#define WSEN_ITDS_CTRL_1_ODR_1600_HZ            0x90
#define WSEN_ITDS_CTRL_1_MODE                   0x0C
#define WSEN_ITDS_CTRL_1_MODE_NORMAL            0x00
#define WSEN_ITDS_CTRL_1_MODE_HIGH_PERF         0x04
#define WSEN_ITDS_CTRL_1_MODE_SINGLE            0x08
#define WSEN_ITDS_CTRL_1_LP_MODE                0x03
#define WSEN_ITDS_CTRL_1_LP_MODE_LOW_POWER      0x00
#define WSEN_ITDS_CTRL_1_LP_MODE_NORMAL         0x01

//CTRL_2 register
#define WSEN_ITDS_CTRL_2_BOOT                   0x80
#define WSEN_ITDS_CTRL_2_SOFT_RESET             0x40
#define WSEN_ITDS_CTRL_2_CP_PU_DISC             0x10
#define WSEN_ITDS_CTRL_2_BDU                    0x08
#define WSEN_ITDS_CTRL_2_IF_ADD_INC             0x04
#define WSEN_ITDS_CTRL_2_I2C_DISABLE            0x02

//CTRL_3 register
#define WSEN_ITDS_CTRL_3_ST                     0xC0
#define WSEN_ITDS_CTRL_3_PP_OD                  0x20
#define WSEN_ITDS_CTRL_3_LIR                    0x10
#define WSEN_ITDS_CTRL_3_H_LACTIVE              0x08
#define WSEN_ITDS_CTRL_3_SLP_MODE_SEL           0x02
#define WSEN_ITDS_CTRL_3_SLP_MODE_1             0x01

//CTRL_4 register
#define WSEN_ITDS_CTRL_4_INT0_6D                0x80
#define WSEN_ITDS_CTRL_4_INT0_SINGLE_TAP        0x40
#define WSEN_ITDS_CTRL_4_INT0_WU                0x20
#define WSEN_ITDS_CTRL_4_INT0_FF                0x10
#define WSEN_ITDS_CTRL_4_INT0_TAP               0x08
#define WSEN_ITDS_CTRL_4_INT0_DIFF5             0x04
#define WSEN_ITDS_CTRL_4_INT0_FTH               0x02
#define WSEN_ITDS_CTRL_4_INT0_DRDY              0x01

//CTRL_5 register
#define WSEN_ITDS_CTRL_5_INT1_SLEEP_STATE       0x80
#define WSEN_ITDS_CTRL_5_INT1_SLEEP_CHG         0x40
#define WSEN_ITDS_CTRL_5_INT1_BOOT              0x20
#define WSEN_ITDS_CTRL_5_INT1_DRDY_T            0x10
#define WSEN_ITDS_CTRL_5_INT1_OVR               0x08
#define WSEN_ITDS_CTRL_5_INT1_DIFF5             0x04
#define WSEN_ITDS_CTRL_5_INT1_FTH               0x02
#define WSEN_ITDS_CTRL_5_INT1_DRDY              0x01

//CTRL_6 register
#define WSEN_ITDS_CTRL_6_BW_FILT                0xC0
#define WSEN_ITDS_CTRL_6_BW_FILT_ODR_DIV_2      0x00
#define WSEN_ITDS_CTRL_6_BW_FILT_ODR_DIV_4      0x40
#define WSEN_ITDS_CTRL_6_BW_FILT_ODR_DIV_10     0x80
#define WSEN_ITDS_CTRL_6_BW_FILT_ODR_DIV_20     0xC0
#define WSEN_ITDS_CTRL_6_FS                     0x30
#define WSEN_ITDS_CTRL_6_FS_2G                  0x00
#define WSEN_ITDS_CTRL_6_FS_4G                  0x10
#define WSEN_ITDS_CTRL_6_FS_8G                  0x20
#define WSEN_ITDS_CTRL_6_FS_16G                 0x30
#define WSEN_ITDS_CTRL_6_FDS                    0x08
#define WSEN_ITDS_CTRL_6_LOW_NOISE              0x04

//T_OUT register
#define WSEN_ITDS_T_OUT_TEMP                    0xFF

//STATUS register
#define WSEN_ITDS_STATUS_FIFO_THS               0x80
#define WSEN_ITDS_STATUS_WU_IA                  0x40
#define WSEN_ITDS_STATUS_SLEEP_STATE            0x20
#define WSEN_ITDS_STATUS_DOUBLE_TAP             0x10
#define WSEN_ITDS_STATUS_SINGLE_TAP             0x08
#define WSEN_ITDS_STATUS_6D_IA                  0x04
#define WSEN_ITDS_STATUS_FF_IA                  0x02
#define WSEN_ITDS_STATUS_DRDY                   0x01

//X_OUT_L register
#define WSEN_ITDS_X_OUT_L_X_L_3_0               0xF0
#define WSEN_ITDS_X_OUT_L_X_L_1_0               0x0C

//X_OUT_H register
#define WSEN_ITDS_X_OUT_H_X_H                   0xFF

//Y_OUT_L register
#define WSEN_ITDS_Y_OUT_L_Y_L_3_0               0xF0
#define WSEN_ITDS_Y_OUT_L_Y_L_1_0               0x0C

//Y_OUT_H register
#define WSEN_ITDS_Y_OUT_H_Y_H                   0xFF

//Z_OUT_L register
#define WSEN_ITDS_Z_OUT_L_Z_L_3_0               0xF0
#define WSEN_ITDS_Z_OUT_L_Z_L_1_0               0x0C

//Z_OUT_H register
#define WSEN_ITDS_Z_OUT_H_Z_H                   0xFF

//FIFO_CTRL register
#define WSEN_ITDS_FIFO_CTRL_FMODE               0xE0
#define WSEN_ITDS_FIFO_CTRL_FTH                 0x1F

//FIFO_SAMPLES register
#define WSEN_ITDS_FIFO_SAMPLES_FIFO_FTH         0x80
#define WSEN_ITDS_FIFO_SAMPLES_FIFO_OVR         0x40
#define WSEN_ITDS_FIFO_SAMPLES_DIFF             0x3F

//TAP_X_TH register
#define WSEN_ITDS_TAP_X_TH_4D_EN                0x80
#define WSEN_ITDS_TAP_X_TH_6D_TH                0x60
#define WSEN_ITDS_TAP_X_TH_TAP_THSX             0x1F

//TAP_Y_TH register
#define WSEN_ITDS_TAP_Y_TH_TAP_PRIOR            0xE0
#define WSEN_ITDS_TAP_Y_TH_TAP_THSY             0x1F

//TAP_Z_TH register
#define WSEN_ITDS_TAP_Z_TH_TAP_X_EN             0x80
#define WSEN_ITDS_TAP_Z_TH_TAP_Y_EN             0x40
#define WSEN_ITDS_TAP_Z_TH_TAP_Z_EN             0x20
#define WSEN_ITDS_TAP_Z_TH_TAP_THSZ             0x1F

//INT_DUR register
#define WSEN_ITDS_INT_DUR_LATENCY               0xF0
#define WSEN_ITDS_INT_DUR_QUIET                 0x0C
#define WSEN_ITDS_INT_DUR_SCHOCK                0x03

//WAKE_UP_TH register
#define WSEN_ITDS_WAKE_UP_TH_SINGLE_DOUBLE_TAP  0x80
#define WSEN_ITDS_WAKE_UP_TH_SLEEP_ON           0x40
#define WSEN_ITDS_WAKE_UP_TH_WK_TH              0x3F

//WAKE_UP_DUR register
#define WSEN_ITDS_WAKE_UP_DUR_FF_DUR_5          0x80
#define WSEN_ITDS_WAKE_UP_DUR_WAKE_DUR          0x60
#define WSEN_ITDS_WAKE_UP_DUR_STATIONARY        0x10
#define WSEN_ITDS_WAKE_UP_DUR_SLEEP_DUR         0x0F

//FREE_FALL register
#define WSEN_ITDS_FREE_FALL_FF_DUR_4_0          0xF8
#define WSEN_ITDS_FREE_FALL_FF_TH               0x07

//STATUS_DETECT register
#define WSEN_ITDS_STATUS_DETECT_OVR             0x80
#define WSEN_ITDS_STATUS_DETECT_DRDY_T          0x40
#define WSEN_ITDS_STATUS_DETECT_SLEEP_STATE_IA  0x20
#define WSEN_ITDS_STATUS_DETECT_DOUBLE_TAP      0x10
#define WSEN_ITDS_STATUS_DETECT_SINGLE_TAP      0x08
#define WSEN_ITDS_STATUS_DETECT_6D_IA           0x04
#define WSEN_ITDS_STATUS_DETECT_FF_IA           0x02
#define WSEN_ITDS_STATUS_DETECT_DRDY            0x01

//WAKE_UP_EVENT register
#define WSEN_ITDS_WAKE_UP_EVENT_FF_IA           0x20
#define WSEN_ITDS_WAKE_UP_EVENT_WU_IA           0x08
#define WSEN_ITDS_WAKE_UP_EVENT_X_WU            0x04
#define WSEN_ITDS_WAKE_UP_EVENT_Y_WU            0x02
#define WSEN_ITDS_WAKE_UP_EVENT_Z_WU            0x01

//TAP_EVENT register
#define WSEN_ITDS_TAP_EVENT_TAP_IA              0x40
#define WSEN_ITDS_TAP_EVENT_SINGLE_TAP          0x20
#define WSEN_ITDS_TAP_EVENT_DOUBLE_TAP          0x10
#define WSEN_ITDS_TAP_EVENT_TAP_SIGN            0x08
#define WSEN_ITDS_TAP_EVENT_X_TAP               0x04
#define WSEN_ITDS_TAP_EVENT_Y_TAP               0x02
#define WSEN_ITDS_TAP_EVENT_Z_TAP               0x01

//6D_EVENT register
#define WSEN_ITDS_6D_EVENT_6D_IA                0x40
#define WSEN_ITDS_6D_EVENT_ZH                   0x20
#define WSEN_ITDS_6D_EVENT_ZL                   0x10
#define WSEN_ITDS_6D_EVENT_YH                   0x08
#define WSEN_ITDS_6D_EVENT_YL                   0x04
#define WSEN_ITDS_6D_EVENT_XH                   0x02
#define WSEN_ITDS_6D_EVENT_XL                   0x01

//ALL_INT_EVENT register
#define WSEN_ITDS_ALL_INT_EVENT_SLEEP_CHANGE_IA 0x20
#define WSEN_ITDS_ALL_INT_EVENT_6D_IA           0x10
#define WSEN_ITDS_ALL_INT_EVENT_DOUBLE_TAP      0x08
#define WSEN_ITDS_ALL_INT_EVENT_SINGLE_TAP      0x04
#define WSEN_ITDS_ALL_INT_EVENT_WU_IA           0x02
#define WSEN_ITDS_ALL_INT_EVENT_FF_IA           0x01

//X_OFS_USR register
#define WSEN_ITDS_X_OFS_USR_X_OFS_USR           0xFF

//Y_OFS_USR register
#define WSEN_ITDS_Y_OFS_USR_Y_OFS_USR           0xFF

//Z_OFS_USR register
#define WSEN_ITDS_Z_OFS_USR_Z_OFS_USR           0xFF

//CTRL_7 register
#define WSEN_ITDS_CTRL_7_DRDY_PULSED            0x80
#define WSEN_ITDS_CTRL_7_INTERRUPTS_ENABLE      0x20
#define WSEN_ITDS_CTRL_7_USR_OFF_ON_OUT         0x10
#define WSEN_ITDS_CTRL_7_USR_OFF_ON_WU          0x08
#define WSEN_ITDS_CTRL_7_USR_OFF_W              0x04
#define WSEN_ITDS_CTRL_7_HP_REF_MODE            0x02
#define WSEN_ITDS_CTRL_7_LPASS_ON6D             0x01

//WSEN-ITDS related functions
error_t wsenItdsInit(void);
error_t wsenItdsGetAcc(int8_t *ax, int8_t *ay, int8_t *az);
error_t wsenItdsWriteReg(uint8_t address, uint8_t data);
error_t wsenItdsReadReg(uint8_t address, uint8_t *data);

//I2C related functions
void i2cInit(void);
void i2cDelay(void);
void i2cStart(void);
void i2cStop(void);
void i2cRepeatedStart(void);
error_t i2cWrite(uint8_t data);
uint8_t i2cRead(bool_t ack);

#endif
