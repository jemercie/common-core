/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:20:38 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/03 15:32:20 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_status	*g_status;

void	init_global(void)
{
	g_status = malloc(sizeof(t_status));
	g_status->exit_code = 0;
	g_status->state = 0;
	g_status->heredoc = 0;
	g_status->check_signal = 0;
}
