#include "holberton.h"

/**
 * cleaner - clear malloc of output
 * @arg_list: list with arguments
 * @output: Struct type buffer_t
 * Return: Without return.
 */
void cleaner(va_list arg_list, buffer_t *output)
{
	va_end(arg_list);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * execute_printf - tour the format to validad every char
 * @format: input
 * @arg_list: list arguments
 * @output: Struct type buffer_t
 * Return: count of char tours
 */
unsigned int execute_printf(const char *format,
							va_list arg_list, buffer_t *output)
{
	unsigned int i, ret = 0, k = 0;
	unsigned int (*f)(va_list, buffer_t *);
	char *characters;

	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			f = character_handler(format + i + 1);
			if (f != NULL)
			{
				i++;
				ret += f(arg_list, output);
				continue;
			}
			else if (*(format + i + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		else if (*(format + i) == '\\')
		{
			characters = "ntbfvr";
			while (characters[k])
			{
				if (characters[k] == *(format + i + 1))
					ret += _copy(output, 92 + (format + i + 1), 1);
			}
		}
		else
			ret += _copy(output, (format + i), 1);
	}
	cleaner(arg_list, output);
	return (ret);
}

/**
 * _printf - print input (format) with arguments (...)
 * @format: chain of character to print
 * Return: count of char tours
 */
unsigned int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list arg_list;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(arg_list, format);

	if (format == NULL || arg_list == NULL ||
		(format[0] == '%' && format[1] == '\0'))
		return (-1);

	ret = execute_printf(format, arg_list, output);

	return (ret);
}
