#include "main.h"
/************************* HANDLE  WRITE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and adding at buffer's right */
	int j = 0;
	char add = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FLAG_ZERO)
		add = '0';
	buffer[j++] = c;
	buffer[j] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buffer[BUFF_SIZE - i - 2] = add;
		if (flags & FLAG_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - j - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - j - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @negative: List of arguments
 * @index: char modes.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1;
	char add = ' ', new_ch = 0;

	UNUSED(size);

	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		add = '0';
	if (negative)
		new_ch = '-';
	else if (flags & FLAG_PLUS)
		new_ch = '+';
	else if (flags & FLAG_SPACE)
		new_ch = ' ';
	return (write_num(index, buffer, flags, width, precision,
		len, add, new_ch));
}
/**
 * write_num - Write a number using a bufffer
 * @index: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @len: Number of length
 * @add: adding char
 * @new_c: New character
 *
 * Return: Number of printed chars.
 */
int write_num(int index, char buffer[],
	int flags, int width, int precision,
	int len, char add, char new_c)
{
	int j, new_add = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 &&
			buffer[index] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = add = ' '; /* width is displayed with adding ' ' */
	if (precision > 0 && precision < len)
		add = ' ';
	while (precision > len)
		buffer[--index] = '0', leng++;
	if (new_c != 0)
		len++;
	if (width > len)
	{
		for (j = 1; j < width - len + 1; j++)
			buffer[j] = add;
		buffer[j] = '\0';
		if (flags & FLAG_MINUS && add == ' ')/* Asign new char to left of buffer */
		{
			if (new_c)
				buffer[--index] = new_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], j - 1));
		} else if (!(flags & FLAG_MINUS) && add == ' ')/* new char to left of buff */
		{
			if (new_c)
			buffer[--index] = new_c;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[index], len));
		} else if (!(flags & FLAG_MINUS) && add == '0')/* new char to left of add */
		{
			if (new_c)
				buffer[--new_add] = new_c;
			return (write(1, &buffer[new_add], j - new_add) +
				write(1, &buffer[index], len - (1 - new_add)));
		}
		if (new_c)
			buffer[--index] = new_c;
	}
	return (write(1, &buffer[index], len));
}
/**
 * write_unsgnd - Writes an unsigned number
 * @negative: Number indicating if the num is negative
 * @index: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int negative, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position i */
	int len = BUFF_SIZE - index - 1, j = 0;
	char add = ' ';

	UNUSED(negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */
	if (precision > 0 && precision < len)
		add = ' ';
	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}
	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		add = '0';
	if (width > len)
	{
		for (j = 0; j < width - len; j++)
			buffer[j] = add;
		buffer[j] = '\0';
		if (flags & FLAG_MINUS) /* Assign new char to left of buffer [buffer>add]*/
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], j));
		}
		else /* Assign new char to left of adding [add>buffer]*/
		{
			return (write(1, &buffer[0], j) + write(1, &buffer[index], len));
		}
	}
	return (write(1, &buffer[index], len));
}
/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @len: Length of number
 * @width: width specifier
 * @flags: Flags specifier
 * @add: Char representing the adding
 * @new_c: Char representing extra char
 * @new_add: Index at which adding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int index, int len,
	int width, int flags, char add, char new_c, int new_add)
{
	int j;

	if (width > len)
	{
		for (j = 3; j < width - len + 3; j++)
			buffer[j] = add;
		buffer[j] = '\0';
		if (flags & FLAG_MINUS && add == ' ')/* Assign new char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (new_c)
				buffer[--index] = new_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], j - 3));
		}
		else if (!(flags & FLAG_MINUS) && add == ' ')/* new char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (new_c)
				buffer[--index] = new_c;
			return (write(1, &buffer[3], j - 3) + write(1, &buffer[index], len));
		}
		else if (!(flags & FLAG_MINUS) && add == '0')/* new char to left of add */
		{
			if (new_c)
				buffer[--new_add] = new_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[new_add], j - new_add) +
				write(1, &buffer[index], len - (1 - new_add) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (new_c)
		buffer[--index] = new_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
