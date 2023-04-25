#include "main.h"


/**
 * pr_rot - ...
 * @ap: ...
 * @poo: ...
 *
 * Return: ...
 */
int pr_rot(va_list ap, para *poo)
{
	char a[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *ar = va_arg(ap, char *);
	int i, j;
	int c = 0;
	(void)poo;

	i = 0;
	j = 0;

	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			j = a[i] - 65;
			c += _putchar(ar[j]);
		}
		else
			c += _putchar(a[i]);
		i++;
	}
	return (c);
}

/**
 * pr_fr_to - ...
 * @sa: ...
 * @so: ...
 * @ex: ...
 *
 * Return: ...
 */
int pr_fr_to(char *sa, char *so, char *ex)
{
	int i = 0;

	while (sa <= so)
	{
		if (sa != ex)
			i += _putchar(*sa);
		sa++;
	}
	return (i);
}

/**
 * pr_rev - ...
 * @ap: ...
 * @poo: ...
 *
 * Return: ...
 */
int pr_rev(va_list ap, para *poo)
{
	int len, i = 0;
	char *st = va_arg(ap, char *);
	(void)poo;

	if (st)
	{
		for (len = 0; *st; st++)
			len++;
		st--;
		for (; len > 0; len--, st--)
			i += _putchar(*st);
	}
	return (i);
}
