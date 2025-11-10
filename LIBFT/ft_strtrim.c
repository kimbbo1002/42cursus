/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:13:19 by bokim             #+#    #+#             */
/*   Updated: 2025/11/10 14:26:32 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	int	i; // index of s1
	int	j; // index of set
	int	k; // index of res
	char	*res;

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
				break;
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
int	main()
{
	printf("%s", ft_strtrim("aaaacaaabaaaiaaawe", "cbiw"));
}
	*/