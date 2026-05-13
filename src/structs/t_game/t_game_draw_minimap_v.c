/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_minimap_v.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 01:44:53 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/13 19:28:39 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* Variable names changed to comply with norminette:
 * 		"g"  = "game"
 * 		"bx" = "brush_x";
 * 		"by" = "brush_y";
 * 		"c"  = "color";
 * 		"t"  = "tile";
 */
static void	draw_tile_vertical(t_game *g, int x, int y, int c)
{
	size_t	t;
	size_t	bx;
	size_t	by;

	t = W_HEIGHT / g->map->map_height;
	bx = 0;
	while (bx < t)
		t_game_draw_pixel(g->minimap, x * t + bx++, y * t, c);
	by = 0;
	while (++by < t - 1)
	{
		bx = 0;
		while (bx < t)
		{
			if (bx == 0 || bx == t - 1)
				t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, c);
			else if (c != BLACK)
				t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, GREEN);
			else
				t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, BLACK);
		}
	}
	bx = 0;
	while (bx < t)
		t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, c);
}

/* Draws a map that has a large "map_width" to fit in a horizontal screen while
 * keeping perfect square aspect ratio.
 */
void	t_game_draw_minimap_v(t_game *game)
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
				draw_tile_vertical(game, x, y, LIME);
			else if (game->map->map[y][x] == '1')
				draw_tile_vertical(game, x, y, SWAMP);
			else
				draw_tile_vertical(game, x, y, BLACK);
			x++;
		}
		y++;
	}
}
