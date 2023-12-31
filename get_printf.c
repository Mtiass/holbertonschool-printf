#include "main.h"
/**
 * _getprintf - function name.
 *
 * Description: function that iterates over an struct array that compares the
 * char s from format in _printf with each member of struct ch
 * and if s == any member of the array struct it returns the value
 * obtained of the function refered by the matching member.
 *
 * @parameters: variadic list obtained from _printf which is sent to
 * the corresponding function.
 * @s: char obtained from format string.
 *
 * Return: 0 if there are no coincidences, otherwise value obtained by matching
 * the function.
 */
int _getprintf(va_list parameters, char s)
{
	int i = 0;

	gc_t ch[] = {
		{'c', prchr},
		{'s', prstr},
		{'d', prnum},
		{'i', prnum},
		{'\0', NULL}
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
