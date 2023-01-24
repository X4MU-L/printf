#include "main.h"
#include <stdio.h>

char *convert(long int num, int base, int flag)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
		printf("%ud\n", n);
	}
	array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" :
		"0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
