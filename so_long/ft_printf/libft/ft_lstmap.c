/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:39:17 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/18 17:48:55 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*ft_flstnew(void *content, void *(*f)(void*))
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = f(content);
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*firstnode;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_flstnew(lst->content, f);
	firstnode = newlist;
	firstnode->next = NULL;
	lst = lst->next;
	while (lst)
	{
		newlist = ft_flstnew(lst->content, f);
		ft_lstadd_back(&firstnode, newlist);
		if (!newlist)
		{
			ft_lstclear(&firstnode, del);
			return (NULL);
		}
		if (lst)
			lst = lst->next;
	}
	return (firstnode);
}
