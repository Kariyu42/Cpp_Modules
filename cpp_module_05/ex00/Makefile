# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 18:25:31 by kquetat-          #+#    #+#              #
#    Updated: 2024/02/11 15:40:43 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- SRC / OBJ --- #
SRC			=	main.cpp Bureaucrat.cpp

OBJ			=	${SRC:.cpp=.o}

# --- COMPILER --- #
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 #-pedantic

# --- DEBUG PURPOSES --- #
ifdef	DEBUG
	CC	+=	-g
endif

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

# --- EXEC / RULES --- #
NAME	=	Bureaucrat

all:	${NAME}

${NAME}:	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

debug:
	${MAKE} DEBUG=1

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean
	${MAKE} all

.PHONY: all debug clean fclean re