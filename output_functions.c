#include "main.h"

/**
 * p_s - ...
 * @a: ...
 * @poo: ...
 *
 * Return: ...
 */
int p_s(va_list a, para *poo)
{
	unsigned int q = 0, s = 0, i = 0, j;
	char *str = va_arg(a, char *), pc = ' ';

	(void)poo;
	switch ((int)(!str))
		case 1:
			str = NULL_S;

	j = q = _stl(str);
	if (poo->precision < q)
		j = q = poo->precision;

	if (poo->minus_flag)
	{
		if (poo->precision != UINT_MAX)
			for (i = 0; i < q; i++)
				s += _putchar(*str++);
		else
			s += __put(str);
	}
	while (j++ < poo->width)
		s += _putchar(pc);
	if (!poo->minus_flag)
	{
		if (poo->precision != UINT_MAX)
			for (i = 0; i < q; i++)
				s += _putchar(*str++);
		else
			s += __put(str);
	}
	return (s);
}
/**
 * p_S - ...
 * @a: ...
 * @poo: ...
 *
 * Return: ...
 */
int p_S(va_list a, para *poo)
{
	int s = 0;
	char *str = va_arg(a, char *);
	char *x;

	if ((int)(!str))
		return (__put(NULL_S));
	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			s += _putchar('\\');
			s += _putchar('x');
			x = conv(*str, 16, 0, poo);
			if (!x[1])
				s += _putchar('0');
			s += __put(x);
		}
		else
		{
			s += _putchar(*str);
		}
		str++;
	}
	return (s);
}

/**
 * p_i - ...
 * @a: ...
 * @poo: ...
 *
 * Return: ...
 */
int p_i(va_list a, para *poo)
{
	long l;

	if (poo->l_modifier)
		l = va_arg(a, long);
	else if (poo->h_modifier)
		l = (short int)va_arg(a, int);
	else
		l = (int)va_arg(a, int);
	return (pr_num(conv(l, 10, 0, poo), poo));
}
/**
 * p_c - ...
 * @a: ...
 * @poo: ...
 *
 * Return: ...
 */
int p_c(va_list a, para *poo)
{
	unsigned int q = 1, s = 0, ch = va_arg(a, int);
	char pc = ' ';

	if (poo->minus_flag)
		s += _putchar(ch);
	while (q++ < poo->width)
		s += _putchar(pc);
	if (!poo->minus_flag)
		s += _putchar(ch);
	return (s);
}


/**
 * p_p - ...
 * @a: ...
 * @poo: ...
 *
 * Return: ...
 */
int p_p(va_list a, para *poo)
{
	(void)a;
	(void)poo;
	return (_putchar('%'));
}
