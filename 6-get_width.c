#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @n: List of arguments to be printed.
 * @args: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *n, va_list args)
{
	int current_p;
	int width = 0;

	for (current_p = *n + 1; format[current_p] != '\0'; current_p++)
	{
		if (is_digit(format[current_p]))
		{
			width *= 10;
			width += format[current_p] - '0';
		}
		else if (format[current_p] == '*')
		{
			current_p++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*n = current_p - 1;
	return (width);
}
