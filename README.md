# _printf
### Objective:
* In this proyect we will recreate some functions of the printf function included in the <stdio.h>
### Requirements:
* Files should be compiled with gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
* No more than 5 functions per file
* The prototypes of all your functions should be included in your header file called holberton.h
* No global variables allowed
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
## Functions included in this printf
| Type   | Output |
|--------|--------|
| d or i | Signed decimal integer |
| u      | Unsigned decimal integer	|
| b      | Unsigned binary |
| o      | Unsigned octal |
| x      | Unsigned hexadecimal integer (lowercase) |
| X      | Unsigned hexadecimal integer (uppercase) |
| r      | prints the reversed string |
| R      | prints the rot13'ed string |
| c      | Single character |
| s      | String of characters |
| S      | prints the string. Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
| p      | Pointer address |
| %      | A % followed by another % character will write a single % |

## holberton.h
* Header file. Includes prototypes, libraries and type structures.
## memory_handle.c
* Includes all the files to manage memory and buffer.
## character_handler.c
* Selects the appropiate function to use according to the character after the %.
## converters
* Includes all the functions to call from character_handler.
## _printf
* Includes the apropiate function to take the inputs, execute the program and return to the standart ouput.
### Authors
* Juan David Peña and Andres Felipe Castañeda
