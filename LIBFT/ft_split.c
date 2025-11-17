/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:01:46 by bokim             #+#    #+#             */
/*   Updated: 2025/11/12 12:34:40 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_group(char const *s, char c);
char	*assign_word(char *str, char c);

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (count_group(s, c) + 1));
	if (!res || !s)
		return (0);
	while (s[i])
	{
		if (s[i] != (unsigned char)c)
		{
			res[j] = assign_word((char *)&s[i], c);
			while (s[i] && s[i] != (unsigned char)c)
				i++;
			j++;
		}
		else
			i++;
	}
	res[j] = 0;
	return (res);
}

int	count_group(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			count++;
		i++;
	}
	return (count + 1);
}

char	*assign_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != (unsigned char)c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = 0;
	while (str[i] && str[i] != (unsigned char)c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
