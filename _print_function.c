#include "main.h"
#include <stdio.h>

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
