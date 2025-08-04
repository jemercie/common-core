/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::   */
/*   env_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:41:26 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/09 12:38:10 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(t_env **env)
{
	print_env_list(env);
}

void	ft_pwd(void)
{
	char	buf[4096];

	if (getcwd(buf, 4096) == NULL)
		return ;
	printf("%s\n", buf);
}
