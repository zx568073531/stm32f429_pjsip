#include "task_network.h"

#include "pcf8574.h"
#include "core/net.h"
#include "drivers/mac/stm32f4xx_eth_driver.h"
#include "drivers/phy/lan8720_driver.h"
#include "dhcp/dhcp_client.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "hardware/stm32f4xx/stm32f4xx_crypto.h"
#include "task_ssh.h"
#include "fs_port.h"

NetInterface *interface;
RNG_HandleTypeDef RNG_Handle;
YarrowContext yarrowContext;

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
static SemaphoreHandle_t waitIP;         /* Semaphore to protect key lists */

/**
 * @brief DHCP configuration timeout callback
 * @param[in] context Pointer to the DHCP client context
 * @param[in] interface interface Underlying network interface
 **/

void dhcpClientTimeoutCallback(DhcpClientContext *context,
   NetInterface *interface)
{
   uint_t i;
   Ipv4Addr ipv4Addr;

   //Stop DHCP client
   dhcpClientStop(context);

   //Set IPv4 host address
   ipv4StringToAddr(APP_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
	 
   ipv4StringToAddr(APP_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
	 
   //Debug message
   msg_log("\r\nStatic configuration:\r\n");

   //Host address
   ipv4GetHostAddr(interface, &ipv4Addr);
   msg_log("  IPv4 Address = %s\r\n", ipv4AddrToString(ipv4Addr, NULL));

   //Subnet mask
   ipv4GetSubnetMask(interface, &ipv4Addr);
   msg_log("  Subnet Mask = %s\r\n", ipv4AddrToString(ipv4Addr, NULL));

   //Default gateway
   ipv4GetDefaultGateway(interface, &ipv4Addr);
   msg_log("  Default Gateway = %s\r\n", ipv4AddrToString(ipv4Addr, NULL));

   //DNS servers
   for(i = 0; i < IPV4_DNS_SERVER_LIST_SIZE; i++)
   {
      ipv4GetDnsServer(interface, i, &ipv4Addr);
      msg_log("  DNS Server %u = %s\r\n", i + 1, ipv4AddrToString(ipv4Addr, NULL));
   }
}


/**
 * @brief Link state change callback
 * @param[in] context Pointer to the DHCP client context
 * @param[in] interface interface Underlying network interface
 * @param[in] linkState Current link state
 **/

void dhcpClientLinkChangeCallback(DhcpClientContext *context,
   NetInterface *interface, bool_t linkState)
{
   //Check whether the link is up
   if(linkState)
   {
      //Start DHCP client
      dhcpClientStart(context);
   }
	 
	 msg_log("link status change %d \r\n",linkState);
}



/**
 * @brief FSM state change callback
 * @param[in] context Pointer to the DHCP client context
 * @param[in] interface interface Underlying network interface
 * @param[in] state New DHCP state
 **/

void dhcpClientStateChangeCallback(DhcpClientContext *context,
   NetInterface *interface, DhcpState state)
{
   error_t error;
   Ipv4Addr ipv4Addr;

   //DHCP process complete?
   if(state == DHCP_STATE_BOUND)
   {
		 //Host address
		 ipv4GetHostAddr(interface, &ipv4Addr);
		 msg_log("  IPv4 Address = %s\r\n", ipv4AddrToString(ipv4Addr, NULL));

		 //Subnet mask
		 ipv4GetSubnetMask(interface, &ipv4Addr);
		 msg_log("  Subnet Mask = %s\r\n", ipv4AddrToString(ipv4Addr, NULL));

		 //Default gateway
		 ipv4GetDefaultGateway(interface, &ipv4Addr);
		 msg_log("  Default Gateway = %s\r\n", ipv4AddrToString(ipv4Addr, NULL));

		 //DNS servers
		 for(uint32_t i = 0; i < IPV4_DNS_SERVER_LIST_SIZE; i++)
		 {
				ipv4GetDnsServer(interface, i, &ipv4Addr);
				msg_log("  DNS Server %u = %s\r\n", i + 1, ipv4AddrToString(ipv4Addr, NULL));
		 }
		 
		 xSemaphoreGive(waitIP);
   }
	 
}



/**
  * @brief network_Init  网络协议栈初始化和硬件初始化 
  * @retval None
  */
void network_Init(void)
{
	error_t error;
	MacAddr macAddr;
	
#if (APP_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif
	
	uint_t i;
	uint32_t value;
	uint8_t seed[32];
	
	waitIP = xSemaphoreCreateBinary();
	
	//Enable RNG peripheral clock
	__HAL_RCC_RNG_CLK_ENABLE();
	//Initialize RNG
	RNG_Handle.Instance = RNG;
	HAL_RNG_Init(&RNG_Handle);
		
	//Generate a random seed
	for(i = 0; i < 32; i += 4)
	{
		//Get 32-bit random value
		HAL_RNG_GenerateRandomNumber(&RNG_Handle, &value);

		//Copy random value
		seed[i] = value & 0xFF;
		seed[i + 1] = (value >> 8) & 0xFF;
		seed[i + 2] = (value >> 16) & 0xFF;
		seed[i + 3] = (value >> 24) & 0xFF;
	}
	
	//Initialize hardware cryptographic accelerator
	error = stm32f4xxCryptoInit();
	//Any error to report?
	if(error)
	{
		//Debug message
		msg_log("Failed to initialize hardware crypto accelerator!\r\n");
	}

	//Generate a random seed
	error = trngGetRandomData(seed, sizeof(seed));
	//Any error to report?
	if(error)
	{
		//Debug message
		msg_log("Failed to generate random data!\r\n");
	}

	//PRNG initialization
	error = yarrowInit(&yarrowContext);
	//Any error to report?
	if(error)
	{
		//Debug message
		msg_log("Failed to initialize PRNG!\r\n");
	}

	//Properly seed the PRNG
	error = yarrowSeed(&yarrowContext, seed, sizeof(seed));
	//Any error to report?
	if(error)
	{
		//Debug message
		msg_log("Failed to seed PRNG!\r\n");
	}
	
	//File system initialization
	error = fsInit();
	//Any error to report?
	if(error)
	{
		//Debug message
		msg_log("Failed to initialize file system!\r\n");
	}
	 
	//TCP/IP stack initialization
	error = netInit();
	//Failed to start DHCP client?
	if(error)
	{
		//Debug message
		msg_log("Net Init Failed!\r\n");
	}
	
	//Configure the first Ethernet interface
	interface = &netInterface[0];

	//Set interface name
	netSetInterfaceName(interface, APP_IF_NAME);
	//Set host name
	netSetHostname(interface, APP_HOST_NAME);

	//Set host MAC address
	macAddr.b[0] = 0x00;
	macAddr.b[1] = 0x80;
	macAddr.b[2] = 0xe1;
	macAddr.b[3] = ((*(__IO uint32_t*)(UID_BASE)>>16)&0XFF);
	macAddr.b[4] = ((*(__IO uint32_t*)(UID_BASE)>>8)&0XFF);
	macAddr.b[5] = (*(__IO uint32_t*)(UID_BASE)&0XFF);
	netSetMacAddr(interface, &macAddr);

	//Select the relevant network adapter
	netSetDriver(interface, &stm32f4xxEthDriver);
	netSetPhyDriver(interface, &lan8720PhyDriver);

	/* initialize the hardware */
	PCF8574_Init();
	
	//Reset PHY transceiver
	PCF8574_WriteBit(ETH_RESET_IO,1);     
	vTaskDelay(10);
	PCF8574_WriteBit(ETH_RESET_IO,0); 
	
	//Initialize network interface
	error = netConfigInterface(interface);
	//Failed to initialize DHCP client?
	if(error)
	{
		//Debug message
		msg_log("Failed to initialize ConfigInterface!\r\n");
	}

#if (IPV4_SUPPORT == ENABLED)
#if (APP_USE_DHCP_CLIENT == ENABLED)
	//Get default settings
	dhcpClientGetDefaultSettings(&dhcpClientSettings);
	//Set the network interface to be configured by DHCP
	dhcpClientSettings.interface = interface;
	//Disable rapid commit option
	dhcpClientSettings.rapidCommit = FALSE;

	//DHCP configuration timeout (30s)
	dhcpClientSettings.timeout = 30000;
	//DHCP configuration timeout event
	dhcpClientSettings.timeoutEvent = dhcpClientTimeoutCallback;
	//Link state change event
	dhcpClientSettings.linkChangeEvent = dhcpClientLinkChangeCallback;
	
  //FSM state change event
  dhcpClientSettings.stateChangeEvent = dhcpClientStateChangeCallback;
	
	//DHCP client initialization
	error = dhcpClientInit(&dhcpClientContext, &dhcpClientSettings);
	//Failed to initialize DHCP client?
	if(error)
	{
		//Debug message
		msg_log("Failed to initialize DHCP client!\r\n");
	}

	//Start DHCP client
	error = dhcpClientStart(&dhcpClientContext);
	//Failed to start DHCP client?
	if(error)
	{
		//Debug message
		msg_log("Failed to start DHCP client!\r\n");
	}
#else
	//Set IPv4 host address
	ipv4StringToAddr(APP_IPV4_HOST_ADDR, &ipv4Addr);
	ipv4SetHostAddr(interface, ipv4Addr);

	//Set subnet mask
	ipv4StringToAddr(APP_IPV4_SUBNET_MASK, &ipv4Addr);
	ipv4SetSubnetMask(interface, ipv4Addr);

	//Set default gateway
	ipv4StringToAddr(APP_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
	ipv4SetDefaultGateway(interface, ipv4Addr);

	//Set primary and secondary DNS servers
	ipv4StringToAddr(APP_IPV4_PRIMARY_DNS, &ipv4Addr);
	ipv4SetDnsServer(interface, 0, ipv4Addr);
	ipv4StringToAddr(APP_IPV4_SECONDARY_DNS, &ipv4Addr);
	ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_USE_SLAAC == ENABLED)
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
		msg_log("Failed to initialize SLAAC!\r\n");
	}

	//Start IPv6 address autoconfiguration process
	error = slaacStart(&slaacContext);
	//Failed to start SLAAC process?
	if(error)
	{
		//Debug message
		msg_log("Failed to start SLAAC!\r\n");
	}
#else
	//Set link-local address
	ipv6StringToAddr(APP_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
	ipv6SetLinkLocalAddr(interface, &ipv6Addr);

	//Set IPv6 prefix
	ipv6StringToAddr(APP_IPV6_PREFIX, &ipv6Addr);
	ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IPV6_PREFIX_LENGTH);

	//Set global address
	ipv6StringToAddr(APP_IPV6_GLOBAL_ADDR, &ipv6Addr);
	ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

	//Set default router
	ipv6StringToAddr(APP_IPV6_ROUTER, &ipv6Addr);
	ipv6SetDefaultRouter(interface, 0, &ipv6Addr);

	//Set primary and secondary DNS servers
	ipv6StringToAddr(APP_IPV6_PRIMARY_DNS, &ipv6Addr);
	ipv6SetDnsServer(interface, 0, &ipv6Addr);
	ipv6StringToAddr(APP_IPV6_SECONDARY_DNS, &ipv6Addr);
	ipv6SetDnsServer(interface, 1, &ipv6Addr);
#endif
#endif
	
//	task_ssh_server_init(&yarrowContext);
	
//	xSemaphoreTake(waitIP , portMAX_DELAY);
	
}

