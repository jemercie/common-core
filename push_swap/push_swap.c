/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:48:19 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:49:38 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_list(int argc, t_stack **stack)
{
	t_stack	*next_arg;
	t_stack	*firstnode;
	int		nb;

	firstnode = *stack;
	next_arg = *stack;
	while (argc > 0)
	{
		*stack = firstnode;
		nb = next_arg->content;
		next_arg = next_arg->next;
		while (*stack)
		{
			if ((*stack)->content > nb)
				(*stack)->index += 1;
			*stack = (*stack)->next;
		}
		argc--;
	}
	*stack = firstnode;
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int	get_the_quotes(t_stack **stack_a, char *argv, int argc)
{
	char	**tab;
	int		len;

	len = argc - 1;
	tab = ft_split(argv, ' ');
	if (tab[0] == NULL)
	{
		free_tab(tab);
		write(2, "Error\n", 6);
		exit(0);
	}
	else
	{
		len = tablen(tab);
		*stack_a = manage_args(len, tab, 0);
	}
	free_tab(tab);
	return (len);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	len = argc - 1;
	stack_a = NULL;
	if (argc == 2)
		len = get_the_quotes(&stack_a, argv[1], argc);
	else
		stack_a = manage_args(argc, argv, 1);
	stack_b = NULL;
	if (stack_a == NULL)
		print_error();
	which_alg(len, &stack_a, &stack_b);
	free_list(&stack_b);
	free_list(&stack_a);
	return (0);
}
