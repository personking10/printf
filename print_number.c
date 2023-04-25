#include "main.h"

/**
 * _isdigit - check char
 * @c: the char check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - return len
 * @s: string
 *
 * Return: int
 */
int _strlen(char *s)
{
	int mos = 0;

	while (*s++)
		mos++;
	return (mos);
}

/**
 * print_number - printing num
 * @str: the base num
 * @params: struct params
 *
 * Return: char
 */
int print_number(char *str, params_t *params)
{
	unsigned int mos = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		mos--;
	}
	if (params->precision != UINT_MAX)
		while (mos++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints nums
 * @str: the base num
 * @params: struct params
 *
 * Return: char
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int mos = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		mos += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		mos += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		mos += _putchar(' ');
	while (i++ < params->width)
		mos += _putchar(pad_char);
	if (neg && pad_char == ' ')
		mos += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		mos += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		mos += _putchar(' ');
	mos += _puts(str);
	return (mos);
}

/**
 * print_number_left_shift - printing nums
 * @str: the base num
 * @params: struct params
 *
 * Return: char
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int mos = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		mos += _putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		mos += _putchar(' '), i++;
	mos += _puts(str);
	while (i++ < params->width)
		mos += _putchar(pad_char);
	return (mos);
}
