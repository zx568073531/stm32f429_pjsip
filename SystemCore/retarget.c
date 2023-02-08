#include <stdio.h>
#include <rt_misc.h>
#include "systemLog.h"

//__asm(".global __use_no_semihosting_swi");

//struct __FILE
//{
//   int handle;
//};

//FILE __stdout;
//FILE __stdin;
//FILE __stderr;

//int fputc(int c, FILE *stream)
//{
//   return c;
//}

//int fgetc(FILE *stream)
//{
//   return EOF;
//}

//int ferror(FILE *stream)
//{
//   return EOF;
//}

//void _ttywrch(int c)
//{
//   fputc(c, stdout);
//}

//void _sys_exit(int code)
//{
//   while(1);
//}

void exit(int return_code)
{
	label:  goto label;  /* endless loop */
}

void __aeabi_assert(const char *expr, const char *file, int line)
{
	msg_log("Assert at file %s, expr %s, line %d", file, expr, line);
	exit(1);
}
