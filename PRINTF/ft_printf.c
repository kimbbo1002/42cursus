/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:23:28 by bokim             #+#    #+#             */
/*   Updated: 2025/11/25 12:44:32 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
return value :
- number of bytes printed
- negative number if error occurs
*/

static int	is_format(char c);
static int	sort_type(const char c, va_list arg);
static int	do_void(void *arg);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && is_format(format[i + 1]))
		{
			count += sort_type(format[i + 1], arg);
			i = i + 2;
		}
		else
			count += ft_putchar(format[i++]);
	}
	va_end(arg);
	return (count);
}

static int	is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

static int	sort_type(const char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count = ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		count = do_void(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		count = ft_putunbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthex(c, va_arg(arg, unsigned int));
	else if (c == '%')
		count = ft_putchar(c);
	return (count);
}

static int	do_void(void *arg)
{
	int	count;

	if (arg == 0)
	{
		count = ft_putstr("(nil)");
		return (count);
	}
	ft_putstr("0x");
	count = ft_putvoid((unsigned long)arg) + 2;
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	int				test;
	char			test2;
	char			*test3;
	unsigned int	test4;
	int				test5;

	test = 11342;
	test2 = 't';
	test3 = "testing";
	test4 = 2147483648;
	test5 = 42;
	ft_printf("hello this is a %i and a %d\n", test, test);
	ft_printf("hello this is a %d\n", test);
	ft_printf("hello this is a %c\n", test2);
	ft_printf("hello this is a %s\n", test3);
	ft_printf("hello this is a %u\n", test4);
	ft_printf("hello this is a %x\n", test5);
	ft_printf("hello this is a %X\n", test5);
}
*/

#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	i = printf(" %www");
	printf("\n");
	j = ft_printf(" %www");
	printf("\n");
	printf("%d, %d", i, j);
}
