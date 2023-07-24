#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @n: List of arguments to be printed.
 * @args: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *n, va_list args)
{
	int current_p = *n + 1;
	int precision = -1;

	if (format[current_p] != '.')
		return (precision);
	precision = 0;
	for (current_p += 1; format[current_p] != '\0'; current_p++)
	{
		if (is_digit(format[current_p]))
		{
			precision *= 10;
			precision += format[current_p] - '0';
		}
		else if (format[current_p] == '*')
		{
			current_p++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*n = current_p - 1;
	return (precision);
}
