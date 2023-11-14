#ifndef _MAIN_H_
#define _MAIN_H_
#include <string.h>
#include <stdarg.h>
/**
 * struct gc - has two members, a pointer char(gc) and a pointer function
 * which takes parameters list as argument.
 * @gc: the char to be refered
 * @f: function pointer that takes a list(parameters) as variadic parameters.
 */
typedef struct gc
{
	const char *gc;
	int (*f)(va_list parameters);
} gc_t;	
int _printf(const char *format, ...);
int _putchar(char c);
int (*_getprintf)(va_list parameters, const char *s);
int prchr(va_list parameters);
int prstr(va_list parameters);
int prnum(va_list parameters);
void printlonnu(long int n);

#endif
