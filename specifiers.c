#include "main.h"

/**
 * get_specifier - Calls a specifier function to print specified identifier
 * @s: pointer to string
 * Return: Returns afunction pointer
 */
int (*get_specifier(char *s))(va_list arg, char *)
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

        return (arr[i].func);

}
