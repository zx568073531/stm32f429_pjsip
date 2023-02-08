#pragma once 

#include <stdint.h>

// 系统HAL库头文件
#include "stm32f4xx_hal.h"

// 主要为HAL库和系统错误函数申明
#include "systemCommon.h"
#include "systemBitband.h"

#include "systemLog.h"

#include "FreeRTOS.h"
#include "semphr.h"
#include "queue.h"
#include "task.h"
#include "timers.h"

// posix 接口
#include "pthread.h"


/* Determine whether we are in thread mode or handler mode. */
static inline int inHandlerMode (void)
{
  return __get_IPSR() != 0;
}

