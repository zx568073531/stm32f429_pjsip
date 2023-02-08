
/**
 * @file FreeRTOS_POSIX_pthread_key.c
 * @brief Implementation of key functions in pthread.h
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


SemaphoreHandle_t pthread_key_sem;

/**
 * @brief Create a mutex for key thread-specific data
 * 
 * See IEEE 1003.1
 */
int pthread_key_init(void)
{
    int iStatus = 0;

    pthread_key_sem = xSemaphoreCreateMutex();
    
    if(pthread_key_sem == NULL )
    {
        /* Failed to create mutex. Set error EAGAIN and free mutex object. */
        iStatus = EAGAIN;
    }
    
    return iStatus;
}

/**
 * @brief Create a key for thread-specific data
 *
 * See IEEE 1003.1
 */
int pthread_key_create(pthread_key_t *key,
		void (*destructor)(void *))
{
	pthread_key_obj *new_key;

	*key = NULL;

	new_key = pvPortMalloc(sizeof(pthread_key_obj));

	if (new_key == NULL) {
		return ENOMEM;
	}
	
	memset(new_key , 0 , sizeof(pthread_key_obj));

	sys_slist_init(&(new_key->key_data_l));

	new_key->destructor = destructor;
	*key = (void *)new_key;

	return 0;
}

/**
 * @brief Delete a key for thread-specific data
 *
 * See IEEE 1003.1
 */
int pthread_key_delete(pthread_key_t key)
{
	pthread_key_obj *key_obj = (pthread_key_obj *)key;
	pthread_key_data *key_data;
	sys_snode_t *node_l, *next_node_l;

	xSemaphoreTake(pthread_key_sem, portMAX_DELAY);

	/* Delete thread-specific elements associated with the key */
	SYS_SLIST_FOR_EACH_NODE_SAFE(&(key_obj->key_data_l),
			node_l, next_node_l) {

		/* Remove the object from the list key_data_l */
		key_data = (pthread_key_data *)
			sys_slist_get(&(key_obj->key_data_l));

		/* Deallocate the object's memory */
		vPortFree((void *)key_data);
	}

	vPortFree((void *)key_obj);

	xSemaphoreGive(pthread_key_sem);

	return 0;
}

/**
 * @brief Associate a thread-specific value with a key
 *
 * See IEEE 1003.1
 */
int pthread_setspecific(pthread_key_t key, const void *value)
{
	pthread_key_obj *key_obj = (pthread_key_obj *)key;
	pthread_internal_t *thread = (pthread_internal_t*)pthread_self();
	pthread_key_data *key_data;
	pthread_thread_data *thread_spec_data;
	sys_snode_t *node_l;
	int retval = 0;

	/* Traverse the list of keys set by the thread, looking for key.
	 * If the key is already in the list, re-assign its value.
	 * Else add the key to the thread's list.
	 */
	xSemaphoreTake(pthread_key_sem, portMAX_DELAY);

	SYS_SLIST_FOR_EACH_NODE(&(thread->key_list), node_l) {

			thread_spec_data = (pthread_thread_data *)node_l;

			if (thread_spec_data->key == key_obj) {

				/* Key is already present so
				 * associate thread specific data
				 */
				thread_spec_data->spec_data = (void *)value;
				goto out;
			}
	}

	if (node_l == NULL) {
		key_data = pvPortMalloc(sizeof(pthread_key_data));

		if (key_data == NULL) {
			retval = ENOMEM;
			goto out;

		} else {
			/* Associate thread specific data, initialize new key */
			key_data->thread_data.key = key;
			key_data->thread_data.spec_data = (void *)value;

			/* Append new thread key data to thread's key list */
			sys_slist_append((&thread->key_list),
				(sys_snode_t *)(&key_data->thread_data));

			/* Append new key data to the key object's list */
			sys_slist_append(&(key_obj->key_data_l),
					(sys_snode_t *)key_data);
		}
	}

out:
	xSemaphoreGive(pthread_key_sem);

	return retval;
}

/**
 * @brief Get the thread-specific value associated with the key
 *
 * See IEEE 1003.1
 */
void *pthread_getspecific(pthread_key_t key)
{
	pthread_key_obj *key_obj = (pthread_key_obj *)key;
	pthread_internal_t *thread = (pthread_internal_t*)pthread_self();
	pthread_thread_data *thread_spec_data;
	void *value = NULL;
	sys_snode_t *node_l;

	xSemaphoreTake(pthread_key_sem, portMAX_DELAY);

	node_l = sys_slist_peek_head(&(thread->key_list));

	/* Traverse the list of keys set by the thread, looking for key */

	SYS_SLIST_FOR_EACH_NODE(&(thread->key_list), node_l) {
		thread_spec_data = (pthread_thread_data *)node_l;
		if (thread_spec_data->key == key_obj) {
			/* Key is present, so get the set thread data */
			value = thread_spec_data->spec_data;
			break;
		}
	}

	xSemaphoreGive(pthread_key_sem);

	return value;
}
