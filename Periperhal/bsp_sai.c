#include "bsp_sai.h" 
#include "systemTime.h"


SAI_HandleTypeDef SAI1A_Handler;        //SAI1 Block A句柄
SAI_HandleTypeDef SAI1B_Handler;        //SAI1 Block B句柄
DMA_HandleTypeDef SAI1_TXDMA_Handler;   //DMA发送句柄
DMA_HandleTypeDef SAI1_RXDMA_Handler;   //DMA接收句柄


void SAIA_Init(uint32_t usAudioFreq)
{
    SAI1A_Handler.Instance=SAI1_Block_A; 

		/* Disable SAI peripheral */
		__HAL_SAI_DISABLE(&SAI1A_Handler);
	  
		HAL_SAI_DeInit(&SAI1A_Handler);    //清除以前的配置
	
		SAI1A_Handler.Init.AudioFrequency 	= usAudioFreq;
	
    SAI1A_Handler.Init.AudioMode			=	SAI_MODEMASTER_TX;                       //设置SAI1工作模式
    SAI1A_Handler.Init.Synchro				=	SAI_ASYNCHRONOUS;             //音频模块异步
    SAI1A_Handler.Init.OutputDrive		=	SAI_OUTPUTDRIVE_DISABLE;   //立即驱动音频模块输出
    SAI1A_Handler.Init.NoDivider			=	SAI_MASTERDIVIDER_ENABLE;   //使能主时钟分频器(MCKDIV)
    SAI1A_Handler.Init.FIFOThreshold	=	SAI_FIFOTHRESHOLD_FULL;  //设置FIFO阈值,1/4 FIFO
    SAI1A_Handler.Init.ClockSource		=	SAI_CLKSOURCE_PLLI2S;     //SIA时钟源为PLL2S
    SAI1A_Handler.Init.MonoStereoMode	=	SAI_STEREOMODE;        //立体声模式
    SAI1A_Handler.Init.Protocol				=	SAI_FREE_PROTOCOL;           //设置SAI1协议为:自由协议(支持I2S/LSB/MSB/TDM/PCM/DSP等协议)
    SAI1A_Handler.Init.DataSize				=	SAI_DATASIZE_16;                     //设置数据大小
    SAI1A_Handler.Init.FirstBit				=	SAI_FIRSTBIT_MSB;            //数据MSB位优先
    SAI1A_Handler.Init.ClockStrobing	=	SAI_CLOCKSTROBING_FALLINGEDGE;                   //数据在时钟的上升/下降沿选通
    	
		SAI1A_Handler.Init.CompandingMode = SAI_NOCOMPANDING;					//μ Law..A Law 
		SAI1A_Handler.Init.SynchroExt 		= SAI_SYNCEXT_DISABLE;	
		SAI1A_Handler.Init.TriState 			= SAI_OUTPUT_NOTRELEASED;	
	
    //帧设置
    SAI1A_Handler.FrameInit.FrameLength				=	64;                  //设置帧长度为64,左通道32个SCK,右通道32个SCK.
    SAI1A_Handler.FrameInit.ActiveFrameLength	=	32;            //设置帧同步有效电平长度,在I2S模式下=1/2帧长.
    SAI1A_Handler.FrameInit.FSDefinition			=	SAI_FS_CHANNEL_IDENTIFICATION;//FS信号为SOF信号+通道识别信号
    SAI1A_Handler.FrameInit.FSPolarity				=	SAI_FS_ACTIVE_LOW;    //FS低电平有效(下降沿)
    SAI1A_Handler.FrameInit.FSOffset					=	SAI_FS_BEFOREFIRSTBIT;  //在slot0的第一位的前一位使能FS,以匹配飞利浦标准	

    //SLOT设置
    SAI1A_Handler.SlotInit.FirstBitOffset			=	0;                 //slot偏移(FBOFF)为0
    SAI1A_Handler.SlotInit.SlotSize						=	SAI_SLOTSIZE_32B;        //slot大小为32位
    SAI1A_Handler.SlotInit.SlotNumber					=	2;                     //slot数为2个    
    SAI1A_Handler.SlotInit.SlotActive					=	SAI_SLOTACTIVE_0|SAI_SLOTACTIVE_1;//使能slot0和slot1
    
    HAL_SAI_Init(&SAI1A_Handler);
		__HAL_SAI_ENABLE(&SAI1A_Handler);
		SAI1A_Handler.Instance->CR1 |= SAI_xCR1_DMAEN;
}


//SAI Block B初始化
void SAIB_Init(uint32_t usAudioFreq)
{
    SAI1B_Handler.Instance=SAI1_Block_B; 

		/* Disable SAI peripheral */
		__HAL_SAI_DISABLE(&SAI1B_Handler);
	
    HAL_SAI_DeInit(&SAI1B_Handler);                         //清除以前的配置
	
		SAI1B_Handler.Init.AudioFrequency 	= usAudioFreq;
	
    SAI1B_Handler.Init.AudioMode				=	SAI_MODESLAVE_RX;                      //设置SAI1工作模式
    SAI1B_Handler.Init.Synchro					=	SAI_SYNCHRONOUS;             //音频模块同步
    SAI1B_Handler.Init.OutputDrive			=	SAI_OUTPUTDRIVE_DISABLE;  //立即驱动音频模块输出
    SAI1B_Handler.Init.NoDivider				=	SAI_MASTERDIVIDER_DISABLE;  //使能主时钟分频器(MCKDIV)
    SAI1B_Handler.Init.FIFOThreshold		=	SAI_FIFOTHRESHOLD_FULL; //设置FIFO阈值,1/4 FIFO
    SAI1B_Handler.Init.ClockSource			=	SAI_CLKSOURCE_PLLI2S;    //SIA时钟源为PLL2S
    SAI1B_Handler.Init.MonoStereoMode		=	SAI_STEREOMODE;       //立体声模式
    SAI1B_Handler.Init.Protocol					=	SAI_FREE_PROTOCOL;          //设置SAI1协议为:自由协议(支持I2S/LSB/MSB/TDM/PCM/DSP等协议)
    SAI1B_Handler.Init.DataSize					=	SAI_DATASIZE_16;                    //设置数据大小
    SAI1B_Handler.Init.FirstBit					=	SAI_FIRSTBIT_MSB;           //数据MSB位优先
    SAI1B_Handler.Init.ClockStrobing		=	SAI_CLOCKSTROBING_RISINGEDGE;                  //数据在时钟的上升/下降沿选通

		SAI1B_Handler.Init.CompandingMode 	= SAI_NOCOMPANDING;					//μ Law..A Law 
		SAI1B_Handler.Init.SynchroExt 			= SAI_SYNCEXT_DISABLE;	
		SAI1B_Handler.Init.TriState 				= SAI_OUTPUT_NOTRELEASED;
		
    //帧设置
    SAI1B_Handler.FrameInit.FrameLength					=	64;                 //设置帧长度为64,左通道32个SCK,右通道32个SCK.
    SAI1B_Handler.FrameInit.ActiveFrameLength		=	32;           //设置帧同步有效电平长度,在I2S模式下=1/2帧长.
    SAI1B_Handler.FrameInit.FSDefinition				=	SAI_FS_CHANNEL_IDENTIFICATION;//FS信号为SOF信号+通道识别信号
    SAI1B_Handler.FrameInit.FSPolarity					=	SAI_FS_ACTIVE_LOW;   //FS低电平有效(下降沿)
    SAI1B_Handler.FrameInit.FSOffset						=	SAI_FS_BEFOREFIRSTBIT; //在slot0的第一位的前一位使能FS,以匹配飞利浦标准	

    //SLOT设置
    SAI1B_Handler.SlotInit.FirstBitOffset				=	0;                //slot偏移(FBOFF)为0
    SAI1B_Handler.SlotInit.SlotSize							=	SAI_SLOTSIZE_32B;       //slot大小为32位
    SAI1B_Handler.SlotInit.SlotNumber						=	2;                    //slot数为2个    
    SAI1B_Handler.SlotInit.SlotActive						=	SAI_SLOTACTIVE_0|SAI_SLOTACTIVE_1;//使能slot0和slot1
    
    HAL_SAI_Init(&SAI1B_Handler);
		__HAL_SAI_ENABLE(&SAI1B_Handler);
		SAI1B_Handler.Instance->CR1 |= SAI_xCR1_DMAEN;
}

//SAI底层驱动，引脚配置，时钟使能
//此函数会被HAL_SAI_Init()调用
//hsdram:SAI句柄
void HAL_SAI_MspInit(SAI_HandleTypeDef *hsai)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_SAI1_CLK_ENABLE();                //使能SAI1时钟
    __HAL_RCC_GPIOE_CLK_ENABLE();               //使能GPIOE时钟
    
    //初始化PE2,3,4,5,6
    GPIO_Initure.Pin=GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;  
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;          //推挽复用
    GPIO_Initure.Pull=GPIO_PULLUP;              //上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;         //高速
    GPIO_Initure.Alternate=GPIO_AF6_SAI1;       //复用为SAI   
    HAL_GPIO_Init(GPIOE,&GPIO_Initure);         //初始化
}

//SAI Block A采样率设置
//采样率计算公式:
//MCKDIV!=0: Fs=SAI_CK_x/[512*MCKDIV]
//MCKDIV==0: Fs=SAI_CK_x/256
//SAI_CK_x=(HSE/pllm)*PLLI2SN/PLLI2SQ/(PLLI2SDIVQ+1)
//一般HSE=25Mhz
//pllm:在Stm32_Clock_Init设置的时候确定，一般是25
//PLLI2SN:一般是192~432 
//PLLI2SQ:2~15 
//PLLI2SDIVQ:0~31
//MCKDIV:0~15 
//SAI A分频系数表@pllm=8,HSE=25Mhz,即vco输入频率为1Mhz 
const uint16_t SAI_PSC_TBL[][5]=
{
	{800 ,344,7,0,12},	//8Khz采样率
	{1102,429,2,18,2},	//11.025Khz采样率 
	{1600,344,7, 0,6},	//16Khz采样率
	{2205,429,2,18,1},	//22.05Khz采样率
	{3200,344,7, 0,3},	//32Khz采样率
	{4410,429,2,18,0},	//44.1Khz采样率
	{4800,344,7, 0,2},	//48Khz采样率
	{8820,271,2, 2,1},	//88.2Khz采样率
	{9600,344,7, 0,1},	//96Khz采样率
	{17640,271,2,2,0},	//176.4Khz采样率 
	{19200,344,7,0,0},	//192Khz采样率
};  

//设置SAIA的采样率(@MCKEN)
//samplerate:采样率,单位:Hz
//返回值:0,设置成功;1,无法设置.
uint8_t SAIA_SampleRate_Set(uint32_t samplerate)
{   
		uint8_t i=0; 

		RCC_PeriphCLKInitTypeDef RCCSAI1_Sture;  

		HAL_RCCEx_GetPeriphCLKConfig(&RCCSAI1_Sture);

		for(i=0;i<(sizeof(SAI_PSC_TBL)/10);i++)//看看改采样率是否可以支持
		{
			if((samplerate/10)==SAI_PSC_TBL[i][0])
				break;
		}
		if(i==(sizeof(SAI_PSC_TBL)/10))
			return 1;//搜遍了也找不到
		RCCSAI1_Sture.PeriphClockSelection=RCC_PERIPHCLK_SAI_PLLI2S;    //外设时钟源选择 
		RCCSAI1_Sture.PLLI2S.PLLI2SN=(uint32_t)SAI_PSC_TBL[i][1];            //设置PLLI2SN
		RCCSAI1_Sture.PLLI2S.PLLI2SQ=(uint32_t)SAI_PSC_TBL[i][2];            //设置PLLI2SQ
		//设置PLLI2SDivQ的时候SAI_PSC_TBL[i][3]要加1，因为HAL库中会在把PLLI2SDivQ赋给寄存器DCKCFGR的时候减1 
		RCCSAI1_Sture.PLLI2SDivQ=SAI_PSC_TBL[i][3]+1;                   //设置PLLI2SDIVQ
		HAL_RCCEx_PeriphCLKConfig(&RCCSAI1_Sture);                      //设置时钟
		
    __HAL_RCC_SAI_BLOCKACLKSOURCE_CONFIG(RCC_SAIACLKSOURCE_PLLI2S); //设置SAI1时钟来源为PLLI2SQ		
    __HAL_RCC_SAI_BLOCKBCLKSOURCE_CONFIG(RCC_SAIACLKSOURCE_PLLI2S); //设置SAI1时钟来源为PLLI2SQ		
		
		__HAL_SAI_DISABLE(&SAI1A_Handler);                          //关闭SAI

		return 0;
} 

__weak void saiTxDMA_ConvCplt(DMA_HandleTypeDef *hdma){}
__weak void saiTxDMA_M1ConvCplt(DMA_HandleTypeDef *hdma){}
__weak void saiRxDMA_ConvCplt(DMA_HandleTypeDef *hdma){}
__weak void saiRxDMA_M1ConvCplt(DMA_HandleTypeDef *hdma){}
		

//SAIA TX DMA配置
//设置为双缓冲模式,并开启DMA传输完成中断
//buf0:M0AR地址.
//buf1:M1AR地址.
//num:每次传输数据量
//width:位宽(存储器和外设,同时设置),0,8位;1,16位;2,32位;
void SAIA_TX_DMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t num,uint8_t width)
{ 
    uint32_t memwidth=0,perwidth=0;      //外设和存储器位宽
    switch(width)
    {
        case 0:         //8位
            memwidth=DMA_MDATAALIGN_BYTE;
            perwidth=DMA_PDATAALIGN_BYTE;
            break;
        case 1:         //16位
            memwidth=DMA_MDATAALIGN_HALFWORD;
            perwidth=DMA_PDATAALIGN_HALFWORD;
            break;
        case 2:         //32位
            memwidth=DMA_MDATAALIGN_WORD;
            perwidth=DMA_PDATAALIGN_WORD;
            break;
            
    }
    __HAL_RCC_DMA2_CLK_ENABLE();                                    //使能DMA2时钟
    
		SAI1_TXDMA_Handler.Instance=DMA2_Stream1;                       //DMA2数据流3                     
    SAI1_TXDMA_Handler.Init.Channel=DMA_CHANNEL_0;                  //通道0
    SAI1_TXDMA_Handler.Init.Direction=DMA_MEMORY_TO_PERIPH;         //存储器到外设模式
    SAI1_TXDMA_Handler.Init.PeriphInc=DMA_PINC_DISABLE;             //外设非增量模式
    SAI1_TXDMA_Handler.Init.MemInc=DMA_MINC_ENABLE;                 //存储器增量模式
    SAI1_TXDMA_Handler.Init.PeriphDataAlignment=perwidth;           //外设数据长度:16/32位
    SAI1_TXDMA_Handler.Init.MemDataAlignment=memwidth;              //存储器数据长度:16/32位
    SAI1_TXDMA_Handler.Init.Mode=DMA_CIRCULAR;                      //使用循环模式 
    SAI1_TXDMA_Handler.Init.Priority=DMA_PRIORITY_HIGH;             //高优先级
    SAI1_TXDMA_Handler.Init.FIFOMode=DMA_FIFOMODE_DISABLE;          //不使用FIFO
    SAI1_TXDMA_Handler.Init.MemBurst=DMA_MBURST_SINGLE;             //存储器单次突发传输
    SAI1_TXDMA_Handler.Init.PeriphBurst=DMA_PBURST_SINGLE;          //外设突发单次传输 
    
		HAL_DMA_DeInit(&SAI1_TXDMA_Handler);                            //先清除以前的设置
    
		SAI1_TXDMA_Handler.XferCpltCallback = saiTxDMA_ConvCplt;
		SAI1_TXDMA_Handler.XferM1CpltCallback = saiTxDMA_M1ConvCplt;
		
		HAL_DMA_Init(&SAI1_TXDMA_Handler);	                            //初始化DMA
		
		__HAL_LINKDMA(&SAI1A_Handler,hdmatx,SAI1_TXDMA_Handler);        //将DMA与SAI联系起来
    
    HAL_DMAEx_MultiBufferStart(&SAI1_TXDMA_Handler,(uint32_t)buf0,(uint32_t)&SAI1_Block_A->DR,(uint32_t)buf1,num);//开启双缓冲
    __HAL_DMA_DISABLE(&SAI1_TXDMA_Handler);                         //先关闭发送DMA
    
}


//SAIA TX DMA配置
//设置为双缓冲模式,并开启DMA传输完成中断
//buf0:M0AR地址.
//buf1:M1AR地址.
//num:每次传输数据量
//width:位宽(存储器和外设,同时设置),0,8位;1,16位;2,32位;
void SAIA_RX_DMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t num,uint8_t width)
{ 
    uint32_t memwidth=0,perwidth=0;      //外设和存储器位宽
    switch(width)
    {
        case 0:         //8位
            memwidth=DMA_MDATAALIGN_BYTE;
            perwidth=DMA_PDATAALIGN_BYTE;
            break;
        case 1:         //16位
            memwidth=DMA_MDATAALIGN_HALFWORD;
            perwidth=DMA_PDATAALIGN_HALFWORD;
            break;
        case 2:         //32位
            memwidth=DMA_MDATAALIGN_WORD;
            perwidth=DMA_PDATAALIGN_WORD;
            break;
            
    }
    __HAL_RCC_DMA2_CLK_ENABLE();                                    //使能DMA2时钟
    
    SAI1_RXDMA_Handler.Instance=DMA2_Stream5;                       //DMA2数据流5                     
    SAI1_RXDMA_Handler.Init.Channel=DMA_CHANNEL_0;                  //通道0
    SAI1_RXDMA_Handler.Init.Direction=DMA_PERIPH_TO_MEMORY;         //外设到存储器模式
    SAI1_RXDMA_Handler.Init.PeriphInc=DMA_PINC_DISABLE;             //外设非增量模式
    SAI1_RXDMA_Handler.Init.MemInc=DMA_MINC_ENABLE;                 //存储器增量模式
    SAI1_RXDMA_Handler.Init.PeriphDataAlignment=perwidth;           //外设数据长度:16/32位
    SAI1_RXDMA_Handler.Init.MemDataAlignment=memwidth;              //存储器数据长度:16/32位
    SAI1_RXDMA_Handler.Init.Mode=DMA_CIRCULAR;                      //使用循环模式 
    SAI1_RXDMA_Handler.Init.Priority=DMA_PRIORITY_MEDIUM;           //中等优先级
    SAI1_RXDMA_Handler.Init.FIFOMode=DMA_FIFOMODE_DISABLE;          //不使用FIFO
    SAI1_RXDMA_Handler.Init.MemBurst=DMA_MBURST_SINGLE;             //存储器单次突发传输
    SAI1_RXDMA_Handler.Init.PeriphBurst=DMA_PBURST_SINGLE;          //外设突发单次传输 
    
		HAL_DMA_DeInit(&SAI1_RXDMA_Handler);                            //先清除以前的设置
		
		SAI1_RXDMA_Handler.XferCpltCallback = saiRxDMA_ConvCplt;
		SAI1_RXDMA_Handler.XferM1CpltCallback = saiRxDMA_M1ConvCplt;
    
		__HAL_LINKDMA(&SAI1B_Handler,hdmarx,SAI1_RXDMA_Handler);        //将DMA与SAI联系起来
		
		HAL_DMA_Init(&SAI1_RXDMA_Handler);	                            //初始化DMA
    
    HAL_DMAEx_MultiBufferStart(&SAI1_RXDMA_Handler,(uint32_t)&SAI1_Block_B->DR,(uint32_t)buf0,(uint32_t)buf1,num);//开启双缓冲
    
		__HAL_DMA_DISABLE(&SAI1_RXDMA_Handler);                         //先关闭接收DMA
}


uint8_t SAIGetTxflag(void)
{
	return (SAI1A_Handler.hdmatx->Instance->CR & DMA_SxCR_CT) ? 1 : 0;
}


uint8_t SAIGetRxflag(void)
{
	return (SAI1B_Handler.hdmarx->Instance->CR & DMA_SxCR_CT) ? 1 : 0;
}

//DMA2_Stream1中断服务函数
void DMA2_Stream1_IRQHandler(void)
{   
		HAL_DMA_IRQHandler(&SAI1_TXDMA_Handler);
}   

//DMA2_Stream5中断服务函数
void DMA2_Stream5_IRQHandler(void)
{  
	  HAL_DMA_IRQHandler(&SAI1_RXDMA_Handler);
}  

//SAI开始播放
void SAI_Play_Start(uint8_t itflag,uint8_t Prio)
{   	
		if(itflag == 1)
		{
			__HAL_DMA_CLEAR_FLAG(&SAI1_TXDMA_Handler , 0x3F << SAI1_TXDMA_Handler.StreamIndex); 
			__HAL_DMA_ENABLE_IT(&SAI1_TXDMA_Handler , DMA_IT_TC);             //开启传输完成中断	

			HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, Prio, 0);
			HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);
		}			
		
		__HAL_DMA_ENABLE(&SAI1_TXDMA_Handler);		
}


//关闭I2S播放
void SAI_Play_Stop(void)
{   
		__HAL_DMA_DISABLE_IT(&SAI1_TXDMA_Handler,DMA_IT_TC);             //开启传输完成中断
		__HAL_DMA_CLEAR_FLAG(&SAI1_TXDMA_Handler,0x3F << SAI1_TXDMA_Handler.StreamIndex);
		__HAL_DMA_DISABLE(&SAI1_TXDMA_Handler);                         //先关闭接收DMA
		
		HAL_NVIC_ClearPendingIRQ(DMA2_Stream1_IRQn); 
		HAL_NVIC_DisableIRQ(DMA2_Stream1_IRQn);       
} 

//SAI开始录音
void SAI_Rec_Start(uint8_t itflag,uint8_t Prio)
{ 
		if(itflag == 1)
		{
			__HAL_DMA_CLEAR_FLAG(&SAI1_RXDMA_Handler , 0x3F << SAI1_TXDMA_Handler.StreamIndex); 
			__HAL_DMA_ENABLE_IT(&SAI1_RXDMA_Handler , DMA_IT_TC);             //开启传输完成中断	

			HAL_NVIC_SetPriority(DMA2_Stream5_IRQn, Prio, 0);
			HAL_NVIC_EnableIRQ(DMA2_Stream5_IRQn);
		}			
		
		__HAL_DMA_ENABLE(&SAI1_RXDMA_Handler);

}

//关闭SAI录音
void SAI_Rec_Stop(void)
{   
	__HAL_DMA_DISABLE_IT(&SAI1_RXDMA_Handler,DMA_IT_TC);             //开启传输完成中断
	__HAL_DMA_CLEAR_FLAG(&SAI1_RXDMA_Handler,0x3F << SAI1_TXDMA_Handler.StreamIndex);
	__HAL_DMA_DISABLE(&SAI1_RXDMA_Handler);                         //先关闭接收DMA
	
	HAL_NVIC_ClearPendingIRQ(DMA2_Stream5_IRQn); 
	HAL_NVIC_DisableIRQ(DMA2_Stream5_IRQn);

}









