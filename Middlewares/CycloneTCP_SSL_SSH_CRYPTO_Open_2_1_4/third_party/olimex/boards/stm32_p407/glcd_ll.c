/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2006
 *
 *    File name   : glcd_ll.c
 *    Description : GLCD low level functions
 *
 *    History :
 *    1. Date        : December 2, 2006
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *    $Revision: #2 $
 **************************************************************************/

#include "stm32f4xx.h"
#include "glcd_ll.h"

static Int32U Width;

/*************************************************************************
 * Function Name: GLCD_SetReset
 * Parameters: Boolean State
 * Return: none
 *
 * Description: Set reset pin state
 *
 *************************************************************************/
void GLCD_SetReset (Boolean State)
{
  if(State)
    HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_MASK, GPIO_PIN_SET);
  else
    HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_MASK, GPIO_PIN_RESET);
}

/*************************************************************************
 * Function Name: GLCD_SetBacklight
 * Parameters: Int8U Light
 * Return: none
 *
 * Description: Set backlight pin state
 *
 *************************************************************************/
void GLCD_Backlight (Int8U Light)
{
  if(Light)
    HAL_GPIO_WritePin(LCD_BL_PORT, LCD_BL_MASK, GPIO_PIN_SET);
  else
    HAL_GPIO_WritePin(LCD_BL_PORT, LCD_BL_MASK, GPIO_PIN_RESET);
}

/*************************************************************************
 * Function Name: GLCD_LLInit
 * Parameters: none
 * Return: none
 *
 * Description: Init Reset and Backlight control outputs
 *
 *************************************************************************/
void GLCD_LLInit (void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock and release reset*/
  LCD_RST_CLK_EN();
  LCD_BL_CLK_EN();

  /*LCD Reset pin init*/
  GPIO_InitStructure.Pin = LCD_RST_MASK;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LCD_RST_PORT, &GPIO_InitStructure);

  GLCD_SetReset(0);

	/* LCD backlight Init*/
  GPIO_InitStructure.Pin = LCD_BL_MASK;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LCD_BL_PORT, &GPIO_InitStructure);

  GLCD_Backlight(0);
}

/*************************************************************************
 * Function Name: LcdSpiChipSelect
 * Parameters: Boolean Select
 * Return: none
 *
 * Description: SPI Chip select control
 * Select = true  - Chip is enable
 * Select = false - Chip is disable
 *
 *************************************************************************/
void GLCD_SPI_ChipSelect (Boolean Select)
{
  volatile int i;
   
  for(i= 5; i; i-- );
   
  if(Select)
    HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_MASK, GPIO_PIN_RESET);
  else
    HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_MASK, GPIO_PIN_SET);
  
  for(i= 5; i; i-- );
}

/*************************************************************************
 * Function Name: LcdSpiSetWordWidth
 * Parameters: Int32U Data
 * Return: Boolean
 *
 * Description: Set SPI word width
 *
 *************************************************************************/
Boolean GLCD_SPI_SetWordWidth (Int32U Data)
{
  if((8 != Data) && (9 != Data))
  {
    return(FALSE);
  }

  Width = Data;
  return(TRUE);
}

/*************************************************************************
 * Function Name: LcdSpiSetClockFreq
 * Parameters: Int32U Frequency
 * Return: Int32U
 *
 * Description: Set SPI clock
 *
 *************************************************************************/
/*
Int32U GLCD_SPI_SetClockFreq (Int32U Frequency)
{
Int32U Fspi = SYS_GetFpclk(Ssp1_PCLK_OFFSET);
Int32U Div = 2;
  while((Div * Frequency) < Fspi)
  {
    if((Div += 2) == 254)
    {
      break;
    }
  }
  Ssp1CPSR = Div;
  return(Fspi/Div);
}
*/
/*************************************************************************
 * Function Name: GLCD_SPI_Init
 * Parameters: Int32U Clk, Int32U Width
 * Return: none
 *
 * Description: Init SPI
 *
 *************************************************************************/
void GLCD_SPI_Init(Int32U Clk, Int32U Width)
{
GPIO_InitTypeDef GPIO_InitStructure;
  /* Enable GPIO clock and release reset*/
  LCD_CS_CLK_EN();
  LCD_SPI_MISO_CLK_EN();
  LCD_SPI_MOSI_CLK_EN();
  LCD_SPI_SCLK_CLK_EN();

  /*LCD_CS*/
  GPIO_InitStructure.Pin = LCD_CS_MASK;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LCD_CS_PORT, &GPIO_InitStructure);

  /*LCD_SPI_SCLK*/
  GPIO_InitStructure.Pin = LCD_SPI_SCLK_MASK;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LCD_SPI_SCLK_PORT, &GPIO_InitStructure);

  /*LCD_SPI_MOSI*/
  GPIO_InitStructure.Pin = LCD_SPI_MOSI_MASK;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LCD_SPI_MOSI_PORT, &GPIO_InitStructure);

#if 0
  /*LCD_SPI_MISO*/
  GPIO_InitStructure.Pin = LCD_SPI_MISO_MASK;
  GPIO_InitStructure.OType = GPIO_OType_PP;
  GPIO_InitStructure.Pull = GPIO_PuPd_UP;
  GPIO_InitStructure.Mode = GPIO_Mode_IN;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
 HAL_GPIO_Init(LCD_SPI_MISO_PORT, &GPIO_InitStructure);
#endif

  // Chip select
  GLCD_SPI_ChipSelect(0);
  GLCD_SPI_CLK_H();

  // Set data width
  GLCD_SPI_SetWordWidth(Width);

}

/*************************************************************************
 * Function Name: GLCD_SPI_TranserByte
 * Parameters: Int32U Data
 * Return: Int32U
 *
 * Description: Transfer byte from SPI
 *
 *************************************************************************/
Int32U GLCD_SPI_TranserByte (Int32U Data)
{
Int32U InData = 0;
Int32U Mask;
volatile Int32U i;

  for (Mask = 1UL << (Width-1); Mask; Mask>>= 1)
  {
    // Set Data
    if (Mask & Data)
    {
      GLCD_SPI_MOSI_H();
    }
    else
    {
      GLCD_SPI_MOSI_L();
    }
    
    InData <<= 1;
    for(i= 5; i; i-- );
    
    // Clock Low
    GLCD_SPI_CLK_L();
    for(i= 5; i; i-- );

    // Get Data
    if (GLCD_SPI_MISO())
    {
      ++InData;
    }
    
    // Clock High
    GLCD_SPI_CLK_H();
    for(i= 5; i; i-- );
  }
  return(InData);
}

/*************************************************************************
 * Function Name: GLCD_SPI_SendBlock
 * Parameters: pInt8U pData, Int32U Size
 *
 * Return: void
 *
 * Description: Write block of data to SPI
 *
 *************************************************************************/
void GLCD_SPI_SendBlock (pInt8U pData, Int32U Size)
{
Int32U OutCount = Size;
  while (OutCount--)
  {
    GLCD_SPI_TranserByte(*pData++ | 0x100);
  }
}

/*************************************************************************
 * Function Name: GLCD_SPI_ReceiveBlock
 * Parameters: pInt8U pData, Int32U Size
 *
 * Return: void
 *
 * Description: Read block of data from SPI
 *
 *************************************************************************/
void GLCD_SPI_ReceiveBlock (pInt8U pData, Int32U Size)
{
  while (Size)
  {
    *pData++ = GLCD_SPI_TranserByte(0xFFFF0);
    --Size;
  }
}
