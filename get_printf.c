#include "main.h"
/**
 * _printf - hola
 * @format: hola
 *
 * Description: hola
 * 
 * Return: hola
 */
int _getprintf(va_list parameters, const char *s)
{
	int i = 0;
	
	gc_t ch[] = {
		{"c", prchr},
		{"s", prstr},
		{"d", prnum},
		{"i", prnum},
		{NULL, NULL}
	};
	while (ch[i].gc != NULL)
	{
		if(strcmp(ch[i].gc , s) == 0)
		{
			return ((ch[i].f)(parameters));
		}
		i++;
	}
	return (0);
}
