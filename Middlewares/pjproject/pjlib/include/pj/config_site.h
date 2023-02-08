/*
 * This file contains several sample settings especially for Windows
 * Mobile and Symbian targets. You can include this file in your
 * <pj/config_site.h> file.
 *
 * The Windows Mobile and Symbian settings will be activated
 * automatically if you include this file.
 *
 * In addition, you may specify one of these macros (before including
 * this file) to activate additional settings:
 *
 * #define PJ_CONFIG_NOKIA_APS_DIRECT
 *   Use this macro to activate the APS-Direct feature. Please see
 *   http://trac.pjsip.org/repos/wiki/Nokia_APS_VAS_Direct for more 
 *   info.
 *
 * #define PJ_CONFIG_WIN32_WMME_DIRECT
 *   Configuration to activate "APS-Direct" media mode on Windows or
 *   Windows Mobile, useful for testing purposes only.
 */

    /*
     * PJLIB settings.
     */

    /* Disable floating point support */
    #undef PJ_HAS_FLOATING_POINT
    #define PJ_HAS_FLOATING_POINT		0

    /* Select codecs to disable */
    #define PJMEDIA_HAS_L16_CODEC		0
    #define PJMEDIA_HAS_ILBC_CODEC		0

    /*
     * PJMEDIA settings
     */

    /* We have our own OpenSL ES backend */
    #define PJMEDIA_AUDIO_DEV_HAS_PORTAUDIO	0
    #define PJMEDIA_AUDIO_DEV_HAS_WMME		0

    /* Quality 3 - 4 to use resampling small filter */
    #undef PJMEDIA_AUDIO_DEV_HAS_PORTAUDIO
    #define PJMEDIA_AUDIO_DEV_HAS_PORTAUDIO		0

    #undef PJMEDIA_AUDIO_DEV_HAS_ALSA
    #define PJMEDIA_AUDIO_DEV_HAS_ALSA			0    

    /*
     * PJSIP settings.
     */

    /* Set maximum number of dialog/transaction/calls to minimum to reduce
     * memory usage 
     */
    #define PJSIP_MAX_TSX_COUNT 		15
    #define PJSIP_MAX_DIALOG_COUNT 		15
    #define PJSUA_MAX_CALLS			    1


    /*
     * PJSUA settings
     */

    /* Default codec quality, previously was set to 5, however it is now
     * set to 4 to make sure pjsua instantiates resampler with small filter.
     */
    #define PJSUA_DEFAULT_CODEC_QUALITY		1

    /* Set maximum number of objects to minimum to reduce memory usage */
    #define PJSUA_MAX_ACC			1
    #define PJSUA_MAX_PLAYERS			2
    #define PJSUA_MAX_RECORDERS			2
    #define PJSUA_MAX_CONF_PORTS		(PJSUA_MAX_CALLS+2*PJSUA_MAX_PLAYERS)
    #define PJSUA_MAX_BUDDIES			32

    #define PJSIP_UDP_SO_SNDBUF_SIZE	4000
    #define PJSIP_UDP_SO_RCVBUF_SIZE	2000
    
    #undef  PJ_IOQUEUE_MAX_HANDLES
    #define PJ_IOQUEUE_MAX_HANDLES	    32

    #define PJMEDIA_HAS_G722_CODEC  0
    #define PJMEDIA_HAS_ILBC_CODEC  0
    #define PJMEDIA_HAS_GSM_CODEC   0



#define PJMEDIA_AUDIO_DEV_HAS_WMME  0
//#define PJ_HAS_FLOATING_POINT       1
#define PJMEDIA_HAS_SRTP            0  
#define PJMEDIA_HAS_ILBC_CODEC      0
#define PJMEDIA_HAS_GSM_CODEC       0
#define PJMEDIA_HAS_L16_CODEC       0
#define PJ_TERM_HAS_COLOR			0
#define PJ_SOCK_HAS_IPV6_V6ONLY 	0
#define PJ_SOCK_HAS_INET_ATON 		1
#define PJ_SOCK_HAS_INET_PTON 		1
#define PJ_SOCK_HAS_INET_NTOP 		1
#define PJ_SOCK_HAS_GETADDRINFO 	0
#define PJ_HAS_SOCKLEN_T			1
#define PJMEDIA_AUDIO_DEV_HAS_NULL_AUDIO  0

#define PJSUA_POOL_LEN 2048
#define PJSUA_POOL_INC 2048
#define PJSUA_POOL_LEN_ACC 2048
#define PJSUA_POOL_INC_ACC 2048
#define PJMEDIA_AUDIO_DEV_HAS_STM   1

// 由于ESP32性能再跑SPEEX的时候不太够,所有就关闭了


#define PJMEDIA_HAS_SPEEX_AEC 0
#define PJMEDIA_HAS_SPEEX_CODEC 0
#define PJMEDIA_SPEEX_AEC_USE_AGC   0
