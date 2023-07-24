#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @index: index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *index, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int j, var_length = 0, output_chars = -1;
	fmt_t fmt_modes[] = {
		{'c', print_character}, {'s', print_string}, {'%', print_percentage},
		{'i', print_integers}, {'d', print_integers}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexadec_upper}, {'p', print_pointer}, {'S', print_non_printed},
		{'r', print_rev}, {'R', print_stringrot13}, {'\0', NULL}
	};
	for (j = 0; fmt_modes[j].fmt != '\0'; j++)
		if (fmt[*index] == fmt_modes[j].fmt)
			return (fmt_modes[j].fn(args, buffer, flags, width, precision, size));

	if (fmt_modes[j].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		var_length += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			var_length += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		var_length += write(1, &fmt[*index], 1);
		return (var_length);
	}
	return (output_chars);
}
