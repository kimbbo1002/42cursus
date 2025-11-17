/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:23:28 by bokim             #+#    #+#             */
/*   Updated: 2025/11/17 15:54:28 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list arg;

	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		while (str[i] != '%')
			write(1, &str[i++], 1);
		if (str[i++] == '%')
		{
			sort_type(&str[i], arg);
			i = i + 2;
		}
	}
	va_end(arg);
	return (0);
}
static void sort_type(const char *str, va_list arg)
{
	if (str[i] == 'c')
		ft_putchar(va_arg(arg, char));
	else if (str[i] == 's')
		ft_putstr(va_arg(arg, char *));
	else if (str[i] == 'p')
		// ?????
	else if (str[i] == 'd')
		ft_putnbr(va_arg(arg, int));
	else if (str[i] == 'i')
		ft_putnbr(va_arg(arg, int));
	else if (str[i] == 'u')
		ft_unsigned_putnbr(va_arg(arg, unsigned int));
	else if (str[i] == 'x')
		//ft_puthexa()
	else if (str[i] == 'X')
		//??
	else if (str[i] == '%')
		write(1, '%', 1);
	return (0);
}
