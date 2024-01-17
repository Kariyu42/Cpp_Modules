# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 14:26:28 by kquetat-          #+#    #+#              #
#    Updated: 2024/01/17 15:15:44 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- SRC / OBJ --- #
SRC			=	Account.cpp tests.cpp

OBJ			=	${SRC:.cpp=.o}

# --- COMPILER --- #
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# --- DEBUG PURPOSES --- #
ifdef	DEBUG
	CC	+=	-g
endif

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

# --- EXEC / RULES --- #
NAME	=	account

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