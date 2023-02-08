#include "systemCore.h"


void SystemLog_Config(void)
{
#if (EVENT_RECORDER == 1)
	/* 初始化EventRecorder并开启 */
	EventRecorderInitialize(EventRecordAll, 1U);
	EventRecorderStart();
#endif
	
#if (SEGGER_RTT_VIEWER == 1)
	SEGGER_RTT_ConfigDownBuffer(0, "RTT_DOWN", NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
  SEGGER_RTT_ConfigUpBuffer(0, "RTT_UP", NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_SKIP);
#endif
	
	msg_log("Log Plathom Init Compelte!\r\n");
}


