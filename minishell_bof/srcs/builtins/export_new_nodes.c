/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_new_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:08:21 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/19 12:33:08 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_env	*new_unset_node(char *str, int add);
static t_env	*new_export_invalid_node(char *str);

void	get_new_node(t_env **list, char *arg, int add)
{
	t_env	*new;

	new = new_unset_node(arg, add);
	if (!new)
		return ;
	if (*list == NULL)
		(*list) = new;
	lstaddback_env_node(*list, new);
}

void	get_new_export_node(t_env **list, char *arg, int add)
{
	t_env	*new;

	new = new_unset_node(arg, add);
	if (!new)
		return ;
	if (*list == NULL)
		(*list) = new;
	lstadd_export_node((*list), new);
}

static t_env	*new_unset_node(char *str, int add)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	if (add == 2)
		new->name = dup_add_name(str);
	else
		new->name = dup_name(str);
	if (new->name == NULL)
		return (NULL);
	new->value = dup_value(str);
	new->next = NULL;
	return (new);
}

void	get_new_export_invalid_node(t_env **list, char *arg)
{
	t_env	*new;

	if (ft_cmp("PWD", arg) == 0)
		check_if_unset(0, 3);
	if (ft_cmp("OLDPWD", arg) == 0)
		check_if_unset(0, 4);
	new = new_export_invalid_node(arg);
	if (!new)
		return ;
	if (*list == NULL)
		(*list) = new;
	lstadd_export_node(*list, new);
}

static t_env	*new_export_invalid_node(char *str)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = ft_strdup(str);
	if (new->name == NULL)
		return (NULL);
	new->value = NULL;
	new->next = NULL;
	return (new);
}
