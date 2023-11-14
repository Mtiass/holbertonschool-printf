#ifndef _MAIN_H_
#define _MAIN_H_
#include <string.h>
#include <stdarg.h>
/**
 * struct gc - 
 * @gc: the char to be refered
 * @f: function pointer that takes a list(parameters) as variadic parameters.
 */
typedef struct gc
{
	char *gc;
	int (*f)(va_list parameters);
} gc_t;	
int _printf(const char *format, ...);
int _putchar(char c);

#endif
