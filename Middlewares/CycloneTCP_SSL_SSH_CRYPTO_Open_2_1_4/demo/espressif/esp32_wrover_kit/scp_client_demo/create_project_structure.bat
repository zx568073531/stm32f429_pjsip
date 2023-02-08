md main\common
md main\cyclone_tcp
md main\cyclone_tcp\core
md main\cyclone_tcp\drivers
md main\cyclone_tcp\drivers\wifi
md main\cyclone_tcp\ipv4
md main\cyclone_tcp\igmp
md main\cyclone_tcp\ipv6
md main\cyclone_tcp\ppp
md main\cyclone_tcp\mibs
md main\cyclone_tcp\dns
md main\cyclone_tcp\mdns
md main\cyclone_tcp\dns_sd
md main\cyclone_tcp\netbios
md main\cyclone_tcp\llmnr
md main\cyclone_tcp\dhcp
md main\cyclone_tcp\dhcpv6
md main\cyclone_ssh
md main\cyclone_ssh\ssh
md main\cyclone_ssh\scp
md main\cyclone_crypto
md main\cyclone_crypto\core
md main\cyclone_crypto\hardware
md main\cyclone_crypto\hardware\esp32
md main\cyclone_crypto\hash
md main\cyclone_crypto\mac
md main\cyclone_crypto\cipher
md main\cyclone_crypto\cipher_mode
md main\cyclone_crypto\aead
md main\cyclone_crypto\pkc
md main\cyclone_crypto\ecc
md main\cyclone_crypto\mpi
md main\cyclone_crypto\encoding
md main\cyclone_crypto\pkix
md main\cyclone_crypto\kdf
md main\cyclone_crypto\rng
md main\cyclone_crypto\xof

REM Common Sources
copy ..\..\..\..\common\cpu_endian.c main\common
copy ..\..\..\..\common\os_port_freertos.c main\common
copy ..\..\..\..\common\date_time.c main\common
copy ..\..\..\..\common\str.c main\common
copy ..\..\..\..\common\path.c main\common
copy ..\..\..\..\common\debug.c main\common

REM Common Headers
copy ..\..\..\..\common\cpu_endian.h main\common
copy ..\..\..\..\common\compiler_port.h main\common
copy ..\..\..\..\common\os_port.h main\common
copy ..\..\..\..\common\os_port_freertos.h main\common
copy ..\..\..\..\common\date_time.h main\common
copy ..\..\..\..\common\str.h main\common
copy ..\..\..\..\common\path.h main\common
copy ..\..\..\..\common\error.h main\common
copy ..\..\..\..\common\debug.h main\common

REM CycloneTCP Sources
copy ..\..\..\..\cyclone_tcp\drivers\wifi\esp32_wifi_driver.c main\cyclone_tcp\drivers\wifi
copy ..\..\..\..\cyclone_tcp\core\*.c main\cyclone_tcp\core
copy ..\..\..\..\cyclone_tcp\ipv4\*.c main\cyclone_tcp\ipv4
copy ..\..\..\..\cyclone_tcp\igmp\*.c main\cyclone_tcp\igmp
copy ..\..\..\..\cyclone_tcp\ipv6\*.c main\cyclone_tcp\ipv6
copy ..\..\..\..\cyclone_tcp\dns\*.c main\cyclone_tcp\dns
copy ..\..\..\..\cyclone_tcp\mdns\*.c main\cyclone_tcp\mdns
copy ..\..\..\..\cyclone_tcp\netbios\*.c main\cyclone_tcp\netbios
copy ..\..\..\..\cyclone_tcp\llmnr\*.c main\cyclone_tcp\llmnr
copy ..\..\..\..\cyclone_tcp\dhcp\*.c main\cyclone_tcp\dhcp

REM CycloneTCP Headers
copy ..\..\..\..\cyclone_tcp\drivers\wifi\esp32_wifi_driver.h main\cyclone_tcp\drivers\wifi
copy ..\..\..\..\cyclone_tcp\core\*.h main\cyclone_tcp\core
copy ..\..\..\..\cyclone_tcp\ipv4\*.h main\cyclone_tcp\ipv4
copy ..\..\..\..\cyclone_tcp\igmp\*.h main\cyclone_tcp\igmp
copy ..\..\..\..\cyclone_tcp\ipv6\*.h main\cyclone_tcp\ipv6
copy ..\..\..\..\cyclone_tcp\ppp\*.h main\cyclone_tcp\ppp
copy ..\..\..\..\cyclone_tcp\mibs\*.h main\cyclone_tcp\mibs
copy ..\..\..\..\cyclone_tcp\dns\*.h main\cyclone_tcp\dns
copy ..\..\..\..\cyclone_tcp\mdns\*.h main\cyclone_tcp\mdns
copy ..\..\..\..\cyclone_tcp\dns_sd\*.h main\cyclone_tcp\dns_sd
copy ..\..\..\..\cyclone_tcp\netbios\*.h main\cyclone_tcp\netbios
copy ..\..\..\..\cyclone_tcp\llmnr\*.h main\cyclone_tcp\llmnr
copy ..\..\..\..\cyclone_tcp\dhcp\*.h main\cyclone_tcp\dhcp
copy ..\..\..\..\cyclone_tcp\dhcpv6\*.h main\cyclone_tcp\dhcpv6

REM CycloneSSH Sources
copy ..\..\..\..\cyclone_ssh\ssh\*.c main\cyclone_ssh\ssh
copy ..\..\..\..\cyclone_ssh\scp\scp_client*.c main\cyclone_ssh\scp
copy ..\..\..\..\cyclone_ssh\scp\scp_common.c main\cyclone_ssh\scp

REM CycloneSSH Headers
copy ..\..\..\..\cyclone_ssh\ssh\*.h main\cyclone_ssh\ssh
copy ..\..\..\..\cyclone_ssh\scp\scp_client*.h main\cyclone_ssh\scp
copy ..\..\..\..\cyclone_ssh\scp\scp_common.h main\cyclone_ssh\scp

REM CycloneCRYPTO Sources
copy ..\..\..\..\cyclone_crypto\hardware\esp32\*.c main\cyclone_crypto\hardware\esp32
copy ..\..\..\..\cyclone_crypto\hash\md5.c main\cyclone_crypto\hash
copy ..\..\..\..\cyclone_crypto\hash\ripemd160.c main\cyclone_crypto\hash
copy ..\..\..\..\cyclone_crypto\hash\sha1.c main\cyclone_crypto\hash
copy ..\..\..\..\cyclone_crypto\hash\sha256.c main\cyclone_crypto\hash
copy ..\..\..\..\cyclone_crypto\hash\sha384.c main\cyclone_crypto\hash
copy ..\..\..\..\cyclone_crypto\hash\sha512.c main\cyclone_crypto\hash
copy ..\..\..\..\cyclone_crypto\mac\hmac.c main\cyclone_crypto\mac
copy ..\..\..\..\cyclone_crypto\cipher\rc4.c main\cyclone_crypto\cipher
copy ..\..\..\..\cyclone_crypto\cipher\idea.c main\cyclone_crypto\cipher
copy ..\..\..\..\cyclone_crypto\cipher\des.c main\cyclone_crypto\cipher
copy ..\..\..\..\cyclone_crypto\cipher\des3.c main\cyclone_crypto\cipher
copy ..\..\..\..\cyclone_crypto\cipher\aes.c main\cyclone_crypto\cipher
copy ..\..\..\..\cyclone_crypto\cipher\blowfish.c main\cyclone_crypto\cipher
copy ..\..\..\..\cyclone_crypto\cipher\camellia.c main\cyclone_crypto\cipher
copy ..\..\..\..\cyclone_crypto\cipher\seed.c main\cyclone_crypto\cipher
copy ..\..\..\..\cyclone_crypto\cipher_mode\cbc.c main\cyclone_crypto\cipher_mode
copy ..\..\..\..\cyclone_crypto\cipher_mode\ctr.c main\cyclone_crypto\cipher_mode
copy ..\..\..\..\cyclone_crypto\aead\gcm.c main\cyclone_crypto\aead
copy ..\..\..\..\cyclone_crypto\cipher\chacha.c main\cyclone_crypto\cipher
copy ..\..\..\..\cyclone_crypto\mac\poly1305.c main\cyclone_crypto\mac
copy ..\..\..\..\cyclone_crypto\pkc\dh.c main\cyclone_crypto\pkc
copy ..\..\..\..\cyclone_crypto\pkc\rsa.c main\cyclone_crypto\pkc
copy ..\..\..\..\cyclone_crypto\pkc\dsa.c main\cyclone_crypto\pkc
copy ..\..\..\..\cyclone_crypto\ecc\ec.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\ec_curves.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\ecdh.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\ecdsa.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\eddsa.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\curve25519.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\curve448.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\x25519.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\x448.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\ed25519.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\ecc\ed448.c main\cyclone_crypto\ecc
copy ..\..\..\..\cyclone_crypto\mpi\mpi.c main\cyclone_crypto\mpi
copy ..\..\..\..\cyclone_crypto\encoding\base64.c main\cyclone_crypto\encoding
copy ..\..\..\..\cyclone_crypto\encoding\asn1.c main\cyclone_crypto\encoding
copy ..\..\..\..\cyclone_crypto\encoding\oid.c main\cyclone_crypto\encoding
copy ..\..\..\..\cyclone_crypto\pkix\pem_import.c main\cyclone_crypto\pkix
copy ..\..\..\..\cyclone_crypto\pkix\pkcs8_key_parse.c main\cyclone_crypto\pkix
copy ..\..\..\..\cyclone_crypto\pkix\x509_key_parse.c main\cyclone_crypto\pkix
copy ..\..\..\..\cyclone_crypto\pkix\x509_common.c main\cyclone_crypto\pkix
copy ..\..\..\..\cyclone_crypto\rng\yarrow.c main\cyclone_crypto\rng

REM CycloneCRYPTO Headers
copy ..\..\..\..\cyclone_crypto\core\*.h main\cyclone_crypto\core
copy ..\..\..\..\cyclone_crypto\hardware\esp32\*.h main\cyclone_crypto\hardware\esp32
copy..\..\..\..\cyclone_crypto\hash\*.h main\cyclone_crypto\hash
copy..\..\..\..\cyclone_crypto\mac\*.h main\cyclone_crypto\mac
copy..\..\..\..\cyclone_crypto\cipher\*.h main\cyclone_crypto\cipher
copy..\..\..\..\cyclone_crypto\cipher_mode\*.h main\cyclone_crypto\cipher_mode
copy..\..\..\..\cyclone_crypto\aead\*.h main\cyclone_crypto\aead
copy..\..\..\..\cyclone_crypto\pkc\*.h main\cyclone_crypto\pkc
copy..\..\..\..\cyclone_crypto\ecc\*.h main\cyclone_crypto\ecc
copy..\..\..\..\cyclone_crypto\mpi\*.h main\cyclone_crypto\mpi
copy..\..\..\..\cyclone_crypto\encoding\*.h main\cyclone_crypto\encoding
copy..\..\..\..\cyclone_crypto\pkix\*.h main\cyclone_crypto\pkix
copy..\..\..\..\cyclone_crypto\rng\*.h main\cyclone_crypto\rng
copy..\..\..\..\cyclone_crypto\xof\*.h main\cyclone_crypto\xof
