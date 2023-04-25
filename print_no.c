#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @ch: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int x = 0;

	while (*str++)
		x++;
	return (x);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @prams: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, prams_t *prams)
{
	unsigned int x = _strlen(str);
	int neg = (!prams->unsign && *str == '-');


	if (!prams->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		x--;
	}
	if (prams->precision != UINT_MAX)
		while (x++ < prams->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!prams->minus_flag)
		return (print_number_right_shift(str, prams));
	else
		return (print_number_left_shift(str, prams));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @prams: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, prams_t *prams)
{
	unsigned int n = 0, neg, neg2, x = _strlen(str);
	char pad_char = ' ';

	if (prams->zero_flag && !prams->minus_flag)
		pad_char = '0';
	neg = neg2 = (!prams->unsign && *str == '-');
	if (neg && x < prams->width && pad_char == '0' && !prams->minus_flag)
		str++;
	else
		neg = 0;
	if ((prams->plus_flag && !neg2) ||
		(!prams->plus_flag && prams->space_flag && !neg2))
		x++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (prams->plus_flag && !neg2 && pad_char == '0' && !prams->unsign)
		n += _putchar('+');
	else if (!prams->plus_flag && prams->space_flag && !neg2 &&
		!prams->unsign && prams->zero_flag)
		n += _putchar(' ');
	while (i++ < prams->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (prams->plus_flag && !neg2 && pad_char == ' ' && !prams->unsign)
		n += _putchar('+');
	else if (!prams->plus_flag && prams->space_flag && !neg2 &&
		!prams->unsign && !prams->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @prams: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, prams_t *prams)
{
	unsigned int n = 0, neg, neg2, x = _strlen(str);
	char pad_char = ' ';

	if (prams->zero_flag && !prams->minus_flag)
		pad_char = '0';
	neg = neg2 = (!prams->unsign && *str == '-');
	if (neg && x < prams->width && pad_char == '0' && !prams->minus_flag)
		str++;
	else
		neg = 0;

	if (prams->plus_flag && !neg2 && !prams->unsign)
		n += _putchar('+'), x++;
	else if (prams->space_flag && !neg2 && !prams->unsign)
		n += _putchar(' '), x++;
	n += _puts(str);
	while (x++ < prams->width)
		n += _putchar(pad_char);
	return (n);
}
