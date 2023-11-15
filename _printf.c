#include "main.h"
/**
 * _printf - hola
 * @format: hola
 *
 * Description: hola
 * 
 * Return: hola
 */
int _printf(const char *format, ...)
{
va_list parameters;
int i, length = 0, lenformat;

if (format != NULL)
{
lenformat = strlen(format);
va_start(parameters, format);
for (i = 0 ; i < lenformat ; i++)
{	
	if (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
		       if (format[i + 1] == 'c' || 
			format[i + 1] == 'i' || format[i + 1] == 's' ||
			format[i + 1] == 'd')
			{
			length += _getprintf(parameters, format[i + 1]);
			i++;
			}
			else if (format[i + 1] != '%')
			{
			       _putchar(format[i]);
				length++;
			}
		       else if (format [i + 1] == '%')
			{
		 		_putchar(format[i]);
		       		i++;
				length++;
			}
		}
		else if (format [i] == '%' && format[i + 1] == '\0')
		{
			return (-1);
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
else
return (-1);
}
