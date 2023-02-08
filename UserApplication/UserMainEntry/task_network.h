
#ifndef __TASK_NETWORK_H_
#define __TASK_NETWORK_H_

#include "os_port.h"
#include "systemCore.h"


//Ethernet interface configuration
#define APP_IF_NAME 							"rei3Lx"										
#define APP_HOST_NAME 						"rei3Lx_Host"			/* ½Ó¿ÚÃû³Æ */	

#define APP_USE_DHCP_CLIENT 			DISABLED
#define APP_IPV4_HOST_ADDR 				"192.168.1.12"
#define APP_IPV4_SUBNET_MASK 			"255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY 	"192.168.1.1"
#define APP_IPV4_PRIMARY_DNS 			"192.168.1.1"
#define APP_IPV4_SECONDARY_DNS 		"8.8.4.4"

#define APP_USE_SLAAC 						DISABLED
#define APP_IPV6_LINK_LOCAL_ADDR 	"fe80::429"
#define APP_IPV6_PREFIX 					"2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 		64
#define APP_IPV6_GLOBAL_ADDR 			"2001:db8::429"
#define APP_IPV6_ROUTER 					"fe80::1"
#define APP_IPV6_PRIMARY_DNS 			"2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS 		"2001:4860:4860::8844"



void network_Init(void);


#endif


