#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @prams: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, prams_t *prams, va_list list)
{
	int dd = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		dd = va_arg(list, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			dd = dd * 10 + (*p++ - '0');
	}
	prams->precision = dd;
	return (p);
}
