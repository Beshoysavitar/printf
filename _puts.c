#include "main.h"

/**
 * __put - ...
 * @s: ...
 *
 * Return: ...
 */
int __put(char *s)
{
	char *c = s;

	while (*s)
		_putchar(*s++);
	return (s - c);
}

/**
 * _putchar - ...
 * @c: ...
 *
 * Return: ...
 */
int _putchar(int c)
{
	static char buf[OP_B_S];
	static int i;

	if (c == B_F || i >= OP_B_S)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != B_F)
		buf[i++] = c;
	return (1);
}
