# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/16 18:44:21 by pde-alme          #+#    #+#              #
#    Updated: 2026/05/22 19:50:50 by pde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

MATHLIB		= -lm

HDR			= ./src/cub3d.h										\
			  ./src/parse_input/parse_input.h					\
			  ./src/structs/t_cub_struct.h						\
			  ./src/structs/t_game_struct.h						\
			  ./src/structs/t_player_struct.h					\
			  ./src/structs/t_map_struct.h						\
			  ./src/structs/t_image_struct.h					\
			  ./src/game/game.h

SRC			= ./src/cub3d.c										\
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
			  ./src/structs/t_game/t_game_debug.c				\
			  ./src/structs/t_game/t_game_destroy.c				\
			  ./src/structs/t_game/t_game_draw_pixel.c			\
			  ./src/structs/t_game/t_game_draw_background.c		\
			  ./src/structs/t_game/t_game_draw_ceiling_floor.c	\
			  ./src/structs/t_game/t_game_draw_minimap_h.c		\
			  ./src/structs/t_game/t_game_draw_minimap_v.c		\
			  ./src/structs/t_game/t_game_draw_minimap_player.c	\
			  ./src/structs/t_game/t_game_minimap_to_window.c	\
			  ./src/structs/t_game/t_game_minimap_show.c		\
			  ./src/structs/t_game/t_game_cube_show.c			\
			  ./src/structs/t_game/t_game_error.c				\
			  ./src/structs/t_game/t_game_init_colors.c			\
			  ./src/structs/t_game/t_game_init_mlx.c			\
			  ./src/structs/t_game/t_game_init_textures.c		\
			  ./src/structs/t_game/t_game_populate.c			\
			  ./src/structs/t_game/t_game_check_keys.c			\
			  ./src/structs/t_game/t_game_check_mouse.c			\
			  ./src/structs/t_game/t_game_check_collisions.c	\
			  ./src/structs/t_game/t_game_clamp_rotation.c		\
			  ./src/structs/t_game/t_game_delta.c				\
			  ./src/structs/t_player/t_player_build.c			\
			  ./src/structs/t_player/t_player_debug.c			\
			  ./src/structs/t_player/t_player_destroy.c			\
			  ./src/structs/t_player/t_player_error.c			\
			  ./src/structs/t_player/t_player_populate.c		\
			  ./src/structs/t_map/t_map_build.c					\
			  ./src/structs/t_map/t_map_debug.c					\
			  ./src/structs/t_map/t_map_destroy.c				\
			  ./src/structs/t_map/t_map_error.c					\
			  ./src/structs/t_map/t_map_populate.c				\
			  ./src/structs/t_image/t_image_build.c				\
			  ./src/structs/t_image/t_image_debug.c				\
			  ./src/structs/t_image/t_image_destroy.c			\
			  ./src/structs/t_image/t_image_error.c				\
			  ./src/structs/t_image/t_image_populate.c			\
			  ./src/structs/t_key/t_key_build.c					\
			  ./src/structs/t_key/t_key_debug.c					\
			  ./src/structs/t_key/t_key_destroy.c				\
			  ./src/structs/t_key/t_key_error.c					\
			  ./src/structs/t_key/t_key_populate.c				\
			  ./src/structs/t_mouse/t_mouse_build.c				\
			  ./src/structs/t_mouse/t_mouse_debug.c				\
			  ./src/structs/t_mouse/t_mouse_destroy.c			\
			  ./src/structs/t_mouse/t_mouse_error.c				\
			  ./src/structs/t_mouse/t_mouse_populate.c			\
			  ./src/game/game.c									\
			  ./src/game/game_update.c							\
			  ./src/game/game_init_screen.c						\
			  ./src/game/game_init_variables.c					\
			  ./src/game/game_init_hooks.c

OBJ			= $(SRC:.c=.o)

LIBFT		= ./libft/libft.a

MLX			= ./minilibx-linux/libmlx_Linux.a

MLXFLAGS	= -std=gnu11 -lX11 -lXext



all: $(NAME)

$(NAME): $(HDR) $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLXFLAGS) $(MATHLIB) -o $(NAME)

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



.PHONY: all clean fclean re
