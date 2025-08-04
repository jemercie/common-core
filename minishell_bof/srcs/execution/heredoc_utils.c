/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:59:53 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/09 19:13:23 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	close_doc(int pipe_heredoc[2])
//	close les fd sans garder les elements du heredoc
{
	close(pipe_heredoc[1]);
	close(pipe_heredoc[0]);
	return (-2);
}

void	print_errordoc(char *str)
{	
	printf("Mickey: warning: here-document at line 1 delimited by end-of-file");
	printf("(wanted `%s')\n", str);
	g_status->exit_code = 0;
}

void	ft_putstr_fd_heredoc(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
