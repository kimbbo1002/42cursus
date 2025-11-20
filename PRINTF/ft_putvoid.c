/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:34:23 by boyoung           #+#    #+#             */
/*   Updated: 2025/11/20 13:47:15 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(unsigned long long int n)
{
	int	tmp;
	int	test;
	int	count;

	count = 0;
	tmp = n % 10;
	if (n > 9)
		count = ft_putvoid(n / 10);
	test = ft_puthex('x', tmp);
	if (test == -1)
		return (-1);
	count += test;
	return (count);
}
