/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:23:00 by psevilla          #+#    #+#             */
/*   Updated: 2024/10/09 22:30:15 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*l_next;

	if (!f || !del || !lst)
		return (NULL);
	l = NULL;
	while (lst)
	{
		l_next = ft_lstnew((*f)(lst->content));
		if (!l_next)
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		ft_lstadd_back(&l, l_next);
		lst = lst->next;
	}
	return (l);
}
