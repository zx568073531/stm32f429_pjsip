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
#include <pj/file_access.h>
#include <pj/assert.h>
#include <pj/errno.h>

#include <sys/types.h>
#include "ff.h"
#include <unistd.h>
#include <stdio.h>	/* rename() */
#include <errno.h>
#include <date_time.h>

/*
 * pj_file_exists()
 */
PJ_DEF(pj_bool_t) pj_file_exists(const char *filename)
{
    FILINFO fno;

    PJ_ASSERT_RETURN(filename, 0);

    if (f_stat(filename, &fno) != FR_OK)
	return 0;

    return PJ_TRUE;
}


/*
 * pj_file_size()
 */
PJ_DEF(pj_off_t) pj_file_size(const char *filename)
{
    FILINFO fno;

    PJ_ASSERT_RETURN(filename, -1);

    if (f_stat(filename, &fno) != FR_OK)
	return -1;

    return fno.fsize;
}


/*
 * pj_file_delete()
 */
PJ_DEF(pj_status_t) pj_file_delete(const char *filename)
{
    PJ_ASSERT_RETURN(filename, PJ_EINVAL);

    if (f_unlink(filename)!=FR_OK) {
	return PJ_RETURN_OS_ERROR(errno);
    }
    return PJ_SUCCESS;
}


/*
 * pj_file_move()
 */
PJ_DEF(pj_status_t) pj_file_move( const char *oldname, const char *newname)
{
    PJ_ASSERT_RETURN(oldname && newname, PJ_EINVAL);

    if (f_rename(oldname, newname) != FR_OK) {
	return PJ_RETURN_OS_ERROR(errno);
    }
    return PJ_SUCCESS;
}


/*
 * pj_file_getstat()
 */
PJ_DEF(pj_status_t) pj_file_getstat(const char *filename, 
				    pj_file_stat *statbuf)
{
    FILINFO fno;

    PJ_ASSERT_RETURN(filename && statbuf, PJ_EINVAL);

    if (f_stat(filename, &fno) != 0) {
	return PJ_RETURN_OS_ERROR(errno);
    }
		DateTime time = {0};
		size_t longtime;
		time.year = (fno.fdate >> 9) + 1980;
		time.month = (fno.fdate >> 5) & 15;
		time.day = fno.fdate & 31;
		time.hours = fno.ftime >> 11;
		time.minutes = fno.ftime & 63;
		longtime = convertDateToUnixTime(&time);
		
    statbuf->size = fno.fsize;
    statbuf->ctime.sec = longtime;
    statbuf->ctime.msec = 0;
    statbuf->mtime.sec = longtime;
    statbuf->mtime.msec = 0;
    statbuf->atime.sec = longtime;
    statbuf->atime.msec = 0;

    return PJ_SUCCESS;
}

