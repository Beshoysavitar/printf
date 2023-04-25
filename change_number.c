#include "main.h"
/**
 * pr_oct - ...
 * @ap: ...
 * @poo: ...
 *
 * Return: ...
 */
int pr_oct(va_list ap, para *poo)
{
	char *st;
	int i = 0;
	unsigned long q;

	if (poo->l_modifier)
		q = (unsigned long)va_arg(ap, unsigned long);
	else if (poo->h_modifier)
		q = (unsigned short int)va_arg(ap, unsigned int);
	else
		q = (unsigned int)va_arg(ap, unsigned int);
	st = conv(q, 8, CON_UN, poo);

	if (poo->hashtag_flag && q)
		*--st = '0';
	poo->unsign = 1;
	return (i += pr_num(st, poo));
}

/**
 * pr_HX - ...
 * @ap: ...
 * @poo: ...
 *
 * Return: ...
 */
int pr_HX(va_list ap, para *poo)
{
	int i = 0;
	char *st;
	unsigned long q;

	switch (poo->length_modifier)
	{
		case MOD_L:
			q = (unsigned long)va_arg(ap, unsigned long);
			break;
		case MOD_H:
			q = (unsigned short int)va_arg(ap, unsigned int);
			break;
		default:
			q = (unsigned int)va_arg(ap, unsigned int);
			break;
	}

	st = conv(q, 16, CON_UN, poo);
	if (poo->hashtag_flag && q)
	{
		*--st = 'X';
		*--st = '0';
	}
	poo->unsign = 1;
	return (i += pr_num(st, poo));
}
/**
 * pr_hx - ...
 * @ap: ...
 * @poo: ...
 *
 * Return: ...
 */
int pr_hx(va_list ap, para *poo)
{
	int i = 0;
	char *st;
	unsigned long q;

	switch (poo->length_modifier)
	{
		case MOD_L:
			q = (unsigned long) va_arg(ap, unsigned long);
			break;
		case MOD_H:
			q = (unsigned short int) va_arg(ap, unsigned int);
			break;
		default:
			q = (unsigned int) va_arg(ap, unsigned int);
	}

	st = conv(q, 16, CON_UN | CON_LOW, poo);
	if (poo->hashtag_flag && q)
	{
		*--st = 'x';
		*--st = '0';
	}
	poo->unsign = 1;
	return (i += pr_num(st, poo));
}

/**
 * pr_bin - ...
 * @ap: ...
 * @poo: ...
 *
 * Return: ...
 */
int pr_bin(va_list ap, para *poo)
{
	char *st = conv(n, 2, CON_UN, poo);
	int i = 0;
	unsigned int n = va_arg(ap, unsigned int);

	if (poo->hashtag_flag && n)
		*--st = '0';
	poo->unsign = 1;

	return (i += pr_num(st, poo));
}
