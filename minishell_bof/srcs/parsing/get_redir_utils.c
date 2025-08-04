/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:23:11 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/08 17:40:19 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_metaspace(int c)
{
	if (c == ' ' || c == '>' || c == '<' || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

int	skip_quote(char *str, int *i, char c)
{
	(*i)++;
	while (str[*i] && str[*i] != c)
		(*i)++;
	if (!str[*i])
		return (1);
	else
		return (0);
}

void	find_next_quote(char *str, int *i, int *count, char c)
{
	(*i)++;
	if (str[(*i)] == c)
		return ;
	while (str[(*i)] != '\0' && str[(*i)] != c)
	{
		(*count)++;
		(*i)++;
	}
	return ;
}

void	skipcopy_str(char *str, char *redir, int *i, int *tmp)
{
	char	c;

	c = str[(*i)];
	(*i)++;
	if (str[(*i)] == c)
	{
		(*i)++;
		return ;
	}
	while (str[(*i)] != c)
	{
		char_copy(str, redir, tmp, i);
		if (str[(*i)] == c)
		{
			(*i)++;
			return ;
		}
	}
	return ;
}
