# [Printf project](https://github.com/Mtiass/holbertonschool-printf/tree/master) 

### Introduction

"Print formatted", shortened as "printf" is the main function used for printing\
formatted output to a terminal in C language. The basic version of printf\
takes a string as an argument and prints the exact text.

An elaborate use of the function takes an argument and also a list of values\
separated by comma(s) to match their associated format specifiers in the string.

All format specifiers, also known as placeholders, use the character percent **(%)** \
followed by another character indicating the data type of the value represented\
In our _printf function we defined the types **'%c'**, **'%s'**, **'%d'**\
and **'%i'**. It's uses are;

| Types   | Description 		      |
| ------- | ----------- 		      |
| %d / %i | for signed and unsigned integers  |
|  %c     | for single characters             |
|  %s     | to print string character         |


## [Library/Header file "main.h"](https://github.com/Mtiass/holbertonschool-printf/blob/master/main.h)

It contains function declarations (It's prototypes) and a struct definition.

- The **gc_t** struct is defined to hold a character and a function pointer.\
The characer is used to identify the type of data (**'c'** for char,\
**'s'** for string, and **'d'/'i'** for integers).\
The function pointer points to the function that handles the type of\
data which the chraracter points to.
```
typedef struct gc
{
	char gc;
	int (*f)(va_list parameters);
} gc_t;
```
| Function name  | Prototype  | Short description |
| :------------: |:---------------| :-----|
| *_putchar* | int _putchar(char c);| Writes a character to the standard output. |
| *prchr*    | int prchr(va_list parameters); | Prints a character. |
| *prstr* | int prstr(va_list parameters);  | Prints a string. |
| *prnum* | int prnum(va_list parameters);  | Prints a number. |
| *printlonnu* | void printlonnu(long int n); | Function used to print a number recursively as a helper for *prnum*. |
| *_getprintf* | int _getprintf(va_list parameters, char s);  | Function used to iterate over the array struct(*gc_t ch[]*) to compare the format spec. from *format* with a member of *gc_t ch[]*. |
| *_printf* | int _printf(const char *format, ...);  | Function that takes a *format* string and a variable number of arguments to print formatted output. |


## [get\_printf.c](https://github.com/Mtiass/holbertonschool-printf/blob/master/get_printf.c) 

Implements **_getprintf** function.

The function *_getprintf* recieves a variadic list (**va_list parameters**)\
and a format specifier **char s**, obtained from the *format* string.

An array named (*ch[]*) of **gc\_t** structures (defined in *main.h*)\
is initialized, where each **gc\_t** structure contains a character\
(**gc** that is the format specifier), and a function pointer (***f**),\
which points to the function that matches the corresponding format specifier.

- This function iterates over an array of **gc_t**(ch[]) structs and if it finds\
a match for the character, from the format string in the struct array, it calls\
the corresponding function and returns the result. If no match is found, returns 0.

## [functions-printf.c](https://github.com/Mtiass/holbertonschool-printf/blob/master/functions-printf.c)

Implements the *prchr*, *prstr*, *prnum*, and *printlonnu* functions, the first three\
are called by the corresponding format specifier defined in the array of structs\
**gc_t** from *_getprintf* function. 

- *prchr* to print single characters refered by the format specifier **c**.\
  And returns it's length (always 1).

- *prstr* to print a string pointed by the format specifier **s**.\
  It iterates over the char pointer (char *s) argument passed by\
  (*va_list parameters*) and prints every character of the string\
  pointed with a for loop that iterates over **s** length.\
  Returns the length of s (*return (strlen(s));*).\
  If **s** is equal to NULL it prints "(null)" and returns it's length (6).
  
- *prnum* to print a number refered by **d/i** format specifiers.\
  If n is 0, it prints it and increments **c** by 1 and returns it.\
  If it is a negative number it prints a **'-'** character and turns **n** to\
  positive by multiplying it's sing by '-' and increments **c** by 1.\
  Then the function iterates through **n2**, which is a copy of **n**,\
  and each iteration checks if **n** is different than 0, if it is,\
  it is divided by 10 and increments **c** in 1.\
  After the iteration is over, *printlonnu* is called to print the reminder of\
  (**n** % 10) in each recursion of (**n** / 10), when this function is over,\
  **c** (number of characters printed) is returned to the function _printf\
  to add it to the total length (**length**) count of the output.
  
- *printlonnu* to help *prnum* to print a number recursively. Is a\
function that takes and prints the rest of **n** divided by ten\
*(n % 10)* in each recursion of *(n / 10)*.

## [\_printf.c](https://github.com/Mtiass/holbertonschool-printf/blob/master/_printf.c) 

Implements the main function *_printf*.

1. The function starts by initializing a **va_list(parameters)** to handle\
the variable number of arguments, starting off the required argument\
(const char *format). It also initializes 3 integer variables;\
**i** as the index, **lenformat** (to make the size of *format* an integer),\
and **length** (to count and return the length of formatted output).

2. Then the code checks if the format string is not **NULL**;

- If it is **NULL**, the function returns -1.
 
- If it is not **NULL**, the *va_start* macro initializes the *parameters* list.\
And assigns length of *format* to the int variable **lenformat**.

3. Then the code enters a for loop that iterates **i** over each character\
in the *format* string conditioning **i** to be less than **lenformat**'s size.

4. If the current character is not the end of the string.\
It checks for several conditions:

- If the current character is a **%** and the next character is **'\0'**,\
it returns -1.

- If the current character is a **%** and the next character is not **'\0'**.\
It checks the next character to see if it is **'c'**, **'s'**, **'d'** or **'i'**.\
If it is, it calls the *_getprintf* function to compare the next character\
with each member of the *ch* structure array until both are the same, to call\
the function pointed by the coincident *ch* structure array member.\
Finally, the total **length** increases with the value return of the\
corresponding function and **i** increases in 1. If there are no coincidences,\
*_getprintf* returns 0.

- If the next character isn't  **'c'**, **'s'**, **'d'**,**'i'** or **%**,\
it calls the *_putchar* function to print the current character, and increases\
**length** in 1.

- If the next character is **%**, it prints the current character,\
increases **i** in 1, and **length** in 1, too.

- If the current character is not **%**, it calls the *_putchar* function\
to print the actual character and increase **length** in 1.

5. After the *for* loop finishes, the *va\_end* macro is called to clean up\
the **parameters** list, and finally, the function returns the total\
**length** (of the printed output).

## [\_putchar.c](https://github.com/Mtiass/holbertonschool-printf/blob/master/_putchar.c)

It implements the _putchar function.

- This function writes a character to the standard output using the write\
function (system call).

## Code example
```
root@74be033d1686:/holbertonschool-printf# cat main.c
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
        int len;

        /* A simple string without format specifiers */
        len = _printf("This is Sparta\n");
        /* A string and an 's' format specifier */
         _printf("String:[%s]\n", "I am a string !");
        /* A string with a 'c' format specifier */
         _printf("Character:[%c]\n", 'H');
        /* A string with a 'd' format specifier pointing to a negative number */
         _printf("Negative:[%d]\n", -762534);
        /* A string with an 'i' format s. */
         _printf("Len:[%i]\n", len);
        /* What if are there two '%' together? */
         _printf("Percent:[%%]\n");
         return (0);
}
root@74be033d1686:/holbertonschool-printf# gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c -o test
root@74be033d1686:/holbertonschool-printf# ./test
This is Sparta
String:[I am a string !]
Character:[H]
Negative:[-762534]
Len:[15]
Percent:[%]
```
## [Clic here to see how we decorated our README.md](https://www.markdownguide.org/basic-syntax/)

![Chart](https://i.postimg.cc/Xq34w9KS/aa2.png)
