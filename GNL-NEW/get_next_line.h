/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:52:32 by marvin            #+#    #+#             */
/*   Updated: 2025/12/02 22:52:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#define MAX_FD 1024

//standard libraries
#include <stdlib.h>
# include <unistd.h>

//get_next_line.c
char    *get_next_line(int fd);
char    *ft_read_line(int fd, char *rest);
char    *ft_get_line(char *rest);
char    *ft_get_rest(char *line);

//get_next_line_utils.c
size_t  ft_strlen(char *str);
char    *ft_strchr(char *str, int c);
char    *ft_strjoin(char *s1, char *s2);

#endif