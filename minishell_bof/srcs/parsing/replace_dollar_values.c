/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:16:11 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/12 11:17:13 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	copy_value_in_str(t_env **env, char *arg, char *newstr, int *i);
static int	manage_dollar(t_env **env, char *arg, char *newstr, int *i);
static int	copy_single_quote(char *arg, char *newstr, int *i);
static int	copy_double_quote(t_env **env, char *arg, char	*newstr, int *i);

char	*replace_dollar_values(t_env **env, char *arg, int i, int j)
{
	char	*newstr;
	int		len;

	len = count_total_len(env, arg, 0);
	newstr = ft_calloc(sizeof(char), (len + 1));
	if (!newstr)
		return (NULL);
	while (arg[i] && j < len)
	{
		if (arg[i] && arg[i + 1] && arg[i] == '<' && arg[i + 1] == '<')
			copy_heredoc_delimiter(arg, newstr, &j, &i);
		else if (arg[i] == '$')
			j = manage_dollar(env, arg, newstr, &i);
		else if (arg[i] == '\'')
			j = copy_single_quote(arg, newstr, &i);
		else if (arg[i] == '\"')
			j = copy_double_quote(env, arg, newstr, &i);
		else if (arg[i])
			char_copy(arg, newstr, &j, &i);
	}
	return (newstr);
}

static int	manage_dollar(t_env **env, char *arg, char *newstr, int *i)
{
	int	j;
	int	ret;

	j = ft_strlen(newstr);
	if (arg[*i] && arg[*i + 1] && arg[*i] == '$' && arg[*i + 1] == '?')
	{
		*i += 2;
		replace_exit_code_value(newstr, &j);
		return (j);
	}
	ret = is_dollar_name_valid_no_incr(env, arg, i);
	if (ret == 0)
		j = copy_value_in_str(env, arg, newstr, i);
	else if (ret == -1)
		char_copy(arg, newstr, &j, i);
	return (j);
}

// copie la valeur de la variable du $NOM correspondant dans la nouvelle string
static int	copy_value_in_str(t_env **env, char *arg, char *newstr, int *i)
{
	char	*value;
	int		k;
	int		j;

	j = ft_strlen(newstr);
	k = 0;
	value = get_dollar_value(env, arg, *i);
	skip_dollar_value(arg, i);
	if (value == NULL)
	{
		free(value);
		return (0);
	}
	while (value[k])
	{
		newstr[j] = value[k];
		j++;
		k++;
	}
	free(value);
	return (j);
}

static int	copy_single_quote(char *arg, char *newstr, int *i)
{
	int	j;

	j = ft_strlen(newstr);
	newstr[j] = '\'';
	j++;
	++*i;
	while (arg[*i] && arg[*i] != '\'')
	{
		newstr[j] = arg[*i];
		j++;
		++*i;
	}
	newstr[j] = '\'';
	j++;
	++*i;
	return (j);
}

/* copie les caracteres entre double quotes et la ou les valeurs des variables 
$NOM(s) correspondant(s) dans la nouvelle string */
static int	copy_double_quote(t_env **env, char *arg, char	*newstr, int *i)
{
	int	j;

	j = ft_strlen(newstr);
	newstr[j] = '\"';
	j++;
	++*i;
	while (arg[*i] && arg[*i] != '\"')
	{
		if (arg[*i] && arg[*i + 1] && arg[*i] == '$' && arg[*i + 1] == '?')
		{
			*i += 2;
			replace_exit_code_value(newstr, &j);
		}
		else if (arg[*i] == '$' && arg[*i + 1] && (ft_isalpha(arg[*i + 1]) > 0 \
			|| ft_isdigit(arg[*i + 1]) > 0 || arg[*i + 1] == '_'))
			j = copy_value_in_str(env, arg, newstr, i);
		else
			char_copy(arg, newstr, &j, i);
	}
	newstr[j] = '\"';
	++*i;
	j++;
	return (j);
}
