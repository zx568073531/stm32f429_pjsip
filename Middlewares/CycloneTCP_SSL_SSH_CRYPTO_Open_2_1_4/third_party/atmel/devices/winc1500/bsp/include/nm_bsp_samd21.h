/**
 * @file nm_bsp_samd21.h
 * @brief BSP for SAMD21 microcontrollers
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

#ifndef _NM_BSP_SAMD21_H_
#define _NM_BSP_SAMD21_H_

//Dependencies
#include "winc1500_config.h"
#include "debug.h"

//Interrupt type
#define NM_LEVEL_INTERRUPT 1
//Ethernet mode
#define ETH_MODE

//Data in pinout
#if (CONF_WINC_MISO_PAD >= 0 && CONF_WINC_MISO_PAD <= 3)
   #define CONF_WINC_SERCOM_DIPO CONF_WINC_MISO_PAD
#else
   #error SERCOM pinout is not valid
#endif

//Data out pinout
#if (CONF_WINC_SCK_PAD == 1 && CONF_WINC_MOSI_PAD == 0)
   #define CONF_WINC_SERCOM_DOPO 0
#elif (CONF_WINC_SCK_PAD == 3 && CONF_WINC_MOSI_PAD == 2)
   #define CONF_WINC_SERCOM_DOPO 1
#elif (CONF_WINC_SCK_PAD == 1 && CONF_WINC_MOSI_PAD == 3)
   #define CONF_WINC_SERCOM_DOPO 2
#elif (CONF_WINC_SCK_PAD == 3 && CONF_WINC_MOSI_PAD == 0)
   #define CONF_WINC_SERCOM_DOPO 3
#else
   #error SERCOM pinout is not valid
#endif

#endif
