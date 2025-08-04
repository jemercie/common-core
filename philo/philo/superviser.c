/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superviser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:52:41 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/15 17:51:41 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_everyone(t_philo **philo);
static int	has_everyone_eaten_enough(t_philo **philo, int *rep);

void	*supervise(t_philo	**philo, int rep)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo[0]->context.nb_of_philo)
		{
			if ((rep > 0) && check_meal(philo[i]) >= rep)
			{
				if (has_everyone_eaten_enough(philo, &rep) == 0)
				{
					kill_everyone(philo);
					return (NULL);
				}
			}
			if (check_death(philo[i]) == 2)
			{
				kill_everyone(philo);
				return (NULL);
			}
			usleep(100);
			i++;
		}
	}
}

static int	has_everyone_eaten_enough(t_philo **philo, int *rep)
{
	int	i;
	int	total_meal;
	int	max_philo;

	i = 0;
	total_meal = philo[i]->context.nb_of_philo;
	max_philo = philo[i]->context.nb_of_philo;
	while (i < max_philo)
	{
		if (check_meal(philo[i]) >= *rep)
		{
			total_meal--;
		}
		else
		{
			return (1);
		}
		i++;
	}
	return (total_meal);
}

static void	kill_everyone(t_philo **philo)
{
	int	i;
	int	nb_philo;

	i = 0;
	nb_philo = philo[i]->context.nb_of_philo;
	while (i < nb_philo)
	{
		if (philo[i]->is_dead != 2)
		{
			pthread_mutex_lock(philo[i]->death_mutex);
			philo[i]->is_dead = 1;
			pthread_mutex_unlock(philo[i]->death_mutex);
		}
		i++;
	}
}
