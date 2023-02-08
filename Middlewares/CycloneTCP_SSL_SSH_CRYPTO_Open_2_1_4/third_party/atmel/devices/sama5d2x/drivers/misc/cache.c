/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2016, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/** \file */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "chip.h"

#include "misc/cache.h"

#include "peripherals/l2cc.h"

#include <assert.h>

/*----------------------------------------------------------------------------
 *        Functions
 *----------------------------------------------------------------------------*/

void cache_invalidate_region(void *start, uint32_t length)
{
	uint32_t start_addr = (uint32_t)start;
	uint32_t end_addr = start_addr + length;

	if (cp15_dcache_is_enabled()) {
		cp15_dcache_invalidate_region(start_addr, end_addr);
#ifdef CONFIG_HAVE_L2CC
		if (l2cc_is_enabled())
			l2cc_invalidate_region(start_addr, end_addr);
#endif
	}
}

void cache_clean_region(const void *start, uint32_t length)
{
	uint32_t start_addr = (uint32_t)start;
	uint32_t end_addr = start_addr + length;

	if (cp15_dcache_is_enabled()) {
		cp15_dcache_clean_region(start_addr, end_addr);
#ifdef CONFIG_HAVE_L2CC
		if (l2cc_is_enabled())
			l2cc_clean_region(start_addr, end_addr);
#endif
	}
}
