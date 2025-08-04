# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 14:54:57 by jemercie          #+#    #+#              #
#    Updated: 2023/05/02 09:52:07 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRC		=	main.c					\
			init_structs.c			\
			parsing.c				\
			check_args.c			\
			superviser.c			\
			routine.c				\
			print_and_usleep.c		\
			mutex_utils.c			\
			destroy_and_free.c

FLAG	=	-pthread -Wall -Wextra -Werror

OBJ 	=	${SRC:.c=.o}

%.o: %.c
	gcc -g ${FLAG} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	gcc -g -pthread ${OBJ} -o $(NAME)

all : ${NAME}

clean:
	/bin/rm -f ${OBJ}

fclean: clean
	/bin/rm -f ${NAME}

re: fclean ${NAME}

.PHONY = all clean fclean re
