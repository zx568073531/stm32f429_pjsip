/**
 * @file main.c
 * @brief Main routine
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

//Dependencies
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "core/net.h"
#include "drivers/wifi/esp32_wifi_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "shell/shell_server.h"
#include "hardware/esp32/esp32_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "resource_manager.h"
#include "debug.h"

//First Wi-Fi interface (STA mode) configuration
#define APP_IF0_NAME "wlan0"
#define APP_IF0_HOST_NAME "ssh-server-demo"
#define APP_IF0_MAC_ADDR "00-00-00-00-00-00"

#define APP_IF0_USE_DHCP_CLIENT ENABLED
#define APP_IF0_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IF0_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF0_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF0_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF0_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF0_USE_SLAAC ENABLED
#define APP_IF0_IPV6_LINK_LOCAL_ADDR "fe80::32:1"

//Second Wi-Fi interface (AP mode) configuration
#define APP_IF1_NAME "wlan1"
#define APP_IF1_HOST_NAME "ssh-server-demo"
#define APP_IF1_MAC_ADDR "00-00-00-00-00-00"

#define APP_IF1_USE_DHCP_SERVER ENABLED
#define APP_IF1_IPV4_HOST_ADDR "192.168.8.1"
#define APP_IF1_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF1_IPV4_DEFAULT_GATEWAY "0.0.0.0"
#define APP_IF1_IPV4_PRIMARY_DNS "0.0.0.0"
#define APP_IF1_IPV4_SECONDARY_DNS "0.0.0.0"
#define APP_IF1_IPV4_ADDR_RANGE_MIN "192.168.8.10"
#define APP_IF1_IPV4_ADDR_RANGE_MAX "192.168.8.99"

#define APP_IF1_USE_ROUTER_ADV ENABLED
#define APP_IF1_IPV6_LINK_LOCAL_ADDR "fe80::32:2"
#define APP_IF1_IPV6_PREFIX "fd00:1:2:3::"
#define APP_IF1_IPV6_PREFIX_LENGTH 64
#define APP_IF1_IPV6_GLOBAL_ADDR "fd00:1:2:3::32:2"

//Wi-Fi parameters (STA mode)
#define APP_WIFI_STA_SSID "TEST_ESP32_STA"
#define APP_WIFI_STA_PASSWORD "12345678"

//Wi-Fi parameters (AP mode)
#define APP_WIFI_AP_SSID "TEST_ESP32_AP"
#define APP_WIFI_AP_PASSWORD "1122334455"

//Application configuration
#define APP_SSH_MAX_CONNECTIONS 3
#define APP_SSH_MAX_CHANNELS 3
#define APP_SHELL_MAX_SESSIONS 3
#define APP_SSH_SERVER_ECDSA_P256_PUBLIC_KEY "keys/server_ecdsa_p256_public_key.pem"
#define APP_SSH_SERVER_ECDSA_P256_PRIVATE_KEY "keys/server_ecdsa_p256_private_key.pem"
#define APP_SSH_SERVER_ED25519_PUBLIC_KEY "keys/server_ed25519_public_key.pem"
#define APP_SSH_SERVER_ED25519_PRIVATE_KEY "keys/server_ed25519_private_key.pem"

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
DhcpServerSettings dhcpServerSettings;
DhcpServerContext dhcpServerContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
NdpRouterAdvSettings ndpRouterAdvSettings;
NdpRouterAdvPrefixInfo ndpRouterAdvPrefixInfo[1];
NdpRouterAdvContext ndpRouterAdvContext;
SshServerSettings sshServerSettings;
SshServerContext sshServerContext;
SshConnection sshConnections[APP_SSH_MAX_CONNECTIONS];
SshChannel sshChannels[APP_SSH_MAX_CHANNELS];
ShellServerSettings shellServerSettings;
ShellServerContext shellServerContext;
ShellServerSession shellSessions[APP_SHELL_MAX_SESSIONS];
YarrowContext yarrowContext;
uint8_t seed[32];

//Forward declaration of functions
error_t wifiStaInterfaceInit(void);
error_t wifiApInterfaceInit(void);

error_t sshServerImportKeys(SshServerContext *context);

SshAuthStatus sshServerPasswordAuthCallback(SshConnection *connection,
   const char_t *user, const char_t *password, size_t passwordLen);

ShellAccessStatus shellServerCheckUserCallback(ShellServerSession *session,
   const char_t *user);

error_t shellServerCommandLineCallback(ShellServerSession *session,
   char_t *commandLine);

esp_err_t wifiConnect(void);
esp_err_t wifiEnableAp(void);

void wifiEventHandler(void *arg, esp_event_base_t eventBase,
   int32_t eventId, void *eventData);


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Configure red LED (GPIO0)
   gpio_pad_select_gpio(0);
   gpio_set_direction(0, GPIO_MODE_OUTPUT);
   gpio_set_level(0, 0);

   //Configure green LED (GPIO2)
   gpio_pad_select_gpio(2);
   gpio_set_direction(2, GPIO_MODE_OUTPUT);
   gpio_set_level(2, 0);

   //Configure blue LED (GPIO4)
   gpio_pad_select_gpio(4);
   gpio_set_direction(4, GPIO_MODE_OUTPUT);
   gpio_set_level(4, 0);
}


/**
 * @brief LED task
 * @param[in] param Unused parameter
 **/

void ledTask(void *param)
{
   //Endless loop
   while(1)
   {
      gpio_set_level(4, 1);
      osDelayTask(100);
      gpio_set_level(4, 0);
      osDelayTask(900);
   }
}


/**
 * @brief Main entry point
 **/

void app_main(void)
{
   error_t error;
   OsTaskId taskId;

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneSSH SSH Server Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2022 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: ESP32\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Initialize NVS memory
   nvs_flash_init();

   //Create default event loop
   esp_event_loop_create_default();

   //Register Wi-Fi event handler
   esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID,
      wifiEventHandler, NULL);

   //Initialize hardware cryptographic accelerator
   error = esp32CryptoInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize hardware crypto accelerator!\r\n");
   }

   //Generate a random seed
   error = trngGetRandomData(seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to generate random data!\r\n");
   }

   //PRNG initialization
   error = yarrowInit(&yarrowContext);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize PRNG!\r\n");
   }

   //Properly seed the PRNG
   error = yarrowSeed(&yarrowContext, seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to seed PRNG!\r\n");
   }

   //TCP/IP stack initialization
   error = netInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
   }

   //Configure the first network interface (Wi-Fi STA mode)
   wifiStaInterfaceInit();

   //Configure the second network interface (Wi-Fi AP mode)
   wifiApInterfaceInit();

   //Get default settings
   sshServerGetDefaultSettings(&sshServerSettings);
   //Bind SSH server to the desired interface
   sshServerSettings.interface = NULL;
   //Listen to port 22
   sshServerSettings.port = SSH_PORT;
   //SSH connections
   sshServerSettings.numConnections = APP_SSH_MAX_CONNECTIONS;
   sshServerSettings.connections = sshConnections;
   //SSH channels
   sshServerSettings.numChannels = APP_SSH_MAX_CHANNELS;
   sshServerSettings.channels = sshChannels;
   //Pseudo-random number generator
   sshServerSettings.prngAlgo = YARROW_PRNG_ALGO;
   sshServerSettings.prngContext = &yarrowContext;
   //Password authentication callback function
   sshServerSettings.passwordAuthCallback = sshServerPasswordAuthCallback;

   //SSH server initialization
   error = sshServerInit(&sshServerContext, &sshServerSettings);
   //Failed to initialize SSH server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SSH server!\r\n");
   }

   //Load keys
   error = sshServerImportKeys(&sshServerContext);
   //Failed to load keys?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to load keys!\r\n");
   }

   //Start SSH server
   error = sshServerStart(&sshServerContext);
   //Failed to start SSH server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SSH server!\r\n");
   }

   //Get default settings
   shellServerGetDefaultSettings(&shellServerSettings);
   //SSH server context
   shellServerSettings.sshServerContext = &sshServerContext;
   //Shell sessions
   shellServerSettings.numSessions = APP_SHELL_MAX_SESSIONS;
   shellServerSettings.sessions = shellSessions;
   //User verification callback function
   shellServerSettings.checkUserCallback = shellServerCheckUserCallback;
   //Command line processing callback function
   shellServerSettings.commandLineCallback = shellServerCommandLineCallback;

   //Shell server initialization
   error = shellServerInit(&shellServerContext, &shellServerSettings);
   //Failed to initialize shell server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize shell server!\r\n");
   }

   //Start shell server
   error = shellServerStart(&shellServerContext);
   //Failed to start shell server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start shell server!\r\n");
   }

   //Create a task to blink the LED
   taskId = osCreateTask("LED", ledTask, NULL, 200, OS_TASK_PRIORITY_NORMAL);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
   }

   //Create a Wi-Fi network (AP mode)
   wifiEnableAp();
}


/**
 * @brief Wi-Fi STA interface initialization
 **/

error_t wifiStaInterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_IF0_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF0_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the first network interface (Wi-Fi STA mode)
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF0_NAME);
   //Set host name
   netSetHostname(interface, APP_IF0_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF0_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &esp32WifiStaDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF0_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext, &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF0_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF0_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF0_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF0_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF0_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF0_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext, &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
      //Exit immediately
      return error;
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF0_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Wi-Fi AP interface initialization
 **/

error_t wifiApInterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
   Ipv4Addr ipv4Addr;
   Ipv6Addr ipv6Addr;

   //Configure the second network interface (Wi-Fi AP mode)
   interface = &netInterface[1];

   //Set interface name
   netSetInterfaceName(interface, APP_IF1_NAME);
   //Set host name
   netSetHostname(interface, APP_IF1_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF1_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &esp32WifiApDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF1_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF1_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF1_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF1_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF1_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);

#if (APP_IF1_USE_DHCP_SERVER == ENABLED)
   //Get default settings
   dhcpServerGetDefaultSettings(&dhcpServerSettings);
   //Set the network interface to be configured by DHCP
   dhcpServerSettings.interface = interface;
   //Lease time, in seconds, assigned to the DHCP clients
   dhcpServerSettings.leaseTime = 3600;

   //Lowest and highest IP addresses in the pool that are available
   //for dynamic address assignment
   ipv4StringToAddr(APP_IF1_IPV4_ADDR_RANGE_MIN, &dhcpServerSettings.ipAddrRangeMin);
   ipv4StringToAddr(APP_IF1_IPV4_ADDR_RANGE_MAX, &dhcpServerSettings.ipAddrRangeMax);

   //Subnet mask
   ipv4StringToAddr(APP_IF1_IPV4_SUBNET_MASK, &dhcpServerSettings.subnetMask);
   //Default gateway
   ipv4StringToAddr(APP_IF1_IPV4_DEFAULT_GATEWAY, &dhcpServerSettings.defaultGateway);
   //DNS servers
   ipv4StringToAddr(APP_IF1_IPV4_PRIMARY_DNS, &dhcpServerSettings.dnsServer[0]);
   ipv4StringToAddr(APP_IF1_IPV4_SECONDARY_DNS, &dhcpServerSettings.dnsServer[1]);

   //DHCP server initialization
   error = dhcpServerInit(&dhcpServerContext, &dhcpServerSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP server!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP server
   error = dhcpServerStart(&dhcpServerContext);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP server!\r\n");
      //Exit immediately
      return error;
   }
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
   //Set link-local address
   ipv6StringToAddr(APP_IF1_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);

   //Set IPv6 prefix
   ipv6StringToAddr(APP_IF1_IPV6_PREFIX, &ipv6Addr);
   ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IF1_IPV6_PREFIX_LENGTH);

   //Set global address
   ipv6StringToAddr(APP_IF1_IPV6_GLOBAL_ADDR, &ipv6Addr);
   ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

#if (APP_IF1_USE_ROUTER_ADV == ENABLED)
   //List of IPv6 prefixes to be advertised
   ipv6StringToAddr(APP_IF1_IPV6_PREFIX, &ndpRouterAdvPrefixInfo[0].prefix);
   ndpRouterAdvPrefixInfo[0].length = APP_IF1_IPV6_PREFIX_LENGTH;
   ndpRouterAdvPrefixInfo[0].onLinkFlag = TRUE;
   ndpRouterAdvPrefixInfo[0].autonomousFlag = TRUE;
   ndpRouterAdvPrefixInfo[0].validLifetime = 3600;
   ndpRouterAdvPrefixInfo[0].preferredLifetime = 1800;

   //Get default settings
   ndpRouterAdvGetDefaultSettings(&ndpRouterAdvSettings);
   //Set the underlying network interface
   ndpRouterAdvSettings.interface = interface;
   //Maximum time interval between unsolicited Router Advertisements
   ndpRouterAdvSettings.maxRtrAdvInterval = 60000;
   //Minimum time interval between unsolicited Router Advertisements
   ndpRouterAdvSettings.minRtrAdvInterval = 20000;
   //Router lifetime
   ndpRouterAdvSettings.defaultLifetime = 0;
   //List of IPv6 prefixes
   ndpRouterAdvSettings.prefixList = ndpRouterAdvPrefixInfo;
   ndpRouterAdvSettings.prefixListLength = arraysize(ndpRouterAdvPrefixInfo);

   //RA service initialization
   error = ndpRouterAdvInit(&ndpRouterAdvContext, &ndpRouterAdvSettings);
   //Failed to initialize DHCPv6 client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize RA service!\r\n");
      //Exit immediately
      return error;
   }

   //Start RA service
   error = ndpRouterAdvStart(&ndpRouterAdvContext);
   //Failed to start RA service?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start RA service!\r\n");
      //Exit immediately
      return error;
   }
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Load SSH server's keys
 * @param[in] context Pointer to the SSH server context
 * @return Error code
 **/

error_t sshServerImportKeys(SshServerContext *context)
{
   error_t error;
   const char_t *publicKey;
   size_t publicKeyLen;
   const char_t *privateKey;
   size_t privateKeyLen;

   //Get server's ECDSA P-256 public key
   error = resGetData(APP_SSH_SERVER_ECDSA_P256_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's ECDSA P-256 private key
   error = resGetData(APP_SSH_SERVER_ECDSA_P256_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load ECDSA P-256 key pair
   error = sshServerLoadHostKey(&sshServerContext, publicKey,
      publicKeyLen, privateKey, privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's Ed25519 public key
   error = resGetData(APP_SSH_SERVER_ED25519_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's Ed25519 private key
   error = resGetData(APP_SSH_SERVER_ED25519_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load Ed25519 key pair
   error = sshServerLoadHostKey(&sshServerContext, publicKey,
      publicKeyLen, privateKey, privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Password authentication callback function
 * @param[in] connection Handle referencing a client connection
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] password NULL-terminated string that contains the corresponding password
 * @return Authentication status (SSH_AUTH_STATUS_SUCCESS, SSH_AUTH_STATUS_FAILURE or
 *   SSH_AUTH_STATUS_PASSWORD_EXPIRED)
 **/

SshAuthStatus sshServerPasswordAuthCallback(SshConnection *connection,
   const char_t *user, const char_t *password, size_t passwordLen)
{
   SshAuthStatus status;

   //Debug message
   TRACE_INFO("SSH server: Password verification\r\n");

   //Manage authentication policy
   if(!strcmp(user, "admin"))
   {
      //Check password
      if(passwordLen == 8 && !strncmp(password, "password", 8))
      {
         //The provided password is valid
         status = SSH_AUTH_STATUS_SUCCESS;
      }
      else
      {
         //The provided password is not valid
         status = SSH_AUTH_STATUS_FAILURE;
      }
   }
   else
   {
      //Unknown user name
      status = SSH_AUTH_STATUS_FAILURE;
   }

   //Return access status
   return status;
}


/**
 * @brief User verification callback function
 * @param[in] session Handle referencing a shell session
 * @param[in] user NULL-terminated string that contains the user name
 * @return Access status
 **/

ShellAccessStatus shellServerCheckUserCallback(ShellServerSession *session,
   const char_t *user)
{
   //Debug message
   TRACE_INFO("Shell server: User verification\r\n");

   //Set welcome banner
   shellServerSetBanner(session,
      "You are connected to \x1b[32mCycloneSSH\x1b[39m Server\r\n");

   //Set shell prompt
   shellServerSetPrompt(session, ">");

   //All SSH users are granted access to the shell service
   return SHELL_ACCESS_ALLOWED;
}


/**
 * @brief Command line processing callback function
 * @param[in] session Handle referencing an SCP session
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] path Canonical path of the file
 * @return Permissions for the specified file
 **/

error_t shellServerCommandLineCallback(ShellServerSession *session,
   char_t *commandLine)
{
   error_t error;

   //Debug message
   TRACE_INFO("Shell server: Command line received\r\n");
   TRACE_INFO("  %s\r\n", commandLine);

   //Check command name
   if(!strcasecmp(commandLine, "hello"))
   {
      //Send response to the client
      error = shellServerWriteStream(session, "Hello World!\r\n", 14,
         NULL, 0);
   }
   else if(!strcasecmp(commandLine, "exit") ||
      !strcasecmp(commandLine, "quit"))
   {
      //Close shell session
      error = ERROR_END_OF_STREAM;
   }
   else
   {
      //Unknown command received
      error = shellServerWriteStream(session, "Unknown command!\r\n", 18,
         NULL, 0);
   }

   //Return status code
   return error;
}


/**
 * @brief Connect to Wi-Fi network (STA mode)
 * @return Error code
 **/

esp_err_t wifiConnect(void)
{
   esp_err_t ret;
   wifi_config_t config;

   //Debug message
   TRACE_INFO("ESP32: Connecting to Wi-Fi network (%s)...\r\n", APP_WIFI_STA_SSID);

   //Initialize configuration structure
   memset(&config, 0, sizeof(wifi_config_t));

   //Set Wi-Fi parameters
   strcpy((char_t *) config.sta.ssid, APP_WIFI_STA_SSID);
   strcpy((char_t *) config.sta.password, APP_WIFI_STA_PASSWORD);

   //Set Wi-Fi operating mode
   ret = esp_wifi_set_mode(WIFI_MODE_STA);

   //Check status code
   if(ret == ESP_OK)
   {
      //Configure STA interface
      ret = esp_wifi_set_config(ESP_IF_WIFI_STA, &config);
   }

   //Check status code
   if(ret == ESP_OK)
   {
      //Start STA interface
      ret = esp_wifi_start();
   }

   //Return status code
   return ret;
}


/**
 * @brief Create Wi-Fi network (AP mode)
 * @return Error code
 **/

esp_err_t wifiEnableAp(void)
{
   esp_err_t ret;
   wifi_config_t config;

   //Debug message
   TRACE_INFO("ESP32: Creating Wi-Fi network (%s)...\r\n", APP_WIFI_AP_SSID);

   //Initialize configuration structure
   memset(&config, 0, sizeof(wifi_config_t));

   //Set Wi-Fi parameters
   strcpy((char_t *) config.ap.ssid, APP_WIFI_AP_SSID);
   strcpy((char_t *) config.ap.password, APP_WIFI_AP_PASSWORD);
   config.ap.authmode = WIFI_AUTH_WPA_WPA2_PSK;
   config.ap.max_connection = 4;

   //Set Wi-Fi operating mode
   ret = esp_wifi_set_mode(WIFI_MODE_AP);

   //Check status code
   if(ret == ESP_OK)
   {
      //Configure AP interface
      ret = esp_wifi_set_config(ESP_IF_WIFI_AP, &config);
   }

   //Check status code
   if(ret == ESP_OK)
   {
      //Start AP interface
      ret = esp_wifi_start();
   }

   //Return status code
   return ret;
}


/**
 * @brief Wi-Fi event handler
 * @param[in] arg User-specific parameter
 * @param[in] eventBase Event base
 * @param[in] eventId Event identifier
 * @param[in] eventData Event-specific data
 **/

void wifiEventHandler(void *arg, esp_event_base_t eventBase,
   int32_t eventId, void *eventData)
{
   //Debug message
   TRACE_INFO("ESP32: Wi-Fi event handler (event = %d)\r\n", eventId);

   //Check event identifier
   if(eventId == WIFI_EVENT_STA_START)
   {
      //Debug message
      TRACE_INFO("ESP32: Station started\r\n");

      //Connect station to the AP
      esp_wifi_connect();
   }
   else if(eventId == WIFI_EVENT_STA_CONNECTED)
   {
      //Debug message
      TRACE_INFO("ESP32: Station connected\r\n");
   }
   else if(eventId == WIFI_EVENT_STA_DISCONNECTED)
   {
      //Debug message
      TRACE_INFO("ESP32: Station disconnected\r\n");

      //Reconnect station to the AP
      esp_wifi_connect();
   }
   else if(eventId == WIFI_EVENT_AP_STACONNECTED)
   {
      MacAddr macAddr;
      wifi_event_ap_staconnected_t *event;

      //Point the event-specific data
      event = (wifi_event_ap_staconnected_t *) eventData;
      //Retrieve the MAC address of the station
      macCopyAddr(&macAddr, event->mac);

      //Debug message
      TRACE_INFO("ESP32: Station %s joining AP\r\n",
         macAddrToString(&macAddr, NULL));
   }
   else if(eventId == WIFI_EVENT_AP_STADISCONNECTED)
   {
      MacAddr macAddr;
      wifi_event_ap_stadisconnected_t *event;

      //Point the event-specific data
      event = (wifi_event_ap_stadisconnected_t *) eventData;
      //Retrieve the MAC address of the station
      macCopyAddr(&macAddr, event->mac);

      //Debug message
      TRACE_INFO("ESP32: Station %s leaving AP\r\n",
         macAddrToString(&macAddr, NULL));
   }
}
