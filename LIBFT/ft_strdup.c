/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:33:17 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 16:36:45 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	len = ft_strlen(str);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (&res[0]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	source[];

    source[] = "GeeksForGeeks";
    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = ft_strdup(source); 
    printf("%s", target);
    return (0);
}
*/