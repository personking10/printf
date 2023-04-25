#include "main.h"

/**
 * get_precision - getting precision
 * @p: string
 * @params: the struct params
 * @ap: pointer
 *
 * Return: pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int mos = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		mos = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			mos = mos * 10 + (*p++ - '0');
	}
	params->precision = mos;
	return (p);
}
