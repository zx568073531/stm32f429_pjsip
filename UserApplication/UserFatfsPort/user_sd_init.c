#include "user_sd_init.h"
#include "ff_gen_drv.h"
#include "sd_diskio_dma_rtos.h"

volatile uint8_t sd_status = 0;
char SDPath[4]; /* SD card logical drive path */
FATFS SDFatFs;  /* File system object for SD card logical drive */

void UserSDcardInit(void)
{
	FATFS_LinkDriver(&SD_Driver, SDPath);
	
	if(BSP_SD_Init() == MSD_OK)
	{
		sd_status = 1;
	}
	else
	{
		sd_status = 0;
	}
	
//	if(f_mount(&SDFatFs, (TCHAR const*)SDPath, 1) != FR_OK)
//	{
//		/* FatFs Initialization Error */
//		Error_Handler();
//	}	
	
}


uint8_t GetSDcardStatus(void)
{
	return sd_status;
}
