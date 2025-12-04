/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 01:06:37 by boyoung           #+#    #+#             */
/*   Updated: 2025/12/04 01:33:55 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_bzero(void *s, size_t n)
{
    while (n--)
        *(char *)s++ = 0;
}

void    *ft_memcpy(void *dst, void *src, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    if (!dst && !src)
        return (0);
    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    while (n--)
        *d++ = *s++;
    return (dst);
}

char    *ft_strjoin(char *s1, char *s2, int *end)
{
    char    *ret;
    size_t  len_s1;
    size_t  len_s2;

    if (!s1 || !s2)
        return (0);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    ret = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    if (!ret)
    {
        free(s1);
        return (0);
    }
    ft_memcpy(ret, s1, len_s1);
    free(s1);
    ft_memcpy(ret + len_s1, s2, len_s2 + 1);
    if (len_s1 + len_s2 > 0 && *(ret + len_s1 + len_s2 - 1) == '\n')
        *end = 0;
    return (ret);
}

void    ft_strlcpy(char *dst, char *src, size_t dstsize)
{
    size_t  i;

    i = 0;
    if (dstsize > 0)
    {
        while (src[i] && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
}