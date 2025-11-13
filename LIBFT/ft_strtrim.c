/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:13:19 by bokim             #+#    #+#             */
/*   Updated: 2025/11/13 15:47:59 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set);
static int	count_alloc(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (count_alloc(s1, set) + 1));
	if (!res)
		return (0);
	while (s1[i])
	{
		if (is_set(s1[i], set) && (i == 0 || i == ft_strlen(s1) - 1))
			i++;
		else
			res[j++] = s1[i++];
	}
	res[j] = '\0';
	return (res);
}

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_alloc(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (is_set(s1[i], set) && (i == 0 || i == ft_strlen(s1) - 1))
			i++;
		else
			count++;
	}
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strtrim("aaaacaaabaaaiaaawe", "cbiw"));
}
*/