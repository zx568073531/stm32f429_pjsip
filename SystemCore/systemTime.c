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
  * @prama _ulDelayTime 需要延时的时间
  * @retval None
  */
//void delay_us(uint32_t _ulDelayTime)
//{	
//  uint32_t tCnt, tDelayCnt;
//	uint32_t tStart;
//	
//	tStart = DWT->CYCCNT;                                     /* 刚进入时的计数器值 */
//	tCnt = 0;
//	tDelayCnt = _ulDelayTime * (SystemCoreClock / 1000000);	 /* 需要的节拍数 */ 		      

//	while(tCnt < tDelayCnt)
//	{
//		tCnt = DWT->CYCCNT - tStart; /* 求减过程中，如果发生第一次32位计数器重新计数，依然可以正确计算 */	
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
	
	return cnt;	//计算过了多少us
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
