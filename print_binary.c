#include "main.h"

/**
 * print_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, ps_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED);
	int len = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (len += print_number(str, params));
}
