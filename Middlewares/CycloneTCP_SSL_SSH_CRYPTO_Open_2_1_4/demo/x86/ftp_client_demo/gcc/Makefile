RESULT ?= ftp_client_demo

DEFINES =

INCLUDES = \
	-I../src \
	-I../../../../common \
	-I../../../../cyclone_tcp \
	-I../../../../cyclone_ssl \
	-I../../../../cyclone_crypto

SOURCES = \
	../src/main.c \
	../../../../common/cpu_endian.c \
	../../../../common/os_port_posix.c \
	../../../../common/date_time.c \
	../../../../common/str.c \
	../../../../common/debug.c \
	../../../../cyclone_tcp/core/net.c \
	../../../../cyclone_tcp/core/net_mem.c \
	../../../../cyclone_tcp/core/net_misc.c \
	../../../../cyclone_tcp/drivers/pcap/pcap_driver.c \
	../../../../cyclone_tcp/core/nic.c \
	../../../../cyclone_tcp/core/ethernet.c \
	../../../../cyclone_tcp/core/ethernet_misc.c \
	../../../../cyclone_tcp/ipv4/arp.c \
	../../../../cyclone_tcp/ipv4/ipv4.c \
	../../../../cyclone_tcp/ipv4/ipv4_frag.c \
	../../../../cyclone_tcp/ipv4/ipv4_misc.c \
	../../../../cyclone_tcp/ipv4/icmp.c \
	../../../../cyclone_tcp/igmp/igmp_host.c \
	../../../../cyclone_tcp/igmp/igmp_host_misc.c \
	../../../../cyclone_tcp/igmp/igmp_common.c \
	../../../../cyclone_tcp/ipv6/ipv6.c \
	../../../../cyclone_tcp/ipv6/ipv6_frag.c \
	../../../../cyclone_tcp/ipv6/ipv6_misc.c \
	../../../../cyclone_tcp/ipv6/ipv6_pmtu.c \
	../../../../cyclone_tcp/ipv6/icmpv6.c \
	../../../../cyclone_tcp/ipv6/mld.c \
	../../../../cyclone_tcp/ipv6/ndp.c \
	../../../../cyclone_tcp/ipv6/ndp_cache.c \
	../../../../cyclone_tcp/ipv6/ndp_misc.c \
	../../../../cyclone_tcp/ipv6/slaac.c \
	../../../../cyclone_tcp/ipv6/slaac_misc.c \
	../../../../cyclone_tcp/core/ip.c \
	../../../../cyclone_tcp/core/tcp.c \
	../../../../cyclone_tcp/core/tcp_fsm.c \
	../../../../cyclone_tcp/core/tcp_misc.c \
	../../../../cyclone_tcp/core/tcp_timer.c \
	../../../../cyclone_tcp/core/udp.c \
	../../../../cyclone_tcp/core/socket.c \
	../../../../cyclone_tcp/core/socket_misc.c \
	../../../../cyclone_tcp/core/raw_socket.c \
	../../../../cyclone_tcp/dns/dns_cache.c \
	../../../../cyclone_tcp/dns/dns_client.c \
	../../../../cyclone_tcp/dns/dns_common.c \
	../../../../cyclone_tcp/dns/dns_debug.c \
	../../../../cyclone_tcp/mdns/mdns_client.c \
	../../../../cyclone_tcp/mdns/mdns_responder.c \
	../../../../cyclone_tcp/mdns/mdns_common.c \
	../../../../cyclone_tcp/netbios/nbns_client.c \
	../../../../cyclone_tcp/netbios/nbns_responder.c \
	../../../../cyclone_tcp/netbios/nbns_common.c \
	../../../../cyclone_tcp/llmnr/llmnr_client.c \
	../../../../cyclone_tcp/llmnr/llmnr_responder.c \
	../../../../cyclone_tcp/llmnr/llmnr_common.c \
	../../../../cyclone_tcp/dhcp/dhcp_client.c \
	../../../../cyclone_tcp/dhcp/dhcp_client_fsm.c \
	../../../../cyclone_tcp/dhcp/dhcp_client_misc.c \
	../../../../cyclone_tcp/dhcp/dhcp_common.c \
	../../../../cyclone_tcp/dhcp/dhcp_debug.c \
	../../../../cyclone_tcp/ftp/ftp_client.c \
	../../../../cyclone_tcp/ftp/ftp_client_transport.c \
	../../../../cyclone_tcp/ftp/ftp_client_misc.c

HEADERS = \
	../src/os_port_config.h \
	../src/net_config.h \
	../../../../common/cpu_endian.h \
	../../../../common/os_port.h \
	../../../../common/os_port_posix.h \
	../../../../common/date_time.h \
	../../../../common/str.h \
	../../../../common/error.h \
	../../../../common/debug.h \
	../../../../cyclone_tcp/core/net.h \
	../../../../cyclone_tcp/core/net_mem.h \
	../../../../cyclone_tcp/core/net_misc.h \
	../../../../cyclone_tcp/drivers/pcap/pcap_driver.h \
	../../../../cyclone_tcp/core/nic.h \
	../../../../cyclone_tcp/core/ethernet.h \
	../../../../cyclone_tcp/core/ethernet_misc.h \
	../../../../cyclone_tcp/ipv4/arp.h \
	../../../../cyclone_tcp/ipv4/ipv4.h \
	../../../../cyclone_tcp/ipv4/ipv4_frag.h \
	../../../../cyclone_tcp/ipv4/ipv4_misc.h \
	../../../../cyclone_tcp/ipv4/icmp.h \
	../../../../cyclone_tcp/igmp/igmp_host.h \
	../../../../cyclone_tcp/igmp/igmp_host_misc.h \
	../../../../cyclone_tcp/igmp/igmp_common.h \
	../../../../cyclone_tcp/ipv6/ipv6.h \
	../../../../cyclone_tcp/ipv6/ipv6_frag.h \
	../../../../cyclone_tcp/ipv6/ipv6_misc.h \
	../../../../cyclone_tcp/ipv6/ipv6_pmtu.h \
	../../../../cyclone_tcp/ipv6/icmpv6.h \
	../../../../cyclone_tcp/ipv6/mld.h \
	../../../../cyclone_tcp/ipv6/ndp.h \
	../../../../cyclone_tcp/ipv6/ndp_cache.h \
	../../../../cyclone_tcp/ipv6/ndp_misc.h \
	../../../../cyclone_tcp/ipv6/slaac.h \
	../../../../cyclone_tcp/ipv6/slaac_misc.h \
	../../../../cyclone_tcp/core/ip.h \
	../../../../cyclone_tcp/core/tcp.h \
	../../../../cyclone_tcp/core/tcp_fsm.h \
	../../../../cyclone_tcp/core/tcp_misc.h \
	../../../../cyclone_tcp/core/tcp_timer.h \
	../../../../cyclone_tcp/core/udp.h \
	../../../../cyclone_tcp/core/socket.h \
	../../../../cyclone_tcp/core/socket_misc.h \
	../../../../cyclone_tcp/core/raw_socket.h \
	../../../../cyclone_tcp/dns/dns_cache.h \
	../../../../cyclone_tcp/dns/dns_client.h \
	../../../../cyclone_tcp/dns/dns_common.h \
	../../../../cyclone_tcp/dns/dns_debug.h \
	../../../../cyclone_tcp/mdns/mdns_client.h \
	../../../../cyclone_tcp/mdns/mdns_responder.h \
	../../../../cyclone_tcp/mdns/mdns_common.h \
	../../../../cyclone_tcp/netbios/nbns_client.h \
	../../../../cyclone_tcp/netbios/nbns_responder.h \
	../../../../cyclone_tcp/netbios/nbns_common.h \
	../../../../cyclone_tcp/llmnr/llmnr_client.h \
	../../../../cyclone_tcp/llmnr/llmnr_responder.h \
	../../../../cyclone_tcp/llmnr/llmnr_common.h \
	../../../../cyclone_tcp/dhcp/dhcp_client.h \
	../../../../cyclone_tcp/dhcp/dhcp_client_fsm.h \
	../../../../cyclone_tcp/dhcp/dhcp_client_misc.h \
	../../../../cyclone_tcp/dhcp/dhcp_common.h \
	../../../../cyclone_tcp/dhcp/dhcp_debug.h \
	../../../../cyclone_tcp/ftp/ftp_client.h \
	../../../../cyclone_tcp/ftp/ftp_client_transport.h \
	../../../../cyclone_tcp/ftp/ftp_client_misc.h

LIBS = -lpcap -lpthread

OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

OBJ_DIR = obj

CFLAGS += -Wall
CFLAGS += $(DEFINES)
CFLAGS += $(INCLUDES)

CC = gcc
LD = ld
OBJDUMP = objdump
OBJCOPY = objcopy
SIZE = size

THIS_MAKEFILE := $(lastword $(MAKEFILE_LIST))

all: build

build: $(RESULT)

$(RESULT): $(OBJECTS) $(HEADERS) $(THIS_MAKEFILE)
	$(CC) -Wl,-M=$(RESULT).map $(CFLAGS) $(addprefix $(OBJ_DIR)/, $(notdir $(OBJECTS))) $(LIBS) -o $@

$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

%.o: %.c $(HEADERS) $(THIS_MAKEFILE)
	$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $(notdir $@))

clean:
	rm -f $(RESULT)
	rm -f $(RESULT).map
	rm -f $(OBJ_DIR)/*.o
