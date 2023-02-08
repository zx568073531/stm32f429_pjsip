/**
 * @file dtls_server.c
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

//Switch to the appropriate trace level
#define TRACE_LEVEL TRACE_LEVEL_DEBUG

#define _WINERROR_

//Dependencies
#include <winsock2.h>
#include "dtls_server.h"
#include "debug.h"

//Check TCP/IP stack configuration
#if (DTLS_SERVER_SUPPORT == ENABLED)


/**
 * @brief Initialize settings with default values
 * @param[out] settings Structure that contains DTLS server settings
 **/

void dtlsServerGetDefaultSettings(DtlsServerSettings *settings)
{
   //Listen to default port
   settings->port = 0;

   //Random data generation callback function
   settings->randCallback = NULL;
   //DTLS session initialization callback function
   settings->sessionInitCallback = NULL;
   //Incoming datagram processing callback
   settings->processDatagramCallback = NULL;
   //DTLS server tick callback
   settings->tickCallback = NULL;
}


/**
 * @brief DTLS server initialization
 * @param[in] context Pointer to the DTLS server context
 * @param[in] settings HTTP server specific settings
 * @return Error code
 **/

error_t dtlsServerInit(DtlsServerContext *context,
   const DtlsServerSettings *settings)
{
   int_t ret;
   SOCKADDR_IN serverAddr;
   DWORD timeout;

   //Debug message
   TRACE_INFO("Initializing DTLS server...\r\n");

   //Ensure the parameters are valid
   if(context == NULL || settings == NULL)
      return ERROR_INVALID_PARAMETER;

   //Clear the DTLS server context
   memset(context, 0, sizeof(DtlsServerContext));

   //Save user settings
   context->settings = *settings;

   //Open a UDP socket
   context->socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
   //Failed to open socket?
   if(context->socket < 0)
      return ERROR_OPEN_FAILED;

   //Server port
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_addr.s_addr = INADDR_ANY;
   serverAddr.sin_port = htons(settings->port);

   //Bind the socket to the relevant port number
   ret = bind(context->socket, (PSOCKADDR) &serverAddr, sizeof(serverAddr));
   //Unable to bind the socket to the desired port?
   if(ret < 0)
      return ERROR_FAILURE;

   //Timeout in milliseconds
   timeout = DTLS_SERVER_TICK_INTERVAL;

   //Set the timeout for blocking receive calls
   ret = setsockopt(context->socket, SOL_SOCKET, SO_RCVTIMEO,
      (char_t *) &timeout, sizeof(timeout));
   //Any error to report?
   if(ret < 0)
      return ERROR_FAILURE;

#if (DTLS_SERVER_CACHE_SIZE > 0)
   //DTLS session cache initialization
   context->dtlsCache = tlsInitCache(DTLS_SERVER_CACHE_SIZE);
   //Any error to report?
   if(context->dtlsCache == NULL)
   {
      //Debug message
      TRACE_ERROR("Error: TLS cache initialization failed\r\n");
   }
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Start DTLS server
 * @param[in] context Pointer to the DTLS server context
 * @return Error code
 **/

error_t dtlsServerStart(DtlsServerContext *context)
{
   OsTask *task;

   //Debug message
   TRACE_INFO("Starting DTLS server...\r\n");

   //Create the DTLS server task
   task = osCreateTask("DTLS Server", (OsTaskCode) dtlsServerTask,
      context, DTLS_SERVER_TASK_STACK_SIZE, DTLS_SERVER_TASK_PRIORITY);

   //Unable to create the task?
   if(task == OS_INVALID_HANDLE)
      return ERROR_OUT_OF_RESOURCES;

   //The DTLS server has successfully started
   return NO_ERROR;
}


/**
 * @brief DTLS server task
 * @param[in] context Pointer to the DTLS server context
 **/

void dtlsServerTask(DtlsServerContext *context)
{
   error_t error;
   int_t n;
   int_t clientIpAddrLen;
   uint_t i;
   size_t length;
   systime_t time;
   DtlsClientSession *session;
   DtlsClientSession *firstFreeSession;
   DtlsClientSession *oldestSession;

   //Main loop
   while(1)
   {
      //Socket address length
      clientIpAddrLen = sizeof(SOCKADDR_IN);

      //Wait for an incoming datagram
      n = recvfrom(context->socket, context->buffer, DTLS_SERVER_BUFFER_SIZE, 0,
         (PSOCKADDR) &context->clientIpAddr, &clientIpAddrLen);

      //Any datagram received?
      if(n > 0)
      {
         //Save the length of the incoming datagram
         context->bufferLen = n;

         //Get current time
         time = osGetSystemTime();

         //Keep track of the first free entry
         firstFreeSession = NULL;
         //Keep track of the oldest entry
         oldestSession = NULL;

         //Demultiplexing of incoming datagrams into separate DTLS sessions
         for(i = 0; i < DTLS_SERVER_MAX_SESSIONS; i++)
         {
            //Point to the current DTLS session
            session = &context->session[i];

            //Valid DTLS session?
            if(session->dtlsContext != NULL)
            {
               //Determine if a DTLS session matches the incoming datagram
               if(context->clientIpAddr.sin_family == session->clientIpAddr.sin_family &&
                  context->clientIpAddr.sin_addr.S_un.S_addr == session->clientIpAddr.sin_addr.S_un.S_addr &&
                  context->clientIpAddr.sin_port == session->clientIpAddr.sin_port)
               {
                  //Save current time
                  session->timestamp = osGetSystemTime();

                  //The UDP datagram is passed to the DTLS implementation
                  error = tlsRead(session->dtlsContext, context->buffer,
                     DTLS_SERVER_BUFFER_SIZE, &length, 0);

                  //Check status code
                  if(!error)
                  {
                     //Debug message
                     TRACE_DEBUG("Datagram received from client %s port %u (%u bytes)...\r\n",
                        inet_ntoa(session->clientIpAddr.sin_addr),
                        ntohs(session->clientIpAddr.sin_port));

                     //Dump the contents of the datagram for debugging purpose
                     TRACE_DEBUG_ARRAY("  ", context->buffer, length);

                     //Any registered callback?
                     if(context->settings.processDatagramCallback != NULL)
                     {
                        //Pass the incoming datagram to the user
                        error = context->settings.processDatagramCallback(session,
                           &session->clientIpAddr, context->buffer, length);
                     }
                  }
                  else if(error == ERROR_TIMEOUT || error == ERROR_WOULD_BLOCK)
                  {
                     //The UDP datagram contains DTLS handshake messages
                  }
                  else
                  {
                     //Debug message
                     TRACE_INFO("Failed to read datagram (error = %d)!\r\n", error);
                     //Release DTLS session
                     dtlsServerDeleteSession(session);
                  }

                  //We are done
                  break;
               }
               else
               {
                  //Keep track of the oldest entry
                  if(oldestSession == NULL)
                  {
                     oldestSession = session;
                  }
                  else if((time - session->timestamp) > (time - oldestSession->timestamp))
                  {
                     oldestSession = session;
                  }
               }
            }
            else
            {
               //Keep track of the first free entry
               if(firstFreeSession == NULL)
               {
                  firstFreeSession = session;
               }
            }
         }

         //No matching DTLS session?
         if(i >= DTLS_SERVER_MAX_SESSIONS)
         {
            //Any DTLS session available for use in the table?
            if(firstFreeSession != NULL)
            {
               session = firstFreeSession;
            }
            else
            {
               //The oldest DTLS session is closed whenever the table runs out of space
               tlsShutdown(oldestSession->dtlsContext);
               dtlsServerDeleteSession(oldestSession);

               //Point to the DTLS session to be reused
               session = oldestSession;
            }

            //Process the new connection attempt
            error = dtlsServerAcceptSession(context, session, &context->clientIpAddr);
         }
      }
      else
      {
         //No datagram received
         context->bufferLen = 0;
      }

      //Handle periodic operations
      dtlsServerTick(context);
   }
}


/**
 * @brief Accept a new session connection from a client
 * @param[in] context Pointer to the DTLS server context
 * @param[in] session Pointer to the DTLS session
 * @param[in] remoteIpAddr Client address
 * @return Error code
 **/

error_t dtlsServerAcceptSession(DtlsServerContext *context,
   DtlsClientSession *session, const SOCKADDR_IN *remoteIpAddr)
{
   error_t error;
   TlsState state;

   //Clear DTLS session
   memset(session, 0, sizeof(DtlsClientSession));

   //Initialize session parameters
   session->context = context;
   session->clientIpAddr = context->clientIpAddr;
   session->timestamp = osGetSystemTime();

   //Allocate DTLS context
   session->dtlsContext = tlsInit();

   //DTLS context successfully created?
   if(session->dtlsContext != NULL)
   {
      //Start of exception handling block
      do
      {
         //Select server operation mode
         error = tlsSetConnectionEnd(session->dtlsContext,
            TLS_CONNECTION_END_SERVER);
         //Any error to report?
         if(error)
            break;

         //Use datagram transport protocol
         error = tlsSetTransportProtocol(session->dtlsContext,
            TLS_TRANSPORT_PROTOCOL_DATAGRAM);
         //Any error to report?
         if(error)
            break;

         //Set send and receive callbacks (I/O abstraction layer)
         error = tlsSetSocketCallbacks(session->dtlsContext, dtlsServerSendCallback,
            dtlsServerReceiveCallback, (TlsSocketHandle) session);
         //Any error to report?
         if(error)
            break;

         //Set cookie generation/verification callbacks
         error = tlsSetCookieCallbacks(session->dtlsContext,
            dtlsServerCookieGenerateCallback, dtlsServerCookieVerifyCallback,
            session);
         //Any error to report?
         if(error)
            break;

#if (DTLS_SERVER_CACHE_SIZE > 0)
         //Session cache that will be used to save/resume DTLS sessions
         error = tlsSetCache(session->dtlsContext, context->dtlsCache);
         //Any error to report?
         if(error)
            break;
#endif
         //Invoke user-defined callback, if any
         if(context->settings.sessionInitCallback != NULL)
         {
            //Perform TLS related initialization
            error = context->settings.sessionInitCallback(session,
               session->dtlsContext);
            //Any error to report?
            if(error)
               break;
         }

         //Initiate DTLS handshake
         error = tlsConnect(session->dtlsContext);
         //Any error to report?
         if(error != NO_ERROR && error != ERROR_WOULD_BLOCK)
            break;

         //Retrieve current state
         state = tlsGetState(session->dtlsContext);

         //The DTLS server verifies the cookie and proceeds with the handshake
         //only if it is valid
         if(state == TLS_STATE_INIT ||
            state == TLS_STATE_CLIENT_HELLO ||
            state == TLS_STATE_CLOSED)
         {
            //Do not allocate connection state yet if the stateless cookie
            //exchange is being performed
            error = ERROR_WRONG_COOKIE;
            break;
         }

         //The DTLS implementation decides to continue with the connection
         error = NO_ERROR;

         //Debug message
         TRACE_INFO("DTLS session #%u established with client %s port %u...\r\n",
            ++context->counter, inet_ntoa(remoteIpAddr->sin_addr),
            ntohs(remoteIpAddr->sin_port));

         //End of exception handling block
      } while(0);

      //Check status code
      if(error)
      {
         //Release DTLS context
         tlsFree(session->dtlsContext);
         session->dtlsContext = NULL;
      }
   }
   else
   {
      //Failed to allocate DTLS context
      error = ERROR_OUT_OF_MEMORY;
   }

   //Return status code
   return error;
}


/**
 * @brief Delete DTLS session
 * @param[in] session Pointer to the DTLS session
 **/

void dtlsServerDeleteSession(DtlsClientSession *session)
{
   //Debug message
   TRACE_INFO("DTLS session closed...\r\n");

   //Release DTLS context
   tlsFree(session->dtlsContext);
   session->dtlsContext = NULL;
}


/**
 * @brief Send a datagram to a DTLS client
 * @param[in] session Pointer to the DTLS session
 * @param[in] data Pointer to a buffer containing the data to be transmitted
 * @param[in] length Number of data bytes to send
 * @return Error code
 **/

error_t dtlsServerSendDatagram(DtlsClientSession *session,
   const void *data, size_t length)
{
   //Check parameters
   if(session == NULL)
      return ERROR_INVALID_PARAMETER;
   if(data == NULL && length != 0)
      return ERROR_INVALID_PARAMETER;

   //Debug message
   TRACE_INFO("Sending datagram to client %s port %u (%u bytes)...\r\n",
      inet_ntoa(session->clientIpAddr.sin_addr),
      ntohs(session->clientIpAddr.sin_port), length);

   //Dump the contents of the datagram for debugging purpose
   TRACE_DEBUG_ARRAY("  ", data, length);

   //Send datagram
   return tlsWrite(session->dtlsContext, data, length, NULL, 0);
}


/**
 * @brief Handle periodic operations
 * @param[in] context Pointer to the DTLS server context
 **/

void dtlsServerTick(DtlsServerContext *context)
{
   error_t error;
   uint_t i;
   DtlsClientSession *session;

#if (DTLS_SERVER_SESSION_TIMEOUT > 0)
   //Get current time
   systime_t time = osGetSystemTime();
#endif

   //Loop through DTLS sessions
   for(i = 0; i < DTLS_SERVER_MAX_SESSIONS; i++)
   {
      //Point to the current DTLS session
      session = &context->session[i];

      //Valid DTLS session?
      if(session->dtlsContext != NULL)
      {
#if (DTLS_SERVER_SESSION_TIMEOUT > 0)
         //Implementations should limit the lifetime of established sessions
         if(timeCompare(time, session->timestamp + DTLS_SERVER_SESSION_TIMEOUT) >= 0)
         {
            //Debug message
            TRACE_INFO("DTLS session timeout!\r\n");

            //Send a close notify alert to the client
            tlsShutdown(session->dtlsContext);
            //Release DTLS session
            dtlsServerDeleteSession(session);
         }
         else
#endif
         {
            //Continue DTLS handshake
            error = tlsConnect(session->dtlsContext);

            //Any error to report?
            if(error != NO_ERROR &&
               error != ERROR_TIMEOUT &&
               error != ERROR_WOULD_BLOCK)
            {
               //Debug message
               TRACE_INFO("DTLS handshake failed (error = %d)!\r\n", error);

               //Release DTLS session
               dtlsServerDeleteSession(session);
            }
         }
      }
   }

   //Any registered callback?
   if(context->settings.tickCallback != NULL)
   {
      //Pass incoming datagram to the proper connection
      context->settings.tickCallback(context);
   }
}


/**
 * @brief DTLS send callback
 * @param[in] handle Handle referencing a client connection
 * @param[in] data Pointer to a buffer containing the data to be transmitted
 * @param[in] length Number of data bytes to send
 * @param[out] written Number of bytes that have been transmitted
 * @param[in] flags Unused parameter
 * @return Error code
 **/

error_t dtlsServerSendCallback(void *handle, const void *data,
   size_t length, size_t *written, uint_t flags)
{
   error_t error;
   int_t n;
   DtlsServerContext *context;
   DtlsClientSession *session;

   //Point to the DTLS session
   session = handle;
   //Point to the DTLS server context
   context = session->context;

   //Send datagram
   n = sendto(context->socket, data, length, 0,
      (PSOCKADDR) &session->clientIpAddr, sizeof(SOCKADDR_IN));

   //Check return value
   if(n > 0)
   {
      //Total number of data that have been written
      *written = n;
      //Successful write operation
      error = NO_ERROR;
   }
   else
   {
      //Timeout error?
      if(WSAGetLastError() == WSAEWOULDBLOCK)
         error = ERROR_WOULD_BLOCK;
      else
         error = ERROR_WRITE_FAILED;
   }

   //Return status code
   return error;
}


/**
 * @brief DTLS receive callback
 * @param[in] handle Handle referencing a client connection
 * @param[out] data Buffer where to store the incoming data
 * @param[in] size Maximum number of bytes that can be received
 * @param[out] received Number of bytes that have been received
 * @param[in] flags Unused parameter
 * @return Error code
 **/

error_t dtlsServerReceiveCallback(void *handle, void *data,
   size_t size, size_t *received, uint_t flags)
{
   error_t error;
   DtlsServerContext *context;
   DtlsClientSession *session;

   //Initialize status code
   error = ERROR_WOULD_BLOCK;

   //Point to the DTLS session
   session = handle;
   //Point to the DTLS server context
   context = session->context;

   //Any pending datagram?
   if(context->bufferLen > 0)
   {
      //Pass incoming datagram to the proper connection
      if(context->clientIpAddr.sin_family == session->clientIpAddr.sin_family &&
         context->clientIpAddr.sin_addr.S_un.S_addr == session->clientIpAddr.sin_addr.S_un.S_addr &&
         context->clientIpAddr.sin_port == session->clientIpAddr.sin_port)
      {
         //Make sure the length of the datagram is acceptable
         if(context->bufferLen < size)
         {
            //Copy incoming datagram
            memcpy(data, context->buffer, context->bufferLen);
            //Return the length of the datagram
            *received = context->bufferLen;

            //Successful processing
            error = NO_ERROR;
         }

         //Flush the receive buffer
         context->bufferLen = 0;
      }
   }

   //Return status code
   return error;
}


/**
 * @brief DTLS cookie generation callback function
 * @param[in] context Pointer to the DTLS context
 * @param[in] clientParams Client's parameters
 * @param[out] cookie Pointer to the first byte of the cookie
 * @param[in,out] length Length of the cookie, in bytes
 * @param[in] param Pointer to the DTLS session
 * @return Error code
 **/

error_t dtlsServerCookieGenerateCallback(TlsContext *context,
   const DtlsClientParameters *clientParams, uint8_t *cookie,
   size_t *length, void *param)
{
   error_t error;
   DtlsClientSession *session;
   HmacContext hmacContext;

   //Point to the DTLS session
   session = (DtlsClientSession *) param;

   //Debug message
   TRACE_INFO("DTLS cookie generation...\r\n");

   //Make sure the output buffer is large enough to hold the cookie
   if(*length < SHA256_DIGEST_SIZE)
      return ERROR_BUFFER_OVERFLOW;

   //Invalid cookie secret?
   if(session->context->cookieSecretLen == 0)
   {
      //Generate a cookie secret
      error = context->prngAlgo->read(context->prngContext,
         session->context->cookieSecret, DTLS_SERVER_MAX_COOKIE_SECRET_SIZE);
      //Any error to report?
      if(error)
         return error;

      //Save the length of the generated secret
      session->context->cookieSecretLen = DTLS_SERVER_MAX_COOKIE_SECRET_SIZE;
   }

   //Initialize HMAC context
   hmacInit(&hmacContext, SHA256_HASH_ALGO, session->context->cookieSecret,
      session->context->cookieSecretLen);

   //Generate stateless cookie
   hmacUpdate(&hmacContext, (uint8_t *) &session->clientIpAddr.sin_addr,
      sizeof(IN_ADDR));

   //The server should use client parameters (version, random, session_id,
   //cipher_suites, compression_method) to generate its cookie
   hmacUpdate(&hmacContext, &clientParams->version, sizeof(uint16_t));
   hmacUpdate(&hmacContext, clientParams->random, clientParams->randomLen);
   hmacUpdate(&hmacContext, clientParams->sessionId, clientParams->sessionIdLen);
   hmacUpdate(&hmacContext, clientParams->cipherSuites, clientParams->cipherSuitesLen);
   hmacUpdate(&hmacContext, clientParams->compressMethods, clientParams->compressMethodsLen);

   //Finalize HMAC computation
   hmacFinal(&hmacContext, cookie);

   //Return the length of the cookie
   *length = SHA256_DIGEST_SIZE;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief DTLS cookie verification callback function
 * @param[in] context Pointer to the DTLS context
 * @param[in] clientParams Client's parameters
 * @param[in] cookie Pointer to the first byte of the cookie
 * @param[in] length Length of the cookie, in bytes
 * @param[in] param Pointer to the DTLS session
 * @return Error code
 **/

error_t dtlsServerCookieVerifyCallback(TlsContext *context,
   const DtlsClientParameters *clientParams, const uint8_t *cookie,
   size_t length, void *param)
{
   error_t error;
   DtlsClientSession *session;
   HmacContext hmacContext;

   //Point to the DTLS session
   session = (DtlsClientSession *) param;

   //Debug message
   TRACE_INFO("DTLS cookie verification...\r\n");

   //Make sure the length of the cookie is acceptable
   if(length != SHA256_DIGEST_SIZE)
      return ERROR_WRONG_COOKIE;

   //Invalid cookie secret?
   if(session->context->cookieSecretLen == 0)
   {
      //Generate a cookie secret
      error = context->prngAlgo->read(context->prngContext,
         session->context->cookieSecret, DTLS_SERVER_MAX_COOKIE_SECRET_SIZE);
      //Any error to report?
      if(error)
         return error;

      //Save the length of the generated secret
      session->context->cookieSecretLen = DTLS_SERVER_MAX_COOKIE_SECRET_SIZE;
   }

   //Initialize HMAC context
   hmacInit(&hmacContext, SHA256_HASH_ALGO, session->context->cookieSecret,
      session->context->cookieSecretLen);

   //Generate stateless cookie
   hmacUpdate(&hmacContext, (uint8_t *) &session->clientIpAddr.sin_addr,
      sizeof(IN_ADDR));

   //The server should use client parameters (version, random, session_id,
   //cipher_suites, compression_method) to generate its cookie
   hmacUpdate(&hmacContext, &clientParams->version, sizeof(uint16_t));
   hmacUpdate(&hmacContext, clientParams->random, clientParams->randomLen);
   hmacUpdate(&hmacContext, clientParams->sessionId, clientParams->sessionIdLen);
   hmacUpdate(&hmacContext, clientParams->cipherSuites, clientParams->cipherSuitesLen);
   hmacUpdate(&hmacContext, clientParams->compressMethods, clientParams->compressMethodsLen);

   //Finalize HMAC computation
   hmacFinal(&hmacContext, NULL);

   //Compare the received cookie against the expected value
   if(!osMemcmp(cookie, hmacContext.digest, length))
   {
      //The cookie is valid
      error = NO_ERROR;
   }
   else
   {
      //The cookie is invalid
      error = ERROR_WRONG_COOKIE;
   }

   //Return status code
   return error;
}

#endif
