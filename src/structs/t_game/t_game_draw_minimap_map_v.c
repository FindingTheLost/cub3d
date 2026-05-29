/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_minimap_map_v.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:43:26 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/28 18:57:58 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static size_t	draw_tile_interior_v(t_game *game, int x, int y, int color)
{
	size_t	tile;
	size_t	index;

	tile = W_HEIGHT / game->map->map_height;
	index = 1;
	while (index < tile - 1)
	{
		if (color == LIME)
			t_game_draw_pixel(game->minimap, x + index++, y, GREEN);
		else if (color == RED6)
			t_game_draw_pixel(game->minimap, x + index++, y, RED7);
		else if (color == BLUE0)
			t_game_draw_pixel(game->minimap, x + index++, y, BLUE1);
		else
			t_game_draw_pixel(game->minimap, x + index++, y, OLIVE);
	}
	return (index);
}

/* Variable names changed to comply with norminette:
 * 		"g"  = "game"
 * 		"bx" = "brush_x";
 * 		"by" = "brush_y";
 * 		"c"  = "color";
 * 		"t"  = "tile";
 */
static void	draw_tile_outline_v(t_game *g, int x, int y, int c)
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
				bx = draw_tile_interior_v(g, x * t, y * t + by, c);
			else
				t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, BLACK);
		}
	}
	bx = 0;
	while (bx < t)
		t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, c);
}

/* Draws the map into the game's "minimap" t_image pointer if the map has a
 * vertical orientation.
 */
void	t_game_draw_minimap_map_v(t_game *game)
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
				draw_tile_outline_v(game, x, y, LIME);
			else if (game->map->map[y][x] == '1')
				draw_tile_outline_v(game, x, y, SWAMP);
			else if (game->map->map[y][x] == ' ')
				draw_tile_outline_v(game, x, y, BLACK);
			else if (game->map->map[y][x] == 'D')
				draw_tile_outline_v(game, x, y, RED6);
			else if (game->map->map[y][x] == 'O')
				draw_tile_outline_v(game, x, y, BLUE0);
			x++;
		}
		y++;
	}
}
