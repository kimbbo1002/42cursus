/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:49:55 by marvin            #+#    #+#             */
/*   Updated: 2025/12/02 22:49:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char        *line;
    static char *rest;

    if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
        return (NULL);
    rest = ft_read_line(fd, rest);
    if (!rest)
        return (NULL);
    line = ft_get_line(rest);
    rest = ft_get_rest(rest);
    return (line);
}

char    *ft_read_line(int fd, char *rest)
{
    char    *buf;
    ssize_t n;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    n = 1;
    while (!(ft_strchr(rest, '\n')) && n > 0)
    {
        n = read(fd, buf, BUFFER_SIZE);
        if (n == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[n] = '\0';
        rest = ft_strjoin(rest, buf);
    }
    free(buf);
    return (rest);
}

char    *ft_get_line(char *rest)
{
    char *line;
    int i;

    i = 0;
    if (!rest[i])
        return (NULL);
    while (rest[i] && rest[i] != '\n')
        i++;
    line = malloc(sizeof(char) * (i + 2));
    if (!line)
        return (NULL);
    i = 0;
    while (rest[i] && rest[i] != '\n')
    {
        line[i] = rest[i];
        i++;
    }
    if (rest[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char    *ft_get_rest(char *line)
{
    char    *rest;
    int     i;
    int     j;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (!line[i])
    {
        free(line);
        return (NULL);
    }
    rest = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
    if (!rest)
        return (NULL);
    i++;
    j = 0;
    while (line[i])
        rest[j++] = line[i++];
    rest[j] = '\0';
    free(line);
    return (rest);
}