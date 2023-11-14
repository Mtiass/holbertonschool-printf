#include "main.h"
/**
 * _printf - 
 * @format:
 *
 * Description:
 * 
 * Return:
 */
int _printf(const char *format, ...)
{
va_list parameters;
int i, length = 0;
char c;

va_start(parameters, format);
for (i = 0 ; i < strlen(format) ; i++)
{	
	if (format[i] != '\0')
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || 
		format[i + 1] == 'i'	|| format[i + 1] == 's' ||
		format[i + 1] == 'd'))
			{	
			length += _getprintf(parameters, &format[i + 1]);
			i++;
			}
		else
			{
			_putchar(format[i]);
			length++;
			}
	}
}
va_end(parameters);
return (length);
}
