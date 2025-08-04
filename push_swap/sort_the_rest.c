/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_rest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:14:55 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:50:55 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_chunk(int done, int argc)
{
	int	rest;
	int	new_chunk;

	rest = argc - done;
	if (argc <= 100)
	{
		if (rest > 27)
			new_chunk = 27;
		else
			new_chunk = rest;
	}
	else
	{
		if (rest > 61)
			new_chunk = 61;
		else
			new_chunk = rest;
	}
	return (new_chunk);
}

void	sort_the_rest(int argc, t_stack **stack_a, t_stack **stack_b)
{
	int	done;
	int	chunk;

	done = 0;
	chunk = 0;
	while (*stack_a)
	{
		chunk = define_chunk(done, argc);
		done += chunk;
		a_to_b(done, chunk, stack_a, stack_b);
	}
	b_to_a(done, stack_a, stack_b);
}

void	a_to_b(int done, int chunk, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (i < chunk)
	{
		if (*stack_b && (*stack_b)->next)
		{
			if ((*stack_b)->index < done - (chunk / 2))
				rb(stack_b);
		}
		ra_or_rra(done, stack_a);
		pb(stack_a, stack_b);
		i++;
	}
}

void	b_to_a(int done, t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*stack_b)
	{
		rb_or_rrb(done, stack_b);
		pa(stack_b, stack_a);
		j++;
		if ((*stack_a)->index == done - 2)
		{
			if ((*stack_a)->next)
				ra(stack_a);
			i++;
		}
		done = what_is_done(stack_a, done, &i, &j);
	}
}	

int	what_is_done(t_stack **stack_a, int done, int *i, int *j)
{
	if (*j == 1 && (*stack_a)->index == done && *i == 0)
	{
		done--;
		*j = 0;
	}
	else if (*j == 2 && *i == 0)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		done -= 2 ;
		*j = 0;
	}
	else if ((*stack_a)->next && (*stack_a)->next->next)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		if ((*stack_a)->next->index == done && (*i == 1))
		{
			rra(stack_a);
			done -= 3;
			*i = 0;
			*j = 0;
		}
	}
	return (done);
}
