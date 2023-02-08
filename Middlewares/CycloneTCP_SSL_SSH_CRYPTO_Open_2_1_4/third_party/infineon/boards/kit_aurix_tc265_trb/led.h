/*====================================================================
* Project:  Board Support Package (BSP)
* Function: LEDs
*
* Copyright HighTec EDV-Systeme GmbH 1982-2019
*====================================================================*/

#ifndef __LED_H__
#define __LED_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void LED_Init(int nr);
void LED_On(int nr);
void LED_Off(int nr);
void LED_Toggle(int nr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __LED_H__ */
