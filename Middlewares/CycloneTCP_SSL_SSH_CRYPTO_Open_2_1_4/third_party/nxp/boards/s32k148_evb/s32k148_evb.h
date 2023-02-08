/**
 * @file s32k148_evb.h
 * @brief S32K148-EVB evaluation board
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

#ifndef _S32K148_EVB_H
#define _S32K148_EVB_H

//Dependencies
#include "s32k148.h"

//Red LED
#define LED_R_POS    21
#define LED_R_MASK   (1 << LED_R_POS)
#define PORT_LED_R   PORTE
#define GPIO_LED_R   PTE

//Green LED
#define LED_G_POS    22
#define LED_G_MASK   (1 << LED_G_POS)
#define PORT_LED_G   PORTE
#define GPIO_LED_G   PTE

//Blue LED
#define LED_B_POS    23
#define LED_B_MASK   (1 << LED_B_POS)
#define PORT_LED_B   PORTE
#define GPIO_LED_B   PTE

//SW3/BTN0
#define SW3_POS      12
#define SW3_MASK     (1 << SW3_POS)
#define PORT_SW3     PORTC
#define GPIO_SW3     PTC

//SW4/BTN1
#define SW4_POS      13
#define SW4_MASK     (1 << SW4_POS)
#define PORT_SW4     PORTC
#define GPIO_SW4     PTC

#endif
