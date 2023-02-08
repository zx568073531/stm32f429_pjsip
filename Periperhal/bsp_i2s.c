
/*
*************************************************************************
*                             包含的头文件
*************************************************************************
*/ 
#include "bsp_i2s.h"
#include "systemTime.h"

/*
*************************************************************************
*                             全局变量定义
*************************************************************************
*/ 


static I2S_HandleTypeDef bsp_i2s2;
static DMA_HandleTypeDef hdma_i2sTx;
static DMA_HandleTypeDef hdma_i2sRx;

/*
*************************************************************************
*                             函数定义
*************************************************************************
*/ 

__weak void txDMAConvCplt(DMA_HandleTypeDef *hdma){}
__weak void rxDMAConvCplt(DMA_HandleTypeDef *hdma){}

/**
  * @brief  I2S配置初始化函数
  * @param  None
  * @retval None
  */
void bsp_i2s_init(uint32_t frqcy)
{
  bsp_i2s2.Instance         = SPI2;
	/* Disable I2S2 block */
  __HAL_I2S_DISABLE(&bsp_i2s2);
	
  /* I2S2 peripheral configuration */
	delay_us(10);
	
	bsp_i2s2.Init.AudioFreq   = frqcy;
  
	bsp_i2s2.Init.ClockSource = I2S_CLOCK_PLL;
  bsp_i2s2.Init.MCLKOutput  = I2S_MCLKOUTPUT_ENABLE;
	bsp_i2s2.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_ENABLE;
	
  bsp_i2s2.Init.Standard    = I2S_STANDARD_PHILIPS;
	bsp_i2s2.Init.Mode        = I2S_MODE_MASTER_TX;
  bsp_i2s2.Init.CPOL        = I2S_CPOL_LOW;
  bsp_i2s2.Init.DataFormat  = I2S_DATAFORMAT_16B;
  /* Initialize the I2S peripheral with the structure above */  
  HAL_I2S_Init(&bsp_i2s2);
	
	SET_BIT(bsp_i2s2.Instance->CR2, SPI_CR2_TXDMAEN);
	SET_BIT(I2SxEXT(bsp_i2s2.Instance)->CR2, SPI_CR2_RXDMAEN);
	SET_BIT(I2SxEXT(bsp_i2s2.Instance)->I2SCFGR,SPI_I2SCFGR_I2SE);
	
	__HAL_I2S_ENABLE(&bsp_i2s2);
}

/**
  * @brief  I2S输出DMA初始化
  * @param  None
  * @retval None
  */
void bsp_i2s2_OutDMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t size)
{
  /* Enable the I2S DMA clock */
  __HAL_RCC_DMA1_CLK_ENABLE(); 
  
	/* Configure the hdma_i2sTx handle parameters */   
	hdma_i2sTx.Init.Channel             = DMA_CHANNEL_0;  
	hdma_i2sTx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
	hdma_i2sTx.Init.PeriphInc           = DMA_PINC_DISABLE;
	hdma_i2sTx.Init.MemInc              = DMA_MINC_ENABLE;
	hdma_i2sTx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
	hdma_i2sTx.Init.MemDataAlignment    = DMA_MDATAALIGN_HALFWORD;
	hdma_i2sTx.Init.Mode                = DMA_CIRCULAR;
	hdma_i2sTx.Init.Priority            = DMA_PRIORITY_HIGH;
	hdma_i2sTx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;         
	hdma_i2sTx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_1QUARTERFULL;
	hdma_i2sTx.Init.MemBurst            = DMA_MBURST_SINGLE;
	hdma_i2sTx.Init.PeriphBurst         = DMA_PBURST_SINGLE; 
	hdma_i2sTx.Instance                 = DMA1_Stream4;

	/* Deinitialize the Stream for new transfer */
	HAL_DMA_DeInit(&hdma_i2sTx);
	
	hdma_i2sTx.XferCpltCallback 	= txDMAConvCplt;
	hdma_i2sTx.XferM1CpltCallback = txDMAConvCplt;
	
	/* Associate the DMA handle */
	__HAL_LINKDMA(&bsp_i2s2, hdmatx, hdma_i2sTx);
		
	/* Configure the DMA Stream */
	HAL_DMA_Init(&hdma_i2sTx);
 
	HAL_DMAEx_MultiBufferStart(&hdma_i2sTx, (uint32_t)buf0,(uint32_t)&bsp_i2s2.Instance->DR, (uint32_t)buf1,size);
	__HAL_DMA_DISABLE(&hdma_i2sTx);                         //先关闭接收DMA
	
}

/**
  * @brief  I2S输如DMA初始化
  * @param  None
  * @retval None
  */
void bsp_i2s2_InDMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t size)
{
  /* Enable the I2S DMA clock */
  __HAL_RCC_DMA1_CLK_ENABLE(); 
  
	/* Configure the hdma_i2sTx handle parameters */   
	hdma_i2sRx.Init.Channel             = DMA_CHANNEL_3;  
	hdma_i2sRx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
	hdma_i2sRx.Init.PeriphInc           = DMA_PINC_DISABLE;
	hdma_i2sRx.Init.MemInc              = DMA_MINC_ENABLE;
	hdma_i2sRx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
	hdma_i2sRx.Init.MemDataAlignment    = DMA_MDATAALIGN_HALFWORD;
	hdma_i2sRx.Init.Mode                = DMA_CIRCULAR;
	hdma_i2sRx.Init.Priority            = DMA_PRIORITY_MEDIUM;
	hdma_i2sRx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;         
	hdma_i2sRx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_1QUARTERFULL;
	hdma_i2sRx.Init.MemBurst            = DMA_MBURST_SINGLE;
	hdma_i2sRx.Init.PeriphBurst         = DMA_PBURST_SINGLE; 
	hdma_i2sRx.Instance                 = DMA1_Stream3;

	/* Deinitialize the Stream for new transfer */
	HAL_DMA_DeInit(&hdma_i2sRx);
	
	hdma_i2sRx.XferCpltCallback 				= rxDMAConvCplt;
	hdma_i2sRx.XferM1CpltCallback 			= rxDMAConvCplt;	
	
	/* Associate the DMA handle */
	__HAL_LINKDMA(&bsp_i2s2, hdmarx, hdma_i2sRx);
		
	/* Configure the DMA Stream */
	HAL_DMA_Init(&hdma_i2sRx);
 
	HAL_DMAEx_MultiBufferStart(&hdma_i2sRx,(uint32_t)&I2SxEXT(bsp_i2s2.Instance)->DR,(uint32_t)buf0,(uint32_t)buf1,size);
	__HAL_DMA_DISABLE(&hdma_i2sRx);                         //先关闭接收DMA

}

uint8_t i2s2GetTxflag(void)
{
	return (bsp_i2s2.hdmatx->Instance->CR & DMA_SxCR_CT) ? 1 : 0;
}

uint8_t i2s2GetRxflag(void)
{
	return (bsp_i2s2.hdmarx->Instance->CR & DMA_SxCR_CT) ? 1 : 0;
}


void bsp_i2s2_playStart(uint8_t itflag,uint8_t Prio)
{
	if(itflag == 1)
	{
		__HAL_DMA_CLEAR_FLAG(&hdma_i2sTx,DMA_FLAG_TCIF0_4);     
		__HAL_DMA_ENABLE_IT(&hdma_i2sTx,DMA_IT_TC);             //开启传输完成中断

		HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, Prio, 0);
		HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);
	}	
	__HAL_DMA_ENABLE(&hdma_i2sTx);
}


void bsp_i2s2_playStop(void)
{
	__HAL_DMA_DISABLE_IT(&hdma_i2sTx,DMA_IT_TC);             //开启传输完成中断
	__HAL_DMA_CLEAR_FLAG(&hdma_i2sTx,DMA_FLAG_TCIF0_4);
	__HAL_DMA_DISABLE(&hdma_i2sTx);                         //先关闭接收DMA
	HAL_NVIC_ClearPendingIRQ(DMA1_Stream4_IRQn); 
	HAL_NVIC_DisableIRQ(DMA1_Stream4_IRQn);
}


void bsp_i2s2_recStart(uint8_t itflag,uint8_t Prio)
{
	if(itflag == 1)
	{
		__HAL_DMA_CLEAR_FLAG(&hdma_i2sRx,DMA_FLAG_TCIF3_7); 
		__HAL_DMA_ENABLE_IT(&hdma_i2sRx,DMA_IT_TC);             //开启传输完成中断	

		HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, Prio, 0);
		HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);
	}			
	__HAL_DMA_ENABLE(&hdma_i2sRx);
}


void bsp_i2s2_recStop(void)
{
	__HAL_DMA_DISABLE_IT(&hdma_i2sRx,DMA_IT_TC);             //开启传输完成中断
	__HAL_DMA_CLEAR_FLAG(&hdma_i2sRx,DMA_FLAG_TCIF3_7);
	__HAL_DMA_DISABLE(&hdma_i2sRx);                         //先关闭接收DMA
	
	HAL_NVIC_ClearPendingIRQ(DMA1_Stream3_IRQn); 
	HAL_NVIC_DisableIRQ(DMA1_Stream3_IRQn);
}

/**
  * @brief This function handles DMA1 stream4 global interrupt.
  */
void DMA1_Stream3_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_i2sRx);
}

/**
  * @brief This function handles DMA1 stream4 global interrupt.
  */
void DMA1_Stream4_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_i2sTx);
}



/**
  * @brief  I2S引脚初始化函数
  * @param  None
  * @retval None
  */
void HAL_I2S_MspInit(I2S_HandleTypeDef *hi2s)
{
	GPIO_InitTypeDef  GPIO_InitStruct = {0};
	if(hi2s == &(bsp_i2s2))
	{
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		
		/* Enable I2S2 clock */
		__HAL_RCC_SPI2_CLK_ENABLE();

		GPIO_InitStruct.Pin         = GPIO_PIN_12 | GPIO_PIN_13 |GPIO_PIN_15; 
		GPIO_InitStruct.Mode        = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull        = GPIO_PULLUP;
		GPIO_InitStruct.Speed       = GPIO_SPEED_FAST;
		GPIO_InitStruct.Alternate   = GPIO_AF5_SPI2;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		GPIO_InitStruct.Pin         = GPIO_PIN_14; 
		GPIO_InitStruct.Alternate   = GPIO_AF6_I2S2ext;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		
		GPIO_InitStruct.Pin         = GPIO_PIN_6; 
		GPIO_InitStruct.Alternate   = GPIO_AF5_SPI2;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	} 
}

void HAL_I2S_MspDeInit(I2S_HandleTypeDef *hi2s)
{
	__HAL_RCC_GPIOC_CLK_DISABLE();
	__HAL_RCC_GPIOB_CLK_DISABLE();
	
	/* Enable I2S2 clock */
	__HAL_RCC_SPI2_CLK_DISABLE();

	HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6);
	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 |GPIO_PIN_15);
}

