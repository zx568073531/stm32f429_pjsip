/**
 * @file dtls_server.h
 * @brief DTLS server
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2022 Oryx Embedded SARL. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.1.4
 **/

#ifndef _DTLS_SERVER_H
#define _DTLS_SERVER_H

//Dependencies
#include "tls.h"
#include "tls_cache.h"
#include "error.h"

//DTLS server support
#ifndef DTLS_SERVER_SUPPORT
   #define DTLS_SERVER_SUPPORT ENABLED
#elif (DTLS_SERVER_SUPPORT != ENABLED && DTLS_SERVER_SUPPORT != DISABLED)
   #error DTLS_SERVER_SUPPORT parameter is not valid
#endif

//Stack size required to run the DTLS server
#ifndef DTLS_SERVER_TASK_STACK_SIZE
   #define DTLS_SERVER_TASK_STACK_SIZE 750
#elif (DTLS_SERVER_TASK_STACK_SIZE < 1)
   #error DTLS_SERVER_TASK_STACK_SIZE parameter is not valid
#endif

//Priority at which the DTLS server should run
#ifndef DTLS_SERVER_TASK_PRIORITY
   #define DTLS_SERVER_TASK_PRIORITY OS_TASK_PRIORITY_NORMAL
#endif

//Maximum number of simultaneous DTLS sessions
#ifndef DTLS_SERVER_MAX_SESSIONS
   #define DTLS_SERVER_MAX_SESSIONS 10
#elif (DTLS_SERVER_MAX_SESSIONS < 1)
   #error DTLS_SERVER_MAX_SESSIONS parameter is not valid
#endif

//Size of the DTLS session cache
#ifndef DTLS_SERVER_CACHE_SIZE
   #define DTLS_SERVER_CACHE_SIZE 10
#elif (DTLS_SERVER_CACHE_SIZE < 0)
   #error DTLS_SERVER_CACHE_SIZE parameter is not valid
#endif

//DTLS server tick interval
#ifndef DTLS_SERVER_TICK_INTERVAL
   #define DTLS_SERVER_TICK_INTERVAL 500
#elif (DTLS_SERVER_TICK_INTERVAL < 100)
   #error DTLS_SERVER_TICK_INTERVAL parameter is not valid
#endif

//DTLS session timeout
#ifndef DTLS_SERVER_SESSION_TIMEOUT
   #define DTLS_SERVER_SESSION_TIMEOUT 0
#elif (DTLS_SERVER_SESSION_TIMEOUT < 0)
   #error DTLS_SERVER_SESSION_TIMEOUT parameter is not valid
#endif

//Size of buffer used for input/output operations
#ifndef DTLS_SERVER_BUFFER_SIZE
   #define DTLS_SERVER_BUFFER_SIZE 4096
#elif (DTLS_SERVER_BUFFER_SIZE < 1)
   #error DTLS_SERVER_BUFFER_SIZE parameter is not valid
#endif

//Maximum size of the cookie secret
#ifndef DTLS_SERVER_MAX_COOKIE_SECRET_SIZE
   #define DTLS_SERVER_MAX_COOKIE_SECRET_SIZE 32
#elif (DTLS_SERVER_MAX_COOKIE_SECRET_SIZE < 1)
   #error DTLS_SERVER_MAX_COOKIE_SECRET_SIZE parameter is not valid
#endif

//Forward declaration of DtlsServerContext structure
struct _DtlsServerContext;
#define DtlsServerContext struct _DtlsServerContext

//Forward declaration of DtlsClientSession structure
struct _DtlsClientSession;
#define DtlsClientSession struct _DtlsClientSession

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Random data generation callback function
 **/

typedef error_t (*DtlsServerRandCallback)(uint8_t *data, size_t length);


/**
 * @brief DTLS session initialization callback
 **/

typedef error_t (*DtlsServerSessionInitCallback)(DtlsClientSession *session,
   TlsContext *dtlsContext);


/**
 * @brief Incoming datagram processing callback
 **/

typedef error_t (*DtlsServerDatagramCallback)(DtlsClientSession *session,
   const SOCKADDR_IN *remoteIpAddr, const uint8_t *data, size_t length);


/**
 * @brief DTLS server tick callback
 **/

typedef void (*DtlsServerTickCallback)(DtlsServerContext *context);


/**
 * @brief DTLS server settings
 **/

typedef struct
{
   uint16_t port;                                      ///<DTLS server port number
   DtlsServerRandCallback randCallback;                ///<Random data generation callback function
   DtlsServerSessionInitCallback sessionInitCallback;  ///<DTLS session initialization callback
   DtlsServerDatagramCallback processDatagramCallback; ///<Incoming datagram processing callback
   DtlsServerTickCallback tickCallback;                ///<DTLS server tick callback
} DtlsServerSettings;


/**
 * @brief DTLS client session
 **/

struct _DtlsClientSession
{
   DtlsServerContext *context;
   SOCKADDR_IN clientIpAddr;
   TlsContext *dtlsContext;
   systime_t timestamp;
};


/**
 * @brief DTLS server context
 **/

struct _DtlsServerContext
{
   DtlsServerSettings settings;                              ///<User settings
   uint_t counter;
   SOCKET socket;                                            ///<Underlying UDP socket
   SOCKADDR_IN clientIpAddr;                                 ///<Client's IP address
   TlsCache *dtlsCache;                                      ///<DTLS session cache
   DtlsClientSession session[DTLS_SERVER_MAX_SESSIONS];      ///<DTLS sessions
   uint8_t cookieSecret[DTLS_SERVER_MAX_COOKIE_SECRET_SIZE]; ///<Cookie secret
   size_t cookieSecretLen;                                   ///<Length of the cookie secret, in bytes
   uint8_t buffer[DTLS_SERVER_BUFFER_SIZE];
   size_t bufferLen;
};


//DTLS server related functions
void dtlsServerGetDefaultSettings(DtlsServerSettings *settings);

error_t dtlsServerInit(DtlsServerContext *context,
   const DtlsServerSettings *settings);

error_t dtlsServerStart(DtlsServerContext *context);
void dtlsServerTask(DtlsServerContext *context);

error_t dtlsServerAcceptSession(DtlsServerContext *context,
   DtlsClientSession *session, const SOCKADDR_IN *remoteIpAddr);

void dtlsServerDeleteSession(DtlsClientSession *session);

error_t dtlsServerSendDatagram(DtlsClientSession *session,
   const void *data, size_t length);

void dtlsServerTick(DtlsServerContext *context);

error_t dtlsServerSendCallback(void *handle, const void *data,
   size_t length, size_t *written, uint_t flags);

error_t dtlsServerReceiveCallback(void *handle, void *data,
   size_t size, size_t *received, uint_t flags);

error_t dtlsServerCookieGenerateCallback(TlsContext *context,
   const DtlsClientParameters *clientParams, uint8_t *cookie,
   size_t *length, void *param);

error_t dtlsServerCookieVerifyCallback(TlsContext *context,
   const DtlsClientParameters *clientParams, const uint8_t *cookie,
   size_t length, void *param);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
