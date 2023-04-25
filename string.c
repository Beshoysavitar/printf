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

	if (*q == '\0')
	{
		i = va_arg(a, int);
		q++;
	}
	else
	{
		for (; _isdig(*q); q++)
		{
			i = i * 10 + (*q - '0');
		}
	}
	poo->precision = i;
	return (q);
}
