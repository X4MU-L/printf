#include "main.h"
#include <stdio.h>

/**
 * _printf - Imitatates the printf function and prints
 * arguments according to specifiers.
 * @format: pointer to a string of char to be printed
 * ...: arg_list
 * Return: Returns the length of format.
 */


int _printf(const char *format, ...)
{
	int len = 0;
	va_list specs;
	pf_t printarray[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{"%", print_percent},
		{NULL, NULL}
	};

	if (format == NULL)
		return (len);

	va_start(specs, format);
	while (format && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			format = call_print(format, &len, printarray, specs);
		}
		else
		{
			_putchar(*format);
			len++;
			format++;
		}
	}
	va_end(specs);
	return (len);
}

/**
 * call_print - Calls a specifier function to print specified identifier
 * @format: pointer to string to print
 * @len: pointer to runing length of string;
 * @arr: array of struct print_f
 * @specs: va_list argument
 * Return: Returns a constant pointer to format string
 */
const char *call_print(const char *format, int *len, pf_t arr[], va_list specs)
{
	int i = 0;

	while (i < 6 && *format != *(arr[i].str)
	       && arr[i].str != NULL)
		i++;

	if (i < 6)
	{
		arr[i].func(specs);
		format++;
		(*len)++;
	}
	else
	{
		_putchar(*format);
		format++;
		(*len)++;
	}

	return (format);

}
