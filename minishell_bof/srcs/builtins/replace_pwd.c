/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:39:12 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/17 19:26:59 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_env	*new_cd_env_node(char *new_name, char *new_value);
static void		replace_value(t_env *tmp, char *str, int *flag);

void	replace_export(char *pwd, char *old_pwd, t_env **export)
{
	t_env	*tmp;
	int		mouse;
	int		rat;

	tmp = (*export);
	mouse = 0;
	rat = 0;
	while (tmp)
	{
		if (ft_cmp("OLDPWD", tmp->name) == 0)
			replace_value(tmp, ft_strdup(old_pwd), &mouse);
		else if (ft_cmp("PWD", tmp->name) == 0)
			replace_value(tmp, ft_strdup(pwd), &rat);
		tmp = tmp->next;
	}
	if (mouse == 0 && check_if_unset(0, 2) == 0)
	{
		tmp = new_cd_env_node("OLDPWD", ft_strdup(old_pwd));
		lstadd_export_node((*export), tmp);
	}
	if (rat == 0 && check_if_unset(0, 1) == 0)
	{
		tmp = new_cd_env_node("PWD", ft_strdup(pwd));
		lstadd_export_node((*export), tmp);
	}
}

void	replace_env(char *pwd, char *old_pwd, t_env **env)
{
	t_env	*tmp;
	int		mouse;
	int		rat;

	tmp = (*env);
	mouse = 0;
	rat = 0;
	while (tmp)
	{
		if (ft_cmp("OLDPWD", tmp->name) == 0)
			replace_value(tmp, ft_strdup(old_pwd), &mouse);
		else if (ft_cmp("PWD", tmp->name) == 0)
			replace_value(tmp, ft_strdup(pwd), &rat);
		tmp = tmp->next;
	}
	if (mouse == 0 && check_if_unset(0, 2) == 0)
	{
		tmp = new_cd_env_node("OLDPWD", ft_strdup(old_pwd));
		lstaddback_env_node((*env), tmp);
	}
	if (rat == 0 && check_if_unset(0, 1) == 0)
	{
		tmp = new_cd_env_node("PWD", ft_strdup(pwd));
		lstaddback_env_node((*env), tmp);
	}
}

static void	replace_value(t_env *tmp, char *str, int *flag)
{
	free(tmp->value);
	tmp->value = str;
	*flag = 1;
}

static t_env	*new_cd_env_node(char *new_name, char *new_value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = ft_strdup(new_name);
	if (new->name == NULL)
		return (NULL);
	new->value = new_value;
	new->next = NULL;
	return (new);
}

int	ft_cmp(char *str1, char *str2)
{
	int	len1;
	int	len2;
	int	i;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 != len2)
		return (-1);
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}
