#include "main.h"

/********************** PRINT CHARACTER **********************/
/**
 * print_character - Prints a char
 * @modes: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_character(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(modes, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/********************** PRINT A STRING **********************/
/**
 * print_string - Prints a string
 * @modes: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, j;
	char *s = va_arg(modes, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & FLAG_MINUS)
		{
			write(1, &s[0], len);
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (width);
		}
	}
	return (write(1, s, len));
}
/********************** PRINT PERCENT SIGN **********************/
/**
 * print_percentage- Prints a percent sign
 * @modes: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percentage(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(modes);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/********************** PRINT INTEGERS **********************/
/**
 * print_integers - Print int
 * @modes: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_integers(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int negative = 0;
	long int m = va_arg(modes, long int);
	unsigned long int number;

	m = convert_size_number(m, size);
	if (m == 0)
		buffer[j--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)m;
	if (m < 0)
	{
		number = (unsigned long int)((-1) * m);
		negative = 1;
	}
	while (number > 0)
	{
		buffer[j--] = (number % 10) + '0';
		number /= 10;
	}
	j++;
	return (write_number(negative, j, buffer, flags, width, precision, size));
}
/********************** PRINT BINARY **********************/
/**
 * print_binary - Prints an unsigned number
 * @modes: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int i, j, m, add;
	unsigned int p[32];
	int number;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	i = va_arg(modes, unsigned int);
	j = 2147483648; /* (2 ^ 31) */
	p[0] = i / j;
	for (m = 1; m < 32; m++)
	{
		j /= 2;
		p[m] = (i / j) % 2;
	}
	for (m = 0, add = 0, number = 0; m < 32; m++)
	{
		add += p[m];
		if (add || m == 31)
		{
			char f = '0' + p[m];

			write(1, &f, 1);
			number++;
		}
	}
	return (number);
}
