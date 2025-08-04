# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 14:48:25 by jemercie          #+#    #+#              #
#    Updated: 2023/10/16 11:39:03 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= brain

SRCS 	:=	./main.cpp			\
			./Animal.cpp		\
			./Cat.cpp			\
			./Dog.cpp			\
			./WrongAnimal.cpp	\
			./WrongCat.cpp		\
			./Brain.cpp

FLAGS	:= -Wall -Wextra -Werror -std=c++98

OBJS	:= ${SRCS:.cpp=.o}

%.o : %.cpp
	g++ -g  $(FLAGS) -c $< -o ${<:.cpp=.o}

${NAME} : ${OBJS}
	c++ ${FLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	/bin/rm -f ${OBJS}

fclean : clean
	/bin/rm -f ${NAME}

re : fclean ${NAME}

.PHONY = all clean fclean re
