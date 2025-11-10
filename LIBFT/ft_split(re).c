/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split(re).c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:01:41 by bokim             #+#    #+#             */
/*   Updated: 2025/11/10 15:06:00 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_groups(char const *s, char c)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && (i != 0 && i != ft_strlen(s, c) - 1))
			count++;
		i++;
	}
	return (count + 1);
}

char	**ft_split(char const *s, char c)
{
	int	i;
}