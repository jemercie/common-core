/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:09:01 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/15 19:27:21 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo **philo)
{
	int	i;
	int	max;

	i = 0;
	max = philo[i]->context.nb_of_philo;
	pthread_mutex_destroy(philo[i]->print_mutex);
	pthread_mutex_destroy(philo[i]->death_mutex);
	pthread_mutex_destroy(philo[i]->meal_mutex);
	while (i < max)
	{
		pthread_mutex_destroy(&philo[i]->left_fork_mutex);
		i++;
	}
}

void	free_philo(t_philo **philo)
{
	int	i;
	int	max;

	i = 0;
	max = philo[i]->context.nb_of_philo;
	while (i < max)
	{
		free(philo[i]);
		i++;
	}
	free(philo);
}
