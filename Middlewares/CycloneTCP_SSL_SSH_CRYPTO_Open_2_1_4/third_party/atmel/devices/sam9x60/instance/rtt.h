/* ---------------------------------------------------------------------------- */
/*                Microchip Microcontroller Software Support                    */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) %copyright_year%, Microchip Technology Inc.                    */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Microchip's name may not be used to endorse or promote products derived from */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS  */
/* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES */
/* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT    */
/* ARE DISCLAIMED. IN NO EVENT SHALL MICROCHIP BE LIABLE FOR ANY DIRECT,        */
/* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES           */
/* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; */
/* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  */
/* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT   */
/* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF     */
/* THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.            */
/* ---------------------------------------------------------------------------- */

#ifndef _SAM9X_RTT_INSTANCE_
#define _SAM9X_RTT_INSTANCE_

/* ========== Register definition for RTT peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
  #define REG_RTT_MR                    (0xFFFFFE20U) /**< \brief (RTT) Mode Register */
  #define REG_RTT_AR                    (0xFFFFFE24U) /**< \brief (RTT) Alarm Register */
  #define REG_RTT_VR                    (0xFFFFFE28U) /**< \brief (RTT) Value Register */
  #define REG_RTT_SR                    (0xFFFFFE2CU) /**< \brief (RTT) Status Register */
  #define REG_RTT_MODR                  (0xFFFFFE30U) /**< \brief (RTT) Modulo Selection Register */
  #define REG_RTT_TSR                   (0xFFFFFE34U) /**< \brief (RTT) TimeStamp Register */
#else
  #define REG_RTT_MR   (*(__IO uint32_t*)0xFFFFFE20U) /**< \brief (RTT) Mode Register */
  #define REG_RTT_AR   (*(__IO uint32_t*)0xFFFFFE24U) /**< \brief (RTT) Alarm Register */
  #define REG_RTT_VR   (*(__I  uint32_t*)0xFFFFFE28U) /**< \brief (RTT) Value Register */
  #define REG_RTT_SR   (*(__I  uint32_t*)0xFFFFFE2CU) /**< \brief (RTT) Status Register */
  #define REG_RTT_MODR (*(__IO uint32_t*)0xFFFFFE30U) /**< \brief (RTT) Modulo Selection Register */
  #define REG_RTT_TSR  (*(__I  uint32_t*)0xFFFFFE34U) /**< \brief (RTT) TimeStamp Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM9X_RTT_INSTANCE_ */
