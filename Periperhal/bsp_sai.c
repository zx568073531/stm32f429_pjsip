#include "bsp_sai.h" 
#include "systemTime.h"


SAI_HandleTypeDef SAI1A_Handler;        //SAI1 Block A���
SAI_HandleTypeDef SAI1B_Handler;        //SAI1 Block B���
DMA_HandleTypeDef SAI1_TXDMA_Handler;   //DMA���;��
DMA_HandleTypeDef SAI1_RXDMA_Handler;   //DMA���վ��


void SAIA_Init(uint32_t usAudioFreq)
{
    SAI1A_Handler.Instance=SAI1_Block_A; 

		/* Disable SAI peripheral */
		__HAL_SAI_DISABLE(&SAI1A_Handler);
	  
		HAL_SAI_DeInit(&SAI1A_Handler);    //�����ǰ������
	
		SAI1A_Handler.Init.AudioFrequency 	= usAudioFreq;
	
    SAI1A_Handler.Init.AudioMode			=	SAI_MODEMASTER_TX;                       //����SAI1����ģʽ
    SAI1A_Handler.Init.Synchro				=	SAI_ASYNCHRONOUS;             //��Ƶģ���첽
    SAI1A_Handler.Init.OutputDrive		=	SAI_OUTPUTDRIVE_DISABLE;   //����������Ƶģ�����
    SAI1A_Handler.Init.NoDivider			=	SAI_MASTERDIVIDER_ENABLE;   //ʹ����ʱ�ӷ�Ƶ��(MCKDIV)
    SAI1A_Handler.Init.FIFOThreshold	=	SAI_FIFOTHRESHOLD_FULL;  //����FIFO��ֵ,1/4 FIFO
    SAI1A_Handler.Init.ClockSource		=	SAI_CLKSOURCE_PLLI2S;     //SIAʱ��ԴΪPLL2S
    SAI1A_Handler.Init.MonoStereoMode	=	SAI_STEREOMODE;        //������ģʽ
    SAI1A_Handler.Init.Protocol				=	SAI_FREE_PROTOCOL;           //����SAI1Э��Ϊ:����Э��(֧��I2S/LSB/MSB/TDM/PCM/DSP��Э��)
    SAI1A_Handler.Init.DataSize				=	SAI_DATASIZE_16;                     //�������ݴ�С
    SAI1A_Handler.Init.FirstBit				=	SAI_FIRSTBIT_MSB;            //����MSBλ����
    SAI1A_Handler.Init.ClockStrobing	=	SAI_CLOCKSTROBING_FALLINGEDGE;                   //������ʱ�ӵ�����/�½���ѡͨ
    	
		SAI1A_Handler.Init.CompandingMode = SAI_NOCOMPANDING;					//�� Law..A Law 
		SAI1A_Handler.Init.SynchroExt 		= SAI_SYNCEXT_DISABLE;	
		SAI1A_Handler.Init.TriState 			= SAI_OUTPUT_NOTRELEASED;	
	
    //֡����
    SAI1A_Handler.FrameInit.FrameLength				=	64;                  //����֡����Ϊ64,��ͨ��32��SCK,��ͨ��32��SCK.
    SAI1A_Handler.FrameInit.ActiveFrameLength	=	32;            //����֡ͬ����Ч��ƽ����,��I2Sģʽ��=1/2֡��.
    SAI1A_Handler.FrameInit.FSDefinition			=	SAI_FS_CHANNEL_IDENTIFICATION;//FS�ź�ΪSOF�ź�+ͨ��ʶ���ź�
    SAI1A_Handler.FrameInit.FSPolarity				=	SAI_FS_ACTIVE_LOW;    //FS�͵�ƽ��Ч(�½���)
    SAI1A_Handler.FrameInit.FSOffset					=	SAI_FS_BEFOREFIRSTBIT;  //��slot0�ĵ�һλ��ǰһλʹ��FS,��ƥ������ֱ�׼	

    //SLOT����
    SAI1A_Handler.SlotInit.FirstBitOffset			=	0;                 //slotƫ��(FBOFF)Ϊ0
    SAI1A_Handler.SlotInit.SlotSize						=	SAI_SLOTSIZE_32B;        //slot��СΪ32λ
    SAI1A_Handler.SlotInit.SlotNumber					=	2;                     //slot��Ϊ2��    
    SAI1A_Handler.SlotInit.SlotActive					=	SAI_SLOTACTIVE_0|SAI_SLOTACTIVE_1;//ʹ��slot0��slot1
    
    HAL_SAI_Init(&SAI1A_Handler);
		__HAL_SAI_ENABLE(&SAI1A_Handler);
		SAI1A_Handler.Instance->CR1 |= SAI_xCR1_DMAEN;
}


//SAI Block B��ʼ��
void SAIB_Init(uint32_t usAudioFreq)
{
    SAI1B_Handler.Instance=SAI1_Block_B; 

		/* Disable SAI peripheral */
		__HAL_SAI_DISABLE(&SAI1B_Handler);
	
    HAL_SAI_DeInit(&SAI1B_Handler);                         //�����ǰ������
	
		SAI1B_Handler.Init.AudioFrequency 	= usAudioFreq;
	
    SAI1B_Handler.Init.AudioMode				=	SAI_MODESLAVE_RX;                      //����SAI1����ģʽ
    SAI1B_Handler.Init.Synchro					=	SAI_SYNCHRONOUS;             //��Ƶģ��ͬ��
    SAI1B_Handler.Init.OutputDrive			=	SAI_OUTPUTDRIVE_DISABLE;  //����������Ƶģ�����
    SAI1B_Handler.Init.NoDivider				=	SAI_MASTERDIVIDER_DISABLE;  //ʹ����ʱ�ӷ�Ƶ��(MCKDIV)
    SAI1B_Handler.Init.FIFOThreshold		=	SAI_FIFOTHRESHOLD_FULL; //����FIFO��ֵ,1/4 FIFO
    SAI1B_Handler.Init.ClockSource			=	SAI_CLKSOURCE_PLLI2S;    //SIAʱ��ԴΪPLL2S
    SAI1B_Handler.Init.MonoStereoMode		=	SAI_STEREOMODE;       //������ģʽ
    SAI1B_Handler.Init.Protocol					=	SAI_FREE_PROTOCOL;          //����SAI1Э��Ϊ:����Э��(֧��I2S/LSB/MSB/TDM/PCM/DSP��Э��)
    SAI1B_Handler.Init.DataSize					=	SAI_DATASIZE_16;                    //�������ݴ�С
    SAI1B_Handler.Init.FirstBit					=	SAI_FIRSTBIT_MSB;           //����MSBλ����
    SAI1B_Handler.Init.ClockStrobing		=	SAI_CLOCKSTROBING_RISINGEDGE;                  //������ʱ�ӵ�����/�½���ѡͨ

		SAI1B_Handler.Init.CompandingMode 	= SAI_NOCOMPANDING;					//�� Law..A Law 
		SAI1B_Handler.Init.SynchroExt 			= SAI_SYNCEXT_DISABLE;	
		SAI1B_Handler.Init.TriState 				= SAI_OUTPUT_NOTRELEASED;
		
    //֡����
    SAI1B_Handler.FrameInit.FrameLength					=	64;                 //����֡����Ϊ64,��ͨ��32��SCK,��ͨ��32��SCK.
    SAI1B_Handler.FrameInit.ActiveFrameLength		=	32;           //����֡ͬ����Ч��ƽ����,��I2Sģʽ��=1/2֡��.
    SAI1B_Handler.FrameInit.FSDefinition				=	SAI_FS_CHANNEL_IDENTIFICATION;//FS�ź�ΪSOF�ź�+ͨ��ʶ���ź�
    SAI1B_Handler.FrameInit.FSPolarity					=	SAI_FS_ACTIVE_LOW;   //FS�͵�ƽ��Ч(�½���)
    SAI1B_Handler.FrameInit.FSOffset						=	SAI_FS_BEFOREFIRSTBIT; //��slot0�ĵ�һλ��ǰһλʹ��FS,��ƥ������ֱ�׼	

    //SLOT����
    SAI1B_Handler.SlotInit.FirstBitOffset				=	0;                //slotƫ��(FBOFF)Ϊ0
    SAI1B_Handler.SlotInit.SlotSize							=	SAI_SLOTSIZE_32B;       //slot��СΪ32λ
    SAI1B_Handler.SlotInit.SlotNumber						=	2;                    //slot��Ϊ2��    
    SAI1B_Handler.SlotInit.SlotActive						=	SAI_SLOTACTIVE_0|SAI_SLOTACTIVE_1;//ʹ��slot0��slot1
    
    HAL_SAI_Init(&SAI1B_Handler);
		__HAL_SAI_ENABLE(&SAI1B_Handler);
		SAI1B_Handler.Instance->CR1 |= SAI_xCR1_DMAEN;
}

//SAI�ײ��������������ã�ʱ��ʹ��
//�˺����ᱻHAL_SAI_Init()����
//hsdram:SAI���
void HAL_SAI_MspInit(SAI_HandleTypeDef *hsai)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_SAI1_CLK_ENABLE();                //ʹ��SAI1ʱ��
    __HAL_RCC_GPIOE_CLK_ENABLE();               //ʹ��GPIOEʱ��
    
    //��ʼ��PE2,3,4,5,6
    GPIO_Initure.Pin=GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;  
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;          //���츴��
    GPIO_Initure.Pull=GPIO_PULLUP;              //����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;         //����
    GPIO_Initure.Alternate=GPIO_AF6_SAI1;       //����ΪSAI   
    HAL_GPIO_Init(GPIOE,&GPIO_Initure);         //��ʼ��
}

//SAI Block A����������
//�����ʼ��㹫ʽ:
//MCKDIV!=0: Fs=SAI_CK_x/[512*MCKDIV]
//MCKDIV==0: Fs=SAI_CK_x/256
//SAI_CK_x=(HSE/pllm)*PLLI2SN/PLLI2SQ/(PLLI2SDIVQ+1)
//һ��HSE=25Mhz
//pllm:��Stm32_Clock_Init���õ�ʱ��ȷ����һ����25
//PLLI2SN:һ����192~432 
//PLLI2SQ:2~15 
//PLLI2SDIVQ:0~31
//MCKDIV:0~15 
//SAI A��Ƶϵ����@pllm=8,HSE=25Mhz,��vco����Ƶ��Ϊ1Mhz 
const uint16_t SAI_PSC_TBL[][5]=
{
	{800 ,344,7,0,12},	//8Khz������
	{1102,429,2,18,2},	//11.025Khz������ 
	{1600,344,7, 0,6},	//16Khz������
	{2205,429,2,18,1},	//22.05Khz������
	{3200,344,7, 0,3},	//32Khz������
	{4410,429,2,18,0},	//44.1Khz������
	{4800,344,7, 0,2},	//48Khz������
	{8820,271,2, 2,1},	//88.2Khz������
	{9600,344,7, 0,1},	//96Khz������
	{17640,271,2,2,0},	//176.4Khz������ 
	{19200,344,7,0,0},	//192Khz������
};  

//����SAIA�Ĳ�����(@MCKEN)
//samplerate:������,��λ:Hz
//����ֵ:0,���óɹ�;1,�޷�����.
uint8_t SAIA_SampleRate_Set(uint32_t samplerate)
{   
		uint8_t i=0; 

		RCC_PeriphCLKInitTypeDef RCCSAI1_Sture;  

		HAL_RCCEx_GetPeriphCLKConfig(&RCCSAI1_Sture);

		for(i=0;i<(sizeof(SAI_PSC_TBL)/10);i++)//�����Ĳ������Ƿ����֧��
		{
			if((samplerate/10)==SAI_PSC_TBL[i][0])
				break;
		}
		if(i==(sizeof(SAI_PSC_TBL)/10))
			return 1;//�ѱ���Ҳ�Ҳ���
		RCCSAI1_Sture.PeriphClockSelection=RCC_PERIPHCLK_SAI_PLLI2S;    //����ʱ��Դѡ�� 
		RCCSAI1_Sture.PLLI2S.PLLI2SN=(uint32_t)SAI_PSC_TBL[i][1];            //����PLLI2SN
		RCCSAI1_Sture.PLLI2S.PLLI2SQ=(uint32_t)SAI_PSC_TBL[i][2];            //����PLLI2SQ
		//����PLLI2SDivQ��ʱ��SAI_PSC_TBL[i][3]Ҫ��1����ΪHAL���л��ڰ�PLLI2SDivQ�����Ĵ���DCKCFGR��ʱ���1 
		RCCSAI1_Sture.PLLI2SDivQ=SAI_PSC_TBL[i][3]+1;                   //����PLLI2SDIVQ
		HAL_RCCEx_PeriphCLKConfig(&RCCSAI1_Sture);                      //����ʱ��
		
    __HAL_RCC_SAI_BLOCKACLKSOURCE_CONFIG(RCC_SAIACLKSOURCE_PLLI2S); //����SAI1ʱ����ԴΪPLLI2SQ		
    __HAL_RCC_SAI_BLOCKBCLKSOURCE_CONFIG(RCC_SAIACLKSOURCE_PLLI2S); //����SAI1ʱ����ԴΪPLLI2SQ		
		
		__HAL_SAI_DISABLE(&SAI1A_Handler);                          //�ر�SAI

		return 0;
} 

__weak void saiTxDMA_ConvCplt(DMA_HandleTypeDef *hdma){}
__weak void saiTxDMA_M1ConvCplt(DMA_HandleTypeDef *hdma){}
__weak void saiRxDMA_ConvCplt(DMA_HandleTypeDef *hdma){}
__weak void saiRxDMA_M1ConvCplt(DMA_HandleTypeDef *hdma){}
		

//SAIA TX DMA����
//����Ϊ˫����ģʽ,������DMA��������ж�
//buf0:M0AR��ַ.
//buf1:M1AR��ַ.
//num:ÿ�δ���������
//width:λ��(�洢��������,ͬʱ����),0,8λ;1,16λ;2,32λ;
void SAIA_TX_DMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t num,uint8_t width)
{ 
    uint32_t memwidth=0,perwidth=0;      //����ʹ洢��λ��
    switch(width)
    {
        case 0:         //8λ
            memwidth=DMA_MDATAALIGN_BYTE;
            perwidth=DMA_PDATAALIGN_BYTE;
            break;
        case 1:         //16λ
            memwidth=DMA_MDATAALIGN_HALFWORD;
            perwidth=DMA_PDATAALIGN_HALFWORD;
            break;
        case 2:         //32λ
            memwidth=DMA_MDATAALIGN_WORD;
            perwidth=DMA_PDATAALIGN_WORD;
            break;
            
    }
    __HAL_RCC_DMA2_CLK_ENABLE();                                    //ʹ��DMA2ʱ��
    
		SAI1_TXDMA_Handler.Instance=DMA2_Stream1;                       //DMA2������3                     
    SAI1_TXDMA_Handler.Init.Channel=DMA_CHANNEL_0;                  //ͨ��0
    SAI1_TXDMA_Handler.Init.Direction=DMA_MEMORY_TO_PERIPH;         //�洢��������ģʽ
    SAI1_TXDMA_Handler.Init.PeriphInc=DMA_PINC_DISABLE;             //���������ģʽ
    SAI1_TXDMA_Handler.Init.MemInc=DMA_MINC_ENABLE;                 //�洢������ģʽ
    SAI1_TXDMA_Handler.Init.PeriphDataAlignment=perwidth;           //�������ݳ���:16/32λ
    SAI1_TXDMA_Handler.Init.MemDataAlignment=memwidth;              //�洢�����ݳ���:16/32λ
    SAI1_TXDMA_Handler.Init.Mode=DMA_CIRCULAR;                      //ʹ��ѭ��ģʽ 
    SAI1_TXDMA_Handler.Init.Priority=DMA_PRIORITY_HIGH;             //�����ȼ�
    SAI1_TXDMA_Handler.Init.FIFOMode=DMA_FIFOMODE_DISABLE;          //��ʹ��FIFO
    SAI1_TXDMA_Handler.Init.MemBurst=DMA_MBURST_SINGLE;             //�洢������ͻ������
    SAI1_TXDMA_Handler.Init.PeriphBurst=DMA_PBURST_SINGLE;          //����ͻ�����δ��� 
    
		HAL_DMA_DeInit(&SAI1_TXDMA_Handler);                            //�������ǰ������
    
		SAI1_TXDMA_Handler.XferCpltCallback = saiTxDMA_ConvCplt;
		SAI1_TXDMA_Handler.XferM1CpltCallback = saiTxDMA_M1ConvCplt;
		
		HAL_DMA_Init(&SAI1_TXDMA_Handler);	                            //��ʼ��DMA
		
		__HAL_LINKDMA(&SAI1A_Handler,hdmatx,SAI1_TXDMA_Handler);        //��DMA��SAI��ϵ����
    
    HAL_DMAEx_MultiBufferStart(&SAI1_TXDMA_Handler,(uint32_t)buf0,(uint32_t)&SAI1_Block_A->DR,(uint32_t)buf1,num);//����˫����
    __HAL_DMA_DISABLE(&SAI1_TXDMA_Handler);                         //�ȹرշ���DMA
    
}


//SAIA TX DMA����
//����Ϊ˫����ģʽ,������DMA��������ж�
//buf0:M0AR��ַ.
//buf1:M1AR��ַ.
//num:ÿ�δ���������
//width:λ��(�洢��������,ͬʱ����),0,8λ;1,16λ;2,32λ;
void SAIA_RX_DMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t num,uint8_t width)
{ 
    uint32_t memwidth=0,perwidth=0;      //����ʹ洢��λ��
    switch(width)
    {
        case 0:         //8λ
            memwidth=DMA_MDATAALIGN_BYTE;
            perwidth=DMA_PDATAALIGN_BYTE;
            break;
        case 1:         //16λ
            memwidth=DMA_MDATAALIGN_HALFWORD;
            perwidth=DMA_PDATAALIGN_HALFWORD;
            break;
        case 2:         //32λ
            memwidth=DMA_MDATAALIGN_WORD;
            perwidth=DMA_PDATAALIGN_WORD;
            break;
            
    }
    __HAL_RCC_DMA2_CLK_ENABLE();                                    //ʹ��DMA2ʱ��
    
    SAI1_RXDMA_Handler.Instance=DMA2_Stream5;                       //DMA2������5                     
    SAI1_RXDMA_Handler.Init.Channel=DMA_CHANNEL_0;                  //ͨ��0
    SAI1_RXDMA_Handler.Init.Direction=DMA_PERIPH_TO_MEMORY;         //���赽�洢��ģʽ
    SAI1_RXDMA_Handler.Init.PeriphInc=DMA_PINC_DISABLE;             //���������ģʽ
    SAI1_RXDMA_Handler.Init.MemInc=DMA_MINC_ENABLE;                 //�洢������ģʽ
    SAI1_RXDMA_Handler.Init.PeriphDataAlignment=perwidth;           //�������ݳ���:16/32λ
    SAI1_RXDMA_Handler.Init.MemDataAlignment=memwidth;              //�洢�����ݳ���:16/32λ
    SAI1_RXDMA_Handler.Init.Mode=DMA_CIRCULAR;                      //ʹ��ѭ��ģʽ 
    SAI1_RXDMA_Handler.Init.Priority=DMA_PRIORITY_MEDIUM;           //�е����ȼ�
    SAI1_RXDMA_Handler.Init.FIFOMode=DMA_FIFOMODE_DISABLE;          //��ʹ��FIFO
    SAI1_RXDMA_Handler.Init.MemBurst=DMA_MBURST_SINGLE;             //�洢������ͻ������
    SAI1_RXDMA_Handler.Init.PeriphBurst=DMA_PBURST_SINGLE;          //����ͻ�����δ��� 
    
		HAL_DMA_DeInit(&SAI1_RXDMA_Handler);                            //�������ǰ������
		
		SAI1_RXDMA_Handler.XferCpltCallback = saiRxDMA_ConvCplt;
		SAI1_RXDMA_Handler.XferM1CpltCallback = saiRxDMA_M1ConvCplt;
    
		__HAL_LINKDMA(&SAI1B_Handler,hdmarx,SAI1_RXDMA_Handler);        //��DMA��SAI��ϵ����
		
		HAL_DMA_Init(&SAI1_RXDMA_Handler);	                            //��ʼ��DMA
    
    HAL_DMAEx_MultiBufferStart(&SAI1_RXDMA_Handler,(uint32_t)&SAI1_Block_B->DR,(uint32_t)buf0,(uint32_t)buf1,num);//����˫����
    
		__HAL_DMA_DISABLE(&SAI1_RXDMA_Handler);                         //�ȹرս���DMA
}


uint8_t SAIGetTxflag(void)
{
	return (SAI1A_Handler.hdmatx->Instance->CR & DMA_SxCR_CT) ? 1 : 0;
}


uint8_t SAIGetRxflag(void)
{
	return (SAI1B_Handler.hdmarx->Instance->CR & DMA_SxCR_CT) ? 1 : 0;
}

//DMA2_Stream1�жϷ�����
void DMA2_Stream1_IRQHandler(void)
{   
		HAL_DMA_IRQHandler(&SAI1_TXDMA_Handler);
}   

//DMA2_Stream5�жϷ�����
void DMA2_Stream5_IRQHandler(void)
{  
	  HAL_DMA_IRQHandler(&SAI1_RXDMA_Handler);
}  

//SAI��ʼ����
void SAI_Play_Start(uint8_t itflag,uint8_t Prio)
{   	
		if(itflag == 1)
		{
			__HAL_DMA_CLEAR_FLAG(&SAI1_TXDMA_Handler , 0x3F << SAI1_TXDMA_Handler.StreamIndex); 
			__HAL_DMA_ENABLE_IT(&SAI1_TXDMA_Handler , DMA_IT_TC);             //������������ж�	

			HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, Prio, 0);
			HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);
		}			
		
		__HAL_DMA_ENABLE(&SAI1_TXDMA_Handler);		
}


//�ر�I2S����
void SAI_Play_Stop(void)
{   
		__HAL_DMA_DISABLE_IT(&SAI1_TXDMA_Handler,DMA_IT_TC);             //������������ж�
		__HAL_DMA_CLEAR_FLAG(&SAI1_TXDMA_Handler,0x3F << SAI1_TXDMA_Handler.StreamIndex);
		__HAL_DMA_DISABLE(&SAI1_TXDMA_Handler);                         //�ȹرս���DMA
		
		HAL_NVIC_ClearPendingIRQ(DMA2_Stream1_IRQn); 
		HAL_NVIC_DisableIRQ(DMA2_Stream1_IRQn);       
} 

//SAI��ʼ¼��
void SAI_Rec_Start(uint8_t itflag,uint8_t Prio)
{ 
		if(itflag == 1)
		{
			__HAL_DMA_CLEAR_FLAG(&SAI1_RXDMA_Handler , 0x3F << SAI1_TXDMA_Handler.StreamIndex); 
			__HAL_DMA_ENABLE_IT(&SAI1_RXDMA_Handler , DMA_IT_TC);             //������������ж�	

			HAL_NVIC_SetPriority(DMA2_Stream5_IRQn, Prio, 0);
			HAL_NVIC_EnableIRQ(DMA2_Stream5_IRQn);
		}			
		
		__HAL_DMA_ENABLE(&SAI1_RXDMA_Handler);

}

//�ر�SAI¼��
void SAI_Rec_Stop(void)
{   
	__HAL_DMA_DISABLE_IT(&SAI1_RXDMA_Handler,DMA_IT_TC);             //������������ж�
	__HAL_DMA_CLEAR_FLAG(&SAI1_RXDMA_Handler,0x3F << SAI1_TXDMA_Handler.StreamIndex);
	__HAL_DMA_DISABLE(&SAI1_RXDMA_Handler);                         //�ȹرս���DMA
	
	HAL_NVIC_ClearPendingIRQ(DMA2_Stream5_IRQn); 
	HAL_NVIC_DisableIRQ(DMA2_Stream5_IRQn);

}









