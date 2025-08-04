/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:16:38 by dafranco          #+#    #+#             */
/*   Updated: 2023/04/24 20:29:40 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_option(char *arg);
static void	ft_putstr_space(char *str);

int	ft_echo(char **args)
{
	int	i;
	int	noline;

	noline = 0;
	i = 1;
	while (args[i] && check_option(args[i]))
	{
		noline = 1;
		i++;
	}
	if (!args[i])
	{
		if (noline == 0)
			ft_printf("\n");
		return (0);
	}
	while (args[i + 1])
	{
		ft_putstr_space(args[i]);
		i++;
	}
	ft_putstr_fd(args[i], 1);
	if (noline == 0)
		ft_printf("\n");
	return (0);
}

static void	ft_putstr_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
}

static int	check_option(char *arg)
{
	size_t	i;

	i = 1;
	if (arg[0] == '-')
	{
		while (arg[i] && arg[i] == 'n')
			i++;
		if (i == ft_strlen(arg) && i > 1)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
