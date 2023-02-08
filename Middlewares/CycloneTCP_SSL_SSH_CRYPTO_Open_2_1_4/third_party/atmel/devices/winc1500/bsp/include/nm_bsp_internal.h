/**
 *
 * \file
 *
 * \brief This module contains NMC1500 BSP APIs declarations.
 *
 * Copyright (c) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/**@defgroup  BSPDefine Defines
 * @ingroup nm_bsp
 * @{
 */
#ifndef _NM_BSP_INTERNAL_H_
#define _NM_BSP_INTERNAL_H_


#if defined(WIN32)
#include "nm_bsp_win32.h"
#endif

#if defined(__K20D50M__)
#include "nm_bsp_k20d50m.h"
#endif

#if defined(__MSP430FR5739__)
#include "bsp_msp430fr5739.h"
#endif

#if defined(_FREESCALE_MCF51CN128_)
#include "bsp/include/nm_bsp_mcf51cn128.h"
#endif

#if defined(__MCF964548__)
#include "bsp/include/nm_bsp_mc96f4548.h"
#endif

#if defined(__APP_APS3_CORTUS__)
#include "nm_bsp_aps3_cortus.h"
#endif

#if defined(__KERNEL__)
#include "bsp\include\nm_bsp_linux.h"
#endif

#if defined(__SAMD21E18A__) || defined(__SAMD21G18A__) || defined(__SAMD21J18A__)
#include "bsp/include/nm_bsp_samd21.h"
#endif

#if defined(__SAM4E16C__) || defined(__SAM4E16E__)
#include "bsp/include/nm_bsp_sam4e.h"
#endif

#if defined(__SAM4S16C__) || defined(__SAM4SD32C__)
#include "bsp/include/nm_bsp_sam4s.h"
#endif

#if defined(__SAMG53N19__)
#include "bsp/include/nm_bsp_samg53.h"
#endif

#if defined(__SAMG55J19__)
#include "bsp/include/nm_bsp_samg55.h"
#endif

#if defined(__SAMD51G18A__) || defined(__SAMD51G19A__) || defined(__SAMD51J18A__) || \
   defined(__SAMD51J19A__) || defined(__SAMD51J20A__) || defined(__SAMD51N19A__) || \
   defined(__SAMD51N20A__) || defined(__SAMD51P19A__) || defined(__SAMD51P20A__)
#include "bsp/include/nm_bsp_samd51.h"
#endif

#if defined(__SAME54N19A__) || defined(__SAME54N20A__) || defined(__SAME54P19A__) || \
   defined(__SAME54P20A__)
#include "bsp/include/nm_bsp_same54.h"
#endif

#if defined(__SAME70Q21__)
#include "bsp/include/nm_bsp_same70.h"
#endif

#if defined(__SAMV71Q21__)
#include "bsp/include/nm_bsp_samv71.h"
#endif

#if defined(CONFIG_SOC_SAMA5D2)
#include "bsp/include/nm_bsp_sama5d2.h"
#endif

#if defined(STM32F10X_LD) || defined(STM32F10X_LD_VL) || defined(STM32F10X_MD) || \
   defined(STM32F10X_MD_VL) || defined(STM32F10X_HD) || defined(STM32F10X_HD_VL) || \
   defined(STM32F10X_XL) || defined(STM32F10X_CL) || defined(STM32F100xB) || \
   defined(STM32F100xE) || defined(STM32F101x6) || defined(STM32F101xB) || \
   defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102x6) || \
   defined(STM32F102xB) || defined(STM32F103x6) || defined(STM32F103xB) || \
   defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC) || \
   defined(STM32F107xC)
#include "bsp/include/nm_bsp_stm32f1xx.h"
#endif

#if defined(STM32F2XX) || defined(STM32F205xx) || defined(STM32F215xx) || \
   defined(STM32F207xx) || defined(STM32F217xx)
#include "bsp/include/nm_bsp_stm32f2xx.h"
#endif

#if defined(STM32F4XX) || defined(STM32F405xx) || defined(STM32F415xx) || \
   defined(STM32F407xx) || defined(STM32F417xx) || defined(STM32F427xx) || \
   defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx) || \
   defined(STM32F401xC) || defined(STM32F401xE) || defined(STM32F410Tx) || \
   defined(STM32F410Cx) || defined(STM32F410Rx) || defined(STM32F411xE) || \
   defined(STM32F446xx) || defined(STM32F469xx) || defined(STM32F479xx) || \
   defined(STM32F412Cx) || defined(STM32F412Rx) || defined(STM32F412Vx) || \
   defined(STM32F412Zx) || defined(STM32F413xx) || defined(STM32F423xx)
#include "bsp/include/nm_bsp_stm32f4xx.h"
#endif

#if defined(STM32F756xx) || defined(STM32F746xx) || defined(STM32F745xx) || \
   defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || \
   defined(STM32F777xx) || defined(STM32F779xx) || defined(STM32F722xx) || \
   defined(STM32F723xx) || defined(STM32F732xx) || defined(STM32F733xx) || \
   defined(STM32F730xx) || defined(STM32F750xx)
#include "bsp/include/nm_bsp_stm32f7xx.h"
#endif

#if defined(STM32H743xx) || defined(STM32H753xx) || defined(STM32H750xx) || \
   defined(STM32H742xx) || defined(STM32H745xx) || defined(STM32H755xx) || \
   defined(STM32H747xx) || defined(STM32H757xx) || defined(STM32H7A3xx) || \
   defined(STM32H7A3xxQ) || defined(STM32H7B3xx) || defined(STM32H7B3xxQ) || \
   defined(STM32H7B0xx) || defined(STM32H7B0xxQ) || defined(STM32H735xx) || \
   defined(STM32H733xx) || defined(STM32H730xx) || defined(STM32H730xxQ) || \
   defined(STM32H725xx) || defined(STM32H723xx)
#include "bsp/include/nm_bsp_stm32h7xx.h"
#endif

#if defined(STM32L412xx) || defined(STM32L422xx) || defined(STM32L431xx) || \
   defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || \
   defined(STM32L443xx) || defined(STM32L451xx) || defined(STM32L452xx) || \
   defined(STM32L462xx) || defined(STM32L471xx) || defined(STM32L475xx) || \
   defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || \
   defined(STM32L496xx) || defined(STM32L4A6xx) || defined(STM32L4P5xx) || \
   defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || \
   defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || \
   defined(STM32L4S9xx)
#include "bsp/include/nm_bsp_stm32l4xx.h"
#endif

#if defined(STM32L552xx) || defined(STM32L562xx)
#include "bsp/include/nm_bsp_stm32l5xx.h"
#endif

#if defined(STM32U575xx) || defined(STM32U585xx)
#include "bsp/include/nm_bsp_stm32u5xx.h"
#endif

#if defined(__32MX470F512H__)
#include "bsp/include/nm_bsp_pic32mx.h"
#endif

#if defined(__32MZ2048EFH064__) || defined(__32MZ2048EFM064__) || \
   defined(__32MZ2048EFM100__) || defined(__32MZ2048EFM144__)
#include "bsp/include/nm_bsp_pic32mz.h"
#endif

#if defined(PART_TM4C1294NCPDT) || defined(PART_TM4C129XNCZAD)
#include "bsp/include/nm_bsp_tm4c129.h"
#endif

#if defined(CORTUS_APP)
#include "crt_iface.h"
#endif

#if defined(NRF51)
#include "nm_bsp_nrf51822.h"
#endif

#if defined(_ARDUINO_UNO_)
#include "bsp/include/nm_bsp_arduino_uno.h"
#endif


#endif //_NM_BSP_INTERNAL_H_
