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

#ifndef _SAM9X_LCDC_COMPONENT_
#define _SAM9X_LCDC_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR LCD Controller */
/* ============================================================================= */
/** \addtogroup SAM9X_LCDC LCD Controller */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief Lcdc hardware registers */
typedef struct {
  __IO uint32_t LCDC_LCDCFG0;       /**< \brief (Lcdc Offset: 0x0) LCD Controller Configuration Register 0 */
  __IO uint32_t LCDC_LCDCFG1;       /**< \brief (Lcdc Offset: 0x4) LCD Controller Configuration Register 1 */
  __IO uint32_t LCDC_LCDCFG2;       /**< \brief (Lcdc Offset: 0x8) LCD Controller Configuration Register 2 */
  __IO uint32_t LCDC_LCDCFG3;       /**< \brief (Lcdc Offset: 0xC) LCD Controller Configuration Register 3 */
  __IO uint32_t LCDC_LCDCFG4;       /**< \brief (Lcdc Offset: 0x10) LCD Controller Configuration Register 4 */
  __IO uint32_t LCDC_LCDCFG5;       /**< \brief (Lcdc Offset: 0x14) LCD Controller Configuration Register 5 */
  __IO uint32_t LCDC_LCDCFG6;       /**< \brief (Lcdc Offset: 0x18) LCD Controller Configuration Register 6 */
  __IO uint32_t LCDC_LCDCFG7;       /**< \brief (Lcdc Offset: 0x1C) LCD Controller Configuration Register 7 */
  __O  uint32_t LCDC_LCDEN;         /**< \brief (Lcdc Offset: 0x20) LCD Controller Enable Register */
  __O  uint32_t LCDC_LCDDIS;        /**< \brief (Lcdc Offset: 0x24) LCD Controller Disable Register */
  __I  uint32_t LCDC_LCDSR;         /**< \brief (Lcdc Offset: 0x28) LCD Controller Status Register */
  __O  uint32_t LCDC_LCDIER;        /**< \brief (Lcdc Offset: 0x2C) LCD Controller Interrupt Enable Register */
  __O  uint32_t LCDC_LCDIDR;        /**< \brief (Lcdc Offset: 0x30) LCD Controller Interrupt Disable Register */
  __I  uint32_t LCDC_LCDIMR;        /**< \brief (Lcdc Offset: 0x34) LCD Controller Interrupt Mask Register */
  __I  uint32_t LCDC_LCDISR;        /**< \brief (Lcdc Offset: 0x38) LCD Controller Interrupt Status Register */
  __O  uint32_t LCDC_ATTR;          /**< \brief (Lcdc Offset: 0x3C) LCD Controller Attribute Register */
  __IO uint32_t LCDC_QOSCFG;        /**< \brief (Lcdc Offset: 0x40) LCD Controller QoS Configuration Register */
  __I  uint32_t LCDC_QOS1M;         /**< \brief (Lcdc Offset: 0x44) LCD Controller QoS 1 Metrics Register */
  __I  uint32_t LCDC_QOS2M;         /**< \brief (Lcdc Offset: 0x48) LCD Controller QoS 2 Metrics Register */
  __I  uint32_t LCDC_QOS3M;         /**< \brief (Lcdc Offset: 0x4C) LCD Controller QoS 3 Metrics Register */
  __I  uint32_t LCDC_QOSMIN;        /**< \brief (Lcdc Offset: 0x50) LCD Controller QoS Min FIFO Level Register */
  __I  uint32_t Reserved1[3];
  __O  uint32_t LCDC_BASECHER;      /**< \brief (Lcdc Offset: 0x60) Base Layer Channel Enable Register */
  __O  uint32_t LCDC_BASECHDR;      /**< \brief (Lcdc Offset: 0x64) Base Layer Channel Disable Register */
  __I  uint32_t LCDC_BASECHSR;      /**< \brief (Lcdc Offset: 0x68) Base Layer Channel Status Register */
  __O  uint32_t LCDC_BASEIER;       /**< \brief (Lcdc Offset: 0x6C) Base Layer Interrupt Enable Register */
  __O  uint32_t LCDC_BASEIDR;       /**< \brief (Lcdc Offset: 0x70) Base Layer Interrupt Disabled Register */
  __I  uint32_t LCDC_BASEIMR;       /**< \brief (Lcdc Offset: 0x74) Base Layer Interrupt Mask Register */
  __I  uint32_t LCDC_BASEISR;       /**< \brief (Lcdc Offset: 0x78) Base Layer Interrupt Status Register */
  __IO uint32_t LCDC_BASEHEAD;      /**< \brief (Lcdc Offset: 0x7C) Base DMA Head Register */
  __IO uint32_t LCDC_BASEADDR;      /**< \brief (Lcdc Offset: 0x80) Base DMA Address Register */
  __IO uint32_t LCDC_BASECTRL;      /**< \brief (Lcdc Offset: 0x84) Base DMA Control Register */
  __IO uint32_t LCDC_BASENEXT;      /**< \brief (Lcdc Offset: 0x88) Base DMA Next Register */
  __IO uint32_t LCDC_BASECFG0;      /**< \brief (Lcdc Offset: 0x8C) Base Layer Configuration Register 0 */
  __IO uint32_t LCDC_BASECFG1;      /**< \brief (Lcdc Offset: 0x90) Base Layer Configuration Register 1 */
  __IO uint32_t LCDC_BASECFG2;      /**< \brief (Lcdc Offset: 0x94) Base Layer Configuration Register 2 */
  __IO uint32_t LCDC_BASECFG3;      /**< \brief (Lcdc Offset: 0x98) Base Layer Configuration Register 3 */
  __IO uint32_t LCDC_BASECFG4;      /**< \brief (Lcdc Offset: 0x9C) Base Layer Configuration Register 4 */
  __IO uint32_t LCDC_BASECFG5;      /**< \brief (Lcdc Offset: 0xA0) Base Layer Configuration Register 5 */
  __IO uint32_t LCDC_BASECFG6;      /**< \brief (Lcdc Offset: 0xA4) Base Layer Configuration Register 6 */
  __I  uint32_t Reserved2[46];
  __O  uint32_t LCDC_OVR1CHER;      /**< \brief (Lcdc Offset: 0x160) Overlay 1 Channel Enable Register */
  __O  uint32_t LCDC_OVR1CHDR;      /**< \brief (Lcdc Offset: 0x164) Overlay 1 Channel Disable Register */
  __I  uint32_t LCDC_OVR1CHSR;      /**< \brief (Lcdc Offset: 0x168) Overlay 1 Channel Status Register */
  __O  uint32_t LCDC_OVR1IER;       /**< \brief (Lcdc Offset: 0x16C) Overlay 1 Interrupt Enable Register */
  __O  uint32_t LCDC_OVR1IDR;       /**< \brief (Lcdc Offset: 0x170) Overlay 1 Interrupt Disable Register */
  __I  uint32_t LCDC_OVR1IMR;       /**< \brief (Lcdc Offset: 0x174) Overlay 1 Interrupt Mask Register */
  __I  uint32_t LCDC_OVR1ISR;       /**< \brief (Lcdc Offset: 0x178) Overlay 1 Interrupt Status Register */
  __IO uint32_t LCDC_OVR1HEAD;      /**< \brief (Lcdc Offset: 0x17C) Overlay 1 DMA Head Register */
  __IO uint32_t LCDC_OVR1ADDR;      /**< \brief (Lcdc Offset: 0x180) Overlay 1 DMA Address Register */
  __IO uint32_t LCDC_OVR1CTRL;      /**< \brief (Lcdc Offset: 0x184) Overlay 1 DMA Control Register */
  __IO uint32_t LCDC_OVR1NEXT;      /**< \brief (Lcdc Offset: 0x188) Overlay 1 DMA Next Register */
  __IO uint32_t LCDC_OVR1CFG0;      /**< \brief (Lcdc Offset: 0x18C) Overlay 1 Configuration Register 0 */
  __IO uint32_t LCDC_OVR1CFG1;      /**< \brief (Lcdc Offset: 0x190) Overlay 1 Configuration Register 1 */
  __IO uint32_t LCDC_OVR1CFG2;      /**< \brief (Lcdc Offset: 0x194) Overlay 1 Configuration Register 2 */
  __IO uint32_t LCDC_OVR1CFG3;      /**< \brief (Lcdc Offset: 0x198) Overlay 1 Configuration Register 3 */
  __IO uint32_t LCDC_OVR1CFG4;      /**< \brief (Lcdc Offset: 0x19C) Overlay 1 Configuration Register 4 */
  __IO uint32_t LCDC_OVR1CFG5;      /**< \brief (Lcdc Offset: 0x1A0) Overlay 1 Configuration Register 5 */
  __IO uint32_t LCDC_OVR1CFG6;      /**< \brief (Lcdc Offset: 0x1A4) Overlay 1 Configuration Register 6 */
  __IO uint32_t LCDC_OVR1CFG7;      /**< \brief (Lcdc Offset: 0x1A8) Overlay 1 Configuration Register 7 */
  __IO uint32_t LCDC_OVR1CFG8;      /**< \brief (Lcdc Offset: 0x1AC) Overlay 1 Configuration Register 8 */
  __IO uint32_t LCDC_OVR1CFG9;      /**< \brief (Lcdc Offset: 0x1B0) Overlay 1 Configuration Register 9 */
  __I  uint32_t Reserved3[43];
  __O  uint32_t LCDC_OVR2CHER;      /**< \brief (Lcdc Offset: 0x260) Overlay 2 Channel Enable Register */
  __O  uint32_t LCDC_OVR2CHDR;      /**< \brief (Lcdc Offset: 0x264) Overlay 2 Channel Disable Register */
  __I  uint32_t LCDC_OVR2CHSR;      /**< \brief (Lcdc Offset: 0x268) Overlay 2 Channel Status Register */
  __O  uint32_t LCDC_OVR2IER;       /**< \brief (Lcdc Offset: 0x26C) Overlay 2 Interrupt Enable Register */
  __O  uint32_t LCDC_OVR2IDR;       /**< \brief (Lcdc Offset: 0x270) Overlay 2 Interrupt Disable Register */
  __I  uint32_t LCDC_OVR2IMR;       /**< \brief (Lcdc Offset: 0x274) Overlay 2 Interrupt Mask Register */
  __I  uint32_t LCDC_OVR2ISR;       /**< \brief (Lcdc Offset: 0x278) Overlay 2 Interrupt Status Register */
  __IO uint32_t LCDC_OVR2HEAD;      /**< \brief (Lcdc Offset: 0x27C) Overlay 2 DMA Head Register */
  __IO uint32_t LCDC_OVR2ADDR;      /**< \brief (Lcdc Offset: 0x280) Overlay 2 DMA Address Register */
  __IO uint32_t LCDC_OVR2CTRL;      /**< \brief (Lcdc Offset: 0x284) Overlay 2 DMA Control Register */
  __IO uint32_t LCDC_OVR2NEXT;      /**< \brief (Lcdc Offset: 0x288) Overlay 2 DMA Next Register */
  __IO uint32_t LCDC_OVR2CFG0;      /**< \brief (Lcdc Offset: 0x28C) Overlay 2 Configuration Register 0 */
  __IO uint32_t LCDC_OVR2CFG1;      /**< \brief (Lcdc Offset: 0x290) Overlay 2 Configuration Register 1 */
  __IO uint32_t LCDC_OVR2CFG2;      /**< \brief (Lcdc Offset: 0x294) Overlay 2 Configuration Register 2 */
  __IO uint32_t LCDC_OVR2CFG3;      /**< \brief (Lcdc Offset: 0x298) Overlay 2 Configuration Register 3 */
  __IO uint32_t LCDC_OVR2CFG4;      /**< \brief (Lcdc Offset: 0x29C) Overlay 2 Configuration Register 4 */
  __IO uint32_t LCDC_OVR2CFG5;      /**< \brief (Lcdc Offset: 0x2A0) Overlay 2 Configuration Register 5 */
  __IO uint32_t LCDC_OVR2CFG6;      /**< \brief (Lcdc Offset: 0x2A4) Overlay 2 Configuration Register 6 */
  __IO uint32_t LCDC_OVR2CFG7;      /**< \brief (Lcdc Offset: 0x2A8) Overlay 2 Configuration Register 7 */
  __IO uint32_t LCDC_OVR2CFG8;      /**< \brief (Lcdc Offset: 0x2AC) Overlay 2 Configuration Register 8 */
  __IO uint32_t LCDC_OVR2CFG9;      /**< \brief (Lcdc Offset: 0x2B0) Overlay 2 Configuration Register 9 */
  __I  uint32_t Reserved4[43];
  __O  uint32_t LCDC_HEOCHER;       /**< \brief (Lcdc Offset: 0x360) High-End Overlay Channel Enable Register */
  __O  uint32_t LCDC_HEOCHDR;       /**< \brief (Lcdc Offset: 0x364) High-End Overlay Channel Disable Register */
  __I  uint32_t LCDC_HEOCHSR;       /**< \brief (Lcdc Offset: 0x368) High-End Overlay Channel Status Register */
  __O  uint32_t LCDC_HEOIER;        /**< \brief (Lcdc Offset: 0x36C) High-End Overlay Interrupt Enable Register */
  __O  uint32_t LCDC_HEOIDR;        /**< \brief (Lcdc Offset: 0x370) High-End Overlay Interrupt Disable Register */
  __I  uint32_t LCDC_HEOIMR;        /**< \brief (Lcdc Offset: 0x374) High-End Overlay Interrupt Mask Register */
  __I  uint32_t LCDC_HEOISR;        /**< \brief (Lcdc Offset: 0x378) High-End Overlay Interrupt Status Register */
  __IO uint32_t LCDC_HEOHEAD;       /**< \brief (Lcdc Offset: 0x37C) High-End Overlay DMA Head Register */
  __IO uint32_t LCDC_HEOADDR;       /**< \brief (Lcdc Offset: 0x380) High-End Overlay DMA Address Register */
  __IO uint32_t LCDC_HEOCTRL;       /**< \brief (Lcdc Offset: 0x384) High-End Overlay DMA Control Register */
  __IO uint32_t LCDC_HEONEXT;       /**< \brief (Lcdc Offset: 0x388) High-End Overlay DMA Next Register */
  __IO uint32_t LCDC_HEOUHEAD;      /**< \brief (Lcdc Offset: 0x38C) High-End Overlay U-UV DMA Head Register */
  __IO uint32_t LCDC_HEOUADDR;      /**< \brief (Lcdc Offset: 0x390) High-End Overlay U-UV DMA Address Register */
  __IO uint32_t LCDC_HEOUCTRL;      /**< \brief (Lcdc Offset: 0x394) High-End Overlay U-UV DMA Control Register */
  __IO uint32_t LCDC_HEOUNEXT;      /**< \brief (Lcdc Offset: 0x398) High-End Overlay U-UV DMA Next Register */
  __IO uint32_t LCDC_HEOVHEAD;      /**< \brief (Lcdc Offset: 0x39C) High-End Overlay V DMA Head Register */
  __IO uint32_t LCDC_HEOVADDR;      /**< \brief (Lcdc Offset: 0x3A0) High-End Overlay V DMA Address Register */
  __IO uint32_t LCDC_HEOVCTRL;      /**< \brief (Lcdc Offset: 0x3A4) High-End Overlay V DMA Control Register */
  __IO uint32_t LCDC_HEOVNEXT;      /**< \brief (Lcdc Offset: 0x3A8) High-End Overlay V DMA Next Register */
  __IO uint32_t LCDC_HEOCFG0;       /**< \brief (Lcdc Offset: 0x3AC) High-End Overlay Configuration Register 0 */
  __IO uint32_t LCDC_HEOCFG1;       /**< \brief (Lcdc Offset: 0x3B0) High-End Overlay Configuration Register 1 */
  __IO uint32_t LCDC_HEOCFG2;       /**< \brief (Lcdc Offset: 0x3B4) High-End Overlay Configuration Register 2 */
  __IO uint32_t LCDC_HEOCFG3;       /**< \brief (Lcdc Offset: 0x3B8) High-End Overlay Configuration Register 3 */
  __IO uint32_t LCDC_HEOCFG4;       /**< \brief (Lcdc Offset: 0x3BC) High-End Overlay Configuration Register 4 */
  __IO uint32_t LCDC_HEOCFG5;       /**< \brief (Lcdc Offset: 0x3C0) High-End Overlay Configuration Register 5 */
  __IO uint32_t LCDC_HEOCFG6;       /**< \brief (Lcdc Offset: 0x3C4) High-End Overlay Configuration Register 6 */
  __IO uint32_t LCDC_HEOCFG7;       /**< \brief (Lcdc Offset: 0x3C8) High-End Overlay Configuration Register 7 */
  __IO uint32_t LCDC_HEOCFG8;       /**< \brief (Lcdc Offset: 0x3CC) High-End Overlay Configuration Register 8 */
  __IO uint32_t LCDC_HEOCFG9;       /**< \brief (Lcdc Offset: 0x3D0) High-End Overlay Configuration Register 9 */
  __IO uint32_t LCDC_HEOCFG10;      /**< \brief (Lcdc Offset: 0x3D4) High-End Overlay Configuration Register 10 */
  __IO uint32_t LCDC_HEOCFG11;      /**< \brief (Lcdc Offset: 0x3D8) High-End Overlay Configuration Register 11 */
  __IO uint32_t LCDC_HEOCFG12;      /**< \brief (Lcdc Offset: 0x3DC) High-End Overlay Configuration Register 12 */
  __IO uint32_t LCDC_HEOCFG13;      /**< \brief (Lcdc Offset: 0x3E0) High-End Overlay Configuration Register 13 */
  __IO uint32_t LCDC_HEOCFG14;      /**< \brief (Lcdc Offset: 0x3E4) High-End Overlay Configuration Register 14 */
  __IO uint32_t LCDC_HEOCFG15;      /**< \brief (Lcdc Offset: 0x3E8) High-End Overlay Configuration Register 15 */
  __IO uint32_t LCDC_HEOCFG16;      /**< \brief (Lcdc Offset: 0x3EC) High-End Overlay Configuration Register 16 */
  __IO uint32_t LCDC_HEOCFG17;      /**< \brief (Lcdc Offset: 0x3F0) High-End Overlay Configuration Register 17 */
  __IO uint32_t LCDC_HEOCFG18;      /**< \brief (Lcdc Offset: 0x3F4) High-End Overlay Configuration Register 18 */
  __IO uint32_t LCDC_HEOCFG19;      /**< \brief (Lcdc Offset: 0x3F8) High-End Overlay Configuration Register 19 */
  __IO uint32_t LCDC_HEOCFG20;      /**< \brief (Lcdc Offset: 0x3FC) High-End Overlay Configuration Register 20 */
  __IO uint32_t LCDC_HEOCFG21;      /**< \brief (Lcdc Offset: 0x400) High-End Overlay Configuration Register 21 */
  __IO uint32_t LCDC_HEOCFG22;      /**< \brief (Lcdc Offset: 0x404) High-End Overlay Configuration Register 22 */
  __IO uint32_t LCDC_HEOCFG23;      /**< \brief (Lcdc Offset: 0x408) High-End Overlay Configuration Register 23 */
  __IO uint32_t LCDC_HEOCFG24;      /**< \brief (Lcdc Offset: 0x40C) High-End Overlay Configuration Register 24 */
  __IO uint32_t LCDC_HEOCFG25;      /**< \brief (Lcdc Offset: 0x410) High-End Overlay Configuration Register 25 */
  __IO uint32_t LCDC_HEOCFG26;      /**< \brief (Lcdc Offset: 0x414) High-End Overlay Configuration Register 26 */
  __IO uint32_t LCDC_HEOCFG27;      /**< \brief (Lcdc Offset: 0x418) High-End Overlay Configuration Register 27 */
  __IO uint32_t LCDC_HEOCFG28;      /**< \brief (Lcdc Offset: 0x41C) High-End Overlay Configuration Register 28 */
  __IO uint32_t LCDC_HEOCFG29;      /**< \brief (Lcdc Offset: 0x420) High-End Overlay Configuration Register 29 */
  __IO uint32_t LCDC_HEOCFG30;      /**< \brief (Lcdc Offset: 0x424) High-End Overlay Configuration Register 30 */
  __IO uint32_t LCDC_HEOCFG31;      /**< \brief (Lcdc Offset: 0x428) High-End Overlay Configuration Register 31 */
  __IO uint32_t LCDC_HEOCFG32;      /**< \brief (Lcdc Offset: 0x42C) High-End Overlay Configuration Register 32 */
  __IO uint32_t LCDC_HEOCFG33;      /**< \brief (Lcdc Offset: 0x430) High-End Overlay Configuration Register 33 */
  __IO uint32_t LCDC_HEOCFG34;      /**< \brief (Lcdc Offset: 0x434) High-End Overlay Configuration Register 34 */
  __IO uint32_t LCDC_HEOCFG35;      /**< \brief (Lcdc Offset: 0x438) High-End Overlay Configuration Register 35 */
  __IO uint32_t LCDC_HEOCFG36;      /**< \brief (Lcdc Offset: 0x43C) High-End Overlay Configuration Register 36 */
  __IO uint32_t LCDC_HEOCFG37;      /**< \brief (Lcdc Offset: 0x440) High-End Overlay Configuration Register 37 */
  __IO uint32_t LCDC_HEOCFG38;      /**< \brief (Lcdc Offset: 0x444) High-End Overlay Configuration Register 38 */
  __IO uint32_t LCDC_HEOCFG39;      /**< \brief (Lcdc Offset: 0x448) High-End Overlay Configuration Register 39 */
  __IO uint32_t LCDC_HEOCFG40;      /**< \brief (Lcdc Offset: 0x44C) High-End Overlay Configuration Register 40 */
  __IO uint32_t LCDC_HEOCFG41;      /**< \brief (Lcdc Offset: 0x450) High-End Overlay Configuration Register 41 */
  __I  uint32_t Reserved5[107];
  __IO uint32_t LCDC_BASECLUT[256]; /**< \brief (Lcdc Offset: 0x600) Base CLUT Register */
  __IO uint32_t LCDC_OVR1CLUT[256]; /**< \brief (Lcdc Offset: 0xA00) Overlay 1 CLUT Register */
  __IO uint32_t LCDC_OVR2CLUT[256]; /**< \brief (Lcdc Offset: 0xE00) Overlay 2 CLUT Register */
  __IO uint32_t LCDC_HEOCLUT[256];  /**< \brief (Lcdc Offset: 0x1200) High-End Overlay CLUT Register */
} Lcdc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- LCDC_LCDCFG0 : (LCDC Offset: 0x0) LCD Controller Configuration Register 0 -------- */
#define LCDC_LCDCFG0_CLKPOL (0x1u << 0) /**< \brief (LCDC_LCDCFG0) LCD Controller Clock Polarity */
#define LCDC_LCDCFG0_CLKPWMSEL (0x1u << 3) /**< \brief (LCDC_LCDCFG0) LCD Controller PWM Clock Source Selection */
#define LCDC_LCDCFG0_CGDISBASE (0x1u << 8) /**< \brief (LCDC_LCDCFG0) Clock Gating Disable Control for the Base Layer */
#define LCDC_LCDCFG0_CGDISOVR1 (0x1u << 9) /**< \brief (LCDC_LCDCFG0) Clock Gating Disable Control for the Overlay 1 Layer */
#define LCDC_LCDCFG0_CGDISOVR2 (0x1u << 10) /**< \brief (LCDC_LCDCFG0) Clock Gating Disable Control for the Overlay 2 Layer */
#define LCDC_LCDCFG0_CGDISHEO (0x1u << 11) /**< \brief (LCDC_LCDCFG0) Clock Gating Disable Control for the High-End Overlay */
#define LCDC_LCDCFG0_CLKDIV_Pos 16
#define LCDC_LCDCFG0_CLKDIV_Msk (0xffu << LCDC_LCDCFG0_CLKDIV_Pos) /**< \brief (LCDC_LCDCFG0) LCD Controller Clock Divider */
#define LCDC_LCDCFG0_CLKDIV(value) ((LCDC_LCDCFG0_CLKDIV_Msk & ((value) << LCDC_LCDCFG0_CLKDIV_Pos)))
/* -------- LCDC_LCDCFG1 : (LCDC Offset: 0x4) LCD Controller Configuration Register 1 -------- */
#define LCDC_LCDCFG1_HSPW_Pos 0
#define LCDC_LCDCFG1_HSPW_Msk (0x3ffu << LCDC_LCDCFG1_HSPW_Pos) /**< \brief (LCDC_LCDCFG1) Horizontal Synchronization Pulse Width */
#define LCDC_LCDCFG1_HSPW(value) ((LCDC_LCDCFG1_HSPW_Msk & ((value) << LCDC_LCDCFG1_HSPW_Pos)))
#define LCDC_LCDCFG1_VSPW_Pos 16
#define LCDC_LCDCFG1_VSPW_Msk (0x3ffu << LCDC_LCDCFG1_VSPW_Pos) /**< \brief (LCDC_LCDCFG1) Vertical Synchronization Pulse Width */
#define LCDC_LCDCFG1_VSPW(value) ((LCDC_LCDCFG1_VSPW_Msk & ((value) << LCDC_LCDCFG1_VSPW_Pos)))
/* -------- LCDC_LCDCFG2 : (LCDC Offset: 0x8) LCD Controller Configuration Register 2 -------- */
#define LCDC_LCDCFG2_VFPW_Pos 0
#define LCDC_LCDCFG2_VFPW_Msk (0x3ffu << LCDC_LCDCFG2_VFPW_Pos) /**< \brief (LCDC_LCDCFG2) Vertical Front Porch Width */
#define LCDC_LCDCFG2_VFPW(value) ((LCDC_LCDCFG2_VFPW_Msk & ((value) << LCDC_LCDCFG2_VFPW_Pos)))
#define LCDC_LCDCFG2_VBPW_Pos 16
#define LCDC_LCDCFG2_VBPW_Msk (0x3ffu << LCDC_LCDCFG2_VBPW_Pos) /**< \brief (LCDC_LCDCFG2) Vertical Back Porch Width */
#define LCDC_LCDCFG2_VBPW(value) ((LCDC_LCDCFG2_VBPW_Msk & ((value) << LCDC_LCDCFG2_VBPW_Pos)))
/* -------- LCDC_LCDCFG3 : (LCDC Offset: 0xC) LCD Controller Configuration Register 3 -------- */
#define LCDC_LCDCFG3_HFPW_Pos 0
#define LCDC_LCDCFG3_HFPW_Msk (0x3ffu << LCDC_LCDCFG3_HFPW_Pos) /**< \brief (LCDC_LCDCFG3) Horizontal Front Porch Width */
#define LCDC_LCDCFG3_HFPW(value) ((LCDC_LCDCFG3_HFPW_Msk & ((value) << LCDC_LCDCFG3_HFPW_Pos)))
#define LCDC_LCDCFG3_HBPW_Pos 16
#define LCDC_LCDCFG3_HBPW_Msk (0x3ffu << LCDC_LCDCFG3_HBPW_Pos) /**< \brief (LCDC_LCDCFG3) Horizontal Back Porch Width */
#define LCDC_LCDCFG3_HBPW(value) ((LCDC_LCDCFG3_HBPW_Msk & ((value) << LCDC_LCDCFG3_HBPW_Pos)))
/* -------- LCDC_LCDCFG4 : (LCDC Offset: 0x10) LCD Controller Configuration Register 4 -------- */
#define LCDC_LCDCFG4_PPL_Pos 0
#define LCDC_LCDCFG4_PPL_Msk (0x7ffu << LCDC_LCDCFG4_PPL_Pos) /**< \brief (LCDC_LCDCFG4) Number of Pixels Per Line */
#define LCDC_LCDCFG4_PPL(value) ((LCDC_LCDCFG4_PPL_Msk & ((value) << LCDC_LCDCFG4_PPL_Pos)))
#define LCDC_LCDCFG4_RPF_Pos 16
#define LCDC_LCDCFG4_RPF_Msk (0x7ffu << LCDC_LCDCFG4_RPF_Pos) /**< \brief (LCDC_LCDCFG4) Number of Active Row Per Frame */
#define LCDC_LCDCFG4_RPF(value) ((LCDC_LCDCFG4_RPF_Msk & ((value) << LCDC_LCDCFG4_RPF_Pos)))
/* -------- LCDC_LCDCFG5 : (LCDC Offset: 0x14) LCD Controller Configuration Register 5 -------- */
#define LCDC_LCDCFG5_HSPOL (0x1u << 0) /**< \brief (LCDC_LCDCFG5) Horizontal Synchronization Pulse Polarity */
#define LCDC_LCDCFG5_VSPOL (0x1u << 1) /**< \brief (LCDC_LCDCFG5) Vertical Synchronization Pulse Polarity */
#define LCDC_LCDCFG5_VSPDLYS (0x1u << 2) /**< \brief (LCDC_LCDCFG5) Vertical Synchronization Pulse Start */
#define LCDC_LCDCFG5_VSPDLYE (0x1u << 3) /**< \brief (LCDC_LCDCFG5) Vertical Synchronization Pulse End */
#define LCDC_LCDCFG5_DISPPOL (0x1u << 4) /**< \brief (LCDC_LCDCFG5) Display Signal Polarity */
#define LCDC_LCDCFG5_DITHER (0x1u << 6) /**< \brief (LCDC_LCDCFG5) LCD Controller Dithering */
#define LCDC_LCDCFG5_DISPDLY (0x1u << 7) /**< \brief (LCDC_LCDCFG5) LCD Controller Display Power Signal Synchronization */
#define LCDC_LCDCFG5_MODE_Pos 8
#define LCDC_LCDCFG5_MODE_Msk (0x3u << LCDC_LCDCFG5_MODE_Pos) /**< \brief (LCDC_LCDCFG5) LCD Controller Output Mode */
#define LCDC_LCDCFG5_MODE(value) ((LCDC_LCDCFG5_MODE_Msk & ((value) << LCDC_LCDCFG5_MODE_Pos)))
#define   LCDC_LCDCFG5_MODE_OUTPUT_12BPP (0x0u << 8) /**< \brief (LCDC_LCDCFG5) LCD Output mode is set to 12 bits per pixel */
#define   LCDC_LCDCFG5_MODE_OUTPUT_16BPP (0x1u << 8) /**< \brief (LCDC_LCDCFG5) LCD Output mode is set to 16 bits per pixel */
#define   LCDC_LCDCFG5_MODE_OUTPUT_18BPP (0x2u << 8) /**< \brief (LCDC_LCDCFG5) LCD Output mode is set to 18 bits per pixel */
#define   LCDC_LCDCFG5_MODE_OUTPUT_24BPP (0x3u << 8) /**< \brief (LCDC_LCDCFG5) LCD Output mode is set to 24 bits per pixel */
#define LCDC_LCDCFG5_VSPSU (0x1u << 12) /**< \brief (LCDC_LCDCFG5) LCD Controller Vertical synchronization Pulse Setup Configuration */
#define LCDC_LCDCFG5_VSPHO (0x1u << 13) /**< \brief (LCDC_LCDCFG5) LCD Controller Vertical synchronization Pulse Hold Configuration */
#define LCDC_LCDCFG5_GUARDTIME_Pos 16
#define LCDC_LCDCFG5_GUARDTIME_Msk (0xffu << LCDC_LCDCFG5_GUARDTIME_Pos) /**< \brief (LCDC_LCDCFG5) LCD DISPLAY Guard Time */
#define LCDC_LCDCFG5_GUARDTIME(value) ((LCDC_LCDCFG5_GUARDTIME_Msk & ((value) << LCDC_LCDCFG5_GUARDTIME_Pos)))
/* -------- LCDC_LCDCFG6 : (LCDC Offset: 0x18) LCD Controller Configuration Register 6 -------- */
#define LCDC_LCDCFG6_PWMPS_Pos 0
#define LCDC_LCDCFG6_PWMPS_Msk (0x7u << LCDC_LCDCFG6_PWMPS_Pos) /**< \brief (LCDC_LCDCFG6) PWM Clock Prescaler */
#define LCDC_LCDCFG6_PWMPS(value) ((LCDC_LCDCFG6_PWMPS_Msk & ((value) << LCDC_LCDCFG6_PWMPS_Pos)))
#define   LCDC_LCDCFG6_PWMPS_DIV_1 (0x0u << 0) /**< \brief (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK */
#define   LCDC_LCDCFG6_PWMPS_DIV_2 (0x1u << 0) /**< \brief (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/2 */
#define   LCDC_LCDCFG6_PWMPS_DIV_4 (0x2u << 0) /**< \brief (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/4 */
#define   LCDC_LCDCFG6_PWMPS_DIV_8 (0x3u << 0) /**< \brief (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/8 */
#define   LCDC_LCDCFG6_PWMPS_DIV_16 (0x4u << 0) /**< \brief (LCDC_LCDCFG6) The counter advances at a rate of fCOUNTER = fPWM_SELECTED_CLOCK/16 */
#define   LCDC_LCDCFG6_PWMPS_DIV_32 (0x5u << 0) /**< \brief (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/32 */
#define   LCDC_LCDCFG6_PWMPS_DIV_64 (0x6u << 0) /**< \brief (LCDC_LCDCFG6) The counter advances at a of rate fCOUNTER = fPWM_SELECTED_CLOCK/64 */
#define LCDC_LCDCFG6_PWMPOL (0x1u << 4) /**< \brief (LCDC_LCDCFG6) LCD Controller PWM Signal Polarity */
#define LCDC_LCDCFG6_PWMCVAL_Pos 8
#define LCDC_LCDCFG6_PWMCVAL_Msk (0xffu << LCDC_LCDCFG6_PWMCVAL_Pos) /**< \brief (LCDC_LCDCFG6) LCD Controller PWM Compare Value */
#define LCDC_LCDCFG6_PWMCVAL(value) ((LCDC_LCDCFG6_PWMCVAL_Msk & ((value) << LCDC_LCDCFG6_PWMCVAL_Pos)))
/* -------- LCDC_LCDCFG7 : (LCDC Offset: 0x1C) LCD Controller Configuration Register 7 -------- */
#define LCDC_LCDCFG7_ROW_Pos 0
#define LCDC_LCDCFG7_ROW_Msk (0x7ffu << LCDC_LCDCFG7_ROW_Pos) /**< \brief (LCDC_LCDCFG7) Row Identifier For Row Interrupt Signal */
#define LCDC_LCDCFG7_ROW(value) ((LCDC_LCDCFG7_ROW_Msk & ((value) << LCDC_LCDCFG7_ROW_Pos)))
/* -------- LCDC_LCDEN : (LCDC Offset: 0x20) LCD Controller Enable Register -------- */
#define LCDC_LCDEN_CLKEN (0x1u << 0) /**< \brief (LCDC_LCDEN) LCD Controller Pixel Clock Enable */
#define LCDC_LCDEN_SYNCEN (0x1u << 1) /**< \brief (LCDC_LCDEN) LCD Controller Horizontal and Vertical Synchronization Enable */
#define LCDC_LCDEN_DISPEN (0x1u << 2) /**< \brief (LCDC_LCDEN) LCD Controller DISP Signal Enable */
#define LCDC_LCDEN_PWMEN (0x1u << 3) /**< \brief (LCDC_LCDEN) LCD Controller Pulse Width Modulation Enable */
/* -------- LCDC_LCDDIS : (LCDC Offset: 0x24) LCD Controller Disable Register -------- */
#define LCDC_LCDDIS_CLKDIS (0x1u << 0) /**< \brief (LCDC_LCDDIS) LCD Controller Pixel Clock Disable */
#define LCDC_LCDDIS_SYNCDIS (0x1u << 1) /**< \brief (LCDC_LCDDIS) LCD Controller Horizontal and Vertical Synchronization Disable */
#define LCDC_LCDDIS_DISPDIS (0x1u << 2) /**< \brief (LCDC_LCDDIS) LCD Controller DISP Signal Disable */
#define LCDC_LCDDIS_PWMDIS (0x1u << 3) /**< \brief (LCDC_LCDDIS) LCD Controller Pulse Width Modulation Disable */
#define LCDC_LCDDIS_CLKRST (0x1u << 8) /**< \brief (LCDC_LCDDIS) LCD Controller Clock Reset */
#define LCDC_LCDDIS_SYNCRST (0x1u << 9) /**< \brief (LCDC_LCDDIS) LCD Controller Horizontal and Vertical Synchronization Reset */
#define LCDC_LCDDIS_DISPRST (0x1u << 10) /**< \brief (LCDC_LCDDIS) LCD Controller DISP Signal Reset */
#define LCDC_LCDDIS_PWMRST (0x1u << 11) /**< \brief (LCDC_LCDDIS) LCD Controller PWM Reset */
/* -------- LCDC_LCDSR : (LCDC Offset: 0x28) LCD Controller Status Register -------- */
#define LCDC_LCDSR_CLKSTS (0x1u << 0) /**< \brief (LCDC_LCDSR) Clock Status */
#define LCDC_LCDSR_LCDSTS (0x1u << 1) /**< \brief (LCDC_LCDSR) LCD Controller Synchronization status */
#define LCDC_LCDSR_DISPSTS (0x1u << 2) /**< \brief (LCDC_LCDSR) LCD Controller DISP Signal Status */
#define LCDC_LCDSR_PWMSTS (0x1u << 3) /**< \brief (LCDC_LCDSR) LCD Controller PWM Signal Status */
#define LCDC_LCDSR_SIPSTS (0x1u << 4) /**< \brief (LCDC_LCDSR) Synchronization In Progress */
/* -------- LCDC_LCDIER : (LCDC Offset: 0x2C) LCD Controller Interrupt Enable Register -------- */
#define LCDC_LCDIER_SOFIE (0x1u << 0) /**< \brief (LCDC_LCDIER) Start of Frame Interrupt Enable */
#define LCDC_LCDIER_DISIE (0x1u << 1) /**< \brief (LCDC_LCDIER) LCD Disable Interrupt Enable */
#define LCDC_LCDIER_DISPIE (0x1u << 2) /**< \brief (LCDC_LCDIER) Powerup/Powerdown Sequence Terminated Interrupt Enable */
#define LCDC_LCDIER_ROWIE (0x1u << 3) /**< \brief (LCDC_LCDIER) Row Interrupt Enable */
#define LCDC_LCDIER_FIFOERRIE (0x1u << 4) /**< \brief (LCDC_LCDIER) Output FIFO Error Interrupt Enable */
#define LCDC_LCDIER_BASEIE (0x1u << 8) /**< \brief (LCDC_LCDIER) Base Layer Interrupt Enable */
#define LCDC_LCDIER_OVR1IE (0x1u << 9) /**< \brief (LCDC_LCDIER) Overlay 1 Interrupt Enable */
#define LCDC_LCDIER_OVR2IE (0x1u << 10) /**< \brief (LCDC_LCDIER) Overlay 2 Interrupt Enable */
#define LCDC_LCDIER_HEOIE (0x1u << 11) /**< \brief (LCDC_LCDIER) High-End Overlay Interrupt Enable */
/* -------- LCDC_LCDIDR : (LCDC Offset: 0x30) LCD Controller Interrupt Disable Register -------- */
#define LCDC_LCDIDR_SOFID (0x1u << 0) /**< \brief (LCDC_LCDIDR) Start of Frame Interrupt Disable */
#define LCDC_LCDIDR_DISID (0x1u << 1) /**< \brief (LCDC_LCDIDR) LCD Disable Interrupt Disable */
#define LCDC_LCDIDR_DISPID (0x1u << 2) /**< \brief (LCDC_LCDIDR) Powerup/Powerdown Sequence Terminated Interrupt Disable */
#define LCDC_LCDIDR_ROWID (0x1u << 3) /**< \brief (LCDC_LCDIDR) Row Interrupt Disable */
#define LCDC_LCDIDR_FIFOERRID (0x1u << 4) /**< \brief (LCDC_LCDIDR) Output FIFO Error Interrupt Disable */
#define LCDC_LCDIDR_BASEID (0x1u << 8) /**< \brief (LCDC_LCDIDR) Base Layer Interrupt Disable */
#define LCDC_LCDIDR_OVR1ID (0x1u << 9) /**< \brief (LCDC_LCDIDR) Overlay 1 Interrupt Disable */
#define LCDC_LCDIDR_OVR2ID (0x1u << 10) /**< \brief (LCDC_LCDIDR) Overlay 2 Interrupt Disable */
#define LCDC_LCDIDR_HEOID (0x1u << 11) /**< \brief (LCDC_LCDIDR) High-End Overlay Interrupt Disable */
/* -------- LCDC_LCDIMR : (LCDC Offset: 0x34) LCD Controller Interrupt Mask Register -------- */
#define LCDC_LCDIMR_SOFIM (0x1u << 0) /**< \brief (LCDC_LCDIMR) Start of Frame Interrupt Mask */
#define LCDC_LCDIMR_DISIM (0x1u << 1) /**< \brief (LCDC_LCDIMR) LCD Disable Interrupt Mask */
#define LCDC_LCDIMR_DISPIM (0x1u << 2) /**< \brief (LCDC_LCDIMR) Powerup/Powerdown Sequence Terminated Interrupt Mask */
#define LCDC_LCDIMR_ROWIM (0x1u << 3) /**< \brief (LCDC_LCDIMR) Row Interrupt Mask */
#define LCDC_LCDIMR_FIFOERRIM (0x1u << 4) /**< \brief (LCDC_LCDIMR) Output FIFO Error Interrupt Mask */
#define LCDC_LCDIMR_BASEIM (0x1u << 8) /**< \brief (LCDC_LCDIMR) Base Layer Interrupt Mask */
#define LCDC_LCDIMR_OVR1IM (0x1u << 9) /**< \brief (LCDC_LCDIMR) Overlay 1 Interrupt Mask */
#define LCDC_LCDIMR_OVR2IM (0x1u << 10) /**< \brief (LCDC_LCDIMR) Overlay 2 Interrupt Mask */
#define LCDC_LCDIMR_HEOIM (0x1u << 11) /**< \brief (LCDC_LCDIMR) High-End Overlay Interrupt Mask */
/* -------- LCDC_LCDISR : (LCDC Offset: 0x38) LCD Controller Interrupt Status Register -------- */
#define LCDC_LCDISR_SOF (0x1u << 0) /**< \brief (LCDC_LCDISR) Start of Frame Interrupt Status */
#define LCDC_LCDISR_DIS (0x1u << 1) /**< \brief (LCDC_LCDISR) LCD Disable Interrupt Status */
#define LCDC_LCDISR_DISP (0x1u << 2) /**< \brief (LCDC_LCDISR) Powerup/Powerdown Sequence Terminated Interrupt Status */
#define LCDC_LCDISR_ROW (0x1u << 3) /**< \brief (LCDC_LCDISR) Row Interrupt Status */
#define LCDC_LCDISR_FIFOERR (0x1u << 4) /**< \brief (LCDC_LCDISR) Output FIFO Error */
#define LCDC_LCDISR_BASE (0x1u << 8) /**< \brief (LCDC_LCDISR) Base Layer Raw Interrupt Status */
#define LCDC_LCDISR_OVR1 (0x1u << 9) /**< \brief (LCDC_LCDISR) Overlay 1 Raw Interrupt Status */
#define LCDC_LCDISR_OVR2 (0x1u << 10) /**< \brief (LCDC_LCDISR) Overlay 2 Raw Interrupt Status */
#define LCDC_LCDISR_HEO (0x1u << 11) /**< \brief (LCDC_LCDISR) High-End Overlay Raw Interrupt Status */
/* -------- LCDC_ATTR : (LCDC Offset: 0x3C) LCD Controller Attribute Register -------- */
#define LCDC_ATTR_BASE (0x1u << 0) /**< \brief (LCDC_ATTR) Base Layer Update Attribute */
#define LCDC_ATTR_OVR1 (0x1u << 1) /**< \brief (LCDC_ATTR) Overlay 1 Update Attribute */
#define LCDC_ATTR_OVR2 (0x1u << 2) /**< \brief (LCDC_ATTR) Overlay 2 Update Attribute */
#define LCDC_ATTR_HEO (0x1u << 3) /**< \brief (LCDC_ATTR) High-End Overlay Update Attribute */
#define LCDC_ATTR_BASEA2Q (0x1u << 8) /**< \brief (LCDC_ATTR) Base Layer Update Add To Queue */
#define LCDC_ATTR_OVR1A2Q (0x1u << 9) /**< \brief (LCDC_ATTR) Overlay 1 Update Add To Queue */
#define LCDC_ATTR_OVR2A2Q (0x1u << 10) /**< \brief (LCDC_ATTR) Overlay 2 Update Add to Queue */
#define LCDC_ATTR_HEOA2Q (0x1u << 11) /**< \brief (LCDC_ATTR) High-End Overlay Update Add To Queue */
/* -------- LCDC_QOSCFG : (LCDC Offset: 0x40) LCD Controller QoS Configuration Register -------- */
#define LCDC_QOSCFG_QOSLOCK (0x1u << 0) /**< \brief (LCDC_QOSCFG) Quality Of Service Lock */
#define LCDC_QOSCFG_QOS1CFG_Pos 4
#define LCDC_QOSCFG_QOS1CFG_Msk (0x3u << LCDC_QOSCFG_QOS1CFG_Pos) /**< \brief (LCDC_QOSCFG) Quality Of Service for 0 to 1 Transition */
#define LCDC_QOSCFG_QOS1CFG(value) ((LCDC_QOSCFG_QOS1CFG_Msk & ((value) << LCDC_QOSCFG_QOS1CFG_Pos)))
#define LCDC_QOSCFG_QOS2CFG_Pos 8
#define LCDC_QOSCFG_QOS2CFG_Msk (0x3u << LCDC_QOSCFG_QOS2CFG_Pos) /**< \brief (LCDC_QOSCFG) Quality Of Service for 1 to 2 Transition */
#define LCDC_QOSCFG_QOS2CFG(value) ((LCDC_QOSCFG_QOS2CFG_Msk & ((value) << LCDC_QOSCFG_QOS2CFG_Pos)))
#define LCDC_QOSCFG_QOS3CFG_Pos 12
#define LCDC_QOSCFG_QOS3CFG_Msk (0x3u << LCDC_QOSCFG_QOS3CFG_Pos) /**< \brief (LCDC_QOSCFG) Quality Of Service for 2 to 3 Transition */
#define LCDC_QOSCFG_QOS3CFG(value) ((LCDC_QOSCFG_QOS3CFG_Msk & ((value) << LCDC_QOSCFG_QOS3CFG_Pos)))
/* -------- LCDC_QOS1M : (LCDC Offset: 0x44) LCD Controller QoS 1 Metrics Register -------- */
#define LCDC_QOS1M_MET1_Pos 0
#define LCDC_QOS1M_MET1_Msk (0xfffffu << LCDC_QOS1M_MET1_Pos) /**< \brief (LCDC_QOS1M) Metrics QoS 1 */
/* -------- LCDC_QOS2M : (LCDC Offset: 0x48) LCD Controller QoS 2 Metrics Register -------- */
#define LCDC_QOS2M_MET2_Pos 0
#define LCDC_QOS2M_MET2_Msk (0xfffffu << LCDC_QOS2M_MET2_Pos) /**< \brief (LCDC_QOS2M) Metrics QoS 2 */
/* -------- LCDC_QOS3M : (LCDC Offset: 0x4C) LCD Controller QoS 3 Metrics Register -------- */
#define LCDC_QOS3M_MET3_Pos 0
#define LCDC_QOS3M_MET3_Msk (0xfffffu << LCDC_QOS3M_MET3_Pos) /**< \brief (LCDC_QOS3M) Metrics QoS 3 */
/* -------- LCDC_QOSMIN : (LCDC Offset: 0x50) LCD Controller QoS Min FIFO Level Register -------- */
#define LCDC_QOSMIN_LEVEL_Pos 0
#define LCDC_QOSMIN_LEVEL_Msk (0x1ffu << LCDC_QOSMIN_LEVEL_Pos) /**< \brief (LCDC_QOSMIN) Minimum FIFO Level */
/* -------- LCDC_BASECHER : (LCDC Offset: 0x60) Base Layer Channel Enable Register -------- */
#define LCDC_BASECHER_CHEN (0x1u << 0) /**< \brief (LCDC_BASECHER) Channel Enable */
#define LCDC_BASECHER_UPDATEEN (0x1u << 1) /**< \brief (LCDC_BASECHER) Update Overlay Attributes Enable */
#define LCDC_BASECHER_A2QEN (0x1u << 2) /**< \brief (LCDC_BASECHER) Add To Queue Enable */
/* -------- LCDC_BASECHDR : (LCDC Offset: 0x64) Base Layer Channel Disable Register -------- */
#define LCDC_BASECHDR_CHDIS (0x1u << 0) /**< \brief (LCDC_BASECHDR) Channel Disable */
#define LCDC_BASECHDR_CHRST (0x1u << 8) /**< \brief (LCDC_BASECHDR) Channel Reset */
/* -------- LCDC_BASECHSR : (LCDC Offset: 0x68) Base Layer Channel Status Register -------- */
#define LCDC_BASECHSR_CHSR (0x1u << 0) /**< \brief (LCDC_BASECHSR) Channel Status */
#define LCDC_BASECHSR_UPDATESR (0x1u << 1) /**< \brief (LCDC_BASECHSR) Update Overlay Attributes In Progress Status */
#define LCDC_BASECHSR_A2QSR (0x1u << 2) /**< \brief (LCDC_BASECHSR) Add To Queue Status */
/* -------- LCDC_BASEIER : (LCDC Offset: 0x6C) Base Layer Interrupt Enable Register -------- */
#define LCDC_BASEIER_DMA (0x1u << 2) /**< \brief (LCDC_BASEIER) End of DMA Transfer Interrupt Enable */
#define LCDC_BASEIER_DSCR (0x1u << 3) /**< \brief (LCDC_BASEIER) Descriptor Loaded Interrupt Enable */
#define LCDC_BASEIER_ADD (0x1u << 4) /**< \brief (LCDC_BASEIER) Head Descriptor Loaded Interrupt Enable */
#define LCDC_BASEIER_DONE (0x1u << 5) /**< \brief (LCDC_BASEIER) End of List Interrupt Enable */
#define LCDC_BASEIER_OVR (0x1u << 6) /**< \brief (LCDC_BASEIER) Overflow Interrupt Enable */
/* -------- LCDC_BASEIDR : (LCDC Offset: 0x70) Base Layer Interrupt Disabled Register -------- */
#define LCDC_BASEIDR_DMA (0x1u << 2) /**< \brief (LCDC_BASEIDR) End of DMA Transfer Interrupt Disable */
#define LCDC_BASEIDR_DSCR (0x1u << 3) /**< \brief (LCDC_BASEIDR) Descriptor Loaded Interrupt Disable */
#define LCDC_BASEIDR_ADD (0x1u << 4) /**< \brief (LCDC_BASEIDR) Head Descriptor Loaded Interrupt Disable */
#define LCDC_BASEIDR_DONE (0x1u << 5) /**< \brief (LCDC_BASEIDR) End of List Interrupt Disable */
#define LCDC_BASEIDR_OVR (0x1u << 6) /**< \brief (LCDC_BASEIDR) Overflow Interrupt Disable */
/* -------- LCDC_BASEIMR : (LCDC Offset: 0x74) Base Layer Interrupt Mask Register -------- */
#define LCDC_BASEIMR_DMA (0x1u << 2) /**< \brief (LCDC_BASEIMR) End of DMA Transfer Interrupt Mask */
#define LCDC_BASEIMR_DSCR (0x1u << 3) /**< \brief (LCDC_BASEIMR) Descriptor Loaded Interrupt Mask */
#define LCDC_BASEIMR_ADD (0x1u << 4) /**< \brief (LCDC_BASEIMR) Head Descriptor Loaded Interrupt Mask */
#define LCDC_BASEIMR_DONE (0x1u << 5) /**< \brief (LCDC_BASEIMR) End of List Interrupt Mask */
#define LCDC_BASEIMR_OVR (0x1u << 6) /**< \brief (LCDC_BASEIMR) Overflow Interrupt Mask */
/* -------- LCDC_BASEISR : (LCDC Offset: 0x78) Base Layer Interrupt Status Register -------- */
#define LCDC_BASEISR_DMA (0x1u << 2) /**< \brief (LCDC_BASEISR) End of DMA Transfer */
#define LCDC_BASEISR_DSCR (0x1u << 3) /**< \brief (LCDC_BASEISR) DMA Descriptor Loaded */
#define LCDC_BASEISR_ADD (0x1u << 4) /**< \brief (LCDC_BASEISR) Head Descriptor Loaded */
#define LCDC_BASEISR_DONE (0x1u << 5) /**< \brief (LCDC_BASEISR) End of List Detected */
#define LCDC_BASEISR_OVR (0x1u << 6) /**< \brief (LCDC_BASEISR) Overflow Detected */
/* -------- LCDC_BASEHEAD : (LCDC Offset: 0x7C) Base DMA Head Register -------- */
#define LCDC_BASEHEAD_HEAD_Pos 2
#define LCDC_BASEHEAD_HEAD_Msk (0x3fffffffu << LCDC_BASEHEAD_HEAD_Pos) /**< \brief (LCDC_BASEHEAD) DMA Head Pointer */
#define LCDC_BASEHEAD_HEAD(value) ((LCDC_BASEHEAD_HEAD_Msk & ((value) << LCDC_BASEHEAD_HEAD_Pos)))
/* -------- LCDC_BASEADDR : (LCDC Offset: 0x80) Base DMA Address Register -------- */
#define LCDC_BASEADDR_ADDR_Pos 0
#define LCDC_BASEADDR_ADDR_Msk (0xffffffffu << LCDC_BASEADDR_ADDR_Pos) /**< \brief (LCDC_BASEADDR) DMA Transfer Start Address */
#define LCDC_BASEADDR_ADDR(value) ((LCDC_BASEADDR_ADDR_Msk & ((value) << LCDC_BASEADDR_ADDR_Pos)))
/* -------- LCDC_BASECTRL : (LCDC Offset: 0x84) Base DMA Control Register -------- */
#define LCDC_BASECTRL_DFETCH (0x1u << 0) /**< \brief (LCDC_BASECTRL) Transfer Descriptor Fetch Enable */
#define LCDC_BASECTRL_LFETCH (0x1u << 1) /**< \brief (LCDC_BASECTRL) Lookup Table Fetch Enable */
#define LCDC_BASECTRL_DMAIEN (0x1u << 2) /**< \brief (LCDC_BASECTRL) End of DMA Transfer Interrupt Enable */
#define LCDC_BASECTRL_DSCRIEN (0x1u << 3) /**< \brief (LCDC_BASECTRL) Descriptor Loaded Interrupt Enable */
#define LCDC_BASECTRL_ADDIEN (0x1u << 4) /**< \brief (LCDC_BASECTRL) Add Head Descriptor to Queue Interrupt Enable */
#define LCDC_BASECTRL_DONEIEN (0x1u << 5) /**< \brief (LCDC_BASECTRL) End of List Interrupt Enable */
/* -------- LCDC_BASENEXT : (LCDC Offset: 0x88) Base DMA Next Register -------- */
#define LCDC_BASENEXT_NEXT_Pos 0
#define LCDC_BASENEXT_NEXT_Msk (0xffffffffu << LCDC_BASENEXT_NEXT_Pos) /**< \brief (LCDC_BASENEXT) DMA Descriptor Next Address */
#define LCDC_BASENEXT_NEXT(value) ((LCDC_BASENEXT_NEXT_Msk & ((value) << LCDC_BASENEXT_NEXT_Pos)))
/* -------- LCDC_BASECFG0 : (LCDC Offset: 0x8C) Base Layer Configuration Register 0 -------- */
#define LCDC_BASECFG0_BLEN_Pos 4
#define LCDC_BASECFG0_BLEN_Msk (0x3u << LCDC_BASECFG0_BLEN_Pos) /**< \brief (LCDC_BASECFG0) System Bus Burst Length */
#define LCDC_BASECFG0_BLEN(value) ((LCDC_BASECFG0_BLEN_Msk & ((value) << LCDC_BASECFG0_BLEN_Pos)))
#define   LCDC_BASECFG0_BLEN_AHB_SINGLE (0x0u << 4) /**< \brief (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_BASECFG0_BLEN_AHB_INCR4 (0x1u << 4) /**< \brief (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used. SINGLE, INCR and INCR4 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_BASECFG0_BLEN_AHB_INCR8 (0x2u << 4) /**< \brief (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used. SINGLE, INCR, INCR4 and INCR8 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_BASECFG0_BLEN_AHB_INCR16 (0x3u << 4) /**< \brief (LCDC_BASECFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define LCDC_BASECFG0_DLBO (0x1u << 8) /**< \brief (LCDC_BASECFG0) defined length Burst Only For Channel Bus Transaction */
/* -------- LCDC_BASECFG1 : (LCDC Offset: 0x90) Base Layer Configuration Register 1 -------- */
#define LCDC_BASECFG1_CLUTEN (0x1u << 0) /**< \brief (LCDC_BASECFG1) Color Lookup Table Mode Enable */
#define LCDC_BASECFG1_RGBMODE_Pos 4
#define LCDC_BASECFG1_RGBMODE_Msk (0xfu << LCDC_BASECFG1_RGBMODE_Pos) /**< \brief (LCDC_BASECFG1) RGB Mode Input Selection */
#define LCDC_BASECFG1_RGBMODE(value) ((LCDC_BASECFG1_RGBMODE_Msk & ((value) << LCDC_BASECFG1_RGBMODE_Pos)))
#define   LCDC_BASECFG1_RGBMODE_12BPP_RGB_444 (0x0u << 4) /**< \brief (LCDC_BASECFG1) 12 bpp RGB 444 */
#define   LCDC_BASECFG1_RGBMODE_16BPP_ARGB_4444 (0x1u << 4) /**< \brief (LCDC_BASECFG1) 16 bpp ARGB 4444 */
#define   LCDC_BASECFG1_RGBMODE_16BPP_RGBA_4444 (0x2u << 4) /**< \brief (LCDC_BASECFG1) 16 bpp RGBA 4444 */
#define   LCDC_BASECFG1_RGBMODE_16BPP_RGB_565 (0x3u << 4) /**< \brief (LCDC_BASECFG1) 16 bpp RGB 565 */
#define   LCDC_BASECFG1_RGBMODE_16BPP_TRGB_1555 (0x4u << 4) /**< \brief (LCDC_BASECFG1) 16 bpp TRGB 1555 */
#define   LCDC_BASECFG1_RGBMODE_18BPP_RGB_666 (0x5u << 4) /**< \brief (LCDC_BASECFG1) 18 bpp RGB 666 */
#define   LCDC_BASECFG1_RGBMODE_18BPP_RGB_666_PACKED (0x6u << 4) /**< \brief (LCDC_BASECFG1) 18 bpp RGB 666 PACKED */
#define   LCDC_BASECFG1_RGBMODE_19BPP_TRGB_1666 (0x7u << 4) /**< \brief (LCDC_BASECFG1) 19 bpp TRGB 1666 */
#define   LCDC_BASECFG1_RGBMODE_19BPP_TRGB_PACKED (0x8u << 4) /**< \brief (LCDC_BASECFG1) 19 bpp TRGB 1666 PACKED */
#define   LCDC_BASECFG1_RGBMODE_24BPP_RGB_888 (0x9u << 4) /**< \brief (LCDC_BASECFG1) 24 bpp RGB 888 */
#define   LCDC_BASECFG1_RGBMODE_24BPP_RGB_888_PACKED (0xAu << 4) /**< \brief (LCDC_BASECFG1) 24 bpp RGB 888 PACKED */
#define   LCDC_BASECFG1_RGBMODE_25BPP_TRGB_1888 (0xBu << 4) /**< \brief (LCDC_BASECFG1) 25 bpp TRGB 1888 */
#define   LCDC_BASECFG1_RGBMODE_32BPP_ARGB_8888 (0xCu << 4) /**< \brief (LCDC_BASECFG1) 32 bpp ARGB 8888 */
#define   LCDC_BASECFG1_RGBMODE_32BPP_RGBA_8888 (0xDu << 4) /**< \brief (LCDC_BASECFG1) 32 bpp RGBA 8888 */
#define LCDC_BASECFG1_CLUTMODE_Pos 8
#define LCDC_BASECFG1_CLUTMODE_Msk (0x3u << LCDC_BASECFG1_CLUTMODE_Pos) /**< \brief (LCDC_BASECFG1) Color Lookup Table Mode Input Selection */
#define LCDC_BASECFG1_CLUTMODE(value) ((LCDC_BASECFG1_CLUTMODE_Msk & ((value) << LCDC_BASECFG1_CLUTMODE_Pos)))
#define   LCDC_BASECFG1_CLUTMODE_1BPP (0x0u << 8) /**< \brief (LCDC_BASECFG1) Color Lookup Table mode set to 1 bit per pixel */
#define   LCDC_BASECFG1_CLUTMODE_2BPP (0x1u << 8) /**< \brief (LCDC_BASECFG1) Color Lookup Table mode set to 2 bits per pixel */
#define   LCDC_BASECFG1_CLUTMODE_4BPP (0x2u << 8) /**< \brief (LCDC_BASECFG1) Color Lookup Table mode set to 4 bits per pixel */
#define   LCDC_BASECFG1_CLUTMODE_8BPP (0x3u << 8) /**< \brief (LCDC_BASECFG1) Color Lookup Table mode set to 8 bits per pixel */
/* -------- LCDC_BASECFG2 : (LCDC Offset: 0x94) Base Layer Configuration Register 2 -------- */
#define LCDC_BASECFG2_XSTRIDE_Pos 0
#define LCDC_BASECFG2_XSTRIDE_Msk (0xffffffffu << LCDC_BASECFG2_XSTRIDE_Pos) /**< \brief (LCDC_BASECFG2) Horizontal Stride */
#define LCDC_BASECFG2_XSTRIDE(value) ((LCDC_BASECFG2_XSTRIDE_Msk & ((value) << LCDC_BASECFG2_XSTRIDE_Pos)))
/* -------- LCDC_BASECFG3 : (LCDC Offset: 0x98) Base Layer Configuration Register 3 -------- */
#define LCDC_BASECFG3_BDEF_Pos 0
#define LCDC_BASECFG3_BDEF_Msk (0xffu << LCDC_BASECFG3_BDEF_Pos) /**< \brief (LCDC_BASECFG3) Blue Default */
#define LCDC_BASECFG3_BDEF(value) ((LCDC_BASECFG3_BDEF_Msk & ((value) << LCDC_BASECFG3_BDEF_Pos)))
#define LCDC_BASECFG3_GDEF_Pos 8
#define LCDC_BASECFG3_GDEF_Msk (0xffu << LCDC_BASECFG3_GDEF_Pos) /**< \brief (LCDC_BASECFG3) Green Default */
#define LCDC_BASECFG3_GDEF(value) ((LCDC_BASECFG3_GDEF_Msk & ((value) << LCDC_BASECFG3_GDEF_Pos)))
#define LCDC_BASECFG3_RDEF_Pos 16
#define LCDC_BASECFG3_RDEF_Msk (0xffu << LCDC_BASECFG3_RDEF_Pos) /**< \brief (LCDC_BASECFG3) Red Default */
#define LCDC_BASECFG3_RDEF(value) ((LCDC_BASECFG3_RDEF_Msk & ((value) << LCDC_BASECFG3_RDEF_Pos)))
/* -------- LCDC_BASECFG4 : (LCDC Offset: 0x9C) Base Layer Configuration Register 4 -------- */
#define LCDC_BASECFG4_DMA (0x1u << 8) /**< \brief (LCDC_BASECFG4) Use DMA Data Path */
#define LCDC_BASECFG4_REP (0x1u << 9) /**< \brief (LCDC_BASECFG4) Use Replication logic to expand RGB color to 24 bits */
#define LCDC_BASECFG4_DISCEN (0x1u << 11) /**< \brief (LCDC_BASECFG4) Discard Area Enable */
/* -------- LCDC_BASECFG5 : (LCDC Offset: 0xA0) Base Layer Configuration Register 5 -------- */
#define LCDC_BASECFG5_DISCXPOS_Pos 0
#define LCDC_BASECFG5_DISCXPOS_Msk (0x7ffu << LCDC_BASECFG5_DISCXPOS_Pos) /**< \brief (LCDC_BASECFG5) Discard Area Horizontal Coordinate */
#define LCDC_BASECFG5_DISCXPOS(value) ((LCDC_BASECFG5_DISCXPOS_Msk & ((value) << LCDC_BASECFG5_DISCXPOS_Pos)))
#define LCDC_BASECFG5_DISCYPOS_Pos 16
#define LCDC_BASECFG5_DISCYPOS_Msk (0x7ffu << LCDC_BASECFG5_DISCYPOS_Pos) /**< \brief (LCDC_BASECFG5) Discard Area Vertical Coordinate */
#define LCDC_BASECFG5_DISCYPOS(value) ((LCDC_BASECFG5_DISCYPOS_Msk & ((value) << LCDC_BASECFG5_DISCYPOS_Pos)))
/* -------- LCDC_BASECFG6 : (LCDC Offset: 0xA4) Base Layer Configuration Register 6 -------- */
#define LCDC_BASECFG6_DISCXSIZE_Pos 0
#define LCDC_BASECFG6_DISCXSIZE_Msk (0x7ffu << LCDC_BASECFG6_DISCXSIZE_Pos) /**< \brief (LCDC_BASECFG6) Discard Area Horizontal Size */
#define LCDC_BASECFG6_DISCXSIZE(value) ((LCDC_BASECFG6_DISCXSIZE_Msk & ((value) << LCDC_BASECFG6_DISCXSIZE_Pos)))
#define LCDC_BASECFG6_DISCYSIZE_Pos 16
#define LCDC_BASECFG6_DISCYSIZE_Msk (0x7ffu << LCDC_BASECFG6_DISCYSIZE_Pos) /**< \brief (LCDC_BASECFG6) Discard Area Vertical Size */
#define LCDC_BASECFG6_DISCYSIZE(value) ((LCDC_BASECFG6_DISCYSIZE_Msk & ((value) << LCDC_BASECFG6_DISCYSIZE_Pos)))
/* -------- LCDC_OVR1CHER : (LCDC Offset: 0x160) Overlay 1 Channel Enable Register -------- */
#define LCDC_OVR1CHER_CHEN (0x1u << 0) /**< \brief (LCDC_OVR1CHER) Channel Enable */
#define LCDC_OVR1CHER_UPDATEEN (0x1u << 1) /**< \brief (LCDC_OVR1CHER) Update Overlay Attributes Enable */
#define LCDC_OVR1CHER_A2QEN (0x1u << 2) /**< \brief (LCDC_OVR1CHER) Add To Queue Enable */
/* -------- LCDC_OVR1CHDR : (LCDC Offset: 0x164) Overlay 1 Channel Disable Register -------- */
#define LCDC_OVR1CHDR_CHDIS (0x1u << 0) /**< \brief (LCDC_OVR1CHDR) Channel Disable */
#define LCDC_OVR1CHDR_CHRST (0x1u << 8) /**< \brief (LCDC_OVR1CHDR) Channel Reset */
/* -------- LCDC_OVR1CHSR : (LCDC Offset: 0x168) Overlay 1 Channel Status Register -------- */
#define LCDC_OVR1CHSR_CHSR (0x1u << 0) /**< \brief (LCDC_OVR1CHSR) Channel Status */
#define LCDC_OVR1CHSR_UPDATESR (0x1u << 1) /**< \brief (LCDC_OVR1CHSR) Update Overlay Attributes In Progress Status */
#define LCDC_OVR1CHSR_A2QSR (0x1u << 2) /**< \brief (LCDC_OVR1CHSR) Add To Queue Status */
/* -------- LCDC_OVR1IER : (LCDC Offset: 0x16C) Overlay 1 Interrupt Enable Register -------- */
#define LCDC_OVR1IER_DMA (0x1u << 2) /**< \brief (LCDC_OVR1IER) End of DMA Transfer Interrupt Enable */
#define LCDC_OVR1IER_DSCR (0x1u << 3) /**< \brief (LCDC_OVR1IER) Descriptor Loaded Interrupt Enable */
#define LCDC_OVR1IER_ADD (0x1u << 4) /**< \brief (LCDC_OVR1IER) Head Descriptor Loaded Interrupt Enable */
#define LCDC_OVR1IER_DONE (0x1u << 5) /**< \brief (LCDC_OVR1IER) End of List Interrupt Enable */
#define LCDC_OVR1IER_OVR (0x1u << 6) /**< \brief (LCDC_OVR1IER) Overflow Interrupt Enable */
/* -------- LCDC_OVR1IDR : (LCDC Offset: 0x170) Overlay 1 Interrupt Disable Register -------- */
#define LCDC_OVR1IDR_DMA (0x1u << 2) /**< \brief (LCDC_OVR1IDR) End of DMA Transfer Interrupt Disable */
#define LCDC_OVR1IDR_DSCR (0x1u << 3) /**< \brief (LCDC_OVR1IDR) Descriptor Loaded Interrupt Disable */
#define LCDC_OVR1IDR_ADD (0x1u << 4) /**< \brief (LCDC_OVR1IDR) Head Descriptor Loaded Interrupt Disable */
#define LCDC_OVR1IDR_DONE (0x1u << 5) /**< \brief (LCDC_OVR1IDR) End of List Interrupt Disable */
#define LCDC_OVR1IDR_OVR (0x1u << 6) /**< \brief (LCDC_OVR1IDR) Overflow Interrupt Disable */
/* -------- LCDC_OVR1IMR : (LCDC Offset: 0x174) Overlay 1 Interrupt Mask Register -------- */
#define LCDC_OVR1IMR_DMA (0x1u << 2) /**< \brief (LCDC_OVR1IMR) End of DMA Transfer Interrupt Mask */
#define LCDC_OVR1IMR_DSCR (0x1u << 3) /**< \brief (LCDC_OVR1IMR) Descriptor Loaded Interrupt Mask */
#define LCDC_OVR1IMR_ADD (0x1u << 4) /**< \brief (LCDC_OVR1IMR) Head Descriptor Loaded Interrupt Mask */
#define LCDC_OVR1IMR_DONE (0x1u << 5) /**< \brief (LCDC_OVR1IMR) End of List Interrupt Mask */
#define LCDC_OVR1IMR_OVR (0x1u << 6) /**< \brief (LCDC_OVR1IMR) Overflow Interrupt Mask */
/* -------- LCDC_OVR1ISR : (LCDC Offset: 0x178) Overlay 1 Interrupt Status Register -------- */
#define LCDC_OVR1ISR_DMA (0x1u << 2) /**< \brief (LCDC_OVR1ISR) End of DMA Transfer */
#define LCDC_OVR1ISR_DSCR (0x1u << 3) /**< \brief (LCDC_OVR1ISR) DMA Descriptor Loaded */
#define LCDC_OVR1ISR_ADD (0x1u << 4) /**< \brief (LCDC_OVR1ISR) Head Descriptor Loaded */
#define LCDC_OVR1ISR_DONE (0x1u << 5) /**< \brief (LCDC_OVR1ISR) End of List Detected */
#define LCDC_OVR1ISR_OVR (0x1u << 6) /**< \brief (LCDC_OVR1ISR) Overflow Detected */
/* -------- LCDC_OVR1HEAD : (LCDC Offset: 0x17C) Overlay 1 DMA Head Register -------- */
#define LCDC_OVR1HEAD_HEAD_Pos 2
#define LCDC_OVR1HEAD_HEAD_Msk (0x3fffffffu << LCDC_OVR1HEAD_HEAD_Pos) /**< \brief (LCDC_OVR1HEAD) DMA Head Pointer */
#define LCDC_OVR1HEAD_HEAD(value) ((LCDC_OVR1HEAD_HEAD_Msk & ((value) << LCDC_OVR1HEAD_HEAD_Pos)))
/* -------- LCDC_OVR1ADDR : (LCDC Offset: 0x180) Overlay 1 DMA Address Register -------- */
#define LCDC_OVR1ADDR_ADDR_Pos 0
#define LCDC_OVR1ADDR_ADDR_Msk (0xffffffffu << LCDC_OVR1ADDR_ADDR_Pos) /**< \brief (LCDC_OVR1ADDR) DMA Transfer Overlay 1 Address */
#define LCDC_OVR1ADDR_ADDR(value) ((LCDC_OVR1ADDR_ADDR_Msk & ((value) << LCDC_OVR1ADDR_ADDR_Pos)))
/* -------- LCDC_OVR1CTRL : (LCDC Offset: 0x184) Overlay 1 DMA Control Register -------- */
#define LCDC_OVR1CTRL_DFETCH (0x1u << 0) /**< \brief (LCDC_OVR1CTRL) Transfer Descriptor Fetch Enable */
#define LCDC_OVR1CTRL_LFETCH (0x1u << 1) /**< \brief (LCDC_OVR1CTRL) Lookup Table Fetch Enable */
#define LCDC_OVR1CTRL_DMAIEN (0x1u << 2) /**< \brief (LCDC_OVR1CTRL) End of DMA Transfer Interrupt Enable */
#define LCDC_OVR1CTRL_DSCRIEN (0x1u << 3) /**< \brief (LCDC_OVR1CTRL) Descriptor Loaded Interrupt Enable */
#define LCDC_OVR1CTRL_ADDIEN (0x1u << 4) /**< \brief (LCDC_OVR1CTRL) Add Head Descriptor to Queue Interrupt Enable */
#define LCDC_OVR1CTRL_DONEIEN (0x1u << 5) /**< \brief (LCDC_OVR1CTRL) End of List Interrupt Enable */
/* -------- LCDC_OVR1NEXT : (LCDC Offset: 0x188) Overlay 1 DMA Next Register -------- */
#define LCDC_OVR1NEXT_NEXT_Pos 0
#define LCDC_OVR1NEXT_NEXT_Msk (0xffffffffu << LCDC_OVR1NEXT_NEXT_Pos) /**< \brief (LCDC_OVR1NEXT) DMA Descriptor Next Address */
#define LCDC_OVR1NEXT_NEXT(value) ((LCDC_OVR1NEXT_NEXT_Msk & ((value) << LCDC_OVR1NEXT_NEXT_Pos)))
/* -------- LCDC_OVR1CFG0 : (LCDC Offset: 0x18C) Overlay 1 Configuration Register 0 -------- */
#define LCDC_OVR1CFG0_BLEN_Pos 4
#define LCDC_OVR1CFG0_BLEN_Msk (0x3u << LCDC_OVR1CFG0_BLEN_Pos) /**< \brief (LCDC_OVR1CFG0) System Bus Burst Length */
#define LCDC_OVR1CFG0_BLEN(value) ((LCDC_OVR1CFG0_BLEN_Msk & ((value) << LCDC_OVR1CFG0_BLEN_Pos)))
#define   LCDC_OVR1CFG0_BLEN_AHB_SINGLE (0x0u << 4) /**< \brief (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_OVR1CFG0_BLEN_AHB_INCR4 (0x1u << 4) /**< \brief (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. An AHB INCR4 Burst is used. SINGLE, INCR and INCR4 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_OVR1CFG0_BLEN_AHB_INCR8 (0x2u << 4) /**< \brief (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. An AHB INCR8 Burst is used. SINGLE, INCR, INCR4 and INCR8 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_OVR1CFG0_BLEN_AHB_INCR16 (0x3u << 4) /**< \brief (LCDC_OVR1CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. An AHB INCR16 Burst is used. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define LCDC_OVR1CFG0_DLBO (0x1u << 8) /**< \brief (LCDC_OVR1CFG0) defined length Burst Only for Channel Bus Transaction */
#define LCDC_OVR1CFG0_ROTDIS (0x1u << 12) /**< \brief (LCDC_OVR1CFG0) Hardware Rotation Optimization Disable */
#define LCDC_OVR1CFG0_LOCKDIS (0x1u << 13) /**< \brief (LCDC_OVR1CFG0) Hardware Rotation Lock Disable */
/* -------- LCDC_OVR1CFG1 : (LCDC Offset: 0x190) Overlay 1 Configuration Register 1 -------- */
#define LCDC_OVR1CFG1_CLUTEN (0x1u << 0) /**< \brief (LCDC_OVR1CFG1) Color Lookup Table Mode Enable */
#define LCDC_OVR1CFG1_RGBMODE_Pos 4
#define LCDC_OVR1CFG1_RGBMODE_Msk (0xfu << LCDC_OVR1CFG1_RGBMODE_Pos) /**< \brief (LCDC_OVR1CFG1) RGB Mode Input Selection */
#define LCDC_OVR1CFG1_RGBMODE(value) ((LCDC_OVR1CFG1_RGBMODE_Msk & ((value) << LCDC_OVR1CFG1_RGBMODE_Pos)))
#define   LCDC_OVR1CFG1_RGBMODE_12BPP_RGB_444 (0x0u << 4) /**< \brief (LCDC_OVR1CFG1) 12 bpp RGB 444 */
#define   LCDC_OVR1CFG1_RGBMODE_16BPP_ARGB_4444 (0x1u << 4) /**< \brief (LCDC_OVR1CFG1) 16 bpp ARGB 4444 */
#define   LCDC_OVR1CFG1_RGBMODE_16BPP_RGBA_4444 (0x2u << 4) /**< \brief (LCDC_OVR1CFG1) 16 bpp RGBA 4444 */
#define   LCDC_OVR1CFG1_RGBMODE_16BPP_RGB_565 (0x3u << 4) /**< \brief (LCDC_OVR1CFG1) 16 bpp RGB 565 */
#define   LCDC_OVR1CFG1_RGBMODE_16BPP_TRGB_1555 (0x4u << 4) /**< \brief (LCDC_OVR1CFG1) 16 bpp TRGB 1555 */
#define   LCDC_OVR1CFG1_RGBMODE_18BPP_RGB_666 (0x5u << 4) /**< \brief (LCDC_OVR1CFG1) 18 bpp RGB 666 */
#define   LCDC_OVR1CFG1_RGBMODE_18BPP_RGB_666_PACKED (0x6u << 4) /**< \brief (LCDC_OVR1CFG1) 18 bpp RGB 666 PACKED */
#define   LCDC_OVR1CFG1_RGBMODE_19BPP_TRGB_1666 (0x7u << 4) /**< \brief (LCDC_OVR1CFG1) 19 bpp TRGB 1666 */
#define   LCDC_OVR1CFG1_RGBMODE_19BPP_TRGB_PACKED (0x8u << 4) /**< \brief (LCDC_OVR1CFG1) 19 bpp TRGB 1666 PACKED */
#define   LCDC_OVR1CFG1_RGBMODE_24BPP_RGB_888 (0x9u << 4) /**< \brief (LCDC_OVR1CFG1) 24 bpp RGB 888 */
#define   LCDC_OVR1CFG1_RGBMODE_24BPP_RGB_888_PACKED (0xAu << 4) /**< \brief (LCDC_OVR1CFG1) 24 bpp RGB 888 PACKED */
#define   LCDC_OVR1CFG1_RGBMODE_25BPP_TRGB_1888 (0xBu << 4) /**< \brief (LCDC_OVR1CFG1) 25 bpp TRGB 1888 */
#define   LCDC_OVR1CFG1_RGBMODE_32BPP_ARGB_8888 (0xCu << 4) /**< \brief (LCDC_OVR1CFG1) 32 bpp ARGB 8888 */
#define   LCDC_OVR1CFG1_RGBMODE_32BPP_RGBA_8888 (0xDu << 4) /**< \brief (LCDC_OVR1CFG1) 32 bpp RGBA 8888 */
#define LCDC_OVR1CFG1_CLUTMODE_Pos 8
#define LCDC_OVR1CFG1_CLUTMODE_Msk (0x3u << LCDC_OVR1CFG1_CLUTMODE_Pos) /**< \brief (LCDC_OVR1CFG1) Color Lookup Table Mode Input Selection */
#define LCDC_OVR1CFG1_CLUTMODE(value) ((LCDC_OVR1CFG1_CLUTMODE_Msk & ((value) << LCDC_OVR1CFG1_CLUTMODE_Pos)))
#define   LCDC_OVR1CFG1_CLUTMODE_1BPP (0x0u << 8) /**< \brief (LCDC_OVR1CFG1) Color Lookup Table mode set to 1 bit per pixel */
#define   LCDC_OVR1CFG1_CLUTMODE_2BPP (0x1u << 8) /**< \brief (LCDC_OVR1CFG1) Color Lookup Table mode set to 2 bits per pixel */
#define   LCDC_OVR1CFG1_CLUTMODE_4BPP (0x2u << 8) /**< \brief (LCDC_OVR1CFG1) Color Lookup Table mode set to 4 bits per pixel */
#define   LCDC_OVR1CFG1_CLUTMODE_8BPP (0x3u << 8) /**< \brief (LCDC_OVR1CFG1) Color Lookup Table mode set to 8 bits per pixel */
/* -------- LCDC_OVR1CFG2 : (LCDC Offset: 0x194) Overlay 1 Configuration Register 2 -------- */
#define LCDC_OVR1CFG2_XPOS_Pos 0
#define LCDC_OVR1CFG2_XPOS_Msk (0x7ffu << LCDC_OVR1CFG2_XPOS_Pos) /**< \brief (LCDC_OVR1CFG2) Horizontal Window Position */
#define LCDC_OVR1CFG2_XPOS(value) ((LCDC_OVR1CFG2_XPOS_Msk & ((value) << LCDC_OVR1CFG2_XPOS_Pos)))
#define LCDC_OVR1CFG2_YPOS_Pos 16
#define LCDC_OVR1CFG2_YPOS_Msk (0x7ffu << LCDC_OVR1CFG2_YPOS_Pos) /**< \brief (LCDC_OVR1CFG2) Vertical Window Position */
#define LCDC_OVR1CFG2_YPOS(value) ((LCDC_OVR1CFG2_YPOS_Msk & ((value) << LCDC_OVR1CFG2_YPOS_Pos)))
/* -------- LCDC_OVR1CFG3 : (LCDC Offset: 0x198) Overlay 1 Configuration Register 3 -------- */
#define LCDC_OVR1CFG3_XSIZE_Pos 0
#define LCDC_OVR1CFG3_XSIZE_Msk (0x7ffu << LCDC_OVR1CFG3_XSIZE_Pos) /**< \brief (LCDC_OVR1CFG3) Horizontal Window Size */
#define LCDC_OVR1CFG3_XSIZE(value) ((LCDC_OVR1CFG3_XSIZE_Msk & ((value) << LCDC_OVR1CFG3_XSIZE_Pos)))
#define LCDC_OVR1CFG3_YSIZE_Pos 16
#define LCDC_OVR1CFG3_YSIZE_Msk (0x7ffu << LCDC_OVR1CFG3_YSIZE_Pos) /**< \brief (LCDC_OVR1CFG3) Vertical Window Size */
#define LCDC_OVR1CFG3_YSIZE(value) ((LCDC_OVR1CFG3_YSIZE_Msk & ((value) << LCDC_OVR1CFG3_YSIZE_Pos)))
/* -------- LCDC_OVR1CFG4 : (LCDC Offset: 0x19C) Overlay 1 Configuration Register 4 -------- */
#define LCDC_OVR1CFG4_XSTRIDE_Pos 0
#define LCDC_OVR1CFG4_XSTRIDE_Msk (0xffffffffu << LCDC_OVR1CFG4_XSTRIDE_Pos) /**< \brief (LCDC_OVR1CFG4) Horizontal Stride */
#define LCDC_OVR1CFG4_XSTRIDE(value) ((LCDC_OVR1CFG4_XSTRIDE_Msk & ((value) << LCDC_OVR1CFG4_XSTRIDE_Pos)))
/* -------- LCDC_OVR1CFG5 : (LCDC Offset: 0x1A0) Overlay 1 Configuration Register 5 -------- */
#define LCDC_OVR1CFG5_PSTRIDE_Pos 0
#define LCDC_OVR1CFG5_PSTRIDE_Msk (0xffffffffu << LCDC_OVR1CFG5_PSTRIDE_Pos) /**< \brief (LCDC_OVR1CFG5) Pixel Stride */
#define LCDC_OVR1CFG5_PSTRIDE(value) ((LCDC_OVR1CFG5_PSTRIDE_Msk & ((value) << LCDC_OVR1CFG5_PSTRIDE_Pos)))
/* -------- LCDC_OVR1CFG6 : (LCDC Offset: 0x1A4) Overlay 1 Configuration Register 6 -------- */
#define LCDC_OVR1CFG6_BDEF_Pos 0
#define LCDC_OVR1CFG6_BDEF_Msk (0xffu << LCDC_OVR1CFG6_BDEF_Pos) /**< \brief (LCDC_OVR1CFG6) Blue Default */
#define LCDC_OVR1CFG6_BDEF(value) ((LCDC_OVR1CFG6_BDEF_Msk & ((value) << LCDC_OVR1CFG6_BDEF_Pos)))
#define LCDC_OVR1CFG6_GDEF_Pos 8
#define LCDC_OVR1CFG6_GDEF_Msk (0xffu << LCDC_OVR1CFG6_GDEF_Pos) /**< \brief (LCDC_OVR1CFG6) Green Default */
#define LCDC_OVR1CFG6_GDEF(value) ((LCDC_OVR1CFG6_GDEF_Msk & ((value) << LCDC_OVR1CFG6_GDEF_Pos)))
#define LCDC_OVR1CFG6_RDEF_Pos 16
#define LCDC_OVR1CFG6_RDEF_Msk (0xffu << LCDC_OVR1CFG6_RDEF_Pos) /**< \brief (LCDC_OVR1CFG6) Red Default */
#define LCDC_OVR1CFG6_RDEF(value) ((LCDC_OVR1CFG6_RDEF_Msk & ((value) << LCDC_OVR1CFG6_RDEF_Pos)))
/* -------- LCDC_OVR1CFG7 : (LCDC Offset: 0x1A8) Overlay 1 Configuration Register 7 -------- */
#define LCDC_OVR1CFG7_BKEY_Pos 0
#define LCDC_OVR1CFG7_BKEY_Msk (0xffu << LCDC_OVR1CFG7_BKEY_Pos) /**< \brief (LCDC_OVR1CFG7) Blue Color Component Chroma Key */
#define LCDC_OVR1CFG7_BKEY(value) ((LCDC_OVR1CFG7_BKEY_Msk & ((value) << LCDC_OVR1CFG7_BKEY_Pos)))
#define LCDC_OVR1CFG7_GKEY_Pos 8
#define LCDC_OVR1CFG7_GKEY_Msk (0xffu << LCDC_OVR1CFG7_GKEY_Pos) /**< \brief (LCDC_OVR1CFG7) Green Color Component Chroma Key */
#define LCDC_OVR1CFG7_GKEY(value) ((LCDC_OVR1CFG7_GKEY_Msk & ((value) << LCDC_OVR1CFG7_GKEY_Pos)))
#define LCDC_OVR1CFG7_RKEY_Pos 16
#define LCDC_OVR1CFG7_RKEY_Msk (0xffu << LCDC_OVR1CFG7_RKEY_Pos) /**< \brief (LCDC_OVR1CFG7) Red Color Component Chroma Key */
#define LCDC_OVR1CFG7_RKEY(value) ((LCDC_OVR1CFG7_RKEY_Msk & ((value) << LCDC_OVR1CFG7_RKEY_Pos)))
/* -------- LCDC_OVR1CFG8 : (LCDC Offset: 0x1AC) Overlay 1 Configuration Register 8 -------- */
#define LCDC_OVR1CFG8_BMASK_Pos 0
#define LCDC_OVR1CFG8_BMASK_Msk (0xffu << LCDC_OVR1CFG8_BMASK_Pos) /**< \brief (LCDC_OVR1CFG8) Blue Color Component Chroma Key Mask */
#define LCDC_OVR1CFG8_BMASK(value) ((LCDC_OVR1CFG8_BMASK_Msk & ((value) << LCDC_OVR1CFG8_BMASK_Pos)))
#define LCDC_OVR1CFG8_GMASK_Pos 8
#define LCDC_OVR1CFG8_GMASK_Msk (0xffu << LCDC_OVR1CFG8_GMASK_Pos) /**< \brief (LCDC_OVR1CFG8) Green Color Component Chroma Key Mask */
#define LCDC_OVR1CFG8_GMASK(value) ((LCDC_OVR1CFG8_GMASK_Msk & ((value) << LCDC_OVR1CFG8_GMASK_Pos)))
#define LCDC_OVR1CFG8_RMASK_Pos 16
#define LCDC_OVR1CFG8_RMASK_Msk (0xffu << LCDC_OVR1CFG8_RMASK_Pos) /**< \brief (LCDC_OVR1CFG8) Red Color Component Chroma Key Mask */
#define LCDC_OVR1CFG8_RMASK(value) ((LCDC_OVR1CFG8_RMASK_Msk & ((value) << LCDC_OVR1CFG8_RMASK_Pos)))
/* -------- LCDC_OVR1CFG9 : (LCDC Offset: 0x1B0) Overlay 1 Configuration Register 9 -------- */
#define LCDC_OVR1CFG9_CRKEY (0x1u << 0) /**< \brief (LCDC_OVR1CFG9) Blender Chroma Key Enable */
#define LCDC_OVR1CFG9_INV (0x1u << 1) /**< \brief (LCDC_OVR1CFG9) Blender Inverted Blender Output Enable */
#define LCDC_OVR1CFG9_ITER2BL (0x1u << 2) /**< \brief (LCDC_OVR1CFG9) Blender Iterated Color Enable */
#define LCDC_OVR1CFG9_ITER (0x1u << 3) /**< \brief (LCDC_OVR1CFG9) Blender Use Iterated Color */
#define LCDC_OVR1CFG9_REVALPHA (0x1u << 4) /**< \brief (LCDC_OVR1CFG9) Blender Reverse Alpha */
#define LCDC_OVR1CFG9_GAEN (0x1u << 5) /**< \brief (LCDC_OVR1CFG9) Blender Global Alpha Enable */
#define LCDC_OVR1CFG9_LAEN (0x1u << 6) /**< \brief (LCDC_OVR1CFG9) Blender Local Alpha Enable */
#define LCDC_OVR1CFG9_OVR (0x1u << 7) /**< \brief (LCDC_OVR1CFG9) Blender Overlay Layer Enable */
#define LCDC_OVR1CFG9_DMA (0x1u << 8) /**< \brief (LCDC_OVR1CFG9) Blender DMA Layer Enable */
#define LCDC_OVR1CFG9_REP (0x1u << 9) /**< \brief (LCDC_OVR1CFG9) Use Replication logic to expand RGB color to 24 bits */
#define LCDC_OVR1CFG9_DSTKEY (0x1u << 10) /**< \brief (LCDC_OVR1CFG9) Destination Chroma Keying */
#define LCDC_OVR1CFG9_GA_Pos 16
#define LCDC_OVR1CFG9_GA_Msk (0xffu << LCDC_OVR1CFG9_GA_Pos) /**< \brief (LCDC_OVR1CFG9) Blender Global Alpha */
#define LCDC_OVR1CFG9_GA(value) ((LCDC_OVR1CFG9_GA_Msk & ((value) << LCDC_OVR1CFG9_GA_Pos)))
/* -------- LCDC_OVR2CHER : (LCDC Offset: 0x260) Overlay 2 Channel Enable Register -------- */
#define LCDC_OVR2CHER_CHEN (0x1u << 0) /**< \brief (LCDC_OVR2CHER) Channel Enable */
#define LCDC_OVR2CHER_UPDATEEN (0x1u << 1) /**< \brief (LCDC_OVR2CHER) Update Overlay Attributes Enable */
#define LCDC_OVR2CHER_A2QEN (0x1u << 2) /**< \brief (LCDC_OVR2CHER) Add To Queue Enable */
/* -------- LCDC_OVR2CHDR : (LCDC Offset: 0x264) Overlay 2 Channel Disable Register -------- */
#define LCDC_OVR2CHDR_CHDIS (0x1u << 0) /**< \brief (LCDC_OVR2CHDR) Channel Disable */
#define LCDC_OVR2CHDR_CHRST (0x1u << 8) /**< \brief (LCDC_OVR2CHDR) Channel Reset */
/* -------- LCDC_OVR2CHSR : (LCDC Offset: 0x268) Overlay 2 Channel Status Register -------- */
#define LCDC_OVR2CHSR_CHSR (0x1u << 0) /**< \brief (LCDC_OVR2CHSR) Channel Status */
#define LCDC_OVR2CHSR_UPDATESR (0x1u << 1) /**< \brief (LCDC_OVR2CHSR) Update Overlay Attributes In Progress Status */
#define LCDC_OVR2CHSR_A2QSR (0x1u << 2) /**< \brief (LCDC_OVR2CHSR) Add To Queue Status */
/* -------- LCDC_OVR2IER : (LCDC Offset: 0x26C) Overlay 2 Interrupt Enable Register -------- */
#define LCDC_OVR2IER_DMA (0x1u << 2) /**< \brief (LCDC_OVR2IER) End of DMA Transfer Interrupt Enable */
#define LCDC_OVR2IER_DSCR (0x1u << 3) /**< \brief (LCDC_OVR2IER) Descriptor Loaded Interrupt Enable */
#define LCDC_OVR2IER_ADD (0x1u << 4) /**< \brief (LCDC_OVR2IER) Head Descriptor Loaded Interrupt Enable */
#define LCDC_OVR2IER_DONE (0x1u << 5) /**< \brief (LCDC_OVR2IER) End of List Interrupt Enable */
#define LCDC_OVR2IER_OVR (0x1u << 6) /**< \brief (LCDC_OVR2IER) Overflow Interrupt Enable */
/* -------- LCDC_OVR2IDR : (LCDC Offset: 0x270) Overlay 2 Interrupt Disable Register -------- */
#define LCDC_OVR2IDR_DMA (0x1u << 2) /**< \brief (LCDC_OVR2IDR) End of DMA Transfer Interrupt Disable */
#define LCDC_OVR2IDR_DSCR (0x1u << 3) /**< \brief (LCDC_OVR2IDR) Descriptor Loaded Interrupt Disable */
#define LCDC_OVR2IDR_ADD (0x1u << 4) /**< \brief (LCDC_OVR2IDR) Head Descriptor Loaded Interrupt Disable */
#define LCDC_OVR2IDR_DONE (0x1u << 5) /**< \brief (LCDC_OVR2IDR) End of List Interrupt Disable */
#define LCDC_OVR2IDR_OVR (0x1u << 6) /**< \brief (LCDC_OVR2IDR) Overflow Interrupt Disable */
/* -------- LCDC_OVR2IMR : (LCDC Offset: 0x274) Overlay 2 Interrupt Mask Register -------- */
#define LCDC_OVR2IMR_DMA (0x1u << 2) /**< \brief (LCDC_OVR2IMR) End of DMA Transfer Interrupt Mask */
#define LCDC_OVR2IMR_DSCR (0x1u << 3) /**< \brief (LCDC_OVR2IMR) Descriptor Loaded Interrupt Mask */
#define LCDC_OVR2IMR_ADD (0x1u << 4) /**< \brief (LCDC_OVR2IMR) Head Descriptor Loaded Interrupt Mask */
#define LCDC_OVR2IMR_DONE (0x1u << 5) /**< \brief (LCDC_OVR2IMR) End of List Interrupt Mask */
#define LCDC_OVR2IMR_OVR (0x1u << 6) /**< \brief (LCDC_OVR2IMR) Overflow Interrupt Mask */
/* -------- LCDC_OVR2ISR : (LCDC Offset: 0x278) Overlay 2 Interrupt Status Register -------- */
#define LCDC_OVR2ISR_DMA (0x1u << 2) /**< \brief (LCDC_OVR2ISR) End of DMA Transfer */
#define LCDC_OVR2ISR_DSCR (0x1u << 3) /**< \brief (LCDC_OVR2ISR) DMA Descriptor Loaded */
#define LCDC_OVR2ISR_ADD (0x1u << 4) /**< \brief (LCDC_OVR2ISR) Head Descriptor Loaded */
#define LCDC_OVR2ISR_DONE (0x1u << 5) /**< \brief (LCDC_OVR2ISR) End of List Detected */
#define LCDC_OVR2ISR_OVR (0x1u << 6) /**< \brief (LCDC_OVR2ISR) Overflow Detected */
/* -------- LCDC_OVR2HEAD : (LCDC Offset: 0x27C) Overlay 2 DMA Head Register -------- */
#define LCDC_OVR2HEAD_HEAD_Pos 2
#define LCDC_OVR2HEAD_HEAD_Msk (0x3fffffffu << LCDC_OVR2HEAD_HEAD_Pos) /**< \brief (LCDC_OVR2HEAD) DMA Head Pointer */
#define LCDC_OVR2HEAD_HEAD(value) ((LCDC_OVR2HEAD_HEAD_Msk & ((value) << LCDC_OVR2HEAD_HEAD_Pos)))
/* -------- LCDC_OVR2ADDR : (LCDC Offset: 0x280) Overlay 2 DMA Address Register -------- */
#define LCDC_OVR2ADDR_ADDR_Pos 0
#define LCDC_OVR2ADDR_ADDR_Msk (0xffffffffu << LCDC_OVR2ADDR_ADDR_Pos) /**< \brief (LCDC_OVR2ADDR) DMA Transfer Overlay 2 Address */
#define LCDC_OVR2ADDR_ADDR(value) ((LCDC_OVR2ADDR_ADDR_Msk & ((value) << LCDC_OVR2ADDR_ADDR_Pos)))
/* -------- LCDC_OVR2CTRL : (LCDC Offset: 0x284) Overlay 2 DMA Control Register -------- */
#define LCDC_OVR2CTRL_DFETCH (0x1u << 0) /**< \brief (LCDC_OVR2CTRL) Transfer Descriptor Fetch Enable */
#define LCDC_OVR2CTRL_LFETCH (0x1u << 1) /**< \brief (LCDC_OVR2CTRL) Lookup Table Fetch Enable */
#define LCDC_OVR2CTRL_DMAIEN (0x1u << 2) /**< \brief (LCDC_OVR2CTRL) End of DMA Transfer Interrupt Enable */
#define LCDC_OVR2CTRL_DSCRIEN (0x1u << 3) /**< \brief (LCDC_OVR2CTRL) Descriptor Loaded Interrupt Enable */
#define LCDC_OVR2CTRL_ADDIEN (0x1u << 4) /**< \brief (LCDC_OVR2CTRL) Add Head Descriptor to Queue Interrupt Enable */
#define LCDC_OVR2CTRL_DONEIEN (0x1u << 5) /**< \brief (LCDC_OVR2CTRL) End of List Interrupt Enable */
/* -------- LCDC_OVR2NEXT : (LCDC Offset: 0x288) Overlay 2 DMA Next Register -------- */
#define LCDC_OVR2NEXT_NEXT_Pos 0
#define LCDC_OVR2NEXT_NEXT_Msk (0xffffffffu << LCDC_OVR2NEXT_NEXT_Pos) /**< \brief (LCDC_OVR2NEXT) DMA Descriptor Next Address */
#define LCDC_OVR2NEXT_NEXT(value) ((LCDC_OVR2NEXT_NEXT_Msk & ((value) << LCDC_OVR2NEXT_NEXT_Pos)))
/* -------- LCDC_OVR2CFG0 : (LCDC Offset: 0x28C) Overlay 2 Configuration Register 0 -------- */
#define LCDC_OVR2CFG0_BLEN_Pos 4
#define LCDC_OVR2CFG0_BLEN_Msk (0x3u << LCDC_OVR2CFG0_BLEN_Pos) /**< \brief (LCDC_OVR2CFG0) System Bus Burst Length */
#define LCDC_OVR2CFG0_BLEN(value) ((LCDC_OVR2CFG0_BLEN_Msk & ((value) << LCDC_OVR2CFG0_BLEN_Pos)))
#define   LCDC_OVR2CFG0_BLEN_AHB_SINGLE (0x0u << 4) /**< \brief (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_OVR2CFG0_BLEN_AHB_INCR4 (0x1u << 4) /**< \brief (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used. SINGLE, INCR and INCR4 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_OVR2CFG0_BLEN_AHB_INCR8 (0x2u << 4) /**< \brief (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used. SINGLE, INCR, INCR4 and INCR8 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_OVR2CFG0_BLEN_AHB_INCR16 (0x3u << 4) /**< \brief (LCDC_OVR2CFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define LCDC_OVR2CFG0_DLBO (0x1u << 8) /**< \brief (LCDC_OVR2CFG0) Defined Length Burst Only For Channel Bus Transaction */
#define LCDC_OVR2CFG0_ROTDIS (0x1u << 12) /**< \brief (LCDC_OVR2CFG0) Hardware Rotation Optimization Disable */
#define LCDC_OVR2CFG0_LOCKDIS (0x1u << 13) /**< \brief (LCDC_OVR2CFG0) Hardware Rotation Lock Disable */
/* -------- LCDC_OVR2CFG1 : (LCDC Offset: 0x290) Overlay 2 Configuration Register 1 -------- */
#define LCDC_OVR2CFG1_CLUTEN (0x1u << 0) /**< \brief (LCDC_OVR2CFG1) Color Lookup Table Mode Enable */
#define LCDC_OVR2CFG1_RGBMODE_Pos 4
#define LCDC_OVR2CFG1_RGBMODE_Msk (0xfu << LCDC_OVR2CFG1_RGBMODE_Pos) /**< \brief (LCDC_OVR2CFG1) RGB Mode Input Selection */
#define LCDC_OVR2CFG1_RGBMODE(value) ((LCDC_OVR2CFG1_RGBMODE_Msk & ((value) << LCDC_OVR2CFG1_RGBMODE_Pos)))
#define   LCDC_OVR2CFG1_RGBMODE_12BPP_RGB_444 (0x0u << 4) /**< \brief (LCDC_OVR2CFG1) 12 bpp RGB 444 */
#define   LCDC_OVR2CFG1_RGBMODE_16BPP_ARGB_4444 (0x1u << 4) /**< \brief (LCDC_OVR2CFG1) 16 bpp ARGB 4444 */
#define   LCDC_OVR2CFG1_RGBMODE_16BPP_RGBA_4444 (0x2u << 4) /**< \brief (LCDC_OVR2CFG1) 16 bpp RGBA 4444 */
#define   LCDC_OVR2CFG1_RGBMODE_16BPP_RGB_565 (0x3u << 4) /**< \brief (LCDC_OVR2CFG1) 16 bpp RGB 565 */
#define   LCDC_OVR2CFG1_RGBMODE_16BPP_TRGB_1555 (0x4u << 4) /**< \brief (LCDC_OVR2CFG1) 16 bpp TRGB 1555 */
#define   LCDC_OVR2CFG1_RGBMODE_18BPP_RGB_666 (0x5u << 4) /**< \brief (LCDC_OVR2CFG1) 18 bpp RGB 666 */
#define   LCDC_OVR2CFG1_RGBMODE_18BPP_RGB_666PACKED (0x6u << 4) /**< \brief (LCDC_OVR2CFG1) 18 bpp RGB 666 PACKED */
#define   LCDC_OVR2CFG1_RGBMODE_19BPP_TRGB_1666 (0x7u << 4) /**< \brief (LCDC_OVR2CFG1) 19 bpp TRGB 1666 */
#define   LCDC_OVR2CFG1_RGBMODE_19BPP_TRGB_PACKED (0x8u << 4) /**< \brief (LCDC_OVR2CFG1) 19 bpp TRGB 1666 PACKED */
#define   LCDC_OVR2CFG1_RGBMODE_24BPP_RGB_888 (0x9u << 4) /**< \brief (LCDC_OVR2CFG1) 24 bpp RGB 888 */
#define   LCDC_OVR2CFG1_RGBMODE_24BPP_RGB_888_PACKED (0xAu << 4) /**< \brief (LCDC_OVR2CFG1) 24 bpp RGB 888 PACKED */
#define   LCDC_OVR2CFG1_RGBMODE_25BPP_TRGB_1888 (0xBu << 4) /**< \brief (LCDC_OVR2CFG1) 25 bpp TRGB 1888 */
#define   LCDC_OVR2CFG1_RGBMODE_32BPP_ARGB_8888 (0xCu << 4) /**< \brief (LCDC_OVR2CFG1) 32 bpp ARGB 8888 */
#define   LCDC_OVR2CFG1_RGBMODE_32BPP_RGBA_8888 (0xDu << 4) /**< \brief (LCDC_OVR2CFG1) 32 bpp RGBA 8888 */
#define LCDC_OVR2CFG1_CLUTMODE_Pos 8
#define LCDC_OVR2CFG1_CLUTMODE_Msk (0x3u << LCDC_OVR2CFG1_CLUTMODE_Pos) /**< \brief (LCDC_OVR2CFG1) Color Lookup Table Mode Input Selection */
#define LCDC_OVR2CFG1_CLUTMODE(value) ((LCDC_OVR2CFG1_CLUTMODE_Msk & ((value) << LCDC_OVR2CFG1_CLUTMODE_Pos)))
#define   LCDC_OVR2CFG1_CLUTMODE_1BPP (0x0u << 8) /**< \brief (LCDC_OVR2CFG1) Color Lookup Table mode set to 1 bit per pixel */
#define   LCDC_OVR2CFG1_CLUTMODE_2BPP (0x1u << 8) /**< \brief (LCDC_OVR2CFG1) Color Lookup Table mode set to 2 bits per pixel */
#define   LCDC_OVR2CFG1_CLUTMODE_4BPP (0x2u << 8) /**< \brief (LCDC_OVR2CFG1) Color Lookup Table mode set to 4 bits per pixel */
#define   LCDC_OVR2CFG1_CLUTMODE_8BPP (0x3u << 8) /**< \brief (LCDC_OVR2CFG1) Color Lookup Table mode set to 8 bits per pixel */
/* -------- LCDC_OVR2CFG2 : (LCDC Offset: 0x294) Overlay 2 Configuration Register 2 -------- */
#define LCDC_OVR2CFG2_XPOS_Pos 0
#define LCDC_OVR2CFG2_XPOS_Msk (0x7ffu << LCDC_OVR2CFG2_XPOS_Pos) /**< \brief (LCDC_OVR2CFG2) Horizontal Window Position */
#define LCDC_OVR2CFG2_XPOS(value) ((LCDC_OVR2CFG2_XPOS_Msk & ((value) << LCDC_OVR2CFG2_XPOS_Pos)))
#define LCDC_OVR2CFG2_YPOS_Pos 16
#define LCDC_OVR2CFG2_YPOS_Msk (0x7ffu << LCDC_OVR2CFG2_YPOS_Pos) /**< \brief (LCDC_OVR2CFG2) Vertical Window Position */
#define LCDC_OVR2CFG2_YPOS(value) ((LCDC_OVR2CFG2_YPOS_Msk & ((value) << LCDC_OVR2CFG2_YPOS_Pos)))
/* -------- LCDC_OVR2CFG3 : (LCDC Offset: 0x298) Overlay 2 Configuration Register 3 -------- */
#define LCDC_OVR2CFG3_XSIZE_Pos 0
#define LCDC_OVR2CFG3_XSIZE_Msk (0x7ffu << LCDC_OVR2CFG3_XSIZE_Pos) /**< \brief (LCDC_OVR2CFG3) Horizontal Window Size */
#define LCDC_OVR2CFG3_XSIZE(value) ((LCDC_OVR2CFG3_XSIZE_Msk & ((value) << LCDC_OVR2CFG3_XSIZE_Pos)))
#define LCDC_OVR2CFG3_YSIZE_Pos 16
#define LCDC_OVR2CFG3_YSIZE_Msk (0x7ffu << LCDC_OVR2CFG3_YSIZE_Pos) /**< \brief (LCDC_OVR2CFG3) Vertical Window Size */
#define LCDC_OVR2CFG3_YSIZE(value) ((LCDC_OVR2CFG3_YSIZE_Msk & ((value) << LCDC_OVR2CFG3_YSIZE_Pos)))
/* -------- LCDC_OVR2CFG4 : (LCDC Offset: 0x29C) Overlay 2 Configuration Register 4 -------- */
#define LCDC_OVR2CFG4_XSTRIDE_Pos 0
#define LCDC_OVR2CFG4_XSTRIDE_Msk (0xffffffffu << LCDC_OVR2CFG4_XSTRIDE_Pos) /**< \brief (LCDC_OVR2CFG4) Horizontal Stride */
#define LCDC_OVR2CFG4_XSTRIDE(value) ((LCDC_OVR2CFG4_XSTRIDE_Msk & ((value) << LCDC_OVR2CFG4_XSTRIDE_Pos)))
/* -------- LCDC_OVR2CFG5 : (LCDC Offset: 0x2A0) Overlay 2 Configuration Register 5 -------- */
#define LCDC_OVR2CFG5_PSTRIDE_Pos 0
#define LCDC_OVR2CFG5_PSTRIDE_Msk (0xffffffffu << LCDC_OVR2CFG5_PSTRIDE_Pos) /**< \brief (LCDC_OVR2CFG5) Pixel Stride */
#define LCDC_OVR2CFG5_PSTRIDE(value) ((LCDC_OVR2CFG5_PSTRIDE_Msk & ((value) << LCDC_OVR2CFG5_PSTRIDE_Pos)))
/* -------- LCDC_OVR2CFG6 : (LCDC Offset: 0x2A4) Overlay 2 Configuration Register 6 -------- */
#define LCDC_OVR2CFG6_BDEF_Pos 0
#define LCDC_OVR2CFG6_BDEF_Msk (0xffu << LCDC_OVR2CFG6_BDEF_Pos) /**< \brief (LCDC_OVR2CFG6) Blue Default */
#define LCDC_OVR2CFG6_BDEF(value) ((LCDC_OVR2CFG6_BDEF_Msk & ((value) << LCDC_OVR2CFG6_BDEF_Pos)))
#define LCDC_OVR2CFG6_GDEF_Pos 8
#define LCDC_OVR2CFG6_GDEF_Msk (0xffu << LCDC_OVR2CFG6_GDEF_Pos) /**< \brief (LCDC_OVR2CFG6) Green Default */
#define LCDC_OVR2CFG6_GDEF(value) ((LCDC_OVR2CFG6_GDEF_Msk & ((value) << LCDC_OVR2CFG6_GDEF_Pos)))
#define LCDC_OVR2CFG6_RDEF_Pos 16
#define LCDC_OVR2CFG6_RDEF_Msk (0xffu << LCDC_OVR2CFG6_RDEF_Pos) /**< \brief (LCDC_OVR2CFG6) Red Default */
#define LCDC_OVR2CFG6_RDEF(value) ((LCDC_OVR2CFG6_RDEF_Msk & ((value) << LCDC_OVR2CFG6_RDEF_Pos)))
/* -------- LCDC_OVR2CFG7 : (LCDC Offset: 0x2A8) Overlay 2 Configuration Register 7 -------- */
#define LCDC_OVR2CFG7_BKEY_Pos 0
#define LCDC_OVR2CFG7_BKEY_Msk (0xffu << LCDC_OVR2CFG7_BKEY_Pos) /**< \brief (LCDC_OVR2CFG7) Blue Color Component Chroma Key */
#define LCDC_OVR2CFG7_BKEY(value) ((LCDC_OVR2CFG7_BKEY_Msk & ((value) << LCDC_OVR2CFG7_BKEY_Pos)))
#define LCDC_OVR2CFG7_GKEY_Pos 8
#define LCDC_OVR2CFG7_GKEY_Msk (0xffu << LCDC_OVR2CFG7_GKEY_Pos) /**< \brief (LCDC_OVR2CFG7) Green Color Component Chroma Key */
#define LCDC_OVR2CFG7_GKEY(value) ((LCDC_OVR2CFG7_GKEY_Msk & ((value) << LCDC_OVR2CFG7_GKEY_Pos)))
#define LCDC_OVR2CFG7_RKEY_Pos 16
#define LCDC_OVR2CFG7_RKEY_Msk (0xffu << LCDC_OVR2CFG7_RKEY_Pos) /**< \brief (LCDC_OVR2CFG7) Red Color Component Chroma Key */
#define LCDC_OVR2CFG7_RKEY(value) ((LCDC_OVR2CFG7_RKEY_Msk & ((value) << LCDC_OVR2CFG7_RKEY_Pos)))
/* -------- LCDC_OVR2CFG8 : (LCDC Offset: 0x2AC) Overlay 2 Configuration Register 8 -------- */
#define LCDC_OVR2CFG8_BMASK_Pos 0
#define LCDC_OVR2CFG8_BMASK_Msk (0xffu << LCDC_OVR2CFG8_BMASK_Pos) /**< \brief (LCDC_OVR2CFG8) Blue Color Component Chroma Key Mask */
#define LCDC_OVR2CFG8_BMASK(value) ((LCDC_OVR2CFG8_BMASK_Msk & ((value) << LCDC_OVR2CFG8_BMASK_Pos)))
#define LCDC_OVR2CFG8_GMASK_Pos 8
#define LCDC_OVR2CFG8_GMASK_Msk (0xffu << LCDC_OVR2CFG8_GMASK_Pos) /**< \brief (LCDC_OVR2CFG8) Green Color Component Chroma Key Mask */
#define LCDC_OVR2CFG8_GMASK(value) ((LCDC_OVR2CFG8_GMASK_Msk & ((value) << LCDC_OVR2CFG8_GMASK_Pos)))
#define LCDC_OVR2CFG8_RMASK_Pos 16
#define LCDC_OVR2CFG8_RMASK_Msk (0xffu << LCDC_OVR2CFG8_RMASK_Pos) /**< \brief (LCDC_OVR2CFG8) Red Color Component Chroma Key Mask */
#define LCDC_OVR2CFG8_RMASK(value) ((LCDC_OVR2CFG8_RMASK_Msk & ((value) << LCDC_OVR2CFG8_RMASK_Pos)))
/* -------- LCDC_OVR2CFG9 : (LCDC Offset: 0x2B0) Overlay 2 Configuration Register 9 -------- */
#define LCDC_OVR2CFG9_CRKEY (0x1u << 0) /**< \brief (LCDC_OVR2CFG9) Blender Chroma Key Enable */
#define LCDC_OVR2CFG9_INV (0x1u << 1) /**< \brief (LCDC_OVR2CFG9) Blender Inverted Blender Output Enable */
#define LCDC_OVR2CFG9_ITER2BL (0x1u << 2) /**< \brief (LCDC_OVR2CFG9) Blender Iterated Color Enable */
#define LCDC_OVR2CFG9_ITER (0x1u << 3) /**< \brief (LCDC_OVR2CFG9) Blender Use Iterated Color */
#define LCDC_OVR2CFG9_REVALPHA (0x1u << 4) /**< \brief (LCDC_OVR2CFG9) Blender Reverse Alpha */
#define LCDC_OVR2CFG9_GAEN (0x1u << 5) /**< \brief (LCDC_OVR2CFG9) Blender Global Alpha Enable */
#define LCDC_OVR2CFG9_LAEN (0x1u << 6) /**< \brief (LCDC_OVR2CFG9) Blender Local Alpha Enable */
#define LCDC_OVR2CFG9_OVR (0x1u << 7) /**< \brief (LCDC_OVR2CFG9) Blender Overlay Layer Enable */
#define LCDC_OVR2CFG9_DMA (0x1u << 8) /**< \brief (LCDC_OVR2CFG9) Blender DMA Layer Enable */
#define LCDC_OVR2CFG9_REP (0x1u << 9) /**< \brief (LCDC_OVR2CFG9) Use Replication logic to expand RGB color to 24 bits */
#define LCDC_OVR2CFG9_DSTKEY (0x1u << 10) /**< \brief (LCDC_OVR2CFG9) Destination Chroma Keying */
#define LCDC_OVR2CFG9_GA_Pos 16
#define LCDC_OVR2CFG9_GA_Msk (0xffu << LCDC_OVR2CFG9_GA_Pos) /**< \brief (LCDC_OVR2CFG9) Blender Global Alpha */
#define LCDC_OVR2CFG9_GA(value) ((LCDC_OVR2CFG9_GA_Msk & ((value) << LCDC_OVR2CFG9_GA_Pos)))
/* -------- LCDC_HEOCHER : (LCDC Offset: 0x360) High-End Overlay Channel Enable Register -------- */
#define LCDC_HEOCHER_CHEN (0x1u << 0) /**< \brief (LCDC_HEOCHER) Channel Enable */
#define LCDC_HEOCHER_UPDATEEN (0x1u << 1) /**< \brief (LCDC_HEOCHER) Update Overlay Attributes Enable */
#define LCDC_HEOCHER_A2QEN (0x1u << 2) /**< \brief (LCDC_HEOCHER) Add To Queue Enable */
/* -------- LCDC_HEOCHDR : (LCDC Offset: 0x364) High-End Overlay Channel Disable Register -------- */
#define LCDC_HEOCHDR_CHDIS (0x1u << 0) /**< \brief (LCDC_HEOCHDR) Channel Disable */
#define LCDC_HEOCHDR_CHRST (0x1u << 8) /**< \brief (LCDC_HEOCHDR) Channel Reset */
/* -------- LCDC_HEOCHSR : (LCDC Offset: 0x368) High-End Overlay Channel Status Register -------- */
#define LCDC_HEOCHSR_CHSR (0x1u << 0) /**< \brief (LCDC_HEOCHSR) Channel Status */
#define LCDC_HEOCHSR_UPDATESR (0x1u << 1) /**< \brief (LCDC_HEOCHSR) Update Overlay Attributes In Progress Status */
#define LCDC_HEOCHSR_A2QSR (0x1u << 2) /**< \brief (LCDC_HEOCHSR) Add To Queue Status */
/* -------- LCDC_HEOIER : (LCDC Offset: 0x36C) High-End Overlay Interrupt Enable Register -------- */
#define LCDC_HEOIER_DMA (0x1u << 2) /**< \brief (LCDC_HEOIER) End of DMA Transfer Interrupt Enable */
#define LCDC_HEOIER_DSCR (0x1u << 3) /**< \brief (LCDC_HEOIER) Descriptor Loaded Interrupt Enable */
#define LCDC_HEOIER_ADD (0x1u << 4) /**< \brief (LCDC_HEOIER) Head Descriptor Loaded Interrupt Enable */
#define LCDC_HEOIER_DONE (0x1u << 5) /**< \brief (LCDC_HEOIER) End of List Interrupt Enable */
#define LCDC_HEOIER_OVR (0x1u << 6) /**< \brief (LCDC_HEOIER) Overflow Interrupt Enable */
#define LCDC_HEOIER_UDMA (0x1u << 10) /**< \brief (LCDC_HEOIER) End of DMA Transfer for U or UV Chrominance Interrupt Enable */
#define LCDC_HEOIER_UDSCR (0x1u << 11) /**< \brief (LCDC_HEOIER) Descriptor Loaded for U or UV Chrominance Interrupt Enable */
#define LCDC_HEOIER_UADD (0x1u << 12) /**< \brief (LCDC_HEOIER) Head Descriptor Loaded for U or UV Chrominance Interrupt Enable */
#define LCDC_HEOIER_UDONE (0x1u << 13) /**< \brief (LCDC_HEOIER) End of List for U or UV Chrominance Interrupt Enable */
#define LCDC_HEOIER_UOVR (0x1u << 14) /**< \brief (LCDC_HEOIER) Overflow for U or UV Chrominance Interrupt Enable */
#define LCDC_HEOIER_VDMA (0x1u << 18) /**< \brief (LCDC_HEOIER) End of DMA for V Chrominance Transfer Interrupt Enable */
#define LCDC_HEOIER_VDSCR (0x1u << 19) /**< \brief (LCDC_HEOIER) Descriptor Loaded for V Chrominance Interrupt Enable */
#define LCDC_HEOIER_VADD (0x1u << 20) /**< \brief (LCDC_HEOIER) Head Descriptor Loaded for V Chrominance Interrupt Enable */
#define LCDC_HEOIER_VDONE (0x1u << 21) /**< \brief (LCDC_HEOIER) End of List for V Chrominance Interrupt Enable */
#define LCDC_HEOIER_VOVR (0x1u << 22) /**< \brief (LCDC_HEOIER) Overflow for V Chrominance Interrupt Enable */
/* -------- LCDC_HEOIDR : (LCDC Offset: 0x370) High-End Overlay Interrupt Disable Register -------- */
#define LCDC_HEOIDR_DMA (0x1u << 2) /**< \brief (LCDC_HEOIDR) End of DMA Transfer Interrupt Disable */
#define LCDC_HEOIDR_DSCR (0x1u << 3) /**< \brief (LCDC_HEOIDR) Descriptor Loaded Interrupt Disable */
#define LCDC_HEOIDR_ADD (0x1u << 4) /**< \brief (LCDC_HEOIDR) Head Descriptor Loaded Interrupt Disable */
#define LCDC_HEOIDR_DONE (0x1u << 5) /**< \brief (LCDC_HEOIDR) End of List Interrupt Disable */
#define LCDC_HEOIDR_OVR (0x1u << 6) /**< \brief (LCDC_HEOIDR) Overflow Interrupt Disable */
#define LCDC_HEOIDR_UDMA (0x1u << 10) /**< \brief (LCDC_HEOIDR) End of DMA Transfer for U or UV Chrominance Component Interrupt Disable */
#define LCDC_HEOIDR_UDSCR (0x1u << 11) /**< \brief (LCDC_HEOIDR) Descriptor Loaded for U or UV Chrominance Component Interrupt Disable */
#define LCDC_HEOIDR_UADD (0x1u << 12) /**< \brief (LCDC_HEOIDR) Head Descriptor Loaded for U or UV Chrominance Component Interrupt Disable */
#define LCDC_HEOIDR_UDONE (0x1u << 13) /**< \brief (LCDC_HEOIDR) End of List Interrupt for U or UV Chrominance Component Disable */
#define LCDC_HEOIDR_UOVR (0x1u << 14) /**< \brief (LCDC_HEOIDR) Overflow Interrupt for U or UV Chrominance Component Disable */
#define LCDC_HEOIDR_VDMA (0x1u << 18) /**< \brief (LCDC_HEOIDR) End of DMA Transfer for V Chrominance Component Interrupt Disable */
#define LCDC_HEOIDR_VDSCR (0x1u << 19) /**< \brief (LCDC_HEOIDR) Descriptor Loaded for V Chrominance Component Interrupt Disable */
#define LCDC_HEOIDR_VADD (0x1u << 20) /**< \brief (LCDC_HEOIDR) Head Descriptor Loaded for V Chrominance Component Interrupt Disable */
#define LCDC_HEOIDR_VDONE (0x1u << 21) /**< \brief (LCDC_HEOIDR) End of List for V Chrominance Component Interrupt Disable */
#define LCDC_HEOIDR_VOVR (0x1u << 22) /**< \brief (LCDC_HEOIDR) Overflow for V Chrominance Component Interrupt Disable */
/* -------- LCDC_HEOIMR : (LCDC Offset: 0x374) High-End Overlay Interrupt Mask Register -------- */
#define LCDC_HEOIMR_DMA (0x1u << 2) /**< \brief (LCDC_HEOIMR) End of DMA Transfer Interrupt Mask */
#define LCDC_HEOIMR_DSCR (0x1u << 3) /**< \brief (LCDC_HEOIMR) Descriptor Loaded Interrupt Mask */
#define LCDC_HEOIMR_ADD (0x1u << 4) /**< \brief (LCDC_HEOIMR) Head Descriptor Loaded Interrupt Mask */
#define LCDC_HEOIMR_DONE (0x1u << 5) /**< \brief (LCDC_HEOIMR) End of List Interrupt Mask */
#define LCDC_HEOIMR_OVR (0x1u << 6) /**< \brief (LCDC_HEOIMR) Overflow Interrupt Mask */
#define LCDC_HEOIMR_UDMA (0x1u << 10) /**< \brief (LCDC_HEOIMR) End of DMA Transfer for U or UV Chrominance Component Interrupt Mask */
#define LCDC_HEOIMR_UDSCR (0x1u << 11) /**< \brief (LCDC_HEOIMR) Descriptor Loaded for U or UV Chrominance Component Interrupt Mask */
#define LCDC_HEOIMR_UADD (0x1u << 12) /**< \brief (LCDC_HEOIMR) Head Descriptor Loaded for U or UV Chrominance Component Mask */
#define LCDC_HEOIMR_UDONE (0x1u << 13) /**< \brief (LCDC_HEOIMR) End of List for U or UV Chrominance Component Mask */
#define LCDC_HEOIMR_UOVR (0x1u << 14) /**< \brief (LCDC_HEOIMR) Overflow for U Chrominance Interrupt Mask */
#define LCDC_HEOIMR_VDMA (0x1u << 18) /**< \brief (LCDC_HEOIMR) End of DMA Transfer for V Chrominance Component Interrupt Mask */
#define LCDC_HEOIMR_VDSCR (0x1u << 19) /**< \brief (LCDC_HEOIMR) Descriptor Loaded for V Chrominance Component Interrupt Mask */
#define LCDC_HEOIMR_VADD (0x1u << 20) /**< \brief (LCDC_HEOIMR) Head Descriptor Loaded for V Chrominance Component Mask */
#define LCDC_HEOIMR_VDONE (0x1u << 21) /**< \brief (LCDC_HEOIMR) End of List for V Chrominance Component Mask */
#define LCDC_HEOIMR_VOVR (0x1u << 22) /**< \brief (LCDC_HEOIMR) Overflow for V Chrominance Interrupt Mask */
/* -------- LCDC_HEOISR : (LCDC Offset: 0x378) High-End Overlay Interrupt Status Register -------- */
#define LCDC_HEOISR_DMA (0x1u << 2) /**< \brief (LCDC_HEOISR) End of DMA Transfer */
#define LCDC_HEOISR_DSCR (0x1u << 3) /**< \brief (LCDC_HEOISR) DMA Descriptor Loaded */
#define LCDC_HEOISR_ADD (0x1u << 4) /**< \brief (LCDC_HEOISR) Head Descriptor Loaded */
#define LCDC_HEOISR_DONE (0x1u << 5) /**< \brief (LCDC_HEOISR) End of List Detected */
#define LCDC_HEOISR_OVR (0x1u << 6) /**< \brief (LCDC_HEOISR) Overflow Detected */
#define LCDC_HEOISR_UDMA (0x1u << 10) /**< \brief (LCDC_HEOISR) End of DMA Transfer for U Component */
#define LCDC_HEOISR_UDSCR (0x1u << 11) /**< \brief (LCDC_HEOISR) DMA Descriptor Loaded for U Component */
#define LCDC_HEOISR_UADD (0x1u << 12) /**< \brief (LCDC_HEOISR) Head Descriptor Loaded for U Component */
#define LCDC_HEOISR_UDONE (0x1u << 13) /**< \brief (LCDC_HEOISR) End of List Detected for U Component */
#define LCDC_HEOISR_UOVR (0x1u << 14) /**< \brief (LCDC_HEOISR) Overflow Detected for U Component */
#define LCDC_HEOISR_VDMA (0x1u << 18) /**< \brief (LCDC_HEOISR) End of DMA Transfer for V Component */
#define LCDC_HEOISR_VDSCR (0x1u << 19) /**< \brief (LCDC_HEOISR) DMA Descriptor Loaded for V Component */
#define LCDC_HEOISR_VADD (0x1u << 20) /**< \brief (LCDC_HEOISR) Head Descriptor Loaded for V Component */
#define LCDC_HEOISR_VDONE (0x1u << 21) /**< \brief (LCDC_HEOISR) End of List Detected for V Component */
#define LCDC_HEOISR_VOVR (0x1u << 22) /**< \brief (LCDC_HEOISR) Overflow Detected for V Component */
/* -------- LCDC_HEOHEAD : (LCDC Offset: 0x37C) High-End Overlay DMA Head Register -------- */
#define LCDC_HEOHEAD_HEAD_Pos 2
#define LCDC_HEOHEAD_HEAD_Msk (0x3fffffffu << LCDC_HEOHEAD_HEAD_Pos) /**< \brief (LCDC_HEOHEAD) DMA Head Pointer */
#define LCDC_HEOHEAD_HEAD(value) ((LCDC_HEOHEAD_HEAD_Msk & ((value) << LCDC_HEOHEAD_HEAD_Pos)))
/* -------- LCDC_HEOADDR : (LCDC Offset: 0x380) High-End Overlay DMA Address Register -------- */
#define LCDC_HEOADDR_ADDR_Pos 0
#define LCDC_HEOADDR_ADDR_Msk (0xffffffffu << LCDC_HEOADDR_ADDR_Pos) /**< \brief (LCDC_HEOADDR) DMA Transfer Start Address */
#define LCDC_HEOADDR_ADDR(value) ((LCDC_HEOADDR_ADDR_Msk & ((value) << LCDC_HEOADDR_ADDR_Pos)))
/* -------- LCDC_HEOCTRL : (LCDC Offset: 0x384) High-End Overlay DMA Control Register -------- */
#define LCDC_HEOCTRL_DFETCH (0x1u << 0) /**< \brief (LCDC_HEOCTRL) Transfer Descriptor Fetch Enable */
#define LCDC_HEOCTRL_LFETCH (0x1u << 1) /**< \brief (LCDC_HEOCTRL) Lookup Table Fetch Enable */
#define LCDC_HEOCTRL_DMAIEN (0x1u << 2) /**< \brief (LCDC_HEOCTRL) End of DMA Transfer Interrupt Enable */
#define LCDC_HEOCTRL_DSCRIEN (0x1u << 3) /**< \brief (LCDC_HEOCTRL) Descriptor Loaded Interrupt Enable */
#define LCDC_HEOCTRL_ADDIEN (0x1u << 4) /**< \brief (LCDC_HEOCTRL) Add Head Descriptor to Queue Interrupt Enable */
#define LCDC_HEOCTRL_DONEIEN (0x1u << 5) /**< \brief (LCDC_HEOCTRL) End of List Interrupt Enable */
/* -------- LCDC_HEONEXT : (LCDC Offset: 0x388) High-End Overlay DMA Next Register -------- */
#define LCDC_HEONEXT_NEXT_Pos 0
#define LCDC_HEONEXT_NEXT_Msk (0xffffffffu << LCDC_HEONEXT_NEXT_Pos) /**< \brief (LCDC_HEONEXT) DMA Descriptor Next Address */
#define LCDC_HEONEXT_NEXT(value) ((LCDC_HEONEXT_NEXT_Msk & ((value) << LCDC_HEONEXT_NEXT_Pos)))
/* -------- LCDC_HEOUHEAD : (LCDC Offset: 0x38C) High-End Overlay U-UV DMA Head Register -------- */
#define LCDC_HEOUHEAD_UHEAD_Pos 0
#define LCDC_HEOUHEAD_UHEAD_Msk (0xffffffffu << LCDC_HEOUHEAD_UHEAD_Pos) /**< \brief (LCDC_HEOUHEAD) DMA Head Pointer */
#define LCDC_HEOUHEAD_UHEAD(value) ((LCDC_HEOUHEAD_UHEAD_Msk & ((value) << LCDC_HEOUHEAD_UHEAD_Pos)))
/* -------- LCDC_HEOUADDR : (LCDC Offset: 0x390) High-End Overlay U-UV DMA Address Register -------- */
#define LCDC_HEOUADDR_UADDR_Pos 0
#define LCDC_HEOUADDR_UADDR_Msk (0xffffffffu << LCDC_HEOUADDR_UADDR_Pos) /**< \brief (LCDC_HEOUADDR) DMA Transfer Start Address for U or UV Chrominance */
#define LCDC_HEOUADDR_UADDR(value) ((LCDC_HEOUADDR_UADDR_Msk & ((value) << LCDC_HEOUADDR_UADDR_Pos)))
/* -------- LCDC_HEOUCTRL : (LCDC Offset: 0x394) High-End Overlay U-UV DMA Control Register -------- */
#define LCDC_HEOUCTRL_UDFETCH (0x1u << 0) /**< \brief (LCDC_HEOUCTRL) Transfer Descriptor Fetch Enable */
#define LCDC_HEOUCTRL_UDMAIEN (0x1u << 2) /**< \brief (LCDC_HEOUCTRL) End of DMA Transfer Interrupt Enable */
#define LCDC_HEOUCTRL_UDSCRIEN (0x1u << 3) /**< \brief (LCDC_HEOUCTRL) Descriptor Loaded Interrupt Enable */
#define LCDC_HEOUCTRL_UADDIEN (0x1u << 4) /**< \brief (LCDC_HEOUCTRL) Add Head Descriptor to Queue Interrupt Enable */
#define LCDC_HEOUCTRL_UDONEIEN (0x1u << 5) /**< \brief (LCDC_HEOUCTRL) End of List Interrupt Enable */
/* -------- LCDC_HEOUNEXT : (LCDC Offset: 0x398) High-End Overlay U-UV DMA Next Register -------- */
#define LCDC_HEOUNEXT_UNEXT_Pos 0
#define LCDC_HEOUNEXT_UNEXT_Msk (0xffffffffu << LCDC_HEOUNEXT_UNEXT_Pos) /**< \brief (LCDC_HEOUNEXT) DMA Descriptor Next Address */
#define LCDC_HEOUNEXT_UNEXT(value) ((LCDC_HEOUNEXT_UNEXT_Msk & ((value) << LCDC_HEOUNEXT_UNEXT_Pos)))
/* -------- LCDC_HEOVHEAD : (LCDC Offset: 0x39C) High-End Overlay V DMA Head Register -------- */
#define LCDC_HEOVHEAD_VHEAD_Pos 0
#define LCDC_HEOVHEAD_VHEAD_Msk (0xffffffffu << LCDC_HEOVHEAD_VHEAD_Pos) /**< \brief (LCDC_HEOVHEAD) DMA Head Pointer */
#define LCDC_HEOVHEAD_VHEAD(value) ((LCDC_HEOVHEAD_VHEAD_Msk & ((value) << LCDC_HEOVHEAD_VHEAD_Pos)))
/* -------- LCDC_HEOVADDR : (LCDC Offset: 0x3A0) High-End Overlay V DMA Address Register -------- */
#define LCDC_HEOVADDR_VADDR_Pos 0
#define LCDC_HEOVADDR_VADDR_Msk (0xffffffffu << LCDC_HEOVADDR_VADDR_Pos) /**< \brief (LCDC_HEOVADDR) DMA Transfer Start Address for V Chrominance */
#define LCDC_HEOVADDR_VADDR(value) ((LCDC_HEOVADDR_VADDR_Msk & ((value) << LCDC_HEOVADDR_VADDR_Pos)))
/* -------- LCDC_HEOVCTRL : (LCDC Offset: 0x3A4) High-End Overlay V DMA Control Register -------- */
#define LCDC_HEOVCTRL_VDFETCH (0x1u << 0) /**< \brief (LCDC_HEOVCTRL) Transfer Descriptor Fetch Enable */
#define LCDC_HEOVCTRL_VDMAIEN (0x1u << 2) /**< \brief (LCDC_HEOVCTRL) End of DMA Transfer Interrupt Enable */
#define LCDC_HEOVCTRL_VDSCRIEN (0x1u << 3) /**< \brief (LCDC_HEOVCTRL) Descriptor Loaded Interrupt Enable */
#define LCDC_HEOVCTRL_VADDIEN (0x1u << 4) /**< \brief (LCDC_HEOVCTRL) Add Head Descriptor to Queue Interrupt Enable */
#define LCDC_HEOVCTRL_VDONEIEN (0x1u << 5) /**< \brief (LCDC_HEOVCTRL) End of List Interrupt Enable */
/* -------- LCDC_HEOVNEXT : (LCDC Offset: 0x3A8) High-End Overlay V DMA Next Register -------- */
#define LCDC_HEOVNEXT_VNEXT_Pos 0
#define LCDC_HEOVNEXT_VNEXT_Msk (0xffffffffu << LCDC_HEOVNEXT_VNEXT_Pos) /**< \brief (LCDC_HEOVNEXT) DMA Descriptor Next Address */
#define LCDC_HEOVNEXT_VNEXT(value) ((LCDC_HEOVNEXT_VNEXT_Msk & ((value) << LCDC_HEOVNEXT_VNEXT_Pos)))
/* -------- LCDC_HEOCFG0 : (LCDC Offset: 0x3AC) High-End Overlay Configuration Register 0 -------- */
#define LCDC_HEOCFG0_BLEN_Pos 4
#define LCDC_HEOCFG0_BLEN_Msk (0x3u << LCDC_HEOCFG0_BLEN_Pos) /**< \brief (LCDC_HEOCFG0) System Bus Burst Length */
#define LCDC_HEOCFG0_BLEN(value) ((LCDC_HEOCFG0_BLEN_Msk & ((value) << LCDC_HEOCFG0_BLEN_Pos)))
#define   LCDC_HEOCFG0_BLEN_AHB_SINGLE (0x0u << 4) /**< \brief (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_HEOCFG0_BLEN_AHB_INCR4 (0x1u << 4) /**< \brief (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. An AHB INCR4 Burst is used. SINGLE, INCR and INCR4 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_HEOCFG0_BLEN_AHB_INCR8 (0x2u << 4) /**< \brief (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. An AHB INCR8 Burst is used. SINGLE, INCR, INCR4 and INCR8 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_HEOCFG0_BLEN_AHB_INCR16 (0x3u << 4) /**< \brief (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. An AHB INCR16 Burst is used. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define LCDC_HEOCFG0_BLENUV_Pos 6
#define LCDC_HEOCFG0_BLENUV_Msk (0x3u << LCDC_HEOCFG0_BLENUV_Pos) /**< \brief (LCDC_HEOCFG0) System Bus Burst Length for U-V Channel */
#define LCDC_HEOCFG0_BLENUV(value) ((LCDC_HEOCFG0_BLENUV_Msk & ((value) << LCDC_HEOCFG0_BLENUV_Pos)))
#define   LCDC_HEOCFG0_BLENUV_AHB_SINGLE (0x0u << 6) /**< \brief (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store one data. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_HEOCFG0_BLENUV_AHB_INCR4 (0x1u << 6) /**< \brief (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 4 data. A system bus INCR4 Burst is used. SINGLE, INCR and INCR4 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_HEOCFG0_BLENUV_AHB_INCR8 (0x2u << 6) /**< \brief (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 8 data. A system bus INCR8 Burst is used. SINGLE, INCR, INCR4 and INCR8 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define   LCDC_HEOCFG0_BLENUV_AHB_INCR16 (0x3u << 6) /**< \brief (LCDC_HEOCFG0) System bus access is started as soon as there is enough space in the FIFO to store a total amount of 16 data. A system bus INCR16 Burst is used. SINGLE, INCR, INCR4, INCR8 and INCR16 bursts are used. INCR is used for a burst of 2 and 3 beats. */
#define LCDC_HEOCFG0_DLBO (0x1u << 8) /**< \brief (LCDC_HEOCFG0) Defined Length Burst Only For Channel Bus Transaction */
#define LCDC_HEOCFG0_ROTDIS (0x1u << 12) /**< \brief (LCDC_HEOCFG0) Hardware Rotation Optimization Disable */
#define LCDC_HEOCFG0_LOCKDIS (0x1u << 13) /**< \brief (LCDC_HEOCFG0) Hardware Rotation Lock Disable */
/* -------- LCDC_HEOCFG1 : (LCDC Offset: 0x3B0) High-End Overlay Configuration Register 1 -------- */
#define LCDC_HEOCFG1_CLUTEN (0x1u << 0) /**< \brief (LCDC_HEOCFG1) Color Lookup Table Mode Enable */
#define LCDC_HEOCFG1_YUVEN (0x1u << 1) /**< \brief (LCDC_HEOCFG1) YUV Color Space Enable */
#define LCDC_HEOCFG1_RGBMODE_Pos 4
#define LCDC_HEOCFG1_RGBMODE_Msk (0xfu << LCDC_HEOCFG1_RGBMODE_Pos) /**< \brief (LCDC_HEOCFG1) RGB Mode Input Selection */
#define LCDC_HEOCFG1_RGBMODE(value) ((LCDC_HEOCFG1_RGBMODE_Msk & ((value) << LCDC_HEOCFG1_RGBMODE_Pos)))
#define   LCDC_HEOCFG1_RGBMODE_12BPP_RGB_444 (0x0u << 4) /**< \brief (LCDC_HEOCFG1) 12 bpp RGB 444 */
#define   LCDC_HEOCFG1_RGBMODE_16BPP_ARGB_4444 (0x1u << 4) /**< \brief (LCDC_HEOCFG1) 16 bpp ARGB 4444 */
#define   LCDC_HEOCFG1_RGBMODE_16BPP_RGBA_4444 (0x2u << 4) /**< \brief (LCDC_HEOCFG1) 16 bpp RGBA 4444 */
#define   LCDC_HEOCFG1_RGBMODE_16BPP_RGB_565 (0x3u << 4) /**< \brief (LCDC_HEOCFG1) 16 bpp RGB 565 */
#define   LCDC_HEOCFG1_RGBMODE_16BPP_TRGB_1555 (0x4u << 4) /**< \brief (LCDC_HEOCFG1) 16 bpp TRGB 1555 */
#define   LCDC_HEOCFG1_RGBMODE_18BPP_RGB_666 (0x5u << 4) /**< \brief (LCDC_HEOCFG1) 18 bpp RGB 666 */
#define   LCDC_HEOCFG1_RGBMODE_18BPP_RGB_666_PACKED (0x6u << 4) /**< \brief (LCDC_HEOCFG1) 18 bpp RGB 666 PACKED */
#define   LCDC_HEOCFG1_RGBMODE_19BPP_TRGB_1666 (0x7u << 4) /**< \brief (LCDC_HEOCFG1) 19 bpp TRGB 1666 */
#define   LCDC_HEOCFG1_RGBMODE_19BPP_TRGB_PACKED (0x8u << 4) /**< \brief (LCDC_HEOCFG1) 19 bpp TRGB 1666 PACKED */
#define   LCDC_HEOCFG1_RGBMODE_24BPP_RGB_888 (0x9u << 4) /**< \brief (LCDC_HEOCFG1) 24 bpp RGB 888 */
#define   LCDC_HEOCFG1_RGBMODE_24BPP_RGB_888_PACKED (0xAu << 4) /**< \brief (LCDC_HEOCFG1) 24 bpp RGB 888 PACKED */
#define   LCDC_HEOCFG1_RGBMODE_25BPP_TRGB_1888 (0xBu << 4) /**< \brief (LCDC_HEOCFG1) 25 bpp TRGB 1888 */
#define   LCDC_HEOCFG1_RGBMODE_32BPP_ARGB_8888 (0xCu << 4) /**< \brief (LCDC_HEOCFG1) 32 bpp ARGB 8888 */
#define   LCDC_HEOCFG1_RGBMODE_32BPP_RGBA_8888 (0xDu << 4) /**< \brief (LCDC_HEOCFG1) 32 bpp RGBA 8888 */
#define LCDC_HEOCFG1_CLUTMODE_Pos 8
#define LCDC_HEOCFG1_CLUTMODE_Msk (0x3u << LCDC_HEOCFG1_CLUTMODE_Pos) /**< \brief (LCDC_HEOCFG1) Color Lookup Table Mode Input Selection */
#define LCDC_HEOCFG1_CLUTMODE(value) ((LCDC_HEOCFG1_CLUTMODE_Msk & ((value) << LCDC_HEOCFG1_CLUTMODE_Pos)))
#define   LCDC_HEOCFG1_CLUTMODE_1BPP (0x0u << 8) /**< \brief (LCDC_HEOCFG1) Color Lookup Table mode set to 1 bit per pixel */
#define   LCDC_HEOCFG1_CLUTMODE_2BPP (0x1u << 8) /**< \brief (LCDC_HEOCFG1) Color Lookup Table mode set to 2 bits per pixel */
#define   LCDC_HEOCFG1_CLUTMODE_4BPP (0x2u << 8) /**< \brief (LCDC_HEOCFG1) Color Lookup Table mode set to 4 bits per pixel */
#define   LCDC_HEOCFG1_CLUTMODE_8BPP (0x3u << 8) /**< \brief (LCDC_HEOCFG1) Color Lookup Table mode set to 8 bits per pixel */
#define LCDC_HEOCFG1_YUVMODE_Pos 12
#define LCDC_HEOCFG1_YUVMODE_Msk (0xfu << LCDC_HEOCFG1_YUVMODE_Pos) /**< \brief (LCDC_HEOCFG1) YUV Mode Input Selection */
#define LCDC_HEOCFG1_YUVMODE(value) ((LCDC_HEOCFG1_YUVMODE_Msk & ((value) << LCDC_HEOCFG1_YUVMODE_Pos)))
#define   LCDC_HEOCFG1_YUVMODE_32BPP_AYCBCR (0x0u << 12) /**< \brief (LCDC_HEOCFG1) 32 bpp AYCbCr 444 */
#define   LCDC_HEOCFG1_YUVMODE_16BPP_YCBCR_MODE0 (0x1u << 12) /**< \brief (LCDC_HEOCFG1) 16 bpp Cr(n)Y(n+1)Cb(n)Y(n) 422 */
#define   LCDC_HEOCFG1_YUVMODE_16BPP_YCBCR_MODE1 (0x2u << 12) /**< \brief (LCDC_HEOCFG1) 16 bpp Y(n+1)Cr(n)Y(n)Cb(n) 422 */
#define   LCDC_HEOCFG1_YUVMODE_16BPP_YCBCR_MODE2 (0x3u << 12) /**< \brief (LCDC_HEOCFG1) 16 bpp Cb(n)Y(+1)Cr(n)Y(n) 422 */
#define   LCDC_HEOCFG1_YUVMODE_16BPP_YCBCR_MODE3 (0x4u << 12) /**< \brief (LCDC_HEOCFG1) 16 bpp Y(n+1)Cb(n)Y(n)Cr(n) 422 */
#define   LCDC_HEOCFG1_YUVMODE_16BPP_YCBCR_SEMIPLANAR (0x5u << 12) /**< \brief (LCDC_HEOCFG1) 16 bpp Semiplanar 422 YCbCr */
#define   LCDC_HEOCFG1_YUVMODE_16BPP_YCBCR_PLANAR (0x6u << 12) /**< \brief (LCDC_HEOCFG1) 16 bpp Planar 422 YCbCr */
#define   LCDC_HEOCFG1_YUVMODE_12BPP_YCBCR_SEMIPLANAR (0x7u << 12) /**< \brief (LCDC_HEOCFG1) 12 bpp Semiplanar 420 YCbCr */
#define   LCDC_HEOCFG1_YUVMODE_12BPP_YCBCR_PLANAR (0x8u << 12) /**< \brief (LCDC_HEOCFG1) 12 bpp Planar 420 YCbCr */
#define LCDC_HEOCFG1_YUV422ROT (0x1u << 16) /**< \brief (LCDC_HEOCFG1) YUV 4:2:2 Rotation */
#define LCDC_HEOCFG1_YUV422SWP (0x1u << 17) /**< \brief (LCDC_HEOCFG1) YUV 4:2:2 Swap */
#define LCDC_HEOCFG1_DSCALEOPT (0x1u << 20) /**< \brief (LCDC_HEOCFG1) Down Scaling Bandwidth Optimization */
/* -------- LCDC_HEOCFG2 : (LCDC Offset: 0x3B4) High-End Overlay Configuration Register 2 -------- */
#define LCDC_HEOCFG2_XPOS_Pos 0
#define LCDC_HEOCFG2_XPOS_Msk (0x7ffu << LCDC_HEOCFG2_XPOS_Pos) /**< \brief (LCDC_HEOCFG2) Horizontal Window Position */
#define LCDC_HEOCFG2_XPOS(value) ((LCDC_HEOCFG2_XPOS_Msk & ((value) << LCDC_HEOCFG2_XPOS_Pos)))
#define LCDC_HEOCFG2_YPOS_Pos 16
#define LCDC_HEOCFG2_YPOS_Msk (0x7ffu << LCDC_HEOCFG2_YPOS_Pos) /**< \brief (LCDC_HEOCFG2) Vertical Window Position */
#define LCDC_HEOCFG2_YPOS(value) ((LCDC_HEOCFG2_YPOS_Msk & ((value) << LCDC_HEOCFG2_YPOS_Pos)))
/* -------- LCDC_HEOCFG3 : (LCDC Offset: 0x3B8) High-End Overlay Configuration Register 3 -------- */
#define LCDC_HEOCFG3_XSIZE_Pos 0
#define LCDC_HEOCFG3_XSIZE_Msk (0x7ffu << LCDC_HEOCFG3_XSIZE_Pos) /**< \brief (LCDC_HEOCFG3) Horizontal Window Size */
#define LCDC_HEOCFG3_XSIZE(value) ((LCDC_HEOCFG3_XSIZE_Msk & ((value) << LCDC_HEOCFG3_XSIZE_Pos)))
#define LCDC_HEOCFG3_YSIZE_Pos 16
#define LCDC_HEOCFG3_YSIZE_Msk (0x7ffu << LCDC_HEOCFG3_YSIZE_Pos) /**< \brief (LCDC_HEOCFG3) Vertical Window Size */
#define LCDC_HEOCFG3_YSIZE(value) ((LCDC_HEOCFG3_YSIZE_Msk & ((value) << LCDC_HEOCFG3_YSIZE_Pos)))
/* -------- LCDC_HEOCFG4 : (LCDC Offset: 0x3BC) High-End Overlay Configuration Register 4 -------- */
#define LCDC_HEOCFG4_XMEMSIZE_Pos 0
#define LCDC_HEOCFG4_XMEMSIZE_Msk (0x7ffu << LCDC_HEOCFG4_XMEMSIZE_Pos) /**< \brief (LCDC_HEOCFG4) Horizontal image Size in Memory */
#define LCDC_HEOCFG4_XMEMSIZE(value) ((LCDC_HEOCFG4_XMEMSIZE_Msk & ((value) << LCDC_HEOCFG4_XMEMSIZE_Pos)))
#define LCDC_HEOCFG4_YMEMSIZE_Pos 16
#define LCDC_HEOCFG4_YMEMSIZE_Msk (0x7ffu << LCDC_HEOCFG4_YMEMSIZE_Pos) /**< \brief (LCDC_HEOCFG4) Vertical image Size in Memory */
#define LCDC_HEOCFG4_YMEMSIZE(value) ((LCDC_HEOCFG4_YMEMSIZE_Msk & ((value) << LCDC_HEOCFG4_YMEMSIZE_Pos)))
/* -------- LCDC_HEOCFG5 : (LCDC Offset: 0x3C0) High-End Overlay Configuration Register 5 -------- */
#define LCDC_HEOCFG5_XSTRIDE_Pos 0
#define LCDC_HEOCFG5_XSTRIDE_Msk (0xffffffffu << LCDC_HEOCFG5_XSTRIDE_Pos) /**< \brief (LCDC_HEOCFG5) Horizontal Stride */
#define LCDC_HEOCFG5_XSTRIDE(value) ((LCDC_HEOCFG5_XSTRIDE_Msk & ((value) << LCDC_HEOCFG5_XSTRIDE_Pos)))
/* -------- LCDC_HEOCFG6 : (LCDC Offset: 0x3C4) High-End Overlay Configuration Register 6 -------- */
#define LCDC_HEOCFG6_PSTRIDE_Pos 0
#define LCDC_HEOCFG6_PSTRIDE_Msk (0xffffffffu << LCDC_HEOCFG6_PSTRIDE_Pos) /**< \brief (LCDC_HEOCFG6) Pixel Stride */
#define LCDC_HEOCFG6_PSTRIDE(value) ((LCDC_HEOCFG6_PSTRIDE_Msk & ((value) << LCDC_HEOCFG6_PSTRIDE_Pos)))
/* -------- LCDC_HEOCFG7 : (LCDC Offset: 0x3C8) High-End Overlay Configuration Register 7 -------- */
#define LCDC_HEOCFG7_UVXSTRIDE_Pos 0
#define LCDC_HEOCFG7_UVXSTRIDE_Msk (0xffffffffu << LCDC_HEOCFG7_UVXSTRIDE_Pos) /**< \brief (LCDC_HEOCFG7) UV Horizontal Stride */
#define LCDC_HEOCFG7_UVXSTRIDE(value) ((LCDC_HEOCFG7_UVXSTRIDE_Msk & ((value) << LCDC_HEOCFG7_UVXSTRIDE_Pos)))
/* -------- LCDC_HEOCFG8 : (LCDC Offset: 0x3CC) High-End Overlay Configuration Register 8 -------- */
#define LCDC_HEOCFG8_UVPSTRIDE_Pos 0
#define LCDC_HEOCFG8_UVPSTRIDE_Msk (0xffffffffu << LCDC_HEOCFG8_UVPSTRIDE_Pos) /**< \brief (LCDC_HEOCFG8) UV Pixel Stride */
#define LCDC_HEOCFG8_UVPSTRIDE(value) ((LCDC_HEOCFG8_UVPSTRIDE_Msk & ((value) << LCDC_HEOCFG8_UVPSTRIDE_Pos)))
/* -------- LCDC_HEOCFG9 : (LCDC Offset: 0x3D0) High-End Overlay Configuration Register 9 -------- */
#define LCDC_HEOCFG9_BDEF_Pos 0
#define LCDC_HEOCFG9_BDEF_Msk (0xffu << LCDC_HEOCFG9_BDEF_Pos) /**< \brief (LCDC_HEOCFG9) Blue Default */
#define LCDC_HEOCFG9_BDEF(value) ((LCDC_HEOCFG9_BDEF_Msk & ((value) << LCDC_HEOCFG9_BDEF_Pos)))
#define LCDC_HEOCFG9_GDEF_Pos 8
#define LCDC_HEOCFG9_GDEF_Msk (0xffu << LCDC_HEOCFG9_GDEF_Pos) /**< \brief (LCDC_HEOCFG9) Green Default */
#define LCDC_HEOCFG9_GDEF(value) ((LCDC_HEOCFG9_GDEF_Msk & ((value) << LCDC_HEOCFG9_GDEF_Pos)))
#define LCDC_HEOCFG9_RDEF_Pos 16
#define LCDC_HEOCFG9_RDEF_Msk (0xffu << LCDC_HEOCFG9_RDEF_Pos) /**< \brief (LCDC_HEOCFG9) Red Default */
#define LCDC_HEOCFG9_RDEF(value) ((LCDC_HEOCFG9_RDEF_Msk & ((value) << LCDC_HEOCFG9_RDEF_Pos)))
/* -------- LCDC_HEOCFG10 : (LCDC Offset: 0x3D4) High-End Overlay Configuration Register 10 -------- */
#define LCDC_HEOCFG10_BKEY_Pos 0
#define LCDC_HEOCFG10_BKEY_Msk (0xffu << LCDC_HEOCFG10_BKEY_Pos) /**< \brief (LCDC_HEOCFG10) Blue Color Component Chroma Key */
#define LCDC_HEOCFG10_BKEY(value) ((LCDC_HEOCFG10_BKEY_Msk & ((value) << LCDC_HEOCFG10_BKEY_Pos)))
#define LCDC_HEOCFG10_GKEY_Pos 8
#define LCDC_HEOCFG10_GKEY_Msk (0xffu << LCDC_HEOCFG10_GKEY_Pos) /**< \brief (LCDC_HEOCFG10) Green Color Component Chroma Key */
#define LCDC_HEOCFG10_GKEY(value) ((LCDC_HEOCFG10_GKEY_Msk & ((value) << LCDC_HEOCFG10_GKEY_Pos)))
#define LCDC_HEOCFG10_RKEY_Pos 16
#define LCDC_HEOCFG10_RKEY_Msk (0xffu << LCDC_HEOCFG10_RKEY_Pos) /**< \brief (LCDC_HEOCFG10) Red Color Component Chroma Key */
#define LCDC_HEOCFG10_RKEY(value) ((LCDC_HEOCFG10_RKEY_Msk & ((value) << LCDC_HEOCFG10_RKEY_Pos)))
/* -------- LCDC_HEOCFG11 : (LCDC Offset: 0x3D8) High-End Overlay Configuration Register 11 -------- */
#define LCDC_HEOCFG11_BMASK_Pos 0
#define LCDC_HEOCFG11_BMASK_Msk (0xffu << LCDC_HEOCFG11_BMASK_Pos) /**< \brief (LCDC_HEOCFG11) Blue Color Component Chroma Key Mask */
#define LCDC_HEOCFG11_BMASK(value) ((LCDC_HEOCFG11_BMASK_Msk & ((value) << LCDC_HEOCFG11_BMASK_Pos)))
#define LCDC_HEOCFG11_GMASK_Pos 8
#define LCDC_HEOCFG11_GMASK_Msk (0xffu << LCDC_HEOCFG11_GMASK_Pos) /**< \brief (LCDC_HEOCFG11) Green Color Component Chroma Key Mask */
#define LCDC_HEOCFG11_GMASK(value) ((LCDC_HEOCFG11_GMASK_Msk & ((value) << LCDC_HEOCFG11_GMASK_Pos)))
#define LCDC_HEOCFG11_RMASK_Pos 16
#define LCDC_HEOCFG11_RMASK_Msk (0xffu << LCDC_HEOCFG11_RMASK_Pos) /**< \brief (LCDC_HEOCFG11) Red Color Component Chroma Key Mask */
#define LCDC_HEOCFG11_RMASK(value) ((LCDC_HEOCFG11_RMASK_Msk & ((value) << LCDC_HEOCFG11_RMASK_Pos)))
/* -------- LCDC_HEOCFG12 : (LCDC Offset: 0x3DC) High-End Overlay Configuration Register 12 -------- */
#define LCDC_HEOCFG12_CRKEY (0x1u << 0) /**< \brief (LCDC_HEOCFG12) Blender Chroma Key Enable */
#define LCDC_HEOCFG12_INV (0x1u << 1) /**< \brief (LCDC_HEOCFG12) Blender Inverted Blender Output Enable */
#define LCDC_HEOCFG12_ITER2BL (0x1u << 2) /**< \brief (LCDC_HEOCFG12) Blender Iterated Color Enable */
#define LCDC_HEOCFG12_ITER (0x1u << 3) /**< \brief (LCDC_HEOCFG12) Blender Use Iterated Color */
#define LCDC_HEOCFG12_REVALPHA (0x1u << 4) /**< \brief (LCDC_HEOCFG12) Blender Reverse Alpha */
#define LCDC_HEOCFG12_GAEN (0x1u << 5) /**< \brief (LCDC_HEOCFG12) Blender Global Alpha Enable */
#define LCDC_HEOCFG12_LAEN (0x1u << 6) /**< \brief (LCDC_HEOCFG12) Blender Local Alpha Enable */
#define LCDC_HEOCFG12_OVR (0x1u << 7) /**< \brief (LCDC_HEOCFG12) Blender Overlay Layer Enable */
#define LCDC_HEOCFG12_DMA (0x1u << 8) /**< \brief (LCDC_HEOCFG12) Blender DMA Layer Enable */
#define LCDC_HEOCFG12_REP (0x1u << 9) /**< \brief (LCDC_HEOCFG12) Use Replication logic to expand RGB color to 24 bits */
#define LCDC_HEOCFG12_DSTKEY (0x1u << 10) /**< \brief (LCDC_HEOCFG12) Destination Chroma Keying */
#define LCDC_HEOCFG12_VIDPRI (0x1u << 12) /**< \brief (LCDC_HEOCFG12) Video Priority */
#define LCDC_HEOCFG12_GA_Pos 16
#define LCDC_HEOCFG12_GA_Msk (0xffu << LCDC_HEOCFG12_GA_Pos) /**< \brief (LCDC_HEOCFG12) Blender Global Alpha */
#define LCDC_HEOCFG12_GA(value) ((LCDC_HEOCFG12_GA_Msk & ((value) << LCDC_HEOCFG12_GA_Pos)))
/* -------- LCDC_HEOCFG13 : (LCDC Offset: 0x3E0) High-End Overlay Configuration Register 13 -------- */
#define LCDC_HEOCFG13_XFACTOR_Pos 0
#define LCDC_HEOCFG13_XFACTOR_Msk (0x3fffu << LCDC_HEOCFG13_XFACTOR_Pos) /**< \brief (LCDC_HEOCFG13) Horizontal Scaling Factor */
#define LCDC_HEOCFG13_XFACTOR(value) ((LCDC_HEOCFG13_XFACTOR_Msk & ((value) << LCDC_HEOCFG13_XFACTOR_Pos)))
#define LCDC_HEOCFG13_YFACTOR_Pos 16
#define LCDC_HEOCFG13_YFACTOR_Msk (0x3fffu << LCDC_HEOCFG13_YFACTOR_Pos) /**< \brief (LCDC_HEOCFG13) Vertical Scaling Factor */
#define LCDC_HEOCFG13_YFACTOR(value) ((LCDC_HEOCFG13_YFACTOR_Msk & ((value) << LCDC_HEOCFG13_YFACTOR_Pos)))
#define LCDC_HEOCFG13_SCALEN (0x1u << 31) /**< \brief (LCDC_HEOCFG13) Hardware Scaler Enable */
/* -------- LCDC_HEOCFG14 : (LCDC Offset: 0x3E4) High-End Overlay Configuration Register 14 -------- */
#define LCDC_HEOCFG14_CSCRY_Pos 0
#define LCDC_HEOCFG14_CSCRY_Msk (0x3ffu << LCDC_HEOCFG14_CSCRY_Pos) /**< \brief (LCDC_HEOCFG14) Color Space Conversion Y coefficient for Red Component 1:2:7 format */
#define LCDC_HEOCFG14_CSCRY(value) ((LCDC_HEOCFG14_CSCRY_Msk & ((value) << LCDC_HEOCFG14_CSCRY_Pos)))
#define LCDC_HEOCFG14_CSCRU_Pos 10
#define LCDC_HEOCFG14_CSCRU_Msk (0x3ffu << LCDC_HEOCFG14_CSCRU_Pos) /**< \brief (LCDC_HEOCFG14) Color Space Conversion U coefficient for Red Component 1:2:7 format */
#define LCDC_HEOCFG14_CSCRU(value) ((LCDC_HEOCFG14_CSCRU_Msk & ((value) << LCDC_HEOCFG14_CSCRU_Pos)))
#define LCDC_HEOCFG14_CSCRV_Pos 20
#define LCDC_HEOCFG14_CSCRV_Msk (0x3ffu << LCDC_HEOCFG14_CSCRV_Pos) /**< \brief (LCDC_HEOCFG14) Color Space Conversion V coefficient for Red Component 1:2:7 format */
#define LCDC_HEOCFG14_CSCRV(value) ((LCDC_HEOCFG14_CSCRV_Msk & ((value) << LCDC_HEOCFG14_CSCRV_Pos)))
#define LCDC_HEOCFG14_CSCYOFF (0x1u << 30) /**< \brief (LCDC_HEOCFG14) Color Space Conversion Offset */
/* -------- LCDC_HEOCFG15 : (LCDC Offset: 0x3E8) High-End Overlay Configuration Register 15 -------- */
#define LCDC_HEOCFG15_CSCGY_Pos 0
#define LCDC_HEOCFG15_CSCGY_Msk (0x3ffu << LCDC_HEOCFG15_CSCGY_Pos) /**< \brief (LCDC_HEOCFG15) Color Space Conversion Y coefficient for Green Component 1:2:7 format */
#define LCDC_HEOCFG15_CSCGY(value) ((LCDC_HEOCFG15_CSCGY_Msk & ((value) << LCDC_HEOCFG15_CSCGY_Pos)))
#define LCDC_HEOCFG15_CSCGU_Pos 10
#define LCDC_HEOCFG15_CSCGU_Msk (0x3ffu << LCDC_HEOCFG15_CSCGU_Pos) /**< \brief (LCDC_HEOCFG15) Color Space Conversion U coefficient for Green Component 1:2:7 format */
#define LCDC_HEOCFG15_CSCGU(value) ((LCDC_HEOCFG15_CSCGU_Msk & ((value) << LCDC_HEOCFG15_CSCGU_Pos)))
#define LCDC_HEOCFG15_CSCGV_Pos 20
#define LCDC_HEOCFG15_CSCGV_Msk (0x3ffu << LCDC_HEOCFG15_CSCGV_Pos) /**< \brief (LCDC_HEOCFG15) Color Space Conversion V coefficient for Green Component 1:2:7 format */
#define LCDC_HEOCFG15_CSCGV(value) ((LCDC_HEOCFG15_CSCGV_Msk & ((value) << LCDC_HEOCFG15_CSCGV_Pos)))
#define LCDC_HEOCFG15_CSCUOFF (0x1u << 30) /**< \brief (LCDC_HEOCFG15) Color Space Conversion Offset */
/* -------- LCDC_HEOCFG16 : (LCDC Offset: 0x3EC) High-End Overlay Configuration Register 16 -------- */
#define LCDC_HEOCFG16_CSCBY_Pos 0
#define LCDC_HEOCFG16_CSCBY_Msk (0x3ffu << LCDC_HEOCFG16_CSCBY_Pos) /**< \brief (LCDC_HEOCFG16) Color Space Conversion Y coefficient for Blue Component 1:2:7 format */
#define LCDC_HEOCFG16_CSCBY(value) ((LCDC_HEOCFG16_CSCBY_Msk & ((value) << LCDC_HEOCFG16_CSCBY_Pos)))
#define LCDC_HEOCFG16_CSCBU_Pos 10
#define LCDC_HEOCFG16_CSCBU_Msk (0x3ffu << LCDC_HEOCFG16_CSCBU_Pos) /**< \brief (LCDC_HEOCFG16) Color Space Conversion U coefficient for Blue Component 1:2:7 format */
#define LCDC_HEOCFG16_CSCBU(value) ((LCDC_HEOCFG16_CSCBU_Msk & ((value) << LCDC_HEOCFG16_CSCBU_Pos)))
#define LCDC_HEOCFG16_CSCBV_Pos 20
#define LCDC_HEOCFG16_CSCBV_Msk (0x3ffu << LCDC_HEOCFG16_CSCBV_Pos) /**< \brief (LCDC_HEOCFG16) Color Space Conversion V coefficient for Blue Component 1:2:7 format */
#define LCDC_HEOCFG16_CSCBV(value) ((LCDC_HEOCFG16_CSCBV_Msk & ((value) << LCDC_HEOCFG16_CSCBV_Pos)))
#define LCDC_HEOCFG16_CSCVOFF (0x1u << 30) /**< \brief (LCDC_HEOCFG16) Color Space Conversion Offset */
/* -------- LCDC_HEOCFG17 : (LCDC Offset: 0x3F0) High-End Overlay Configuration Register 17 -------- */
#define LCDC_HEOCFG17_XPHI0COEFF0_Pos 0
#define LCDC_HEOCFG17_XPHI0COEFF0_Msk (0xffu << LCDC_HEOCFG17_XPHI0COEFF0_Pos) /**< \brief (LCDC_HEOCFG17) Horizontal Coefficient for phase 0 tap 0 */
#define LCDC_HEOCFG17_XPHI0COEFF0(value) ((LCDC_HEOCFG17_XPHI0COEFF0_Msk & ((value) << LCDC_HEOCFG17_XPHI0COEFF0_Pos)))
#define LCDC_HEOCFG17_XPHI0COEFF1_Pos 8
#define LCDC_HEOCFG17_XPHI0COEFF1_Msk (0xffu << LCDC_HEOCFG17_XPHI0COEFF1_Pos) /**< \brief (LCDC_HEOCFG17) Horizontal Coefficient for phase 0 tap 1 */
#define LCDC_HEOCFG17_XPHI0COEFF1(value) ((LCDC_HEOCFG17_XPHI0COEFF1_Msk & ((value) << LCDC_HEOCFG17_XPHI0COEFF1_Pos)))
#define LCDC_HEOCFG17_XPHI0COEFF2_Pos 16
#define LCDC_HEOCFG17_XPHI0COEFF2_Msk (0xffu << LCDC_HEOCFG17_XPHI0COEFF2_Pos) /**< \brief (LCDC_HEOCFG17) Horizontal Coefficient for phase 0 tap 2 */
#define LCDC_HEOCFG17_XPHI0COEFF2(value) ((LCDC_HEOCFG17_XPHI0COEFF2_Msk & ((value) << LCDC_HEOCFG17_XPHI0COEFF2_Pos)))
#define LCDC_HEOCFG17_XPHI0COEFF3_Pos 24
#define LCDC_HEOCFG17_XPHI0COEFF3_Msk (0xffu << LCDC_HEOCFG17_XPHI0COEFF3_Pos) /**< \brief (LCDC_HEOCFG17) Horizontal Coefficient for phase 0 tap 3 */
#define LCDC_HEOCFG17_XPHI0COEFF3(value) ((LCDC_HEOCFG17_XPHI0COEFF3_Msk & ((value) << LCDC_HEOCFG17_XPHI0COEFF3_Pos)))
/* -------- LCDC_HEOCFG18 : (LCDC Offset: 0x3F4) High-End Overlay Configuration Register 18 -------- */
#define LCDC_HEOCFG18_XPHI0COEFF4_Pos 0
#define LCDC_HEOCFG18_XPHI0COEFF4_Msk (0xffu << LCDC_HEOCFG18_XPHI0COEFF4_Pos) /**< \brief (LCDC_HEOCFG18) Horizontal Coefficient for phase 0 tap 4 */
#define LCDC_HEOCFG18_XPHI0COEFF4(value) ((LCDC_HEOCFG18_XPHI0COEFF4_Msk & ((value) << LCDC_HEOCFG18_XPHI0COEFF4_Pos)))
/* -------- LCDC_HEOCFG19 : (LCDC Offset: 0x3F8) High-End Overlay Configuration Register 19 -------- */
#define LCDC_HEOCFG19_XPHI1COEFF0_Pos 0
#define LCDC_HEOCFG19_XPHI1COEFF0_Msk (0xffu << LCDC_HEOCFG19_XPHI1COEFF0_Pos) /**< \brief (LCDC_HEOCFG19) Horizontal Coefficient for phase 1 tap 0 */
#define LCDC_HEOCFG19_XPHI1COEFF0(value) ((LCDC_HEOCFG19_XPHI1COEFF0_Msk & ((value) << LCDC_HEOCFG19_XPHI1COEFF0_Pos)))
#define LCDC_HEOCFG19_XPHI1COEFF1_Pos 8
#define LCDC_HEOCFG19_XPHI1COEFF1_Msk (0xffu << LCDC_HEOCFG19_XPHI1COEFF1_Pos) /**< \brief (LCDC_HEOCFG19) Horizontal Coefficient for phase 1 tap 1 */
#define LCDC_HEOCFG19_XPHI1COEFF1(value) ((LCDC_HEOCFG19_XPHI1COEFF1_Msk & ((value) << LCDC_HEOCFG19_XPHI1COEFF1_Pos)))
#define LCDC_HEOCFG19_XPHI1COEFF2_Pos 16
#define LCDC_HEOCFG19_XPHI1COEFF2_Msk (0xffu << LCDC_HEOCFG19_XPHI1COEFF2_Pos) /**< \brief (LCDC_HEOCFG19) Horizontal Coefficient for phase 1 tap 2 */
#define LCDC_HEOCFG19_XPHI1COEFF2(value) ((LCDC_HEOCFG19_XPHI1COEFF2_Msk & ((value) << LCDC_HEOCFG19_XPHI1COEFF2_Pos)))
#define LCDC_HEOCFG19_XPHI1COEFF3_Pos 24
#define LCDC_HEOCFG19_XPHI1COEFF3_Msk (0xffu << LCDC_HEOCFG19_XPHI1COEFF3_Pos) /**< \brief (LCDC_HEOCFG19) Horizontal Coefficient for phase 1 tap 3 */
#define LCDC_HEOCFG19_XPHI1COEFF3(value) ((LCDC_HEOCFG19_XPHI1COEFF3_Msk & ((value) << LCDC_HEOCFG19_XPHI1COEFF3_Pos)))
/* -------- LCDC_HEOCFG20 : (LCDC Offset: 0x3FC) High-End Overlay Configuration Register 20 -------- */
#define LCDC_HEOCFG20_XPHI1COEFF4_Pos 0
#define LCDC_HEOCFG20_XPHI1COEFF4_Msk (0xffu << LCDC_HEOCFG20_XPHI1COEFF4_Pos) /**< \brief (LCDC_HEOCFG20) Horizontal Coefficient for phase 1 tap 4 */
#define LCDC_HEOCFG20_XPHI1COEFF4(value) ((LCDC_HEOCFG20_XPHI1COEFF4_Msk & ((value) << LCDC_HEOCFG20_XPHI1COEFF4_Pos)))
/* -------- LCDC_HEOCFG21 : (LCDC Offset: 0x400) High-End Overlay Configuration Register 21 -------- */
#define LCDC_HEOCFG21_XPHI2COEFF0_Pos 0
#define LCDC_HEOCFG21_XPHI2COEFF0_Msk (0xffu << LCDC_HEOCFG21_XPHI2COEFF0_Pos) /**< \brief (LCDC_HEOCFG21) Horizontal Coefficient for phase 2 tap 0 */
#define LCDC_HEOCFG21_XPHI2COEFF0(value) ((LCDC_HEOCFG21_XPHI2COEFF0_Msk & ((value) << LCDC_HEOCFG21_XPHI2COEFF0_Pos)))
#define LCDC_HEOCFG21_XPHI2COEFF1_Pos 8
#define LCDC_HEOCFG21_XPHI2COEFF1_Msk (0xffu << LCDC_HEOCFG21_XPHI2COEFF1_Pos) /**< \brief (LCDC_HEOCFG21) Horizontal Coefficient for phase 2 tap 1 */
#define LCDC_HEOCFG21_XPHI2COEFF1(value) ((LCDC_HEOCFG21_XPHI2COEFF1_Msk & ((value) << LCDC_HEOCFG21_XPHI2COEFF1_Pos)))
#define LCDC_HEOCFG21_XPHI2COEFF2_Pos 16
#define LCDC_HEOCFG21_XPHI2COEFF2_Msk (0xffu << LCDC_HEOCFG21_XPHI2COEFF2_Pos) /**< \brief (LCDC_HEOCFG21) Horizontal Coefficient for phase 2 tap 2 */
#define LCDC_HEOCFG21_XPHI2COEFF2(value) ((LCDC_HEOCFG21_XPHI2COEFF2_Msk & ((value) << LCDC_HEOCFG21_XPHI2COEFF2_Pos)))
#define LCDC_HEOCFG21_XPHI2COEFF3_Pos 24
#define LCDC_HEOCFG21_XPHI2COEFF3_Msk (0xffu << LCDC_HEOCFG21_XPHI2COEFF3_Pos) /**< \brief (LCDC_HEOCFG21) Horizontal Coefficient for phase 2 tap 3 */
#define LCDC_HEOCFG21_XPHI2COEFF3(value) ((LCDC_HEOCFG21_XPHI2COEFF3_Msk & ((value) << LCDC_HEOCFG21_XPHI2COEFF3_Pos)))
/* -------- LCDC_HEOCFG22 : (LCDC Offset: 0x404) High-End Overlay Configuration Register 22 -------- */
#define LCDC_HEOCFG22_XPHI2COEFF4_Pos 0
#define LCDC_HEOCFG22_XPHI2COEFF4_Msk (0xffu << LCDC_HEOCFG22_XPHI2COEFF4_Pos) /**< \brief (LCDC_HEOCFG22) Horizontal Coefficient for phase 2 tap 4 */
#define LCDC_HEOCFG22_XPHI2COEFF4(value) ((LCDC_HEOCFG22_XPHI2COEFF4_Msk & ((value) << LCDC_HEOCFG22_XPHI2COEFF4_Pos)))
/* -------- LCDC_HEOCFG23 : (LCDC Offset: 0x408) High-End Overlay Configuration Register 23 -------- */
#define LCDC_HEOCFG23_XPHI3COEFF0_Pos 0
#define LCDC_HEOCFG23_XPHI3COEFF0_Msk (0xffu << LCDC_HEOCFG23_XPHI3COEFF0_Pos) /**< \brief (LCDC_HEOCFG23) Horizontal Coefficient for phase 3 tap 0 */
#define LCDC_HEOCFG23_XPHI3COEFF0(value) ((LCDC_HEOCFG23_XPHI3COEFF0_Msk & ((value) << LCDC_HEOCFG23_XPHI3COEFF0_Pos)))
#define LCDC_HEOCFG23_XPHI3COEFF1_Pos 8
#define LCDC_HEOCFG23_XPHI3COEFF1_Msk (0xffu << LCDC_HEOCFG23_XPHI3COEFF1_Pos) /**< \brief (LCDC_HEOCFG23) Horizontal Coefficient for phase 3 tap 1 */
#define LCDC_HEOCFG23_XPHI3COEFF1(value) ((LCDC_HEOCFG23_XPHI3COEFF1_Msk & ((value) << LCDC_HEOCFG23_XPHI3COEFF1_Pos)))
#define LCDC_HEOCFG23_XPHI3COEFF2_Pos 16
#define LCDC_HEOCFG23_XPHI3COEFF2_Msk (0xffu << LCDC_HEOCFG23_XPHI3COEFF2_Pos) /**< \brief (LCDC_HEOCFG23) Horizontal Coefficient for phase 3 tap 2 */
#define LCDC_HEOCFG23_XPHI3COEFF2(value) ((LCDC_HEOCFG23_XPHI3COEFF2_Msk & ((value) << LCDC_HEOCFG23_XPHI3COEFF2_Pos)))
#define LCDC_HEOCFG23_XPHI3COEFF3_Pos 24
#define LCDC_HEOCFG23_XPHI3COEFF3_Msk (0xffu << LCDC_HEOCFG23_XPHI3COEFF3_Pos) /**< \brief (LCDC_HEOCFG23) Horizontal Coefficient for phase 3 tap 3 */
#define LCDC_HEOCFG23_XPHI3COEFF3(value) ((LCDC_HEOCFG23_XPHI3COEFF3_Msk & ((value) << LCDC_HEOCFG23_XPHI3COEFF3_Pos)))
/* -------- LCDC_HEOCFG24 : (LCDC Offset: 0x40C) High-End Overlay Configuration Register 24 -------- */
#define LCDC_HEOCFG24_XPHI3COEFF4_Pos 0
#define LCDC_HEOCFG24_XPHI3COEFF4_Msk (0xffu << LCDC_HEOCFG24_XPHI3COEFF4_Pos) /**< \brief (LCDC_HEOCFG24) Horizontal Coefficient for phase 3 tap 4 */
#define LCDC_HEOCFG24_XPHI3COEFF4(value) ((LCDC_HEOCFG24_XPHI3COEFF4_Msk & ((value) << LCDC_HEOCFG24_XPHI3COEFF4_Pos)))
/* -------- LCDC_HEOCFG25 : (LCDC Offset: 0x410) High-End Overlay Configuration Register 25 -------- */
#define LCDC_HEOCFG25_XPHI4COEFF0_Pos 0
#define LCDC_HEOCFG25_XPHI4COEFF0_Msk (0xffu << LCDC_HEOCFG25_XPHI4COEFF0_Pos) /**< \brief (LCDC_HEOCFG25) Horizontal Coefficient for phase 4 tap 0 */
#define LCDC_HEOCFG25_XPHI4COEFF0(value) ((LCDC_HEOCFG25_XPHI4COEFF0_Msk & ((value) << LCDC_HEOCFG25_XPHI4COEFF0_Pos)))
#define LCDC_HEOCFG25_XPHI4COEFF1_Pos 8
#define LCDC_HEOCFG25_XPHI4COEFF1_Msk (0xffu << LCDC_HEOCFG25_XPHI4COEFF1_Pos) /**< \brief (LCDC_HEOCFG25) Horizontal Coefficient for phase 4 tap 1 */
#define LCDC_HEOCFG25_XPHI4COEFF1(value) ((LCDC_HEOCFG25_XPHI4COEFF1_Msk & ((value) << LCDC_HEOCFG25_XPHI4COEFF1_Pos)))
#define LCDC_HEOCFG25_XPHI4COEFF2_Pos 16
#define LCDC_HEOCFG25_XPHI4COEFF2_Msk (0xffu << LCDC_HEOCFG25_XPHI4COEFF2_Pos) /**< \brief (LCDC_HEOCFG25) Horizontal Coefficient for phase 4 tap 2 */
#define LCDC_HEOCFG25_XPHI4COEFF2(value) ((LCDC_HEOCFG25_XPHI4COEFF2_Msk & ((value) << LCDC_HEOCFG25_XPHI4COEFF2_Pos)))
#define LCDC_HEOCFG25_XPHI4COEFF3_Pos 24
#define LCDC_HEOCFG25_XPHI4COEFF3_Msk (0xffu << LCDC_HEOCFG25_XPHI4COEFF3_Pos) /**< \brief (LCDC_HEOCFG25) Horizontal Coefficient for phase 4 tap 3 */
#define LCDC_HEOCFG25_XPHI4COEFF3(value) ((LCDC_HEOCFG25_XPHI4COEFF3_Msk & ((value) << LCDC_HEOCFG25_XPHI4COEFF3_Pos)))
/* -------- LCDC_HEOCFG26 : (LCDC Offset: 0x414) High-End Overlay Configuration Register 26 -------- */
#define LCDC_HEOCFG26_XPHI4COEFF4_Pos 0
#define LCDC_HEOCFG26_XPHI4COEFF4_Msk (0xffu << LCDC_HEOCFG26_XPHI4COEFF4_Pos) /**< \brief (LCDC_HEOCFG26) Horizontal Coefficient for phase 4 tap 4 */
#define LCDC_HEOCFG26_XPHI4COEFF4(value) ((LCDC_HEOCFG26_XPHI4COEFF4_Msk & ((value) << LCDC_HEOCFG26_XPHI4COEFF4_Pos)))
/* -------- LCDC_HEOCFG27 : (LCDC Offset: 0x418) High-End Overlay Configuration Register 27 -------- */
#define LCDC_HEOCFG27_XPHI5COEFF0_Pos 0
#define LCDC_HEOCFG27_XPHI5COEFF0_Msk (0xffu << LCDC_HEOCFG27_XPHI5COEFF0_Pos) /**< \brief (LCDC_HEOCFG27) Horizontal Coefficient for phase 5 tap 0 */
#define LCDC_HEOCFG27_XPHI5COEFF0(value) ((LCDC_HEOCFG27_XPHI5COEFF0_Msk & ((value) << LCDC_HEOCFG27_XPHI5COEFF0_Pos)))
#define LCDC_HEOCFG27_XPHI5COEFF1_Pos 8
#define LCDC_HEOCFG27_XPHI5COEFF1_Msk (0xffu << LCDC_HEOCFG27_XPHI5COEFF1_Pos) /**< \brief (LCDC_HEOCFG27) Horizontal Coefficient for phase 5 tap 1 */
#define LCDC_HEOCFG27_XPHI5COEFF1(value) ((LCDC_HEOCFG27_XPHI5COEFF1_Msk & ((value) << LCDC_HEOCFG27_XPHI5COEFF1_Pos)))
#define LCDC_HEOCFG27_XPHI5COEFF2_Pos 16
#define LCDC_HEOCFG27_XPHI5COEFF2_Msk (0xffu << LCDC_HEOCFG27_XPHI5COEFF2_Pos) /**< \brief (LCDC_HEOCFG27) Horizontal Coefficient for phase 5 tap 2 */
#define LCDC_HEOCFG27_XPHI5COEFF2(value) ((LCDC_HEOCFG27_XPHI5COEFF2_Msk & ((value) << LCDC_HEOCFG27_XPHI5COEFF2_Pos)))
#define LCDC_HEOCFG27_XPHI5COEFF3_Pos 24
#define LCDC_HEOCFG27_XPHI5COEFF3_Msk (0xffu << LCDC_HEOCFG27_XPHI5COEFF3_Pos) /**< \brief (LCDC_HEOCFG27) Horizontal Coefficient for phase 5 tap 3 */
#define LCDC_HEOCFG27_XPHI5COEFF3(value) ((LCDC_HEOCFG27_XPHI5COEFF3_Msk & ((value) << LCDC_HEOCFG27_XPHI5COEFF3_Pos)))
/* -------- LCDC_HEOCFG28 : (LCDC Offset: 0x41C) High-End Overlay Configuration Register 28 -------- */
#define LCDC_HEOCFG28_XPHI5COEFF4_Pos 0
#define LCDC_HEOCFG28_XPHI5COEFF4_Msk (0xffu << LCDC_HEOCFG28_XPHI5COEFF4_Pos) /**< \brief (LCDC_HEOCFG28) Horizontal Coefficient for phase 5 tap 4 */
#define LCDC_HEOCFG28_XPHI5COEFF4(value) ((LCDC_HEOCFG28_XPHI5COEFF4_Msk & ((value) << LCDC_HEOCFG28_XPHI5COEFF4_Pos)))
/* -------- LCDC_HEOCFG29 : (LCDC Offset: 0x420) High-End Overlay Configuration Register 29 -------- */
#define LCDC_HEOCFG29_XPHI6COEFF0_Pos 0
#define LCDC_HEOCFG29_XPHI6COEFF0_Msk (0xffu << LCDC_HEOCFG29_XPHI6COEFF0_Pos) /**< \brief (LCDC_HEOCFG29) Horizontal Coefficient for phase 6 tap 0 */
#define LCDC_HEOCFG29_XPHI6COEFF0(value) ((LCDC_HEOCFG29_XPHI6COEFF0_Msk & ((value) << LCDC_HEOCFG29_XPHI6COEFF0_Pos)))
#define LCDC_HEOCFG29_XPHI6COEFF1_Pos 8
#define LCDC_HEOCFG29_XPHI6COEFF1_Msk (0xffu << LCDC_HEOCFG29_XPHI6COEFF1_Pos) /**< \brief (LCDC_HEOCFG29) Horizontal Coefficient for phase 6 tap 1 */
#define LCDC_HEOCFG29_XPHI6COEFF1(value) ((LCDC_HEOCFG29_XPHI6COEFF1_Msk & ((value) << LCDC_HEOCFG29_XPHI6COEFF1_Pos)))
#define LCDC_HEOCFG29_XPHI6COEFF2_Pos 16
#define LCDC_HEOCFG29_XPHI6COEFF2_Msk (0xffu << LCDC_HEOCFG29_XPHI6COEFF2_Pos) /**< \brief (LCDC_HEOCFG29) Horizontal Coefficient for phase 6 tap 2 */
#define LCDC_HEOCFG29_XPHI6COEFF2(value) ((LCDC_HEOCFG29_XPHI6COEFF2_Msk & ((value) << LCDC_HEOCFG29_XPHI6COEFF2_Pos)))
#define LCDC_HEOCFG29_XPHI6COEFF3_Pos 24
#define LCDC_HEOCFG29_XPHI6COEFF3_Msk (0xffu << LCDC_HEOCFG29_XPHI6COEFF3_Pos) /**< \brief (LCDC_HEOCFG29) Horizontal Coefficient for phase 6 tap 3 */
#define LCDC_HEOCFG29_XPHI6COEFF3(value) ((LCDC_HEOCFG29_XPHI6COEFF3_Msk & ((value) << LCDC_HEOCFG29_XPHI6COEFF3_Pos)))
/* -------- LCDC_HEOCFG30 : (LCDC Offset: 0x424) High-End Overlay Configuration Register 30 -------- */
#define LCDC_HEOCFG30_XPHI6COEFF4_Pos 0
#define LCDC_HEOCFG30_XPHI6COEFF4_Msk (0xffu << LCDC_HEOCFG30_XPHI6COEFF4_Pos) /**< \brief (LCDC_HEOCFG30) Horizontal Coefficient for phase 6 tap 4 */
#define LCDC_HEOCFG30_XPHI6COEFF4(value) ((LCDC_HEOCFG30_XPHI6COEFF4_Msk & ((value) << LCDC_HEOCFG30_XPHI6COEFF4_Pos)))
/* -------- LCDC_HEOCFG31 : (LCDC Offset: 0x428) High-End Overlay Configuration Register 31 -------- */
#define LCDC_HEOCFG31_XPHI7COEFF0_Pos 0
#define LCDC_HEOCFG31_XPHI7COEFF0_Msk (0xffu << LCDC_HEOCFG31_XPHI7COEFF0_Pos) /**< \brief (LCDC_HEOCFG31) Horizontal Coefficient for phase 7 tap 0 */
#define LCDC_HEOCFG31_XPHI7COEFF0(value) ((LCDC_HEOCFG31_XPHI7COEFF0_Msk & ((value) << LCDC_HEOCFG31_XPHI7COEFF0_Pos)))
#define LCDC_HEOCFG31_XPHI7COEFF1_Pos 8
#define LCDC_HEOCFG31_XPHI7COEFF1_Msk (0xffu << LCDC_HEOCFG31_XPHI7COEFF1_Pos) /**< \brief (LCDC_HEOCFG31) Horizontal Coefficient for phase 7 tap 1 */
#define LCDC_HEOCFG31_XPHI7COEFF1(value) ((LCDC_HEOCFG31_XPHI7COEFF1_Msk & ((value) << LCDC_HEOCFG31_XPHI7COEFF1_Pos)))
#define LCDC_HEOCFG31_XPHI7COEFF2_Pos 16
#define LCDC_HEOCFG31_XPHI7COEFF2_Msk (0xffu << LCDC_HEOCFG31_XPHI7COEFF2_Pos) /**< \brief (LCDC_HEOCFG31) Horizontal Coefficient for phase 7 tap 2 */
#define LCDC_HEOCFG31_XPHI7COEFF2(value) ((LCDC_HEOCFG31_XPHI7COEFF2_Msk & ((value) << LCDC_HEOCFG31_XPHI7COEFF2_Pos)))
#define LCDC_HEOCFG31_XPHI7COEFF3_Pos 24
#define LCDC_HEOCFG31_XPHI7COEFF3_Msk (0xffu << LCDC_HEOCFG31_XPHI7COEFF3_Pos) /**< \brief (LCDC_HEOCFG31) Horizontal Coefficient for phase 7 tap 3 */
#define LCDC_HEOCFG31_XPHI7COEFF3(value) ((LCDC_HEOCFG31_XPHI7COEFF3_Msk & ((value) << LCDC_HEOCFG31_XPHI7COEFF3_Pos)))
/* -------- LCDC_HEOCFG32 : (LCDC Offset: 0x42C) High-End Overlay Configuration Register 32 -------- */
#define LCDC_HEOCFG32_XPHI7COEFF4_Pos 0
#define LCDC_HEOCFG32_XPHI7COEFF4_Msk (0xffu << LCDC_HEOCFG32_XPHI7COEFF4_Pos) /**< \brief (LCDC_HEOCFG32) Horizontal Coefficient for phase 7 tap 4 */
#define LCDC_HEOCFG32_XPHI7COEFF4(value) ((LCDC_HEOCFG32_XPHI7COEFF4_Msk & ((value) << LCDC_HEOCFG32_XPHI7COEFF4_Pos)))
/* -------- LCDC_HEOCFG33 : (LCDC Offset: 0x430) High-End Overlay Configuration Register 33 -------- */
#define LCDC_HEOCFG33_YPHI0COEFF0_Pos 0
#define LCDC_HEOCFG33_YPHI0COEFF0_Msk (0xffu << LCDC_HEOCFG33_YPHI0COEFF0_Pos) /**< \brief (LCDC_HEOCFG33) Vertical Coefficient for phase 0 tap 0 */
#define LCDC_HEOCFG33_YPHI0COEFF0(value) ((LCDC_HEOCFG33_YPHI0COEFF0_Msk & ((value) << LCDC_HEOCFG33_YPHI0COEFF0_Pos)))
#define LCDC_HEOCFG33_YPHI0COEFF1_Pos 8
#define LCDC_HEOCFG33_YPHI0COEFF1_Msk (0xffu << LCDC_HEOCFG33_YPHI0COEFF1_Pos) /**< \brief (LCDC_HEOCFG33) Vertical Coefficient for phase 0 tap 1 */
#define LCDC_HEOCFG33_YPHI0COEFF1(value) ((LCDC_HEOCFG33_YPHI0COEFF1_Msk & ((value) << LCDC_HEOCFG33_YPHI0COEFF1_Pos)))
#define LCDC_HEOCFG33_YPHI0COEFF2_Pos 16
#define LCDC_HEOCFG33_YPHI0COEFF2_Msk (0xffu << LCDC_HEOCFG33_YPHI0COEFF2_Pos) /**< \brief (LCDC_HEOCFG33) Vertical Coefficient for phase 0 tap 2 */
#define LCDC_HEOCFG33_YPHI0COEFF2(value) ((LCDC_HEOCFG33_YPHI0COEFF2_Msk & ((value) << LCDC_HEOCFG33_YPHI0COEFF2_Pos)))
/* -------- LCDC_HEOCFG34 : (LCDC Offset: 0x434) High-End Overlay Configuration Register 34 -------- */
#define LCDC_HEOCFG34_YPHI1COEFF0_Pos 0
#define LCDC_HEOCFG34_YPHI1COEFF0_Msk (0xffu << LCDC_HEOCFG34_YPHI1COEFF0_Pos) /**< \brief (LCDC_HEOCFG34) Vertical Coefficient for phase 1 tap 0 */
#define LCDC_HEOCFG34_YPHI1COEFF0(value) ((LCDC_HEOCFG34_YPHI1COEFF0_Msk & ((value) << LCDC_HEOCFG34_YPHI1COEFF0_Pos)))
#define LCDC_HEOCFG34_YPHI1COEFF1_Pos 8
#define LCDC_HEOCFG34_YPHI1COEFF1_Msk (0xffu << LCDC_HEOCFG34_YPHI1COEFF1_Pos) /**< \brief (LCDC_HEOCFG34) Vertical Coefficient for phase 1 tap 1 */
#define LCDC_HEOCFG34_YPHI1COEFF1(value) ((LCDC_HEOCFG34_YPHI1COEFF1_Msk & ((value) << LCDC_HEOCFG34_YPHI1COEFF1_Pos)))
#define LCDC_HEOCFG34_YPHI1COEFF2_Pos 16
#define LCDC_HEOCFG34_YPHI1COEFF2_Msk (0xffu << LCDC_HEOCFG34_YPHI1COEFF2_Pos) /**< \brief (LCDC_HEOCFG34) Vertical Coefficient for phase 1 tap 2 */
#define LCDC_HEOCFG34_YPHI1COEFF2(value) ((LCDC_HEOCFG34_YPHI1COEFF2_Msk & ((value) << LCDC_HEOCFG34_YPHI1COEFF2_Pos)))
/* -------- LCDC_HEOCFG35 : (LCDC Offset: 0x438) High-End Overlay Configuration Register 35 -------- */
#define LCDC_HEOCFG35_YPHI2COEFF0_Pos 0
#define LCDC_HEOCFG35_YPHI2COEFF0_Msk (0xffu << LCDC_HEOCFG35_YPHI2COEFF0_Pos) /**< \brief (LCDC_HEOCFG35) Vertical Coefficient for phase 2 tap 0 */
#define LCDC_HEOCFG35_YPHI2COEFF0(value) ((LCDC_HEOCFG35_YPHI2COEFF0_Msk & ((value) << LCDC_HEOCFG35_YPHI2COEFF0_Pos)))
#define LCDC_HEOCFG35_YPHI2COEFF1_Pos 8
#define LCDC_HEOCFG35_YPHI2COEFF1_Msk (0xffu << LCDC_HEOCFG35_YPHI2COEFF1_Pos) /**< \brief (LCDC_HEOCFG35) Vertical Coefficient for phase 2 tap 1 */
#define LCDC_HEOCFG35_YPHI2COEFF1(value) ((LCDC_HEOCFG35_YPHI2COEFF1_Msk & ((value) << LCDC_HEOCFG35_YPHI2COEFF1_Pos)))
#define LCDC_HEOCFG35_YPHI2COEFF2_Pos 16
#define LCDC_HEOCFG35_YPHI2COEFF2_Msk (0xffu << LCDC_HEOCFG35_YPHI2COEFF2_Pos) /**< \brief (LCDC_HEOCFG35) Vertical Coefficient for phase 2 tap 2 */
#define LCDC_HEOCFG35_YPHI2COEFF2(value) ((LCDC_HEOCFG35_YPHI2COEFF2_Msk & ((value) << LCDC_HEOCFG35_YPHI2COEFF2_Pos)))
/* -------- LCDC_HEOCFG36 : (LCDC Offset: 0x43C) High-End Overlay Configuration Register 36 -------- */
#define LCDC_HEOCFG36_YPHI3COEFF0_Pos 0
#define LCDC_HEOCFG36_YPHI3COEFF0_Msk (0xffu << LCDC_HEOCFG36_YPHI3COEFF0_Pos) /**< \brief (LCDC_HEOCFG36) Vertical Coefficient for phase 3 tap 0 */
#define LCDC_HEOCFG36_YPHI3COEFF0(value) ((LCDC_HEOCFG36_YPHI3COEFF0_Msk & ((value) << LCDC_HEOCFG36_YPHI3COEFF0_Pos)))
#define LCDC_HEOCFG36_YPHI3COEFF1_Pos 8
#define LCDC_HEOCFG36_YPHI3COEFF1_Msk (0xffu << LCDC_HEOCFG36_YPHI3COEFF1_Pos) /**< \brief (LCDC_HEOCFG36) Vertical Coefficient for phase 3 tap 1 */
#define LCDC_HEOCFG36_YPHI3COEFF1(value) ((LCDC_HEOCFG36_YPHI3COEFF1_Msk & ((value) << LCDC_HEOCFG36_YPHI3COEFF1_Pos)))
#define LCDC_HEOCFG36_YPHI3COEFF2_Pos 16
#define LCDC_HEOCFG36_YPHI3COEFF2_Msk (0xffu << LCDC_HEOCFG36_YPHI3COEFF2_Pos) /**< \brief (LCDC_HEOCFG36) Vertical Coefficient for phase 3 tap 2 */
#define LCDC_HEOCFG36_YPHI3COEFF2(value) ((LCDC_HEOCFG36_YPHI3COEFF2_Msk & ((value) << LCDC_HEOCFG36_YPHI3COEFF2_Pos)))
/* -------- LCDC_HEOCFG37 : (LCDC Offset: 0x440) High-End Overlay Configuration Register 37 -------- */
#define LCDC_HEOCFG37_YPHI4COEFF0_Pos 0
#define LCDC_HEOCFG37_YPHI4COEFF0_Msk (0xffu << LCDC_HEOCFG37_YPHI4COEFF0_Pos) /**< \brief (LCDC_HEOCFG37) Vertical Coefficient for phase 4 tap 0 */
#define LCDC_HEOCFG37_YPHI4COEFF0(value) ((LCDC_HEOCFG37_YPHI4COEFF0_Msk & ((value) << LCDC_HEOCFG37_YPHI4COEFF0_Pos)))
#define LCDC_HEOCFG37_YPHI4COEFF1_Pos 8
#define LCDC_HEOCFG37_YPHI4COEFF1_Msk (0xffu << LCDC_HEOCFG37_YPHI4COEFF1_Pos) /**< \brief (LCDC_HEOCFG37) Vertical Coefficient for phase 4 tap 1 */
#define LCDC_HEOCFG37_YPHI4COEFF1(value) ((LCDC_HEOCFG37_YPHI4COEFF1_Msk & ((value) << LCDC_HEOCFG37_YPHI4COEFF1_Pos)))
#define LCDC_HEOCFG37_YPHI4COEFF2_Pos 16
#define LCDC_HEOCFG37_YPHI4COEFF2_Msk (0xffu << LCDC_HEOCFG37_YPHI4COEFF2_Pos) /**< \brief (LCDC_HEOCFG37) Vertical Coefficient for phase 4 tap 2 */
#define LCDC_HEOCFG37_YPHI4COEFF2(value) ((LCDC_HEOCFG37_YPHI4COEFF2_Msk & ((value) << LCDC_HEOCFG37_YPHI4COEFF2_Pos)))
/* -------- LCDC_HEOCFG38 : (LCDC Offset: 0x444) High-End Overlay Configuration Register 38 -------- */
#define LCDC_HEOCFG38_YPHI5COEFF0_Pos 0
#define LCDC_HEOCFG38_YPHI5COEFF0_Msk (0xffu << LCDC_HEOCFG38_YPHI5COEFF0_Pos) /**< \brief (LCDC_HEOCFG38) Vertical Coefficient for phase 5 tap 0 */
#define LCDC_HEOCFG38_YPHI5COEFF0(value) ((LCDC_HEOCFG38_YPHI5COEFF0_Msk & ((value) << LCDC_HEOCFG38_YPHI5COEFF0_Pos)))
#define LCDC_HEOCFG38_YPHI5COEFF1_Pos 8
#define LCDC_HEOCFG38_YPHI5COEFF1_Msk (0xffu << LCDC_HEOCFG38_YPHI5COEFF1_Pos) /**< \brief (LCDC_HEOCFG38) Vertical Coefficient for phase 5 tap 1 */
#define LCDC_HEOCFG38_YPHI5COEFF1(value) ((LCDC_HEOCFG38_YPHI5COEFF1_Msk & ((value) << LCDC_HEOCFG38_YPHI5COEFF1_Pos)))
#define LCDC_HEOCFG38_YPHI5COEFF2_Pos 16
#define LCDC_HEOCFG38_YPHI5COEFF2_Msk (0xffu << LCDC_HEOCFG38_YPHI5COEFF2_Pos) /**< \brief (LCDC_HEOCFG38) Vertical Coefficient for phase 5 tap 2 */
#define LCDC_HEOCFG38_YPHI5COEFF2(value) ((LCDC_HEOCFG38_YPHI5COEFF2_Msk & ((value) << LCDC_HEOCFG38_YPHI5COEFF2_Pos)))
/* -------- LCDC_HEOCFG39 : (LCDC Offset: 0x448) High-End Overlay Configuration Register 39 -------- */
#define LCDC_HEOCFG39_YPHI6COEFF0_Pos 0
#define LCDC_HEOCFG39_YPHI6COEFF0_Msk (0xffu << LCDC_HEOCFG39_YPHI6COEFF0_Pos) /**< \brief (LCDC_HEOCFG39) Vertical Coefficient for phase 6 tap 0 */
#define LCDC_HEOCFG39_YPHI6COEFF0(value) ((LCDC_HEOCFG39_YPHI6COEFF0_Msk & ((value) << LCDC_HEOCFG39_YPHI6COEFF0_Pos)))
#define LCDC_HEOCFG39_YPHI6COEFF1_Pos 8
#define LCDC_HEOCFG39_YPHI6COEFF1_Msk (0xffu << LCDC_HEOCFG39_YPHI6COEFF1_Pos) /**< \brief (LCDC_HEOCFG39) Vertical Coefficient for phase 6 tap 1 */
#define LCDC_HEOCFG39_YPHI6COEFF1(value) ((LCDC_HEOCFG39_YPHI6COEFF1_Msk & ((value) << LCDC_HEOCFG39_YPHI6COEFF1_Pos)))
#define LCDC_HEOCFG39_YPHI6COEFF2_Pos 16
#define LCDC_HEOCFG39_YPHI6COEFF2_Msk (0xffu << LCDC_HEOCFG39_YPHI6COEFF2_Pos) /**< \brief (LCDC_HEOCFG39) Vertical Coefficient for phase 6 tap 2 */
#define LCDC_HEOCFG39_YPHI6COEFF2(value) ((LCDC_HEOCFG39_YPHI6COEFF2_Msk & ((value) << LCDC_HEOCFG39_YPHI6COEFF2_Pos)))
/* -------- LCDC_HEOCFG40 : (LCDC Offset: 0x44C) High-End Overlay Configuration Register 40 -------- */
#define LCDC_HEOCFG40_YPHI7COEFF0_Pos 0
#define LCDC_HEOCFG40_YPHI7COEFF0_Msk (0xffu << LCDC_HEOCFG40_YPHI7COEFF0_Pos) /**< \brief (LCDC_HEOCFG40) Vertical Coefficient for phase 7 tap 0 */
#define LCDC_HEOCFG40_YPHI7COEFF0(value) ((LCDC_HEOCFG40_YPHI7COEFF0_Msk & ((value) << LCDC_HEOCFG40_YPHI7COEFF0_Pos)))
#define LCDC_HEOCFG40_YPHI7COEFF1_Pos 8
#define LCDC_HEOCFG40_YPHI7COEFF1_Msk (0xffu << LCDC_HEOCFG40_YPHI7COEFF1_Pos) /**< \brief (LCDC_HEOCFG40) Vertical Coefficient for phase 7 tap 1 */
#define LCDC_HEOCFG40_YPHI7COEFF1(value) ((LCDC_HEOCFG40_YPHI7COEFF1_Msk & ((value) << LCDC_HEOCFG40_YPHI7COEFF1_Pos)))
#define LCDC_HEOCFG40_YPHI7COEFF2_Pos 16
#define LCDC_HEOCFG40_YPHI7COEFF2_Msk (0xffu << LCDC_HEOCFG40_YPHI7COEFF2_Pos) /**< \brief (LCDC_HEOCFG40) Vertical Coefficient for phase 7 tap 2 */
#define LCDC_HEOCFG40_YPHI7COEFF2(value) ((LCDC_HEOCFG40_YPHI7COEFF2_Msk & ((value) << LCDC_HEOCFG40_YPHI7COEFF2_Pos)))
/* -------- LCDC_HEOCFG41 : (LCDC Offset: 0x450) High-End Overlay Configuration Register 41 -------- */
#define LCDC_HEOCFG41_XPHIDEF_Pos 0
#define LCDC_HEOCFG41_XPHIDEF_Msk (0x7u << LCDC_HEOCFG41_XPHIDEF_Pos) /**< \brief (LCDC_HEOCFG41) Horizontal Filter Phase Offset */
#define LCDC_HEOCFG41_XPHIDEF(value) ((LCDC_HEOCFG41_XPHIDEF_Msk & ((value) << LCDC_HEOCFG41_XPHIDEF_Pos)))
#define LCDC_HEOCFG41_YPHIDEF_Pos 16
#define LCDC_HEOCFG41_YPHIDEF_Msk (0x7u << LCDC_HEOCFG41_YPHIDEF_Pos) /**< \brief (LCDC_HEOCFG41) Vertical Filter Phase Offset */
#define LCDC_HEOCFG41_YPHIDEF(value) ((LCDC_HEOCFG41_YPHIDEF_Msk & ((value) << LCDC_HEOCFG41_YPHIDEF_Pos)))
/* -------- LCDC_BASECLUT[256] : (LCDC Offset: 0x600) Base CLUT Register -------- */
#define LCDC_BASECLUT_BCLUT_Pos 0
#define LCDC_BASECLUT_BCLUT_Msk (0xffu << LCDC_BASECLUT_BCLUT_Pos) /**< \brief (LCDC_BASECLUT[256]) Blue Color Entry */
#define LCDC_BASECLUT_BCLUT(value) ((LCDC_BASECLUT_BCLUT_Msk & ((value) << LCDC_BASECLUT_BCLUT_Pos)))
#define LCDC_BASECLUT_GCLUT_Pos 8
#define LCDC_BASECLUT_GCLUT_Msk (0xffu << LCDC_BASECLUT_GCLUT_Pos) /**< \brief (LCDC_BASECLUT[256]) Green Color Entry */
#define LCDC_BASECLUT_GCLUT(value) ((LCDC_BASECLUT_GCLUT_Msk & ((value) << LCDC_BASECLUT_GCLUT_Pos)))
#define LCDC_BASECLUT_RCLUT_Pos 16
#define LCDC_BASECLUT_RCLUT_Msk (0xffu << LCDC_BASECLUT_RCLUT_Pos) /**< \brief (LCDC_BASECLUT[256]) Red Color Entry */
#define LCDC_BASECLUT_RCLUT(value) ((LCDC_BASECLUT_RCLUT_Msk & ((value) << LCDC_BASECLUT_RCLUT_Pos)))
/* -------- LCDC_OVR1CLUT[256] : (LCDC Offset: 0xA00) Overlay 1 CLUT Register -------- */
#define LCDC_OVR1CLUT_BCLUT_Pos 0
#define LCDC_OVR1CLUT_BCLUT_Msk (0xffu << LCDC_OVR1CLUT_BCLUT_Pos) /**< \brief (LCDC_OVR1CLUT[256]) Blue Color Entry */
#define LCDC_OVR1CLUT_BCLUT(value) ((LCDC_OVR1CLUT_BCLUT_Msk & ((value) << LCDC_OVR1CLUT_BCLUT_Pos)))
#define LCDC_OVR1CLUT_GCLUT_Pos 8
#define LCDC_OVR1CLUT_GCLUT_Msk (0xffu << LCDC_OVR1CLUT_GCLUT_Pos) /**< \brief (LCDC_OVR1CLUT[256]) Green Color Entry */
#define LCDC_OVR1CLUT_GCLUT(value) ((LCDC_OVR1CLUT_GCLUT_Msk & ((value) << LCDC_OVR1CLUT_GCLUT_Pos)))
#define LCDC_OVR1CLUT_RCLUT_Pos 16
#define LCDC_OVR1CLUT_RCLUT_Msk (0xffu << LCDC_OVR1CLUT_RCLUT_Pos) /**< \brief (LCDC_OVR1CLUT[256]) Red Color Entry */
#define LCDC_OVR1CLUT_RCLUT(value) ((LCDC_OVR1CLUT_RCLUT_Msk & ((value) << LCDC_OVR1CLUT_RCLUT_Pos)))
#define LCDC_OVR1CLUT_ACLUT_Pos 24
#define LCDC_OVR1CLUT_ACLUT_Msk (0xffu << LCDC_OVR1CLUT_ACLUT_Pos) /**< \brief (LCDC_OVR1CLUT[256]) Alpha Color Entry */
#define LCDC_OVR1CLUT_ACLUT(value) ((LCDC_OVR1CLUT_ACLUT_Msk & ((value) << LCDC_OVR1CLUT_ACLUT_Pos)))
/* -------- LCDC_OVR2CLUT[256] : (LCDC Offset: 0xE00) Overlay 2 CLUT Register -------- */
#define LCDC_OVR2CLUT_BCLUT_Pos 0
#define LCDC_OVR2CLUT_BCLUT_Msk (0xffu << LCDC_OVR2CLUT_BCLUT_Pos) /**< \brief (LCDC_OVR2CLUT[256]) Blue Color Entry */
#define LCDC_OVR2CLUT_BCLUT(value) ((LCDC_OVR2CLUT_BCLUT_Msk & ((value) << LCDC_OVR2CLUT_BCLUT_Pos)))
#define LCDC_OVR2CLUT_GCLUT_Pos 8
#define LCDC_OVR2CLUT_GCLUT_Msk (0xffu << LCDC_OVR2CLUT_GCLUT_Pos) /**< \brief (LCDC_OVR2CLUT[256]) Green Color Entry */
#define LCDC_OVR2CLUT_GCLUT(value) ((LCDC_OVR2CLUT_GCLUT_Msk & ((value) << LCDC_OVR2CLUT_GCLUT_Pos)))
#define LCDC_OVR2CLUT_RCLUT_Pos 16
#define LCDC_OVR2CLUT_RCLUT_Msk (0xffu << LCDC_OVR2CLUT_RCLUT_Pos) /**< \brief (LCDC_OVR2CLUT[256]) Red Color Entry */
#define LCDC_OVR2CLUT_RCLUT(value) ((LCDC_OVR2CLUT_RCLUT_Msk & ((value) << LCDC_OVR2CLUT_RCLUT_Pos)))
#define LCDC_OVR2CLUT_ACLUT_Pos 24
#define LCDC_OVR2CLUT_ACLUT_Msk (0xffu << LCDC_OVR2CLUT_ACLUT_Pos) /**< \brief (LCDC_OVR2CLUT[256]) Alpha Color Entry */
#define LCDC_OVR2CLUT_ACLUT(value) ((LCDC_OVR2CLUT_ACLUT_Msk & ((value) << LCDC_OVR2CLUT_ACLUT_Pos)))
/* -------- LCDC_HEOCLUT[256] : (LCDC Offset: 0x1200) High-End Overlay CLUT Register -------- */
#define LCDC_HEOCLUT_BCLUT_Pos 0
#define LCDC_HEOCLUT_BCLUT_Msk (0xffu << LCDC_HEOCLUT_BCLUT_Pos) /**< \brief (LCDC_HEOCLUT[256]) Blue Color Entry */
#define LCDC_HEOCLUT_BCLUT(value) ((LCDC_HEOCLUT_BCLUT_Msk & ((value) << LCDC_HEOCLUT_BCLUT_Pos)))
#define LCDC_HEOCLUT_GCLUT_Pos 8
#define LCDC_HEOCLUT_GCLUT_Msk (0xffu << LCDC_HEOCLUT_GCLUT_Pos) /**< \brief (LCDC_HEOCLUT[256]) Green Color Entry */
#define LCDC_HEOCLUT_GCLUT(value) ((LCDC_HEOCLUT_GCLUT_Msk & ((value) << LCDC_HEOCLUT_GCLUT_Pos)))
#define LCDC_HEOCLUT_RCLUT_Pos 16
#define LCDC_HEOCLUT_RCLUT_Msk (0xffu << LCDC_HEOCLUT_RCLUT_Pos) /**< \brief (LCDC_HEOCLUT[256]) Red Color Entry */
#define LCDC_HEOCLUT_RCLUT(value) ((LCDC_HEOCLUT_RCLUT_Msk & ((value) << LCDC_HEOCLUT_RCLUT_Pos)))
#define LCDC_HEOCLUT_ACLUT_Pos 24
#define LCDC_HEOCLUT_ACLUT_Msk (0xffu << LCDC_HEOCLUT_ACLUT_Pos) /**< \brief (LCDC_HEOCLUT[256]) Alpha Color Entry */
#define LCDC_HEOCLUT_ACLUT(value) ((LCDC_HEOCLUT_ACLUT_Msk & ((value) << LCDC_HEOCLUT_ACLUT_Pos)))

/*@}*/


#endif /* _SAM9X_LCDC_COMPONENT_ */
