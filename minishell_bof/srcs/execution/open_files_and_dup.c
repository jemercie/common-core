/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_and_dup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:43:49 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/04 21:39:10 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	open_files(t_args *lst_arg, int *open_in, int *open_out);
static int	open_outfile(t_args *lst_arg, int i);
static int	open_infile(t_args	*lst_args, int i);
static int	perror_or_dup(char *file, int *fd, int oldfd);

int	open_and_dup(t_args *lst_args, int fd[2][2], int i)
{
	int	open_in;
	int	open_out;

	open_in = 0;
	open_out = 0;
	open_files(lst_args, &open_in, &open_out);
	if (open_in < 0 || open_out < 0)
		return (-1);
	if ((open_in == 0) && (i != 0) && (i % 2 == 0))
		dup2(fd[0][0], STDIN_FILENO);
	else if ((open_in == 0) && (i != 0) && (i % 2 == 1))
		dup2(fd[1][0], STDIN_FILENO);
	if ((open_out == 0) && (i % 2 == 0) && (i < lst_args->lst_len))
		dup2(fd[1][1], STDOUT_FILENO);
	else if ((open_out == 0) && (i % 2 == 1) && (i < lst_args->lst_len))
		dup2(fd[0][1], STDOUT_FILENO);
	close_all(fd);
	return (0);
}

static void	open_files(t_args *lst_arg, int *open_in, int *open_out)
{
	int	i;

	i = 0;
	if (!lst_arg->token || lst_arg->token[i] == 0)
		return ;
	while (lst_arg->token[i] != 0)
	{
		if (lst_arg->token[i] == OUTFILE || lst_arg->token[i] == APPEND)
		{	
			*open_out = open_outfile(lst_arg, i);
			if (*open_out < 0)
				return ;
		}
		else if (lst_arg->token[i] == INFILE || lst_arg->token[i] == HEREDOC)
		{
			*open_in = open_infile(lst_arg, i);
			if (*open_in < 0)
				return ;
		}
		i++;
	}
}

static int	open_outfile(t_args *lst_arg, int i)
{
	int	is_outfile;
	int	out;

	is_outfile = 0;
	if (lst_arg->token[i] == OUTFILE)
	{
		out = open(lst_arg->delimiter[i], O_TRUNC | O_CREAT | O_WRONLY, 0644);
		is_outfile = perror_or_dup(lst_arg->delimiter[i], &out, STDOUT_FILENO);
	}
	else if (lst_arg->token[i] == APPEND)
	{
		out = open(lst_arg->delimiter[i], O_APPEND | O_CREAT | O_WRONLY, 0644);
		is_outfile = perror_or_dup(lst_arg->delimiter[i], &out, STDOUT_FILENO);
	}
	return (is_outfile);
}

static int	open_infile(t_args	*lst_arg, int i)
{
	int	is_infile;
	int	in;

	is_infile = 0;
	if (lst_arg->token[i] == INFILE)
	{
		in = open(lst_arg->delimiter[i], O_RDONLY, 0644);
		is_infile = perror_or_dup(lst_arg->delimiter[i], &in, STDIN_FILENO);
	}
	else if (lst_arg->token[i] == HEREDOC)
	{
		dup2(lst_arg->pipe_heredoc[0], STDIN_FILENO);
		is_infile = 1;
	}
	return (is_infile);
}

static int	perror_or_dup(char *file, int *fd, int oldfd)
{
	(void) file;
	if (*fd < 0)
	{
		g_status->exit_code = 1;
		if ((access(file, F_OK) < 0))
		{
			ft_putstr_fd("Mickey: ", 2);
			ft_putstr_fd(file, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (-1);
		}
		ft_putstr_fd("Mickey: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (-1);
	}
	dup2(*fd, oldfd);
	close(*fd);
	return (1);
}
