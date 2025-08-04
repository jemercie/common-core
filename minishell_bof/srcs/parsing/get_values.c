/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:56:23 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/24 19:57:38 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_dollar_value(t_env **env, char *arg, int i)
{
	char		*name;
	char		*value;

	name = NULL;
	value = NULL;
	name = get_the_dollar_name(arg, i, 0);
	if (!name)
		return (NULL);
	value = get_value(env, name);
	free(name);
	return (value);
}

char	*get_value(t_env **env, char *name)
{
	char	*value;
	t_env	*tmp;

	value = NULL;
	tmp = (*env);
	while (tmp)
	{
		if (ft_strncmp(name, tmp->name, ft_strlen(name)) == 0)
			value = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	return (value);
}

char	*get_the_dollar_name(char *arg, int i, int j)
{
	int		len;
	char	*name;

	len = 0;
	if (arg[i] != '$')
		return (NULL);
	i++;
	j = i;
	while (arg[i] && (ft_isalpha(arg[i]) > 0 || ft_isdigit(arg[i]) > 0 \
		|| arg[i] == '_'))
	{
		len++;
		i++;
	}
	i = j;
	j = 0;
	name = ft_calloc(sizeof(char), (len + 1));
	if (!name)
		return (NULL);
	while (arg[i] && j < len)
	{
		name[j] = arg[i + j];
		j++;
	}
	return (name);
}
