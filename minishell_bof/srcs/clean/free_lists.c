/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc_env_lists.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:25:19 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/17 11:25:43 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_lists(t_args **lst_args, t_env **lst_env, t_env **export)
{
	if (*lst_env)
		free_env_list(lst_env);
	if (*export)
		free_env_list(export);
	if (*lst_args)
		free_arg_list(lst_args);
}

void	free_env_list(t_env **lst_env)
{
	t_env	*list;

	list = NULL;
	if (!(*lst_env))
		return ;
	list = (*lst_env);
	while (list)
	{
		*lst_env = (*lst_env)->next;
		if (list->name)
			free(list->name);
		if (list->value)
			free(list->value);
		free(list);
		list = *lst_env;
	}
	free(*lst_env);
	*lst_env = NULL;
}

void	free_arg_node(t_args **lst_arg)
{
	t_args	*node;

	node = NULL;
	if (!(*lst_arg))
		return ;
	node = (*lst_arg);
	*lst_arg = (*lst_arg)->next;
	if (node->cmd)
		free_tab(node->cmd);
	if (node->delimiter)
		free_tab(node->delimiter);
	if (node->token)
		free(node->token);
	free(node);
}

void	free_arg_list(t_args **lst_arg)
{
	t_args	*list;

	list = NULL;
	if (!(*lst_arg))
		return ;
	list = (*lst_arg);
	while (list)
	{
		*lst_arg = (*lst_arg)->next;
		if (list->cmd)
			free_tab(list->cmd);
		if (list->delimiter)
			free_tab(list->delimiter);
		if (list->token)
			free(list->token);
		if (list)
			free(list);
		list = *lst_arg;
	}
	free(*lst_arg);
	*lst_arg = NULL;
}

void	free_and_exit(t_args **lst_arg, t_env **lst_env, t_env **export)
{
	free_lists(lst_arg, lst_env, export);
	exit (g_status->exit_code);
}
