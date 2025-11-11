/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:31:41 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 16:08:13 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < n && big[i])
	{
		j = 0;
		while (little[j] && big[i] == little[j] && i < n)
		{
			if (!little[j + 1])
			{
				res = (char *)big;
				return (&res[i - ft_strlen(little) + 1]);
			}
			j++;
			i++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   const char str[20] = "TutorialsPoint";
   const char substr[10] = "Point";
   char *ret;
   
   // strstr(main_string, substring)
   ret = ft_strnstr(str, substr, 20);
   
   // Display the output
   printf("The substring is: %s\n", ret);
   
   return(0);
}
   */

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
   char str_1[100] = "Welcome to Tutorialspoint";
   char *str_2;
   str_2 = ft_strnstr(str_1, "ials", 100);
   printf("\nSubstring is: %s", str_2);
   return (0);
}
*/