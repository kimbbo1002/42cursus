/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:34:23 by boyoung           #+#    #+#             */
/*   Updated: 2025/11/17 22:57:37 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_putvoid(void *s)
{
    int i;
    unsigned char   *str;
    char    *base;
    char    *res;

    i = 0;
    str = (unsigned char)s;
    base = "0123456789abcdef"
    while (str[i])
    {
        ft_putchar(base[str[i] / 16]);
        ft_putchar(base[str[i] % 16]);
        i++;
    }
}