#include "main.h"

/**
 * print_char - prints character
 * @list: argument pointer
 * @prams: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list list, prams_t *prams)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(list, int);

	if (prams->minus_flag)
		sum += _putchar(ch);
	while (pad++ < prams->width)
		sum += _putchar(pad_char);
	if (!prams->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @list: argument pointer
 * @prams: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list list, prams_t *prams)
{
	long l;

	if (prams->l_modifier)
		l = va_arg(list, long);
	else if (prams->h_modifier)
		l = (short int)va_arg(list, int);
	else
		l = (int)va_arg(list, int);
	return (print_number(convert(l, 10, 0, prams), prams));
}

/**
 * print_string - prints string
 * @list: argument pointer
 * @prams: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list list, prams_t *prams)
{
	char *str = va_arg(list, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)prams;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (prams->precision < pad)
		j = pad = prams->precision;

	if (prams->minus_flag)
	{
		if (prams->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < prams->width)
		sum += _putchar(pad_char);
	if (!prams->minus_flag)
	{
		if (prams->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @list: argument pointer
 * @prams: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list list, prams_t *prams)
{
	(void)list;
	(void)prams;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @list: argument pointer
 * @prams: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list list, prams_t *prams)
{
	char *str = va_arg(list, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, prams);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
