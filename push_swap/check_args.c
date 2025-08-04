/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:13:24 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:48:42 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_format(char *argv)
{
	int	i;
	int	start;

	i = 0;
	if (ft_isspace(argv[i]) > 0)
		while (argv[i] && (ft_isspace(argv[i]) > 0))
			i++;
	start = i;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	if (ft_isdigit(argv[i]) > 0)
		while (argv[i] && (ft_isdigit(argv[i]) > 0))
			i++;
	else
		return (1);
	if (check_int(argv, start, i) != 0)
		return (1);
	if (ft_isspace(argv[i]) > 0)
		while (argv[i] && (ft_isspace(argv[i]) > 0))
			i++;
	if (argv[i] != '\0')
		return (1);
	return (0);
}

int	is_int(char *argv, int start, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (argv[start + i] < set[i])
			return (0);
		else if (argv[start + i] == set[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_int(char *argv, int start, int end)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (argv[start] == '-' || argv[start] == '+')
		i++;
	if (argv[start + i] == '0')
		while (argv[start + i] == '0')
				i++;
	if ((end - ((start) + i)) < 10)
		return (0);
	if ((end - ((start) + i)) > 10)
		return (1);
	if (argv[start] == '-')
		nb = is_int(argv, (start + i), "2147483648");
	else
		nb = is_int(argv, (start + i), "2147483647");
	return (nb);
}

int	check_double(t_stack *stack_a, int nb)
{
	while (stack_a)
	{
		if (stack_a->content == nb)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
