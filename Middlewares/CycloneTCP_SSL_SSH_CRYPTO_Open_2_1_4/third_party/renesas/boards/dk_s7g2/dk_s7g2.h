/**
 * @file dk_s7g2.h
 * @brief DK-S7G2 Starter Kit
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

#ifndef _DK_S7G2_H
#define _DK_S7G2_H

//Dependencies
#include "bsp_irq_cfg.h"
#include "s7g2.h"

//Green LED (LED2)
#define LED2_MASK (1U << 7)
#define LED2_IOPORT R_IOPORT8
#define LED2_PFS_b P807PFS_b

//Red LED (LED3)
#define LED3_MASK (1U << 8)
#define LED3_IOPORT R_IOPORT8
#define LED3_PFS_b P808PFS_b

//Green LED (LED4)
#define LED4_MASK (1U << 9)
#define LED4_IOPORT R_IOPORT8
#define LED4_PFS_b P809PFS_b

//Red LED (LED5)
#define LED5_MASK (1U << 10)
#define LED5_IOPORT R_IOPORT8
#define LED5_PFS_b P810PFS_b

//Push button (S2)
#define S2_MASK (1U << 6)
#define S2_IOPORT R_IOPORT0
#define S2_PFS_b P006PFS_b

//Push button (S3)
#define S3_MASK (1U << 10)
#define S3_IOPORT R_IOPORT0
#define S3_PFS_b P010PFS_b

//Push button (S4)
#define S4_MASK (1U << 11)
#define S4_IOPORT R_IOPORT0
#define S4_PFS_b P011PFS_b

//ETH0 reset pin
#define ETH0_RST_MASK (1U << 3)
#define ETH0_RST_IOPORT R_IOPORT9
#define ETH0_RST_PFS_b P903PFS_b

//ETH0 IRQ pin
#define ETH0_IRQ_MASK (1U << 15)
#define ETH0_IRQ_IOPORT R_IOPORT0
#define ETH0_IRQ_PFS_b P015PFS_b

//ETH1 reset pin
#define ETH1_RST_MASK (1U << 6)
#define ETH1_RST_IOPORT R_IOPORT7
#define ETH1_RST_PFS_b P706PFS_b

//ETH1 IRQ pin
#define ETH1_IRQ_MASK (1U << 2)
#define ETH1_IRQ_IOPORT R_IOPORT0
#define ETH1_IRQ_PFS_b P002PFS_b

#endif
