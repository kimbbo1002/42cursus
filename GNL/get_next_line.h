/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:45:03 by bokim             #+#    #+#             */
/*   Updated: 2025/11/24 14:17:06 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// BUFFER_SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// standard header files
# include <stdlib.h>
# include <unistd.h>

// get_next_line.c
char		*get_next_line(int fd);
char		*fill_line(int fd, char *left, char *buf);
char		*trim_line(char *line);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

// get_next_line_utils.c
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_count_len(char const *s, unsigned int start, size_t len);

#endif