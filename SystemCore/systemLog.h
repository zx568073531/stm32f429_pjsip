#pragma once 


#define EVENT_RECORDER			1
#if (EVENT_RECORDER == 1)
#include "EventRecorder.h"  
#endif

#define SEGGER_RTT_VIEWER		1
#if (SEGGER_RTT_VIEWER == 1)
#include "SEGGER_RTT.h"
#endif

#define msg_log(...)	do {	\
												SEGGER_RTT_printf(0, ##__VA_ARGS__); \
											}while(0);


void SystemLog_Config(void);
