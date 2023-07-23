#include "main.h"

/********* PRINT UNSIGNED NUMBER *********/
/**
 * print_unsigned - Prints an unsigned number
 * @modes: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int number = va_arg(modes, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[j--] = (number % 10) + '0';
		number /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/***** PRINT UNSIGNED NUMBER IN OCTAL  ******/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @modes: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int number = va_arg(modes, unsigned long int);
	unsigned long int initial_num = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[j--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & FLAG_HASH && initial_num != 0)
		buffer[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/***** PRINT UNSIGNED NUMBER IN HEXADECIMAL *****/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @modes: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(modes, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/***** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ******/
/**
 * print_hexadec_upper - Prints an unsgnd number in upper hexadecimal notation
 * @modes: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadec_upper(va_list modes, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(modes, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/***** PRINT HEXX NUM IN LOWER OR UPPER *****/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @modes: List of arguments
 * @associate: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_h: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list modes, char associate[], char buffer[],
	int flags, char flag_h, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int number = va_arg(modes, unsigned long int);
	unsigned long int initial_num = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[j--] = associate[number % 16];
		number /= 16;
	}

	if (flags & FLAG_HASH && initial_num != 0)
	{
		buffer[j--] = flag_h;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
