/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:34:44 by bokim             #+#    #+#             */
/*   Updated: 2025/11/10 09:50:05 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int	i;
	char	*res;

	res = (char *)str;
	i = 0;
	while (res[i])
	{
		if (res[i] == c)
			return (&res[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	printf("%s", ft_strchr("hello", 'l'));
}
	*/