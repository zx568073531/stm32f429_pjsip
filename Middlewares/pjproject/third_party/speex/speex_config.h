#pragma once
#include <pj/types.h>

/* Check if we need to use the fixed point version */
#if !defined(PJ_HAS_FLOATING_POINT) || PJ_HAS_FLOATING_POINT==0
#   define FIXED_POINT
#   define USE_KISS_FFT
#else 
#   define FLOATING_POINT
//#   define USE_SMALLFT
#   define USE_KISS_FFT
#endif

#define EXPORT

#if (defined(PJ_WIN32) && PJ_WIN32!=0) || \
    (defined(PJ_WIN64) && PJ_WIN64!=0) || \
    (defined(PJ_WIN32_WINCE) && PJ_WIN32_WINCE != 0) 
#   include "../../speex/win32/config.h"
#else
#define inline __inline
#define restrict
#endif

#ifdef _MSC_VER
#   pragma warning(disable: 4100)   // unreferenced formal parameter
#   pragma warning(disable: 4101)   // unreferenced local variable
#   pragma warning(disable: 4244)   // conversion from 'double ' to 'float '
#   pragma warning(disable: 4305)   // truncation from 'const double ' to 'float '
#   pragma warning(disable: 4018)   // signed/unsigned mismatch
#   pragma warning(disable: 4456)   // declaration of '[var]' hides previous local declaration
#   pragma warning(disable: 4267)   // conversion from 'size_t' to 'int', possible loss of data
#   pragma warning(disable: 4706)   // assignment within conditional expression
//#   pragma warning(disable: 4701)   // local variable used without initialized
#endif

#if defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__) >= 402
#  pragma GCC diagnostic ignored "-Wpragmas"
#  pragma GCC diagnostic ignored "-Wunknown-warning-option"
#  pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#include <pj/log.h>

/*
 * Override miscellaneous Speex functions.
 */
#define OVERRIDE_SPEEX_ERROR
#define speex_error(str) PJ_LOG(4,("speex", "error: %s", str))

#define OVERRIDE_SPEEX_WARNING
#define speex_warning(str) PJ_LOG(5,("speex", "warning: %s", str))

#define OVERRIDE_SPEEX_WARNING_INT
#define speex_warning_int(str,val)  PJ_LOG(5,("speex", "warning: %s: %d", str, val))

/** Speex wrapper for calloc. To do your own dynamic allocation, all you need to do is replace this function, speex_realloc and speex_free
    NOTE: speex_alloc needs to CLEAR THE MEMORY */
#define  OVERRIDE_SPEEX_ALLOC
static inline void *speex_alloc (int size)
{
   /* WARNING: this is not equivalent to malloc(). If you want to use malloc()
      or your own allocator, YOU NEED TO CLEAR THE MEMORY ALLOCATED. Otherwise
      you will experience strange bugs */
	void * p = pvPortMalloc(size);
	
	if(p)
		memset(p , 0 , size);
   
	return p;
}


/** Same as speex_alloc, except that the area is only needed inside a Speex call (might cause problem with wideband though) */
#define OVERRIDE_SPEEX_ALLOC_SCRATCH
static inline void *speex_alloc_scratch (int size)
{
   /* Scratch space doesn't need to be cleared */
	return pvPortMalloc(size);
}


/** Speex wrapper for realloc. To do your own dynamic allocation, all you need to do is replace this function, speex_alloc and speex_free */
#define OVERRIDE_SPEEX_REALLOC
static inline void *speex_realloc (void *ptr, int size)
{
	 vPortFree(ptr);
	 if(size != 0)
		return pvPortMalloc(size);
   else
		return NULL;
}


/** Speex wrapper for calloc. To do your own dynamic allocation, all you need to do is replace this function, speex_realloc and speex_alloc */
#define OVERRIDE_SPEEX_FREE
static inline void speex_free (void *ptr)
{
   vPortFree(ptr);
}


/** Same as speex_free, except that the area is only needed inside a Speex call (might cause problem with wideband though) */
#define OVERRIDE_SPEEX_FREE_SCRATCH
static inline void speex_free_scratch (void *ptr)
{
   vPortFree(ptr);
}

