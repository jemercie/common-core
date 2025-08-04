# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 09:57:24 by jemercie          #+#    #+#              #
#    Updated: 2023/05/19 14:50:36 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCS	=	./srcs/main.c								\
			./srcs/parsing/get_token_tab.c				\
			./srcs/parsing/get_redir_len.c				\
			./srcs/parsing/get_redir_utils.c			\
			./srcs/parsing/check_readline_return.c		\
			./srcs/parsing/check_readline_return_utils.c\
			./srcs/parsing/get_cmd_tab.c				\
			./srcs/parsing/get_cmd_tab_utils.c			\
			./srcs/parsing/get_prompt.c					\
			./srcs/parsing/init_list_args.c				\
			./srcs/parsing/parsing_utils.c				\
			./srcs/parsing/print_lists.c				\
			./srcs/parsing/replace_dollar_values.c		\
			./srcs/parsing/get_total_len.c				\
			./srcs/parsing/get_values.c					\
			./srcs/parsing/replace_dollar_values_utils.c\
			./srcs/builtins/init_builtins.c				\
			./srcs/builtins/get_env.c					\
			./srcs/builtins/get_export.c				\
			./srcs/builtins/export.c					\
			./srcs/builtins/export_utils.c				\
			./srcs/builtins/export_new_nodes.c			\
			./srcs/builtins/unset.c						\
			./srcs/builtins/env_pwd.c					\
			./srcs/builtins/echo.c						\
			./srcs/builtins/cd.c						\
			./srcs/builtins/replace_pwd.c				\
			./srcs/builtins/exit.c						\
			./srcs/builtins/exit_utils.c				\
			./srcs/execution/open_files_and_dup.c		\
			./srcs/execution/check_arg_access.c			\
			./srcs/execution/execution.c				\
			./srcs/execution/heredoc.c					\
			./srcs/execution/heredoc_utils.c			\
			./srcs/execution/signaux_handlers.c			\
			./srcs/execution/env_lst_to_tab.c			\
			./srcs/execution/global.c					\
			./srcs/clean/free_tab_close_fd.c			\
			./srcs/clean/free_lists.c

FLAG	=	-Wall -Wextra -Werror

PRINTF	=	./ft_printf/libftprintf.a

OBJ		=	${SRCS:.c=.o}

%.o: %.c
	clang ${FLAG} -c $< -o $@

all :  $(NAME)

$(NAME)	:	${PRINTF} ${OBJ}
	clang ${OBJ} ${PRINTF} -lreadline -o ${NAME}

$(PRINTF) :
	${MAKE} -C ./ft_printf

clean :
	${MAKE} -C ./ft_printf clean
	/bin/rm -f ${OBJ}

fclean : clean
	${MAKE} -C ./ft_printf fclean
	/bin/rm -f ${NAME} ${PRINTF}

re : fclean ${NAME}

PHONY : all clean fclean re

