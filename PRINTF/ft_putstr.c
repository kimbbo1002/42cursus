/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:46:57 by bokim             #+#    #+#             */
/*   Updated: 2025/11/21 10:21:33 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	if (!str)
	{
		count = ft_putstr("(null)");
		if (count == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		count = ft_putchar(str[i]);
		if (count == -1)
			return (-1);
		i++;
	}
	return (ft_strlen(str));
}
