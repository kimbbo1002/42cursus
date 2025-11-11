/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:54:11 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 09:25:01 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	if (n == 0 || size == 0)
		return (0);
	res = malloc(size * n);
	if (!res)
		return (0);
	while (res[i])
		res[i++] = 0;
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void) {
    int *ptr = (int *)ft_calloc(5, sizeof(int));
    
    // Checking if failed or pass
    if (ptr == NULL) {
        printf("Allocation Failed");
        exit(0);
    }
    
    // No need to populate as already
    // initialized to 0
        
    // Print the array
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
    return (0);
}
	*/
