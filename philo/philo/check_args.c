/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:44:15 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/02 09:46:43 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c);
static int	check_int(char *argv);
static int	is_int(char *argv, char *set);

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (!argv[i] || !argv[i][0] || check_int(argv[i]) < 0)
			return (-1);
		if (argv[i][j] == '-' || argv[i][j] == '+' || argv[i][j] == '0')
			return (-1);
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	if (check_nb_of_philo(argv[1]) < 0)
		return (-1);
	return (0);
}

static int	check_int(char *argv)
{
	int	nb;

	nb = 0;
	if (ft_strlen(argv) < 10)
		return (0);
	if (ft_strlen(argv) > 10)
		return (-1);
	nb = is_int(argv, "2147483647");
	return (nb);
}

static int	is_int(char *argv, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (argv[i] < set[i])
			return (0);
		else if (argv[i] == set[i])
			i++;
		else
			return (-1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static int	ft_isdigit(int c)
{
	if ((c > 47) && (c < 58))
		return (2048);
	else
		return (0);
}
