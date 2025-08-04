/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:11:28 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/03 09:25:57 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **str, int index, char *s1)
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
	if (s1)
		free(s1);
}

void	close_fd(int fd[2])
{
	if (fd[0] > 0)
		close(fd[0]);
	if (fd[1] > 0)
		close(fd[1]);
}

void	close_all(int fd[2], int file[2])
{
	close_fd(fd);
	close_fd(file);
}

void	file_error(int fd[2], char *arg)
{
	perror(arg);
	free(arg);
	close_fd(fd);
	exit(errno);
}

void	filename_error(char **str, char *filename)
{
	perror(str[0]);
	free_tab(str, 0, filename);
	exit(errno);
}
