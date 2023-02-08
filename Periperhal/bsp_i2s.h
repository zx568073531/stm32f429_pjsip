#ifndef __BSP_I2S_H_
#define __BSP_I2S_H_

#include "systemCore.h"

void bsp_i2s_init(uint32_t Frequcy);
void bsp_i2s2_OutDMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t size);
void bsp_i2s2_InDMA_Init(uint8_t* buf0,uint8_t *buf1,uint16_t size);

void bsp_i2s2_playStop(void);
void bsp_i2s2_playStart(uint8_t itflag,uint8_t Prio);

void bsp_i2s2_recStop(void);
void bsp_i2s2_recStart(uint8_t itflag,uint8_t Prio);

uint8_t i2s2GetTxflag(void);
uint8_t i2s2GetRxflag(void);


#endif

