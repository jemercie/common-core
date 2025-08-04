/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_tab_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:57:36 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/15 10:40:10 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_args(char	*arg, int *j)
{
	int	i;
	int	len;

	i = *j;
	len = 0;
	while (arg[i] && arg[i] != '|')
	{
		if (arg[i] == '<' || arg[i] == '>')
			skip_redirections(arg, &i);
		else if (arg[i] && (arg[i] == '\'' || arg[i] == '\"'))
		{
			skipkot(arg, &i, arg[i]);
			len++;
		}
		else
		{
			skip_arg(arg, &i);
			len++;
		}
		if (arg[i] == ' ')
			skip_isspaces(arg, &i);
	}
	return (len);
}

void	skip_arg(char	*arg, int *i)
{
	while (arg[*i])
	{
		if (arg[*i] == ' ' || ft_is_redirection(arg[*i]) < 0 || arg[*i] == '|')
			return ;
		else if (arg[*i] == '\"' || arg[*i] == '\"')
			skipkot(arg, i, arg[*i]);
		else
			++*i;
	}
}

void	skip_redirections(char	*arg, int *i)
{
	++*i;
	if (arg[*i] && arg[*i] == '<')
	{
		--*i;
		skip_heredoc_delimiter(arg, i);
		return ;
	}
	if (arg[*i] && arg[*i] == '>')
		++*i;
	if (arg[*i] && arg[*i] == ' ')
		skip_isspaces(arg, i);
	while (arg[*i])
	{
		if (arg[*i] == ' ' || ft_is_redirection(arg[*i]) < 0 || arg[*i] == '|')
			return ;
		else if (arg[*i] == '\'' || arg[*i] == '\"')
			skipkot(arg, i, arg[*i]);
		else
			++*i;
	}
}
