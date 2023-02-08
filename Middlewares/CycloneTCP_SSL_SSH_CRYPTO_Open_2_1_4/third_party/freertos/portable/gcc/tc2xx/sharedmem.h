/*
 * sharedmem.h
 *
 *  Created on: 02.06.2015
 *      Author: AllanTengg
 */

#ifndef SHAREDMEM_H_
#define SHAREDMEM_H_

#define SHAREDFIFOWORDSIZE 1024
#define SHAREDFIFOMESSAGECOUNT 8
#define NUMCORES 3
#define SHAREDMEMINTPRIO 9

void SharedMemInit();
short int SharedMemSend(unsigned short dest_cpu_id, unsigned int *data, unsigned short len);
short int SharedMemReceive(unsigned int *data, unsigned short len, unsigned int timeout);
short int SharedMemDataAvailable();

#endif /* SHAREDMEM_H_ */
