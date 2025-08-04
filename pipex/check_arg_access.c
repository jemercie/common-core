/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:12:22 by jemercie          #+#    #+#             */
/*   Updated: 2023/01/17 14:12:23 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_arg(char *argv, char *path)
{
	char	**arg;
	char	*filename;

	arg = ft_split(argv, ' ');
	if (arg == NULL)
	{
		arg = malloc(sizeof(char *) * 2);
		arg[1] = NULL;
		arg[0] = malloc(sizeof(char) * 2);
		arg[0][0] = ' ';
		arg[0][1] = '\0';
	}
	filename = get_access(path, arg[0]);
	free_tab(arg, 0, path);
	return (filename);
}

/* Get the path in the envp environment variable */

char	*get_path(char **envp)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
			j = 5;
			k = 0;
			while (envp[i][j])
			{
				path[k] = envp[i][j];
				k++;
				j++;
			}
			path[k] = '\0';
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	reset_filename(char **filename)
{
	free(*filename);
	*filename = NULL;
}

/* Check for all paths if the command is valid  */

char	*get_access(char *path, char *arg)
{
	char	**path_tab;
	char	*filename;
	int		i;

	i = 0;
	path_tab = ft_split(path, ':');
	filename = NULL;
	filename = ft_strjoin(filename, arg);
	while (path_tab[i])
	{
		if (access(filename, X_OK) == 0)
		{
			free_tab(path_tab, (i + 1), NULL);
			return (filename);
		}
		reset_filename(&filename);
		filename = ft_strjoin(path_tab[i], "/");
		filename = ft_strjoin(filename, arg);
		i++;
	}
	reset_filename(&filename);
	perror(arg);
	free(path_tab);
	return (filename);
}
