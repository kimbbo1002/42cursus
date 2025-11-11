/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:34:44 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 22:32:52 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	int		len;
	char	*res;

	res = (char *)str;
	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (res[i] == (unsigned char)c)
			return (&res[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strchr("hello", 'l'));
}
	*/