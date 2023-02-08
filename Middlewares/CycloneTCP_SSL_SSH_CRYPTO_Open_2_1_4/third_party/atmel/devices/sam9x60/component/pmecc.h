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

#ifndef _SAM9X_PMECC_COMPONENT_
#define _SAM9X_PMECC_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Programmable Multibit Error Correction Code Controller */
/* ============================================================================= */
/** \addtogroup SAM9X_PMECC Programmable Multibit Error Correction Code Controller */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PmeccEcc hardware registers */
typedef struct {
  __I uint32_t PMECC_ECC[11]; /**< \brief (PmeccEcc Offset: 0x0) PMECC ECC x Register */
  __I uint32_t Reserved1[5];
} PmeccEcc;
/** \brief PmeccRem hardware registers */
typedef struct {
  __I uint32_t PMECC_REM[12]; /**< \brief (PmeccRem Offset: 0x0) PMECC REM x Register */
  __I uint32_t Reserved1[4];
} PmeccRem;
/** \brief Pmecc hardware registers */
#define PMECCECC_NUMBER 8
#define PMECCREM_NUMBER 8
typedef struct {
  __IO uint32_t PMECC_CFG;                  /**< \brief (Pmecc Offset: 0x0) PMECC Configuration Register */
  __IO uint32_t PMECC_SAREA;                /**< \brief (Pmecc Offset: 0x4) PMECC Spare Area Size Register */
  __IO uint32_t PMECC_SADDR;                /**< \brief (Pmecc Offset: 0x8) PMECC Start Address Register */
  __IO uint32_t PMECC_EADDR;                /**< \brief (Pmecc Offset: 0xC) PMECC End Address Register */
  __IO uint32_t PMECC_CLK;                  /**< \brief (Pmecc Offset: 0x10) PMECC Clock Control Register */
  __O  uint32_t PMECC_CTRL;                 /**< \brief (Pmecc Offset: 0x14) PMECC Control Register */
  __I  uint32_t PMECC_SR;                   /**< \brief (Pmecc Offset: 0x18) PMECC Status Register */
  __O  uint32_t PMECC_IER;                  /**< \brief (Pmecc Offset: 0x1C) PMECC Interrupt Enable register */
  __O  uint32_t PMECC_IDR;                  /**< \brief (Pmecc Offset: 0x20) PMECC Interrupt Disable Register */
  __I  uint32_t PMECC_IMR;                  /**< \brief (Pmecc Offset: 0x24) PMECC Interrupt Mask Register */
  __I  uint32_t PMECC_ISR;                  /**< \brief (Pmecc Offset: 0x28) PMECC Interrupt Status Register */
  __I  uint32_t Reserved1[5];
       PmeccEcc PMECC_ECC[PMECCECC_NUMBER]; /**< \brief (Pmecc Offset: 0x40) sec_num = 0 .. 7 */
       PmeccRem PMECC_REM[PMECCREM_NUMBER]; /**< \brief (Pmecc Offset: 0x240) sec_num = 0 .. 7 */
} Pmecc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- PMECC_CFG : (PMECC Offset: 0x0) PMECC Configuration Register -------- */
#define PMECC_CFG_BCH_ERR_Pos 0
#define PMECC_CFG_BCH_ERR_Msk (0x7u << PMECC_CFG_BCH_ERR_Pos) /**< \brief (PMECC_CFG) Error Correct Capability */
#define PMECC_CFG_BCH_ERR(value) ((PMECC_CFG_BCH_ERR_Msk & ((value) << PMECC_CFG_BCH_ERR_Pos)))
#define   PMECC_CFG_BCH_ERR_BCH_ERR2 (0x0u << 0) /**< \brief (PMECC_CFG) 2 errors */
#define   PMECC_CFG_BCH_ERR_BCH_ERR4 (0x1u << 0) /**< \brief (PMECC_CFG) 4 errors */
#define   PMECC_CFG_BCH_ERR_BCH_ERR8 (0x2u << 0) /**< \brief (PMECC_CFG) 8 errors */
#define   PMECC_CFG_BCH_ERR_BCH_ERR12 (0x3u << 0) /**< \brief (PMECC_CFG) 12 errors */
#define   PMECC_CFG_BCH_ERR_BCH_ERR24 (0x4u << 0) /**< \brief (PMECC_CFG) 24 errors */
#define PMECC_CFG_SECTORSZ (0x1u << 4) /**< \brief (PMECC_CFG) Sector Size */
#define PMECC_CFG_PAGESIZE_Pos 8
#define PMECC_CFG_PAGESIZE_Msk (0x3u << PMECC_CFG_PAGESIZE_Pos) /**< \brief (PMECC_CFG) Number of Sectors in the Page */
#define PMECC_CFG_PAGESIZE(value) ((PMECC_CFG_PAGESIZE_Msk & ((value) << PMECC_CFG_PAGESIZE_Pos)))
#define   PMECC_CFG_PAGESIZE_PAGESIZE_1SEC (0x0u << 8) /**< \brief (PMECC_CFG) 1 sector for main area (512 or 1024 bytes) */
#define   PMECC_CFG_PAGESIZE_PAGESIZE_2SEC (0x1u << 8) /**< \brief (PMECC_CFG) 2 sectors for main area (1024 or 2048 bytes) */
#define   PMECC_CFG_PAGESIZE_PAGESIZE_4SEC (0x2u << 8) /**< \brief (PMECC_CFG) 4 sectors for main area (2048 or 4096 bytes) */
#define   PMECC_CFG_PAGESIZE_PAGESIZE_8SEC (0x3u << 8) /**< \brief (PMECC_CFG) 8 errors for main area (4096 or 8192 bytes) */
#define PMECC_CFG_NANDWR (0x1u << 12) /**< \brief (PMECC_CFG) NAND Write Access */
#define PMECC_CFG_SPAREEN (0x1u << 16) /**< \brief (PMECC_CFG) Spare Enable */
#define PMECC_CFG_AUTO (0x1u << 20) /**< \brief (PMECC_CFG) Automatic Mode Enable */
/* -------- PMECC_SAREA : (PMECC Offset: 0x4) PMECC Spare Area Size Register -------- */
#define PMECC_SAREA_SPARESIZE_Pos 0
#define PMECC_SAREA_SPARESIZE_Msk (0x1ffu << PMECC_SAREA_SPARESIZE_Pos) /**< \brief (PMECC_SAREA) Spare Area Size */
#define PMECC_SAREA_SPARESIZE(value) ((PMECC_SAREA_SPARESIZE_Msk & ((value) << PMECC_SAREA_SPARESIZE_Pos)))
/* -------- PMECC_SADDR : (PMECC Offset: 0x8) PMECC Start Address Register -------- */
#define PMECC_SADDR_STARTADDR_Pos 0
#define PMECC_SADDR_STARTADDR_Msk (0x1ffu << PMECC_SADDR_STARTADDR_Pos) /**< \brief (PMECC_SADDR) ECC Area Start Address (byte oriented address) */
#define PMECC_SADDR_STARTADDR(value) ((PMECC_SADDR_STARTADDR_Msk & ((value) << PMECC_SADDR_STARTADDR_Pos)))
/* -------- PMECC_EADDR : (PMECC Offset: 0xC) PMECC End Address Register -------- */
#define PMECC_EADDR_ENDADDR_Pos 0
#define PMECC_EADDR_ENDADDR_Msk (0x1ffu << PMECC_EADDR_ENDADDR_Pos) /**< \brief (PMECC_EADDR) ECC Area End Address (byte oriented address) */
#define PMECC_EADDR_ENDADDR(value) ((PMECC_EADDR_ENDADDR_Msk & ((value) << PMECC_EADDR_ENDADDR_Pos)))
/* -------- PMECC_CLK : (PMECC Offset: 0x10) PMECC Clock Control Register -------- */
#define PMECC_CLK_CLKCTRL_Pos 0
#define PMECC_CLK_CLKCTRL_Msk (0x7u << PMECC_CLK_CLKCTRL_Pos) /**< \brief (PMECC_CLK) Clock Control Register */
#define PMECC_CLK_CLKCTRL(value) ((PMECC_CLK_CLKCTRL_Msk & ((value) << PMECC_CLK_CLKCTRL_Pos)))
/* -------- PMECC_CTRL : (PMECC Offset: 0x14) PMECC Control Register -------- */
#define PMECC_CTRL_RST (0x1u << 0) /**< \brief (PMECC_CTRL) Reset the PMECC Module */
#define PMECC_CTRL_DATA (0x1u << 1) /**< \brief (PMECC_CTRL) Start a Data Phase */
#define PMECC_CTRL_USER (0x1u << 2) /**< \brief (PMECC_CTRL) Start a User Mode Phase */
#define PMECC_CTRL_ENABLE (0x1u << 4) /**< \brief (PMECC_CTRL) PMECC Module Enable */
#define PMECC_CTRL_DISABLE (0x1u << 5) /**< \brief (PMECC_CTRL) PMECC Module Disable */
/* -------- PMECC_SR : (PMECC Offset: 0x18) PMECC Status Register -------- */
#define PMECC_SR_BUSY (0x1u << 0) /**< \brief (PMECC_SR) The Kernel of the PMECC is Busy */
#define PMECC_SR_ENABLE (0x1u << 4) /**< \brief (PMECC_SR) PMECC Module Status */
/* -------- PMECC_IER : (PMECC Offset: 0x1C) PMECC Interrupt Enable register -------- */
#define PMECC_IER_ERRIE (0x1u << 0) /**< \brief (PMECC_IER) Error Interrupt Enable */
/* -------- PMECC_IDR : (PMECC Offset: 0x20) PMECC Interrupt Disable Register -------- */
#define PMECC_IDR_ERRID (0x1u << 0) /**< \brief (PMECC_IDR) Error Interrupt Disable */
/* -------- PMECC_IMR : (PMECC Offset: 0x24) PMECC Interrupt Mask Register -------- */
#define PMECC_IMR_ERRIM (0x1u << 0) /**< \brief (PMECC_IMR) Error Interrupt Mask */
/* -------- PMECC_ISR : (PMECC Offset: 0x28) PMECC Interrupt Status Register -------- */
#define PMECC_ISR_ERRIS_Pos 0
#define PMECC_ISR_ERRIS_Msk (0xffu << PMECC_ISR_ERRIS_Pos) /**< \brief (PMECC_ISR) Error Interrupt Status */
/* -------- PMECC_ECC[11] : (PMECC Offset: N/A) PMECC ECC x Register -------- */
#define PMECC_ECC_ECC_Pos 0
#define PMECC_ECC_ECC_Msk (0xffffffffu << PMECC_ECC_ECC_Pos) /**< \brief (PMECC_ECC[11]) BCH Redundancy */
/* -------- PMECC_REM[12] : (PMECC Offset: N/A) PMECC REM x Register -------- */
#define PMECC_REM_REM2NP1_Pos 0
#define PMECC_REM_REM2NP1_Msk (0x3fffu << PMECC_REM_REM2NP1_Pos) /**< \brief (PMECC_REM[12]) BCH Remainder 2 * N + 1 */
#define PMECC_REM_REM2NP3_Pos 16
#define PMECC_REM_REM2NP3_Msk (0x3fffu << PMECC_REM_REM2NP3_Pos) /**< \brief (PMECC_REM[12]) BCH Remainder 2 * N + 3 */

/*@}*/


#endif /* _SAM9X_PMECC_COMPONENT_ */
