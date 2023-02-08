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
	"cyclone_tcp/http"
	"cyclone_ssl"
	"cyclone_crypto/core"
	"cyclone_crypto/hardware"
	"cyclone_crypto/hardware/esp32"
	"cyclone_crypto/hash"
	"cyclone_crypto/mac"
	"cyclone_crypto/cipher"
	"cyclone_crypto/cipher_mode"
	"cyclone_crypto/aead"
	"cyclone_crypto/pkc"
	"cyclone_crypto/ecc"
	"cyclone_crypto/mpi"
	"cyclone_crypto/encoding"
	"cyclone_crypto/pkix"
	"cyclone_crypto/kdf"
	"cyclone_crypto/rng")

set(COMPONENT_ADD_INCLUDEDIRS "."
	"common"
	"cyclone_tcp"
	"cyclone_ssl"
	"cyclone_crypto")

register_component()
