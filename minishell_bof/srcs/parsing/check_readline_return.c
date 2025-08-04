/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_readline_return.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:13:37 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/18 20:42:00 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_quotes(char *arg);
static int	check_start_end(char *arg);
static int	check_redirections(char *arg);
static int	check_consecutive_metacharacters(char *arg, int i);

int	check_readline_return(char *arg)
{
	if (check_quotes(arg) < 0)
	{
		printf("Mickey: syntax error, close your quote pls\n");
		g_status->exit_code = 2;
		return (-1);
	}
	else if (check_heredoc_number(arg) < 0)
	{
		printf("Mickey: maximum here-document count exceeded\n");
		g_status->exit_code = 2;
		return (-2);
	}
	else if (check_redirections(arg) < 0 || check_start_end(arg) < 0)
		return (-1);
	return (0);
}

static int	check_quotes(char *arg)
{
	int		i;
	char	quote;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\'' || arg[i] == '\"')
		{
			quote = arg[i];
			i++;
			if (!arg[i])
				return (-1);
			while (arg[i] && arg[i] != quote)
			{
				i++;
				if (!arg[i])
					return (-1);
			}
		}
		i++;
	}
	return (0);
}

static int	check_redirections(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\'' || arg[i] == '\"')
		{
			skipkot(arg, &i, arg[i]);
			if (!arg[i])
				return (0);
		}
		else if (arg[i] == '|' || arg[i] == '>' || arg[i] == '<')
		{
			if (check_consecutive_metacharacters(arg, i) < 0)
				return (-1);
		}
		i++;
	}
	return (0);
}

static int	check_start_end(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && ft_isspace(arg[i]) == 1)
		i++;
	if (!arg[i])
		return (0);
	if (arg[i] == '|')
	{
		printf("Mickey: syntax error near unexpected token `%c'\n", arg[i]);
		return (-1);
	}
	while (arg[i])
		i++;
	i--;
	while (arg[i] && (ft_isspace(arg[i]) == 1 || arg[i] == '\n'))
		i--;
	if (arg[i] && ft_is_redirection(arg[i]) < 0)
	{
		printf("Mickey: syntax error near unexpected token `newline'\n");
		g_status->exit_code = 2;
		return (-1);
	}
	return (0);
}	

static int	check_consecutive_metacharacters(char *arg, int i)
{
	if (arg[i] && arg[i] == '|')
		i++;
	if (ft_isspace(arg[i]) == 1)
		skip_isspaces(arg, &i);
	if (arg[i] && arg[i] == '<')
	{
		i++;
		if (arg[i] && arg[i] == '<')
			i++;
	}
	else if (arg[i] && arg[i] == '>')
	{
		i++;
		if (arg[i] && arg[i] == '>')
			i++;
	}
	if (arg[i] && check_is_valid_arg_next(arg, i) < 0)
		return (-1);
	return (0);
}
