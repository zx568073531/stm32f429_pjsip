/**
 * @file fpb_ra6e1.h
 * @brief FPB-RA6E1 fast prototyping board
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

#ifndef _FPB_RA6E1_H
#define _FPB_RA6E1_H

//Dependencies
#include "bsp_api.h"

//Green LED (LED1)
#define LED1_MASK (1U << 8)
#define LED1_PORT R_PORT4
#define LED1_PFS PORT[4].PIN[8].PmnPFS

//Green LED (LED2)
#define LED2_MASK (1U << 7)
#define LED2_PORT R_PORT4
#define LED2_PFS PORT[4].PIN[7].PmnPFS

//Push button (S1)
#define S1_MASK (1U << 5)
#define S1_PORT R_PORT2
#define S1_PFS PORT[2].PIN[5].PmnPFS

#endif
