#include "main.h"
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
	unsigned long n = n;
	(void)poo;
	static char *array;
	static char buffer[50];
	char sign = 0;

	if (!(f & CON_UN) && n < 0)
	{
		n = -n;
		sign = '-';

	}
	array = f & CON_LOW ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	while (n != 0)
	{
		*--ptr = array[n % b];
		n /= b;
	}

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

	switch (poo->length_modifier)
	{
		case LEN_L:
			e = (unsigned long)va_arg(ap, unsigned long);
			break;
		case LEN_H:
			e = (unsigned short int)va_arg(ap, unsigned int);
			break;
		default:
			e = (unsigned int)va_arg(ap, unsigned int);
			break;
	}

	poo->unsign = 1;
	return (pr_num(conv(e, 10, CON_UN, poo), poo));
}
