/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:13:19 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 09:52:38 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	res = malloc(sizeof(char) * ft_strlen(s1));
	if (!res)
		return (0);
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			res[k++] = s1[i];
		i++;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strtrim("aaaacaaabaaaiaaawe", "cbiw"));
}
	*/