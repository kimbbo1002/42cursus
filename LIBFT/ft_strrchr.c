/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:03:06 by bokim             #+#    #+#             */
/*   Updated: 2025/11/10 09:43:00 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, int c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == c)
			res = i;
		i++;
	}
	if (res == 0 && str[res] != c)
		return (0);
	return (&str[res]);
}

/*
#include <stdio.h>
int main()
{
    printf("%s", ft_strrchr("test", 't'));
}
	*/