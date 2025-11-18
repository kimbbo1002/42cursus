/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:46:57 by bokim             #+#    #+#             */
/*   Updated: 2025/11/18 12:45:54 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	test;

	i = 0;
	while (str[i])
	{
		test = ft_putchar(str[i]);
		if (test == -1)
			return (-1);
		i++;
	}
	return (1);
}