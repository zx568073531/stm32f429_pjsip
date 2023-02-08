/*
 * Amazon FreeRTOS POSIX V1.1.0
 * Copyright (C) 2018 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/**
 * @file FreeRTOS_POSIX.h
 * @brief FreeRTOS+POSIX header.
 *
 * This file must be included before all other FreeRTOS+POSIX includes.
 */

#ifndef _FREERTOS_POSIX_H_
#define _FREERTOS_POSIX_H_

#include "slist.h"

/* FreeRTOS+POSIX platform-specific configuration headers. */
#include "FreeRTOS_POSIX_portable.h"
#include "FreeRTOS_POSIX_portable_default.h"

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "event_groups.h"
#include "semphr.h"
#include "task.h"

/* FreeRTOS+POSIX data types and internal structs. */
#include "FreeRTOS_POSIX/sys/types.h"
#include "FreeRTOS_POSIX_internal.h"


/**
 * @brief Thread attribute object.
 */
typedef struct pthread_attr_internal
{
    uint16_t usStackSize;                /**< Stack size. */
    uint16_t usSchedPriorityDetachState; /**< Schedule priority 15 bits (LSB) Detach state: 1 bits (MSB) */
} pthread_attr_internal_t;

/**
 * @brief Thread object.
 */
typedef struct pthread_internal
{
    pthread_attr_internal_t xAttr;        /**< Thread attributes. */
    void * ( *pvStartRoutine )( void * ); /**< Application thread function. */
    void * xTaskArg;                      /**< Arguments for application thread function. */
    TaskHandle_t xTaskHandle;             /**< FreeRTOS task handle. */
    StaticSemaphore_t xJoinBarrier;       /**< Synchronizes the two callers of pthread_join. */
    StaticSemaphore_t xJoinMutex;         /**< Ensures that only one other thread may join this thread. */
    void * xReturn;                       /**< Return value of pvStartRoutine. */

	/* List of keys that thread has called pthread_setspecific() on */
	sys_slist_t key_list;

} pthread_internal_t;


#endif /* _FREERTOS_POSIX_H_ */
