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
	char neg = '-', zero = '0', temp;
	char *max = "2147483647", *min = "2147483648";

	if (num < 0)
	{
		_copy(output, &neg, 1);
		if (num == INT_MIN)
		{
			_copy(output, min, 10);
			return (11);
		}
		num *= -1;
		tensit *= -1;
	}
	if (num == 0)
	{
		_copy(output, &zero, 1);
	}
	if (num == INT_MAX)
	{
		_copy(output, max, 10);
		return (10);
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
