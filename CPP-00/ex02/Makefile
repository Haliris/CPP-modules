# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 14:44:08 by jteissie          #+#    #+#              #
#    Updated: 2024/08/21 12:33:48 by jteissie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILE =	tests.cpp \
			Account.cpp \

INCLUDE = -I include/

OBJ_FILE = $(SRC_FILE:.c=.o)

OBJS = $(OBJ_FILE)

all: $(NAME)

$(OBJS):
	$(CPP) $(CPP_FLAGS) $(INCLUDE) $(SRC_FILE) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

clean:
	rm -rf account.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONE: all clean fclean re
