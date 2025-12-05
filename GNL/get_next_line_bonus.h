/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:18:48 by bokim             #+#    #+#             */
/*   Updated: 2025/12/04 13:21:41 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define MAX_FD 1024

// standar headers
# include <stdlib.h>
# include <unistd.h>

// get_next_line_bonus.c
char	*get_next_line(int fd);
char	*ft_make_line(char *rest, int *nl);
char	*ft_get_line(char *line, char *rest, int *nl, int fd);
size_t	ft_find_nl(char *line);

// get_next_line_utils_bonus.c
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2, int *nl);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif