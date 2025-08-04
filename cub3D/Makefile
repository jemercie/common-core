# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 16:26:33 by jemercie          #+#    #+#              #
#    Updated: 2023/08/28 15:22:56 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3D

CFLAGS	:= -g -Wextra -Wall -Werror

LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include

LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	:=	./srcs/main.c									\
			./srcs/parsing/parsing.c						\
			./srcs/parsing/init_struct.c					\
			./srcs/parsing/errors.c							\
			./srcs/parsing/check_file.c						\
			./srcs/parsing/check_file_content.c				\
			./srcs/parsing/get_params.c						\
			./srcs/parsing/get_perso_position.c				\
			./srcs/parsing/get_colors.c						\
			./srcs/parsing/get_and_check_the_map.c			\
			./srcs/parsing/parsing_utils.c					\
			./srcs/parsing/free_and_close_fd.c				\
			./srcs/execution/draw.c							\
			./srcs/execution/hooks.c		 				\
			./srcs/execution/calcul_the_view.c

LIBFT	=	./libft./libft.a

OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	clang $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	clang $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) ./libft/libft.a

${LIBFT}:
	${MAKE} -C ./libft

bonus:
	${MAKE} -C ./bonus_cub3D
	cp ./bonus_cub3D/cub3D_bonus .

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	${MAKE} -C ./libft clean
	${MAKE} clean -C ./bonus_cub3D

fclean: clean
	@rm -rf $(NAME)
	${MAKE} fclean -C ./bonus_cub3D
	
re: clean all

.PHONY: all, clean, fclean, re, libmlx
