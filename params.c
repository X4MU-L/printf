#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
<<<<<<< HEAD
=======
 *
>>>>>>> 60cbd950fa4e7b36f464e8fe6a18d2b04c84b0e4
 * Return: void
 */
void init_params(ps_t *params)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
}
