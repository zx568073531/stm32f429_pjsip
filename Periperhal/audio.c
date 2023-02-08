

/*
*************************************************************************
*                             包含的头文件
*************************************************************************
*/ 
#include "audio.h"
#include "bsp_i2s.h"
#include "bsp_sai.h"

#include "wm8978.h"

#define AUDIO_INTERFACE_I2S	0
#define AUDIO_INTERFACE_SAI	1

#define AUDIO_USE_INTERFACE	AUDIO_INTERFACE_SAI


#define AUDIO_SAMPLE_RATE		16000		// 16K
#define AUDIO_CHANNEL_NUM		2				// stereo
#define AUDIO_PER_BIT				16			// 16bit
#define AUDIO_PER_SECON			20			// 20ms
#define AUDIO_PER_DATE			(AUDIO_SAMPLE_RATE / (1000 / AUDIO_PER_SECON))


uint8_t i2Stxbuf1[AUDIO_PER_DATE * 2 * 2];				
uint8_t i2Stxbuf2[AUDIO_PER_DATE * 2 * 2]; 				
		
uint8_t i2Srxbuf1[AUDIO_PER_DATE * 2 * 2];				
uint8_t i2Srxbuf2[AUDIO_PER_DATE * 2 * 2];			


 /**
  * @brief  Enter PlayMode
  * @param  
  * @retval 无
  */ 
void Audio_Config_Play(void)
{
	/* 配置WM8978芯片，输入为线输入，输出为耳机，R2如果不打开ROUT1EN和LOUT1EN就会嘎啦?	*/
	wm8978_CfgAudioPath(DAC_ON , SPK_ON );
	
	/* 调节音量，左右相同音量 */
	wm8978_SetOUT2Volume(60);
	
	/* 配置WM8978音频接口为飞利浦标准I2S接口，16bit */
	wm8978_CfgAudioIF(I2S_Standard_Phillips, 16 , SAMPLE_16K);
	
#if (AUDIO_USE_INTERFACE == AUDIO_INTERFACE_I2S)
	
	bsp_i2s2_playStop();
	bsp_i2s2_recStop();
	
	bsp_i2s_init(AUDIO_SAMPLE_RATE);
	
	bsp_i2s2_InDMA_Init(i2Srxbuf1,i2Srxbuf2,txsize * 2);	
	bsp_i2s2_OutDMA_Init(i2Stxbuf1,i2Stxbuf2,txsize * 2);

	bsp_i2s2_recStart(0,4);	
	bsp_i2s2_playStart(1,4);	
	
#else

	SAIA_Init(AUDIO_SAMPLE_RATE);	
	SAIB_Init(AUDIO_SAMPLE_RATE);
	
	SAIA_TX_DMA_Init(i2Stxbuf1 , i2Stxbuf2 , AUDIO_PER_DATE * sizeof(uint16_t) , 1 );
	SAIA_RX_DMA_Init(i2Srxbuf1 , i2Srxbuf2 , AUDIO_PER_DATE * sizeof(uint16_t) , 1 );
	
	SAI_Play_Start(1 , 0xE);
	SAI_Rec_Start(0 , 0xE);
	
#endif
}

 /**
  * @brief  Enter PlayMode
  * @param  
  * @retval 无
  */ 
void Audio_Config_Rec(void)
{
	/* 配置WM8978芯片，输入为线输入，输出为耳机，R2如果不打开ROUT1EN和LOUT1EN就会嘎啦?	*/
	wm8978_CfgAudioPath(MIC_LEFT_ON | MIC_RIGHT_ON | ADC_ON ,OUT_PATH_OFF);
	
	/* 设置MIC采样之后声音放大倍数 */
	wm8978_SetMicGain(55);
	
	/* 配置WM8978音频接口为飞利浦标准I2S接口，16bit */
	wm8978_CfgAudioIF(I2S_Standard_Phillips, 16 , SAMPLE_16K);
	
#if (AUDIO_USE_INTERFACE == AUDIO_INTERFACE_I2S)
		
	bsp_i2s2_playStop();
	bsp_i2s2_recStop();
	
	bsp_i2s_init(AUDIO_SAMPLE_RATE);
	
	bsp_i2s2_InDMA_Init(i2Srxbuf1 , i2Srxbuf2  , AUDIO_PER_DATE * 2);
	bsp_i2s2_OutDMA_Init(i2Stxbuf1 ,i2Stxbuf2 , AUDIO_PER_DATE * 2);

	bsp_i2s2_playStart(0,4);	

	bsp_i2s2_recStart(1,4);

#else

	SAIA_Init(AUDIO_SAMPLE_RATE);	
	SAIB_Init(AUDIO_SAMPLE_RATE);
	
	SAIA_TX_DMA_Init(i2Stxbuf1 , i2Stxbuf2 , AUDIO_PER_DATE * sizeof(uint16_t) , 1 );
	SAIA_RX_DMA_Init(i2Srxbuf1 , i2Srxbuf2 , AUDIO_PER_DATE * sizeof(uint16_t) , 1 );
	
	SAI_Play_Start(0 , 0xE);
	SAI_Rec_Start(1 , 0xE);	

#endif

}

void Audio_Set_Volmue(uint8_t val)
{
	/* 调节音量，左右相同音量 */
	wm8978_SetOUT2Volume(val);
}

 /**
  * @brief  Enter Fullduplex 
  * @param  
  * @retval 无
  */ 
void Audio_Config_FullDuplex()
{
	TickType_t dtime;

	/* 配置WM8978芯片，输入为线输入，输出为耳机	*/
	wm8978_CfgAudioPath(MIC_LEFT_ON | MIC_RIGHT_ON | ADC_ON | DAC_ON , SPK_ON | EAR_LEFT_ON | EAR_RIGHT_ON);
	
	/* 设置MIC采样之后声音放大倍数 */
	wm8978_SetMicGain(55);
	
	/* 调节音量，左右相同音量 */
	wm8978_SetOUT1Volume(60);
	wm8978_SetOUT2Volume(60);

	/* 配置WM8978音频接口为飞利浦标准I2S接口，16bit */
	wm8978_CfgAudioIF(I2S_Standard_Phillips, 16 , SAMPLE_16K);

#if (AUDIO_USE_INTERFACE == AUDIO_INTERFACE_I2S)
		
	bsp_i2s_init(AUDIO_SAMPLE_RATE);
	
	bsp_i2s2_OutDMA_Init(i2Stxbuf1 , i2Stxbuf2 , AUDIO_PER_DATE * 2);
	bsp_i2s2_InDMA_Init(i2Srxbuf1 , i2Srxbuf2 , AUDIO_PER_DATE * 2);

	bsp_i2s2_recStart(1,4);	

	dtime = xTaskGetTickCount();
	vTaskDelayUntil(&dtime,10);
	
	bsp_i2s2_playStart(1,4);

#else

//	SAI_Play_Stop();
//	SAI_Rec_Stop();

	SAIA_Init(AUDIO_SAMPLE_RATE);	
	SAIB_Init(AUDIO_SAMPLE_RATE);

	SAIA_TX_DMA_Init(i2Stxbuf1 , i2Stxbuf2 ,  AUDIO_PER_DATE * 2 , 1 );
	SAIA_RX_DMA_Init(i2Srxbuf1 , i2Srxbuf2 ,  AUDIO_PER_DATE * 2 , 1 );
	
	SAI_Rec_Start(1 , 0xE);	
	SAI_Play_Start(1 , 0xE);

#endif
	
}

void Audio_StreamStop(void)
{
#if (AUDIO_USE_INTERFACE == AUDIO_INTERFACE_I2S)
			
	bsp_i2s2_playStop();
	bsp_i2s2_recStop();

#else

	SAI_Play_Stop();
	SAI_Rec_Stop();
	
#endif	
	
	wm8978_Reset();
}


////////////////////////////////////////////////////////////////////////////////////////

#include "systemCore.h"


typedef struct {
    char *buf;
    int buf_size;
    volatile int rw_pos;
    volatile void *curr_ptr;
    SemaphoreHandle_t mux;
    xQueueHandle queue;
		volatile int w_pos;
		xQueueHandle event;
} audio_dma_t;


audio_dma_t play;
audio_dma_t rec;

#define AUDIO_NUMBER	6
#define AUDIO_TOAL	(AUDIO_NUMBER * AUDIO_PER_DATE * 2 * 2)


int32_t AudioInterfaceInit(uint8_t tx_event , uint8_t rx_event)
{
	memset(&play , 0 , sizeof(audio_dma_t));
	
	play.queue = xQueueCreate(AUDIO_NUMBER , sizeof(void * ));
	play.mux = xSemaphoreCreateMutex();
	play.buf = pvPortMalloc(AUDIO_TOAL);
	if(play.buf != NULL)
	{
		memset(play.buf , 0 , AUDIO_TOAL);
	}
	play.buf_size = AUDIO_PER_DATE * 2 * 2;
	
	if(tx_event != 0)
	{
		play.event = xQueueCreate(AUDIO_NUMBER , sizeof(int32_t));
	}
	
	memset(&rec , 0 , sizeof(audio_dma_t));
	
	rec.queue = xQueueCreate(4 , sizeof(void * ));
	rec.mux = xSemaphoreCreateMutex();
	rec.buf = pvPortMalloc(AUDIO_TOAL);
	if(rec.buf != NULL)
	{
		memset(rec.buf , 0 , AUDIO_TOAL);
	}
	rec.buf_size = AUDIO_PER_DATE * 2 * 2;
	
	if(rx_event != 0)
	{
		rec.event = xQueueCreate(AUDIO_NUMBER , sizeof(int32_t));
	}	
	
	wm8978_Init();
	
	return (play.queue == NULL) || (play.mux == NULL) || (play.buf == NULL)||
		 (rec.queue == NULL) || (rec.mux == NULL)|| (rec.buf == NULL);
}
	

int32_t AudioWriteData(const void *src, uint32_t size, uint32_t *bytes_written, uint32_t ticks_to_wait)
{
	char *data_ptr, *src_byte;
	size_t bytes_can_write;
	*bytes_written = 0;
	
	xSemaphoreTake(play.mux, (portTickType)portMAX_DELAY);
	
	src_byte = (char *)src;
	while (size > 0) {
		
			if (play.rw_pos == play.buf_size || play.curr_ptr == NULL) {
					if (xQueueReceive(play.queue, &play.curr_ptr, ticks_to_wait) == pdFALSE) {
							break;
					}
					play.rw_pos = 0;
			}
			
			data_ptr = (char *)play.curr_ptr;
			data_ptr += play.rw_pos;
			bytes_can_write = play.buf_size - play.rw_pos;
			
			if (bytes_can_write > size) {
					bytes_can_write = size;
			}
			
			memcpy(data_ptr, src_byte, bytes_can_write);
			
			size -= bytes_can_write;
			src_byte += bytes_can_write;
			play.rw_pos += bytes_can_write;
			(*bytes_written) += bytes_can_write;
	}

	xSemaphoreGive(play.mux);
	return 0;
}


int32_t AudioReadData(const void *dest, uint32_t size, uint32_t *bytes_read, uint32_t ticks_to_wait)
{
	char *data_ptr, *dest_byte;
	int bytes_can_read;
	*bytes_read = 0;
	dest_byte = (char *)dest;
	
	xSemaphoreTake(rec.mux , (portTickType)portMAX_DELAY);

	while (size > 0) {
			if (rec.rw_pos == rec.buf_size || rec.curr_ptr == NULL) {
					if (xQueueReceive(rec.queue, &rec.curr_ptr, ticks_to_wait) == pdFALSE) {
							break;
					}
					rec.rw_pos = 0;
			}
			data_ptr = (char *)rec.curr_ptr;
			data_ptr += rec.rw_pos;
			bytes_can_read = rec.buf_size - rec.rw_pos;
			if (bytes_can_read > (int)size) {
					bytes_can_read = size;
			}
			
			memcpy(dest_byte, data_ptr, bytes_can_read);
			
			size -= bytes_can_read;
			dest_byte += bytes_can_read;
			rec.rw_pos += bytes_can_read;
			(*bytes_read) += bytes_can_read;
	}
	
	xSemaphoreGive(rec.mux);
	return 0;
}



int32_t Audio_DMA_tx_callback(uint8_t DEM)
{
	// 从队列中读取数据,并且写入到语音buffer
	BaseType_t taskWoken = 0;
	BaseType_t ret = 0;
	int32_t dummy;
	int32_t event = 0;
	
	EventStopA(0);
	
	EventStartA(0);
	
	if (xQueueIsQueueFullFromISR(play.queue)) {
			xQueueReceiveFromISR(play.queue, &dummy, &taskWoken);
			memset((void *)dummy , 0 , (AUDIO_PER_DATE * 2 * 2));
	}
	
	if(DEM)
	{
		memcpy(&i2Stxbuf2 , &play.buf[play.w_pos] , (AUDIO_PER_DATE * 2 * 2));
	}
	else
	{
		// 拷贝数据到 DMAbuff 0
		memcpy(&i2Stxbuf1 , &play.buf[play.w_pos] , (AUDIO_PER_DATE * 2 * 2));
	}
	
	dummy = (uint32_t)&play.buf[play.w_pos];
	ret = xQueueSendFromISR(play.queue, &dummy, &taskWoken);	
	
	play.w_pos += (AUDIO_PER_DATE * 2 * 2);
	if(play.w_pos >= AUDIO_TOAL)
	{
		play.w_pos = 0;
	}
	
	if(play.event != NULL)
	{
		if (xQueueIsQueueFullFromISR(play.event)) {
        xQueueReceiveFromISR(play.event, &dummy, &taskWoken);
    }
    xQueueSendFromISR(play.event, (void *)&event, &taskWoken);		
	}
	
	return taskWoken;
}


void saiTxDMA_ConvCplt(DMA_HandleTypeDef *hdma)
{
	BaseType_t taskWoken ;
	taskWoken = Audio_DMA_tx_callback(1);
	if( taskWoken )
		portEND_SWITCHING_ISR(taskWoken);
}

void saiTxDMA_M1ConvCplt(DMA_HandleTypeDef *hdma)
{
	BaseType_t taskWoken ;
	taskWoken = Audio_DMA_tx_callback(0);
	if( taskWoken )
		portEND_SWITCHING_ISR(taskWoken);	
}
	

int32_t Audio_DMA_rx_callback(uint8_t DEM)
{
	// 从队列中读取数据,并且写入到语音buffer
	BaseType_t taskWoken = 0;
	BaseType_t ret = 0;
	int32_t dummy;
	int32_t event = 0;
	EventStopA(1);
	
	EventStartA(1);	
	if (xQueueIsQueueFullFromISR(rec.queue)) {
			xQueueReceiveFromISR(rec.queue, &dummy, &taskWoken);
	}
	
	if(DEM)
	{
		memcpy(&rec.buf[rec.w_pos] , &i2Srxbuf2 , (AUDIO_PER_DATE * 2 * 2));
	}
	else
	{
		// 拷贝数据到 DMAbuff 0
		memcpy(&rec.buf[rec.w_pos] , &i2Srxbuf1 , (AUDIO_PER_DATE * 2 * 2));
	}
	dummy = (uint32_t)&rec.buf[rec.w_pos];
	ret = xQueueSendFromISR(rec.queue, &dummy , &taskWoken);	
	
	rec.w_pos += (AUDIO_PER_DATE * 2 * 2);
	if(rec.w_pos >= AUDIO_TOAL)
	{
		rec.w_pos = 0;
	}
	
	if(rec.event != NULL)
	{
		if (xQueueIsQueueFullFromISR(rec.event)) {
        xQueueReceiveFromISR(rec.event, &dummy, &taskWoken);
    }
    xQueueSendFromISR(rec.event, (void *)&event, &taskWoken);		
	}
	
	return taskWoken;
}



void saiRxDMA_ConvCplt(DMA_HandleTypeDef *hdma)
{
	BaseType_t taskWoken ;
	
	taskWoken = Audio_DMA_rx_callback(0);
	if( taskWoken )
		portEND_SWITCHING_ISR(taskWoken);
}
	

void saiRxDMA_M1ConvCplt(DMA_HandleTypeDef *hdma)
{
	BaseType_t taskWoken ;
	
	taskWoken = Audio_DMA_rx_callback(1);
	if( taskWoken )
		portEND_SWITCHING_ISR(taskWoken);
			
}

	
	
	
	