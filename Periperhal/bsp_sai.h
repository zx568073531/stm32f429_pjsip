#ifndef __BSP_SAI_H
#define __BSP_SAI_H
#include "systemCore.h"   
 									
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32������
//SAI ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2016/1/11
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved	
//********************************************************************************
//V1.1 20160111
//����SAIB_Init��SAIA_RX_DMA_Init��SAI_Rec_Start��SAI_Rec_Stop�Ⱥ���								   
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





















