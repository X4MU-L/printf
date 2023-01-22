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
 * print_int - Prints an int.
 * @arg: A list of arguments pointing to
 *       the integer to be printed.
 */

void print_int(va_list arg)
{
	int num;

	num = va_arg(arg, int);
	_int_printer(num);
}


/**
 * _int_printer - Prints an int.
 * @num: int to be printed
 */

void _int_printer(int num)
{
	int sign = -1;

	if (num < 0)
	{
		num *= sign;
		_putchar('-');
	}

	if ((num / 10) > 0)
		_int_printer(num / 10);

	_putchar((num % 10) + '0');
}

/**
 * print_percent - Prints the character '%'.
 * @arg: A placeholder argument (unused)
 */

void print_percent(va_list __attribute__((unused)) arg)
{
	_putchar('%');
}
