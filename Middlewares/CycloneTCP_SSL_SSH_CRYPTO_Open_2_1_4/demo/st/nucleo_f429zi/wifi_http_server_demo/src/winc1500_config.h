/**
 * @file winc1500_config.h
 * @brief WINC1500 configuration
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

#ifndef _WINC1500_CONFIG_H
#define _WINC1500_CONFIG_H

//Dependencies
#include <stdint.h>

//SPI interface
#define CONF_WINC_USE_SPI                1

//Debug logs
#define CONF_WINC_DEBUG                  1
//Debug output redirection
#define CONF_WINC_PRINTF                 TRACE_PRINTF

//RST pin (PE11)
#define CONF_WINC_RST_GPIO               GPIOE
#define CONF_WINC_RST_PIN                GPIO_PIN_11
#define CONF_WINC_RST_SPEED              GPIO_SPEED_FREQ_MEDIUM
#define CONF_WINC_RST_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOE_CLK_ENABLE()

//CE pin (unused)
#define CONF_WINC_CE_GPIO                GPIOE
#define CONF_WINC_CE_PIN                 GPIO_PIN_11
#define CONF_WINC_CE_SPEED               GPIO_SPEED_FREQ_MEDIUM
#define CONF_WINC_CE_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOE_CLK_ENABLE()

//WAKE pin (unused)
#define CONF_WINC_WAKE_GPIO              GPIOE
#define CONF_WINC_WAKE_PIN               GPIO_PIN_11
#define CONF_WINC_WAKE_SPEED             GPIO_SPEED_FREQ_MEDIUM
#define CONF_WINC_WAKE_GPIO_CLK_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE()

//CS pin (PD14)
#define CONF_WINC_CS_GPIO                GPIOD
#define CONF_WINC_CS_PIN                 GPIO_PIN_14
#define CONF_WINC_CS_SPEED               GPIO_SPEED_FREQ_VERY_HIGH
#define CONF_WINC_CS_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOD_CLK_ENABLE()

//IRQ pin (PF13)
#define CONF_WINC_IRQ_GPIO               GPIOF
#define CONF_WINC_IRQ_PIN                GPIO_PIN_13
#define CONF_WINC_IRQ_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOF_CLK_ENABLE()

//SCK pin (PA5)
#define CONF_WINC_SCK_GPIO               GPIOA
#define CONF_WINC_SCK_PIN                GPIO_PIN_5
#define CONF_WINC_SCK_SPEED              GPIO_SPEED_FREQ_VERY_HIGH
#define CONF_WINC_SCK_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE();

//MOSI pin (PB5)
#define CONF_WINC_MOSI_GPIO              GPIOB
#define CONF_WINC_MOSI_PIN               GPIO_PIN_5
#define CONF_WINC_MOSI_SPEED             GPIO_SPEED_FREQ_VERY_HIGH
#define CONF_WINC_MOSI_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()

//MISO pin (PA6)
#define CONF_WINC_MISO_GPIO              GPIOA
#define CONF_WINC_MISO_PIN               GPIO_PIN_6
#define CONF_WINC_MISO_SPEED             GPIO_SPEED_FREQ_VERY_HIGH
#define CONF_WINC_MISO_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

//SPI instance
#define CONF_WINC_SPI                    SPI1
#define CONF_WINC_SPI_ALTERNATE          GPIO_AF5_SPI1
#define CONF_WINC_SPI_CLK_ENABLE()       __HAL_RCC_SPI1_CLK_ENABLE()

//SPI clock prescaler
#define CONF_WINC_SPI_BAUDRATE_PRE       SPI_BAUDRATEPRESCALER_4

//IRQ number
#define CONF_WINC_IRQn                   EXTI15_10_IRQn
//IRQ handler
#define CONF_WINC_IRQHandler             EXTI15_10_IRQHandler

//Interrupt priority grouping
#define CONF_WINC_IRQ_PRIORITY_GROUPING  3
//Interrupt group priority
#define CONF_WINC_IRQ_GROUP_PRIORITY     15
//Interrupt subpriority
#define CONF_WINC_IRQ_SUB_PRIORITY       0

//Forward function declaration
extern void winc1500EventHook(uint8_t msgType, void *msg);

//Callback function that processes Wi-Fi event notifications
#define CONF_WINC_EVENT_HOOK(msgType, msg) winc1500EventHook(msgType, msg)

#endif
