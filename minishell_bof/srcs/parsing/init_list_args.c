/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:37:53 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/15 13:29:25 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_args	*new_arg_node(char *arg, int *i);
static void		lstaddback_arg_node(t_args *list_arg, t_args *new);
static void		assign_arg_list_len(t_args *lst_arg);
static int		arg_list_len(t_args	*lst_args);

t_args	*get_args_list(char	*arg)
{
	int		i;
	t_args	*list_arg;
	t_args	*new;

	i = 0;
	list_arg = NULL;
	new = new_arg_node(arg, &i);
	list_arg = new;
	while (arg[i])
	{
		if (arg[i] == ' ')
			skip_isspaces(arg, &i);
		if (arg[i] == '|')
			i++;
		new = new_arg_node(arg, &i);
		if (!new)
		{
			free_arg_list(&list_arg);
			return (NULL);
		}
		lstaddback_arg_node(list_arg, new);
	}
	assign_arg_list_len(list_arg);
	free(arg);
	return (list_arg);
}

static t_args	*new_arg_node(char *arg, int *i)
{
	t_args	*new;
	int		j;

	new = malloc(sizeof(t_args));
	if (!new)
		return (NULL);
	if (arg[*i] == ' ')
		skip_isspaces(arg, i);
	j = *i;
	new->cmd = get_cmd_tab(arg, &j);
	j = *i;
	new->delimiter = get_redir_tab(arg, &j);
	new->token = get_token_tab(arg, i);
	new->lst_len = 0;
	new->next = NULL;
	return (new);
}

static void	lstaddback_arg_node(t_args *list_arg, t_args *new)
{
	t_args	*list;

	if (!list_arg)
	{
		list_arg = new;
		return ;
	}
	list = list_arg;
	while (list->next)
		list = list->next;
	list->next = new;
}

static void	assign_arg_list_len(t_args *lst_arg)
{
	int		max;
	t_args	*tmp;

	tmp = lst_arg;
	max = (arg_list_len(lst_arg) - 1);
	while (lst_arg)
	{
		lst_arg->lst_len = max;
		lst_arg = lst_arg->next;
	}
	lst_arg = tmp;
}

static int	arg_list_len(t_args	*lst_args)
{
	int	i;

	i = 0;
	while (lst_args)
	{
		lst_args = lst_args->next;
		i++;
	}
	return (i);
}
