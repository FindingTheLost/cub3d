/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:09:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 20:26:45 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	debug_time(t_game *game)
{
	ft_printf("Delta: Seconds: %i | Microseconds: %i\n", game->delta.tv_sec,
		game->delta.tv_usec);
	ft_printf("New delta: Seconds: %i | Microseconds: %i\n",
		game->new_delta.tv_sec, game->new_delta.tv_usec);
}

static void	debug_colors(t_game *game)
{
	ft_printf("Floor color: %i\n", game->f_color);
	ft_printf("Ceiling color: %i\n", game->c_color);
}

static void	debug_textures(t_game *game)
{
	t_image_debug(game->no_texture);
	t_image_debug(game->so_texture);
	t_image_debug(game->we_texture);
	t_image_debug(game->ea_texture);
	t_image_debug(game->door_texture);
}

void	t_game_debug(t_game *game)
{
	ft_printf(RED_BOLD "T_GAME STRUCT DEBUG:\n" DEF);
	if (game->mlx)
		ft_printf("MLX: present.\n");
	else
		ft_printf("MLX: not present.\n");
	if (game->mlx_window)
		ft_printf("MLX window: present.\n");
	else
		ft_printf("MLX window: not present.\n");
	debug_textures(game);
	debug_colors(game);
	t_player_debug(game->player);
	t_map_debug(game->map);
	t_image_debug(game->image);
	t_image_debug(game->minimap);
	t_image_debug(game->backgrd);
	t_key_debug(game->key);
	t_mouse_debug(game->mouse);
	t_render_debug(game->render);
	debug_time(game);
}
