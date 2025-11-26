/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:26:57 by bokim             #+#    #+#             */
/*   Updated: 2025/11/26 16:33:51 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buf;
	char		*line;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left);
		free(buf);
		left = 0;
		buf = 0;
		return (0);
	}
	if (!buf)
		return (0);
	line = fill_line(fd, left, buf);
	free(buf);
	buf = 0;
	if (!line)
	{
		left = 0;
		return (0);
	}
	left = trim_line(line);
	return (line);
}

char	*fill_line(int fd, char *left, char *buf)
{
	char	*tmp;
	ssize_t	n;

	n = 1;
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(left);
			return (0);
		}
		else if (n == 0)
			break ;
		buf[n] = '\0';
		if (!left)
			left = ft_strdup("");
		tmp = left;
		left = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = 0;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (left);
}

char	*trim_line(char *line)
{
	char	*left;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i] || (line[1]))
		return (0);
	left = ft_substr(line, i + 1, ft_strlen(line) - i);
	line[i + 1] = '\0';
	if (!left || !(*left))
	{
		free(left);
		left = 0;
	}
	return (left);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
