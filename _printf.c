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
	char *c, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_params(&params, ap);
		if (*c != '%')
		{
			sum += _putchar(*c);
			continue;
		}
		start = c;
		c++;
		while (get_flag(c, &params)) 
		{
			c++; 
		}
		c = get_width(c, &params, ap);
		c = get_precision(c, &params, ap);
		if (get_modifier(c, &params))
			c++;
		if (!get_specifier(c))
			sum += print_from_to(start, c,
				params.l_modifier || params.h_modifier ? c - 1 : 0);
		else
			sum += get_print_func(c, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
