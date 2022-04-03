# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 13:01:09 by kmilchev          #+#    #+#              #
#    Updated: 2022/04/03 17:25:04 by kmilchev         ###   ########.fr        #
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


# -I[/path/to/header-files]
# Add search path to header files (.h) or (.hpp).
FLAGS = -Wall -Wextra -Werror -Iincludes -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): 
	$(MAKE) -C mlx/
	$(CC) $(SRC) $(FLAGS) $(NAME)

clean:
	$(RM) so_long
	
fclean: clean
	$(MAKE) clean -C mlx/
	
re: fclean all
