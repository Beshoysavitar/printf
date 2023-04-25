#ifndef _PRINTF_H
#define _PRINTF_H
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#define PARA_I {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CON_LOW	1
#define CON_UN	2
#define OP_B_S 1024
#define B_F -1
#define F_B_S 50
#define NULL_S "(null)"
/**
 * struct parameters - ...
 * @unsign: ...
 * @plus_flag: ...
 * @space_flag: ...
 * @hashtag_flag: ...
 * @zero_flag: ...
 * @minus_flag: ...
 * @width: ...
 * @precision: ...
 * @h_modifier: ...
 * @l_modifier: ...
 */
typedef struct parameters
{
	unsigned int unsign			: 1;
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} para;
/**
 * struct speci - ...
 *
 * @speci: ...
 * @f: ...
 */
typedef struct speci
{
	char *speci;
	int (*f)(va_list, para *);
} spec;
int pr_rot(va_list ap, para *poo);
void i_par(para *poo, va_list ap);
char *g_pre(char *q, para *poo, va_list a);
int _printf(const char *format, ...);
int __put(char *str);
int _putchar(int c);
int p_p(va_list a, para *poo);
int p_S(va_list a, para *poo);
int _isdig(int c);
int _stl(char *s);
char *conv(long int n, int b, int f, para *poo);
int p_un(va_list ap, para *poo);
int p_addr(va_list ap, para *poo);
int (*get_speci(char *s))(va_list ap, para *poo);
int g_p_func(char *s, va_list ap, para *poo);
int g_f(char *s, para *poo);
int g_mod(char *s, para *poo);
char *g_w(char *s, para *poo, va_list ap);
int p_c(va_list a, para *poo);
int pr_num(char *st, para *poo);
int pr_right(char *st, para *poo);
int pr_left(char *st, para *poo);
int p_i(va_list a, para *poo);
int p_s(va_list a, para *poo);
int pr_hx(va_list ap, para *poo);
int pr_HX(va_list ap, para *poo);
int pr_bin(va_list ap, para *poo);
int pr_oct(va_list ap, para *poo);
int pr_fr_to(char *sa, char *so, char *ex);
int pr_rev(va_list ap, para *poo);
#endif
