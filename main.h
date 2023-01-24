#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} ps_t;

/**
 * struct print_f - Defines a struct for mapping a function to a type
 * of specifers
 * @str: pointer to a string - specifiers
 * @func: function pointer to a function that returns void and take va_list
 */

typedef struct print_f
{
	char *str;
	int (*func)(va_list arg);
} pf_t;

int _putchar(int c);
int _printf(const char *format, ...);
int print_percent(va_list arg);
int print_char(va_list arg);
int print_string(va_list arg);
int (*get_specifier(char *s))(va_list arg);
int set_flag(char *s, ps_t *flags);
char *set_width(char *s, ps_t *params, va_list ap);
int set_modifier(char *s, ps_t *mods);
char *set_precision(char *p, ps_t *params, va_list ap);
void init_params(ps_t *params);
int _isdigit(int c);
int print_from_to(char *start, char *stop, char *except);

#endif
