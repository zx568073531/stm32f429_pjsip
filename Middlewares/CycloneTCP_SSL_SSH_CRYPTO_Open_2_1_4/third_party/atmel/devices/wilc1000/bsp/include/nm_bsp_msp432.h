/**
 * @file nm_bsp_msp432.h
 * @brief BSP for MSP432 microcontrollers
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

#ifndef _NM_BSP_MSP432_H_
#define _NM_BSP_MSP432_H_

//Dependencies
#include "wilc1000_config.h"
#include "debug.h"

//Interrupt type
#define NM_LEVEL_INTERRUPT 1
//Debug logs
#define NM_DEBUG           CONF_WILC_DEBUG
//Debug output redirection
#define NM_BSP_PRINTF      CONF_WILC_PRINTF

#endif
