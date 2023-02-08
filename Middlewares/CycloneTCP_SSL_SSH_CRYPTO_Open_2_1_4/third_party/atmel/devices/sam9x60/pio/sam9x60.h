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

#ifndef _SAM9X60_PIO_
#define _SAM9X60_PIO_

#define PIO_PA0                 (1u << 0)  /**< \brief Pin Controlled by PA0 */
#define PIO_PA1                 (1u << 1)  /**< \brief Pin Controlled by PA1 */
#define PIO_PA2                 (1u << 2)  /**< \brief Pin Controlled by PA2 */
#define PIO_PA3                 (1u << 3)  /**< \brief Pin Controlled by PA3 */
#define PIO_PA4                 (1u << 4)  /**< \brief Pin Controlled by PA4 */
#define PIO_PA5                 (1u << 5)  /**< \brief Pin Controlled by PA5 */
#define PIO_PA6                 (1u << 6)  /**< \brief Pin Controlled by PA6 */
#define PIO_PA7                 (1u << 7)  /**< \brief Pin Controlled by PA7 */
#define PIO_PA8                 (1u << 8)  /**< \brief Pin Controlled by PA8 */
#define PIO_PA9                 (1u << 9)  /**< \brief Pin Controlled by PA9 */
#define PIO_PA10                (1u << 10) /**< \brief Pin Controlled by PA10 */
#define PIO_PA11                (1u << 11) /**< \brief Pin Controlled by PA11 */
#define PIO_PA12                (1u << 12) /**< \brief Pin Controlled by PA12 */
#define PIO_PA13                (1u << 13) /**< \brief Pin Controlled by PA13 */
#define PIO_PA14                (1u << 14) /**< \brief Pin Controlled by PA14 */
#define PIO_PA15                (1u << 15) /**< \brief Pin Controlled by PA15 */
#define PIO_PA16                (1u << 16) /**< \brief Pin Controlled by PA16 */
#define PIO_PA17                (1u << 17) /**< \brief Pin Controlled by PA17 */
#define PIO_PA18                (1u << 18) /**< \brief Pin Controlled by PA18 */
#define PIO_PA19                (1u << 19) /**< \brief Pin Controlled by PA19 */
#define PIO_PA20                (1u << 20) /**< \brief Pin Controlled by PA20 */
#define PIO_PA21                (1u << 21) /**< \brief Pin Controlled by PA21 */
#define PIO_PA22                (1u << 22) /**< \brief Pin Controlled by PA22 */
#define PIO_PA23                (1u << 23) /**< \brief Pin Controlled by PA23 */
#define PIO_PA24                (1u << 24) /**< \brief Pin Controlled by PA24 */
#define PIO_PA25                (1u << 25) /**< \brief Pin Controlled by PA25 */
#define PIO_PA26                (1u << 26) /**< \brief Pin Controlled by PA26 */
#define PIO_PA27                (1u << 27) /**< \brief Pin Controlled by PA27 */
#define PIO_PA28                (1u << 28) /**< \brief Pin Controlled by PA28 */
#define PIO_PA29                (1u << 29) /**< \brief Pin Controlled by PA29 */
#define PIO_PA30                (1u << 30) /**< \brief Pin Controlled by PA30 */
#define PIO_PA31                (1u << 31) /**< \brief Pin Controlled by PA31 */
#define PIO_PB0                 (1u << 0)  /**< \brief Pin Controlled by PB0 */
#define PIO_PB1                 (1u << 1)  /**< \brief Pin Controlled by PB1 */
#define PIO_PB2                 (1u << 2)  /**< \brief Pin Controlled by PB2 */
#define PIO_PB3                 (1u << 3)  /**< \brief Pin Controlled by PB3 */
#define PIO_PB4                 (1u << 4)  /**< \brief Pin Controlled by PB4 */
#define PIO_PB5                 (1u << 5)  /**< \brief Pin Controlled by PB5 */
#define PIO_PB6                 (1u << 6)  /**< \brief Pin Controlled by PB6 */
#define PIO_PB7                 (1u << 7)  /**< \brief Pin Controlled by PB7 */
#define PIO_PB8                 (1u << 8)  /**< \brief Pin Controlled by PB8 */
#define PIO_PB9                 (1u << 9)  /**< \brief Pin Controlled by PB9 */
#define PIO_PB10                (1u << 10) /**< \brief Pin Controlled by PB10 */
#define PIO_PB11                (1u << 11) /**< \brief Pin Controlled by PB11 */
#define PIO_PB12                (1u << 12) /**< \brief Pin Controlled by PB12 */
#define PIO_PB13                (1u << 13) /**< \brief Pin Controlled by PB13 */
#define PIO_PB14                (1u << 14) /**< \brief Pin Controlled by PB14 */
#define PIO_PB15                (1u << 15) /**< \brief Pin Controlled by PB15 */
#define PIO_PB16                (1u << 16) /**< \brief Pin Controlled by PB16 */
#define PIO_PB17                (1u << 17) /**< \brief Pin Controlled by PB17 */
#define PIO_PB18                (1u << 18) /**< \brief Pin Controlled by PB18 */
#define PIO_PB19                (1u << 19) /**< \brief Pin Controlled by PB19 */
#define PIO_PB20                (1u << 20) /**< \brief Pin Controlled by PB20 */
#define PIO_PB21                (1u << 21) /**< \brief Pin Controlled by PB21 */
#define PIO_PB22                (1u << 22) /**< \brief Pin Controlled by PB22 */
#define PIO_PB23                (1u << 23) /**< \brief Pin Controlled by PB23 */
#define PIO_PB24                (1u << 24) /**< \brief Pin Controlled by PB24 */
#define PIO_PB25                (1u << 25) /**< \brief Pin Controlled by PB25 */
#define PIO_PC0                 (1u << 0)  /**< \brief Pin Controlled by PC0 */
#define PIO_PC1                 (1u << 1)  /**< \brief Pin Controlled by PC1 */
#define PIO_PC2                 (1u << 2)  /**< \brief Pin Controlled by PC2 */
#define PIO_PC3                 (1u << 3)  /**< \brief Pin Controlled by PC3 */
#define PIO_PC4                 (1u << 4)  /**< \brief Pin Controlled by PC4 */
#define PIO_PC5                 (1u << 5)  /**< \brief Pin Controlled by PC5 */
#define PIO_PC6                 (1u << 6)  /**< \brief Pin Controlled by PC6 */
#define PIO_PC7                 (1u << 7)  /**< \brief Pin Controlled by PC7 */
#define PIO_PC8                 (1u << 8)  /**< \brief Pin Controlled by PC8 */
#define PIO_PC9                 (1u << 9)  /**< \brief Pin Controlled by PC9 */
#define PIO_PC10                (1u << 10) /**< \brief Pin Controlled by PC10 */
#define PIO_PC11                (1u << 11) /**< \brief Pin Controlled by PC11 */
#define PIO_PC12                (1u << 12) /**< \brief Pin Controlled by PC12 */
#define PIO_PC13                (1u << 13) /**< \brief Pin Controlled by PC13 */
#define PIO_PC14                (1u << 14) /**< \brief Pin Controlled by PC14 */
#define PIO_PC15                (1u << 15) /**< \brief Pin Controlled by PC15 */
#define PIO_PC16                (1u << 16) /**< \brief Pin Controlled by PC16 */
#define PIO_PC17                (1u << 17) /**< \brief Pin Controlled by PC17 */
#define PIO_PC18                (1u << 18) /**< \brief Pin Controlled by PC18 */
#define PIO_PC19                (1u << 19) /**< \brief Pin Controlled by PC19 */
#define PIO_PC20                (1u << 20) /**< \brief Pin Controlled by PC20 */
#define PIO_PC21                (1u << 21) /**< \brief Pin Controlled by PC21 */
#define PIO_PC22                (1u << 22) /**< \brief Pin Controlled by PC22 */
#define PIO_PC23                (1u << 23) /**< \brief Pin Controlled by PC23 */
#define PIO_PC24                (1u << 24) /**< \brief Pin Controlled by PC24 */
#define PIO_PC25                (1u << 25) /**< \brief Pin Controlled by PC25 */
#define PIO_PC26                (1u << 26) /**< \brief Pin Controlled by PC26 */
#define PIO_PC27                (1u << 27) /**< \brief Pin Controlled by PC27 */
#define PIO_PC28                (1u << 28) /**< \brief Pin Controlled by PC28 */
#define PIO_PC29                (1u << 29) /**< \brief Pin Controlled by PC29 */
#define PIO_PC30                (1u << 30) /**< \brief Pin Controlled by PC30 */
#define PIO_PC31                (1u << 31) /**< \brief Pin Controlled by PC31 */
#define PIO_PD0                 (1u << 0)  /**< \brief Pin Controlled by PD0 */
#define PIO_PD1                 (1u << 1)  /**< \brief Pin Controlled by PD1 */
#define PIO_PD2                 (1u << 2)  /**< \brief Pin Controlled by PD2 */
#define PIO_PD3                 (1u << 3)  /**< \brief Pin Controlled by PD3 */
#define PIO_PD4                 (1u << 4)  /**< \brief Pin Controlled by PD4 */
#define PIO_PD5                 (1u << 5)  /**< \brief Pin Controlled by PD5 */
#define PIO_PD6                 (1u << 6)  /**< \brief Pin Controlled by PD6 */
#define PIO_PD7                 (1u << 7)  /**< \brief Pin Controlled by PD7 */
#define PIO_PD8                 (1u << 8)  /**< \brief Pin Controlled by PD8 */
#define PIO_PD9                 (1u << 9)  /**< \brief Pin Controlled by PD9 */
#define PIO_PD10                (1u << 10) /**< \brief Pin Controlled by PD10 */
#define PIO_PD11                (1u << 11) /**< \brief Pin Controlled by PD11 */
#define PIO_PD12                (1u << 12) /**< \brief Pin Controlled by PD12 */
#define PIO_PD13                (1u << 13) /**< \brief Pin Controlled by PD13 */
#define PIO_PD14                (1u << 14) /**< \brief Pin Controlled by PD14 */
#define PIO_PD15                (1u << 15) /**< \brief Pin Controlled by PD15 */
#define PIO_PD16                (1u << 16) /**< \brief Pin Controlled by PD16 */
#define PIO_PD17                (1u << 17) /**< \brief Pin Controlled by PD17 */
#define PIO_PD18                (1u << 18) /**< \brief Pin Controlled by PD18 */
#define PIO_PD19                (1u << 19) /**< \brief Pin Controlled by PD19 */
#define PIO_PD20                (1u << 20) /**< \brief Pin Controlled by PD20 */
#define PIO_PD21                (1u << 21) /**< \brief Pin Controlled by PD21 */
/* ========== Pio definition for ADC peripheral ========== */
#define PIO_PB11X1_AD0          (1u << 11) /**< \brief Adc signal: AD0 */
#define PIO_PB12X1_AD1          (1u << 12) /**< \brief Adc signal: AD1 */
#define PIO_PB9X1_AD10          (1u << 9)  /**< \brief Adc signal: AD10 */
#define PIO_PB10X1_AD11         (1u << 10) /**< \brief Adc signal: AD11 */
#define PIO_PB13X1_AD2          (1u << 13) /**< \brief Adc signal: AD2 */
#define PIO_PB14X1_AD3          (1u << 14) /**< \brief Adc signal: AD3 */
#define PIO_PB15X1_AD4          (1u << 15) /**< \brief Adc signal: AD4 */
#define PIO_PB16X1_AD5          (1u << 16) /**< \brief Adc signal: AD5 */
#define PIO_PB17X1_AD6          (1u << 17) /**< \brief Adc signal: AD6 */
#define PIO_PB6X1_AD7           (1u << 6)  /**< \brief Adc signal: AD7 */
#define PIO_PB7X1_AD8           (1u << 7)  /**< \brief Adc signal: AD8 */
#define PIO_PB8X1_AD9           (1u << 8)  /**< \brief Adc signal: AD9 */
#define PIO_PB18B_ADTRG         (1u << 18) /**< \brief Adc signal: ADTRG */
/* ========== Pio definition for AIC peripheral ========== */
#define PIO_PC31A_FIQ           (1u << 31) /**< \brief Aic signal: FIQ */
#define PIO_PB18A_IRQ           (1u << 18) /**< \brief Aic signal: IRQ */
/* ========== Pio definition for ARM peripheral ========== */
#define PIO_PB25B_NTRST         (1u << 25) /**< \brief Arm signal: NTRST */
/* ========== Pio definition for CAN0 peripheral ========== */
#define PIO_PA9B_CANRX0         (1u << 9)  /**< \brief Can0 signal: CANRX0 */
#define PIO_PA10B_CANTX0        (1u << 10) /**< \brief Can0 signal: CANTX0 */
/* ========== Pio definition for CAN1 peripheral ========== */
#define PIO_PA6B_CANRX1         (1u << 6)  /**< \brief Can1 signal: CANRX1 */
#define PIO_PA5B_CANTX1         (1u << 5)  /**< \brief Can1 signal: CANTX1 */
/* ========== Pio definition for CLASSD peripheral ========== */
#define PIO_PA24C_CLASSD_L0     (1u << 24) /**< \brief Classd signal: CLASSD_L0 */
#define PIO_PA25C_CLASSD_L1     (1u << 25) /**< \brief Classd signal: CLASSD_L1 */
#define PIO_PA26C_CLASSD_L2     (1u << 26) /**< \brief Classd signal: CLASSD_L2 */
#define PIO_PA27C_CLASSD_L3     (1u << 27) /**< \brief Classd signal: CLASSD_L3 */
/* ========== Pio definition for DBGU peripheral ========== */
#define PIO_PA9A_DRXD           (1u << 9)  /**< \brief Dbgu signal: DRXD */
#define PIO_PA10A_DTXD          (1u << 10) /**< \brief Dbgu signal: DTXD */
/* ========== Pio definition for EBI peripheral ========== */
#define PIO_PD15B_A20           (1u << 15) /**< \brief Ebi signal: A20 */
#define PIO_PD2A_A21            (1u << 2)  /**< \brief Ebi signal: A21/NANDALE */
#define PIO_PD2A_NANDALE        (1u << 2)  /**< \brief Ebi signal: A21/NANDALE */
#define PIO_PD3A_A22            (1u << 3)  /**< \brief Ebi signal: A22/NANDCLE */
#define PIO_PD3A_NANDCLE        (1u << 3)  /**< \brief Ebi signal: A22/NANDCLE */
#define PIO_PD16B_A23           (1u << 16) /**< \brief Ebi signal: A23 */
#define PIO_PD17B_A24           (1u << 17) /**< \brief Ebi signal: A24 */
#define PIO_PD18B_A25           (1u << 18) /**< \brief Ebi signal: A25 */
#define PIO_PD6A_D16            (1u << 6)  /**< \brief Ebi signal: D16 */
#define PIO_PD7A_D17            (1u << 7)  /**< \brief Ebi signal: D17 */
#define PIO_PD8A_D18            (1u << 8)  /**< \brief Ebi signal: D18 */
#define PIO_PD9A_D19            (1u << 9)  /**< \brief Ebi signal: D19 */
#define PIO_PD10A_D20           (1u << 10) /**< \brief Ebi signal: D20 */
#define PIO_PD11A_D21           (1u << 11) /**< \brief Ebi signal: D21 */
#define PIO_PD12A_D22           (1u << 12) /**< \brief Ebi signal: D22 */
#define PIO_PD13A_D23           (1u << 13) /**< \brief Ebi signal: D23 */
#define PIO_PD14A_D24           (1u << 14) /**< \brief Ebi signal: D24 */
#define PIO_PD15A_D25           (1u << 15) /**< \brief Ebi signal: D25 */
#define PIO_PD16A_D26           (1u << 16) /**< \brief Ebi signal: D26 */
#define PIO_PD17A_D27           (1u << 17) /**< \brief Ebi signal: D27 */
#define PIO_PD18A_D28           (1u << 18) /**< \brief Ebi signal: D28 */
#define PIO_PD19A_D29           (1u << 19) /**< \brief Ebi signal: D29 */
#define PIO_PD20A_D30           (1u << 20) /**< \brief Ebi signal: D30 */
#define PIO_PD21A_D31           (1u << 21) /**< \brief Ebi signal: D31 */
#define PIO_PD0A_NANDOE         (1u << 0)  /**< \brief Ebi signal: NANDOE */
#define PIO_PD1A_NANDWE         (1u << 1)  /**< \brief Ebi signal: NANDWE */
#define PIO_PD19B_NCS2          (1u << 19) /**< \brief Ebi signal: NCS2 */
#define PIO_PD4A_NCS3           (1u << 4)  /**< \brief Ebi signal: NCS3/NANDCS */
#define PIO_PD4A_NANDCS         (1u << 4)  /**< \brief Ebi signal: NCS3/NANDCS */
#define PIO_PD20B_NCS4          (1u << 20) /**< \brief Ebi signal: NCS4 */
#define PIO_PD21B_NCS5          (1u << 21) /**< \brief Ebi signal: NCS5 */
#define PIO_PD5A_NWAIT          (1u << 5)  /**< \brief Ebi signal: NWAIT */
/* ========== Pio definition for EMAC0 peripheral ========== */
#define PIO_PB17A_E0_COL        (1u << 17) /**< \brief Emac0 signal: E0_COL */
#define PIO_PB16A_E0_CRS        (1u << 16) /**< \brief Emac0 signal: E0_CRS */
#define PIO_PA30C_E0_MDC        (1u << 30) /**< \brief Emac0 signal: E0_MDC */
#define PIO_PB6A_E0_MDC         (1u << 6)  /**< \brief Emac0 signal: E0_MDC */
#define PIO_PB5A_E0_MDIO        (1u << 5)  /**< \brief Emac0 signal: E0_MDIO */
#define PIO_PB0A_E0_RX0         (1u << 0)  /**< \brief Emac0 signal: E0_RX0 */
#define PIO_PB1A_E0_RX1         (1u << 1)  /**< \brief Emac0 signal: E0_RX1 */
#define PIO_PB13A_E0_RX2        (1u << 13) /**< \brief Emac0 signal: E0_RX2 */
#define PIO_PB14A_E0_RX3        (1u << 14) /**< \brief Emac0 signal: E0_RX3 */
#define PIO_PB15A_E0_RXCK       (1u << 15) /**< \brief Emac0 signal: E0_RXCK */
#define PIO_PB3A_E0_RXDV        (1u << 3)  /**< \brief Emac0 signal: E0_RXDV */
#define PIO_PB2A_E0_RXER        (1u << 2)  /**< \brief Emac0 signal: E0_RXER */
#define PIO_PA2C_E0_TX0         (1u << 2)  /**< \brief Emac0 signal: E0_TX0 */
#define PIO_PB9A_E0_TX0         (1u << 9)  /**< \brief Emac0 signal: E0_TX0 */
#define PIO_PA3C_E0_TX1         (1u << 3)  /**< \brief Emac0 signal: E0_TX1 */
#define PIO_PB10A_E0_TX1        (1u << 10) /**< \brief Emac0 signal: E0_TX1 */
#define PIO_PB11A_E0_TX2        (1u << 11) /**< \brief Emac0 signal: E0_TX2 */
#define PIO_PB12A_E0_TX3        (1u << 12) /**< \brief Emac0 signal: E0_TX3 */
#define PIO_PB4A_E0_TXCK        (1u << 4)  /**< \brief Emac0 signal: E0_TXCK */
#define PIO_PA31C_E0_TXEN       (1u << 31) /**< \brief Emac0 signal: E0_TXEN */
#define PIO_PB7A_E0_TXEN        (1u << 7)  /**< \brief Emac0 signal: E0_TXEN */
#define PIO_PA4C_E0_TXER        (1u << 4)  /**< \brief Emac0 signal: E0_TXER */
#define PIO_PB8A_E0_TXER        (1u << 8)  /**< \brief Emac0 signal: E0_TXER */
/* ========== Pio definition for EMAC1 peripheral ========== */
#define PIO_PC28B_E1_CRSDV      (1u << 28) /**< \brief Emac1 signal: E1_CRSDV */
#define PIO_PC30B_E1_MDC        (1u << 30) /**< \brief Emac1 signal: E1_MDC */
#define PIO_PC31B_E1_MDIO       (1u << 31) /**< \brief Emac1 signal: E1_MDIO */
#define PIO_PC20B_E1_RX0        (1u << 20) /**< \brief Emac1 signal: E1_RX0 */
#define PIO_PC21B_E1_RX1        (1u << 21) /**< \brief Emac1 signal: E1_RX1 */
#define PIO_PC16B_E1_RXER       (1u << 16) /**< \brief Emac1 signal: E1_RXER */
#define PIO_PC18B_E1_TX0        (1u << 18) /**< \brief Emac1 signal: E1_TX0 */
#define PIO_PC19B_E1_TX1        (1u << 19) /**< \brief Emac1 signal: E1_TX1 */
#define PIO_PC29B_E1_TXCK       (1u << 29) /**< \brief Emac1 signal: E1_TXCK */
#define PIO_PC27B_E1_TXEN       (1u << 27) /**< \brief Emac1 signal: E1_TXEN */
/* ========== Pio definition for FLEXCOM0 peripheral ========== */
#define PIO_PA0A_FLEXCOM0_IO0   (1u << 0)  /**< \brief Flexcom0 signal: FLEXCOM0_IO0 */
#define PIO_PA1A_FLEXCOM0_IO1   (1u << 1)  /**< \brief Flexcom0 signal: FLEXCOM0_IO1 */
#define PIO_PA4A_FLEXCOM0_IO2   (1u << 4)  /**< \brief Flexcom0 signal: FLEXCOM0_IO2 */
#define PIO_PA3A_FLEXCOM0_IO3   (1u << 3)  /**< \brief Flexcom0 signal: FLEXCOM0_IO3 */
#define PIO_PA2A_FLEXCOM0_IO4   (1u << 2)  /**< \brief Flexcom0 signal: FLEXCOM0_IO4 */
#define PIO_PB6B_FLEXCOM0_IO7   (1u << 6)  /**< \brief Flexcom0 signal: FLEXCOM0_IO7 */
/* ========== Pio definition for FLEXCOM1 peripheral ========== */
#define PIO_PA5A_FLEXCOM1_IO0   (1u << 5)  /**< \brief Flexcom1 signal: FLEXCOM1_IO0 */
#define PIO_PA6A_FLEXCOM1_IO1   (1u << 6)  /**< \brief Flexcom1 signal: FLEXCOM1_IO1 */
#define PIO_PC29C_FLEXCOM1_IO2  (1u << 29) /**< \brief Flexcom1 signal: FLEXCOM1_IO2 */
#define PIO_PC28C_FLEXCOM1_IO3  (1u << 28) /**< \brief Flexcom1 signal: FLEXCOM1_IO3 */
#define PIO_PC27C_FLEXCOM1_IO4  (1u << 27) /**< \brief Flexcom1 signal: FLEXCOM1_IO4 */
#define PIO_PC17B_FLEXCOM1_IO7  (1u << 17) /**< \brief Flexcom1 signal: FLEXCOM1_IO7 */
/* ========== Pio definition for FLEXCOM10 peripheral ========== */
#define PIO_PC16C_FLEXCOM10_IO0 (1u << 16) /**< \brief Flexcom10 signal: FLEXCOM10_IO0 */
#define PIO_PC17C_FLEXCOM10_IO1 (1u << 17) /**< \brief Flexcom10 signal: FLEXCOM10_IO1 */
/* ========== Pio definition for FLEXCOM11 peripheral ========== */
#define PIO_PB19C_FLEXCOM11_IO0 (1u << 19) /**< \brief Flexcom11 signal: FLEXCOM11_IO0 */
#define PIO_PB20C_FLEXCOM11_IO1 (1u << 20) /**< \brief Flexcom11 signal: FLEXCOM11_IO1 */
/* ========== Pio definition for FLEXCOM12 peripheral ========== */
#define PIO_PB21C_FLEXCOM12_IO0 (1u << 21) /**< \brief Flexcom12 signal: FLEXCOM12_IO0 */
#define PIO_PB22C_FLEXCOM12_IO1 (1u << 22) /**< \brief Flexcom12 signal: FLEXCOM12_IO1 */
/* ========== Pio definition for FLEXCOM2 peripheral ========== */
#define PIO_PA7A_FLEXCOM2_IO0   (1u << 7)  /**< \brief Flexcom2 signal: FLEXCOM2_IO0 */
#define PIO_PA8A_FLEXCOM2_IO1   (1u << 8)  /**< \brief Flexcom2 signal: FLEXCOM2_IO1 */
#define PIO_PB2B_FLEXCOM2_IO2   (1u << 2)  /**< \brief Flexcom2 signal: FLEXCOM2_IO2 */
#define PIO_PB1B_FLEXCOM2_IO3   (1u << 1)  /**< \brief Flexcom2 signal: FLEXCOM2_IO3 */
#define PIO_PB0B_FLEXCOM2_IO4   (1u << 0)  /**< \brief Flexcom2 signal: FLEXCOM2_IO4 */
#define PIO_PA29C_FLEXCOM2_IO7  (1u << 29) /**< \brief Flexcom2 signal: FLEXCOM2_IO7 */
/* ========== Pio definition for FLEXCOM3 peripheral ========== */
#define PIO_PC22B_FLEXCOM3_IO0  (1u << 22) /**< \brief Flexcom3 signal: FLEXCOM3_IO0 */
#define PIO_PC23B_FLEXCOM3_IO1  (1u << 23) /**< \brief Flexcom3 signal: FLEXCOM3_IO1 */
#define PIO_PC26B_FLEXCOM3_IO2  (1u << 26) /**< \brief Flexcom3 signal: FLEXCOM3_IO2 */
#define PIO_PC25B_FLEXCOM3_IO3  (1u << 25) /**< \brief Flexcom3 signal: FLEXCOM3_IO3 */
#define PIO_PC24B_FLEXCOM3_IO4  (1u << 24) /**< \brief Flexcom3 signal: FLEXCOM3_IO4 */
#define PIO_PC30C_FLEXCOM3_IO7  (1u << 30) /**< \brief Flexcom3 signal: FLEXCOM3_IO7 */
/* ========== Pio definition for FLEXCOM4 peripheral ========== */
#define PIO_PA12A_FLEXCOM4_IO0  (1u << 12) /**< \brief Flexcom4 signal: FLEXCOM4_IO0 */
#define PIO_PA11A_FLEXCOM4_IO1  (1u << 11) /**< \brief Flexcom4 signal: FLEXCOM4_IO1 */
#define PIO_PA13A_FLEXCOM4_IO2  (1u << 13) /**< \brief Flexcom4 signal: FLEXCOM4_IO2 */
#define PIO_PA14A_FLEXCOM4_IO3  (1u << 14) /**< \brief Flexcom4 signal: FLEXCOM4_IO3 */
#define PIO_PA0C_FLEXCOM4_IO4   (1u << 0)  /**< \brief Flexcom4 signal: FLEXCOM4_IO4 */
#define PIO_PA7B_FLEXCOM4_IO4   (1u << 7)  /**< \brief Flexcom4 signal: FLEXCOM4_IO4 */
#define PIO_PA1B_FLEXCOM4_IO5   (1u << 1)  /**< \brief Flexcom4 signal: FLEXCOM4_IO5 */
#define PIO_PA8C_FLEXCOM4_IO5   (1u << 8)  /**< \brief Flexcom4 signal: FLEXCOM4_IO5 */
#define PIO_PB3B_FLEXCOM4_IO6   (1u << 3)  /**< \brief Flexcom4 signal: FLEXCOM4_IO6 */
/* ========== Pio definition for FLEXCOM5 peripheral ========== */
#define PIO_PA22B_FLEXCOM5_IO0  (1u << 22) /**< \brief Flexcom5 signal: FLEXCOM5_IO0 */
#define PIO_PA21B_FLEXCOM5_IO1  (1u << 21) /**< \brief Flexcom5 signal: FLEXCOM5_IO1 */
#define PIO_PA23B_FLEXCOM5_IO2  (1u << 23) /**< \brief Flexcom5 signal: FLEXCOM5_IO2 */
#define PIO_PA8B_FLEXCOM5_IO3   (1u << 8)  /**< \brief Flexcom5 signal: FLEXCOM5_IO3 */
#define PIO_PA0B_FLEXCOM5_IO4   (1u << 0)  /**< \brief Flexcom5 signal: FLEXCOM5_IO4 */
#define PIO_PA7C_FLEXCOM5_IO4   (1u << 7)  /**< \brief Flexcom5 signal: FLEXCOM5_IO4 */
#define PIO_PA31B_FLEXCOM5_IO5  (1u << 31) /**< \brief Flexcom5 signal: FLEXCOM5_IO5 */
#define PIO_PA30B_FLEXCOM5_IO6  (1u << 30) /**< \brief Flexcom5 signal: FLEXCOM5_IO6 */
/* ========== Pio definition for FLEXCOM6 peripheral ========== */
#define PIO_PA30A_FLEXCOM6_IO0  (1u << 30) /**< \brief Flexcom6 signal: FLEXCOM6_IO0 */
#define PIO_PA31A_FLEXCOM6_IO1  (1u << 31) /**< \brief Flexcom6 signal: FLEXCOM6_IO1 */
/* ========== Pio definition for FLEXCOM7 peripheral ========== */
#define PIO_PC0C_FLEXCOM7_IO0   (1u << 0)  /**< \brief Flexcom7 signal: FLEXCOM7_IO0 */
#define PIO_PC1C_FLEXCOM7_IO1   (1u << 1)  /**< \brief Flexcom7 signal: FLEXCOM7_IO1 */
/* ========== Pio definition for FLEXCOM8 peripheral ========== */
#define PIO_PB4B_FLEXCOM8_IO0   (1u << 4)  /**< \brief Flexcom8 signal: FLEXCOM8_IO0 */
#define PIO_PB5B_FLEXCOM8_IO1   (1u << 5)  /**< \brief Flexcom8 signal: FLEXCOM8_IO1 */
/* ========== Pio definition for FLEXCOM9 peripheral ========== */
#define PIO_PC8C_FLEXCOM9_IO0   (1u << 8)  /**< \brief Flexcom9 signal: FLEXCOM9_IO0 */
#define PIO_PC9C_FLEXCOM9_IO1   (1u << 9)  /**< \brief Flexcom9 signal: FLEXCOM9_IO1 */
/* ========== Pio definition for I2SMCC peripheral ========== */
#define PIO_PB19B_I2SMCC_CK     (1u << 19) /**< \brief I2smcc signal: I2SMCC_CK */
#define PIO_PB21B_I2SMCC_DIN0   (1u << 21) /**< \brief I2smcc signal: I2SMCC_DIN0 */
#define PIO_PB22B_I2SMCC_DOUT0  (1u << 22) /**< \brief I2smcc signal: I2SMCC_DOUT0 */
#define PIO_PB23B_I2SMCC_MCK    (1u << 23) /**< \brief I2smcc signal: I2SMCC_MCK */
#define PIO_PB20B_I2SMCC_WS     (1u << 20) /**< \brief I2smcc signal: I2SMCC_WS */
/* ========== Pio definition for ISI peripheral ========== */
#define PIO_PC0B_ISI_D0         (1u << 0)  /**< \brief Isi signal: ISI_D0 */
#define PIO_PC1B_ISI_D1         (1u << 1)  /**< \brief Isi signal: ISI_D1 */
#define PIO_PC10B_ISI_D10       (1u << 10) /**< \brief Isi signal: ISI_D10 */
#define PIO_PC11B_ISI_D11       (1u << 11) /**< \brief Isi signal: ISI_D11 */
#define PIO_PC2B_ISI_D2         (1u << 2)  /**< \brief Isi signal: ISI_D2 */
#define PIO_PC3B_ISI_D3         (1u << 3)  /**< \brief Isi signal: ISI_D3 */
#define PIO_PC4B_ISI_D4         (1u << 4)  /**< \brief Isi signal: ISI_D4 */
#define PIO_PC5B_ISI_D5         (1u << 5)  /**< \brief Isi signal: ISI_D5 */
#define PIO_PC6B_ISI_D6         (1u << 6)  /**< \brief Isi signal: ISI_D6 */
#define PIO_PC7B_ISI_D7         (1u << 7)  /**< \brief Isi signal: ISI_D7 */
#define PIO_PC8B_ISI_D8         (1u << 8)  /**< \brief Isi signal: ISI_D8 */
#define PIO_PC9B_ISI_D9         (1u << 9)  /**< \brief Isi signal: ISI_D9 */
#define PIO_PC14B_ISI_HSYNC     (1u << 14) /**< \brief Isi signal: ISI_HSYNC */
#define PIO_PC15B_ISI_MCK       (1u << 15) /**< \brief Isi signal: ISI_MCK */
#define PIO_PC12B_ISI_PCK       (1u << 12) /**< \brief Isi signal: ISI_PCK */
#define PIO_PC13B_ISI_VSYNC     (1u << 13) /**< \brief Isi signal: ISI_VSYNC */
/* ========== Pio definition for LCDC peripheral ========== */
#define PIO_PC0A_LCDDAT0        (1u << 0)  /**< \brief Lcdc signal: LCDDAT0 */
#define PIO_PC1A_LCDDAT1        (1u << 1)  /**< \brief Lcdc signal: LCDDAT1 */
#define PIO_PC10A_LCDDAT10      (1u << 10) /**< \brief Lcdc signal: LCDDAT10 */
#define PIO_PC11A_LCDDAT11      (1u << 11) /**< \brief Lcdc signal: LCDDAT11 */
#define PIO_PC12A_LCDDAT12      (1u << 12) /**< \brief Lcdc signal: LCDDAT12 */
#define PIO_PC13A_LCDDAT13      (1u << 13) /**< \brief Lcdc signal: LCDDAT13 */
#define PIO_PC14A_LCDDAT14      (1u << 14) /**< \brief Lcdc signal: LCDDAT14 */
#define PIO_PC15A_LCDDAT15      (1u << 15) /**< \brief Lcdc signal: LCDDAT15 */
#define PIO_PC16A_LCDDAT16      (1u << 16) /**< \brief Lcdc signal: LCDDAT16 */
#define PIO_PC17A_LCDDAT17      (1u << 17) /**< \brief Lcdc signal: LCDDAT17 */
#define PIO_PC18A_LCDDAT18      (1u << 18) /**< \brief Lcdc signal: LCDDAT18 */
#define PIO_PC19A_LCDDAT19      (1u << 19) /**< \brief Lcdc signal: LCDDAT19 */
#define PIO_PC2A_LCDDAT2        (1u << 2)  /**< \brief Lcdc signal: LCDDAT2 */
#define PIO_PC20A_LCDDAT20      (1u << 20) /**< \brief Lcdc signal: LCDDAT20 */
#define PIO_PC21A_LCDDAT21      (1u << 21) /**< \brief Lcdc signal: LCDDAT21 */
#define PIO_PC22A_LCDDAT22      (1u << 22) /**< \brief Lcdc signal: LCDDAT22 */
#define PIO_PC23A_LCDDAT23      (1u << 23) /**< \brief Lcdc signal: LCDDAT23 */
#define PIO_PC3A_LCDDAT3        (1u << 3)  /**< \brief Lcdc signal: LCDDAT3 */
#define PIO_PC4A_LCDDAT4        (1u << 4)  /**< \brief Lcdc signal: LCDDAT4 */
#define PIO_PC5A_LCDDAT5        (1u << 5)  /**< \brief Lcdc signal: LCDDAT5 */
#define PIO_PC6A_LCDDAT6        (1u << 6)  /**< \brief Lcdc signal: LCDDAT6 */
#define PIO_PC7A_LCDDAT7        (1u << 7)  /**< \brief Lcdc signal: LCDDAT7 */
#define PIO_PC8A_LCDDAT8        (1u << 8)  /**< \brief Lcdc signal: LCDDAT8 */
#define PIO_PC9A_LCDDAT9        (1u << 9)  /**< \brief Lcdc signal: LCDDAT9 */
#define PIO_PC29A_LCDDEN        (1u << 29) /**< \brief Lcdc signal: LCDDEN */
#define PIO_PC24A_LCDDISP       (1u << 24) /**< \brief Lcdc signal: LCDDISP */
#define PIO_PC28A_LCDHSYNC      (1u << 28) /**< \brief Lcdc signal: LCDHSYNC */
#define PIO_PC30A_LCDPCK        (1u << 30) /**< \brief Lcdc signal: LCDPCK */
#define PIO_PC26A_LCDPWM        (1u << 26) /**< \brief Lcdc signal: LCDPWM */
#define PIO_PC27A_LCDVSYNC      (1u << 27) /**< \brief Lcdc signal: LCDVSYNC */
/* ========== Pio definition for PMC peripheral ========== */
#define PIO_PB10B_PCK0          (1u << 10) /**< \brief Pmc signal: PCK0 */
#define PIO_PC15C_PCK0          (1u << 15) /**< \brief Pmc signal: PCK0 */
#define PIO_PB9B_PCK1           (1u << 9)  /**< \brief Pmc signal: PCK1 */
#define PIO_PC31C_PCK1          (1u << 31) /**< \brief Pmc signal: PCK1 */
/* ========== Pio definition for PWM peripheral ========== */
#define PIO_PB11B_PWM0          (1u << 11) /**< \brief Pwm signal: PWM0 */
#define PIO_PC10C_PWM0          (1u << 10) /**< \brief Pwm signal: PWM0 */
#define PIO_PC18C_PWM0          (1u << 18) /**< \brief Pwm signal: PWM0 */
#define PIO_PB12B_PWM1          (1u << 12) /**< \brief Pwm signal: PWM1 */
#define PIO_PC11C_PWM1          (1u << 11) /**< \brief Pwm signal: PWM1 */
#define PIO_PC19C_PWM1          (1u << 19) /**< \brief Pwm signal: PWM1 */
#define PIO_PB13B_PWM2          (1u << 13) /**< \brief Pwm signal: PWM2 */
#define PIO_PC20C_PWM2          (1u << 20) /**< \brief Pwm signal: PWM2 */
#define PIO_PB14B_PWM3          (1u << 14) /**< \brief Pwm signal: PWM3 */
#define PIO_PC21C_PWM3          (1u << 21) /**< \brief Pwm signal: PWM3 */
/* ========== Pio definition for QSPI peripheral ========== */
#define PIO_PB20A_QCS           (1u << 20) /**< \brief Qspi signal: QCS */
#define PIO_PB21A_QIO0          (1u << 21) /**< \brief Qspi signal: QIO0 */
#define PIO_PB22A_QIO1          (1u << 22) /**< \brief Qspi signal: QIO1 */
#define PIO_PB23A_QIO2          (1u << 23) /**< \brief Qspi signal: QIO2 */
#define PIO_PB24A_QIO3          (1u << 24) /**< \brief Qspi signal: QIO3 */
#define PIO_PB19A_QSCK          (1u << 19) /**< \brief Qspi signal: QSCK */
/* ========== Pio definition for SDMMC0 peripheral ========== */
#define PIO_PA17A_SDMMC0_CK     (1u << 17) /**< \brief Sdmmc0 signal: SDMMC0_CK */
#define PIO_PA16A_SDMMC0_CMD    (1u << 16) /**< \brief Sdmmc0 signal: SDMMC0_CMD */
#define PIO_PA15A_SDMMC0_DAT0   (1u << 15) /**< \brief Sdmmc0 signal: SDMMC0_DAT0 */
#define PIO_PA18A_SDMMC0_DAT1   (1u << 18) /**< \brief Sdmmc0 signal: SDMMC0_DAT1 */
#define PIO_PA19A_SDMMC0_DAT2   (1u << 19) /**< \brief Sdmmc0 signal: SDMMC0_DAT2 */
#define PIO_PA20A_SDMMC0_DAT3   (1u << 20) /**< \brief Sdmmc0 signal: SDMMC0_DAT3 */
/* ========== Pio definition for SDMMC1 peripheral ========== */
#define PIO_PA13B_SDMMC1_CK     (1u << 13) /**< \brief Sdmmc1 signal: SDMMC1_CK */
#define PIO_PA12B_SDMMC1_CMD    (1u << 12) /**< \brief Sdmmc1 signal: SDMMC1_CMD */
#define PIO_PA11B_SDMMC1_DAT0   (1u << 11) /**< \brief Sdmmc1 signal: SDMMC1_DAT0 */
#define PIO_PA2B_SDMMC1_DAT1    (1u << 2)  /**< \brief Sdmmc1 signal: SDMMC1_DAT1 */
#define PIO_PA3B_SDMMC1_DAT2    (1u << 3)  /**< \brief Sdmmc1 signal: SDMMC1_DAT2 */
#define PIO_PA4B_SDMMC1_DAT3    (1u << 4)  /**< \brief Sdmmc1 signal: SDMMC1_DAT3 */
/* ========== Pio definition for SSC peripheral ========== */
#define PIO_PA27B_RD            (1u << 27) /**< \brief Ssc signal: RD */
#define PIO_PA29B_RF            (1u << 29) /**< \brief Ssc signal: RF */
#define PIO_PA28B_RK            (1u << 28) /**< \brief Ssc signal: RK */
#define PIO_PA26B_TD            (1u << 26) /**< \brief Ssc signal: TD */
#define PIO_PA25B_TF            (1u << 25) /**< \brief Ssc signal: TF */
#define PIO_PA24B_TK            (1u << 24) /**< \brief Ssc signal: TK */
/* ========== Pio definition for TC0 peripheral ========== */
#define PIO_PA24A_TCLK0         (1u << 24) /**< \brief Tc0 signal: TCLK0 */
#define PIO_PA25A_TCLK1         (1u << 25) /**< \brief Tc0 signal: TCLK1 */
#define PIO_PA26A_TCLK2         (1u << 26) /**< \brief Tc0 signal: TCLK2 */
#define PIO_PA21A_TIOA0         (1u << 21) /**< \brief Tc0 signal: TIOA0 */
#define PIO_PA22A_TIOA1         (1u << 22) /**< \brief Tc0 signal: TIOA1 */
#define PIO_PA23A_TIOA2         (1u << 23) /**< \brief Tc0 signal: TIOA2 */
#define PIO_PA27A_TIOB0         (1u << 27) /**< \brief Tc0 signal: TIOB0 */
#define PIO_PA28A_TIOB1         (1u << 28) /**< \brief Tc0 signal: TIOB1 */
#define PIO_PA29A_TIOB2         (1u << 29) /**< \brief Tc0 signal: TIOB2 */
/* ========== Pio definition for TC1 peripheral ========== */
#define PIO_PC4C_TCLK3          (1u << 4)  /**< \brief Tc1 signal: TCLK3 */
#define PIO_PC7C_TCLK4          (1u << 7)  /**< \brief Tc1 signal: TCLK4 */
#define PIO_PC14C_TCLK5         (1u << 14) /**< \brief Tc1 signal: TCLK5 */
#define PIO_PC2C_TIOA3          (1u << 2)  /**< \brief Tc1 signal: TIOA3 */
#define PIO_PC5C_TIOA4          (1u << 5)  /**< \brief Tc1 signal: TIOA4 */
#define PIO_PC12C_TIOA5         (1u << 12) /**< \brief Tc1 signal: TIOA5 */
#define PIO_PC3C_TIOB3          (1u << 3)  /**< \brief Tc1 signal: TIOB3 */
#define PIO_PC6C_TIOB4          (1u << 6)  /**< \brief Tc1 signal: TIOB4 */
#define PIO_PC13C_TIOB5         (1u << 13) /**< \brief Tc1 signal: TIOB5 */
/* ========== Pio indexes ========== */
#define PIO_PA0_IDX             0
#define PIO_PA1_IDX             1
#define PIO_PA2_IDX             2
#define PIO_PA3_IDX             3
#define PIO_PA4_IDX             4
#define PIO_PA5_IDX             5
#define PIO_PA6_IDX             6
#define PIO_PA7_IDX             7
#define PIO_PA8_IDX             8
#define PIO_PA9_IDX             9
#define PIO_PA10_IDX            10
#define PIO_PA11_IDX            11
#define PIO_PA12_IDX            12
#define PIO_PA13_IDX            13
#define PIO_PA14_IDX            14
#define PIO_PA15_IDX            15
#define PIO_PA16_IDX            16
#define PIO_PA17_IDX            17
#define PIO_PA18_IDX            18
#define PIO_PA19_IDX            19
#define PIO_PA20_IDX            20
#define PIO_PA21_IDX            21
#define PIO_PA22_IDX            22
#define PIO_PA23_IDX            23
#define PIO_PA24_IDX            24
#define PIO_PA25_IDX            25
#define PIO_PA26_IDX            26
#define PIO_PA27_IDX            27
#define PIO_PA28_IDX            28
#define PIO_PA29_IDX            29
#define PIO_PA30_IDX            30
#define PIO_PA31_IDX            31
#define PIO_PB0_IDX             32
#define PIO_PB1_IDX             33
#define PIO_PB2_IDX             34
#define PIO_PB3_IDX             35
#define PIO_PB4_IDX             36
#define PIO_PB5_IDX             37
#define PIO_PB6_IDX             38
#define PIO_PB7_IDX             39
#define PIO_PB8_IDX             40
#define PIO_PB9_IDX             41
#define PIO_PB10_IDX            42
#define PIO_PB11_IDX            43
#define PIO_PB12_IDX            44
#define PIO_PB13_IDX            45
#define PIO_PB14_IDX            46
#define PIO_PB15_IDX            47
#define PIO_PB16_IDX            48
#define PIO_PB17_IDX            49
#define PIO_PB18_IDX            50
#define PIO_PB19_IDX            51
#define PIO_PB20_IDX            52
#define PIO_PB21_IDX            53
#define PIO_PB22_IDX            54
#define PIO_PB23_IDX            55
#define PIO_PB24_IDX            56
#define PIO_PB25_IDX            57
#define PIO_PC0_IDX             64
#define PIO_PC1_IDX             65
#define PIO_PC2_IDX             66
#define PIO_PC3_IDX             67
#define PIO_PC4_IDX             68
#define PIO_PC5_IDX             69
#define PIO_PC6_IDX             70
#define PIO_PC7_IDX             71
#define PIO_PC8_IDX             72
#define PIO_PC9_IDX             73
#define PIO_PC10_IDX            74
#define PIO_PC11_IDX            75
#define PIO_PC12_IDX            76
#define PIO_PC13_IDX            77
#define PIO_PC14_IDX            78
#define PIO_PC15_IDX            79
#define PIO_PC16_IDX            80
#define PIO_PC17_IDX            81
#define PIO_PC18_IDX            82
#define PIO_PC19_IDX            83
#define PIO_PC20_IDX            84
#define PIO_PC21_IDX            85
#define PIO_PC22_IDX            86
#define PIO_PC23_IDX            87
#define PIO_PC24_IDX            88
#define PIO_PC25_IDX            89
#define PIO_PC26_IDX            90
#define PIO_PC27_IDX            91
#define PIO_PC28_IDX            92
#define PIO_PC29_IDX            93
#define PIO_PC30_IDX            94
#define PIO_PC31_IDX            95
#define PIO_PD0_IDX             96
#define PIO_PD1_IDX             97
#define PIO_PD2_IDX             98
#define PIO_PD3_IDX             99
#define PIO_PD4_IDX             100
#define PIO_PD5_IDX             101
#define PIO_PD6_IDX             102
#define PIO_PD7_IDX             103
#define PIO_PD8_IDX             104
#define PIO_PD9_IDX             105
#define PIO_PD10_IDX            106
#define PIO_PD11_IDX            107
#define PIO_PD12_IDX            108
#define PIO_PD13_IDX            109
#define PIO_PD14_IDX            110
#define PIO_PD15_IDX            111
#define PIO_PD16_IDX            112
#define PIO_PD17_IDX            113
#define PIO_PD18_IDX            114
#define PIO_PD19_IDX            115
#define PIO_PD20_IDX            116
#define PIO_PD21_IDX            117

#endif /* _SAM9X60_PIO_ */
