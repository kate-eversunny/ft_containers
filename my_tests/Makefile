# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 11:32:12 by gbroccol          #+#    #+#              #
#    Updated: 2021/03/11 18:00:42 by pvivian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_containers

CC =		clang++

FLAGS =		-Wall -Werror -Wextra -g -std=c++98 -I ../containers -I .

# HEADER = /.

SRCS =		main.cpp \
			list_test.cpp \
			vector_test.cpp \
			# map_test.cpp \
			# queue_test.cpp \
			# stack_test.cpp \
			
OBJ =		$(SRCS:.cpp=.o)

%.o: %.cpp
			$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
clean:
			rm -rf $(OBJ)
fclean:
			rm -rf $(OBJ) $(NAME)
re: fclean all

.PHONY: all clean fclean re