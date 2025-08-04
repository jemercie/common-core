/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:56:25 by jemercie          #+#    #+#             */
/*   Updated: 2022/12/07 20:01:50 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include <stdio.h>
# include <errno.h>

// ------ utils.c
void	close_fd(int fd[2]);
void	free_tab(char **str, int index, char *s1);
void	file_error(int fd[2], char *arg);
void	filename_error(char **str, char *filename);
void	close_all(int fd[2], int file[2]);

// ------ childs.c
int		pipex(int argc, char **argv, char *path);
void	child(int i, char **argv, char *path);
void	dupdup(int i, int fd[2], int file[2]);

// ------ check_arg_access
char	*get_path(char **envp);
char	*get_arg(char *argv, char *path);
char	*get_access(char *path, char *arg);
void	reset_filename(char **filename);

int		open_file(int argc, char **argv, int *f1, int *f2);

#endif
