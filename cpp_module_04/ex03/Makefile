# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 15:28:20 by kquetat-          #+#    #+#              #
#    Updated: 2024/02/04 18:00:50 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- SRC / OBJ --- #
SRC			=	main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJ			=	${SRC:.cpp=.o}

# --- COMPILER --- #
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic

# --- DEBUG PURPOSES --- #
ifdef	DEBUG
	CC	+=	-g
endif

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

# --- EXEC / RULES --- #
NAME	=	Materia

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