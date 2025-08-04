# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 11:13:00 by jemercie          #+#    #+#              #
#    Updated: 2023/03/05 20:02:14 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	push_swap.c\
			manage_args.c\
			check_args.c\
			push.c\
			swap.c\
			rotate.c\
			reverse_rotate.c\
			sort_one_to_five.c\
			sort_the_rest.c\
			push_swap_utils.c\
			utils_a_to_b.c\
			utils_b_to_a.c

FLAG	=	-Wall -Wextra -Werror

PRINTF	=	./ft_printf/libftprintf.a

OBJ		=	${SRC:.c=.o}

.c.o :
	gcc ${FLAG} -c $< -o ${<:.c=.o}

$(NAME): ${PRINTF} ${OBJ}
	gcc ${OBJ} ./ft_printf/libftprintf.a -o ${NAME}

$(PRINTF) :
	${MAKE} -C ./ft_printf

all : ${NAME}

clean :
	${MAKE} -C ./ft_printf clean
	/bin/rm -f ${OBJ}

fclean : clean
	/bin/rm -f ${NAME} ${PRINTF} ./checker ./ft_printf/libft/libft.a

re : fclean ${NAME}

PHONY : all clean fclean re
