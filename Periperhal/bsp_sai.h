#ifndef __BSP_SAI_H
#define __BSP_SAI_H
#include "systemCore.h"   
 									
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板
//SAI 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2016/1/11
//版本：V1.1
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved	
//********************************************************************************
//V1.1 20160111
//新增SAIB_Init、SAIA_RX_DMA_Init、SAI_Rec_Start和SAI_Rec_Stop等函数								   
////////////////////////////////////////////////////////////////////////////////// 	

void SAIA_Init(uint32_t);
void SAIB_Init(uint32_t);

void SAIA_TX_DMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t num,uint8_t width);
void SAIA_RX_DMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t num,uint8_t width);

void SAI_Play_Start(uint8_t itflag,uint8_t Prio); 
void SAI_Play_Stop(void);  

void SAI_Rec_Start(uint8_t itflag,uint8_t Prio);
void SAI_Rec_Stop(void);

#endif





















