# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 18:05:53 by fdelsing          #+#    #+#              #
#    Updated: 2018/02/13 06:08:01 by fdelsing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -lmlx -framework OpenGL -framework Appkit

SRC = main.c	map_error.c		free.c		image.c		move.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cd ./Libft $(MAKE)
	$(CC) -o $(NAME) -L./Libft/ -lft $(CFLAGS) $(OBJ) 

clean:
	cd ./Libft $(MAKE) clean
	rm -rf $(OBJ)

fclean: clean
	cd ./Libft $(MAKE) fclean
	rm -f $(NAME)

re: 
	cd ./libft $(MAKE) re
	fclean all
