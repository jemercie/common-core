# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 19:43:13 by jemercie          #+#    #+#              #
#    Updated: 2023/02/17 20:20:37 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRC 	=	pipex.c\
			check_arg_access.c\
			childs.c\
			utils.c

FLAG	=	-Wall -Wextra -Werror

PRINTF	=	./ft_printf/libftprintf.a

OBJ		=	${SRC:.c=.o}

.c.o:
	clang ${FLAG} -c $< -o ${<:.c=.o}

$(NAME): ${PRINTF} ${OBJ}
	clang -g ${OBJ} ./ft_printf/libftprintf.a -o ${NAME}

$(PRINTF) :
	${MAKE} -C ./ft_printf

all : ${NAME}

clean :
	${MAKE} -C ./ft_printf clean
	/bin/rm -f ${OBJ}

fclean : clean
	${MAKE} -C ./ft_printf fclean
	/bin/rm -f ${NAME} ${PRINTF}

re : fclean ${NAME}

PHONY : all clean fclean re

