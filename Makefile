# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 13:01:09 by kmilchev          #+#    #+#              #
#    Updated: 2022/03/07 14:18:58 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC =	src/main.c \
		src/input_validation.c \
		src/handle_images.c \
		src/render_map.c \
		src/handle_keys.c \
		src/utils.c \
		src/utils2.c \
		src/map_validation.c \
		42_get_next_line/get_next_line.c \
		42_get_next_line/get_next_line_utils.c \
		
OBJs := $(SRC:.c=.o)


# -I[/path/to/header-files]
# Add search path to header files (.h) or (.hpp).
FLAGS = -Wall -Wextra -Werror -Iincludes

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJs)
	$(MAKE) -C mlx/
	$(CC) $(OBJs) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) so_long $(OBJs)
	$(MAKE) clean -C mlx/
re: clean all
