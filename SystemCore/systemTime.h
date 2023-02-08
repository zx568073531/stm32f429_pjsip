#ifndef __SYSTEMTIME_H
#define __SYSTEMTIME_H

#include <stdint.h>
#include "SystemCore.h"

void delay_us(uint32_t _ulDelayTime);
#define System_DelayMS HAL_Delay

uint32_t calu_us(uint32_t tStart);
uint32_t get_us(void);


#endif
