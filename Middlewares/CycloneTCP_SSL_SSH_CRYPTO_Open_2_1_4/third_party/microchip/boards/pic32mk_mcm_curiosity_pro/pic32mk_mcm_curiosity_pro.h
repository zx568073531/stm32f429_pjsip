/**
 * @file pic32mk_mcm_curiosity_pro.h
 * @brief PIC32MK MCM Curiosity Pro
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

#ifndef _PIC32MK_MCM_CURIOSITY_PRO_H
#define _PIC32MK_MCM_CURIOSITY_PRO_H

//Dependencies
#include <p32xxxx.h>

//LEDs
#define LED1_MASK (1 << 12)
#define LED2_MASK (1 << 13)
#define LED3_MASK (1 << 14)

//Push buttons
#define SW1_MASK (1 << 11)
#define SW2_MASK (1 << 12)
#define SW3_MASK (1 << 13)

#endif
