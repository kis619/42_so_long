# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 13:01:09 by kmilchev          #+#    #+#              #
#    Updated: 2022/03/05 11:52:30 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC =	main.c \
		test.c \
		42_get_next_line/get_next_line.c \
		42_get_next_line/get_next_line_utils.c \
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


TEST =	main.c \
		test.c \
		42_get_next_line/get_next_line.c \
		42_get_next_line/get_next_line_utils.c \
		handle_images.c

TOBJs = $(TEST:.c=.o)

test: $(TOBJs)
	$(CC) $(TOBJs) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o z_test


# test: $(TOBJs)
# 	$(CC) $(TOBJs) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o z_test

text_editing:
	gcc y_conversion.c -Iincludes 42_get_next_line/get_next_line.c 42_get_next_line/get_next_line_utils.c