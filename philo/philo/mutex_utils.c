/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:28:59 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/02 16:29:52 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_flag(t_philo *philo, int right);

int	lock_forks(t_philo *philo)
{
	while (check_flag(philo, 1) == 1)
	{
		if (time_is_over(philo) == 0 || check_death(philo) > 0)
			return (-1);
		usleep(100);
	}
	pthread_mutex_lock(&philo->left_fork_flag_mutex);
	philo->left_fork_flag = 1;
	pthread_mutex_unlock(&philo->left_fork_flag_mutex);
	pthread_mutex_lock(&philo->left_fork_mutex);
	while (check_flag(philo, 0) == 1)
	{
		if (time_is_over(philo) == 0 || check_death(philo) > 0)
		{
			pthread_mutex_unlock(&philo->left_fork_mutex);
			return (-1);
		}
		usleep(100);
	}
	pthread_mutex_lock(philo->right_fork_flag_mutex);
	*philo->right_fork_flag = 1;
	pthread_mutex_unlock(philo->right_fork_flag_mutex);
	pthread_mutex_lock(philo->right_fork_mutex);
	return (0);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork_flag_mutex);
	philo->left_fork_flag = 0;
	pthread_mutex_unlock(&philo->left_fork_flag_mutex);
	pthread_mutex_lock(philo->right_fork_flag_mutex);
	*philo->right_fork_flag = 0;
	pthread_mutex_unlock(philo->right_fork_flag_mutex);
	pthread_mutex_unlock(&philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}

int	check_death(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(philo->death_mutex);
	ret = philo->is_dead;
	pthread_mutex_unlock(philo->death_mutex);
	return (ret);
}

int	check_meal(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(philo->meal_mutex);
	ret = philo->nb_meal;
	pthread_mutex_unlock(philo->meal_mutex);
	return (ret);
}

static int	check_flag(t_philo *philo, int right)
{
	int	ret;

	if (right == 0)
	{
		pthread_mutex_lock(philo->right_fork_flag_mutex);
		ret = *philo->right_fork_flag;
		pthread_mutex_unlock(philo->right_fork_flag_mutex);
		return (ret);
	}
	pthread_mutex_lock(&philo->left_fork_flag_mutex);
	ret = philo->left_fork_flag;
	pthread_mutex_unlock(&philo->left_fork_flag_mutex);
	return (ret);
}
