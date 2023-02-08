/**
 * @file ek_ra6m2.h
 * @brief EK-RA6M2 evaluation kit
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

#ifndef _EK_RA6M2_H
#define _EK_RA6M2_H

//Dependencies
#include "bsp_api.h"

//User LED (LED1)
#define LED1_MASK (1U << 6)
#define LED1_PORT R_PORT1
#define LED1_PFS PORT[1].PIN[6].PmnPFS

//Push button (S1)
#define S1_MASK (1U << 5)
#define S1_PORT R_PORT1
#define S1_PFS PORT[1].PIN[5].PmnPFS

#endif
