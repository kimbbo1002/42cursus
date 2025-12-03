/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:49:55 by marvin            #+#    #+#             */
/*   Updated: 2025/12/03 16:01:47 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h> // to remove

void *ft_malloc(size_t size)
{
	static int i = 0;
	
	if (i++ == 600000)
		return (NULL);
	return (malloc(size));
}

static char	*ft_get_line(char *rest)
{
	char	*line;
	int		i;

	i = 0;
	if (!*rest)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = ft_malloc(sizeof(char) * (i + 2));
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

static char	*ft_get_rest(char **line)
{
	char *rest;
	int i;
	int j;

	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if (!(*line)[i])
	{
		free((*line));
		(*line) = NULL;
		return (NULL);
	}
	rest = ft_malloc(sizeof(char) * (ft_strlen((*line)) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while ((*line)[i])
		rest[j++] = (*line)[i++];
	rest[j] = '\0';
	free((*line));
	(*line) = NULL;
	return (rest);
}

static char	*ft_joinfree(char **rest, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*rest, buf);
	if (!tmp)
	{
		free(*rest);
		*rest = NULL;
		return (NULL);
	}
	return (tmp);
}

static char	*ft_read_line(int fd, char **rest)
{
	char	*buf;
	ssize_t	n;

	buf = ft_malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(*rest);
		*rest = NULL;
		return (NULL);
	}
	n = 1;
	while (!(ft_strchr(*rest, '\n')) && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(buf);
			buf = NULL;
			free(*rest);
			*rest = NULL;
			return (NULL);
		}
		if (n == 0)
			break ;
		buf[n] = '\0';
		*rest = ft_joinfree(rest, buf);
	}
	free(buf);
	buf = NULL;
	return (*rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest = 0;
	char		 *s = NULL;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	rest = ft_read_line(fd, &rest);
	if (!rest)
		return (NULL);
	line = ft_get_line(rest);
	if (!line)
    {
		free(rest);
		rest = NULL;
        return (NULL);
    }
	rest = ft_get_rest(&rest);
	if (rest == NULL)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	s = strdup(line);
	free(line);
	line = NULL;
	if (!s)
	{
		free(rest);
		rest = NULL;
	}
	return (s);
}
