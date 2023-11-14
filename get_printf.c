#include "main.h"
/**
 * _printf - 
 * @format:
 *
 * Description:
 * 
 * Return:
 */
int (*_getprintf(parameters, char *s))
{
	gc_t ch[] = {
		{"c", prch},
		{"s", prstr},
		{"d", prnum},
		{"i", prnum},
		{NULL, NULL}
	};
	int i = 0;
	while (ch[i].gc != NULL)
	{
		if(strcmp(ch[i].gc , s) == 0)
		{
			return ((ch[i].f)(parameters));
		}
		i++;
	}
	return (-1);
}
