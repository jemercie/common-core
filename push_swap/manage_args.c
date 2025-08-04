/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:50:47 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:49:00 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_alg(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->next == NULL)
		return (0);
	else if (argc == 2)
		sort_two(stack_a);
	else if (argc == 3)
		sort_three(stack_a);
	else if (argc == 4)
		sort_four(stack_a, stack_b);
	else if (argc == 5)
		sort_five(stack_a, stack_b);
	else
	{
		index_list(argc, stack_a);
		sort_the_rest(argc, stack_a, stack_b);
	}
	return (0);
}

t_stack	*manage_args(int argc, char **argv, int min)
{
	t_stack	*stack_a;
	int		i;

	i = min;
	stack_a = NULL;
	while (i < argc)
	{
		if (check_format(argv[i]) == 0)
			i++;
		else
			return (NULL);
	}
	stack_a = get_the_a_stack((argc - 1), argv, min);
	if (is_sorted(stack_a) == 0)
	{
		if (min == 0)
			free_tab(argv);
		free_list(&stack_a);
		exit(0);
	}
	return (stack_a);
}

t_stack	*get_the_a_stack(int argc, char **argv, int min)
{
	t_stack	*stack_a;
	t_stack	*new;

	new = new_elmt(ft_atoi(argv[argc]));
	new->next = NULL;
	stack_a = new;
	while (argc > min)
	{
		argc--;
		new = new_elmt(ft_atoi(argv[argc]));
		if (!new || check_double(stack_a, new->content) != 0)
		{
			write(2, "Error\n", 6);
			free_list(&stack_a);
			if (new)
				free(new);
			if (min == 0)
				free_tab(argv);
			exit (0);
		}
		new->next = stack_a;
		stack_a = new;
	}
	return (stack_a);
}

t_stack	*new_elmt(int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->index = 1;
	list->next = NULL;
	return (list);
}

void	free_list(t_stack **stack_a)
{
	t_stack	*list;

	if (!*stack_a)
		return ;
	list = (*stack_a);
	while (list)
	{
		*stack_a = (*stack_a)->next;
		free(list);
		list = *stack_a;
	}
	*stack_a = NULL;
}
