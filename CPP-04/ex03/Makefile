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
			MateriaSource.cpp \
			Stash.cpp

INCLUDE = -I include/

OBJ_FILE = $(SRC_FILE:.cpp=.o)

OBJS = $(OBJ_FILE)

all: $(NAME)

%.o : %.cpp
	$(CPP) $(CPP_FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONE: all clean fclean re
