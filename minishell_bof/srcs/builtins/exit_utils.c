/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:33:59 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/09 19:42:49 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	p_exit(t_args *arg, t_env *env, t_env *e, int is_pipe)
{
	print_exit_if_not_piped(is_pipe);
	write(2, "Mickey: exit: ", 14);
	write(2, arg->cmd[1], ft_strlen(arg->cmd[1]));
	write(2, ": numeric argument required\n", 28);
	free_lists (&arg, &env, &e);
	exit(2);
}

int	p_exit_args(int is_pipe)
{
	print_exit_if_not_piped(is_pipe);
	write(2, "Mickey: exit: too many arguments\n", 33);
	g_status->exit_code = 1;
	return (0);
}

void	print_exit_if_not_piped(int is_pipe)
{
	if (is_pipe == 0)
		write(1, "exit\n", 5);
}

void	exit_no_args(t_args *arg, t_env *env, t_env *export, int is_pipe)
{
	print_exit_if_not_piped(is_pipe);
	free_lists(&arg, &env, &export);
	exit(g_status->exit_code);
}
