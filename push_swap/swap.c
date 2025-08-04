/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:28:00 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:51:08 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	if ((*stack)->next)
		tmp->next = (*stack)->next;
	else
		tmp->next = NULL;
	(*stack)->next = tmp;
}

void	sa(t_stack **stack)
{
	if (!(*stack)->next)
		return ;
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	if (!(*stack)->next)
		return ;
	swap(stack);
	write(1, "sb\n", 3);
}

void	swapswap(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a)->next)
		return ;
	if (!(*stack_b)->next)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
