#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @prams: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, prams_t *prams)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @list: argument pointer
 * @prams: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list list, prams_t *prams)
{
	unsigned long l;

	if (prams->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);
	prams->unsign = 1;
	return (print_no(convert(l, 10, CONVERT_UNSIGNED, prams), prams));
}



/**
 * print_address - prints address
 * @list: argument pointer
 * @prams: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list list, prams_t *prams)
{
	unsigned long int n = va_arg(list, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prams);
	*--str = 'x';
	*--str = '0';
	return (print_no(str, prams));
}
