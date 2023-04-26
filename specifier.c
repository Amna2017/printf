#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list list, prams_t *prams)
{
	specifiers_t specifiers[] = {
		{ "c", print_char },
		{ "d", print_int},
		{ "i", print_int},
		{ "s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int x = 0;

	while (specifiers[x].specifiers)
	{
		if (*s == specifiers[x].specifiers[0])
		{
			return (specifiers[x].fun);
		}
		x++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @list: argument pointer
 * @prams: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list list, prams_t *prams)
{
	int (*f)(va_list, prams_t *) = get_specifier(s);

	if (f)
		return (f(list, prams));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @prams: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *s, prams_t *prams)
{
	int id = 0;

	switch (*s)
	{
		case '+':
			id = prams->plus_flag = 1;
			break;
		case ' ':
			id = prams->space_flag = 1;
			break;
		case '#':
			id = prams->hashtag_flag = 1;
			break;
		case '-':
			id = prams->minus_flag = 1;
			break;
		case '0':
			id = prams->zero_flag = 1;
			break;
	}
	return (id);
}

/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @prams: the prameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, prams_t *prams)
{
	int id = 0;

	switch (*s)
	{
	case 'h':
		id = prams->h_modifier = 1;
		break;
	case 'l':
		id = prams->l_modifier = 1;
		break;
	}
	return (id);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @prams: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, prams_t *prams, va_list list)
{
	int dd = 0;

	if (*s == '*')
	{
		dd = va_arg(list, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			dd = dd * 10 + (*s++ - '0');
	}
	prams->width = dd;
	return (s);
}
