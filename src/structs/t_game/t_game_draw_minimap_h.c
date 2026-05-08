/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_minimap_h.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 01:44:53 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/08 03:55:09 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	draw_tile_horizontal(t_game *game, int x, int y, int cor, size_t t)
{
	size_t	brush_x;
	size_t	brush_y;

	brush_x = 0;
	while (brush_x < t)
		t_game_draw_pixel(game->minimap, x * t + brush_x++, y * t, cor);
	brush_y = 1;
	while (brush_y < t - 1)
	{
		brush_x = 0;
		while (brush_x < t)
		{
			if (brush_x == 0 || brush_x == t - 1)
				t_game_draw_pixel(game->minimap, x * t + brush_x++,
					y * t + brush_y, cor);
			else
				t_game_draw_pixel(game->minimap, x * t + brush_x++,
					y * t + brush_y, 0);
		}
		brush_y++;
	}
	brush_x = 0;
	while (brush_x < t)
		t_game_draw_pixel(game->minimap, x * t
			+ brush_x++, y * t + brush_y, cor);
}

/* Draws a map that has a large "map_width" to fit in a horizontal screen while
 * keeping perfect square aspect ratio.
 */
void	t_game_draw_minimap_h(t_game *game, size_t tile)
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
				draw_tile_horizontal(game, x, y, 0x00AA0000, tile);
			else if (game->map->map[y][x] == '1')
				draw_tile_horizontal(game, x, y, 0x00DDDDDD, tile);
			else
				draw_tile_horizontal(game, x, y, 0x00000000, tile);
			x++;
		}
		y++;
	}
}
