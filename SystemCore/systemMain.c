#include "systemCore.h"
#include "systemClock.h"
#include "systemCompont.h"

// �û��������ͷ�ļ�
#include "task_main.h"



/**
  * @brief  ���������
  */
int main(void)
{
  HeapRegion_t xHeapRegions[] =
  {
		{(uint8_t*)0x10000000UL,0x10000},
		{(uint8_t*)0xC1000000UL,0x1000000},
  	{ NULL, 0 } 
	};
	
	// ���嵱ǰʹ��Heap��ַ
	vPortDefineHeapRegions(xHeapRegions);	
	
	// ��ʼ��ϵͳ��
	HAL_Init();
	
	// ��ʼ��ϵͳʱ��
	SystemClock_Config();
	
	// EventRecorder ��ʼ��
	SystemLog_Config();
		
	// ��ʼ����Ҫ�ĳ�ʼ�����
	SystemCompont_Config();
	
	// ������ҪUSER�����������
	UserApplication_Entry();
}
