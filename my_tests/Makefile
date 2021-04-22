# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvivian <pvivian@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 11:32:12 by gbroccol          #+#    #+#              #
#    Updated: 2021/04/22 21:20:30 by pvivian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

CC = clang++

FLAGS =	-Wall -Werror -Wextra -g -fsanitize=address -std=c++98 -I ../containers -I ../containers/iterators/ -I . -MMD

MAIN = $(SRCS_DIR)main.cpp

SRCS =	main.cpp \
		vector_test.cpp \
		list_test.cpp \
		map_test.cpp \
		# stack_test.cpp \
		# queue_test.cpp \


SRCS_DIR = ./sources/

OBJS =	$(SRCS:.cpp=.o)
OBJS_DIR = ./objects/
OBJ = $(addprefix $(OBJS_DIR), $(OBJS))

DEP = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) $(MAIN)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	test -d $(OBJS_DIR) || mkdir $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean:
	rm -rf $(OBJS_DIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re