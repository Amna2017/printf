#include "main.h"

/**
 * _puts - prints a string with newline
 * @st: the string to print
 *
 * Return: void
 */
int _puts(char *st)
{
	char *a = st;

	while (*st)
		_putchar(*st++);
	return (st - a);
}

/**
 * _putchars - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putchar(int c)
{
	static int x;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || x >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
