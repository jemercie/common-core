# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 15:21:53 by jemercie          #+#    #+#              #
#    Updated: 2022/11/10 20:44:36 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRC		= ft_printf.c\
			ft_printf_utils.c\
			ft_puthexa_low.c\
			ft_puthexa_upp.c\
			ft_putptr.c\
			ft_putunsigned.c\
			ft_intlen_hexa.c\

FLAG	= -Wall -Wextra -Werror
LIBFT	= ./libft/libft.a
SUBDIR	= ./libft
OBJ		= ${SRC:.c=.o}

.c.o:
	gcc ${FLAG} -c $< -o ${<:.c=.o}

$(NAME): ${LIBFT} ${OBJ}
	ar rc ${NAME} ${OBJ}

${LIBFT}:
	 ${MAKE} -C ${SUBDIR}
	cp libft/libft.a ./libftprintf.a

clean_lib:
	${MAKE} -C ${SUBDIR} clean

clean:
	/bin/rm -f ${OBJ}

fclean: clean clean_lib
	/bin/rm -f ${NAME} ${LIBFT}

re: fclean ${NAME}

.PHONY = all clean clean_lib fclean re
