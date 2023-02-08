/* $Id$ */
/* 
 * Copyright (C) 2008-2011 Teluu Inc. (http://www.teluu.com)
 * Copyright (C) 2003-2008 Benny Prijono <benny@prijono.org>
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
#include <pj/os.h>
#include <pj/compat/time.h>
#include <pj/errno.h>

#include <date_time.h>

///////////////////////////////////////////////////////////////////////////////

#if !defined(PJ_WIN32) || PJ_WIN32==0

PJ_DEF(pj_status_t) pj_time_decode(const pj_time_val *tv, pj_parsed_time *pt)
{
//    struct tm local_time;
		DateTime local_time;
	
    PJ_CHECK_STACK();

//#if defined(PJ_HAS_LOCALTIME_R) && PJ_HAS_LOCALTIME_R != 0
//    localtime_r((time_t*)&tv->sec, &local_time);
//#else
//    /* localtime() is NOT thread-safe. */
//    local_time = *localtime((time_t*)&tv->sec);
//#endif
		
		convertUnixTimeToDate((time_t)tv->sec , &local_time);
		
    pt->year = local_time.year+1900;
    pt->mon = local_time.month;
    pt->day = local_time.day;
    pt->hour = local_time.hours + 8;
    pt->min = local_time.minutes;
    pt->sec = local_time.seconds;
    pt->wday = local_time.dayOfWeek;
    pt->msec = tv->msec;

    return PJ_SUCCESS;
}

/**
 * Encode parsed time to time value.
 */
PJ_DEF(pj_status_t) pj_time_encode(const pj_parsed_time *pt, pj_time_val *tv)
{
//    struct tm local_time;
		DateTime local_time;
	
    local_time.year = pt->year-1900;
    local_time.month = pt->mon;
    local_time.day = pt->day;
    local_time.hours = pt->hour;
    local_time.minutes = pt->min;
    local_time.seconds = pt->sec;
//    local_time.tm_isdst = 0;
    
		tv->sec = convertDateToUnixTime(&local_time);
	
//    tv->sec = mktime(&local_time);
    tv->msec = pt->msec;

    return PJ_SUCCESS;
}

#endif /* !PJ_WIN32 */


static int get_tz_offset_secs()
{
//    time_t epoch_plus_11h = 60 * 60 * 11;
////    struct tm ltime, gtime;
//		DateTime ltime,gtime;
    int offset_min;

//#if defined(PJ_HAS_LOCALTIME_R) && PJ_HAS_LOCALTIME_R != 0
//    localtime_r(&epoch_plus_11h, &ltime);
//    gmtime_r(&epoch_plus_11h, &gtime);
//#else
//    ltime = *localtime(&epoch_plus_11h);
//    gtime = *gmtime(&epoch_plus_11h);
//#endif

//    offset_min = (ltime.tm_hour*60+ltime.tm_min) - (gtime.tm_hour*60+gtime.tm_min);
		offset_min = 8 * 60;
    return offset_min*60;
}

/**
 * Convert local time to GMT.
 */
PJ_DEF(pj_status_t) pj_time_local_to_gmt(pj_time_val *tv)
{
    tv->sec -= get_tz_offset_secs();
    return PJ_SUCCESS;
}

/**
 * Convert GMT to local time.
 */
PJ_DEF(pj_status_t) pj_time_gmt_to_local(pj_time_val *tv)
{
    tv->sec += get_tz_offset_secs();
    return PJ_SUCCESS;
}


