#include "main.h"
/**
 * prchr - function that prints a character.
 * @parameters: arguments to prchr.
 *
 * Return: an integer which is lenght of string.
 */
int prchr(va_list parameters)
{
	char c;

	c = va_arg(parameters, int);
	_putchar(c);
	return (1);
}
/**
 * prstr - function that iterates and prints a string
 * @parameters: argument/s to prstr.
 *
 * Return: strlen of string c.
 */
int prstr(va_list parameters)
{
	char *c;
	int i = 0;
	
	c = va_arg(parameters, char *);
	if (c != NULL)
	{
	for (; i < strlen(c); i++)
	{
		_putchar(c[i]);
	}
	return (strlen(c));
	}
	else 
	{
		_printf("(null)");
		return (6);
	}
}
/**
 * prnum - function that prints a digit/number.
 * @parameters: argument/s to prnum.
 *
 * Return: an integer (length of n(number)).
 */
int prnum(va_list parameters)
{
	int c = 0;
	long int n = va_arg(parameters, int);
	long int n2 = n;

	if (n == 0)
	{
		_putchar('0');
		c++;
		return (c);
	}
	if (n < 0)
	{
		_putchar('-');
		n = -n;
		c++;
	}
	while (n2 != 0)
	{
		n2 = n2 / 10;
		c++;
	}
	printlonnu(n);
	return (c);
}
/**
 * printlonnu - function that recurses over a number and prints the last part of each
 * saved part saved.
 * @n: long int number to be divided and printed out.
 * Return: nothing.
 */  
void printlonnu(long int n)
{
	if (n / 10)
		printlonnu(n / 10);

	_putchar(n % 10 + '0');
}
