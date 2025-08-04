/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:33:30 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/09 12:37:41 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	unset_env(t_env **env, char *arg);
static void	unset_export(t_env **export, char *arg);
static int	check_unset(char *arg);

void	ft_unset(t_env **env, t_env **export, char	**arg)
{
	int	i;

	i = 1;
	if (arg[i] == NULL)
		return ;
	while (arg[i])
	{
		if (check_unset(arg[i]) == 0)
		{
			unset_env(env, arg[i]);
			unset_export(export, arg[i]);
		}
		i++;
	}
}

static void	unset_env(t_env **env, char *arg)
{
	t_env	*ret;
	t_env	*tmp;

	ret = (*env);
	if (ft_cmp(arg, "PWD") == 0)
		check_if_unset(1, 3);
	if (ft_cmp(arg, "OLDPWD") == 0)
		check_if_unset(1, 4);
	while ((*env) && (*env)->next)
	{
		if (arg[0] != '_' && arg[1] && ft_cmp((*env)->next->name, arg) == 0)
		{
			tmp = (*env)->next->next;
			free((*env)->next->name);
			if ((*env)->next->value)
				free((*env)->next->value);
			free((*env)->next);
			(*env)->next = tmp;
			(*env) = ret;
			return ;
		}
		(*env) = (*env)->next;
	}
	(*env) = ret;
}

static void	unset_export(t_env **export, char *arg)
{
	t_env	*ret;
	t_env	*tmp;

	ret = (*export);
	if (ft_cmp(arg, "PWD") == 0)
		check_if_unset(1, 3);
	if (ft_cmp(arg, "OLDPWD") == 0)
		check_if_unset(1, 4);
	while ((*export) && (*export)->next)
	{
		if (ft_cmp((*export)->next->name, arg) == 0)
		{
			tmp = (*export)->next->next;
			free((*export)->next->name);
			if ((*export)->next->value)
				free((*export)->next->value);
			free((*export)->next);
			(*export)->next = tmp;
			(*export) = ret;
			return ;
		}
		(*export) = (*export)->next;
	}
	(*export) = ret;
}

static int	check_unset(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
		return (err(1, "Mickey: unset: `", arg, \
		"': not a valid identifier\n"));
	while (arg[i])
	{
		if (ft_isalnum(arg[i]) != 8 && arg[i] != '_')
			return (err(1, "Mickey: unset: `", arg, \
			"': not a valid identifier\n"));
		i++;
	}
	return (0);
}

int	err(int code, char *name, char *arg, char *msg)
{
	if (name)
		ft_putstr_fd(name, 2);
	if (arg)
		ft_putstr_fd(arg, 2);
	if (msg)
		ft_putstr_fd(msg, 2);
	g_status->exit_code = code;
	return (-1);
}
