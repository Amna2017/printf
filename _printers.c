#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @go: starting address
 * @end: stopping address
 * @not: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *go, char *end, char *not)
{
	int sum = 0;

	while (go <= stop)
	{
		if (go != except)
			sum += _putchar(*go);
		go++;
	}
	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @list: string
 * @prams: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list list, prams_t *prams)
{
	int len, sum = 0;
	char *str = va_arg(list, char *);
	(void)prams;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @list: string
 * @prams: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list list, prams_t *prams)
{
	int x, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(list, char *);
	(void)prams;

	x = 0;
	index = 0;
	while (a[x])
	{
		if ((a[x] >= 'A' && a[x] <= 'Z')
		    || (a[x] >= 'a' && a[x] <= 'z'))
		{
			index = a[x] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[x]);
		x++;
	}
	return (count);
}
