/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 23:19:25 by marvin            #+#    #+#             */
/*   Updated: 2025/12/02 23:19:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strchr(char *str, int c)
{
    size_t  i;

    i = 0;
    if (!str)
        return (0);
    if (c == '\0')
        return (&str[ft_strlen(str)]);
    while (str[i])
    {
        if (str[i] == (char)c)
            return (&str[i]);
        i++;
    }
    return (0);
}

char    *ft_strjoin(char *s1, char *s2)
{
    size_t  i;
    size_t  j;
    char    *ret;

    if (!s1)
    {
        s1 = malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    if (!s2)
        return (NULL);
    ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!ret)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
        ret[j++] = s1[i++];
    i = 0;
    while (s2[i])
        ret[j++] = s2[i++];
    ret[j] = '\0';
    free(s1);
    return (ret);
}
