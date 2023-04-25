#include "main.h"

/**
 * _puts - print string with lines
 * @str: string
 *
 * Return: void
 */
int _puts(char *str)
{
	char *mos = str;

	while (*str)
		_putchar(*str++);
	return (str - mos);
}

/**
 * _putchar - write chars
 * @c: chars
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int moss;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || moss >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, moss);
		moss = 0;
	}
	if (c != BUF_FLUSH)
		buf[moss++] = c;
	return (1);
}
