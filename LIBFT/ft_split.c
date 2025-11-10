/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:26:50 by bokim             #+#    #+#             */
/*   Updated: 2025/11/10 15:01:21 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_group(char const *s, char c)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count + 1);
}

char	**assign_group(char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	char	**res;

	i = 0;
	res = malloc(sizeof(char*) * count_group(s, c));
	if (!res)
		return (0);
	
	while (res[i])
		res[i] = malloc(sizeof(char) * (ft_strlen(s[i++]) + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != c)
			res[j][k++] = s[i++];
		res[j++][k++] = '\0';
		i++;
	}
	return (res);
}

char	*trim_firstlast(char const *s, char c)
{
	int	i;
	int	j;
	char	*res;
	
	j = 0;
	if (s[0] == c && s[ft_strlen(s) - 1] == c)
	{
		i = 1;
		while (i < ft_strlen(s) - 2)
			res[j++] = s[i++];
	}
	else if (s[0] == c)
	{
		i = 1;
		while (s[i])
			res[j++] = s[i++];
	}
	else
	{
		i = 0;
		while (i < ft_strlen(s) - 2)
			res[j++] = s[i++];
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*cpy;
	
	if (s[0] == c || s[ft_strlen(s) - 1] == c)
		cpy = trim_firstlast(s, c);
	else
		cpy = (char	*)s;
	res = assign_group(cpy, c);
	return (res);
}

#include <stdio.h>
int	main()
{
	char	**res = ft_split("hello,this,is,a,test", ',');
	int i = 0;
	while (res[i])
		printf("%s", res[i++]);
}