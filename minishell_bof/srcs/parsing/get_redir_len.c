/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:47:55 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/08 17:40:08 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*copy_str(char *str, char *redir, int *i);

int	count_char_redir(int *count, char *s, int *i)
{
	int		tmp;

	tmp = *i;
	while (s[tmp] && ft_isspace(s[tmp]) != 1 && s[tmp] != '|')
	{
		if (s[tmp] && ft_isspace(s[tmp]) != 1 && s[tmp] != '|'
			&& s[tmp] != '\"' && s[tmp] != '\'')
			(*count)++;
		else if (s[tmp] && (s[tmp] == '\"' || s[tmp] == '\''))
			find_next_quote(s, &tmp, count, s[tmp]);
		if (s[tmp + 1])
			tmp++;
		else
			return ((*count));
	}
	return ((*count));
}

int	get_next_redir(char *str, int *i)
{
	int		count;

	count = 0;
	while (str[*i])
	{
		if (str[*i] == '|')
			return (count);
		if (str[*i] == '\'' || str[*i] == '\"')
			skip_quote(str, i, str[(*i)]);
		if ((str[*i] == '<' || str[*i] == '>') && str[*i + 1] != '\0')
		{
			while (ft_is_metaspace(str[*i]) == 1)
				(*i)++;
			if (count_char_redir(&count, str, i) > -1)
				return (count);
		}
		(*i)++;
	}
	return (count);
}

char	*get_redir_str(char	*str, int *i)
{
	char	*redir;
	int		len;

	len = get_next_redir(str, i);
	redir = ft_calloc(sizeof(char), (len + 1));
	if (!redir)
		return (NULL);
	while (str[(*i)] && str[(*i)] != '|')
	{
		while (ft_is_metaspace(str[*i]) == 1)
			(*i)++;
		redir = copy_str(str, redir, i);
		break ;
	}
	return (redir);
}

static char	*copy_str(char *str, char *redir, int *i)
{
	int		tmp;

	tmp = 0;
	while (str[(*i)] && str[(*i)] != '|')
	{
		if (str[(*i)] == '\'' || str[(*i)] == '\"')
			skipcopy_str(str, redir, i, &tmp);
		else if (str[(*i)] == '\0' || str[(*i)] == '|' || str[(*i)] == ' ')
			break ;
		else if (str[(*i)] && str[(*i)] != '\'' && str[(*i)] != '\"')
			char_copy(str, redir, &tmp, i);
	}
	return (redir);
}

char	**get_redir_tab(char *str, int *i)
{
	int		tmp;
	int		len;
	char	**redir;
	int		j;

	tmp = (*i);
	len = get_redir(str, i);
	redir = NULL;
	redir = ft_calloc(sizeof(char *), (len + 1));
	if (!redir)
		return (NULL);
	j = 0;
	while (j < len)
	{
		redir[j] = get_redir_str(str, &tmp);
		j++;
	}
	redir[j] = NULL;
	return (redir);
}
