#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *x, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (x = (char *)format; *x; x++)
	{
		init_params(&params, ap);
		if (*x != '%')
		{
			sum += _putchar(*x);
			continue;
		}
		start = x;
		x++;
		while (get_flag(x, &params)) /* while char at p is flag char */
		{
			x++; /* next char */
		}
		x = get_width(x, &params, ap);
		x = get_precision(x, &params, ap);
		if (get_modifier(x, &params))
			x++;
		if (!get_specifier(x))
			sum += print_from_to(start, x,
				params.l_modifier || params.h_modifier ? x - 1 : 0);
		else
			sum += get_print_func(x, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
