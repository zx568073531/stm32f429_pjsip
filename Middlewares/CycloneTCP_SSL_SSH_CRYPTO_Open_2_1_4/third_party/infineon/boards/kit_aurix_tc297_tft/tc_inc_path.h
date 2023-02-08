/*====================================================================
* Project:  Board Support Package (BSP)
* Function: macros for handling different AURIX TC27x devices and boards
*
* Copyright HighTec EDV-Systeme GmbH 1982-2019
*====================================================================*/

#ifndef __TC_INC_PATH_H__
#define __TC_INC_PATH_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define TCPATH tc29xb
#define TC_STR(s) # s
#define TC_INCLUDE(f) TC_STR(f)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TC_INC_PATH_H__ */
