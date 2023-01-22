#include "main.h"

/**
 * print_char - Prints a char.
 * @arg: A list of arguments pointing to
 *       the character to be printed.
 */

void print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	_putchar(c);
}

/**
 * print_string - Prints a string.
 * @arg: A list of arguments pointing to
 *       the string to be printed.
 */

void print_string(va_list arg)
{
	char *str;
	int i = 0;

	str = va_arg(arg, char *);

	if (str == NULL)
	{
		return;
	}

	while (*(str + i))
	{
		_putchar(*(str + i));
		i++;
	}
}

/**
 * print_percent - Prints the character '%'.
 * @arg: A placeholder argument (unused)
 */

void print_percent(va_list __attribute__((unused)) arg)
{
	_putchar('%');
}
