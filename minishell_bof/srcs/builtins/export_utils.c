/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:30:31 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/19 12:32:58 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_export_name_set(t_env **env, char *name)
{
	t_env	*tmp;
	int		len;

	len = ft_strlen(name);
	tmp = (*env);
	while (tmp)
	{
		if (ft_strncmp(name, tmp->name, len + 1) == 0 && !tmp->name[len])
			return (0);
		tmp = tmp->next;
	}
	return (-1);
}

int	is_env_value_set(t_env **env, char *arg_name)
{
	t_env	*tmp;
	int		len;

	tmp = (*env);
	len = ft_strlen(arg_name);
	while (tmp)
	{
		if (ft_cmp(arg_name, tmp->name) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (-1);
}

char	*which_dup_name(char *arg, int add)
{
	char	*name;

	if (add == 2)
		name = dup_add_name(arg);
	else
		name = dup_name(arg);
	return (name);
}
