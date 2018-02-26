# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 18:05:53 by fdelsing          #+#    #+#              #
#    Updated: 2018/02/26 16:23:12 by fdelsing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
FLAGS = -lmlx -framework OpenGL -framework Appkit


SRC = main.c	map_error.c		free.c		image.c		move.c		trace.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) -L./libft/ -lft $(FLAGS) $(OBJ) 

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: 
	$(MAKE) re -C ./libft
	fclean all

################################################################################

fsanitize : $(OBJ)
	cd ./libft $(MAKE)
	$(CC) -g -fsanitize=address -o $(NAME) -L./libft/ -lft $(CFLAGS) $(OBJ) 


