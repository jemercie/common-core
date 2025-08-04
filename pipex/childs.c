/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:11:05 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/03 09:22:14 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Call  */

int	pipex(int argc, char **argv, char *path)
{
	int	fd[2];
	int	pid;
	int	file[2];
	int	i;

	if (pipe(fd) == -1)
		return (-1);
	i = open_file(argc, argv, &file[0], &file[1]);
	while (i < argc - 2)
	{
		i++;
		pid = fork();
		if (pid == 0)
		{
			dupdup(i, fd, file);
			close_all(fd, file);
			if (file[1] < 0 && i > argc - 3)
				free(path);
			if (file[1] < 0 && i > argc - 3)
				exit(-1);
			child(i, argv, path);
		}
	}
	close_all(fd, file);
	return (pid);
}

/* Check the first command and execute it in the fork */

void	child(int i, char **argv, char *path)
{
	char	*filename;
	char	**args;

	args = ft_split(argv[i], ' ');
	filename = get_arg(args[0], path);
	if (filename == NULL)
	{
		free_tab(args, 0, filename);
		exit(127);
	}
	free(args[0]);
	args[0] = filename;
	execve(filename, args, NULL);
	free_tab(args, 0, filename);
	exit(1);
}

/* check the last command and execute it */

void	dupdup(int i, int fd[2], int file[2])
{
	if (i == 2)
	{
		dup2(file[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
	}
	else if (i == 3)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(file[1], STDOUT_FILENO);
	}
}
