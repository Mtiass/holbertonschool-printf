#include "main.h"
/**
 * _printf - hola
 * @format: hola
 *
 * Description: hola
 * 
 * Return: hola
 */
int _getprintf(va_list parameters, char s)
{
	int i = 0;
	
	gc_t ch[] = {
		{'c', prchr},
		{'s', prstr},
		{'d', prnum},
		{'i', prnum}
	};
	while (ch[i].gc != '\0')
	{
		if (ch[i].gc == s)
		{
			return ((ch[i].f)(parameters));
		}
		i++;
	}
	return (0);
}
