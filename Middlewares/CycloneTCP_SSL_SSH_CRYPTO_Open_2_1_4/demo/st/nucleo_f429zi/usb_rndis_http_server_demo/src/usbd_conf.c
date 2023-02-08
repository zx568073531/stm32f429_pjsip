/**
 * @file usbd_conf.c
 * @brief USB device low-level configuration
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

//Dependencies
#include "usbd_core.h"

//Peripheral controller driver
PCD_HandleTypeDef hpcd;


/**
 * @brief PCD MSP initialization
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 **/

void HAL_PCD_MspInit(PCD_HandleTypeDef *hpcd)
{
   GPIO_InitTypeDef GPIO_InitStruct;

   //Enable GPIO clock
   __HAL_RCC_GPIOA_CLK_ENABLE();

   //Configure VBUS pin (PA9)
   GPIO_InitStruct.Pin = GPIO_PIN_9;
   GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
   GPIO_InitStruct.Pull = GPIO_PULLDOWN;
   HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

   //Configure OTG_FS_ID (PA10)
   GPIO_InitStruct.Pin = GPIO_PIN_10;
   GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
   GPIO_InitStruct.Pull = GPIO_PULLUP;
   GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
   HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

   //Configure OTG_FS_DM (PA11) and OTG_FS_DP (PA12)
   GPIO_InitStruct.Pin = GPIO_PIN_11 | GPIO_PIN_12;
   GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
   GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
   HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

   //Enable USB FS clock
   __HAL_RCC_USB_OTG_FS_CLK_ENABLE();

   //Set OTG_FS interrupt priority
   HAL_NVIC_SetPriority(OTG_FS_IRQn, 15, 0);

   //Enable OTG_FS interrupts
   HAL_NVIC_EnableIRQ(OTG_FS_IRQn);
}


/**
 * @brief PCD MSP de-initialization
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 **/

void HAL_PCD_MspDeInit(PCD_HandleTypeDef *hpcd)
{
   //Disable USB FS clock
   __HAL_RCC_USB_OTG_FS_CLK_DISABLE();
}


/**
 * @brief Setup stage callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 **/

void HAL_PCD_SetupStageCallback(PCD_HandleTypeDef *hpcd)
{
   USBD_LL_SetupStage(hpcd->pData, (uint8_t *) hpcd->Setup);
}


/**
 * @brief Data out stage callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 * @param[in] epnum Endpoint number
 **/

void HAL_PCD_DataOutStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
   USBD_LL_DataOutStage(hpcd->pData, epnum, hpcd->OUT_ep[epnum].xfer_buff);
}


/**
 * @brief Data in stage callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 * @param[in] epnum Endpoint number
 **/

void HAL_PCD_DataInStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
   USBD_LL_DataInStage(hpcd->pData, epnum, hpcd->IN_ep[epnum].xfer_buff);
}


/**
 * @brief SOF callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 **/

void HAL_PCD_SOFCallback(PCD_HandleTypeDef *hpcd)
{
   USBD_LL_SOF(hpcd->pData);
}


/**
 * @brief Reset callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 **/

void HAL_PCD_ResetCallback(PCD_HandleTypeDef *hpcd)
{
   //Set USB speed
   USBD_LL_SetSpeed(hpcd->pData, USBD_SPEED_FULL);

   //Reset USB device
   USBD_LL_Reset(hpcd->pData);
}


/**
 * @brief Suspend callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 **/

void HAL_PCD_SuspendCallback(PCD_HandleTypeDef *hpcd)
{
   USBD_LL_Suspend(hpcd->pData);
}


/**
 * @brief Resume callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 */

void HAL_PCD_ResumeCallback(PCD_HandleTypeDef *hpcd)
{
   USBD_LL_Resume(hpcd->pData);
}


/**
 * @brief ISO out incomplete callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 * @param[in] epnum Endpoint number
 **/

void HAL_PCD_ISOOUTIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
   USBD_LL_IsoOUTIncomplete(hpcd->pData, epnum);
}


/**
 * @brief ISO in incomplete callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 * @param[in] epnum Endpoint number
 **/

void HAL_PCD_ISOINIncompleteCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
   USBD_LL_IsoINIncomplete(hpcd->pData, epnum);
}


/**
 * @brief Connect callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 **/

void HAL_PCD_ConnectCallback(PCD_HandleTypeDef *hpcd)
{
   USBD_LL_DevConnected(hpcd->pData);
}


/**
 * @brief Disconnect callback
 * @param[in] hpcd Pointer to a PCD_HandleTypeDef structure
 **/

void HAL_PCD_DisconnectCallback(PCD_HandleTypeDef *hpcd)
{
   USBD_LL_DevDisconnected(hpcd->pData);
}


/**
 * @brief Low-level initialization of the USB device driver
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_Init(USBD_HandleTypeDef *pdev)
{
   //Set PCD parameters
   hpcd.Instance = USB_OTG_FS;
   hpcd.Init.dev_endpoints = 4;
   hpcd.Init.use_dedicated_ep1 = 0;
   hpcd.Init.ep0_mps = 64;
   hpcd.Init.dma_enable = 0;
   hpcd.Init.low_power_enable = 0;
   hpcd.Init.phy_itface = PCD_PHY_EMBEDDED;
   hpcd.Init.Sof_enable = 0;
   hpcd.Init.speed = PCD_SPEED_FULL;
   hpcd.Init.vbus_sensing_enable = 1;
   hpcd.Init.lpm_enable = 0;

   //Link the driver to the stack
   hpcd.pData = pdev;
   pdev->pData = &hpcd;

   //PCD initialization
   HAL_PCD_Init(&hpcd);

   //Configure RX FIFO
   HAL_PCDEx_SetRxFiFo(&hpcd, 64);

   //Configure TX FIFOs
   HAL_PCDEx_SetTxFiFo(&hpcd, 0, 64);
   HAL_PCDEx_SetTxFiFo(&hpcd, 1, 64);
   HAL_PCDEx_SetTxFiFo(&hpcd, 2, 64);

   //Successful initialization
   return USBD_OK;
}


/**
 * @brief De-initialization of the USB device driver
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_DeInit(USBD_HandleTypeDef *pdev)
{
   HAL_PCD_DeInit(pdev->pData);
   return USBD_OK;
}


/**
 * @brief Start the USB device driver
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_Start(USBD_HandleTypeDef *pdev)
{
   HAL_PCD_Start(pdev->pData);
   return USBD_OK;
}


/**
 * @brief Stop the USB device driver
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_Stop(USBD_HandleTypeDef *pdev)
{
   HAL_PCD_Stop(pdev->pData);
   return USBD_OK;
}


/**
 * @brief Open the specified endpoint
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] ep_addr Endpoint address
 * @param[in] ep_type Endpoint type
 * @param[in] ep_mps Max Packet Size
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_OpenEP(USBD_HandleTypeDef *pdev,
   uint8_t ep_addr, uint8_t ep_type, uint16_t ep_mps)
{
   HAL_PCD_EP_Open(pdev->pData, ep_addr, ep_mps, ep_type);
   return USBD_OK;
}


/**
 * @brief Close the specified endpoint
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] ep_addr Endpoint address
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_CloseEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
   HAL_PCD_EP_Close(pdev->pData, ep_addr);
   return USBD_OK;
}


/**
 * @brief Flushe the specified endpoint
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] ep_addr Endpoint address
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_FlushEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
   HAL_PCD_EP_Flush(pdev->pData, ep_addr);
   return USBD_OK;
}


/**
 * @brief Stall the specified endpoint
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] ep_addr Endpoint address
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_StallEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
   HAL_PCD_EP_SetStall(pdev->pData, ep_addr);
   return USBD_OK;
}


/**
 * @brief Clear stall condition
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] ep_addr Endpoint address
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_ClearStallEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
   HAL_PCD_EP_ClrStall(pdev->pData, ep_addr);
   return USBD_OK;
}


/**
 * @brief Check whether the specified endpoint is stalled
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] ep_addr Endpoint address
 * @return Stall condition
 **/

uint8_t USBD_LL_IsStallEP(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
   PCD_HandleTypeDef *hpcd = pdev->pData;

   if((ep_addr & 0x80) == 0x80)
   {
      return hpcd->IN_ep[ep_addr & 0x7F].is_stall;
   }
   else
   {
      return hpcd->OUT_ep[ep_addr & 0x7F].is_stall;
   }
}


/**
 * @brief Assign an address to the USB device
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] dev_addr Device address
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_SetUSBAddress(USBD_HandleTypeDef *pdev, uint8_t dev_addr)
{
   HAL_PCD_SetAddress(pdev->pData, dev_addr);
   return USBD_OK;
}


/**
 * @brief Transmit data over an endpoint
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] ep_addr Endpoint address
 * @param[in] pbuf Pointer to the data to be sent
 * @param[in] size Number of data bytes to send
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_Transmit(USBD_HandleTypeDef *pdev,
   uint8_t ep_addr, uint8_t *pbuf, uint32_t size)
{
   HAL_PCD_EP_Transmit(pdev->pData, ep_addr, pbuf, size);
   return USBD_OK;
}


/**
 * @brief Prepare an endpoint for reception
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] ep_addr Endpoint address
 * @param[in] pbuf Buffer where to store the incoming data
 * @param[in] size Size of the buffer, in bytes
 * @return USB device status
 **/

USBD_StatusTypeDef USBD_LL_PrepareReceive(USBD_HandleTypeDef *pdev,
   uint8_t ep_addr, uint8_t *pbuf, uint32_t size)
{
   HAL_PCD_EP_Receive(pdev->pData, ep_addr, pbuf, size);
   return USBD_OK;
}


/**
 * @brief Return the size of the last packet that has been transfered
 * @param[in] pdev Pointer to a USBD_HandleTypeDef structure
 * @param[in] ep_addr Endpoint address
 * @return Data size
 **/

uint32_t USBD_LL_GetRxDataSize(USBD_HandleTypeDef *pdev, uint8_t ep_addr)
{
   return HAL_PCD_EP_GetRxCount(pdev->pData, ep_addr);
}


/**
 * @brief Delay routine for the USB device library
 * @param[in] delay Delay in milliseconds
 **/

void USBD_LL_Delay(uint32_t delay)
{
   HAL_Delay(delay);
}
