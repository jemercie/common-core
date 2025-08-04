# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemercie <jemercie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 14:48:25 by jemercie          #+#    #+#              #
#    Updated: 2023/11/22 17:58:32 by jemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= easyfind

SRCS 	:=	./main.cpp

FLAGS	:= -Wall -Wextra -Werror -std=c++98

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
