/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:12:48 by jemercie          #+#    #+#             */
/*   Updated: 2022/10/14 16:38:36 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;

	if (!del || !lst)
		return ;
	list = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		del(list->content);
		free(list);
		list = *lst;
	}
	*lst = NULL;
}
