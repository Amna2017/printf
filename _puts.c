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
 * _putchars - writes the character ch to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putchar(int ch)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}
