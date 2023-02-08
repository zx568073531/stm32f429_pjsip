#include "systemCore.h"
#include "systemCompont.h"


CRC_HandleTypeDef sysCRC;
RNG_HandleTypeDef sysRNG;

void SystemCompont_Config(void)
{
	__HAL_RCC_CRC_CLK_ENABLE();
	
  sysCRC.Instance = CRC;
  if (HAL_CRC_Init(&sysCRC) != HAL_OK)
  {
    Error_Handler();
  }	
	
	__HAL_RCC_RNG_CLK_ENABLE();
	
  sysRNG.Instance = RNG;
  if (HAL_RNG_Init(&sysRNG) != HAL_OK)
  {
    Error_Handler();
  }
}



