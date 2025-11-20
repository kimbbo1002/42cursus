/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:48:40 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 15:44:44 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	tmp;
	int	test;

	if (n < 0)
	{
		test = ft_putchar('-');
		if (test == -1)
			return (-1);
		ft_putunbr(-n);
	}
	if (n >= 0)
	{
		tmp = n % 10 + '0';
		if (n > 9)
			ft_putnbr(n / 10);
		test = ft_putchar(tmp);
		if (test == -1)
			return (-1);
	}
	return (ft_intlen(n));
}
/*
#include "limits.h"
int	main()
{
	ft_putnbr(INT_MIN);
}
*/