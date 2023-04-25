#include "main.h"

/**
 * get_specifier - finding func
 * @s: string
 *
 * Return: num of bytes
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
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
	int mos = 0;

	while (specifiers[mos].specifier)
	{
		if (*s == specifiers[mos].specifier[0])
		{
			return (specifiers[mos].f);
		}
		mos++;
	}
	return (NULL);
}

/**
 * get_print_func - finding func
 * @s: string
 * @ap: pointer
 * @params: struct parameter
 *
 * Return: num of bytes
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - finding flag
 * @s: string
 * @params: struct params
 *
 * Return: if valid
 */
int get_flag(char *s, params_t *params)
{
	int mos = 0;

	switch (*s)
	{
		case '+':
			mos = params->plus_flag = 1;
			break;
		case ' ':
			mos = params->space_flag = 1;
			break;
		case '#':
			mos = params->hashtag_flag = 1;
			break;
		case '-':
			mos = params->minus_flag = 1;
			break;
		case '0':
			mos = params->zero_flag = 1;
			break;
	}
	return (mos);
}

/**
 * get_modifier - finds function of modif
 * @s: string format
 * @params: struct params
 *
 * Return: if valid
 */
int get_modifier(char *s, params_t *params)
{
	int mos = 0;

	switch (*s)
	{
	case 'h':
		mos = params->h_modifier = 1;
		break;
	case 'l':
		mos = params->l_modifier = 1;
		break;
	}
	return (mos);
}

/**
 * get_width - getting width
 * @s: string
 * @params: params
 * @ap: pointer
 *
 * Return: pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int mos = 0;

	if (*s == '*')
	{
		mos = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			mos = mos * 10 + (*s++ - '0');
	}
	params->width = mos;
	return (s);
}
