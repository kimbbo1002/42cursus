/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boyoung <boyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:31:02 by boyoung           #+#    #+#             */
/*   Updated: 2025/11/16 19:47:41 by boyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_content;

	if (!lst || !f || !del)
		return (0);
	new_list = 0;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, new_content);
        lst = lst->next;
	}
	return (new_list);
}
