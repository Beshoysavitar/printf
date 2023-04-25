#include "main.h"

/**
 * g_mod - ...
 * @s: ...
 * @poo: ...
 *
 * Return: ...
 */
int g_mod(char *s, para *poo)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = poo->h_modifier = 1;
		break;
	case 'l':
		i = poo->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * g_p_func - ...
 * @s: ...
 * @ap: ...
 * @poo: ...
 *
 * Return: ...
 */
int g_p_func(char *s, va_list ap, para *poo)
{
	int (*f)(va_list, para *) = get_speci(s);

	if (f)
		return (f(ap, poo));
	return (0);
}
/**
 * g_w - ...
 * @s: ...
 * @poo: ...
 * @ap: ...
 *
 * Return: ...
 */
char *g_w(char *s, para *poo, va_list ap)
/* should this function use char **s and modify the pointer? */
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdig(*s))
			d = d * 10 + (*s++ - '0');
	}
	poo->width = d;
	return (s);
}
/**
 * get_speci - ...
 * @s: ...
 *
 * Return: ...
 */
int (*get_speci(char *s))(va_list ap, para *poo)
{
	int i = 0;

	spec specis[] = {
		{"c", p_c},
		{"d", p_i},
		{"i", p_i},
		{"s", p_s},
		{"%", p_p},
		{"b", pr_bin},
		{"o", pr_oct},
		{"u", p_un},
		{"x", pr_hx},
		{"X", pr_HX},
		{"p", p_addr},
		{"S", p_S},
		{"r", pr_rev},
		{"R", pr_rot},
		{NULL, NULL}
	};

	while (specis[i].speci)
	{
		if (*s == specis[i].speci[0])
		{
			return (specis[i].f);
		}
		i++;
	}
	return (NULL);
}
/**
 * g_f - ...
 * @s: the ...
 * @poo: ...
 *
 * Return: ...
 */
int g_f(char *s, para *poo)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = poo->plus_flag = 1;
			break;
		case ' ':
			i = poo->space_flag = 1;
			break;
		case '#':
			i = poo->hashtag_flag = 1;
			break;
		case '-':
			i = poo->minus_flag = 1;
			break;
		case '0':
			i = poo->zero_flag = 1;
			break;
	}
	return (i);
}
