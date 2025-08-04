/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:47:55 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/09 19:15:26 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	heredoc(char *delimiter, int pipe_heredoc[2]);
static void	get_line(char *delimiter, char *str, char *buf, int pipe_here[2]);
static char	*line_cpy(char *buffer);

void	init_heredoc(t_args *lst_arg, int i, int fd)
{
	t_args	*tmp;

	tmp = lst_arg;
	while (lst_arg)
	{
		while (lst_arg->token && lst_arg->token[i] != 0)
		{
			if (lst_arg->token[i] == HEREDOC)
			{
				if (fd != 0)
					close_fd(lst_arg->pipe_heredoc);
				if (heredoc(lst_arg->delimiter[i], lst_arg->pipe_heredoc) == -3)
				{
					lst_arg = tmp;
					return ;
				}
				fd++;
			}
			i++;
		}
		i = 0;
		fd = 0;
		lst_arg = lst_arg->next;
	}
	lst_arg = tmp;
}

static int	heredoc(char *delimiter, int pipe_heredoc[2])
{
	char	*buf;
	char	*str;

	if (pipe(pipe_heredoc) == -1)
		return (-1);
	if (g_status->check_signal == true)
		return (-3);
	buf = readline("> ");
	if (buf == NULL && g_status->check_signal == false)
	{
		printf("Mickey: warning: here-document at line 1 delimited by ");
		printf("end-of-file (wanted `%s')\n", delimiter);
		return (-1);
	}
	if (buf != NULL)
	{
		str = line_cpy(buf);
		get_line(delimiter, str, buf, pipe_heredoc);
	}
	return (0);
}

static char	*line_cpy(char *buffer)
{
	int		i;
	char	*newstr;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	newstr = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		newstr[i] = buffer[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static void	get_line(char *delimiter, char *str, char *buf, int pipe_here[2])
{
	int	len;

	len = ft_strlen(delimiter) + 1;
	while (ft_strncmp(delimiter, str, len) != 0)
	{
		ft_putstr_fd_heredoc(buf, pipe_here[1]);
		free(buf);
		buf = NULL;
		buf = readline("> ");
		if (g_status->check_signal == true)
		{
			close_doc(pipe_here);
			break ;
		}
		if (buf == NULL)
		{
			print_errordoc(delimiter);
			break ;
		}
		free(str);
		str = line_cpy(buf);
	}
	free(str);
	close(pipe_here[1]);
	free(buf);
}
