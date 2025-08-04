/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:33:27 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/15 17:51:33 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		init_and_assign_mutex(t_philo **philo, t_context *context);

long long int	get_time(long long int start_time)
{
	struct timeval	time;
	long long int	time_now;

	gettimeofday(&time, NULL);
	time_now = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	time_now -= start_time;
	return (time_now);
}

void	init_and_assign_mutex(t_philo **philo, t_context *context)
{
	int						i;
	static pthread_mutex_t	init_print_mutex;
	static pthread_mutex_t	init_death_mutex;
	static pthread_mutex_t	init_meal_mutex;

	i = 0;
	pthread_mutex_init(&init_print_mutex, NULL);
	pthread_mutex_init(&init_death_mutex, NULL);
	pthread_mutex_init(&init_meal_mutex, NULL);
	while (i < context->nb_of_philo - 1)
	{
		philo[i]->right_fork_flag = &philo[i + 1]->left_fork_flag;
		philo[i]->right_fork_flag_mutex = &philo[i + 1]->left_fork_flag_mutex;
		philo[i]->right_fork_mutex = &philo[i + 1]->left_fork_mutex;
		philo[i]->print_mutex = &init_print_mutex;
		philo[i]->death_mutex = &init_death_mutex;
		philo[i]->meal_mutex = &init_meal_mutex;
		i++;
	}
	philo[i]->right_fork_mutex = &philo[0]->left_fork_mutex;
	philo[i]->right_fork_flag_mutex = &philo[0]->left_fork_flag_mutex;
	philo[i]->right_fork_flag = &philo[0]->left_fork_flag;
	philo[i]->print_mutex = &init_print_mutex;
	philo[i]->death_mutex = &init_death_mutex;
	philo[i]->meal_mutex = &init_meal_mutex;
}

t_context	*init_context(void)
{
	static t_context	ctx;

	ctx.nb_of_philo = 0;
	ctx.time_to_die = 0;
	ctx.time_to_eat = 0;
	ctx.time_to_sleep = 0;
	ctx.repeat = 0;
	ctx.start_time = get_time(0);
	return (&ctx);
}

t_philo	**init_philo(t_context *context)
{
	t_philo	**philo;
	int		i;

	i = 0;
	philo = (t_philo **)malloc(sizeof(t_philo *) * (context->nb_of_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < context->nb_of_philo)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philo[i])
			return (NULL);
		philo[i]->last_meal = 0;
		philo[i]->context = *context;
		philo[i]->number = i;
		philo[i]->time_tmp = 0;
		philo[i]->nb_meal = 0;
		philo[i]->is_dead = 0;
		philo[i]->left_fork_flag = 0;
		pthread_mutex_init(&philo[i]->left_fork_mutex, NULL);
		pthread_mutex_init(&philo[i]->left_fork_flag_mutex, NULL);
		i++;
	}
	return (philo);
}
