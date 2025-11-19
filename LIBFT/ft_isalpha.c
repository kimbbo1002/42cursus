/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:45:04 by bokim             #+#    #+#             */
/*   Updated: 2025/11/19 10:32:56 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
description :
ft_isalpha checks whether the value of c is alphabetic

return value :
- 1 if c is alphabetic
- 0 if not
*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
