/**
 * @file main.c
 * @brief DTLS server demo
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
#include "tls_misc.h"
#include "rng/yarrow.h"
#include "dtls_server.h"
#include "debug.h"

//Libraries
#pragma comment(lib, "ws2_32.lib")

//Server port
#define APP_SERVER_PORT 44333

//Diffie-Hellman parameters
#define APP_SERVER_DH_PARAMS "..\\certs\\dh_params.pem"

//Server's RSA certificate and private key
#define APP_SERVER_RSA_CERT "..\\certs\\server_rsa_cert.pem"
#define APP_SERVER_RSA_PRIVATE_KEY "..\\certs\\server_rsa_key.pem"

//Server's ECDSA certificate and private key
#define APP_SERVER_ECDSA_CERT "..\\certs\\server_ecdsa_cert.pem"
#define APP_SERVER_ECDSA_PRIVATE_KEY "..\\certs\\server_ecdsa_key.pem"

//Trusted CA bundle
#define APP_CA_CERT_BUNDLE "..\\certs\\ca_cert_bundle.pem"

//Client's raw public key (for Raw Public Key authentication method only)
const uint8_t clientRawPublicKey[] = {
   0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A,
   0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0x4E, 0xC7, 0xA2, 0x22, 0xFD,
   0xA1, 0x24, 0x54, 0xCB, 0xE2, 0x8E, 0x9C, 0x37, 0x8F, 0x30, 0x52, 0xC0, 0x55, 0x1F, 0x5C, 0xC0,
   0x97, 0x79, 0xA2, 0x4F, 0xB2, 0x85, 0x5F, 0xA2, 0xF9, 0x9C, 0x14, 0x36, 0x3D, 0x6A, 0x50, 0xAE,
   0x78, 0xF7, 0x34, 0x81, 0x25, 0xD7, 0xCF, 0xEE, 0x45, 0x79, 0x62, 0x40, 0x80, 0x48, 0xE2, 0xDD,
   0x1B, 0xB8, 0x97, 0x7B, 0x28, 0xB6, 0x15, 0x87, 0xAE, 0x08, 0x59};

//Credentials
char_t *dhParams = NULL;
size_t dhParamsLength = 0;
char_t *serverRsaCert = NULL;
size_t serverRsaCertLength = 0;
char_t *serverRsaPrivateKey = NULL;
size_t serverRsaPrivateKeyLength = 0;
char_t *serverEcdsaCert = NULL;
size_t serverEcdsaCertLength = 0;
char_t *serverEcdsaPrivateKey = NULL;
size_t serverEcdsaPrivateKeyLength = 0;
char_t *trustedCaList = NULL;
size_t trustedCaListLength = 0;

//Pseudo-random number generator
YarrowContext yarrowContext;
//DTLS context
DtlsServerSettings dtlsServerSettings;
DtlsServerContext dtlsServerContext;

//Forward declaration of functions
error_t dtlsServerRandCallback(uint8_t *data, size_t length);

error_t dtlsServerSessionInitCallback(DtlsClientSession *session,
   TlsContext *dtlsContext);

error_t dtlsServerRpkVerifyCallback(TlsContext *context,
   const uint8_t *rawPublicKey, size_t rawPublicKeyLen);

error_t dtlsServerProcessDatagramCallback(DtlsClientSession *session,
   const SOCKADDR_IN *remoteIpAddr, const uint8_t *data, size_t length);

void dtlsServerTickCallback(DtlsServerContext *context);

error_t readPemFile(const char_t *filename, char_t **buffer, size_t *length);


/**
 * @brief User task
 * @param[in] param Unused parameter
 **/

void userTask(void *param)
{
   int_t ch;

   //Endless loop
   while(1)
   {
      //Any key pressed?
      if(_kbhit())
      {
         //Get the corresponding character
         ch = _getch();

         //Q key pressed?
         if(toupper(ch) == 'Q')
         {
            //Kill ourselves
            osDeleteTask(NULL);
         }
      }

      //Loop delay
      osDelayTask(100);
   }
}


/**
 * @brief Main entry point
 * @return Unused value
 **/

int_t main(void)
{
   error_t error;
   int_t ret;
   WSADATA wsaData;
   HCRYPTPROV hProvider;
   OsTaskId taskId;
   uint8_t seed[32];

   //Start-up message
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneSSL DTLS Server Demo ***\r\n");
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

      //Load Diffie-Hellman parameters
      error = readPemFile(APP_SERVER_DH_PARAMS,  &dhParams, &dhParamsLength);
      //Any error to report?
      if(error)
         break;

      //Load server's RSA certificate
      error = readPemFile(APP_SERVER_RSA_CERT, &serverRsaCert, &serverRsaCertLength);
      //Any error to report?
      if(error)
         break;

      //Load server's RSA private key
      error = readPemFile(APP_SERVER_RSA_PRIVATE_KEY, &serverRsaPrivateKey, &serverRsaPrivateKeyLength);
      //Any error to report?
      if(error)
         break;

      //Load server's ECDSA certificate
      error = readPemFile(APP_SERVER_ECDSA_CERT, &serverEcdsaCert, &serverEcdsaCertLength);
      //Any error to report?
      if(error)
         break;

      //Load server's ECDSA private key
      error = readPemFile(APP_SERVER_ECDSA_PRIVATE_KEY, &serverEcdsaPrivateKey, &serverEcdsaPrivateKeyLength);
      //Any error to report?
      if(error)
         break;

      //Load trusted CA certificates
      error = readPemFile(APP_CA_CERT_BUNDLE, &trustedCaList, &trustedCaListLength);
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

   //Get default settings
   dtlsServerGetDefaultSettings(&dtlsServerSettings);

   //Listen to port 44333
   dtlsServerSettings.port = APP_SERVER_PORT;
   //Random data generation callback function
   dtlsServerSettings.randCallback = dtlsServerRandCallback;
   //DTLS session initialization callback function
   dtlsServerSettings.sessionInitCallback = dtlsServerSessionInitCallback;
   //Incoming datagram processing callback
   dtlsServerSettings.processDatagramCallback = dtlsServerProcessDatagramCallback;
   //DTLS server tick callback
   dtlsServerSettings.tickCallback = dtlsServerTickCallback;

   //DTLS server initialization
   error = dtlsServerInit(&dtlsServerContext, &dtlsServerSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DTLS server!\r\n");
   }

   //Start DTLS server
   error = dtlsServerStart(&dtlsServerContext);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DTLS server!\r\n");
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
   free(dhParams);
   free(serverRsaCert);
   free(serverRsaPrivateKey);
   free(serverEcdsaCert);
   free(serverEcdsaPrivateKey);
   free(trustedCaList);

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
 * @brief Random data generation callback function
 **/

error_t dtlsServerRandCallback(uint8_t *data, size_t length)
{
   //Generate random data
   return yarrowRead(&yarrowContext, data, length);
}


/**
 * @brief DTLS session initialization callback
 * @param[in] context Pointer to the DTLS server context
 * @param[in] dtlsContext Pointer to the DTLS context
 * @return Error code
 **/

error_t dtlsServerSessionInitCallback(DtlsClientSession *session,
   TlsContext *dtlsContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("DTLS session initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(dtlsContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

   //Client authentication is required
   error = tlsSetClientAuthMode(dtlsContext, TLS_CLIENT_AUTH_REQUIRED);
   //Any error to report?
   if(error)
      return error;

   //Import server's ECDSA certificate
   error = tlsAddCertificate(dtlsContext, serverEcdsaCert, strlen(serverEcdsaCert),
      serverEcdsaPrivateKey, strlen(serverEcdsaPrivateKey));
   //Any error to report?
   if(error)
      return error;

   //Import the list of trusted CA certificates
   error = tlsSetTrustedCaList(dtlsContext, trustedCaList, strlen(trustedCaList));
   //Any error to report?
   if(error)
      return error;

#if (TLS_RAW_PUBLIC_KEY_SUPPORT == ENABLED)
      //Register the raw public key verification callback function
      error = tlsSetRpkVerifyCallback(dtlsContext, dtlsServerRpkVerifyCallback);
      //Any error to report?
      if(error)
         return error;
#endif

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Raw public key verification callback function
 * @param[in] rawPublicKey Pointer to the raw public key
 * @param[in] rawPublicKeyLen Length of the raw public key, in bytes
 * @return Error code
 **/

error_t dtlsServerRpkVerifyCallback(TlsContext *context,
   const uint8_t *rawPublicKey, size_t rawPublicKeyLen)
{
   error_t error;

   //Dump the SubjectPublicKeyInfo field (raw public key)
   TRACE_INFO_ARRAY("   ", rawPublicKey, rawPublicKeyLen);

   //When raw public keys are used, authentication of the peer is supported
   //only through authentication of the received SubjectPublicKeyInfo
   if(rawPublicKeyLen == arraysize(clientRawPublicKey) &&
      !memcmp(rawPublicKey, clientRawPublicKey, rawPublicKeyLen))
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
 * @brief Incoming datagram processing callback
 * @param[in] session Pointer to the DTLS session
 * @param[in] remoteIpAddr Address of the client
 * @param[in] data Pointer to the received datagram
 * @param[in] length Length of the datagram, in bytes
 * @return Error code
 **/

error_t dtlsServerProcessDatagramCallback(DtlsClientSession *session,
   const SOCKADDR_IN *remoteIpAddr, const uint8_t *data, size_t length)
{
   error_t error;

   //Debug message
   TRACE_INFO("Datagram processing callback\r\n");

   //Check incoming command
   if(length >= 5 && !strncasecmp((char_t *) data, "hello", 5))
   {
      //Send a test pattern to the client
      error = dtlsServerSendDatagram(session, "Hello World!\r\n", 14);
   }
   else
   {
      //Echo the received datagram
      error = dtlsServerSendDatagram(session, data, length);
   }

   //Return status code
   return error;
}


/**
 * @brief DTLS server tick callback
 * @param[in] context Pointer to the DTLS server context
 **/

void dtlsServerTickCallback(DtlsServerContext *context)
{
}


/**
 * @brief Load the specified PEM file
 * @param[in] filename Name of the PEM file to load
 * @param[out] buffer Memory buffer that holds the contents of the file
 * @param[out] length Length of the file in bytes
 * @return Error code
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
