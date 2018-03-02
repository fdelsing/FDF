# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 18:05:53 by fdelsing          #+#    #+#              #
#    Updated: 2018/03/02 18:51:46 by fdelsing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = -I./includes	-I./libft/includes	
CC = @gcc
CFLAGS = -Wall -Werror -Wextra $(HEADER)
FLAGS = -lmlx -framework OpenGL -framework Appkit


SRC = ./src/main.c		./src/map_error.c		./src/free.c	\
	  ./src/image.c		./src/move.c			./src/trace.c

OBJ = $(SRC:.c=.o)

##OBJ = main.o	map_error.o		free.o		image.o		move.o		trace.o

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ./libft
	@echo "FDF : *.c are compiled into *.o"
	$(CC) -o $(NAME) -L./libft/ -lft $(FLAGS) $(OBJ)
	@echo "FDF : fdf exec is created and ready for use"

clean:
	@$(MAKE) clean -C ./libft
	rm -rf $(OBJ)
	@echo "FDF : *.o are deleted"

fclean: clean
	@$(MAKE) fclean -C ./libft
	rm -f $(NAME)
	@echo "FDF : fdf exec is deleted"

re: fclean all
	@$(MAKE) re -C ./libft

################################################################################

fsanitize : $(OBJ)
	cd ./libft $(MAKE)
	$(CC) -g -fsanitize=address -o $(NAME) -L./libft/ -lft $(CFLAGS) $(OBJ) 


