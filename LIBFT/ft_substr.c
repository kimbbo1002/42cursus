/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:41:25 by bokim             #+#    #+#             */
/*   Updated: 2025/11/10 14:03:11 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t i;
	size_t j;
	char	*res;
	
	i = 0;
	j = 0;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	while (str[i] != (char)start)
		i++;
	while (str[i] && j < len)
		res[j++] = str[i++];
	res[j] = '\0';
	if (res[0] == '\0')
		return (0);
	else
		return (res);
}
/*
#include <stdio.h>
int	main()
{
	char const* test = "hellothisisatest";
	printf("%s", ft_substr(test, 't', 5));
}
	*/