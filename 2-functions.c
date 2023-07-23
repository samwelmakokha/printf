#include "main.h"
/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @modes: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	char new_c = 0, add = ' ';
	int index = BUFF_SIZE - 2, len = 2, new_add = 1; /* len=2, for '0x' */
	unsigned long num_address;
	char associate[] = "0123456789abcdef";
	void *address = va_arg(modes, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_address = (unsigned long)addrs;
	while (num_address > 0)
	{
		buffer[index--] = associate[num_address % 16];
		num_address /= 16;
		leng++;
	}
	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		add = '0';
	if (flags & FLAG_PLUS)
		new_c = '+', leng++;
	else if (flags & FLAG_SPACE)
		new_c = ' ', len++;
	index++;
	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, index, len,
		width, flags, add, new_c, new_add));
}
/************************* PRINT NON PRINTED *************************/
/**
 * print_non_printed - Prints ascii codes in hexa of non printable chars
 * @modes: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printed(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, shift = 0;
	char *s = va_arg(modes, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[j] != '\0')
	{
		if (is_printed(s[j]))
			buffer[j + shift] = s[j];
		else
			shift += append_hexa_code(s[j], buffer, j + shift);
		j++;
	}
	buffer[j + shift] = '\0';
	return (write(1, buffer, j + shift));
}
/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @modes: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	char *s;
	int j, number = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	s = va_arg(modes, char *);

	if (s == NULL)
	{
		UNUSED(precision);
		s = ")Null(";
	}
	for (j = 0; s[j]; j++)
		;
	for (j = j - 1; j >= 0; j--)
	{
		char p = s[j];

		write(1, &p, 1);
		number++;
	}
	return (number);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_stringrot13 - Print a string in rot13.
 * @modes: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_stringrot13(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	char k;
	char *s;
	unsigned int a, b;
	int number = 0;
	char start[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char end[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(modes, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (a = 0; s[a]; a++)
	{
		for (b = 0; start[b]; b++)
		{
			if (start[b] == s[a])
			{
				k = end[b];
				write(1, &k, 1);
				number++;
				break;
			}
		}
		if (!start[b])
		{
			k = s[a];
			write(1, &k, 1);
			number++;
		}
	}
	return (number);
}
