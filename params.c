#include "main.h"

/**
 * i_par - ...
 * @poo: ...
 * @a: ...
 *
 * Return: ...
 */
void i_par(para *poo, va_list a)
{
	poo->unsign = 0;
	poo->width = 0;
	poo->zero_flag = 0;
	poo->minus_flag = 0;
	poo->h_modifier = 0;
	poo->l_modifier = 0;
	poo->precision = UINT_MAX;
	poo->plus_flag = 0;
	poo->space_flag = 0;
	poo->hashtag_flag = 0;
	(void)a;
}
