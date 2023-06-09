#include "main.h"

/**
 * conv - ...
 * @n: ...
 * @b: ...
 * @f: ...
 * @poo: ...
 *
 * Return: ...
 */
char *conv(long int n, int b, int f, para *poo)
{
	char *ptr;
	unsigned long un = n;
	static char buffer[50];
	static char *array;
	char sign = 0;
	(void)poo;

	if (!(f & CON_UN) && n < 0)
	{
		un = -n;
		sign = '-';
	}
	array = f & CON_LOW ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[un % b];
		un /= b;
	} while (un != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * p_un - ...
 * @ap: ...
 * @poo: ...
 *
 * Return: ...
 */
int p_un(va_list ap, para *poo)
{
	unsigned long e;

	if (poo->l_modifier)
		e = (unsigned long)va_arg(ap, unsigned long);
	else if (poo->h_modifier)
		e = (unsigned short int)va_arg(ap, unsigned int);
	else
		e = (unsigned int)va_arg(ap, unsigned int);
	poo->unsign = 1;
	return (pr_num(conv(e, 10, CON_UN, poo), poo));
}

/**
 * p_addr - ...
 * @ap: ...
 * @poo: ...
 *
 * Return: ...
 */
int p_addr(va_list ap, para *poo)
{
	char *st;
	unsigned long int i = va_arg(ap, unsigned long int);

	if (!i)
		return (__put("(nil)"));

	st = conv(i, 16, CON_UN | CON_LOW, poo);
	*--st = 'x';
	*--st = '0';
	return (pr_num(st, poo));
}
