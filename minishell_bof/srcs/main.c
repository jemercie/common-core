/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:17:51 by dafranco          #+#    #+#             */
/*   Updated: 2023/05/09 18:31:46 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	line_manager(char *line, t_env *lst_env, t_env *export);
static void	init_and_call(char *str, t_env *lst_env, t_env *xprt);
static void	wait_loop(int *pid, int len);

int	main(int argc, char **argv, char **env)
{
	char		*line;
	char		*prompt;
	t_env		*lst_env;
	t_env		*export;

	if (argc != 1 || argv[1])
		return (1);
	init_global();
	lst_env = get_env_list(env);
	export = get_export_list(lst_env);
	while (1)
	{
		prompt = make_prompt();
		line = readline(prompt);
		if (!line)
		{
			free(g_status);
			free_prompt_lists(lst_env, prompt, line, export);
			printf("Quit\n");
			break ;
		}
		free(prompt);
		line_manager(line, lst_env, export);
	}
	return (0);
}

static void	line_manager(char *line, t_env *lst_env, t_env *export)
{
	char	*str;

	if (ft_strlen(line) != 0)
	{
		signal(SIGINT, handle_sigint_exec);
		signal(SIGQUIT, handle_sigquit);
	}
	if (line && *line)
		add_history(line);
	if (check_readline_return(line) < 0)
		return ;
	else
	str = replace_dollar_values(&lst_env, line, 0, 0);
	free(line);
	init_and_call(str, lst_env, export);
	if (!line)
	{
		line = NULL;
		free(line);
	}
}

static void	init_and_call(char *str, t_env *lst_env, t_env *xprt)
{
	t_args	*lst_arg;
	int		*pid;
	int		len;

	pid = NULL;
	lst_arg = get_args_list(str);
	init_heredoc(lst_arg, 0, 0);
	len = lst_arg->lst_len + 1;
	if (g_status->heredoc != 0)
		dup2(g_status->heredoc, 0);
	if (!lst_arg->next && not_fork_builtins(lst_arg, lst_env, xprt) == 0)
		free_arg_list(&lst_arg);
	else
		pid = minishell(lst_arg, lst_env, 0, xprt);
	wait_loop(pid, len);
}

static void	wait_loop(int *pid, int len)
{
	int	i;
	int	r;
	int	*status;

	i = 0;
	r = 0;
	status = malloc(sizeof(int) * len);
	while (pid && i < len)
	{
		waitpid(pid[r], &status[r], 0);
		r++;
		i++;
	}
	if (r > 0 && WIFEXITED(status[r - 1]) == true)
		g_status->exit_code = WEXITSTATUS(status[r - 1]);
	free(pid);
	free(status);
}

void	free_prompt_lists(t_env *env, char *prompt, char *line, t_env *exp)
{
	free(prompt);
	free(line);
	free_env_list(&exp);
	free_env_list(&env);
}
