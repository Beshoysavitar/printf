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
	char *a = va_arg(ap, char *);
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
			c += _putchar(a[j]);
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
	int i;

	for (i = 0; sa <= so; sa++)
	{
		if (sa != ex)
		i += _putchar(*sa);
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
	(void)poo;
	int len, i = 0;
	char *st = va_arg(ap, char *);

	switch ((int)(!*st))
	{
		case 1:
			*st = NULL_S;
	}

	if (st)
	{
		len = 0;
		while (*st)
		{
			len++;
			st++;
		}
		st--;
		while (len > 0)
		{
			i += _putchar(*st);
			st--;
			len--;
		}
	}
	return (i);
}
