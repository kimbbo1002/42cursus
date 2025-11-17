/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:31:02 by boyoung           #+#    #+#             */
/*   Updated: 2025/11/17 09:46:05 by bokim            ###   ########.fr       */
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
		new_content = ft_lstnew(f(lst->content));
		if (!new_content)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new_content);
		lst = lst->next;
	}
	return (new_list);
}
