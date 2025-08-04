/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:05:54 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/13 16:08:37 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	skip_isspaces(char	*arg, int *i)
{
	while (arg[*i] && ft_isspace(arg[*i]) > 0)
			++*i;
}

int	skipkot(char *str, int *i, char c)
{
	int	len;

	len = 0;
	++*i;
	while (str[*i] && str[*i] != c)
	{
		len++;
		++*i;
	}
	++*i;
	return (len);
}

int	ft_is_redirection(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (-1);
	return (0);
}

char	*copy_heredoc_delimiter(char *arg, char *newstr, int *j, int *i)
{
	char	c;

	newstr = char_copy(arg, newstr, j, i);
	newstr = char_copy(arg, newstr, j, i);
	while (arg[*i] && ft_isspace(arg[*i]) > 0)
			newstr = char_copy(arg, newstr, j, i);
	while (arg[*i])
	{
		if (arg[*i] && arg[*i] == ' ')
			return (newstr);
		else if (arg[*i] && (arg[*i] == '\'' || arg[*i] == '\"'))
		{
			c = arg[*i];
			newstr = char_copy(arg, newstr, j, i);
			while (arg[*i] && arg[*i] != c)
				newstr = char_copy(arg, newstr, j, i);
			newstr = char_copy(arg, newstr, j, i);
		}
		else if (arg[*i])
			newstr = char_copy(arg, newstr, j, i);
	}
	return (newstr);
}
