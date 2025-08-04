/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:52:41 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/15 17:51:41 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	str_to_llint(const char *arg);

int	get_args(t_context *context, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (i == 1)
			context->nb_of_philo = (str_to_llint(argv[i]));
		if (i == 2)
			context->time_to_die = (str_to_llint(argv[i]));
		if (i == 3)
			context->time_to_eat = (str_to_llint(argv[i]));
		if (i == 4)
			context->time_to_sleep = (str_to_llint(argv[i]));
		if (i == 5)
			context->repeat = (str_to_llint(argv[i]));
		i++;
	}
	if (argc == 5)
		context->repeat = 0;
	return (0);
}

static int	str_to_llint(const char *arg)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (arg[i] == '+')
		i++;
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		nb = ((nb * 10) + arg[i] - '0');
		i++;
	}
	return (nb);
}

int	check_nb_of_philo(char *str)
{
	if (ft_strlen(str) > 4)
		return (-1);
	return (0);
}
