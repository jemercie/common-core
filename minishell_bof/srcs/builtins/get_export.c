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

static void	free_node(char *s1, char *s2, t_env *tmp);

t_env	*get_export_list(t_env *env)
{
	t_env	*tmp;
	t_env	*export;
	t_env	*new;

	tmp = env;
	export = new_env_node("AA=AA");
	while (tmp)
	{
		if (!(tmp->name[0] == '_') && tmp->name[1])
		{
			new = new_export_node(tmp);
			if (!new)
			{
				free_env_list(&export);
				return (NULL);
			}
			lstadd_export_node(export, new);
		}
		tmp = tmp->next;
	}
	tmp = export;
	export = export->next;
	free_node(tmp->name, tmp->value, tmp);
	return (export);
}

void	lstadd_export_node(t_env *env, t_env *new)
{
	t_env	*tmp;
	int		len;

	tmp = env;
	while (tmp)
	{
		if (tmp->next)
		{
			len = ft_strlen(new->name) + 1;
			if (ft_strncmp(new->name, tmp->next->name, len) > 0)
				tmp = tmp->next;
			else
			{
				new->next = tmp->next;
				tmp->next = new;
				return ;
			}	
		}
		else
		{
			tmp->next = new;
			return ;
		}
	}
}

t_env	*new_export_node(t_env *env)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = ft_strdup(env->name);
	if (new->name == NULL)
		return (NULL);
	new->value = ft_strdup(env->value);
	new->next = NULL;
	return (new);
}

static void	free_node(char *s1, char *s2, t_env *tmp)
{
	free(s1);
	free(s2);
	free(tmp);
}
