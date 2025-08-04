/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:33:49 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/09 18:32:45 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	which_builtin(char *cmd)
{
	int		j;
	int		len;
	char	**builtins;

	builtins = NULL;
	len = ft_strlen(cmd);
	if (len == 0)
		return (-1);
	builtins = init_builtins();
	j = 0;
	while (builtins[j])
	{
		if (ft_strncmp(cmd, builtins[j], len + 1) == 0)
		{
			free_tab(builtins);
			return (j + 1);
		}
		j++;
	}
	free_tab(builtins);
	return (-1);
}

char	**init_builtins(void)
{
	int		i;
	char	**builtins_list;

	i = 0;
	builtins_list = malloc(sizeof(char *) * 8);
	if (!builtins_list)
		return (NULL);
	builtins_list[0] = ft_strdup("echo");
	builtins_list[1] = ft_strdup("cd");
	builtins_list[2] = ft_strdup("pwd");
	builtins_list[3] = ft_strdup("export");
	builtins_list[4] = ft_strdup("unset");
	builtins_list[5] = ft_strdup("env");
	builtins_list[6] = ft_strdup("exit");
	builtins_list[7] = NULL;
	return (builtins_list);
}
