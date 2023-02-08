/**
 * @file main.c
 * @brief DTLS client demo
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

#define _CRTDBG_MAP_ALLOC
#define _WINERROR_

//Dependencies
#include <stdlib.h>
#include <crtdbg.h>
#include <conio.h>
#include <winsock2.h>
#include "tls.h"
#include "tls_cipher_suites.h"
#include "rng/yarrow.h"
#include "debug.h"

//Libraries
#pragma comment(lib, "ws2_32.lib")

//Server hostname and port
#define APP_SERVER_NAME "localhost"
#define APP_SERVER_PORT 44333

//Compilation options
#define APP_SET_CIPHER_SUITES DISABLED
#define APP_SET_SERVER_NAME DISABLED
#define APP_SET_TRUSTED_CA_LIST ENABLED
#define APP_SET_CLIENT_CERT ENABLED

//Trusted CA bundle
#define APP_CA_CERT_BUNDLE "..\\certs\\ca_cert_bundle.pem"

//Client's certificate and private key
#define APP_CLIENT_CERT "..\\certs\\client_ecdsa_cert.pem"
#define APP_CLIENT_PRIVATE_KEY "..\\certs\\client_ecdsa_key.pem"

//Server's raw public key (for Raw Public Key authentication method only)
const uint8_t serverRawPublicKey[] = {
   0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A,
   0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0x88, 0x34, 0xC6, 0xF6, 0xE8,
   0x57, 0xEF, 0x5A, 0xB6, 0xF7, 0xC4, 0x67, 0x27, 0x3C, 0x08, 0x09, 0x50, 0x5B, 0x05, 0xCF, 0xB4,
   0x26, 0x47, 0x8D, 0xC2, 0x8C, 0xB5, 0xC5, 0x50, 0x32, 0x6D, 0x30, 0xC1, 0x52, 0xDF, 0xFB, 0x2F,
   0x8C, 0x63, 0x9D, 0xF1, 0xAA, 0x7F, 0xCC, 0xC1, 0x72, 0xAA, 0xC0, 0xC8, 0x4D, 0x78, 0x5D, 0x4D,
   0x1E, 0xC3, 0x54, 0x6F, 0x3D, 0x91, 0x3F, 0x01, 0xA4, 0xF0, 0x0A};

//List of preferred ciphersuites
const uint16_t cipherSuites[] =
{
   TLS_CHACHA20_POLY1305_SHA256,
   TLS_AES_128_GCM_SHA256,
   TLS_AES_256_GCM_SHA384,
   TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256,
   TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256,
   TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256,
   TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256,
   TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384,
   TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384,
   TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA,
   TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA,
   TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA,
   TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA,
   TLS_DHE_RSA_WITH_AES_128_GCM_SHA256,
   TLS_DHE_RSA_WITH_AES_256_GCM_SHA384,
   TLS_DHE_RSA_WITH_AES_128_CBC_SHA,
   TLS_DHE_RSA_WITH_AES_256_CBC_SHA,
   TLS_RSA_WITH_AES_128_GCM_SHA256,
   TLS_RSA_WITH_AES_256_GCM_SHA384,
   TLS_RSA_WITH_AES_128_CBC_SHA,
   TLS_RSA_WITH_AES_256_CBC_SHA,
   TLS_RSA_WITH_3DES_EDE_CBC_SHA
};

//Pseudo-random number generator
YarrowContext yarrowContext;
//Socket descriptor
SOCKET sock = SOCKET_ERROR;
//DTLS context
TlsContext *dtlsContext = NULL;
//DTLS session state
TlsSessionState dtlsSession;

//Credentials
char_t *clientCert = NULL;
size_t clientCertLength = 0;
char_t *clientPrivateKey = NULL;
size_t clientPrivateKeyLength = 0;
char_t *trustedCaList = NULL;
size_t trustedCaListLength = 0;

//Forward declaration of functions
error_t readPemFile(const char_t *filename, char_t **buffer, size_t *length);

error_t dtlsClientConnect(void);
void dtlsClientDisconnect(void);

error_t dtlsClientRpkVerifyCallback(TlsContext *context,
   const uint8_t *rawPublicKey, size_t rawPublicKeyLen);

error_t dtlsClientSendCallback(TlsSocketHandle socket, const void *data,
   size_t length, size_t *written, uint_t flags);

error_t dtlsClientReceiveCallback(TlsSocketHandle socket, void *data,
   size_t size, size_t *received, uint_t flags);


/**
 * @brief User task
 * @param[in] param Unused parameter
 **/

void userTask(void *param)
{
   error_t error;
   int_t ch;
   size_t n;
   char_t buffer[2048];

   //Initialize DTLS session state
   tlsInitSessionState(&dtlsSession);

   //Endless loop
   while(1)
   {
      //Any key pressed?
      if(_kbhit())
      {
         //Get the corresponding character
         ch = _getch();

         //C key pressed?
         if(toupper(ch) == 'C')
         {
            //Establish connection with the DTLS server
            error = dtlsClientConnect();
         }
         //D key pressed?
         else if(toupper(ch) == 'D')
         {
            //Disconnect from the DTLS server
            dtlsClientDisconnect();
         }
         //T key pressed?
         else if(toupper(ch) == 'T')
         {
            //Valid TLS context?
            if(dtlsContext != NULL)
            {
               //Format message
               n = sprintf(buffer, "Hello World!");

               //Debug message
               TRACE_INFO("Sending datagram (%u bytes)...\r\n", n);
               TRACE_INFO("%s\r\n", buffer);

               //Send a datagram
               error = tlsWrite(dtlsContext, buffer, n, NULL, 0);
            }
         }
         //Q key pressed?
         else if(toupper(ch) == 'Q')
         {
            //Close DTLS session
            dtlsClientDisconnect();
            //Release DTLS session state
            tlsFreeSessionState(&dtlsSession);

            //Kill ourselves
            osDeleteTask(NULL);
         }
      }

      //Valid TLS context?
      if(dtlsContext != NULL)
      {
         //Receive datagram
         error = tlsRead(dtlsContext, buffer, sizeof(buffer) - 1, &n, 0);

         //Any datagram received?
         if(!error)
         {
            //Properly terminate the string with a NULL character
            buffer[n] = '\0';

            //Debug message
            TRACE_INFO("Datagram received (%u bytes)...\r\n", n);
            TRACE_INFO("%s\r\n", buffer);
         }
      }
      else
      {
         //Loop delay
         osDelayTask(100);
      }
   }
}


/**
 * @brief Main entry point
 * @return Status code
 **/

int_t main(void)
{
   error_t error;
   int_t ret;
   WSADATA wsaData;
   HCRYPTPROV hProvider;
   OsTaskId taskId;
   uint8_t seed[32];

   //Socket descriptor
   SOCKET sock = SOCKET_ERROR;

   //TLS context
   TlsContext *dtlsContext = NULL;

   //Start-up message
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneSSL DTLS Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("\r\n");

   //Acquire cryptographic context
   ret = CryptAcquireContext(&hProvider, 0, 0, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_SILENT);
   //Any error to report?
   if(!ret)
   {
      //Debug message
      TRACE_ERROR("Error: Cannot acquire cryptographic context (%d)\r\n", GetLastError());
      //Exit immediately
      return ERROR_FAILURE;
   }

   //Generate a random seed
   ret = CryptGenRandom(hProvider, sizeof(seed), seed);
   //Any error to report?
   if(!ret)
   {
      //Debug message
      TRACE_ERROR("Error: Failed to generate random data (%d)\r\n", GetLastError());
      //Exit immediately
      return ERROR_FAILURE;
   }

   //Release cryptographic context
   CryptReleaseContext(hProvider, 0);

   //PRNG initialization
   error = yarrowInit(&yarrowContext);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Error: PRNG initialization failed (%d)\r\n", error);
      //Exit immediately
      return ERROR_FAILURE;
   }

   //Properly seed the PRNG
   error = yarrowSeed(&yarrowContext, seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Error: Failed to seed PRNG (%d)\r\n", error);
      //Exit immediately
      return error;
   }

   //Winsock initialization
   ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
   //Any error to report?
   if(ret)
   {
      //Debug message
      TRACE_ERROR("Error: Winsock initialization failed (%d)\r\n", ret);
      //Exit immediately
      return ERROR_FAILURE;
   }

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("Loading credentials...\r\n");

      //Load trusted CA certificates
      error = readPemFile(APP_CA_CERT_BUNDLE, &trustedCaList, &trustedCaListLength);
      //Any error to report?
      if(error)
         break;

      //Load client's certificate
      error = readPemFile(APP_CLIENT_CERT, &clientCert, &clientCertLength);
      //Any error to report?
      if(error)
         break;

      //Load client's private key
      error = readPemFile(APP_CLIENT_PRIVATE_KEY, &clientPrivateKey, &clientPrivateKeyLength);
      //Any error to report?
      if(error)
         break;

      //End of exception handling block
   } while(0);

   //Check error code
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to load credentials!\r\n");
   }

   //Create user task
   taskId = osCreateTask("User", userTask, NULL, 800, OS_TASK_PRIORITY_NORMAL);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
   }

   //Wait until the user task has terminated
   WaitForSingleObject(taskId, INFINITE_DELAY);

   //Free previously allocated resources
   free(trustedCaList);
   free(clientCert);
   free(clientPrivateKey);

   //Release PRNG context
   yarrowRelease(&yarrowContext);

   //Winsock related cleanup
   WSACleanup();
   //Dumps all the memory blocks in the heap when a memory leak has occurred
   _CrtDumpMemoryLeaks();

   //Return status code
   return error;
}


/**
 * @brief Load the specified PEM file
 * @param[in] filename Name of the PEM file to load
 * @param[out] buffer Memory buffer that holds the contents of the file
 * @param[out] length Length of the file in bytes
 **/

error_t readPemFile(const char_t *filename, char_t **buffer, size_t *length)
{
   int_t ret;
   error_t error;
   FILE *fp;

   //Initialize output parameters
   *buffer = NULL;
   *length = 0;

   //Start of exception handling block
   do
   {
      //Open the specified file
      fp = fopen(filename, "rb");

      //Failed to open the file?
      if(fp == NULL)
      {
         error = ERROR_OPEN_FAILED;
         break;
      }

      //Jump to the end of the file
      ret = fseek(fp, 0, SEEK_END);

      //Any error to report?
      if(ret != 0)
      {
         error = ERROR_FAILURE;
         break;
      }

      //Retrieve the length of the file
      *length = ftell(fp);
      //Allocate a buffer to hold the contents of the file
      *buffer = malloc(*length);

      //Failed to allocate memory?
      if(*buffer == NULL)
      {
         error = ERROR_OUT_OF_MEMORY;
         break;
      }

      //Rewind to the beginning of the file
      rewind(fp);
      //Read file contents
      ret = fread(*buffer, 1, *length, fp);

      //Failed to read data?
      if(ret != *length)
      {
         error = ERROR_READ_FAILED;
         break;
      }

      //Successful processing
      error = NO_ERROR;

      //End of exception handling block
   } while(0);

   //Close file
   if(fp != NULL)
      fclose(fp);

   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Error: Cannot load file %s\r\n", filename);
      //Clean up side effects
      free(*buffer);
   }

   //Return status code
   return error;
}


/**
 * @brief Connect to the DTLS server
 **/

error_t dtlsClientConnect(void)
{
   error_t error;
   int_t ret;
   HOSTENT *host;
   SOCKADDR_IN addr;
   DWORD timeout;

   //Drop existing connection, if any
   dtlsClientDisconnect();

   //Debug message
   TRACE_INFO("Trying to resolve %s...\r\n", APP_SERVER_NAME);

   //Resolve server name
   host = gethostbyname(APP_SERVER_NAME);
   //Failed to resolve server name?
   if(!host)
   {
      //Debug message
      TRACE_ERROR("Error: Cannot resolve server name (%d)\r\n", WSAGetLastError());
      //Report an error
      return ERROR_FAILURE;
   }

   //Open a UDP socket
   sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
   //Failed to open socket?
   if(sock < 0)
   {
      //Debug message
      TRACE_ERROR("Error: Cannot open socket (%d)\r\n", WSAGetLastError());
      //Report an error
      return ERROR_FAILURE;
   }

   //Start of exception handling block
   do
   {
      //Destination address
      addr.sin_family = host->h_addrtype;
      memcpy(&addr.sin_addr, host->h_addr, host->h_length);
      addr.sin_port = htons(APP_SERVER_PORT);

      //Connect to the SSL server
      ret = connect(sock, (PSOCKADDR) &addr, sizeof(addr));
      //Connection with server failed?
      if(ret < 0)
      {
         //Debug message
         TRACE_ERROR("Error: Failed to connect (%d)\r\n", WSAGetLastError());
         //Report an error
         error = ERROR_FAILURE;
         //Exit immediately
         break;
      }

      //Timeout in milliseconds
      timeout = 100;

      //Set the timeout for blocking receive calls
      ret = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char_t *) &timeout, sizeof(timeout));
      //Failed to set option?
      if(ret < 0)
      {
         //Debug message
         TRACE_ERROR("Error: Failed to set option (%d)\r\n", WSAGetLastError());
         //Report an error
         error = ERROR_FAILURE;
         //Exit immediately
         break;
      }

      //Initialize TLS context
      dtlsContext = tlsInit();
      //Initialization failed?
      if(!dtlsContext)
      {
         //Report an error
         error = ERROR_OUT_OF_MEMORY;
         //Exit immediately
         break;
      }

      //Set send and receive callbacks (I/O abstraction layer)
      error = tlsSetSocketCallbacks(dtlsContext, dtlsClientSendCallback,
         dtlsClientReceiveCallback, (TlsSocketHandle) sock);
      //Any error to report?
      if(error)
         break;

      //Use datagram transport protocol
      error = tlsSetTransportProtocol(dtlsContext, TLS_TRANSPORT_PROTOCOL_DATAGRAM);
      //Any error to report?
      if(error)
         break;

      //Select client operation mode
      error = tlsSetConnectionEnd(dtlsContext, TLS_CONNECTION_END_CLIENT);
      //Any error to report?
      if(error)
         break;

      //Set the PRNG algorithm to be used
      error = tlsSetPrng(dtlsContext, YARROW_PRNG_ALGO, &yarrowContext);
      //Any error to report?
      if(error)
         break;

#if (APP_SET_CIPHER_SUITES == ENABLED)
      //Preferred cipher suite list
      error = tlsSetCipherSuites(dtlsContext, cipherSuites, arraysize(cipherSuites));
      //Any error to report?
      if(error)
         break;
#endif

#if (APP_SET_SERVER_NAME == ENABLED)
      //Set the fully qualified domain name of the server
      error = tlsSetServerName(dtlsContext, APP_SERVER_NAME);
      //Any error to report?
      if(error)
         break;
#endif

#if (APP_SET_TRUSTED_CA_LIST == ENABLED)
      //Import the list of trusted CA certificates
      error = tlsSetTrustedCaList(dtlsContext, trustedCaList, strlen(trustedCaList));
      //Any error to report?
      if(error)
         break;
#endif

#if (APP_SET_CLIENT_CERT == ENABLED)
      //Import the client's certificate
      error = tlsAddCertificate(dtlsContext, clientCert,
         clientCertLength, clientPrivateKey, clientPrivateKeyLength);
      //Any error to report?
      if(error)
         break;
#endif

#if (TLS_RAW_PUBLIC_KEY_SUPPORT == ENABLED)
      //Register the raw public key verification callback function
      error = tlsSetRpkVerifyCallback(dtlsContext, dtlsClientRpkVerifyCallback);
      //Any error to report?
      if(error)
         return error;
#endif


      //Restore DTLS session, if any
      error = tlsRestoreSessionState(dtlsContext, &dtlsSession);
      //Any error to report?
      if(error)
         return error;

      //Set connection timeout
      error = tlsSetTimeout(dtlsContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Establish a secure session
      error = tlsConnect(dtlsContext);
      //TLS handshake failure?
      if(error)
         break;

      //Save DTLS session
      error = tlsSaveSessionState(dtlsContext, &dtlsSession);
      //Any error to report?
      if(error)
         return error;

      //Set timeout for receive operations (non-blocking mode)
      error = tlsSetTimeout(dtlsContext, 0);
      //Any error to report?
      if(error)
         break;

      //End of exception handling block
   } while(0);

   //Check status code
   if(error)
   {
      //Clean up side effects
      dtlsClientDisconnect();
   }

   //Return status code
   return error;
}


/**
 * @brief Disconnect from the DTLS server
 **/

void dtlsClientDisconnect(void)
{
   //Valid TLS context?
   if(dtlsContext != NULL)
   {
      //Terminate DTLS session
      tlsShutdown(dtlsContext);

      //Release TLS context
      tlsFree(dtlsContext);
      dtlsContext = NULL;
   }

   //Valid socket?
   if(sock >= 0)
   {
      //Close socket
      closesocket(sock);
      sock = SOCKET_ERROR;
   }
}


/**
 * @brief Raw public key verification callback function
 * @param[in] rawPublicKey Pointer to the raw public key
 * @param[in] rawPublicKeyLen Length of the raw public key, in bytes
 * @return Error code
 **/

error_t dtlsClientRpkVerifyCallback(TlsContext *context,
   const uint8_t *rawPublicKey, size_t rawPublicKeyLen)
{
   error_t error;

   //Dump the SubjectPublicKeyInfo field (raw public key)
   TRACE_INFO_ARRAY("   ", rawPublicKey, rawPublicKeyLen);

   //When raw public keys are used, authentication of the peer is supported
   //only through authentication of the received SubjectPublicKeyInfo
   if(rawPublicKeyLen == arraysize(serverRawPublicKey) &&
      !memcmp(rawPublicKey, serverRawPublicKey, rawPublicKeyLen))
   {
      //The public key is trusted
      error = NO_ERROR;
   }
   else
   {
      //Unknown public key value
      error = ERROR_BAD_CERTIFICATE;
   }

   //Return status code
   return error;
}


/**
 * @brief DTLS send callback (I/O abstraction layer)
 * @param[in] socket Handle that identifies a socket
 * @param[in] data Pointer to a buffer containing the data to be transmitted
 * @param[in] length Number of data bytes to send
 * @param[out] written Number of bytes that have been transmitted
 * @param[in] flags Unused parameter
 * @return Error code
 **/

error_t dtlsClientSendCallback(TlsSocketHandle socket, const void *data,
   size_t length, size_t *written, uint_t flags)
{
   int_t n;
   error_t error;

   //Send data
   n = send((SOCKET) socket, data, length, 0);

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
#if defined(_WIN32)
      //Timeout error?
      if(WSAGetLastError() == WSAEWOULDBLOCK)
         error = ERROR_TIMEOUT;
      else
         error = ERROR_WRITE_FAILED;
#else
      //Timeout error?
      if(errno == EAGAIN || errno == EWOULDBLOCK)
         error = ERROR_TIMEOUT;
      else
         error = ERROR_WRITE_FAILED;
#endif
   }

   //Return status code
   return error;
}


/**
 * @brief DTLS receive callback (I/O abstraction layer)
 * @param[in] socket Handle that identifies a socket
 * @param[out] data Buffer where to store the incoming data
 * @param[in] size Maximum number of bytes that can be received
 * @param[out] received Number of bytes that have been received
 * @param[in] flags Unused parameter
 * @return Error code
 **/

error_t dtlsClientReceiveCallback(TlsSocketHandle socket, void *data,
   size_t size, size_t *received, uint_t flags)
{
   int_t n;
   error_t error;
   uint_t lastError;

   //Send data
   n = recv((SOCKET) socket, data, size, 0);

   //Check return value
   if(n > 0)
   {
      //Total number of data that have been received
      *received = n;
      //Successful write operation
      error = NO_ERROR;
   }
   else
   {
#if defined(_WIN32)
      //Retrieve last error
      lastError = WSAGetLastError();

      //Timeout error?
      if(lastError == WSAEWOULDBLOCK || lastError == WSAETIMEDOUT)
         error = ERROR_TIMEOUT;
      else
         error = ERROR_READ_FAILED;
#else
      //Timeout error?
      if(errno == EAGAIN || errno == EWOULDBLOCK)
         error = ERROR_TIMEOUT;
      else
         error = ERROR_READ_FAILED;
#endif
   }

   //Return status code
   return error;
}
