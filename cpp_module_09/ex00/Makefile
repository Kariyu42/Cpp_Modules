# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 22:35:40 by kquetat-          #+#    #+#              #
#    Updated: 2024/02/18 17:26:09 by kquetat-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- SRC / OBJ --- #
SRC			=	main.cpp BitcoinExchange.cpp

OBJ			=	${SRC:.cpp=.o}

# --- COMPILER --- #
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic

# --- COLORS --- #
RED			=	\033[0;31m
GREEN		=	\033[0;32m
PURPLE		=	\033[0;35m
CYAN		=	\033[0;36m
NC			=	\033[0m

# --- DEBUG PURPOSES --- #
ifdef	DEBUG
	CC	+=	-g
endif

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

# --- EXEC / RULES --- #
NAME	=	btc
TEST_FILE	= input.txt

all:	${NAME} generate

${NAME}:	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}
	@printf "Compiled ${GREEN}${NAME}${NC}\n"

debug:
	${MAKE} DEBUG=1

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}
	rm -f ${TEST_FILE}

re:	fclean
	${MAKE} all

generate:
	@echo "date | value" > ${TEST_FILE}
	@echo "2011-01-03 | 3" >> ${TEST_FILE}
	@echo "2011-01-03 | 2" >> ${TEST_FILE}
	@echo "2011-01-03 | 1" >> ${TEST_FILE}
	@echo "2011-01-03 | 1.2" >> ${TEST_FILE}
	@echo "2011-01-09 | 1" >> ${TEST_FILE}
	@echo "2012-01-11 | -1" >> ${TEST_FILE}
	@echo "2001-42-42" >> ${TEST_FILE}
	@echo "2012-01-11 | 1" >> ${TEST_FILE}
	@echo "2012-01-11 | 2147483648" >> ${TEST_FILE}
	@printf "Generated ${CYAN}${TEST_FILE}${NC}\n"

.PHONY: all debug clean fclean re generate