/* $Id$ */
/*
 * Copyright (C) 2009-2011 Teluu Inc. (http://www.teluu.com)
 * Copyright (C) 2007-2009 Keystream AB and Konftel AB, All rights reserved.
 *                         Author: <dan.aberg@keystream.se>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <pjmedia_audiodev.h>
#include <pj/assert.h>
#include <pj/log.h>
#include <pj/os.h>
#include <pj/pool.h>
#include <pjmedia/errno.h>
#include <pjmedia/stereo.h>

#if defined(PJMEDIA_AUDIO_DEV_HAS_STM) && (PJMEDIA_AUDIO_DEV_HAS_STM == 1)

#include "audio.h"
// STM32 Audio Interface Headers


#define THIS_FILE 			        "stm_dev.c"

/* Set to 1 to enable tracing */
#define ENABLE_TRACING			1

#if ENABLE_TRACING
#	define TRACE_(expr)		PJ_LOG(3,expr)
#else
#	define TRACE_(expr)
#endif

#define I2S_SAMPLE_RATE     16000
#define I2S_CHANNELS        2
#define I2S_BITS            16


/* esp32_audio factory */
struct esp32_audio_factory
{
    pjmedia_aud_dev_factory	 base;
    pj_pool_t							*pool;
    pj_pool_factory				*pf;

    unsigned			 				dev_count;
    pjmedia_aud_dev_info 	dev_info;
};

/* Sound stream. */
struct esp32_audio_stream
{
    pjmedia_aud_stream	base;		    /**< Base stream	       */
    struct esp32_audio_factory *nf;
    pjmedia_aud_param	 	param;		    /**< Settings	       */
    pj_pool_t           *pool;              /**< Memory pool.          */
    int                 quit;


    pj_thread_t         *pb_thread;
    pjmedia_aud_play_cb play_cb;           /**< Playback callback.    */
    unsigned            pb_buf_size;
    char		        		*pb_buf;


    pj_thread_t		   	 	*ca_thread;
    pjmedia_aud_rec_cb  rec_cb;            /**< Capture callback.     */
    unsigned            ca_buf_size;
    char		        		*ca_buf;    

    void                *user_data;         /**< Application data.     */

};


/* Prototypes */
static pj_status_t esp32_factory_init(pjmedia_aud_dev_factory *f);
static pj_status_t esp32_factory_destroy(pjmedia_aud_dev_factory *f);
static pj_status_t esp32_factory_refresh(pjmedia_aud_dev_factory *f);
static unsigned    esp32_factory_get_dev_count(pjmedia_aud_dev_factory *f);
static pj_status_t esp32_factory_get_dev_info(pjmedia_aud_dev_factory *f,
					     unsigned index,
					     pjmedia_aud_dev_info *info);
static pj_status_t esp32_factory_default_param(pjmedia_aud_dev_factory *f,
					      unsigned index,
					      pjmedia_aud_param *param);
static pj_status_t esp32_factory_create_stream(pjmedia_aud_dev_factory *f,
					      const pjmedia_aud_param *param,
					      pjmedia_aud_rec_cb rec_cb,
					      pjmedia_aud_play_cb play_cb,
					      void *user_data,
					      pjmedia_aud_stream **p_aud_strm);

static pj_status_t esp32_stream_get_param(pjmedia_aud_stream *strm,
					 pjmedia_aud_param *param);
static pj_status_t esp32_stream_get_cap(pjmedia_aud_stream *strm,
				       pjmedia_aud_dev_cap cap,
				       void *value);
static pj_status_t esp32_stream_set_cap(pjmedia_aud_stream *strm,
				       pjmedia_aud_dev_cap cap,
				       const void *value);
static pj_status_t esp32_stream_start(pjmedia_aud_stream *strm);
static pj_status_t esp32_stream_stop(pjmedia_aud_stream *strm);
static pj_status_t esp32_stream_destroy(pjmedia_aud_stream *strm);

/* Operations */
static pjmedia_aud_dev_factory_op esp_factory_op =
{
    &esp32_factory_init,
    &esp32_factory_destroy,
    &esp32_factory_get_dev_count,
    &esp32_factory_get_dev_info,
    &esp32_factory_default_param,
    &esp32_factory_create_stream,
    &esp32_factory_refresh
};

static pjmedia_aud_stream_op esp_stream_op =
{
    &esp32_stream_get_param,
    &esp32_stream_get_cap,
    &esp32_stream_set_cap,
    &esp32_stream_start,
    &esp32_stream_stop,
    &esp32_stream_destroy
};


/****************************************************************************
 * Factory operations
 */
/*
 * Init esp32_audio audio driver.
 */
pjmedia_aud_dev_factory* pjmedia_esp32_audio_factory(pj_pool_factory *pf)
{
    struct esp32_audio_factory *f;
    pj_pool_t *pool;

    pool = pj_pool_create(pf, "esp32 audio", 1024, 1024, NULL);
    f = PJ_POOL_ZALLOC_T(pool, struct esp32_audio_factory);
    f->pf = pf;
    f->pool = pool;
    f->base.op = &esp_factory_op;

    return &f->base;
}


/* API: init factory */
static pj_status_t esp32_factory_init(pjmedia_aud_dev_factory *f)
{
    struct esp32_audio_factory *nf = (struct esp32_audio_factory*)f;
    pjmedia_aud_dev_info *ndi;

    /* Initialize input and output devices here */
    nf->dev_count = 1;
    ndi = &nf->dev_info;
    
    pj_bzero(ndi, sizeof(*ndi));
    strcpy(ndi->name, "esp32 device");
    strcpy(ndi->driver, "esp32");
    ndi->input_count = 1;
    ndi->output_count = 1;
    ndi->default_samples_per_sec = I2S_SAMPLE_RATE;
    /* Set the device capabilities here */
    ndi->caps = 0;

    ndi->caps |= PJMEDIA_AUD_DEV_CAP_INPUT_LATENCY;
    ndi->caps |= PJMEDIA_AUD_DEV_CAP_OUTPUT_LATENCY;
    
    TRACE_((THIS_FILE, "esp32 audio initialized"));

    return PJ_SUCCESS;
}

/* API: destroy factory */
static pj_status_t esp32_factory_destroy(pjmedia_aud_dev_factory *f)
{
    struct esp32_audio_factory *nf = (struct esp32_audio_factory*)f;

    pj_pool_safe_release(&nf->pool);

    return PJ_SUCCESS;
}

/* API: refresh the list of devices */
static pj_status_t esp32_factory_refresh(pjmedia_aud_dev_factory *f)
{
    PJ_UNUSED_ARG(f);

    /* esp32 only one device not need refresh */
    TRACE_((THIS_FILE, "refresh device!"));
    return PJ_SUCCESS;
}

/* API: get number of devices */
static unsigned esp32_factory_get_dev_count(pjmedia_aud_dev_factory *f)
{
    struct esp32_audio_factory *nf = (struct esp32_audio_factory*)f;
    return nf->dev_count;
}

/* API: get device info */
static pj_status_t esp32_factory_get_dev_info(pjmedia_aud_dev_factory *f,
					     unsigned index,
					     pjmedia_aud_dev_info *info)
{
    struct esp32_audio_factory *nf = (struct esp32_audio_factory*)f;

    PJ_ASSERT_RETURN(index < nf->dev_count, PJMEDIA_EAUD_INVDEV);

    pj_memcpy(info, &nf->dev_info, sizeof(*info));
    info->caps = PJMEDIA_AUD_DEV_CAP_INPUT_LATENCY |
		        PJMEDIA_AUD_DEV_CAP_OUTPUT_LATENCY;

    TRACE_((THIS_FILE,"esp32_factory_get_dev_info %d",index));

    return PJ_SUCCESS;
}

/* API: create default device parameter */
static pj_status_t esp32_factory_default_param(pjmedia_aud_dev_factory *f,
					      unsigned index,
					      pjmedia_aud_param *param)
{
    struct esp32_audio_factory *nf = (struct esp32_audio_factory*)f;
    pjmedia_aud_dev_info *di = NULL;

    PJ_ASSERT_RETURN(index < nf->dev_count, PJMEDIA_EAUD_INVDEV);
    di = &nf->dev_info;

    TRACE_((THIS_FILE, "factory_default_param ndi %p",di));

    pj_bzero(param, sizeof(*param));
    if (di->input_count && di->output_count) {
        param->dir = PJMEDIA_DIR_CAPTURE_PLAYBACK;
        param->rec_id = index;
        param->play_id = index;
    } else if (di->input_count) {
        param->dir = PJMEDIA_DIR_CAPTURE;
        param->rec_id = index;
        param->play_id = PJMEDIA_AUD_INVALID_DEV;
    } else if (di->output_count) {
        param->dir = PJMEDIA_DIR_PLAYBACK;
        param->play_id = index;
        param->rec_id = PJMEDIA_AUD_INVALID_DEV;
    } else {
	    return PJMEDIA_EAUD_INVDEV;
    }

    /* Set the mandatory settings here */
    /* The values here are just some examples */
    param->clock_rate = di->default_samples_per_sec;
    param->channel_count = 2;
    param->samples_per_frame = di->default_samples_per_sec * 20 / 1000;
    param->bits_per_sample = 16;

    TRACE_((THIS_FILE,"di->default_samples_per_sec %d",di->default_samples_per_sec));
    TRACE_((THIS_FILE,"nf->dev_info[index] %d",index));
    TRACE_((THIS_FILE,"param->clock_rate %d",param->clock_rate));
    TRACE_((THIS_FILE, "param %p",param));
    /* Set the device capabilities here */
    param->flags = di->caps;
    param->input_latency_ms = 40;
    param->output_latency_ms = 40;

    return PJ_SUCCESS;
}

static int pb_thread_func (void *arg)
{
    struct esp32_audio_stream* stream = (struct esp32_audio_stream*) arg;
    int size                   = stream->pb_buf_size;
    void* user_data            = stream->user_data;
    char* buf 		           = stream->pb_buf;
    pj_timestamp tstamp;
    uint32_t result;
	
//		pj_thread_set_prio(pj_thread_this(), 2);
    
    pj_bzero (buf, size);
    tstamp.u64 = 0;

    TRACE_((THIS_FILE, "pb_thread_func: Started"));
    while (!stream->quit) {
        pjmedia_frame frame;

        frame.type = PJMEDIA_FRAME_TYPE_AUDIO;
        frame.buf = buf;
        frame.size = size;
        frame.timestamp.u64 = tstamp.u64;
        frame.bit_info = 0;

        result = stream->play_cb (user_data, &frame);
        if (result != PJ_SUCCESS || stream->quit)
            break;

        if (frame.type != PJMEDIA_FRAME_TYPE_AUDIO)
            pj_bzero (buf, size);

        pjmedia_convert_channel_1ton((pj_int16_t*)buf, 
						 (const pj_int16_t*)buf,
						 2, 
						 320,
						 0);

        /* Write Stream To I2S */
				AudioWriteData(buf, size * 2 , &result , portMAX_DELAY);		 
        if (result != size * 2) {
            TRACE_((THIS_FILE, "pb_thread_func: error writing data!"));
        }        
        else if(result < size)
        {
            TRACE_((THIS_FILE, "pb_thread_func: underrun!"));            
        }

        tstamp.u64 += size;
    }
		
    TRACE_((THIS_FILE, "pb_thread_func: Stopped"));
		pthread_exit(NULL);
    return PJ_SUCCESS;
}


static int ca_thread_func (void *arg)
{
    struct esp32_audio_stream* stream = (struct esp32_audio_stream*) arg;
    int size                   = stream->ca_buf_size;
    void* user_data            = stream->user_data;
    char* buf 		           = stream->ca_buf;
    pj_timestamp tstamp;
    uint32_t result;
    uint32_t wav_pick = 0;
		
//		pj_thread_set_prio(pj_thread_this(), 2);
    
		pj_bzero (buf, size);
    tstamp.u64 = 0;

    TRACE_((THIS_FILE, "ca_thread_func: Started"));
    TRACE_((THIS_FILE, "size %d",size));
		
    while (!stream->quit) {
        pjmedia_frame frame;

        pj_bzero (buf, size);
				
				AudioReadData(buf , size * 2 , &result , portMAX_DELAY);
				result = size * 2;
        if (result != size * 2) {
            TRACE_((THIS_FILE, "ca_thread_func: error reading data!"));
        }
        else if(result < 0)
        {
            TRACE_((THIS_FILE, "ca_thread_func: overrun!"));
        }
        
        if (stream->quit)
            break;

        pjmedia_convert_channel_nto1((pj_int16_t*)buf, (const pj_int16_t*)buf , 2, size , PJ_TRUE , 0);

        frame.type = PJMEDIA_FRAME_TYPE_AUDIO;
        frame.buf = (void*) buf;
        frame.size = size;
        frame.timestamp.u64 = tstamp.u64;
        frame.bit_info = 0;

        result = stream->rec_cb (user_data, &frame);
        if (result != PJ_SUCCESS || stream->quit)
            break;

        tstamp.u64 += size;
    }
		
    TRACE_((THIS_FILE, "ca_thread_func: Stopped"));
		pthread_exit(NULL);
    return PJ_SUCCESS;
}

static pj_status_t open_playback (struct esp32_audio_stream* stream,
			          const pjmedia_aud_param *param)
{
    int result;
    unsigned int rate;
    pj_uint32_t tmp_buf_size;
    pj_uint32_t tmp_period_size;

    if (param->play_id < 0 || param->play_id >= stream->nf->dev_count)
	return PJMEDIA_EAUD_INVDEV;

    /* Open PCM for playback */
    TRACE_((THIS_FILE, "open_playback: Open playback device '%s'",
	       stream->nf->dev_info.name));

    TRACE_((THIS_FILE, "open_playback: bits_per_sample '%d'",
            param->bits_per_sample));

    /* Set number of channels */
    TRACE_((THIS_FILE, "open_playback: set channels: %d",
		       param->channel_count));

    /* Set clock rate */
    rate = param->clock_rate;
    TRACE_((THIS_FILE, "open_playback: set clock rate: %d", rate));

    /* Set period size to samples_per_frame frames. */
    TRACE_((THIS_FILE, "open_playback: set period size: %d %d", param->samples_per_frame , param->channel_count));

    tmp_period_size = param->samples_per_frame /
					    param->channel_count;
    /* Set the sound device buffer size and latency */
    if (param->flags & PJMEDIA_AUD_DEV_CAP_OUTPUT_LATENCY)
	    tmp_buf_size = (rate / 1000) * param->output_latency_ms;
    else
	    tmp_buf_size = (rate / 1000) * PJMEDIA_SND_DEFAULT_PLAY_LATENCY;
    if (tmp_buf_size < tmp_period_size * 2)
        tmp_buf_size = tmp_period_size * 2;

    stream->param.output_latency_ms = tmp_buf_size / (rate / 1000);

    /* Set our buffer */
    stream->pb_buf_size = param->samples_per_frame * param->channel_count *
			  (param->bits_per_sample/8);
    stream->pb_buf = (char*) pj_pool_alloc(stream->pool, stream->pb_buf_size * 2);

    TRACE_((THIS_FILE, "open_playback: buffer size set to: %d",
	    (int)tmp_buf_size));
    TRACE_((THIS_FILE, "open_playback: playback_latency set to: %d ms",
	    (int)stream->param.output_latency_ms));

    TRACE_((THIS_FILE, "open_playback: stream->pb_buf_size set to: %d ",
	    (int)stream->pb_buf_size));

    TRACE_((THIS_FILE, "Opened device (%s) for playing, sample rate=%d"
	       ", ch=%d, bits=%d, period size=%d frames, latency=%d ms",
	       stream->nf->dev_info.name,
	       rate, param->channel_count,
	       param->bits_per_sample, tmp_period_size,
	       (int)stream->param.output_latency_ms));

    return PJ_SUCCESS;
}




static pj_status_t open_capture (struct esp32_audio_stream* stream,
			         const pjmedia_aud_param *param)
{
    int result;
    unsigned int rate;
    pj_uint32_t tmp_buf_size;
    pj_uint32_t tmp_period_size;

    if (param->rec_id < 0 || param->rec_id >= stream->nf->dev_count)
	return PJMEDIA_EAUD_INVDEV;

    /* Open PCM for capture */
    TRACE_((THIS_FILE, "open_capture: Open capture device '%s'",
	       stream->nf->dev_info.name));

    TRACE_((THIS_FILE, "open_playback: bits_per_sample '%d'",
            param->bits_per_sample));

    /* Set number of channels */
    TRACE_((THIS_FILE, "open_capture: set channels: %d",
	    param->channel_count));
    
    /* Set clock rate */
    rate = param->clock_rate;
    TRACE_((THIS_FILE, "open_capture: set clock rate: %d", rate));
    
    /* Set period size to samples_per_frame frames. */
    TRACE_((THIS_FILE, "open_capture: set period size: %d %d", param->samples_per_frame , param->channel_count));

    tmp_period_size = param->samples_per_frame /
					    param->channel_count;
    /* Set the sound device buffer size and latency */
    if (param->flags & PJMEDIA_AUD_DEV_CAP_INPUT_LATENCY)
	    tmp_buf_size = (rate / 1000) * param->input_latency_ms;
    else
	    tmp_buf_size = (rate / 1000) * PJMEDIA_SND_DEFAULT_REC_LATENCY;
    if (tmp_buf_size < tmp_period_size * 2)
        tmp_buf_size = tmp_period_size * 2;
   
    stream->param.input_latency_ms = tmp_buf_size / (rate / 1000);

    /* Set our buffer */
    stream->ca_buf_size = param->samples_per_frame * param->channel_count *
			  (param->bits_per_sample/8);
    stream->ca_buf = (char*) pj_pool_alloc (stream->pool, stream->ca_buf_size * 2);

    TRACE_((THIS_FILE, "open_capture: buffer size set to: %d",
	    (int)tmp_buf_size));
    TRACE_((THIS_FILE, "open_capture: capture_latency set to: %d ms",
	    (int)stream->param.input_latency_ms));

    TRACE_((THIS_FILE, "Opened device (%s) for capture, sample rate=%d"
	       ", ch=%d, bits=%d, period size=%d frames, latency=%d ms",
	       stream->nf->dev_info.name,
	       rate, param->channel_count,
	       param->bits_per_sample, tmp_period_size,
	       (int)stream->param.input_latency_ms));
           
		TRACE_((THIS_FILE, " recorder has been created"));
    
		return PJ_SUCCESS;
}



/* API: create stream */
static pj_status_t esp32_factory_create_stream(pjmedia_aud_dev_factory *f,
					      const pjmedia_aud_param *param,
					      pjmedia_aud_rec_cb rec_cb,
					      pjmedia_aud_play_cb play_cb,
					      void *user_data,
					      pjmedia_aud_stream **p_aud_strm)
{
    struct esp32_audio_factory *nf = (struct esp32_audio_factory*)f;
    pj_pool_t *pool;
    struct esp32_audio_stream *strm;
    pj_status_t status;

    /* Create and Initialize stream descriptor */
    pool = pj_pool_create(nf->pf, "esp32_audio-dev", 2048, 2048, NULL);
    PJ_ASSERT_RETURN(pool != NULL, PJ_ENOMEM);

    strm = PJ_POOL_ZALLOC_T(pool, struct esp32_audio_stream);
    strm->base.op = &esp_stream_op;
    strm->pool = pool;
    strm->nf   = nf;
    strm->rec_cb = rec_cb;
    strm->play_cb = play_cb;
    strm->user_data = user_data;
    strm->quit      = 0;

    pj_memcpy(&strm->param, param, sizeof(*param));

    TRACE_((THIS_FILE, "esp32_factory_create_stream"));

    TRACE_((THIS_FILE, "param %p",param));
    TRACE_((THIS_FILE, "param->rate %d",param->clock_rate));
    TRACE_((THIS_FILE, "sizeof(*param) %d",sizeof(*param)));

    TRACE_((THIS_FILE, "param->play_id %d",param->play_id));
    TRACE_((THIS_FILE, "param->rec_id %d",param->rec_id));

    // 使能全双工语音
		Audio_Config_FullDuplex();
		
    /* Create player stream here */
    if (param->dir & PJMEDIA_DIR_PLAYBACK) {
        status = open_playback (strm, param);
        if (status != PJ_SUCCESS) {
            pj_pool_release (pool);
            return status;
        }
    }

    /* Create capture stream here */
    if (param->dir & PJMEDIA_DIR_CAPTURE) {
        status = open_capture (strm, param);
        if (status != PJ_SUCCESS) {
            if (param->dir & PJMEDIA_DIR_PLAYBACK)
                TRACE_((THIS_FILE,"Close Play"));
            
            pj_pool_release (pool);
            return status;
        }
    }

    /* Apply the remaining settings */
    /* Below is an example if you want to set the output volume */
    if (param->flags & PJMEDIA_AUD_DEV_CAP_OUTPUT_VOLUME_SETTING) {
        esp32_stream_set_cap(&strm->base,
                        PJMEDIA_AUD_DEV_CAP_OUTPUT_VOLUME_SETTING,
                        &param->output_vol);
    }
		

    /* Done */
    *p_aud_strm = &strm->base;
    return PJ_SUCCESS;
}

/* API: Get stream  */
static pj_status_t esp32_stream_get_param(pjmedia_aud_stream *s,
					 pjmedia_aud_param *pi)
{
    struct esp32_audio_stream *strm = (struct esp32_audio_stream*)s;

    PJ_ASSERT_RETURN(strm && pi, PJ_EINVAL);

    pj_memcpy(pi, &strm->param, sizeof(*pi));

    /* Example: Update the volume setting */
    if (esp32_stream_get_cap(s, PJMEDIA_AUD_DEV_CAP_OUTPUT_VOLUME_SETTING,
			    &pi->output_vol) == PJ_SUCCESS)
    {
        pi->flags |= PJMEDIA_AUD_DEV_CAP_OUTPUT_VOLUME_SETTING;
    }

    return PJ_SUCCESS;
}

/* API: get capability */
static pj_status_t esp32_stream_get_cap(pjmedia_aud_stream *s,
				       pjmedia_aud_dev_cap cap,
				       void *pval)
{
    struct esp32_audio_stream *strm = (struct esp32_audio_stream*)s;

    PJ_ASSERT_RETURN(s && pval, PJ_EINVAL);

    /* Example: Get the output's volume setting */
    if (cap==PJMEDIA_AUD_DEV_CAP_OUTPUT_VOLUME_SETTING)
    {
        /* Output volume setting */
        *(unsigned*)pval = 0; // retrieve output device's volume here
        return PJ_SUCCESS;
    } 
    else if (cap==PJMEDIA_AUD_DEV_CAP_INPUT_LATENCY &&
	(strm->param.dir & PJMEDIA_DIR_CAPTURE))
    {
        /* Recording latency */
        *(unsigned*)pval = strm->param.input_latency_ms;
        return PJ_SUCCESS;
    } 
    else if (cap==PJMEDIA_AUD_DEV_CAP_OUTPUT_LATENCY &&
	       (strm->param.dir & PJMEDIA_DIR_PLAYBACK))
    {
        /* Playback latency */
        *(unsigned*)pval = strm->param.output_latency_ms;
        return PJ_SUCCESS;
    } 
    else 
    {
	    return PJMEDIA_EAUD_INVCAP;
    }
}

/* API: set capability */
static pj_status_t esp32_stream_set_cap(pjmedia_aud_stream *s,
				       pjmedia_aud_dev_cap cap,
				       const void *pval)
{
    struct esp32_audio_stream *strm = (struct esp32_audio_stream*)s;

    PJ_UNUSED_ARG(strm);

    PJ_ASSERT_RETURN(s && pval, PJ_EINVAL);

    /* Example */
    if (cap==PJMEDIA_AUD_DEV_CAP_OUTPUT_VOLUME_SETTING)
    {
        /* Output volume setting */
        // set output's volume level here
        return PJ_SUCCESS;
    }

    return PJMEDIA_EAUD_INVCAP;
}

/* API: Start stream. */
static pj_status_t esp32_stream_start(pjmedia_aud_stream *strm)
{
    struct esp32_audio_stream *stream = (struct esp32_audio_stream*)strm;
    pj_status_t status = PJ_SUCCESS;

    PJ_ASSERT_RETURN(strm, PJ_EINVAL);

    stream->quit = 0;

    if (stream->param.dir & PJMEDIA_DIR_PLAYBACK) {
        status = pj_thread_create (stream->pool,
                    "esp32_playback",
                    pb_thread_func,
                    stream,
                    8192, //ZERO,
                    0,
                    &stream->pb_thread);
        if (status != PJ_SUCCESS)
            return status;
    }

    if (stream->param.dir & PJMEDIA_DIR_CAPTURE) 
    {
        status = pj_thread_create (stream->pool,
                    "esp32_recback",
                    ca_thread_func,
                    stream,
                    8192, //ZERO,
                    0,
                    &stream->ca_thread);
        if (status != PJ_SUCCESS) {
            stream->quit = PJ_TRUE;
            pj_thread_join(stream->pb_thread);
            pj_thread_destroy(stream->pb_thread);
            stream->pb_thread = NULL;
        }
    }

    TRACE_((THIS_FILE, "Starting esp32 audio stream"));

    return PJ_SUCCESS;
}

/* API: Stop stream. */
static pj_status_t esp32_stream_stop(pjmedia_aud_stream *strm)
{
    struct esp32_audio_stream *stream = (struct esp32_audio_stream*)strm;
    stream->quit = 1;

    if (stream->pb_thread) {
        TRACE_((THIS_FILE,
            "alsa_stream_stop(esp32_playback): Waiting for playback to stop."));
        pj_thread_join (stream->pb_thread);

        TRACE_((THIS_FILE,
            "alsa_stream_stop(esp32_playback): playback stopped."));
        pj_thread_destroy(stream->pb_thread);
        stream->pb_thread = NULL;
    }

    if (stream->ca_thread) {
        TRACE_((THIS_FILE,
            "alsa_stream_stop(esp32_recback): Waiting for capture to stop."));
        pj_thread_join (stream->ca_thread);

        TRACE_((THIS_FILE,
            "alsa_stream_stop(esp32_recback): capture stopped."));
        pj_thread_destroy(stream->ca_thread);
        stream->ca_thread = NULL;
    }

    TRACE_((THIS_FILE, "Stopping esp32 audio stream"));

    return PJ_SUCCESS;
}


/* API: Destroy stream. */
static pj_status_t esp32_stream_destroy(pjmedia_aud_stream *strm)
{
    struct esp32_audio_stream *stream = (struct esp32_audio_stream*)strm;

    PJ_ASSERT_RETURN(stream != NULL, PJ_EINVAL);

    if (stream->param.dir & PJMEDIA_DIR_PLAYBACK) {
        /* 清除或者关闭音频流,其实只需要将音频接口的驱动停止即可 */
				
    }
    if (stream->param.dir & PJMEDIA_DIR_CAPTURE) {
        /* 清除或关闭录音驱动即可 */

    }
		
		// 停止语音流
		Audio_StreamStop();
		
    esp32_stream_stop(strm);

    pj_pool_release(stream->pool);

    return PJ_SUCCESS;
}

#endif	/* PJMEDIA_AUDIO_DEV_HAS_esp32_AUDIO */
