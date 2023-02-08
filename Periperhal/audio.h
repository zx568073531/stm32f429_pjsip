#ifndef __AUDIO_H_
#define __AUDIO_H_

#include <stdint.h>



void Audio_Config_Play(void);
void Audio_Config_Rec(void);
void Audio_Config_FullDuplex(void);
void Audio_StreamStop(void);

void Audio_Set_Volmue(uint8_t val);

int32_t AudioInterfaceInit(uint8_t tx_event , uint8_t rx_event);
int32_t AudioWriteData(const void *src, uint32_t size, uint32_t *bytes_written, uint32_t ticks_to_wait);
int32_t AudioReadData(const void *dest, uint32_t size, uint32_t *bytes_read, uint32_t ticks_to_wait);


#endif
