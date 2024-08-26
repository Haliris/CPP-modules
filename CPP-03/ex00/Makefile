# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 14:44:08 by jteissie          #+#    #+#              #
#    Updated: 2024/08/26 11:30:53 by jteissie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp_test

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILE =	main.cpp \
			ClapTrap.cpp

INCLUDE = -I include/

OBJ_FILE = $(SRC_FILE:.c=.o)

OBJS = $(OBJ_FILE)

all: $(NAME)

$(OBJS):
	$(CPP) $(CPP_FLAGS) $(INCLUDE) $(SRC_FILE) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

clean:
	rm -rf main.o ClapTrap.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONE: all clean fclean re
