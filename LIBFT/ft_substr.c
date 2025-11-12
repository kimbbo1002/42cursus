/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:41:25 by bokim             #+#    #+#             */
/*   Updated: 2025/11/12 15:38:42 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc((len + 1) * sizeof(char));
	if (!res || start >= ft_strlen(str))
		return (0);
	while (i != start)
		i++;
	while (str[i] && j < len)
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char const* test = "hellothisisatest";
	printf("%s", ft_substr(test, 't', 30));
}
*/