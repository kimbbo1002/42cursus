/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:30:50 by bokim             #+#    #+#             */
/*   Updated: 2025/11/18 11:39:02 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunbr(unsigned int n)
{
	int	tmp;
	int	test;
	
	tmp = n % 10 + '0';
	if (n > 9)
		ft_putunbr(n / 10);
	test = write(1, &tmp, 1);
	if (test == -1)
		return (-1);
	return (0);
}
/*
#include <limits.h>

int main()
{
	ft_putunbr(2147483648);
}
	*/