/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_minimap_show.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:44:09 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/17 20:26:00 by pde-alme         ###   ########.fr       */
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

void	t_game_minimap_show(t_game *game)
{
	t_image	*minimap;
	t_image	*backgrd;
	int		x;
	int		y;

	minimap = game->minimap;
	backgrd = game->backgrd;
	if (check_map_aspect_ratio(game->map->map_width, game->map->map_height))
	{
		t_game_draw_minimap_h(game);
		t_game_draw_minimap_player(game, true);
		t_game_minimap_to_window_h(game, &x, &y);
		add_vertical_offset(game, &y);
	}
	else
	{
		t_game_draw_minimap_v(game);
		t_game_draw_minimap_player(game, false);
		t_game_minimap_to_window_v(game, &x, &y);
		add_horizontal_offset(game, &x);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, backgrd->image, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_window, minimap->image, x, y);
}
