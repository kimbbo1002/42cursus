/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:15:53 by bokim             #+#    #+#             */
/*   Updated: 2025/11/10 09:38:43 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	const void	*tmp;

	i = 0;
	j = 0;
	tmp = src;
	while (*(unsigned char *)(dest + i) != '\0' )
	{
		if (*(unsigned char *)(tmp + j) == '\0')
			j = 0;
		*(unsigned char *)(dest + i++) = *(unsigned char *)(tmp + j++);
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   char dest_str[] = "oldstring";
   const char src_str[]  = "newstring";
   printf("Before memmove dest = %s, src = %s\n", dest_str, src_str);
   ft_memmove(dest_str, src_str, 9);
   printf("After memmove dest = %s, src = %s\n", dest_str, src_str);
   return(0);
}
*/