/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:45:14 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/13 14:46:15 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_env_list(t_env **env_list)
{
	t_env	*print_list;

	print_list = (*env_list)->next;
	while (print_list)
	{
		printf("%s=%s\n", print_list->name, print_list->value);
		print_list = print_list->next;
	}
}

void	print_arg_list(t_args	**list_arg)
{
	int	i;

	while ((*list_arg))
	{
		i = 0;
		while ((*list_arg)->cmd[i])
		{
			printf("cmd %d = %s\n", i, (*list_arg)->cmd[i]);
			i++;
		}
		i = 0;
		while ((*list_arg)->token[i] != 0)
		{
			printf("delimiter %d = %s\n", i, (*list_arg)->delimiter[i]);
			printf("token_lst = %d\n", (*list_arg)->token[i]);
			i++;
		}
		(*list_arg) = (*list_arg)->next;
	}
}

void	print_export_list(t_env **export)
{
	t_env	*print_list;

	print_list = (*export)->next;
	while (print_list)
	{
		if (print_list->value)
			printf("declare -x %s=\"%s\"\n", print_list->name, print_list->value);
		else
			printf("declare -x %s\n", print_list->name);
		print_list = print_list->next;
	}
}
