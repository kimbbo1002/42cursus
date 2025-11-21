/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:34:23 by boyoung           #+#    #+#             */
/*   Updated: 2025/11/21 11:30:39 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(unsigned long long int n)
{
	int	tmp;
	int	test;
	int	count;

	count = 0;
	tmp = n % 16;
	if (n >= 16)
		count = ft_putvoid(n / 16);
	test = ft_puthex('x', tmp);
	if (test == -1)
		return (-1);
	count += test;
	return (count);
}
