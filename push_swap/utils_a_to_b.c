/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:50:36 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:51:23 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ra_worth(int done, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index <= done)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_rra_worth(int done, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack)
	{
		if (stack->index <= done)
			j = i;
		stack = stack->next;
		i++;
	}
	return (i - j);
}

void	ra_or_rra(int done, t_stack **stack_a)
{
	int	i;
	int	j;

	i = is_ra_worth(done, *stack_a);
	j = is_rra_worth(done, *stack_a);
	if (i > j)
	{
		while (j > 0)
		{
			rra(stack_a);
			j--;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(stack_a);
			i--;
		}
	}
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
