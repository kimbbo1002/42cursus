/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:36:47 by bokim             #+#    #+#             */
/*   Updated: 2025/11/12 13:38:07 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n);
static char	*ft_revstr(char *str);

char	*ft_itoa(int n)
{
	int		i;
	int		num;
	char	*res;

	if (n >= 0)
		num = n;
	else
		num = -n;
	res = malloc(sizeof(char) * (ft_intlen(n) + 2));
	if (!res)
		return (0);
	i = 0;
	while (num / 10 != 0)
	{
		res[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	res[i++] = num + '0';
	if (n < 0)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_revstr(res));
}

static int	ft_intlen(int n)
{
	int	len;
	int	num;

	num = n;
	len = 0;
	while (num / 10 != 0)
	{
		num = num / 10;
		len++;
	}
	return (len + 1);
}

static char	*ft_revstr(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_itoa(-123));
}
*/