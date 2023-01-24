#include "main.h"

/**
 * print_int - Prints an int.
 * @arg: A list of arguments pointing to
 *       the integer to be printed.
 */

int print_int(va_list arg)
{
	int num;

	num = va_arg(arg, int);
	return (_int_printer(num));
}


/**
 * _int_printer - Prints an int.
 * @num: int to be printed
 */

int _int_printer(int num)
{
	static unsigned int sum = 0;
	int sign = -1;

	if (num < 0)
	{
		num *= sign;
		_putchar('-');
		sum++;
	}

	if ((num / 10) > 0)
		_int_printer(num / 10);

	sum++;
	return (sum + _putchar((num % 10) + '0'));
}
