/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:57:11 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/28 16:35:03 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*get_the_arg(char *arg, int *i);
static char	*copy_quote_content(char *arg, char *newstr, int *i, int *j);
static int	get_arg_len(char *arg, int i);

char	**get_cmd_tab(char *arg, int *i)
{
	int		len;
	char	**cmd;
	int		j;

	cmd = NULL;
	len = count_args(arg, i);
	cmd = malloc(sizeof(char *) * (len + 1));
	if (!cmd)
		return (NULL);
	j = 0;
	while ((arg[*i] || j < len) && arg[*i] != '|')
	{
		if (arg[*i] == '<' || arg[*i] == '>')
			skip_redirections(arg, i);
		else
		{
			cmd[j] = get_the_arg(arg, i);
			j++;
		}
		if (arg[*i] == ' ')
			skip_isspaces(arg, i);
	}
	cmd[j] = NULL;
	return (cmd);
}

static char	*get_the_arg(char *arg, int *i)
{
	char	*newstr;
	int		len;
	int		j;

	j = 0;
	len = get_arg_len(arg, *i);
	newstr = malloc(sizeof(char) * (len + 1));
	while (arg[*i])
	{
		if (arg[*i] == ' ' || ft_is_redirection(arg[*i]) < 0 || arg[*i] == '|')
		{
			newstr[j] = '\0';
			return (newstr);
		}
		else if (arg[*i] == '\'' || arg[*i] == '\"')
			newstr = copy_quote_content(arg, newstr, i, &j);
		else
		{
			newstr[j] = arg[*i];
			j++;
			++*i;
		}
	}
	newstr[j] = '\0';
	return (newstr);
}

static char	*copy_quote_content(char *arg, char *newstr, int *i, int *j)
{
	char	c;

	c = arg[*i];
	++*i;
	if (arg[*i] == c)
		newstr[*j] = '\0';
	while (arg[*i] && arg[*i] != c)
	{
		newstr[*j] = arg[*i];
		++*j;
		++*i;
	}
	++*i;
	return (newstr);
}

static int	get_arg_len(char *arg, int i)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (arg[i])
	{
		if (arg[i] == ' ' || ft_is_redirection(arg[i]) < 0 || arg[i] == '|')
			return (len);
		else if (arg[i] == '\'' || arg[i] == '\"')
			len += skipkot(arg, &i, arg[i]);
		else if (arg[i])
		{
			len++;
			i++;
		}
	}
	return (len);
}
