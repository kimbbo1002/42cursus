/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:46:00 by bokim             #+#    #+#             */
/*   Updated: 2025/11/25 12:43:53 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putvoid(unsigned long n)
{
	int	tmp;
	int	count;

	count = 0;
	tmp = n % 16;
	if (n >= 16)
		count = ft_putvoid(n / 16);
	count += ft_puthex('x', tmp);
	return (count);
}

int	ft_puthex(char c, unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(c, n / 16);
	ft_putchar(base[n % 16]);
	return (count + 1);
}
