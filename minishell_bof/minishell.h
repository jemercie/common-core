/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:43:22 by jemercie          #+#    #+#             */
/*   Updated: 2023/05/08 17:39:41 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <errno.h>

# define PROMPT 0
# define HEREDOC 1
# define APPEND 2
# define OUTFILE 3
# define INFILE 4

/*		global_struct		*/
typedef struct s_status
{
	int				state;
	int				heredoc;
	bool			check_signal;
	long long int	exit_code;
}			t_status;

/*		env_variables		*/

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;

/*		arguments list		*/

typedef struct s_args
{
	char			**cmd;
	char			**delimiter;
	int				*token;
	int				lst_len;
	int				pipe_heredoc[2];
	struct s_args	*next;
}				t_args;

				/****************
				*	△ GLOBAL	*
				****************/

extern t_status	*g_status;

				/****************
				*	 PARSING	*
				*****************/
/*				main.c						*/
void		free_prompt_lists(t_env *env, char *prompt, char *line, t_env *exp);

/*			get_prompt.c					*/
char		*make_prompt(void);

/*			check_readline_return.c			*/
int			check_readline_return(char *arg);

/*			check_readline_return_utils.c	*/
int			check_is_valid_arg_next(char *arg, int i);
int			check_heredoc_number(char *arg);

/*			replace_dollar_values_utils.c	*/
void		skip_dollar_value(char *arg, int *i);
void		skip_heredoc_delimiter(char	*arg, int *i);
char		*char_copy(char	*arg, char *newstr, int *j, int *i);
int			is_dollar_name_valid(t_env **env, char *arg, int *i);
int			is_dollar_name_valid_no_incr(t_env **env, char *arg, int *i);

/*			get_total_len.c					*/
int			count_total_len(t_env **env, char *arg, int i);
int			get_value_len(t_env **env, char *str, int *k);
int			get_double_quote_len(t_env **env, char *arg, int *i);
void		replace_exit_code_value(char *newstr, int *j);

/*			get_values.c					*/
char		*get_the_dollar_name(char *arg, int i, int j);
char		*get_dollar_value(t_env **env, char *arg, int i);
char		*get_value(t_env **env, char *name);

/*			replace_dollar_values.c			*/
char		*replace_dollar_values(t_env **env, char *arg, int i, int j);
char		*copy_heredoc_delimiter(char *arg, char *newstr, int *j, int *i);

/*			init_list_args.c				*/
t_args		*get_args_list(char	*arg);

/*			get_cmd_tab.c					*/
char		**get_cmd_tab(char *arg, int *i);

/*			get_cmd_tab_utils.c				*/
int			skip_quote(char *str, int *i, char c);
int			count_args(char	*arg, int	*j);
void		skip_arg(char	*str, int *i);
void		skip_redirections(char	*arg, int *i);

/*			get_token_tab					*/
int			*get_token_tab(char *str, int *i);
int			set_token(char *line, int *i);
int			get_next_token(char *line, int *i);
int			count_redir(int *count, char *line, int i);
int			get_redir(char *str, int *i);

/*			redir_len.c						*/
void		find_next_quote(char *str, int *i, int *count, char c);
int			count_char_redir(int *count, char *s, int *i);
int			get_next_redir(char *str, int *i);
char		*get_redir_str(char	*str, int *i);
char		**get_redir_tab(char *str, int *i);

/*			get_redir_utils.c						*/

void		skipcopy_str(char *str, char *redir, int *i, int *tmp);
void		find_next_quote(char *str, int *i, int *count, char c);
int			ft_is_metaspace(int c);

/*			print_lists						*/
void		print_env_list(t_env **env_list);
void		print_arg_list(t_args	**list_arg);
void		print_export_list(t_env **export);

/*			parsing_utils.c					*/
void		skip_isspaces(char *arg, int *i);
int			skipkot(char *str, int *i, char c);
int			ft_is_redirection(char c);

				/****************
				*	 BUILTINS	*
				*****************/

/*			init_builtins.c					*/
int			which_builtin(char *cmd);
char		**init_builtins(void);

/*			get_env.c						*/
t_env		*get_env_list(char **env);
void		lstaddback_env_node(t_env *env_list, t_env *new);
t_env		*new_env_node(char *str);
char		*dup_value(const char *str);
char		*dup_name(const char *str);

/*			get_export.c					*/
t_env		*get_export_list(t_env *env);
void		lstadd_export_node(t_env *env, t_env *new);
t_env		*new_export_node(t_env *env);

/*			export.c						*/
void		ft_export(t_env **env, t_env **export, char **arg);
char		*dup_add_name(const char *str);

/*			export_utils.c					*/
char		*which_dup_name(char *arg, int add);
int			is_export_name_set(t_env **env, char *name);
int			is_env_value_set(t_env **env, char *arg_name);

/*			export_new_nodes.c				*/
void		get_new_node(t_env **list, char *arg, int add);
void		get_new_export_node(t_env **list, char *arg, int add);
void		get_new_export_invalid_node(t_env **list, char *arg);

/*			sort_export.c					*/
void		print_sort_env(t_env **lst_env);
int			ft_list_len(t_env **lst_env);

/*			env_pwd.c						*/
void		ft_env(t_env **env);
void		ft_pwd(void);

/*			unset.c							*/
void		ft_unset(t_env **env, t_env **export, char **arg);
int			err(int code, char *name, char *arg, char *msg);

/*			echo.c							*/
int			ft_echo(char **args);

/*			cd.c							*/
int			ft_cd(t_env **env, t_env **export, char *path);
int			check_args_cd(char **args);
int			check_if_unset(int i, int action);

/*			replace_pwd.c					*/
void		replace_export(char *pwd, char *old_pwd, t_env **export);
void		replace_env(char *pwd, char *old_pwd, t_env **env);
int			ft_cmp(char *str1, char *str2);

/*			exit.c							*/
int			ft_exit(t_args *cmd, t_env *env, t_env *export, int is_pipe);

/*           exit_utils.c                            */
void		p_exit(t_args *arg, t_env *env, t_env *e, int is_pipe);
int			p_exit_args(int is_pipe);
void		print_exit_if_not_piped(int is_pipe);
void		exit_no_args(t_args *arg, t_env *env, t_env *export, int is_pipe);

/*			global.c						*/
void		init_global(void);

				/****************
				*	EXECUTION	*
				*****************/

/*			open_files_and_dup.c			*/
int			open_and_dup(t_args *lst_args, int fd[2][2], int i);

/*			check_arg_access				*/
char		*get_arg(t_env *lst_env, char *cmd);

/*			execution.c						*/
int			*minishell(t_args *lst_args, t_env *lst_env, int i, t_env *export);
int			not_fork_builtins(t_args *lst_arg, t_env *lst_env, t_env *export);

/*			signaux_handlers.c				*/
void		handle_sigint(int signum);
void		handle_sigint_exec(int signum);
void		handle_sigquit(int signum);

/*			heredoc.c						*/
void		init_heredoc(t_args *lst_arg, int i, int fd);

/*			heredoc_utils.c                        */
int			close_doc(int pipe_heredoc[2]);
void		print_errordoc(char *str);
void		ft_putstr_fd_heredoc(char *s, int fd);

/*			env_lst_to_tab.c				*/
char		**env_lst_to_tab(t_env *env);

				/****************
				*	  CLEAN		*
				*****************/

/*			free_and_close.c				*/
void		free_tab(char **tabtab);
void		close_fd(int fd[2]);
void		close_all(int fd[2][2]);
void		free_tab_index(char **str, int index);
void		free_lst_close_all(t_args **lst_arg, int fd[2][2]);

/*			free_lists.c					*/
void		free_lists(t_args **lst_args, t_env **lst_env, t_env **export);
void		free_env_list(t_env **lst_env);
void		free_arg_list(t_args **lst_arg);
void		free_arg_node(t_args **lst_arg);
void		free_and_exit(t_args **lst_arg, t_env **lst_env, t_env **export);

#endif
