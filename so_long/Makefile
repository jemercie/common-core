# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 14:54:57 by jemercie          #+#    #+#              #
#    Updated: 2023/03/15 17:03:12 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC		=	so_long.c\
			check_the_map.c\
			get_the_map.c\
			init_structs.c\
			display_map.c\
			get_the_move.c\
			destroy_and_free.c

FLAG	=	-Wall -Wextra -Werror

OBJ 	=	${SRC:.c=.o}

PRINTF	=	./ft_printf/libftprintf.a

SUBDIR = ./minilibx-linux

%.o: %.c
	gcc -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

$(NAME): ${PRINTF} $(OBJ)
	gcc $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ./ft_printf/libftprintf.a -o $(NAME)

$(PRINTF) :
	${MAKE} -C ./ft_printf

clean:
	/bin/rm -f ${OBJ}
	${MAKE} -C ./ft_printf clean

fclean: clean
	/bin/rm -f ${NAME} ${MLX} ./ft_printf/libft/libft.a ./ft_printf/libftprintf.a

re_printf :
	${MAKE} -C ./ft_printf re

re: fclean re_printf ${NAME} 

.PHONY = clean fclean re
