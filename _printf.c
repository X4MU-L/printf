#include "main.h"

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
	char *p, *start;
	int (*func)(va_list arg, ps_t *params);
	ps_t params = PARAMS_INIT;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(specs, format);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params);
		if (*p != '%')
		{
			len += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (set_flag(p, &params))
			p++;
		p = set_width(p, &params, specs);
		p = set_precision(p, &params, specs);
		if (set_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			len += print_from_to(start, p,
				      params.l_modifier ||
				      params.h_modifier ? p - 1 : 0);
		else
		{
			func = get_specifier(p);
			len += func(specs, &params);
		}
	}
	_putchar(BUF_FLUSH);
	va_end(specs);
	return (len);
}
