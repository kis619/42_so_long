# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 13:01:09 by kmilchev          #+#    #+#              #
#    Updated: 2022/03/06 12:31:20 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC =	main.c \
		test.c \
		on_click.c \
		utils.c \
		matrix_stuff.c \
		42_get_next_line/get_next_line.c \
		42_get_next_line/get_next_line_utils.c \
		input_validation.c \
		handle_images.c
		
OBJs := $(SRC:.c=.o)


# -I[/path/to/header-files]
# Add search path to header files (.h) or (.hpp).
FLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

# %.o: %.c
# 	$(CC) $(FLAGS) -c $< -o $@

%.o: %.c
	$(CC) -Iincludes -c $< -o $@

$(NAME): $(OBJs)
	$(CC) $(OBJs) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) *.out *.o so_long

re: clean all
