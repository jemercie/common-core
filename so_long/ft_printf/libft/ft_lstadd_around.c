/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_around.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:50:12 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/28 11:54:55 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_around(t_list *pile_a, t_list *new)
{
	if (!pile_a)
		return ;
	new->next = pile_a->next;
	pile_a->next = new;
	pile_a = new;
}
