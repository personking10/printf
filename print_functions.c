#include "main.h"

/**
 * print_char - printing  chars
 * @ap: pointer
 * @params: struct params
 *
 * Return: int
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, all = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		all += _putchar(ch);
	while (pad++ < params->width)
		all += _putchar(pad_char);
	if (!params->minus_flag)
		all += _putchar(ch);
	return (all);
}

/**
 * print_int - printing integer
 * @ap: pointer
 * @params: struct params
 *
 * Return: int
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - printing string
 * @ap: pointer
 * @params: struct params
 *
 * Return: int
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, all = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				all += _putchar(*str++);
		else
			all += _puts(str);
	}
	while (j++ < params->width)
		all += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				all += _putchar(*str++);
		else
			all += _puts(str);
	}
	return (all);
}

/**
 * print_percent - printing string
 * @ap: pointer
 * @params: struct params
 *
 * Return: int
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - format specif
 * @ap: pointer
 * @params: struct params
 *
 * Return: int
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int all = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			all += _putchar('\\');
			all += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				all += _putchar('0');
			all += _puts(hex);
		}
		else
		{
			all += _putchar(*str);
		}
	}
	return (all);
}
