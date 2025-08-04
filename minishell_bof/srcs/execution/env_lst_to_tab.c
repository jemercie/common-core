/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:50:14 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/08 18:02:41 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	lst_len(t_env *env);

char	**env_lst_to_tab(t_env *env)
{
	int		i;
	int		len;
	char	**env_tab;
	t_env	*tmp;

	i = 0;
	tmp = env;
	len = lst_len(env);
	env_tab = malloc(sizeof(char *) * (len + 1));
	while (tmp)
	{
		env_tab[i] = ft_strdup(tmp->name);
		env_tab[i] = ft_strjoin(env_tab[i], "=");
		env_tab[i] = ft_strjoin(env_tab[i], tmp->value);
		i++;
		tmp = tmp->next;
	}
	env_tab[i] = NULL;
	return (env_tab);
}

static int	lst_len(t_env *env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
