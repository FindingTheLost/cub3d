/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_minimap_v.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 01:44:53 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/08 04:01:44 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	draw_tile_vertical(t_game *game, int x, int y, int cor, size_t tile)
{
	size_t	brush_x;
	size_t	brush_y;

	brush_x = 0;
	while (brush_x < tile)
		t_game_draw_pixel(game->minimap, x * tile + brush_x++, y * tile, cor);
	brush_y = 1;
	while (brush_y < tile - 1)
	{
		brush_x = 0;
		while (brush_x < tile)
		{
			if (brush_x == 0 || brush_x == tile - 1)
				t_game_draw_pixel(game->minimap, x * tile + brush_x++,
					y * tile + brush_y, cor);
			else
				t_game_draw_pixel(game->minimap, x * tile + brush_x++,
					y * tile + brush_y, 0);
		}
		brush_y++;
	}
	brush_x = 0;
	while (brush_x < tile)
		t_game_draw_pixel(game->minimap, x * tile
			+ brush_x++, y * tile + brush_y, cor);
}

/* Draws a map that has a large "map_width" to fit in a horizontal screen while
 * keeping perfect square aspect ratio.
 */
void	t_game_draw_minimap_v(t_game *game, size_t tile)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '0')
				draw_tile_vertical(game, x, y, 0x00AA0000, tile);
			else if (game->map->map[y][x] == '1')
				draw_tile_vertical(game, x, y, 0x00DDDDDD, tile);
			else
				draw_tile_vertical(game, x, y, 0x00000000, tile);
			x++;
		}
		y++;
	}
}
