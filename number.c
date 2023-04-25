#include "main.h"

/**
 * convert - converting functions
 * @num: nums
 * @base: bases
 * @flags: flag
 * @params: struct params
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long mos = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		mos = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[mos % base];
		mos /= base;
	} while (mos != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - printing unsigned ints
 * @ap: pointer
 * @params: struct params
 *
 * Return: printing bytes
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long mos;

	if (params->l_modifier)
		mos = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		mos = (unsigned short int)va_arg(ap, unsigned int);
	else
		mos = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(mos, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * print_address - address has been printing
 * @ap: pointers
 * @params: struct params
 *
 * Return: printing bytes
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int mos = va_arg(ap, unsigned long int);
	char *str;

	if (!mos)
		return (_puts("(nil)"));

	str = convert(mos, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
