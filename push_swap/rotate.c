/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:49:24 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:50:31 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	tmp->next = NULL;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	ra(t_stack **stack)
{
	if (!(*stack)->next)
		return ;
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	if (!(*stack)->next)
		return ;
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rotarota(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a)->next)
		return ;
	if (!(*stack_b)->next)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
