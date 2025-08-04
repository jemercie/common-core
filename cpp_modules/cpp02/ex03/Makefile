# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 14:48:25 by jemercie          #+#    #+#              #
#    Updated: 2023/10/23 12:09:16 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= ex03

SRCS 	:=	./main.cpp	\
			./Fixed.cpp	\
			./Point.cpp	\
			./bsp.cpp

FLAGS	:= -g -Wall -Wextra -Werror -std=c++98

OBJS	:= ${SRCS:.cpp=.o}

%.o : %.cpp
	c++ $(FLAGS) -c $< -o ${<:.cpp=.o}

${NAME} : ${OBJS}
	c++ ${FLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	/bin/rm -f ${OBJS}

fclean : clean
	/bin/rm -f ${NAME}

re : fclean ${NAME}

.PHONY = all clean fclean re
