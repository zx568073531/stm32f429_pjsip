/**
  ******************************************************************************
  * @file    sd_diskio_dma_rtos.c
  * @author  MCD Application Team
  * @brief   SD Disk I/O DMA with RTOS driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ff_gen_drv.h"
#include "sd_diskio_dma_rtos.h"
#include "systemCore.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define QUEUE_SIZE         (uint32_t) 10
#define READ_CPLT_MSG      (uint32_t) 1
#define WRITE_CPLT_MSG     (uint32_t) 2

/*
 * the following Timeout is useful to give the control back to the applications
 * in case of errors in either BSP_SD_ReadCpltCallback() or BSP_SD_WriteCpltCallback()
 * the value by default is as defined in the BSP platform driver otherwise 30 secs
 *
 */

#define SD_TIMEOUT 30 * 1000

#define SD_DEFAULT_BLOCK_SIZE 512

/*
 * Depending on the usecase, the SD card initialization could be done at the
 * application level, if it is the case define the flag below to disable
 * the BSP_SD_Init() call in the SD_Initialize().
 */

#define DISABLE_SD_INIT


/*
 * when using cachable memory region, it may be needed to maintain the cache
 * validity. Enable the define below to activate a cache maintenance at each
 * read and write operation.
 * Notice: This is applicable only for cortex M7 based platform.
 */

/* #define ENABLE_SD_DMA_CACHE_MAINTENANCE  1 */


/* Private variables ---------------------------------------------------------*/
/* Disk status */
static volatile DSTATUS Stat = STA_NOINIT;
static void * SDQueueID;
/* Private function prototypes -----------------------------------------------*/
static DSTATUS SD_CheckStatus(BYTE lun);
DSTATUS SD_initialize (BYTE);
DSTATUS SD_status (BYTE);
DRESULT SD_read (BYTE, BYTE*, DWORD, UINT);
DRESULT SD_write (BYTE, const BYTE*, DWORD, UINT);
DRESULT SD_ioctl (BYTE, BYTE, void*);

const Diskio_drvTypeDef  SD_Driver =
{
  SD_initialize,
  SD_status,
  SD_read,
  SD_write,
  SD_ioctl,

};



uint32_t osKernelSysTick(void)
{
  if (inHandlerMode()) {
    return xTaskGetTickCountFromISR();
  }
  else {
    return xTaskGetTickCount();
  }
}


/* Private functions ---------------------------------------------------------*/
static DSTATUS SD_CheckStatus(BYTE lun)
{
  Stat = STA_NOINIT;

  if(BSP_SD_GetCardState() == MSD_OK)
  {
    Stat &= ~STA_NOINIT;
  }

  return Stat;
}

/**
  * @brief  Initializes a Drive
  * @param  lun : not used
  * @retval DSTATUS: Operation status
  */
DSTATUS SD_initialize(BYTE lun)
{
  Stat = STA_NOINIT;
  /*
   * check that the kernel has been started before continuing
   * as the osMessage API will fail otherwise
   */
  if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
  {
#if !defined(DISABLE_SD_INIT)

    if(BSP_SD_Init() == MSD_OK)
    {
      Stat = SD_CheckStatus(lun);
    }

#else
    Stat = SD_CheckStatus(lun);
#endif

    /*
     * if the SD is correctly initialized, create the operation queue
     */

    if (Stat != STA_NOINIT)
    {
			if(SDQueueID == NULL)
			{
				SDQueueID = xQueueCreate (QUEUE_SIZE, sizeof(uint16_t));
			}
      
    }
  }

  return Stat;
}

/**
  * @brief  Gets Disk Status
  * @param  lun : not used
  * @retval DSTATUS: Operation status
  */
DSTATUS SD_status(BYTE lun)
{
  return SD_CheckStatus(lun);
}

/**
  * @brief  Reads Sector(s)
  * @param  lun : not used
  * @param  *buff: Data buffer to store read data
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to read (1..128)
  * @retval DRESULT: Operation result
  */
DRESULT SD_read(BYTE lun, BYTE *buff, DWORD sector, UINT count)
{
  DRESULT res = RES_ERROR;
	
  portBASE_TYPE taskWoken;
  taskWoken = pdFALSE;
	
  uint32_t timer;
	uint16_t event;
	uint8_t ret ;
	
#if (ENABLE_SD_DMA_CACHE_MAINTENANCE == 1)
  uint32_t alignedAddr;
#endif

  if(BSP_SD_ReadBlocks_DMA((uint32_t*)buff,
                           (uint32_t) (sector),
                           count) == MSD_OK)
  {
		ret = 0;
		
		if (inHandlerMode()) 
		{
			if (xQueueReceiveFromISR(SDQueueID, &event, &taskWoken) == pdTRUE) 
			{
				ret = 1;
				portEND_SWITCHING_ISR(taskWoken);
			}
		}
		else 
		{
			if (xQueueReceive(SDQueueID, &event, SD_TIMEOUT) == pdTRUE) 
			{
				ret = 1;
			}
		}
	
    /* wait for a message from the queue or a timeout */
    if (ret == 1)
    {
      if (event == READ_CPLT_MSG)
      {
        timer = osKernelSysTick() + SD_TIMEOUT;
        /* block until SDIO IP is ready or a timeout occur */
        while(timer > osKernelSysTick())
        {
          if (BSP_SD_GetCardState() == SD_TRANSFER_OK)
          {
            res = RES_OK;
#if (ENABLE_SD_DMA_CACHE_MAINTENANCE == 1)
            /*
               the SCB_InvalidateDCache_by_Addr() requires a 32-Byte aligned address,
               adjust the address and the D-Cache size to invalidate accordingly.
             */
            alignedAddr = (uint32_t)buff & ~0x1F;
            SCB_InvalidateDCache_by_Addr((uint32_t*)alignedAddr, count*BLOCKSIZE + ((uint32_t)buff - alignedAddr));
#endif
            break;
          }
        }
      }
    }
  }

  return res;
}

/**
  * @brief  Writes Sector(s)
  * @param  lun : not used
  * @param  *buff: Data to be written
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to write (1..128)
  * @retval DRESULT: Operation result
  */
DRESULT SD_write(BYTE lun, const BYTE *buff, DWORD sector, UINT count)
{
  DRESULT res = RES_ERROR;
	
  portBASE_TYPE taskWoken;
  taskWoken = pdFALSE;
	
  uint32_t timer;
	uint16_t event;
	uint8_t ret ;
	
#if (ENABLE_SD_DMA_CACHE_MAINTENANCE == 1)
  uint32_t alignedAddr;
  /*
    the SCB_CleanDCache_by_Addr() requires a 32-Byte aligned address
    adjust the address and the D-Cache size to clean accordingly.
  */
  alignedAddr = (uint32_t)buff & ~0x1F;
  SCB_CleanDCache_by_Addr((uint32_t*)alignedAddr, count*BLOCKSIZE + ((uint32_t)buff - alignedAddr));
#endif


  if(BSP_SD_WriteBlocks_DMA((uint32_t*)buff,
                           (uint32_t) (sector),
                           count) == MSD_OK)
  {
		ret = 0;
		
		if (inHandlerMode()) 
		{
			if (xQueueReceiveFromISR(SDQueueID, &event, &taskWoken) == pdTRUE) 
			{
				ret = 1;
				portEND_SWITCHING_ISR(taskWoken);
			}
		}
		else 
		{
			if (xQueueReceive(SDQueueID, &event, SD_TIMEOUT) == pdTRUE) 
			{
				ret = 1;
			}
		}
	
    /* wait for a message from the queue or a timeout */
    if (ret == 1)
    {
      if (event == WRITE_CPLT_MSG)
      {
        timer = osKernelSysTick() + SD_TIMEOUT;
        /* block until SDIO IP is ready or a timeout occur */
        while(timer > osKernelSysTick())
        {
          if (BSP_SD_GetCardState() == SD_TRANSFER_OK)
          {
            res = RES_OK;
            break;
          }
        }
      }
    }
  }

  return res;
}

/**
  * @brief  I/O control operation
  * @param  lun : not used
  * @param  cmd: Control code
  * @param  *buff: Buffer to send/receive control data
  * @retval DRESULT: Operation result
  */
DRESULT SD_ioctl(BYTE lun, BYTE cmd, void *buff)
{
  DRESULT res = RES_ERROR;
  BSP_SD_CardInfo CardInfo;

  if (Stat & STA_NOINIT) return RES_NOTRDY;

  switch (cmd)
  {
  /* Make sure that no pending write process */
  case CTRL_SYNC :
    res = RES_OK;
    break;

  /* Get number of sectors on the disk (DWORD) */
  case GET_SECTOR_COUNT :
    BSP_SD_GetCardInfo(&CardInfo);
    *(DWORD*)buff = CardInfo.LogBlockNbr;
    res = RES_OK;
    break;

  /* Get R/W sector size (WORD) */
  case GET_SECTOR_SIZE :
    BSP_SD_GetCardInfo(&CardInfo);
    *(WORD*)buff = CardInfo.LogBlockSize;
    res = RES_OK;
    break;

  /* Get erase block size in unit of sector (DWORD) */
  case GET_BLOCK_SIZE :
    BSP_SD_GetCardInfo(&CardInfo);
    *(DWORD*)buff = CardInfo.LogBlockSize / SD_DEFAULT_BLOCK_SIZE;
	res = RES_OK;
    break;

  default:
    res = RES_PARERR;
  }

  return res;
}


/**
  * @brief Tx Transfer completed callbacks
  * @param hsd: SD handle
  * @retval None
  */
void BSP_SD_WriteCpltCallback(void)
{
	portBASE_TYPE taskWoken = pdFALSE;
	uint16_t event = WRITE_CPLT_MSG;
	
  if (inHandlerMode()) {
    if (xQueueSendFromISR(SDQueueID, &event, &taskWoken) != pdTRUE) {
      return ;
    }
    portEND_SWITCHING_ISR(taskWoken);
  }
  else {
		xQueueSend(SDQueueID, &event, portMAX_DELAY);
  }
	
  /*
   * No need to add an "osKernelRunning()" check here, as the SD_initialize()
   * is always called before any SD_Read()/SD_Write() call
   */
//   osMessagePut(SDQueueID, WRITE_CPLT_MSG, osWaitForever);
}

/**
  * @brief Rx Transfer completed callbacks
  * @param hsd: SD handle
  * @retval None
  */
void BSP_SD_ReadCpltCallback(void)
{
	portBASE_TYPE taskWoken = pdFALSE;
	uint16_t event = READ_CPLT_MSG;
	
  if (inHandlerMode()) {
    if (xQueueSendFromISR(SDQueueID, &event, &taskWoken) != pdTRUE) {
      return ;
    }
    portEND_SWITCHING_ISR(taskWoken);
  }
  else {
		xQueueSend(SDQueueID, &event, portMAX_DELAY);
  }
	
  /*
   * No need to add an "osKernelRunning()" check here, as the SD_initialize()
   * is always called before any SD_Read()/SD_Write() call
   */
//   osMessagePut(SDQueueID, READ_CPLT_MSG, osWaitForever);
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

