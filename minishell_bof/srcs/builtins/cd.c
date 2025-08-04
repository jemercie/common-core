/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:20:54 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/08 18:49:27 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

static char	*ft_get_old_pwd(t_env **env);
static void	print_error_path(char *path);

int	ft_cd(t_env **env, t_env **export, char *path)
{
	char	*old_pwd;
	char	*pwd;

	if (path == NULL || ft_strlen(path) == 0)
		return (0);
	old_pwd = ft_get_old_pwd(env);
	if (path && chdir(path))
	{
		free(old_pwd);
		print_error_path(path);
		return (1);
	}
	pwd = ft_calloc(4096, sizeof(char));
	if (pwd == NULL)
	{
		if (old_pwd)
			free(old_pwd);
		return (1);
	}
	getcwd(pwd, 4096);
	replace_export(pwd, old_pwd, export);
	replace_env(pwd, old_pwd, env);
	free(pwd);
	free(old_pwd);
	return (0);
}

int	check_if_unset(int i, int action)
{
	static int	pwd;
	static int	old_pwd;

	if (action == 1)
		return (pwd);
	else if (action == 2)
		return (old_pwd);
	if (action == 3)
		pwd = i;
	else if (action == 4)
		old_pwd = i;
	return (0);
}

static char	*ft_get_old_pwd(t_env **env)
{
	t_env	*tmp;
	char	*old_pwd;

	if (!(*env))
		return (NULL);
	old_pwd = NULL;
	tmp = (*env);
	while (tmp)
	{
		if (ft_cmp("PWD", tmp->name) == 0)
		{
			if (tmp->value)
			{
				old_pwd = ft_strdup(tmp->value);
				return (old_pwd);
			}
			else
				return (NULL);
		}
		tmp = tmp->next;
	}
	old_pwd = ft_calloc(4096, sizeof(char));
	getcwd(old_pwd, 4096);
	return (old_pwd);
}

static void	print_error_path(char *path)
{
	g_status->exit_code = 1;
	ft_putstr_fd("Mickey: cd:", 1);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(" No such file or directory\n", 2);
	return ;
}

int	check_args_cd(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	if (i > 2)
	{
		g_status->exit_code = 1;
		ft_putstr_fd("Mickey: cd: too many arguments\n", 2);
		return (1);
	}
	return (0);
}
