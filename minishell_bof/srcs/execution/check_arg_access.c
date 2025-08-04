/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:39:58 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/17 13:00:21 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*check_access(char *cmd, int i, char **path_tab);
static char	*check_is_executable(char *cmd);
static void	reset_filename(char **filename);
static void	check_access_error(int exit_code, char *cmd, char *msg);

char	*get_arg(t_env *lst_env, char *cmd)
{
	char	*path;
	char	*filename;
	char	**path_tab;

	if (!cmd)
		return (NULL);
	if (cmd[0] == '.' || cmd[0] == '/')
	{
		filename = check_is_executable(cmd);
		return (filename);
	}
	path = get_value(&lst_env, "PATH");
	path_tab = ft_split(path, ':');
	free(path);
	filename = check_access(cmd, 0, path_tab);
	return (filename);
}

static char	*check_is_executable(char *cmd)
{
	int	fd;

	fd = open(cmd, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		check_access_error(126, cmd, ": Is a directory\n");
	}
	else if (access(cmd, X_OK | F_OK) == 0)
		return (ft_strdup(cmd));
	else if ((access(cmd, F_OK) < 0))
		check_access_error(127, cmd, ": No such file or directory\n");
	else
		check_access_error(126, cmd, ": Permission denied\n");
	return (NULL);
}

static char	*check_access(char *cmd, int i, char **path_tab)
{
	char	*filename;
	int		fd;

	filename = NULL;
	filename = ft_strjoin(filename, cmd);
	fd = open(filename, O_DIRECTORY);
	while (path_tab && path_tab[i] && fd < 0)
	{
		if (access(filename, F_OK | X_OK) == 0)
		{
			free_tab_index(path_tab, (i));
			return (filename);
		}
		reset_filename(&filename);
		filename = ft_strjoin(path_tab[i], "/");
		filename = ft_strjoin(filename, cmd);
		fd = open(filename, O_DIRECTORY);
		i++;
	}
	if (fd >= 0)
		close(fd);
	check_access_error(127, cmd, ": command not found\n");
	reset_filename(&filename);
	free_tab_index(path_tab, i);
	return (NULL);
}

static void	check_access_error(int exit_code, char *cmd, char *msg)
{
	g_status->exit_code = exit_code;
	ft_putstr_fd("Mickey: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(msg, 2);
}

static void	reset_filename(char **filename)
{
	free(*filename);
	*filename = NULL;
}
