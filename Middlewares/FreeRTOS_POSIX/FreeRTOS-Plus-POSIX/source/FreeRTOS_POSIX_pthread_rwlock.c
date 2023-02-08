/*
 * Copyright (c) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/* C standard library includes. */
#include <stddef.h>
#include <string.h>

/* FreeRTOS+POSIX includes. */
#include "FreeRTOS_POSIX.h"
#include "FreeRTOS_POSIX/errno.h"
#include "FreeRTOS_POSIX/pthread.h"
#include "FreeRTOS_POSIX/utils.h"
#include "FreeRTOS_POSIX/semaphore.h"
#include "FreeRTOS_POSIX/pthread_key.h"
#include "slist.h"

#define INITIALIZED 1
#define NOT_INITIALIZED 0

#define CONCURRENT_READER_LIMIT  (32)

uint32_t timespec_to_timeoutms(const struct timespec *abstime);
static uint32_t read_lock_acquire(pthread_rwlock_t *rwlock, uint32_t timeout);
static uint32_t write_lock_acquire(pthread_rwlock_t *rwlock, uint32_t timeout);


/**
 * @brief get timespec to timeout ms
 *
 * See IEEE 1003.1
 */
uint32_t timespec_to_timeoutms(const struct timespec *abstime)
{
    uint32_t xDelay = portMAX_DELAY;
    int iStatus = 0;

    if( abstime != NULL )
    {
        /* If the provided timespec is invalid, still attempt to take the
         * semaphore without blocking, per POSIX spec. */


        /* # Already Check the abstime vailed.
        */
        // if( UTILS_ValidateTimespec( abstime ) == false )
        // {
        //     xDelay = 0;
        //     iStatus = EINVAL;
        // }
        // else
        // {
            struct timespec xCurrentTime = { 0 };

            /* Get current time */
            if( clock_gettime( CLOCK_REALTIME, &xCurrentTime ) != 0 )
            {
                iStatus = EINVAL;
            }
            else
            {
                iStatus = UTILS_AbsoluteTimespecToDeltaTicks( abstime, &xCurrentTime, &xDelay );
            }

            /* If abstime was in the past, still attempt to take the semaphore without
             * blocking, per POSIX spec. */
            if( iStatus == ETIMEDOUT )
            {
                xDelay = 0;
            }
        // }
    }

    return xDelay;
}

/**
 * @brief Initialize read-write lock object.
 *
 * See IEEE 1003.1
 */
int pthread_rwlock_init(pthread_rwlock_t *rwlock,
			const pthread_rwlockattr_t *attr)
{
    ( void ) xSemaphoreCreateCountingStatic(CONCURRENT_READER_LIMIT , CONCURRENT_READER_LIMIT , &rwlock->rd_sem);
    ( void ) xSemaphoreCreateCountingStatic(1, 1, &rwlock->wr_sem );
    ( void ) xSemaphoreCreateCountingStatic(1, 1, &rwlock->reader_active );

	rwlock->wr_owner = NULL;
	rwlock->status = INITIALIZED;
	return 0;
}

/**
 * @brief Destroy read-write lock object.
 *
 * See IEEE 1003.1
 */
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock)
{
	if (rwlock->status == NOT_INITIALIZED) {
		return EINVAL;
	}

	if (rwlock->wr_owner != NULL) {
		return EBUSY;
	}

	if (rwlock->status == INITIALIZED) {
		rwlock->status = NOT_INITIALIZED;
		return 0;
	}

	return EINVAL;
}

/**
 * @brief Lock a read-write lock object for reading.
 *
 * API behaviour is unpredictable if number of concurrent reader
 * lock held is greater than CONCURRENT_READER_LIMIT.
 *
 * See IEEE 1003.1
 */
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock)
{
	if (rwlock->status == NOT_INITIALIZED) {
		return EINVAL;
	}

	return read_lock_acquire(rwlock, portMAX_DELAY);
}

/**
 * @brief Lock a read-write lock object for reading within specific time.
 *
 * API behaviour is unpredictable if number of concurrent reader
 * lock held is greater than CONCURRENT_READER_LIMIT.
 *
 * See IEEE 1003.1
 */
int pthread_rwlock_timedrdlock(pthread_rwlock_t *rwlock,
			       const struct timespec *abstime)
{
	uint32_t timeout;
	uint32_t ret = 0U;

	if (rwlock->status == NOT_INITIALIZED || abstime->tv_nsec < 0 ||
	    abstime->tv_nsec > NANOSECONDS_PER_SECOND) {
		return EINVAL;
	}

	timeout = timespec_to_timeoutms(abstime);

	if (read_lock_acquire(rwlock, timeout) != 0U) {
		ret = ETIMEDOUT;
	}

	return ret;
}

/**
 * @brief Lock a read-write lock object for reading immediately.
 *
 * API behaviour is unpredictable if number of concurrent reader
 * lock held is greater than CONCURRENT_READER_LIMIT.
 *
 * See IEEE 1003.1
 */
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock)
{
	if (rwlock->status == NOT_INITIALIZED) {
		return EINVAL;
	}

	return read_lock_acquire(rwlock, 0);
}

/**
 * @brief Lock a read-write lock object for writing.
 *
 * Write lock does not have priority over reader lock,
 * threads get lock based on priority.
 *
 * See IEEE 1003.1
 */
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock)
{
	if (rwlock->status == NOT_INITIALIZED) {
		return EINVAL;
	}

	return write_lock_acquire(rwlock, portMAX_DELAY);
}

/**
 * @brief Lock a read-write lock object for writing within specific time.
 *
 * Write lock does not have priority over reader lock,
 * threads get lock based on priority.
 *
 * See IEEE 1003.1
 */
int pthread_rwlock_timedwrlock(pthread_rwlock_t *rwlock,
			       const struct timespec *abstime)
{
	uint32_t timeout;
	uint32_t ret = 0U;

	if (rwlock->status == NOT_INITIALIZED || abstime->tv_nsec < 0 ||
	    abstime->tv_nsec > NANOSECONDS_PER_SECOND) {
		return EINVAL;
	}

	timeout = timespec_to_timeoutms(abstime);

	if (write_lock_acquire(rwlock, timeout) != 0U) {
		ret = ETIMEDOUT;
	}

	return ret;
}

/**
 * @brief Lock a read-write lock object for writing immediately.
 *
 * Write lock does not have priority over reader lock,
 * threads get lock based on priority.
 *
 * See IEEE 1003.1
 */
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock)
{
	if (rwlock->status == NOT_INITIALIZED) {
		return EINVAL;
	}

	return write_lock_acquire(rwlock, 0);
}

/**
 *
 * @brief Unlock a read-write lock object.
 *
 * See IEEE 1003.1
 */
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock)
{
	if (rwlock->status == NOT_INITIALIZED) {
		return EINVAL;
	}

	if (xTaskGetApplicationTaskTag( NULL ) == rwlock->wr_owner) {
		/* Write unlock */
		rwlock->wr_owner = NULL;
		xSemaphoreGive(( SemaphoreHandle_t ) &rwlock->reader_active);
		xSemaphoreGive(( SemaphoreHandle_t ) &rwlock->wr_sem);
	} else {
		/* Read unlock */
		if (uxSemaphoreGetCount(( SemaphoreHandle_t ) &rwlock->rd_sem) ==
				    (CONCURRENT_READER_LIMIT - 1)) {
			/* Last read lock, unlock writer */
			xSemaphoreGive(( SemaphoreHandle_t ) &rwlock->reader_active);
		}

		xSemaphoreGive(( SemaphoreHandle_t ) &rwlock->rd_sem);
	}
	return 0;
}


static uint32_t read_lock_acquire(pthread_rwlock_t *rwlock, uint32_t timeout)
{
	uint32_t ret = 0U;

	if (xSemaphoreTake(( SemaphoreHandle_t ) &rwlock->wr_sem, timeout) == 0) {
		xSemaphoreTake(( SemaphoreHandle_t ) &rwlock->reader_active, 0);
		xSemaphoreTake(( SemaphoreHandle_t ) &rwlock->rd_sem, 0);
		xSemaphoreGive(( SemaphoreHandle_t ) &rwlock->wr_sem);
	} else {
		ret = EBUSY;
	}

	return ret;
}

static uint32_t write_lock_acquire(pthread_rwlock_t *rwlock, uint32_t timeout)
{
	uint32_t ret = 0U;
	int64_t elapsed_time, st_time = xTaskGetTickCount();
	uint32_t k_timeout;

	k_timeout = timeout;

	/* waiting for release of write lock */
	if (xSemaphoreTake(( SemaphoreHandle_t ) &rwlock->wr_sem, k_timeout) == 0) {
		/* update remaining timeout time for 2nd sem */
		if (timeout != portMAX_DELAY) {
			elapsed_time = xTaskGetTickCount() - st_time;
			timeout = timeout <= elapsed_time ? 0 :
				  timeout - elapsed_time;
		}

		k_timeout = timeout;

		/* waiting for reader to complete operation */
		if (xSemaphoreTake(( SemaphoreHandle_t ) &rwlock->reader_active, k_timeout) == 0) {
			rwlock->wr_owner = xTaskGetApplicationTaskTag(NULL);
		} else {
			xSemaphoreGive(( SemaphoreHandle_t ) &rwlock->wr_sem);
			ret = EBUSY;
		}

	} else {
		ret = EBUSY;
	}
	return ret;
}
