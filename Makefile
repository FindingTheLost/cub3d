# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/16 18:44:21 by pde-alme          #+#    #+#              #
#    Updated: 2026/04/19 20:46:06 by pde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Add more files, fix empty variables, empty rules and hide some messages.

NAME		= cub3D

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

HDR			= ./src/cub3d.h										\
			  ./src/parse_input/parse_input.h

SRC			= ./src/cub3d.c										\
			  ./src/parse_input/parse_input.c					\
			  ./src/parse_input/parse_input_argc.c				\
			  ./src/parse_input/parse_input_file_extension.c	\
			  ./src/parse_input/parse_input_valid_file.c		\
			  ./src/parse_input/parse_input_line.c		\
			  ./src/parse_input/parse_input_orientation.c		\
			  ./src/parse_input/parse_input_color.c

OBJ			= $(SRC:.c=.o)

LIBFT		= ./libft/libft.a

MLX			= ./minilibx-linux/libmlx_Linux.a

MLXFLAGS	= -std=gnu11 -lX11 -lXext



all: $(NAME)

bonus:

$(NAME): $(HDR) $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make clean -C minilibx-linux

re: fclean all



.PHONY: all bonus clean fclean re
