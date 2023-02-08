/**
 * @file kit_xmc4400_plt2go.h
 * @brief XMC4400 Platform2Go Kit
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

#ifndef _KIT_XMC4400_PLT2GO_H
#define _KIT_XMC4400_PLT2GO_H

//Dependencies
#include "xmc4400.h"

//LED1
#define LED1_MASK    PORT0_OUT_P6_Msk
#define PORT_LED1    PORT0

//LED2
#define LED2_MASK    PORT0_OUT_P7_Msk
#define PORT_LED2    PORT0

//Button 1
#define BUTTON1_MASK PORT3_IN_P1_Msk
#define PORT_BUTTON1 PORT3

//Button 2
#define BUTTON2_MASK PORT3_IN_P2_Msk
#define PORT_BUTTON2 PORT3

#endif
