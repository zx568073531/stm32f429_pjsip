
#include "systemCore.h"
#include "tusb.h"
#include "user_sd_init.h"


// Invoked when cdc when line state changed e.g connected/disconnected
void  tud_cdc_line_state_cb(uint8_t itf, bool dtr, bool rts) 
{
  (void) itf;
  (void) rts;

  // TODO set some indicator
  if ( dtr )
  {
    // Terminal connected
		printf("device con!\r\n");
  }else
  {
    // Terminal disconnected
		printf("device decon!\r\n");
  }
	
	printf("dtr %d , rts %d \r\n",dtr ,rts);
}

void tud_cdc_line_coding_cb(uint8_t itf, cdc_line_coding_t const* p_line_coding)
{

	printf("bit_rate %d \n\
					stop_bits %d \n\
					parity %d \n\
					data_bits %d \n",	p_line_coding->bit_rate,
  p_line_coding->stop_bits,
  p_line_coding->parity,
  p_line_coding->data_bits);
}

// Invoked when CDC interface received data from host
void tud_cdc_rx_cb(uint8_t itf)
{
  (void) itf;
}


static inline void board_vbus_sense_init(void)
{
  // Enable VBUS sense (B device) via pin PA9
  USB_OTG_FS->GCCFG &= ~USB_OTG_GCCFG_NOVBUSSENS;
  USB_OTG_FS->GCCFG |= USB_OTG_GCCFG_VBUSBSEN;
}


void UserUSB_Init(void)
{

  GPIO_InitTypeDef  GPIO_InitStruct = {0};
	
	NVIC_SetPriority(OTG_FS_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY );

  /* Configure USB FS GPIOs */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* Configure USB D+ D- Pins */
  GPIO_InitStruct.Pin = GPIO_PIN_11 | GPIO_PIN_12;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* Configure VBUS Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* ID Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // Enable USB OTG clock
  __HAL_RCC_USB_OTG_FS_CLK_ENABLE();
	
  board_vbus_sense_init();
}


//--------------------------------------------------------------------+
// Forward USB interrupt events to TinyUSB IRQ Handler
//--------------------------------------------------------------------+
void OTG_FS_IRQHandler(void)
{
  tud_int_handler(0);
}



// USB Device Driver task
// This top level thread process all usb events and invoke callbacks
void usb_device_task(void* param)
{
  (void) param;

  // This should be called after scheduler/kernel is started.
  // Otherwise it could cause kernel issue since USB IRQ handler does use RTOS queue API.
  tusb_init();

  // RTOS forever loop
  while (1)
  {
    // tinyusb device task
    tud_task();
  }
	
}


void cdc_task(void* params)
{
  (void) params;

  // RTOS forever loop
  while ( 1 )
  {
    // connected() check for DTR bit
    // Most but not all terminal client set this when making connection
    // if ( tud_cdc_connected() )
    {
      // There are data available
      if ( tud_cdc_available() )
      {
        uint8_t buf[64];

        // read and echo back
        uint32_t count = tud_cdc_read(buf, sizeof(buf));
        (void) count;

        // Echo back
        // Note: Skip echo by commenting out write() and write_flush()
        // for throughput test e.g
        //    $ dd if=/dev/zero of=/dev/ttyACM0 count=10000
        tud_cdc_write(buf, count);
        tud_cdc_write_flush();
      }
    }

    // For ESP32-S2 this delay is essential to allow idle how to run and reset wdt
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}



void UserUSB_ApplicationInit(void)
{
	UserSDcardInit();
	
	UserUSB_Init();

  // Create a task for tinyusb device stack
  (void) xTaskCreate( usb_device_task, "usbd", 4096, NULL, configMAX_PRIORITIES - 2, NULL);

  // Create CDC task
  (void) xTaskCreate( cdc_task, "cdc", 512, NULL, configMAX_PRIORITIES - 3, NULL);
	
}