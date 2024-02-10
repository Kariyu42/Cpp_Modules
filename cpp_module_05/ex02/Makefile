# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 18:25:31 by kquetat-          #+#    #+#              #
#    Updated: 2024/02/10 13:41:44 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- SRC / OBJ --- #
SRC			=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

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
NAME	=	DifferentForms

all:	${NAME}

${NAME}:	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

debug:
	${MAKE} DEBUG=1

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}
	rm -f shrub_shrubbery

re:	fclean
	${MAKE} all

.PHONY: all debug clean fclean re