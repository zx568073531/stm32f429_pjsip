/**
 * @file usbd_conf.h
 * @brief USB device low-level configuration
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2022 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
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

#ifndef _USBD_CONF_H
#define _USBD_CONF_H

//Dependencies
#include "stm32f4xx_hal.h"

//Settings
#define USBD_MAX_NUM_INTERFACES     1
#define USBD_MAX_NUM_CONFIGURATION  1
#define USBD_MAX_STR_DESC_SIZ       256
#define USBD_SUPPORT_USER_STRING    0
#define USBD_SELF_POWERED           1
#define USBD_DEBUG_LEVEL            0

//Debug macros
#if (USBD_DEBUG_LEVEL > 0)
   #define USBD_UsrLog(...) printf(__VA_ARGS__); printf("\r\n");
#else
   #define USBD_UsrLog(...)
#endif

#if (USBD_DEBUG_LEVEL > 1)
   #define USBD_ErrLog(...) printf("ERROR: "); printf(__VA_ARGS__); printf("\r\n");
#else
   #define USBD_ErrLog(...)
#endif

#if (USBD_DEBUG_LEVEL > 2)
   #define USBD_DbgLog(...) printf("DEBUG: "); printf(__VA_ARGS__); printf("\r\n");
#else
   #define USBD_DbgLog(...)
#endif

#endif
