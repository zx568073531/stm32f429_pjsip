
#ifndef __WM8978_H_
#define __WM8978_H_

#include "stdint.h"

#define WM8978_ADDR				0X1A	//WM8978的器件地址,固定为0X1A 

#define I2S_Standard_Phillips           ((uint16_t)0x0000)
#define I2S_Standard_MSB                ((uint16_t)0x0010)
#define I2S_Standard_LSB                ((uint16_t)0x0020)


/* WM8978 音频输入通道控制选项, 可以选择多路，比如 MIC_LEFT_ON | LINE_ON */
typedef enum
{
	IN_PATH_OFF		= 0x00,	/* 无输入 */
	MIC_LEFT_ON 	= 0x01,	/* LIN,LIP脚，MIC左声道（接板载咪头）  */
	MIC_RIGHT_ON	= 0x02,	/* RIN,RIP脚，MIC右声道（接板载咪头）  */
	LINE_ON			  = 0x04, /* L2,R2 立体声输入(接板载耳机插座) */
	AUX_ON			  = 0x08,	/* AUXL,AUXR 立体声输入（开发板没用到） */
	DAC_ON			  = 0x10,	/* I2S数据DAC (CPU产生音频信号) */
	ADC_ON			  = 0x20,	/* 输入的音频馈入WM8978内部ADC （I2S录音) */
	LINE_BOOST_EN = 0x40,
	LINE_L2_EN    = 0x80,
	LINE_R2_EN    = 0x100,
}IN_PATH_E;

/* WM8978 音频输出通道控制选项, 可以选择多路 */
typedef enum
{
	OUT_PATH_OFF	= 0x00,	/* 无输出 */
	EAR_LEFT_ON 	= 0x01,	/* LOUT1 耳机左声道(接板载耳机插座) */
	EAR_RIGHT_ON	= 0x02,	/* ROUT1 耳机右声道(接板载耳机插座) */
	SPK_ON			  = 0x04,	/* LOUT2和ROUT2反相输出单声道 */
	OUT3_ON		  	= 0x08,	/* OUT3 输出单声道音频 */
	OUT4_ON				= 0x10,	/* OUT4 输出单声道音频 */
	BYPASS_ON     = 0x20, /* 输入的直通给输出 */	
	MIXER_OUT_ON  = 0x40,	/* 输出混音器的属共输出到OUT4 */
	DAC_OUT_ON		= 0x80,
	AUR_BYPASS_ON = 0x100,
}OUT_PATH_E;

typedef enum
{
	SAMPLE_8K		= 0x01,
	SAMPLE_16K	= 0x02,
	SAMPLE_24K	=	0x04,
	SAMPLE_32K	= 0x08,
	SAMPLE_4K	= 0x10	
}SAMPLE_RATE_E;


typedef enum
{
	ALC_OFF = 0,
	ALC_RIGHT_ONLY,
	ALC_LEFT_ONLY,
	ALC_BOTH_ONLY
	
}ALC_SET_E;


typedef enum
{
	ALC_MIN_M12dB,
	ALC_MIN_M6dB,
	ALC_MIN_0dB,
	ALC_MIN_6dB,
	ALC_MIN_12dB,
	ALC_MIN_18dB,
	ALC_MIN_24dB,
	ALC_MIN_30dB	
}ALC_MIN_DB_E;

typedef enum
{
	ALC_MAX_M6p75dB,
	ALC_MAX_M0p75dB,
	ALC_MAX_5p25dB,
	ALC_MAX_11p25dB,
	ALC_MAX_17p25dB,
	ALC_MAX_23p25dB,
	ALC_MAX_29p25dB,
	ALC_MAX_35p25dB	
	
}ALC_MAX_DB_E;

/* 定义最大音量 */
#define VOLUME_MAX		                      63		/* 最大音量 */
#define VOLUME_STEP		                       1		/* 音量调节步长 */

/* 定义最大MIC增益 */
#define GAIN_MAX		                        63		/* 最大增益 */
#define GAIN_STEP		                         1		/* 增益步长 */



/* 供外部引用的函数声明 */
uint8_t wm8978_Init(void);
uint8_t wm8978_Reset(void);
void wm8978_CfgAudioIF(uint16_t _usStandard, uint8_t _ucWordLen,uint16_t _ucSample);
void wm8978_OutMute(uint8_t _ucMute);
void wm8978_PowerDown(void);
void wm8978_CfgAudioPath(uint16_t _InPath, uint16_t _OutPath);
void wm8978_SetMicGain(uint8_t _ucGain);
void wm8978_SetLineGain(uint16_t In_path,uint8_t _ucGain);
void wm8978_SetAUXGain(uint8_t _ucGain);

void wm8978_SetOUT2Volume(uint8_t _ucVolume);
void wm8978_SetOUT1Volume(uint8_t _ucVolume);


uint8_t wm8978_ReadOUT1Volume(void);
uint8_t wm8978_ReadOUT2Volume(void);
void wm8978_NotchFilter(uint16_t _NFA0, uint16_t _NFA1);
void wm8978_ALC_Set(void);


extern uint8_t ucVolue;

#endif

