/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_minimap_show.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:44:09 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/24 22:32:55 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* Checks whether the map has an horizontal tendency or vertical.
 * Returns "true" if the map is more inclined toward a horizontal rectangle and
 * beyond a perfect square.
 * Returns "false" if the map is more inclined toward a vertical rectangle or
 * is a perfect square.
 */
static int	check_map_aspect_ratio(t_map *map)
{
	float	x;
	float	y;

	x = map->map_width / 16;
	y = map->map_height / 9;
	if (x > y)
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
	if (check_map_aspect_ratio(game->map))
	{
		t_game_draw_minimap_map(game, true);
		t_game_draw_minimap_player(game, true);
		t_game_minimap_to_center(game, &x, &y, true);
	}
	else
	{
		t_game_draw_minimap_map(game, false);
		t_game_draw_minimap_player(game, false);
		t_game_minimap_to_center(game, &x, &y, false);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, backgrd->image, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_window, minimap->image, x, y);
}
