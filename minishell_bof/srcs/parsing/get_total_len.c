/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_dollar_values_len.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:16:38 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/24 19:13:06 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	free_strings(char *str1, char *str2);

int	count_total_len(t_env **env, char *arg, int i)
{
	int	total;
	int	ret;

	total = 0;
	while (arg[i])
	{
		if (arg[i] && arg[i + 1] && arg[i] == '<' && arg[i + 1] == '<')
			skip_heredoc_delimiter(arg, &i);
		else if (arg[i] == '$')
		{
			ret = is_dollar_name_valid_no_incr(env, arg, &i);
			if (ret == 0)
				total += get_value_len(env, arg, &i);
			else if (ret == -1)
				i++;
		}
		else if (arg[i] && arg[i] == '\'')
			skipkot(arg, &i, arg[i]);
		else if (arg[i] && arg[i] == '\"')
			total += get_double_quote_len(env, arg, &i);
		else if (arg[i])
			i++;
	}
	return (total + i);
}

int	get_value_len(t_env **env, char *str, int *k)
{
	char	*name;
	char	*value;
	int		total;
	int		i;

	i = 0;
	total = 0;
	if (str[*k] && str[*k + 1] && str[*k] == '$' && str[*k + 1] == '?')
	{
		(*k) += 2;
		return (ft_intlen(g_status->exit_code) - 2);
	}
	name = get_the_dollar_name(str, *k, 0);
	*k += ft_strlen(name);
	if (name == NULL)
		return (-1);
	value = get_value(env, name);
	if (value == NULL)
	{
		free(name);
		return (-1);
	}
	total = (ft_strlen(value) - ft_strlen(name));
	free_strings(value, name);
	return (total);
}

int	get_double_quote_len(t_env **env, char *arg, int *i)
{
	int	ret;

	ret = 0;
	++*i;
	while (arg[*i] && arg[*i] != '\"')
	{
		if (arg[*i] == '$' && is_dollar_name_valid_no_incr(env, arg, i) == 0)
			ret = get_value_len(env, arg, i);
		else
			++*i;
	}
	++*i;
	return (ret);
}

void	replace_exit_code_value(char *newstr, int *j)
{
	int			i;
	int			len;
	char		*value;
	long int	nb;

	nb = g_status->exit_code;
	i = 0;
	len = ft_intlen(nb);
	value = ft_itoa(nb);
	while (value[i])
	{
		newstr[*j] = value[i];
		++*j;
		i++;
	}
	free (value);
}

static void	free_strings(char *str1, char *str2)
{
	free(str1);
	free(str2);
}
