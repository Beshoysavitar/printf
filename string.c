#include "main.h"

/**
 * g_pre - ...
 * @q: ...
 * @poo: ...
 * @a: ...
 *
 * Return: ...
 */
char *g_pre(char *q, para *poo, va_list a)
{
	int i = 0;

	if (*q != '.')
		return (q);
	q++;

	if (q == '')
	{
		i = va_arg(a, int);
		q++;
	}
	else
	{
		for (; isdigit(*q); q++)
		{
			i = i * 10 + (*q - '0');
		}
	}
	poo->precision = i;
	return (q);
}
