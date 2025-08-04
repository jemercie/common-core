/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:59:28 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/09 19:42:48 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static long long	ft_atoll(char *str);
static long long	exit_check_arg(char *str);
static int			is_llint(char *nb, char *set, int pos);
static int			check_is_numeric_arg(char *str);

int	ft_exit(t_args *arg, t_env *env, t_env *export, int is_pipe)
{
	long long int	exit_code;
	int				pos;

	pos = 0;
	if (!arg->cmd[1])
		exit_no_args(arg, env, export, is_pipe);
	exit_code = exit_check_arg(arg->cmd[1]);
	if (arg->cmd[1][0] == '-')
		pos = 1;
	if (ft_strlen(arg->cmd[1]) > (size_t)(19 + pos) || is_llint(arg->cmd[1], \
	"", pos) == -1 || check_is_numeric_arg(arg->cmd[1]) == -1 || \
	arg->cmd[1][0] == '\0')
		p_exit(arg, env, export, is_pipe);
	if (arg->cmd[2] != NULL)
		return (p_exit_args(is_pipe));
	if (pos == -1)
		exit_code -= 256;
	exit_code = ft_atoll(arg->cmd[1]);
	if (arg->cmd[1] == NULL)
		exit_code = 0;
	free_lists(&arg, &env, &export);
	print_exit_if_not_piped(is_pipe);
	exit(exit_code % 256);
}

static int	check_is_numeric_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

static long long int	exit_check_arg(char *str)
{
	long long int	value;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (2);
		i++;
	}
	value = ft_atoll(str);
	return (value);
}

static long long int	ft_atoll(char *str)
{
	int						i;
	int						sign;
	unsigned long long int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str[i])
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 9223372036854775807 && sign == 1)
			return (2);
		i++;
	}
	return (nbr * sign);
}

static int	is_llint(char *nb, char *set, int pos)
{
	if (pos == 1)
		set = "-9223372036854775808";
	else if (pos == 0)
		set = "9223372036854775807";
	while (set[pos])
	{
		if (nb[pos] < set[pos])
			return (0);
		else if (nb[pos] == set[pos])
			pos++;
		else
			return (-1);
	}
	return (0);
}
