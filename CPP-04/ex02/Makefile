# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 14:44:08 by jteissie          #+#    #+#              #
#    Updated: 2024/09/17 12:59:17 by jteissie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstract_test

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC_FILE =	main.cpp \
			Aanimal.cpp \
			Cat.cpp \
			Dog.cpp \
			Brain.cpp


INCLUDE = -I include/

OBJ_FILE = $(SRC_FILE:.c=.o)

OBJS = $(OBJ_FILE)

all: $(NAME)

$(OBJS):
	$(CPP) $(CPP_FLAGS) $(INCLUDE) $(SRC_FILE) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

clean:
	rm -rf main.o Aanimal.o Cat.o Dog.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONE: all clean fclean re
