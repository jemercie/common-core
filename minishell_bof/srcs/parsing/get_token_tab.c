/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:47:55 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/08 17:34:17 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	set_token(char *line, int *i)
{
	int	token;

	token = 0;
	if (line[(*i)] && line[(*i)] == '<'
		&& line[(*i + 1)] && line[(*i + 1)] == '<')
		token = HEREDOC;
	else if (line[(*i)] && line[(*i)] == '>'
		&& line[(*i + 1)] && line[(*i + 1)] == '>')
		token = APPEND;
	else if (line[(*i)] && line[(*i)] == '>')
		token = OUTFILE;
	else if (line[(*i)] && line[(*i)] == '<')
		token = INFILE;
	if (line[(*i)] && line[(*i + 1)]
		&& ((line[(*i)] == '<' && line[(*i + 1)] == '<')
			|| (line[(*i)] == '>' && line[(*i + 1)] == '>')))
		(*i) += 2;
	else if (line[(*i)] && (line[(*i)] == '>' || line[(*i)] == '<'))
		(*i)++;
	return (token);
}

int	get_next_token(char *line, int *i)
{
	int	token;

	token = 0;
	while (line[(*i)] && line[(*i)] != '|')
	{
		if (line[(*i)] == '<' || line[(*i)] == '>')
		{
			token = set_token(line, i);
			return (token);
		}
		if (line[(*i)] == '\'' || line[(*i)] == '\"')
			skip_quote(line, i, line[(*i)]);
		(*i)++;
	}
	return (token);
}

int	count_redir(int *count, char *line, int i)
{
	int	j;

	j = i + 1;
	if (line[i] && line[i] == '<' && line[j] && line[j] == '<')
		++*count;
	else if (line[i] && line[i] == '>' && line[j] && line[j] == '>')
		++*count;
	else if (line[i] && line[i] == '>')
		++*count;
	else if (line[i] && line[i] == '<')
		++*count;
	if (line[i] && line[j] && ((line[i] == '<' && line[j] == '<')
			|| (line[i] == '>' && line[j] == '>')))
		i += 2;
	else if (line[i] && (line[i] == '>' || line[i] == '<'))
		i++;
	return (i);
}

int	get_redir(char *str, int *i)
{
	int		count;

	count = 0;
	while (str[*i])
	{
		if (str[*i] == '|')
			return (count);
		if ((str[*i] == '<' || str[*i] == '>') && str[*i + 1] != '\0')
			*i = count_redir(&count, str, *i);
		if ((str[*i] == '\'') || (str[*i] == '\"'))
			skip_quote(str, i, str[(*i)]);
		(*i)++;
	}
	return (count);
}

int	*get_token_tab(char *str, int *i)
{
	int	j;
	int	*tab;
	int	len;
	int	tmp;

	tmp = *i;
	j = 0;
	len = get_redir(str, i);
	if (len == 0)
		return (NULL);
	tab = NULL;
	tab = malloc(sizeof(int) * (len + 1));
	if (!tab)
		return (NULL);
	while (j < len)
	{
		tab[j] = get_next_token(str, &tmp);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
