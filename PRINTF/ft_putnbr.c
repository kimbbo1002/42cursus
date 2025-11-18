/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:48:40 by bokim             #+#    #+#             */
/*   Updated: 2025/11/18 11:45:39 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		test = write(1, &tmp, 1);
		if (test == -1)
			return (-1);
	}
	return (1);
}
/*
#include "limits.h"
int	main()
{
	ft_putnbr(INT_MIN);
}
*/