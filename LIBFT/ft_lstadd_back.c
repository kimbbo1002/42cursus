/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:51:27 by boyoung           #+#    #+#             */
/*   Updated: 2025/11/16 19:43:41 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;
    
    if (!new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
	last = ft_lstlast(*lst);
    last->next = new;
}
