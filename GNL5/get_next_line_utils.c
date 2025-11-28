/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:34:01 by bokim             #+#    #+#             */
/*   Updated: 2025/11/28 13:36:10 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
description :
ft_strchr finds the first occurence of c in str

return value :
- pointer to the first occurence of c in str
- NULL if c is not found
*/

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!str)
		return (0);
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
description :
ft_strdup duplicates s1 by allocating memory and copying

return value :
- pointer to the new string
- NULL if the memory allocation fails
*/

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}

/*
description :
ft_strjoin allocates memory to a new string and concatenates s1 and s2

return value :
- pointer to new string
- NULL if memory alloc fails
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (0);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!s)
		return (malloc(0));
	res = malloc((ft_count_len(s, start, len) + 1) * sizeof(char));
	if (!res)
		return (0);
	if ((size_t)start < ft_strlen(s))
	{
		i = start;
		while (s[i] && j < len)
			res[j++] = s[i++];
	}
	res[j] = '\0';
	return (res);
}

int	ft_count_len(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = ft_strlen(s);
	if ((size_t)start < i)
	{
		if (len < i - (size_t)start)
			count = len;
		else
			count = i - (size_t)start;
	}
	return (count);
}
