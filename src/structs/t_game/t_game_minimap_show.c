/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_minimap_show.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:25:22 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/08 18:54:47 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	add_horizontal_offset(t_game *game, int *x)
{
	size_t	tile;

	tile = (W_HEIGHT / game->map->map_height) * game->map->map_width;
	*x += (W_WIDTH - tile) / 2;
}

static void	add_vertical_offset(t_game *game, int *y)
{
	size_t	tile;

	tile = (W_WIDTH / game->map->map_width) * game->map->map_height;
	*y += (W_HEIGHT - tile) / 2;
}

/* Checks whether the map can fit in a 16:9 aspect ratio (or larger width) or
 * not.
 */
static int	check_map_aspect_ratio(size_t map_width, size_t map_height)
{
	float	x;
	float	y;

	x = map_width / 16;
	y = map_height / 9;
	if (x >= y)
		return (true);
	return (false);
}

/*
The tile is now being set in this function and both draw_player_vertical and
draw_player_horizontal are both the same function taking tile as a parameter!
*/

void	t_game_minimap_show(t_game *game)
{
	t_image	*minimap;
	t_image	*bg;
	size_t	tile;
	int		x;
	int		y;

	minimap = game->minimap;
	bg = game->minimap_background;
	if (check_map_aspect_ratio(game->map->map_width, game->map->map_height))
	{
		tile = W_WIDTH / game->map->map_width;
		t_game_draw_minimap_h(game, tile);
		t_game_minimap_to_window_h(game, &x, &y);
		add_vertical_offset(game, &y);
	}
	else
	{
		tile = W_HEIGHT / game->map->map_height;
		t_game_draw_minimap_v(game, tile);
		t_game_minimap_to_window_v(game, &x, &y);
		add_horizontal_offset(game, &x);
	}
	t_game_draw_player(game, tile);
	mlx_put_image_to_window(game->mlx, game->mlx_window, bg->image, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_window, minimap->image, x, y);
}
