/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 01:09:14 by boyoung           #+#    #+#             */
/*   Updated: 2025/12/04 01:38:13 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char rest[BUFFER_SIZE + 1];
    char        *line;
    int         end;
    
    if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
        return (0);

    end = -1;
    line = ft_make_line(rest, &end);
    if (!line)
        return (0);
    ft_strlcpy(rest, &rest[end + 1], BUFFER_SIZE + 1);
    line = ft_get_line(line, rest, &end, fd);
    if (!line || !line[0])
    {
        free(line);
        return (0);
    }
    return (line);
}

char    *ft_make_line(char *rest, int *end)
{
    size_t  i;
    char    *line;
    i = 0;
    while (rest[i] && rest[i] != '\n')
        i++;
    i++;
    line = malloc(sizeof(char) * (i + 1));
    if (!line)
        return (0);
    ft_memcpy(line, rest, i);
    line[i] = '\0';
    if (i > 0 && line[i - 1] == '\n')
        *end = i - 1;
    return (line);
}

char    *ft_get_line(char *line, char *rest, int *end, int fd)
{
    char    buf[BUFFER_SIZE + 1];
    ssize_t n;
    size_t  line_size;

    while (*end == -1)
    {
        ft_bzero(buf, (BUFFER_SIZE + 1));
        n = read(fd, buf, BUFFER_SIZE);
        if (n == -1)
        {
            free(line);
            ft_bzero(rest, (BUFFER_SIZE + 1));
            return (0);
        }
        line_size = ft_find_end(buf);
        ft_strlcpy(rest, &buf[line_size], (BUFFER_SIZE + 1));
        buf[line_size] = '\0';
        line = ft_strjoin(line, buf, end);
        if (n == 0)
        {
            ft_bzero(rest, BUFFER_SIZE + 1);
            break ;
        }
    }
    return (line);
}

size_t  ft_find_end(char *line)
{
    size_t  i;
    
    i = 0;
    if (!line)
        return (-1);
    while (i < BUFFER_SIZE)
    {
        if (line[i] == '\n' || !line[i])
            return (i + 1);
        i++;
    }
    return (i);
}