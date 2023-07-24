#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*n)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *n,
va_list args, char buffer[], int flags, int width, int precision, int size);

/****** FUNCTIONS ******/

/* Functions to print chars and strings */
int print_character(va_list modes, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list modes, char buffer[],
	int flags, int width, int precision, int size);
int print_percentage(va_list modes, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_integers(va_list modes, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list modes, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list modes, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list modes, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list modes, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadec_upper(va_list modes, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list modes, char associate[],
char buffer[], int flags, char flag_h, int width, int precision, int size);

/* Function to print non printed characters */
int print_non_printed(va_list modes, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list modes, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *n);
int get_width(const char *format, int *n, va_list args);
int get_precision(const char *format, int *n, va_list args);
int get_size(const char *format, int *n);

/* Function to print string in reverse */
int print_rev(va_list modes, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print a string in rot 13 */
int print_stringrot13(va_list modes, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int negative, int index, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width, int precision,
	int len, char add, char new_c);
int write_pointer(char buffer[], int index, int len,
	int width, int flags, char add, char new_c, int new_add);

int write_unsgnd(int negative, int index,
char buffer[],
	int flags, int width, int precision, int size);

/****** UTILS ******/
int is_printed(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int number, int size);

#endif /* MAIN_H */
