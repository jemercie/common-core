/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:16:07 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/12 20:49:27 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating(t_philo *philo);
static int	sleeping(t_philo *philo);

void	*routine(void	*phil)
{
	t_philo			*philo;

	philo = (t_philo *) phil;
	if ((philo->number % 2) == 1)
		usleep(500);
	while (time_is_over(philo) == -1)
	{
		if (time_is_over(philo) == -1 && check_death(philo) == 0)
		{
			if (eating(philo) < 0)
				return (NULL);
			if (check_death(philo) == 1 || sleeping(philo) < 0)
				return (NULL);
			if (time_is_over(philo) == 0 || print_think(philo) < 0)
				return (NULL);
		}
		else
			return (NULL);
	}
	if (check_death(philo) == 1)
		return (NULL);
	pthread_mutex_lock(philo->death_mutex);
	philo->is_dead = 2;
	pthread_mutex_unlock(philo->death_mutex);
	return (NULL);
}

static int	eating(t_philo *philo)
{
	if (lock_forks(philo) < 0)
		return (-1);
	print_fork_eat(philo);
	philo->time_tmp = (philo->last_meal + philo->context.time_to_eat);
	if (split_usleep(philo) < 0)
	{
		pthread_mutex_unlock(&philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		return (-1);
	}
	pthread_mutex_lock(philo->meal_mutex);
	philo->nb_meal++;
	pthread_mutex_unlock(philo->meal_mutex);
	unlock_forks(philo);
	return (0);
}

static int	sleeping(t_philo *philo)
{	
	pthread_mutex_lock(philo->print_mutex);
	philo->time_tmp = get_time(philo->context.start_time);
	printf("%s%lld   %d is sleeping\n", YELLOW, philo->time_tmp, philo->number);
	philo->time_tmp += philo->context.time_to_sleep;
	pthread_mutex_unlock(philo->print_mutex);
	if (split_usleep(philo) < 0)
		return (-1);
	return (0);
}
