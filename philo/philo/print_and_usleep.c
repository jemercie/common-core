/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_usleep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:16:07 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/12 20:49:27 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_is_over(t_philo *philo)
{
	if (philo->last_meal + philo->context.time_to_die < \
		get_time(philo->context.start_time))
	{
		pthread_mutex_lock(philo->death_mutex);
		philo->is_dead = 2;
		pthread_mutex_unlock(philo->death_mutex);
		return (0);
	}
	return (-1);
}

void	print_fork_eat(t_philo *philo)
{
	int	nb;

	nb = 0;
	if (check_death(philo) == 1 || time_is_over(philo) == 0)
		return ;
	nb = philo->number;
	pthread_mutex_lock(philo->print_mutex);
	philo->last_meal = get_time(philo->context.start_time);
	printf("%s%lld   %d has taken a fork\n%lld   %d has taken a fork\n%s\
%lld   %d is eating\n", BLUE, philo->last_meal, nb, philo->last_meal, \
		nb, GREEN, philo->last_meal, nb);
	pthread_mutex_unlock(philo->print_mutex);
}

int	split_usleep(t_philo *philo)
{
	while (philo->time_tmp > get_time(philo->context.start_time))
	{
		if (time_is_over(philo) == 0 || check_death(philo) > 0)
			return (-1);
		usleep(500);
	}
	return (0);
}

void	print_death(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < philo[0]->context.nb_of_philo)
	{
		if (check_death(philo[i]) == 2)
		{
			pthread_mutex_lock(philo[i]->print_mutex);
			printf("\033[0;38m%lld   %d died\n"\
				, get_time(philo[i]->context.start_time), philo[i]->number);
			pthread_mutex_unlock(philo[i]->print_mutex);
			return ;
		}
		i++;
	}
}

int	print_think(t_philo	*philo)
{
	long long int	time_atm;

	if (check_death(philo) == 1)
		return (-1);
	time_atm = 0;
	pthread_mutex_lock(philo->print_mutex);
	time_atm = get_time(philo->context.start_time);
	printf("%s%lld   %d is thinking\n", PURPLE, time_atm, philo->number);
	pthread_mutex_unlock(philo->print_mutex);
	return (0);
}
