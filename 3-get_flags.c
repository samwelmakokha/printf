#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @n: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *n)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, current_p;
	int flag = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};

	for (current_p = *n + 1; format[current_p] != '\0'; current_p++)
	{
		for (a = 0; FLAGS_CHAR[a] != '\0'; a++)
			if (format[current_p] == FLAGS_CHAR[a])
			{
				flag |= FLAGS_ARRAY[a];
				break;
			}

		if (FLAGS_CHAR[a] == 0)
			break;
	}

	*n = current_p - 1;

	return (flag);
}
