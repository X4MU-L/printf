#include "main.h"

/**
 * get_specifier - Calls a specifier function to print specified identifier
 * @s: pointer to string
 * Return: Returns afunction pointer
 */
int (*get_specifier(char *s))(va_list arg)
{
	int i = 0;
	pf_t specs_array[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	while (i < 4 && *s != *(specs_array[i].str)
	       && specs_array[i].str != NULL)
		i++;
	return (specs_array[i].func);

}

/**
 * set_flag - finds the flag func
 * @s: the format string
 * @flags: the flags struct parameter
 * Return: if flag was valid
 */

int set_flag(char *s, ps_t *flags)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = flags->plus_flag = 1;
			break;
		case ' ':
			i = flags->space_flag = 1;
			break;
		case '#':
			i = flags->hashtag_flag = 1;
			break;
		case '-':
			i = flags->minus_flag = 1;
			break;
		case '0':
			i = flags->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * set_width - gets the width from the format string or va_list
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: the pointer address passed or incremented
 */

char *set_width(char *s, ps_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int); /*gets the width from args specified */
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}

/**
 * set_modifier - sets the modifier flag if any
 * @s: the format string
 * @mods: the modifiers struct parameters
 *
 * Return: 1 if modifier was valid else 0
 */

int set_modifier(char *s, ps_t *mods)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = mods->h_modifier = 1;
		break;
	case 'l':
		i = mods->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * set_precision - sets the precision from the format string or va_list
 * @p: the format string
 * @params: the parameters struct
 * @ap: the pointer address passed or incremented
 *
 * Return: new pointer
 */

char *set_precision(char *p, ps_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
