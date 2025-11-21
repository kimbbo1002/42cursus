/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:24:25 by bokim             #+#    #+#             */
/*   Updated: 2025/11/20 23:50:03 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// includes
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// mandatory part
int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(char c, unsigned int n);
int		ft_putvoid(unsigned long long int n);

// function i need
int		ft_intlen(int n);
int		ft_uintlen(unsigned int n);
size_t	ft_strlen(char *str);

#endif