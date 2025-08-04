/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:17:51 by dafranco          #+#    #+#             */
/*   Updated: 2023/04/04 18:25:07 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	find_last_slash_index(char *directory_path);
static char	*get_prompt_name(char *shell_name, char *directory_path);

char	*make_prompt(void)
{
	char	buf[4096];
	char	*prompt;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	g_status->state = PROMPT;
	g_status->check_signal = false;
	if (getcwd(buf, 4096) == NULL)
	{
		prompt = get_prompt_name("mickeyshell ~", "");
		return (prompt);
	}
	prompt = get_prompt_name("mickeyshell ~", buf);
	return (prompt);
}

static char	*get_prompt_name(char *shell_name, char *directory_path)
{
	int		i;
	int		j;
	char	*prompt;

	i = ft_strlen(directory_path);
	j = find_last_slash_index(directory_path);
	prompt = malloc(sizeof(char) * (i - j + 16));
	if (!prompt)
		return (NULL);
	i = 0;
	while (shell_name[i])
	{
		prompt[i] = shell_name[i];
		i++;
	}
	while (directory_path[j])
	{
		prompt[i] = directory_path[j];
		i++;
		j++;
	}
	prompt[i] = ':';
	prompt[i + 1] = ' ';
	prompt[i + 2] = '\0';
	return (prompt);
}

static int	find_last_slash_index(char *directory_path)
{
	int	i;

	i = ft_strlen(directory_path);
	while (i >= 0)
	{
		if (directory_path[i] == '/')
			return (i);
		i--;
	}
	return (0);
}
