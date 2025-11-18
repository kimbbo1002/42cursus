/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:34:23 by boyoung           #+#    #+#             */
/*   Updated: 2025/11/18 13:34:56 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(void *s)
{
	unsigned long int	ptr;
	int					test;

	ptr = (unsigned long int)s;
	test = ft_putunbr(ptr);
	if (test == -1)
		return (-1);
	return (1);
}
