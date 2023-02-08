/**
 * @file same70_xplained_ultra.h
 * @brief SAME70-Xplained-Ultra evaluation kit
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

#ifndef _SAME70_XPLAINED_ULTRA_H
#define _SAME70_XPLAINED_ULTRA_H

//Dependencies
#include "same70.h"

//LED2
#define LED2        PIO_PB8
#define PIO_LED2    PIOB
#define ID_PIO_LED2 ID_PIOB

//LED3
#define LED3        PIO_PA5
#define PIO_LED3    PIOA
#define ID_PIO_LED3 ID_PIOA

//SW0 button
#define SW0         PIO_PA11
#define PIO_SW0     PIOA
#define ID_PIO_SW0  ID_PIOA

#endif
