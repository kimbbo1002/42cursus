/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:57:49 by bokim             #+#    #+#             */
/*   Updated: 2025/11/17 15:58:29 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_putbase(char c, int n);

int	ft_puthex(char c, int nb)
{
	int		test;
	long	n;
	int		tmp;
	int		count;

	count = 0;
	n = (long)nb;
	if (nb < 0)
	{
		test = ft_putbase(c, '-');
		if (test == -1)
			return (-1);
		count = 2;
		n = -n;
	}
	tmp = n % 10 + '0';
	if (n > 9)
		count = ft_puthex(c, n / 10);
	test = ft_putbase(c, tmp);
	if (test == -1)
		return (-1);
	count += 2;
	return (count);
}

static int ft_putbase(char c, int n)
{
	char	*base;
	int		test;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	test = ft_putchar(base[n / 16]);
	if (test == -1)
		return (-1);
	return (2);
}
/*
#include <stdio.h>

int	main(void)
{
	ft_puthex('X', 42);
}
	*/
