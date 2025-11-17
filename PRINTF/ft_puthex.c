/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:57:49 by bokim             #+#    #+#             */
/*   Updated: 2025/11/17 15:58:29 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex(char c, unsigned int i)
{
    char    *base;
    int test;

    if (c == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    
    while (i / 256 != 0)
        i = i / 256;
    test = putchar(base[i / 16]);
    if (test == -1)
        return (-1);
    test = putchar(base[i % 16]);
    if (test == -1)
        return (-1);
    return (1);
}
