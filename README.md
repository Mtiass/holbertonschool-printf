<snippet>
  <content>

## Printf Introduction

Print formatted, shortened as printf is the main function used in printing
formatted output to a terminal in C language.The basic version of printf use
takes a string as an argument and print the exact text.

An elaborate use of the function takes an argument, then a list of
values separated by comma(s) to match their associated format specifiers in the
string.

All format specifiers are written as the percent (%) sign in front of a letter
(usually, data types). In our _printf function we defined the types %c, %s, %d
and %i. It's uses are;
%d / %i for signed decimal integer.
%c for single characters.
%s for printing string characters.


## Library/Header file "main.h"

It contains function declarations and a struct definition.

- The gc_t struct is defined to hold a character and a function pointer.
The characer is used to identify the type of data ('c' for char, 's' for
string, and 'd'/'i' for integers.
The function pointer points to the function that handles the type of data which
the chraracter points to.

- The prototypes of;

- _putchar function, which writes a character to the standard output.
- prchr, prstr, and prnum functions (prchr for printing a character, prstr to
print a string and prnum to print a number).
- printlonnu function which is used to print a number recursively (used by
prnum).
-  _getprintf function, that is used to match the character from the format
string with the struct array and call the corresponding function.
- _printf function,  which is the main function that takes a format string and
a variable number of arguments (va_list parameters).


## get\_printf.c 

- Implements _getprintf function.

This function iterates over an array of gc_t structs and if it finds a match
for the character from the format string in the struct array, it calls the
corresponding function and returns the result. If no match is found, returns 0.


## functions-printf.c

Implements the prchr, prstr, prnum, and printlonnu functions.

- prchr to print single characters.
- prstr to print a string.
- prnum to pint a number.
- printlonnu to help prnum to print a number recursively.

## \_printf.c 

Implements the main function _printf.

- The function starts by initializing a va_list(parameters) to handle the
variable number of arguments, starting off the required argument (const char
*format) followed by the optional ones.
Then, it iterates over the format string an if it encounters a '%' character,
it checks the next one to determine the type of data and calls the
corresponding function from the gc_t struct array. But if it encounters any
other character (while it's not NULL or other '%' char), it simply prints that
character.
- After processing all characters in the format string, it ends the variadic list
parameters and returns the total number of characters printed.

## \_putchar.c

It implements the _putchar function.

- This function writes a character to the standard output using the write
function (system call).

## Webpage we used to write this README.md

- https://gist.github.com/pedronauck/5573168

</content>
</snippet>
