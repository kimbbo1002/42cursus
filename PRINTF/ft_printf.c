/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:23:28 by bokim             #+#    #+#             */
/*   Updated: 2025/11/17 23:17:56 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			test = sort_type(&format[i + 1], arg);
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
	if (c = 'c' || 's' || 'p' || 'd' || 'i' || 'u' || 'x' || 'X' || '%')
		return (1);
	else
		return (0);
}


static int sort_type(const char c, va_list arg)
{
	int	test;

	test = 1;
	if (c == 'c')
		test = ft_putchar(va_arg(arg, char));
	else if (c == 's')
		test = ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		test = ft_putvoid(va_arg(arg, void *));
	else if (c == 'd')
		test = ft_putnbr(va_arg(arg, int));
	else if (c == 'i')
		test = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		test = ft_unsigned_putnbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		test = ft_puthex(va_arg(arg, unsigned int));
	else if (c == '%')
		test = ft_putchar(c);
	if (test = -1)
		return (0)
	return (1);
}
