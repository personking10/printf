#include "main.h"

/**
 * print_from_to - printing range
 * @start: start
 * @stop: stopp
 * @except: nor address
 *
 * Return: printing num bytes
 */
int print_from_to(char *start, char *stop, char *except)
{
	int all = 0;

	while (start <= stop)
	{
		if (start != except)
			all += _putchar(*start);
		start++;
	}
	return (all);
}

/**
 * print_rev - reversing string
 * @ap: string
 * @params: struct params
 *
 * Return: printing num bytes
 */
int print_rev(va_list ap, params_t *params)
{
	int length, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (length = 0; *str; str++)
			length++;
		str--;
		for (; length > 0; length--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - printing string
 * @ap: strings
 * @params: struct params
 *
 * Return: num bytes
 */
int print_rot13(va_list ap, params_t *params)
{
	int mos, index;
	int cou = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	mos = 0;
	index = 0;
	while (a[mos])
	{
		if ((a[mos] >= 'A' && a[mos] <= 'Z')
		    || (a[mos] >= 'a' && a[mos] <= 'z'))
		{
			index = a[mos] - 65;
			cou += _putchar(arr[index]);
		}
		else
			cou += _putchar(a[mos]);
		mos++;
	}
	return (cou);
}
