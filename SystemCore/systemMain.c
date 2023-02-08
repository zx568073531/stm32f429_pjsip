#include "systemCore.h"
#include "systemClock.h"
#include "systemCompont.h"

// 用户定义包含头文件
#include "task_main.h"



/**
  * @brief  主函数入口
  */
int main(void)
{
  HeapRegion_t xHeapRegions[] =
  {
		{(uint8_t*)0x10000000UL,0x10000},
		{(uint8_t*)0xC1000000UL,0x1000000},
  	{ NULL, 0 } 
	};
	
	// 定义当前使用Heap地址
	vPortDefineHeapRegions(xHeapRegions);	
	
	// 初始化系统库
	HAL_Init();
	
	// 初始化系统时钟
	SystemClock_Config();
	
	// EventRecorder 初始化
	SystemLog_Config();
		
	// 初始化必要的初始化组件
	SystemCompont_Config();
	
	// 进入主要USER的主函数入口
	UserApplication_Entry();
}
