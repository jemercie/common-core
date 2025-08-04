/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_readline_return_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:43:37 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/09 19:52:30 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_is_valid_arg_next(char *arg, int i)
{
	while (arg[i] && ft_isspace(arg[i]) > 0)
		i++;
	if (ft_is_redirection(arg[i]) < 0)
	{
		printf("Mickey: syntax error near unexpected token `%c'\n", arg[i]);
		return (-1);
	}
	return (0);
}

int	check_heredoc_number(char *arg)
{
	int	i;
	int	heredoc_nb;

	i = 0;
	heredoc_nb = 0;
	while (arg[i])
	{
		if (arg[i] == '|')
			heredoc_nb = 0;
		if (arg[i] == '\'' || arg[i] == '\"')
			skipkot(arg, &i, arg[i]);
		else if (arg[i] && arg[i + 1] && arg[i] == '<' && arg[i + 1] == '<')
		{
			skip_heredoc_delimiter(arg, &i);
			heredoc_nb++;
		}
		else
			i++;
		if (heredoc_nb > 16)
			return (-1);
	}
	return (0);
}
