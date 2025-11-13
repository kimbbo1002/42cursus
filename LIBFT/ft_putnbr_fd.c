/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:12:48 by bokim             #+#    #+#             */
/*   Updated: 2025/11/13 10:42:12 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*res;
	int		i;

	res = ft_itoa(n);
	i = 0;
	while (res[i])
	{
		write(fd, &res[i], 1);
		i++;
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-12345, 1);
}
	*/