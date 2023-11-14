#include "main.h"
/**
 * _printf - 
 * @format:
 *
 * Description:
 * 
 * Return:
 */
int (*_getprintf(char *s))(void *ptr)
{
	gc_t ch[] = {
		{"c", prch},
		{"s", prstr},
		{"%", prpor},
		{"d", prnum},
		{"i", prnum},
		{NULL, NULL}
	};
	int i = 0;
	while (ch[i].gc != NULL)
	{
		if(strcmp(ch[i].gc , s) == 0)
		{
			return (ch[i].f);
		}
		i++;
	}
	return (-1);
}
