
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#include "systemCore.h"
#include "audio.h"
#include "task_network.h"
#include "user_sd_init.h"
#include <cm_backtrace.h>
#include <pjsua-lib/pjsua.h>
#include <pthread.h>

#define THIS_FILE	"APP"

#define SIP_DOMAIN	"192.168.1.20"
#define SIP_USER		"7000"
#define SIP_PASSWD	"7000"


/* Callback called by the library upon receiving incoming call */
static void on_incoming_call(pjsua_acc_id acc_id, pjsua_call_id call_id,
			     pjsip_rx_data *rdata)
{
    pjsua_call_info ci;

    PJ_UNUSED_ARG(acc_id);
    PJ_UNUSED_ARG(rdata);

    pjsua_call_get_info(call_id, &ci);

    PJ_LOG(3,(THIS_FILE, "Incoming call from %.*s!!",
			 (int)ci.remote_info.slen,
			 ci.remote_info.ptr));

    /* Automatically answer incoming calls with 200/OK */
    pjsua_call_answer(call_id, 200, NULL, NULL);
}

/* Callback called by the library when call's state has changed */
static void on_call_state(pjsua_call_id call_id, pjsip_event *e)
{
    pjsua_call_info ci;

    PJ_UNUSED_ARG(e);

    pjsua_call_get_info(call_id, &ci);
    PJ_LOG(3,(THIS_FILE, "Call %d state=%.*s", call_id,
			 (int)ci.state_text.slen,
			 ci.state_text.ptr));
}

/* Callback called by the library when call's media state has changed */
static void on_call_media_state(pjsua_call_id call_id)
{
    pjsua_call_info ci;

    pjsua_call_get_info(call_id, &ci);

    if (ci.media_status == PJSUA_CALL_MEDIA_ACTIVE) {
	// When media is active, connect call to sound device.
	pjsua_conf_connect(ci.conf_slot, 0);
	pjsua_conf_connect(0, ci.conf_slot);
    }
}

/* Display error and exit application */
static void error_exit(const char *title, pj_status_t status)
{
    pjsua_perror(THIS_FILE, title, status);
    pjsua_destroy();
    exit(1);
}


/*
 * main()
 *
 * argv[1] may contain URL to call.
 */
void* simple_pjsua(void * argv)
{
    pjsua_acc_id acc_id;
    pj_status_t status;
	
    /* Create pjsua first! */
    status = pjsua_create();
    if (status != PJ_SUCCESS) error_exit("Error in pjsua_create()", status);

//    /* If argument is specified, it's got to be a valid SIP URL */
//    if (argv > 1) {
//	status = pjsua_verify_url(argv[1]);
//	if (status != PJ_SUCCESS) error_exit("Invalid URL in argv", status);
//    }

    /* Init pjsua */
    {
	pjsua_config cfg;
	pjsua_logging_config log_cfg;

	pjsua_config_default(&cfg);
	cfg.cb.on_incoming_call = &on_incoming_call;
	cfg.cb.on_call_media_state = &on_call_media_state;
	cfg.cb.on_call_state = &on_call_state;

	pjsua_logging_config_default(&log_cfg);
	log_cfg.console_level = 4;

	status = pjsua_init(&cfg, &log_cfg, NULL);
	if (status != PJ_SUCCESS) error_exit("Error in pjsua_init()", status);
    }

    /* Add UDP transport. */
    {
	pjsua_transport_config cfg;

	pjsua_transport_config_default(&cfg);
	cfg.port = 5060;
	status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, NULL);
	if (status != PJ_SUCCESS) error_exit("Error creating transport", status);
    }

    /* Initialization is done, now start pjsua */
    status = pjsua_start();
    if (status != PJ_SUCCESS) error_exit("Error starting pjsua", status);

    /* Register to SIP server by creating SIP account. */
    {
			pjsua_acc_config cfg;

			pjsua_acc_config_default(&cfg);
			cfg.id = pj_str("sip:" SIP_USER "@" SIP_DOMAIN);
			cfg.reg_uri = pj_str("sip:" SIP_DOMAIN);
			cfg.cred_count = 1;
			cfg.cred_info[0].realm = pj_str("*");
			cfg.cred_info[0].scheme = pj_str("digest");
			cfg.cred_info[0].username = pj_str(SIP_USER);
			cfg.cred_info[0].data_type = PJSIP_CRED_DATA_PLAIN_PASSWD;
			cfg.cred_info[0].data = pj_str(SIP_PASSWD);

			status = pjsua_acc_add(&cfg, PJ_TRUE, &acc_id);
			if (status != PJ_SUCCESS) error_exit("Error adding account", status);
    }

    /* If URL is specified, make call to the URL. */
//    if (argc > 1) {
//			pj_str_t uri = pj_str(argv[1]);
//			status = pjsua_call_make_call(acc_id, &uri, 0, NULL, NULL, NULL);
//			if (status != PJ_SUCCESS) error_exit("Error making call", status);
//    }
			uint8_t CPU_RunInfo[400];		//保存任务运行时间信息
  
			memset(CPU_RunInfo,0,400);				//信息缓冲区清零
			
    /* Wait until user press "q" to quit. */
    for (;;) {

//			vTaskList((char *)&CPU_RunInfo);  //获取任务运行时间信息
//			
//			msg_log("---------------------------------------------\r\n");
//			msg_log("NAME      STATUS  PRIO   STACK  NUMBER\r\n");
//			msg_log("%s", CPU_RunInfo);
//			msg_log("---------------------------------------------\r\n");
//			
//			memset(CPU_RunInfo,0,400);				//信息缓冲区清零
//			
//			vTaskGetRunTimeStats((char *)&CPU_RunInfo);
//			
//			msg_log("NAME       Count         CPU\r\n");
//			msg_log("%s", CPU_RunInfo);
//			msg_log("---------------------------------------------\r\n\n");
//		
			sleep(5);

//			char option[10];

//			puts("Press 'h' to hangup all calls, 'q' to quit");
//			option[0] = SEGGER_RTT_WaitKey();

//			if (option[0] == 'q')
//					break;

//			if (option[0] == 'h')
//					pjsua_call_hangup_all();
    }

    /* Destroy pjsua */
    pjsua_destroy();

    return NULL;
}




//const unsigned char wav[384000];

//void* audio_test(void * argv)
//{
//	uint32_t pick = 0;
//	uint32_t write ;
//	
//	// 初始化音频接口
//	AudioInterfaceInit(0,0);
//	
//	Audio_Config_FullDuplex();
//	
//	while(1)
//	{
//		AudioWriteData(&wav[pick] , 384000 , &write , portMAX_DELAY);
//		printf("Write %d %d\r\n",write,xTaskGetTickCount());
//	}

//  return NULL;
//}




void userAppEntry(void *arg)
{
	static pthread_t  thread;

	pthread_key_init();
	
	// 初始化音频接口
	AudioInterfaceInit(0,0);	
	
	// SD卡初始化
	UserSDcardInit();
	
	// 初始化系统网络/协议栈
	network_Init();
	
	vTaskDelay(2000);
	
	// 使能PJSIP
	pthread_attr_t attr;
	
	pthread_attr_init(&attr);
	
	attr.ulpthreadAttrStorage &= (0xFFFF0000);
	attr.ulpthreadAttrStorage |= (15 * 1024);
	
	pthread_create(&thread, &attr, simple_pjsua, NULL);
	

	// 删除当前线程
	vTaskDelete(NULL);
}


/**
  * @brief  用户函数入口
  */
void UserApplication_Entry(void)
{
	/* CmBacktrace initialize */
	cm_backtrace_init("CmBacktrace", "1.0", "1.0");

  // Create CDC task
  (void) xTaskCreate( userAppEntry, "app", 4096, NULL, configMAX_PRIORITIES - 1, NULL);
	
  // skip starting scheduler (and return) for ESP32-S2 or ESP32-S3
  vTaskStartScheduler();

	for(;;);
}
