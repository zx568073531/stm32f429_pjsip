#pragma once 

#include <stdint.h>

// ϵͳHAL��ͷ�ļ�
#include "stm32f4xx_hal.h"

// ��ҪΪHAL���ϵͳ����������
#include "systemCommon.h"
#include "systemBitband.h"

#include "systemLog.h"

#include "FreeRTOS.h"
#include "semphr.h"
#include "queue.h"
#include "task.h"
#include "timers.h"

// posix �ӿ�
#include "pthread.h"


/* Determine whether we are in thread mode or handler mode. */
static inline int inHandlerMode (void)
{
  return __get_IPSR() != 0;
}

