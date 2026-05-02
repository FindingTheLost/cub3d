# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/16 18:44:21 by pde-alme          #+#    #+#              #
#    Updated: 2026/05/02 02:11:54 by pde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Add more files, fix empty variables, empty rules and hide some messages.

NAME		= cub3D

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

HDR			= ./src/cub3d.h										\
			  ./src/structs/t_cub_struct.h						\
			  ./src/structs/t_game_struct.h						\
			  ./src/structs/t_player_struct.h					\
			  ./src/structs/t_map_struct.h						\
			  ./src/parse_input/parse_input.h					\
			  ./src/game/game.h

SRC			= ./src/cub3d.c										\
			  ./src/structs/t_cub/t_cub_build.c					\
			  ./src/structs/t_cub/t_cub_build_map.c				\
			  ./src/structs/t_cub/t_cub_destroy.c				\
			  ./src/structs/t_cub/t_cub_error.c					\
			  ./src/structs/t_cub/t_cub_debug.c					\
			  ./src/structs/t_cub/t_cub_get_width.c				\
			  ./src/structs/t_cub/t_cub_get_height.c			\
			  ./src/structs/t_cub/t_cub_check_if_element.c		\
			  ./src/structs/t_cub/t_cub_open_file.c				\
			  ./src/structs/t_cub/t_cub_populate.c				\
			  ./src/structs/t_game/t_game_build.c				\
			  ./src/structs/t_game/t_game_destroy.c				\
			  ./src/structs/t_game/t_game_error.c				\
			  ./src/structs/t_game/t_game_init_colors.c			\
			  ./src/structs/t_game/t_game_init_mlx.c			\
			  ./src/structs/t_game/t_game_init_textures.c		\
			  ./src/structs/t_game/t_game_populate.c			\
			  ./src/structs/t_player/t_player_build.c			\
			  ./src/structs/t_player/t_player_destroy.c			\
			  ./src/structs/t_player/t_player_error.c			\
			  ./src/structs/t_player/t_player_populate.c		\
			  ./src/structs/t_map/t_map_build.c					\
			  ./src/structs/t_map/t_map_destroy.c				\
			  ./src/structs/t_map/t_map_error.c					\
			  ./src/structs/t_map/t_map_populate.c				\
			  ./src/parse_input/parse_input.c					\
			  ./src/parse_input/parse_input_argc.c				\
			  ./src/parse_input/parse_input_help.c				\
			  ./src/parse_input/parse_input_file_extension.c	\
			  ./src/parse_input/parse_input_valid_file.c		\
			  ./src/parse_input/parse_input_line.c				\
			  ./src/parse_input/parse_input_orientation.c		\
			  ./src/parse_input/parse_input_color.c				\
			  ./src/parse_input/parse_input_map_found.c			\
			  ./src/parse_input/parse_input_map_whole.c			\
			  ./src/parse_input/parse_input_map_player.c		\
			  ./src/parse_input/parse_input_map_surroundings.c	\
			  ./src/game/game.c									\
			  ./src/game/game_init_vars.c

OBJ			= $(SRC:.c=.o)

LIBFT		= ./libft/libft.a

MLX			= ./minilibx-linux/libmlx_Linux.a

MLXFLAGS	= -std=gnu11 -lX11 -lXext



all: $(NAME)

bonus:

$(NAME): $(HDR) $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

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
