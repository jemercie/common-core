# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 16:26:08 by jemercie          #+#    #+#              #
#    Updated: 2023/08/19 16:26:12 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS	:= cub3D_bonus

CFLAGS	:= -g -Wextra -Wall -Werror

LIBMLX	:= ../MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include

LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS_BONUS	:=	./srcs/main_bonus.c									\
				./srcs/parsing/parsing_bonus.c						\
				./srcs/parsing/init_struct_bonus.c					\
				./srcs/parsing/errors_bonus.c						\
				./srcs/parsing/check_file_bonus.c					\
				./srcs/parsing/check_file_content_bonus.c			\
				./srcs/parsing/get_params_bonus.c					\
				./srcs/parsing/get_perso_position_bonus.c			\
				./srcs/parsing/get_colors_bonus.c					\
				./srcs/parsing/get_and_check_the_map_bonus.c		\
				./srcs/parsing/get_and_check_the_map_utils_bonus.c	\
				./srcs/parsing/get_sprite_tab_and_rank_bonus.c		\
				./srcs/parsing/parsing_utils_bonus.c				\
				./srcs/parsing/free_and_delete_bonus.c				\
				./srcs/execution/draw_bonus.c						\
				./srcs/execution/draw_walls_bonus.c					\
				./srcs/execution/draw_sprite_bonus.c				\
				./srcs/execution/draw_the_map_bonus.c				\
				./srcs/execution/hooks_bonus.c		 				\
				./srcs/execution/door_w_s_hooks_bonus.c				\
				./srcs/execution/calcul_the_view_bonus.c			\
				./srcs/execution/calcul_images_bonus.c				\
				./srcs/execution/door_bonus.c						\
				./srcs/execution/moove_the_door_bonus.c

LIBFT	=	../libft./libft.a

OBJS_BONUS	:= ${SRCS_BONUS:.c=.o}

all: libmlx $(NAME_BONUS)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	clang $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME_BONUS): $(OBJS_BONUS)
	clang $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS) ../libft/libft.a

${LIBFT}:
	${MAKE} -C ../libft

clean:
	@rm -rf $(OBJS_BONUS)
	@rm -rf $(LIBMLX)/build
	${MAKE} -C ../libft clean

fclean: clean
	@rm -rf $(NAME_BONUS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
