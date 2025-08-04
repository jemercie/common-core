/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:11:16 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/03 09:35:17 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(int argc, char **argv, int *f1, int *f2)
{
	int	i;

	i = 1;
	*f1 = open(argv[1], O_RDONLY, 0644);
	if (*f1 < 0)
	{
		perror(argv[1]);
		i = 2;
	}
	*f2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (*f2 < 0)
		perror(argv[argc - 1]);
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	int		status;
	int		pid;

	status = 0;
	if (argc != 5)
	{
		ft_printf("Wrong number of arguments\n");
		return (0);
	}
	path = get_path(envp);
	pid = pipex(argc, argv, path);
	waitpid(pid, &status, 0);
	free(path);
	return (WEXITSTATUS(status));
}
