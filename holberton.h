#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int _printf(const char *format, ...);

/**
 * struct buffer - struct to buffer.
 * @buffer: pointer to a buffer.
 * @start: point to start when print and tour.
 * @len: size of input printed.
 */
typedef struct buffer
{
	char *buffer;
	char *start;
	int len;
} buffer_t;

/**
 * struct converter - struct to get a function pointer a use.
 * @character: character of read (%c, %s, %d, %i, ...).
 * @func: function pointer a function a use
 */
typedef struct converter
{
	char character;
	unsigned int (*func)(va_list, buffer_t *);
} converter_t;

unsigned int convert_c(va_list ap, buffer_t *output);
unsigned int convert_s(va_list ap, buffer_t *output);

/**
 * convert_percent - when the next char a % is other %
 * @arg_list: List of arguments
 * @output: Struct type buffer_t to save char's
 * Return: count of char tours
 */
unsigned int convert_percent(__attribute__((unused)) va_list arg_list,
							 buffer_t *output);
unsigned int convert_di(va_list arg_list, buffer_t *output);
unsigned int handle_limits(buffer_t *output, int num);
unsigned int convert_b(va_list arg_list, buffer_t *output);
unsigned int convert_ubase(buffer_t *output, unsigned long int num,
						   char *base);
unsigned int convert_u(va_list arg_list, buffer_t *output);
unsigned int convert_o(va_list arg_list, buffer_t *output);
unsigned int convert_x(va_list arg_list, buffer_t *output);
unsigned int convert_X(va_list arg_list, buffer_t *output);
unsigned int convert_S(va_list arg_list, buffer_t *output);
unsigned int convert_p(va_list arg_list, buffer_t *output);
unsigned int convert_r(va_list arg_list, buffer_t *output);
unsigned int convert_R(va_list arg_list, buffer_t *output);

buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
unsigned int _copy(buffer_t *output, const char *src, int n);

unsigned int (*character_handler(const char *character))(va_list, buffer_t *);

#endif
