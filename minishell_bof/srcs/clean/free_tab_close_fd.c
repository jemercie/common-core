/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:04:23 by jemercie          #+#    #+#             */
/*   Updated: 2023/04/17 11:29:04 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_tab_index(char **str, int index)
{
	int	i;

	i = index;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	str = NULL;
}

void	free_tab(char **tabtab)
{
	int	i;

	i = 0;
	if (!tabtab)
		return ;
	while (tabtab[i])
	{
		free(tabtab[i]);
		i++;
	}
	free(tabtab);
	tabtab = NULL;
}

void	free_lst_close_all(t_args **lst_arg, int fd[2][2])
{
	if (*lst_arg)
		free(*lst_arg);
	close_all(fd);
}

void	close_fd(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

void	close_all(int fd[2][2])
{
	close_fd(fd[0]);
	close_fd(fd[1]);
}
