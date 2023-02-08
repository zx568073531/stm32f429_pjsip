md main\CycloneTCP\common
md main\CycloneTCP\cyclone_tcp
md main\CycloneTCP\cyclone_tcp\core
md main\CycloneTCP\cyclone_tcp\drivers
md main\CycloneTCP\cyclone_tcp\drivers\wifi
md main\CycloneTCP\cyclone_tcp\ipv4
md main\CycloneTCP\cyclone_tcp\igmp
md main\CycloneTCP\cyclone_tcp\ipv6
md main\CycloneTCP\cyclone_tcp\ppp
md main\CycloneTCP\cyclone_tcp\mibs
md main\CycloneTCP\cyclone_tcp\dns
md main\CycloneTCP\cyclone_tcp\mdns
md main\CycloneTCP\cyclone_tcp\dns_sd
md main\CycloneTCP\cyclone_tcp\netbios
md main\CycloneTCP\cyclone_tcp\llmnr
md main\CycloneTCP\cyclone_tcp\dhcp
md main\CycloneTCP\cyclone_tcp\dhcpv6
md main\CycloneTCP\cyclone_ssh
md main\CycloneTCP\cyclone_ssh\ssh
md main\CycloneTCP\cyclone_ssh\shell
md main\CycloneTCP\cyclone_crypto
md main\CycloneTCP\cyclone_crypto\core
md main\CycloneTCP\cyclone_crypto\hardware
md main\CycloneTCP\cyclone_crypto\hardware\esp32
md main\CycloneTCP\cyclone_crypto\hash
md main\CycloneTCP\cyclone_crypto\mac
md main\CycloneTCP\cyclone_crypto\cipher
md main\CycloneTCP\cyclone_crypto\cipher_mode
md main\CycloneTCP\cyclone_crypto\aead
md main\CycloneTCP\cyclone_crypto\pkc
md main\CycloneTCP\cyclone_crypto\ecc
md main\CycloneTCP\cyclone_crypto\mpi
md main\CycloneTCP\cyclone_crypto\encoding
md main\CycloneTCP\cyclone_crypto\pkix
md main\CycloneTCP\cyclone_crypto\kdf
md main\CycloneTCP\cyclone_crypto\rng
md main\CycloneTCP\cyclone_crypto\xof

REM Common Sources
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\cpu_endian.c main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\os_port_freertos.c main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\date_time.c main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\str.c main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\resource_manager.c main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\debug.c main\CycloneTCP\common

REM Common Headers
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\cpu_endian.h main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\compiler_port.h main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\os_port.h main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\os_port_freertos.h main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\date_time.h main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\str.h main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\resource_manager.h main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\error.h main\CycloneTCP\common
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\common\debug.h main\CycloneTCP\common

REM CycloneTCP Sources
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\drivers\wifi\esp32_wifi_driver.c main\CycloneTCP\cyclone_tcp\drivers\wifi
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\core\*.c main\CycloneTCP\cyclone_tcp\core
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\ipv4\*.c main\CycloneTCP\cyclone_tcp\ipv4
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\igmp\*.c main\CycloneTCP\cyclone_tcp\igmp
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\ipv6\*.c main\CycloneTCP\cyclone_tcp\ipv6
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\dns\*.c main\CycloneTCP\cyclone_tcp\dns
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\mdns\*.c main\CycloneTCP\cyclone_tcp\mdns
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\netbios\*.c main\CycloneTCP\cyclone_tcp\netbios
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\llmnr\*.c main\CycloneTCP\cyclone_tcp\llmnr
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\dhcp\*.c main\CycloneTCP\cyclone_tcp\dhcp

REM CycloneTCP Headers
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\drivers\wifi\esp32_wifi_driver.h main\CycloneTCP\cyclone_tcp\drivers\wifi
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\core\*.h main\CycloneTCP\cyclone_tcp\core
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\ipv4\*.h main\CycloneTCP\cyclone_tcp\ipv4
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\igmp\*.h main\CycloneTCP\cyclone_tcp\igmp
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\ipv6\*.h main\CycloneTCP\cyclone_tcp\ipv6
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\ppp\*.h main\CycloneTCP\cyclone_tcp\ppp
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\mibs\*.h main\CycloneTCP\cyclone_tcp\mibs
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\dns\*.h main\CycloneTCP\cyclone_tcp\dns
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\mdns\*.h main\CycloneTCP\cyclone_tcp\mdns
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\dns_sd\*.h main\CycloneTCP\cyclone_tcp\dns_sd
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\netbios\*.h main\CycloneTCP\cyclone_tcp\netbios
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\llmnr\*.h main\CycloneTCP\cyclone_tcp\llmnr
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\dhcp\*.h main\CycloneTCP\cyclone_tcp\dhcp
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_tcp\dhcpv6\*.h main\CycloneTCP\cyclone_tcp\dhcpv6

REM CycloneSSH Sources
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_ssh\ssh\*.c main\CycloneTCP\cyclone_ssh\ssh
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_ssh\shell\*.c main\CycloneTCP\cyclone_ssh\shell

REM CycloneSSH Headers
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_ssh\ssh\*.h main\CycloneTCP\cyclone_ssh\ssh
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_ssh\shell\*.h main\CycloneTCP\cyclone_ssh\shell

REM CycloneCRYPTO Sources
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\hardware\esp32\*.c main\CycloneTCP\cyclone_crypto\hardware\esp32
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\hash\md5.c main\CycloneTCP\cyclone_crypto\hash
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\hash\ripemd160.c main\CycloneTCP\cyclone_crypto\hash
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\hash\sha1.c main\CycloneTCP\cyclone_crypto\hash
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\hash\sha256.c main\CycloneTCP\cyclone_crypto\hash
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\hash\sha384.c main\CycloneTCP\cyclone_crypto\hash
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\hash\sha512.c main\CycloneTCP\cyclone_crypto\hash
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\mac\hmac.c main\CycloneTCP\cyclone_crypto\mac
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\rc4.c main\CycloneTCP\cyclone_crypto\cipher
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\idea.c main\CycloneTCP\cyclone_crypto\cipher
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\des.c main\CycloneTCP\cyclone_crypto\cipher
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\des3.c main\CycloneTCP\cyclone_crypto\cipher
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\aes.c main\CycloneTCP\cyclone_crypto\cipher
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\blowfish.c main\CycloneTCP\cyclone_crypto\cipher
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\camellia.c main\CycloneTCP\cyclone_crypto\cipher
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\seed.c main\CycloneTCP\cyclone_crypto\cipher
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher_mode\cbc.c main\CycloneTCP\cyclone_crypto\cipher_mode
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher_mode\ctr.c main\CycloneTCP\cyclone_crypto\cipher_mode
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\aead\gcm.c main\CycloneTCP\cyclone_crypto\aead
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\chacha.c main\CycloneTCP\cyclone_crypto\cipher
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\mac\poly1305.c main\CycloneTCP\cyclone_crypto\mac
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\pkc\dh.c main\CycloneTCP\cyclone_crypto\pkc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\pkc\rsa.c main\CycloneTCP\cyclone_crypto\pkc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\pkc\dsa.c main\CycloneTCP\cyclone_crypto\pkc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\ec.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\ec_curves.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\ecdh.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\ecdsa.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\eddsa.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\curve25519.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\curve448.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\x25519.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\x448.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\ed25519.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\ed448.c main\CycloneTCP\cyclone_crypto\ecc
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\mpi\mpi.c main\CycloneTCP\cyclone_crypto\mpi
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\encoding\base64.c main\CycloneTCP\cyclone_crypto\encoding
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\encoding\asn1.c main\CycloneTCP\cyclone_crypto\encoding
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\encoding\oid.c main\CycloneTCP\cyclone_crypto\encoding
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\pkix\pem_import.c main\CycloneTCP\cyclone_crypto\pkix
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\pkix\pkcs8_key_parse.c main\CycloneTCP\cyclone_crypto\pkix
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\pkix\x509_key_parse.c main\CycloneTCP\cyclone_crypto\pkix
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\pkix\x509_common.c main\CycloneTCP\cyclone_crypto\pkix
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\rng\yarrow.c main\CycloneTCP\cyclone_crypto\rng

REM CycloneCRYPTO Headers
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\core\*.h main\CycloneTCP\cyclone_crypto\core
copy .\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\hardware\esp32\*.h main\CycloneTCP\cyclone_crypto\hardware\esp32
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\hash\*.h main\CycloneTCP\cyclone_crypto\hash
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\mac\*.h main\CycloneTCP\cyclone_crypto\mac
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher\*.h main\CycloneTCP\cyclone_crypto\cipher
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\cipher_mode\*.h main\CycloneTCP\cyclone_crypto\cipher_mode
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\aead\*.h main\CycloneTCP\cyclone_crypto\aead
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\pkc\*.h main\CycloneTCP\cyclone_crypto\pkc
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\ecc\*.h main\CycloneTCP\cyclone_crypto\ecc
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\mpi\*.h main\CycloneTCP\cyclone_crypto\mpi
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\encoding\*.h main\CycloneTCP\cyclone_crypto\encoding
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\pkix\*.h main\CycloneTCP\cyclone_crypto\pkix
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\rng\*.h main\CycloneTCP\cyclone_crypto\rng
copy.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\cyclone_crypto\xof\*.h main\CycloneTCP\cyclone_crypto\xof

REM Compile resources
.\middlewares\CycloneTCP_SSL_SSH_CRYPTO_Open_2_1_4\utils\ResourceCompiler\bin\rc.exe resources main\CycloneTCP\res.c
