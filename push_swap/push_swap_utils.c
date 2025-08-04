/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:01:51 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:50:01 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_nb(t_stack *stack)
{
	int	nb;

	if (!stack)
		return (0);
	if (stack->next && stack->content == 0 && stack->next->content == 0)
	{
		nb = stack->index;
		while (stack)
		{
			if (stack->index > nb)
				nb = stack->index;
			stack = stack->next;
		}
	}
	else
	{
		nb = stack->content;
		while (stack)
		{
			if (stack->content > nb)
				nb = stack->content;
			stack = stack->next;
		}
	}
	return (nb);
}

int	smallest_nb(t_stack *stack)
{
	int	nb;

	nb = stack->content;
	while (stack)
	{
		if (stack->content < nb)
			nb = stack->content;
		stack = stack->next;
	}
	return (nb);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if ((stack->content) > (stack->next->content))
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_reverse_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if ((stack->content) < (stack->next->content))
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_index_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if ((stack->index) > (stack->next->index))
			return (1);
		stack = stack->next;
	}
	return (0);
}
