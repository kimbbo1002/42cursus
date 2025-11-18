/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:23:28 by bokim             #+#    #+#             */
/*   Updated: 2025/11/18 13:01:26 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	is_format(char c);
static int sort_type(const char c, va_list arg);

int	ft_printf(const char *format, ...)
{
	int	i;
	int	test;
	va_list arg;

	if (!format)
		return (-1);
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && is_format(format[i + 1]))
		{
			test = sort_type(format[i + 1], arg);
			i = i + 2;
		}
		else
			test = write(1, &format[i++], 1);
		if (!test)
				return (-1);
	}
	va_end(arg);
	return (0);
}

static int	is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' 
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}


static int sort_type(const char c, va_list arg)
{
	int	test;

	test = 1;
	if (c == 'c')
		test = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		test = ft_putstr(va_arg(arg, char *));
	//else if (c == 'p')
		//test = ft_putvoid(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		test = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		test = ft_putunbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		test = ft_puthex(c, va_arg(arg, unsigned int));
	else if (c == '%')
		test = ft_putchar(c);
	if (test == -1)
		return (0);
	return (1);
}
/*
#include <stdio.h>

int	main()
{
	int	test = 11342;
	char	test2 = 't';
	char	*test3 = "testing";
	unsigned int test4 = 2147483648;
	int	test5 = 42;
	ft_printf("hello this is a %i\n", test);
	ft_printf("hello this is a %d\n", test);
	ft_printf("hello this is a %c\n", test2);
	ft_printf("hello this is a %s\n", test3);
	ft_printf("hello this is a %u\n", test4);
	ft_printf("hello this is a %x\n", test5);
	ft_printf("hello this is a %X\n", test5);
}
	*/