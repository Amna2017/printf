#include "main.h"

/**
 * _printf - prints anything
 * @form: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *form, ...)
{
	int sum = 0;
	va_list list;
	char *p, *start;
	prams_t prams = PARAMS_INIT;

	va_start(list, form);

	if (!form || (form[0] == '%' && !form[1]))
		return (-1);
	if (form[0] == '%' && form[1] == ' ' && !form[2])
		return (-1);
	for (p = (char *)form; *p; p++)
	{
		init_params(&prams, list);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &prams)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &prams, list);
		p = get_precision(p, &prams, list);
		if (get_modifier(p, &prams))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
				prams.l_modifier || prams.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, list, &prams);
	}
	_putchar(BUF_FLUSH);
	va_end(list);
	return (sum);
}
