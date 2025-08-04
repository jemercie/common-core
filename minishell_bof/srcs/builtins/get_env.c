/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:01:54 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/04 18:17:33 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*get_env_list(char **env)
{
	t_env	*env_list;
	t_env	*new;
	int		i;

	i = 0;
	env_list = new_env_node("333=333");
	while (env[i])
	{
		new = new_env_node(env[i]);
		if (!new)
		{
			free_env_list(&env_list);
			return (NULL);
		}
		lstaddback_env_node(env_list, new);
		i++;
	}
	return (env_list);
}

void	lstaddback_env_node(t_env *env_list, t_env *new)
{
	t_env	*list;

	list = env_list;
	if (! env_list)
	{
		env_list = new;
		return ;
	}
	list = env_list;
	while (list->next)
		list = list->next;
	list->next = new;
}

t_env	*new_env_node(char *str)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = dup_name(str);
	if (new->name == NULL)
		return (NULL);
	new->value = dup_value(str);
	new->next = NULL;
	return (new);
}

char	*dup_name(const char *str)
{
	int		i;
	char	*dup;

	dup = NULL;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] != '=')
		return (NULL);
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*dup_value(const char *str)
{
	int		i;
	int		j;
	char	*dup;

	dup = NULL;
	j = 0;
	i = 0;
	while (str[i] != '=')
		i++;
	i += 1;
	while (str[i + j])
		j++;
	dup = malloc(sizeof(char) * (j + 1));
	if (!dup)
		return (NULL);
	j = 0;
	while (str[i] && str[i + j])
	{
		dup[j] = str[i + j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
