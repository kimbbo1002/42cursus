/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 01:18:11 by boyoung           #+#    #+#             */
/*   Updated: 2025/12/04 01:34:59 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#define MAX_FD 1024

//standar headers
#include <stdlib.h>
#include <unistd.h>

//get_next_line.c
char    *get_next_line(int fd);
char    *ft_make_line(char *rest, int *end);
char    *ft_get_line(char *line, char *rest, int *end, int fd);
size_t  ft_find_end(char *line);

//get_next_line_utils.c
size_t  ft_strlen(char *s);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dst, void *src, size_t n);
char    *ft_strjoin(char *s1, char *s2, int *end);
void    ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif