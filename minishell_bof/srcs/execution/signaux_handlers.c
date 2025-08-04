/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:22:51 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/09 01:41:26 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_sigint(int signum)
// gere CTRL + C une fois le programme demarre
{
	(void)signum;
	g_status->exit_code = 130;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigint_exec(int signum)
// gere CTRL + C une fois la fonction readline appellee une fois
{
	(void)signum;
	if (g_status->state == HEREDOC)
	{
		g_status->heredoc = dup(0);
		close(0);
		g_status->exit_code = 130;
		g_status->check_signal = true;
	}
	g_status->exit_code = 130;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
}

void	handle_sigquit(int signum)
{
	(void)signum;
	if (g_status->state == HEREDOC)
		return ;
	printf("Quit\n");
	exit(0);
}
