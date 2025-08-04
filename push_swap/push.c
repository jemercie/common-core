/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:52:57 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:49:20 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*tmp;

	if (!*stack_src)
		return ;
	tmp = *stack_src;
	if ((*stack_src)->next == NULL)
		*stack_src = NULL;
	else
		*stack_src = (*stack_src)->next;
	if (*stack_dest == NULL)
		tmp->next = NULL;
	else
		tmp->next = *stack_dest;
	*stack_dest = tmp;
}

void	pa(t_stack **stack_src, t_stack **stack_dest)
{
	push(stack_src, stack_dest);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_src, t_stack **stack_dest)
{
	push(stack_src, stack_dest);
	write(1, "pb\n", 3);
}
