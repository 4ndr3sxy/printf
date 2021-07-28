#include "holberton.h"
#include <limits.h>

/**
 * convert_di - Converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * Extra: this one works with %d and %i.
 * @arg_list: A va_list list containing the arguments..
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_di(va_list arg_list, buffer_t *output)
{
	int tens = 1, num = va_arg(arg_list, int), tensit = num;
	unsigned int ret = 0;
	char neg = '-';
	char temp = '0';

	if (num == INT_MAX || num == INT_MIN)
	{
		ret = handle_limits(output, num);
		return (ret);
	}
	if (num < 0)
	{
		num *= -1;
		_copy(output, &neg, 1);
		tensit *= -1;
	}
	if (num == 0)
	{
		_copy(output, &temp, 1);
	}
	while (num != 0)
	{
		num = num / 10;
		tens *= 10;
	}
	tens /= 10;
	while (tens != 0)
	{
		temp = (tensit / tens) + '0';
		_copy(output, &temp, 1);
		tensit = tensit % tens;
		tens /= 10;
		ret++;
	}
	return (ret);
}

/**
 * handle_limits - Handles with the limits for convert_di.
 * @num: int to handle.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int handle_limits(buffer_t *output, int num)
{
	char *min = "2147483648", *max = "2147483647", neg = '-';

	if (num == INT_MAX)
	{
		_copy(output, max, 10);
		return (10);
	}
	else
	{
		_copy(output, &neg, 1);
		_copy(output, min, 10);
		return (11);
	}
}
