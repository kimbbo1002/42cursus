/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:33:17 by bokim             #+#    #+#             */
/*   Updated: 2025/11/10 13:37:33 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int	i;
	char	*res;
	int	len;

	i = 0;
	len = ft_strlen(str);
	res = malloc(len * sizeof(char));
	if (!res)
		return (0);
	while(str[i])
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
/*
#include<stdio.h>
#include<string.h>

int main()
{
    char source[] = "GeeksForGeeks";

    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = ft_strdup(source); 

    printf("%s", target);
    return 0;
}
*/