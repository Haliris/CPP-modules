# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 14:44:08 by jteissie          #+#    #+#              #
#    Updated: 2024/09/15 15:44:15 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = temu_final_fantasy

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC_FILE =	main.cpp \
			AMateria.cpp \
			Cure.cpp \
			Ice.cpp \
			Character.cpp \
			MateriaSource.cpp

INCLUDE = -I include/

OBJ_FILE = $(SRC_FILE:.c=.o)

OBJS = $(OBJ_FILE)

all: $(NAME)

$(OBJS):
	$(CPP) $(CPP_FLAGS) $(INCLUDE) $(SRC_FILE) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

clean:
	rm -rf main.o AMateria.o Cure.o Ice.o Character.o MateriaSource.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONE: all clean fclean re
