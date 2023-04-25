#include "main.h"


/**
 * pr_left - ...
 * @st: ...
 * @poo: ...
 *
 * Return: ...
 */
int pr_left(char *st, para *poo)
{
	char p_d = ' ';
	unsigned int n = 0, q, q2, i = _stl(st);

	if (poo->zero_flag && !poo->minus_flag)
		p_d = '0';
	q = q2 = (!poo->unsign && *st == '-');
	if (q && i < poo->width && p_d == '0' && !poo->minus_flag)
		st++;
	else
		q = 0;

	if (poo->plus_flag && !q2 && !poo->unsign)
		n += _putchar('+'), i++;
	else if (poo->space_flag && !q2 && !poo->unsign)
		n += _putchar(' '), i++;
	n += __put(st);
	for (; i < poo->width; i++)
		n += _putchar(p_d);
	return (n);
}


/**
 * pr_num - ...
 * @st: ...
 * @poo: ...
 *
 * Return: ...
 */
int pr_num(char *st, para *poo)
{
	int q = (!poo->unsign && *st == '-');
	unsigned int i = _stl(st);

	if (!poo->precision && *st == '0' && !st[1])
		st = "";
	if (q)
	{
		st++;
		i--;
	}
	if (poo->precision != UINT_MAX)
		while (i++ < poo->precision)
			*--st = '0';
	if (q)
		*--st = '-';

	if (!poo->minus_flag)
		return (pr_right(st, poo));
	else
		return (pr_left(st, poo));
}
/**
 * _stl - ...
 * @s: ...
 *
 * Return: ...
 */
int _stl(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
		i++;
	return (i);
}

/**
 * pr_right - ...
 * @st: ...
 * @poo: ...
 *
 * Return: ...
 */
int pr_right(char *st, para *poo)
{
	char p_d = ' ';
	unsigned int n = 0, q, q2;
	int i;

	if (poo->zero_flag && !poo->minus_flag)
		p_d = '0';
	q = q2 = (!poo->unsign && *st == '-');

	if (q && _stl(st) < poo->width && p_d == '0' && !poo->minus_flag)
		st++;
	else
		q = 0;
	if ((poo->plus_flag && !q2) ||
		(!poo->plus_flag && poo->space_flag && !q2))
	_stl(st)++;
	if (q && p_d == '0')
		n += _putchar('-');
	if (poo->plus_flag && !q2 && p_d == '0' && !poo->unsign)
		n += _putchar('+');
	else if (!poo->plus_flag && poo->space_flag && !q2 &&
			!poo->unsign && poo->zero_flag)
		n += _putchar(' ');
	for (i = _stl(st); i++ < poo->width;)
		n += _putchar(p_d);
	if (q && p_d == ' ')
		n += _putchar('-');
	if (poo->plus_flag && !q2 && p_d == ' ' && !poo->unsign)
		n += _putchar('+');
	else if (!poo->plus_flag && poo->space_flag && !q2 &&
		!poo->unsign && !poo->zero_flag)
		n += _putchar(' ');
	for (i = 0; st[i] != '\0'; i++)
		n += _putchar(st[i]);
	return (n);
}

/**
 * _isdig - ...
 * @c: ...
 *
 * Return: ...
 */
int _isdig(int c)
{
	return (c >= '0' && c <= '9');
}
