#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct print_f - Defines a struct for mapping a function to a type
 * of specifers
 * @str: pointer to a string - specifiers
 * @func: function pointer to a function that returns void and take va_list
 */

typedef struct print_f
{
	char *str;
	void (*func)(va_list arg);
} pf_t;

int _putchar(char c);
int _printf(const char *format, ...);
void print_percent(va_list arg);
void print_char(va_list arg);
void print_string(va_list arg);
void print_int(va_list arg);
void _int_printer(int num);
const char *call_print(const char *format, int *len, pf_t arr[], va_list specs);

#endif
