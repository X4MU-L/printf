#include "main.h"

/**
 * print_char - Prints a char.
 * @arg: A list of arguments pointing to
 *       the character to be printed.
 */

int print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	return (_putchar(c));
}

/**
 * print_string - Prints a string.
 * @arg: A list of arguments pointing to
 *       the string to be printed.
 */

int print_string(va_list arg)
{
	char *str;
	int i = 0;

	str = va_arg(arg, char *);

	if (str == NULL)
	{
		return (0);
	}

	while (*(str + i))
	{
		_putchar(*(str + i));
		i++;
	}
	return (i);
}

/**
 * print_percent - Prints the character '%'.
 * @arg: A placeholder argument (unused)
 */

int print_percent(va_list __attribute__((unused)) arg)
{
	return (_putchar('%'));
}

/**
 * _isdigit - checks if an int is a digit
 * @c: int
 * Return: return 1 if digit 0 if false
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}
