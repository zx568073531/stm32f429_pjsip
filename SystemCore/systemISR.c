#include "systemCore.h"
#include "systemISR.h"


extern void xPortSysTickHandler(void);

void SysTick_Handler(void)
{
	HAL_IncTick();
	
	if(xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
	{
		xPortSysTickHandler();
	}		
	
}
