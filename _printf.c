#include "main.h"
/**
 * _printf - main function used to print formatted output to the terminal.
 * @format: is the required argument, used to intialize the va_list
 * (parameters).
 * Return: length of everything printed in output (length of format plus the
 * length of the variadic argument sent to the function. On error case -1.
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
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (format[i + 1] == 'c' ||
			format[i + 1] == 'i' || format[i + 1] == 's' ||
			format[i + 1] == 'd')
			{
				length += _getprintf(parameters, format[i + 1]);
				i++; }
			else if (format[i + 1] != '%')
			{
				_putchar(format[i]);
				length++; }
			else if (format[i + 1] == '%')
			{
				_putchar(format[i]);
				i++;
				length++; }
		}
		else
		{
			_putchar(format[i]);
			length++; }
	}
}
va_end(parameters);
return (length); }
else
	return (-1); }
