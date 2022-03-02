# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 13:01:09 by kmilchev          #+#    #+#              #
#    Updated: 2022/03/01 12:11:41 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c file1.c file2.c file3.c
OBJs := $(SRC:.c=.o)

# -I[/path/to/header-files]
# Add search path to header files (.h) or (.hpp).
FLAGS = -Wall -Wextra -Werror -I mlx 

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJs)
	$(CC) $(OBJs) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) *.out *.o so_long

re: clean all