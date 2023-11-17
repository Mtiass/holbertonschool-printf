# [Printf project](https://github.com/Mtiass/holbertonschool-printf/tree/master) 

### Introduction

Print formatted, shortened as printf is the main function used in printing\
formatted output to a terminal in C language. The basic version of printf use\
takes a string as an argument and print the exact text.

An elaborate use of the function takes an argument, then a list of values\
separated by comma(s) to match their associated format specifiers in the
string.

All format specifiers are written as the percent (%) sign in front of a letter\
(usually, data types). In our _printf function we defined the types **'%c'**, **'%s'**, **'%d'**\
and **'%i'**. It's uses are;

| Types   | Description |
| ----------- | ----------- |
| %d / %i |for signed decimal integer|
|  %c     | for single characters|
|  %s     | to print string character|


## [Library/Header file "main.h"](https://github.com/Mtiass/holbertonschool-printf/blob/master/main.h)

It contains function declarations and a struct definition.

- The **gc_t** struct is defined to hold a character and a function pointer.\
The characer is used to identify the type of data (**'c'** for char, **'s'** for\
string, and **'d'/'i'** for integers).\
The function pointer points to the function that handles the type of data which\
the chraracter points to.

- The prototypes of;

- *_putchar* function, which writes a character to the standard output.
- *prchr*, *prstr*, and *prnum* functions (prchr for printing a character, prstr to\
print a string and prnum to print a number).
- *printlonnu* function which is used to print a number recursively (used by\
prnum as a helper).
-  *_getprintf* function, that is used to match the character from the format\
string with the struct array and call the corresponding function.
- *_printf* function,  which is the main function that takes a format string and\
a variable number of arguments (*va_list parameters*).

## [get\_printf.c](https://github.com/Mtiass/holbertonschool-printf/blob/master/get_printf.c) 

Implements **_getprintf** function.

The function *_getprintf* is declared with a variadic list (**va_list parameters**)\
and the format specifier **char s**, obtained from the format string, as
parameters.

An array of gc\_t structures (defined in main.h) is initialized where each\
gc\_t structure contains a character (gc is the format specifier),\
and a function pointer (f, which points to the function that matches the\
corresponding format specifier).

- This function iterates over an array of **gc_t** structs and if it finds a match\
for the character from the format string in the struct array, it calls the\
corresponding function and returns the result. If no match is found, returns 0.


## [functions-printf.c](https://github.com/Mtiass/holbertonschool-printf/blob/master/functions-printf.c)

Implements the prchr, prstr, prnum, and printlonnu functions, the first three\
are called by the corresponding format specifier defined in the array of structs\
**gc_t** from *_getprintf* function. *printlonnu* is a helper function to print\
character by character taking and printing the rest of **n** divided by ten *(n % 10)*\
in each recursion of *(n / 10)*.

- *prchr* to print single characters refered by the format specifier **c**.
- *prstr* to print a string pointed by the format specifier **s**.
- *prnum* to pint a number refered by **d/i** format specifiers.
- *printlonnu* to help *prnum* to print a number recursively.

## [\_printf.c](https://github.com/Mtiass/holbertonschool-printf/blob/master/_printf.c) 

Implements the main function _printf.

- The function starts by initializing a **va_list(parameters)** to handle the\
variable number of arguments, starting off the required argument (const char\
*format) followed by the optional ones.

- The code checks if the format string is not **NULL**. If it is **NULL**,\
the function returns -1.
 
- If it is not **NULL**, the *va_start* macro initializes the parameters list.\
Then the code enters a loop that iterates over each character in the format string.\
If the current character is not the end of the string, it checks for several
conditions:

- If the character is a **%** and the next character is also **%**, it returns -1.

- If the character is a **%** and the next character is not **%**, it checks the\
next character to see if it's **'c'**, **'s'**, **'d'** or **'i'**. If it is, it calls\
the *_getprintf* function and increments the length with the value return of the,\
corresponding function.

-  If the next character is not **%**, it calls the *_putchar* function to print\
the character and increments the length.

- If the next character is **%**, it calls the _putchar function to print the\
character, increments the length, and moves to the next character.

- If the character is not **%**, it calls the _putchar function to print the\
character and increments the length.

After the loop, the *va\_end* macro is called to clean up the **parameters** list,\
and finally, the function returns the *length* of the printed string.

## [\_putchar.c](https://github.com/Mtiass/holbertonschool-printf/blob/master/_putchar.c)

It implements the _putchar function.

- This function writes a character to the standard output using the write\
function (system call).

## [How we decorated our README.md](https://www.markdownguide.org/extended-syntax/#heading-ids)
