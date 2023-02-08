set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DESP32_WROVER_KIT -D__error_t_defined")

set(COMPONENT_SRCDIRS "."
	"common"
	"cyclone_tcp/drivers/wifi"
	"cyclone_tcp/core"
	"cyclone_tcp/dhcp"
	"cyclone_tcp/dns"
	"cyclone_tcp/ipv4"
	"cyclone_tcp/igmp"
	"cyclone_tcp/ipv6"
	"cyclone_tcp/netbios"
	"cyclone_tcp/llmnr"
	"cyclone_tcp/ftp")

set(COMPONENT_ADD_INCLUDEDIRS "."
	"common"
	"cyclone_tcp")

register_component()
