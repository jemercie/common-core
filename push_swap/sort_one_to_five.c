/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_to_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:26:44 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:50:46 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if (*stack > (*stack)->next)
		sa(stack);
}

void	sort_three(t_stack **stack)
{
	if (is_sorted(*stack) == 0)
		return ;
	else
	{
		if ((*stack)->next->content == biggest_nb(*stack))
			rra(stack);
		else if ((*stack)->content == biggest_nb(*stack))
			ra(stack);
		else if ((*stack)->next->next->content == biggest_nb(*stack))
			sa(stack);
		sort_three(stack);
	}
}

void	sort_reverse_three(t_stack **stack)
{
	if (is_reverse_sorted(*stack) == 0)
		return ;
	else
	{
		if ((*stack)->next->content == smallest_nb(*stack))
			ra(stack);
		else if ((*stack)->content == smallest_nb(*stack))
			rra(stack);
		else if ((*stack)->next->content == biggest_nb(*stack))
			sa(stack);
		sort_reverse_three(stack);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a) == 0)
		return ;
	if ((*stack_a)->next->content == smallest_nb(*stack_a))
		sa(stack_a);
	if ((*stack_a)->next->next->next->content == smallest_nb(*stack_a))
		ra(stack_a);
	if ((*stack_a)->next->next->content == smallest_nb(*stack_a))
		ra(stack_a);
	if ((*stack_a)->content == smallest_nb(*stack_a))
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_b, stack_a);
	}
	sort_four(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a) == 0)
		return ;
	if ((*stack_a)->next->content == smallest_nb(*stack_a))
		ra(stack_a);
	if ((*stack_a)->next->next->content == smallest_nb(*stack_a))
		ra(stack_a);
	if ((*stack_a)->next->next->next->content == smallest_nb(*stack_a))
		rra(stack_a);
	if ((*stack_a)->next->next->next->next->content == smallest_nb(*stack_a))
		rra(stack_a);
	if ((*stack_a)->content == smallest_nb(*stack_a))
	{
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_b, stack_a);
	}
	sort_five(stack_a, stack_b);
}
