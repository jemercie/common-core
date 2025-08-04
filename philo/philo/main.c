/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:09:01 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/15 19:27:21 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_thread(t_philo **philo, t_context *context);
static void	create_thread(t_philo **philo, t_context *context);

int	main(int argc, char **argv)
{
	t_context	*context;
	t_philo		**philo;

	if ((argc > 6 || argc < 5) || check_args(argv) < 0)
	{
		printf("Error, wrong args.\n");
		return (-1);
	}
	context = NULL;
	context = init_context();
	if (get_args(context, argc, argv) < 0)
		return (-1);
	philo = init_philo(context);
	init_and_assign_mutex(philo, context);
	create_thread(philo, context);
	supervise(philo, philo[0]->context.repeat);
	join_thread(philo, context);
	print_death(philo);
	destroy_mutex(philo);
	free_philo(philo);
	return (0);
}

static void	create_thread(t_philo **philo, t_context *context)
{
	int	i;

	i = 0;
	while (i < context->nb_of_philo)
	{
		if (pthread_create(&philo[i]->th, NULL, routine, (void *)philo[i]) != 0)
			return ;
		i++;
	}
}

static void	join_thread(t_philo **philo, t_context *context)
{
	int	i;

	i = 0;
	while (i < context->nb_of_philo)
	{
		if (pthread_join(philo[i]->th, NULL) != 0)
		{
			return ;
		}
		i++;
	}
}
