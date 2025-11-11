/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:03:06 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 15:06:22 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;
	int	res;
	int	len;

	i = 0;
	res = 0;
	len = ft_strlen(str);
	if (c == '\0')
		return (&str[len]);
	while (str[i])
	{
		if (str[i] == c)
			res = i;
		i++;
	}
	if (res == 0 && str[res] != c)
		return (0);
	return (&str[res]);
}

/*
#include <stdio.h>

int	main(void)
{
    printf("%s", ft_strrchr("test", 't'));
}
	*/