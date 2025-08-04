/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:28:41 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/03 15:32:11 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	execve_call(t_env *lst_env, t_args	*lst_args, t_env *export);
static void	builtins_or_execve(t_args *lst_arg, t_env *lst_env, t_env *export);
static int	open_close_pipes(int fd[2][2], int i);

int	*minishell(t_args *lst_arg, t_env *lst_env, int i, t_env *export)
{
	static int	fd[2][2];
	int			*pid;

	pid = malloc(sizeof(int) * (lst_arg->lst_len + 1));
	while (lst_arg)
	{
		open_close_pipes(fd, i);
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (lst_arg->cmd == NULL || open_and_dup(lst_arg, fd, i) < 0)
				free_and_exit(&lst_arg, &lst_env, &export);
			builtins_or_execve(lst_arg, lst_env, export);
		}
		free_arg_node(&lst_arg);
		i++;
		open_close_pipes(fd, i);
	}
	free_lst_close_all(&lst_arg, fd);
	return (pid);
}

int	not_fork_builtins(t_args *lst_arg, t_env *lst_env, t_env *export)
{
	int		builtin;

	builtin = which_builtin(lst_arg->cmd[0]);
	if (builtin == 2 || builtin == 4 || builtin == 5 || builtin == 7)
	{
		if (builtin == 2)
		{
			if (check_args_cd(lst_arg->cmd) == 0)
				ft_cd(&lst_env, &export, lst_arg->cmd[1]);
		}
		else if (builtin == 4)
			ft_export(&lst_env, &export, lst_arg->cmd);
		else if (builtin == 5)
			ft_unset(&lst_env, &export, lst_arg->cmd);
		else if (builtin == 7)
			ft_exit(lst_arg, lst_env, export, 0);
		return (0);
	}
	return (-1);
}

static void	builtins_or_execve(t_args *lst_arg, t_env *lst_env, t_env *export)
{
	int		builtin;

	builtin = which_builtin(lst_arg->cmd[0]);
	if (builtin < 0)
		execve_call(lst_env, lst_arg, export);
	else if (builtin == 1)
		ft_echo(lst_arg->cmd);
	else if (builtin == 2)
	{
		if (check_args_cd(lst_arg->cmd) == 0)
			ft_cd(&lst_env, &export, lst_arg->cmd[1]);
	}
	else if (builtin == 3)
		ft_pwd();
	else if (builtin == 4)
		ft_export(&lst_env, &export, lst_arg->cmd);
	else if (builtin == 5)
		ft_unset(&lst_env, &export, lst_arg->cmd);
	else if (builtin == 6)
		ft_env(&lst_env);
	else if (builtin == 7)
		ft_exit(lst_arg, lst_env, export, 1);
	free_and_exit(&lst_arg, &lst_env, &export);
}

static void	execve_call(t_env *lst_env, t_args *lst_args, t_env *export)
{
	char	*filename;
	char	**env;

	env = env_lst_to_tab(lst_env);
	filename = get_arg(lst_env, lst_args->cmd[0]);
	if (filename == NULL)
	{
		free_lists(&lst_args, &lst_env, &export);
		exit(g_status->exit_code);
	}
	free(lst_args->cmd[0]);
	lst_args->cmd[0] = filename;
	execve(filename, lst_args->cmd, env);
	g_status->exit_code = errno;
	free_lists(&lst_args, &lst_env, &export);
	exit(g_status->exit_code);
}

static int	open_close_pipes(int fd[2][2], int i)
{
	if (i == 0)
	{
		if (pipe(fd[0]) == -1)
			return (-1);
		if (pipe(fd[1]) == -1)
		{
			close_fd(fd[0]);
			return (-1);
		}
		return (0);
	}
	else if ((i % 2) == 1)
	{
		close_fd(fd[0]);
		if (pipe(fd[0]) == -1)
			return (-1);
	}
	else if ((i % 2) == 0)
	{
		close_fd(fd[1]);
		if (pipe(fd[1]) == -1)
			return (-1);
	}
	return (0);
}
