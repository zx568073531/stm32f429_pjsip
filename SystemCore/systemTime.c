#include "SystemTime.h"

extern HAL_StatusTypeDef $Super$$HAL_Init(void);

/**
  * @brief System Delya_us Configuration
  * @retval None
  */
void $Sub$$HAL_Init(void)
{
//	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
//	DWT->CYCCNT = 0;
//	DWT->CTRL   |= DWT_CTRL_CYCCNTENA_Msk;
//	
	$Super$$HAL_Init();
}

/**
  * @brief System Delya_us 
  * @prama _ulDelayTime ��Ҫ��ʱ��ʱ��
  * @retval None
  */
//void delay_us(uint32_t _ulDelayTime)
//{	
//  uint32_t tCnt, tDelayCnt;
//	uint32_t tStart;
//	
//	tStart = DWT->CYCCNT;                                     /* �ս���ʱ�ļ�����ֵ */
//	tCnt = 0;
//	tDelayCnt = _ulDelayTime * (SystemCoreClock / 1000000);	 /* ��Ҫ�Ľ����� */ 		      

//	while(tCnt < tDelayCnt)
//	{
//		tCnt = DWT->CYCCNT - tStart; /* ��������У����������һ��32λ���������¼�������Ȼ������ȷ���� */	
//	}
//	
//}


uint32_t get_us(void)
{
	return DWT->CYCCNT;
}


uint32_t calu_us(uint32_t tStart)
{
	uint32_t cnt;
	
	cnt = DWT->CYCCNT - tStart;
	cnt /= (SystemCoreClock / 1000000);
	
	return cnt;	//������˶���us
}

void delay_us(uint32_t _ulDelayTime)
{	
	uint32_t ticks;
	uint32_t told;
	uint32_t tnow;
	uint32_t tcnt = 0;
	uint32_t reload;

	reload = SysTick->LOAD;                
	ticks = _ulDelayTime * (SystemCoreClock / 1000000);	 

	tcnt = 0;
	told = SysTick->VAL;     

	while (1)
	{
		tnow = SysTick->VAL;    
		if (tnow != told)
		{    
			if (tnow < told)
			{
				tcnt += told - tnow;    
			}
			else
			{
				tcnt += reload - tnow + told;    
			}        
			told = tnow;
			if (tcnt >= ticks)
			{
				break;
			}
		}  
	}
}
