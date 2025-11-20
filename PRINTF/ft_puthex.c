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

int	ft_puthex(char c, int nb)
{
	int		test;
	long	n;
	int		tmp;

	n = (long)nb;
	if (nb < 0)
	{
		test = putbase(c, '-');
		if (test == -1)
			return (-1);
		
	}
	test = ft_putchar(base[i % 16]);
	if (test == -1)
		return (-1);
	return (2);
}

static int ft_putbase(char c, int n)
{
	char	*base;
	int		test;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	test = putchar(base[i / 16]);
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
