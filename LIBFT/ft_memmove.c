/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:15:53 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 11:55:10 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (dest < src)
	{
		i = 0;
		while (*(unsigned char *)(dest + i) != '\0' && i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (*(unsigned char *)(dest + i) != '\0' && i >= 0)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i--;
		}
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
   ft_memmove(dest_str, dest_str + 5, 9);
   printf("After memmove dest = %s, src = %s\n", dest_str, src_str);
   return(0);
}
*/

/*
#include <stdio.h> 
#include <string.h> 
int main() 
{ 
char csrc[100] = "Geeksfor"; 
memmove(csrc+5, csrc, strlen(csrc)+1); 
printf("%s", csrc); 
return 0; 
}
*/