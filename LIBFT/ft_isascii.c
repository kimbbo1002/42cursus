/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:03:45 by bokim             #+#    #+#             */
/*   Updated: 2025/11/19 10:33:05 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
description :
ft_isascii checks whether the value of c is an ascii character

return value :
- 1 if c is ascii
- 0 if not
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
