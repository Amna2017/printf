#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @list: the argument pointer
 * @prams: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list list, prams_t *prams)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (prams->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (prams->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prams);
	if (prams->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	prams->unsign = 1;
	return (c += print_number(str, prams));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @list: the argument pointer
 * @prams: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list list, prams_t *prams)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (prams->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (prams->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, prams);
	if (prams->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	prams->unsign = 1;
	return (c += print_number(str, prams));
}
/**
 * print_binary - prints unsigned binary number
 * @list: the argument pointer
 * @prams: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list list, prams_t *prams)
{
	unsigned int n = va_arg(list, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, prams);
	int c = 0;

	if (prams->hashtag_flag && n)
		*--str = '0';
	prams->unsign = 1;
	return (c += print_number(str, prams));
}

/**
 * print_octal - prints unsigned octal numbers
 * @list: the argument pointer
 * @prams: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list list, prams_t *prams)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (prams->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (prams->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, prams);

	if (prams->hashtag_flag && l)
		*--str = '0';
	prams->unsign = 1;
	return (c += print_number(str, prams));
}
