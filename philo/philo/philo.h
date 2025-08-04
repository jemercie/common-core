/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:11:37 by jemercie          #+#    #+#             */
/*   Updated: 2023/03/12 15:53:22 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# define BLUE "\033[0;34m"
# define GREEN "\033[0;36m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"

	/**********************
	*   	STRUCTS       *
	**********************/

typedef struct s_context
{
	long long int	nb_of_philo;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	repeat;
	long long int	start_time;
}				t_context;

typedef struct s_philo
{
	int				number;
	long long int	last_meal;
	pthread_t		th;
	long long int	nb_meal;
	int				is_dead;
	long long int	time_tmp;
	int				left_fork_flag;
	int				*right_fork_flag;
	pthread_mutex_t	left_fork_flag_mutex;
	pthread_mutex_t	*right_fork_flag_mutex;
	pthread_mutex_t	left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*meal_mutex;
	t_context		context;
}				t_philo;

	/************************
	*		FONCTIONS		*
	************************/

/*			parsing.c				*/
int				get_args(t_context *context, int argc, char **argv);
int				check_nb_of_philo(char *str);

/*			check_args.c			*/
int				check_args(char **argv);
int				ft_strlen(char *str);

/*			init_structs.c			*/
long long int	get_time(long long int start_time);
void			init_and_assign_mutex(t_philo **philo, t_context *context);
t_context		*init_context(void);
t_philo			**init_philo(t_context *context);

/*			routine .c				*/
void			*routine(void	*phil);

/*			destroy_and_free.c		*/
void			destroy_mutex(t_philo **philo);
void			free_philo(t_philo **philo);

/*			print_and_usleep.c		*/
void			print_fork_eat(t_philo *philo);
int				split_usleep(t_philo *philo);
int				print_think(t_philo *philo);
void			print_death(t_philo **philo);
int				time_is_over(t_philo *philo);

/*			superviser.c			*/
void			*supervise(t_philo **philo, int rep);

/*			mutex_utils.c		    */
int				lock_forks(t_philo *philo);
void			unlock_forks(t_philo *philo);
int				check_meal(t_philo *philo);
int				check_death(t_philo *philo);

#endif
