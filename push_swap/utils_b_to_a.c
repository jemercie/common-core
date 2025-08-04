/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:42:00 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:51:35 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rb_worth(int target, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == target)
			return (i);
		else if (stack->index == target - 1)
			return (i);
		else if (stack->index == target - 2)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	is_rrb_worth(int target, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack)
	{
		if (stack->index == target)
			j = i;
		else if (stack->index == target -1)
			j = i;
		else if (stack->index == target - 2)
			j = i;
		stack = stack->next;
		i++;
	}
	return (i - j);
}

void	rb_or_rrb(int done, t_stack **stack)
{
	int	i;
	int	j;

	i = is_rb_worth(done, *stack);
	j = is_rrb_worth(done, *stack);
	if (i > j)
	{
		while (j > 0)
		{
			rrb(stack);
			j--;
		}
	}
	else
	{
		while (i > 0)
		{
			rb(stack);
			i--;
		}
	}
}
