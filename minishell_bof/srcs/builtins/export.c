/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:17:48 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/18 21:16:16 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_export_format(char *arg, t_env **export);
static void	free_and_replace_value(t_env **env, char *arg, int add);
static int	is_env_value_set_export(t_env **env, char *arg_name, int add);

void	ft_export(t_env **env, t_env **export, char **arg)
{
	int		i;
	int		ret;

	i = 1;
	if (!arg[i])
		print_export_list(export);
	while (arg[i])
	{
		ret = check_export_format(arg[i], export);
		if (ret >= 0)
		{
			if (is_env_value_set_export(env, arg[i], ret) == 0)
				free_and_replace_value(env, arg[i], ret);
			else
				get_new_node(env, arg[i], ret);
			if (is_env_value_set_export(export, arg[i], ret) == 0)
				free_and_replace_value(export, arg[i], ret);
			else
				get_new_export_node(export, arg[i], ret);
			g_status->exit_code = 0;
		}
		i++;
	}
}

static int	check_export_format(char *arg, t_env **export)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
		return (err(1, "Mickey: export: `", &arg[i], \
		"': not a valid identifier\n"));
	while (arg[i] && arg[i] != ' ')
	{
		if (arg[i] == '\'' || arg[i] == '\"')
			skipkot(arg, &i, arg[i]);
		else if (ft_isalnum(arg[i]) != 8 && arg[i] != '_')
			return \
			(err(1, "Mickey: export: `", &arg[i], \
			"': not a valid identifier\n"));
		i++;
		if (arg[i] == '=' && i != 0)
			return (0);
		if (arg[i] && arg[i + 1] && arg[i] == '+' && arg[i + 1] == '=' \
		&& i != 0)
			return (2);
	}
	if (is_export_name_set(export, arg) < 0)
		get_new_export_invalid_node(export, arg);
	return (-1);
}

static int	is_env_value_set_export(t_env **env, char *arg_name, int add)
{
	t_env	*tmp;
	char	*name;

	name = which_dup_name(arg_name, add);
	tmp = (*env);
	while (tmp)
	{
		if (ft_cmp(name, tmp->name) == 0)
		{
			free(name);
			return (0);
		}
		tmp = tmp->next;
	}
	free(name);
	return (-1);
}

void	free_and_replace_value(t_env **env, char *arg, int add)
{
	t_env	*tmp;
	char	*name;

	name = which_dup_name(arg, add);
	tmp = (*env);
	while (tmp)
	{
		if (ft_cmp(name, tmp->name) == 0)
		{
			if (add == 2)
				tmp->value = ft_strjoin_unset(tmp->value, dup_value(arg));
			else
			{
				if (tmp->value)
					free(tmp->value);
				tmp->value = dup_value(arg);
			}
			free(name);
			return ;
		}
		tmp = tmp->next;
	}
	free(name);
}

char	*dup_add_name(const char *str)
{
	int		i;
	char	*dup;

	dup = NULL;
	i = 0;
	while (str[i] && str[i] != '+')
		i++;
	if (str[i] != '+')
		return (NULL);
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '+')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
