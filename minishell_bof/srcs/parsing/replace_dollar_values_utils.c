/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nb_of_dollar_values.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:21:19 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/20 16:30:14 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	skip_dollar_value(char *arg, int *i)
{
	if (arg[*i] != '$')
		return ;
	++*i;
	while (arg[*i])
	{
		if (arg[*i] == '\'' || arg[*i] == '\"' || arg[*i] == ' ' || \
			ft_is_redirection(arg[*i]) < 0 || arg[*i] == '|' || arg[*i] == '$')
			return ;
		++*i;
	}
}

void	skip_heredoc_delimiter(char	*arg, int *i)
{
	*i += 2;
	if (arg[*i] && arg[*i] == ' ')
		skip_isspaces(arg, i);
	if (!arg[*i])
		return ;
	while (arg[*i])
	{
		if (arg[*i] && arg[*i] == ' ')
			return ;
		else if (arg[*i] && arg[*i] == '\'')
		{
			++*i;
			while (arg[*i] && arg[*i] != '\'')
				++*i;
		}
		else if (arg[*i] && arg[*i] == '\"')
		{
			++*i;
			while (arg[*i] && arg[*i] != '\"')
				++*i;
		}
		++*i;
	}
}

char	*char_copy(char	*arg, char *newstr, int *j, int *i)
{
	newstr[*j] = arg[*i];
	++*i;
	++*j;
	return (newstr);
}

int	is_dollar_name_valid(t_env **env, char *arg, int *i)
{
	char	*name;

	if (arg[*i] && arg[*i + 1] && arg[*i] == '$' && arg[*i + 1] == '?')
		return (0);
	if (!(arg[*i] == '$' && arg[*i + 1] && (ft_isalpha(arg[*i + 1]) > 0 || \
			ft_isdigit(arg[*i + 1]) > 0 || arg[*i + 1] == '_')))
		return (-1);
	name = get_the_dollar_name(arg, *i, 0);
	if (is_env_value_set(env, name) < 0)
	{
		free(name);
		skip_dollar_value(arg, i);
		return (-2);
	}
	*i += ft_strlen(name);
	free(name);
	return (0);
}

int	is_dollar_name_valid_no_incr(t_env **env, char *arg, int *i)
{
	char	*name;

	if (arg[*i] && arg[*i + 1] && arg[*i] == '$' && arg[*i + 1] == '?')
		return (0);
	if (!(arg[*i] == '$' && arg[*i + 1] && (ft_isalpha(arg[*i + 1]) > 0 || \
			ft_isdigit(arg[*i + 1]) > 0 || arg[*i + 1] == '_')))
		return (-1);
	name = get_the_dollar_name(arg, *i, 0);
	if (is_env_value_set(env, name) < 0)
	{
		free(name);
		skip_dollar_value(arg, i);
		return (-2);
	}
	free(name);
	return (0);
}
