#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @n: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *n)
{
	int current_p = *n + 1;
	int size = 0;

	if (format[current_p] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*n = current_p - 1;
	else
		*n = current_p;

	return (size);
}
