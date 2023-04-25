#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign		: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} prams_t;

/**
 * struct specifiers - Struct token
 *
 * @specifiers: format token
 * @fun: The function associated
 */
typedef struct specifiers
{
	char *specifiers;
	int (*fun)(va_list, prams_t *);
} specifiers_t;

/* _puts.c module */
int _puts(char *st);
int _putchar(int c);

/* print_fun.c module */
int print_char(va_list list, prams_t *prams);
int print_int(va_list list, prams_t *prams);
int print_string(va_list list, prams_t *prams);
int print_percent(va_list list, prams_t *prams);
int print_S(va_list list, prams_t *prams);

/* no.c module */
char *convert(long int num, int base, int flags, prams_t *prams);
int print_unsigned(va_list list, prams_t *prams);
int print_address(va_list list, prams_t *prams);

/* specifier.c module */
int (*get_specifier(char *s))(va_list list, prams_t *prams);
int get_print_func(char *s, va_list list, prams_t *prams);
int get_flag(char *s, prams_t *prams);
int get_modifier(char *s, prams_t *prams);
char *get_width(char *s, prams_t *prams, va_list list);

/* convert_no.c module */
int print_hex(va_list list, prams_t *prams);
int print_HEX(va_list list, prams_t *prams);
int print_binary(va_list list, prams_t *prams);
int print_octal(va_list list, prams_t *prams);

/* _printers.c module */
int print_from_to(char *go, char *end, char *not);
int print_rev(va_list list, prams_t *prams);
int print_rot13(va_list list, prams_t *prams);

/* print_no.c module */
int _isdigit(int ch);
int _strlen(char *str);
int print_number(char *str, prams_t *prams);
int print_number_right_shift(char *str, prams_t *prams);
int print_number_left_shift(char *str, prams_t *prams);

/* prams.c module */
void init_params(prams_t *prams, va_list list);

/* str_fields.c modoule */
char *get_precision(char *p, prams_t *prams, va_list list);

/* _prinf.c module */
int _printf(const char *form, ...);

#endif
