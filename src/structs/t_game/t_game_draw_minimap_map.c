/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_minimap_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:43:26 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/24 22:32:38 by pde-alme         ###   ########.fr       */
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
		else
			t_game_draw_pixel(game->minimap, x + index++, y, OLIVE);
	}
	return (index);
}

static size_t	draw_tile_interior_h(t_game *game, int x, int y, int color)
{
	size_t	tile;
	size_t	index;

	tile = W_WIDTH / game->map->map_width;
	index = 1;
	while (index < tile - 1)
	{
		if (color == LIME)
			t_game_draw_pixel(game->minimap, x + index++, y, GREEN);
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
				bx = draw_tile_interior_v(g, x * t, y * t + by, c);
			else
				t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, BLACK);
		}
	}
	bx = 0;
	while (bx < t)
		t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, c);
}

/* Variable names changed to comply with norminette:
 * 		"g"  = "game"
 * 		"bx" = "brush_x";
 * 		"by" = "brush_y";
 * 		"c"  = "color";
 * 		"t"  = "tile"; 
 */
static void	draw_tile_horizontal(t_game *g, int x, int y, int c)
{
	size_t	t;
	size_t	bx;
	size_t	by;

	t = W_WIDTH / g->map->map_width;
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
				bx = draw_tile_interior_h(g, x * t, y * t + by, c);
			else
				t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, BLACK);
		}
	}
	bx = 0;
	while (bx < t)
		t_game_draw_pixel(g->minimap, x * t + bx++, y * t + by, c);
}

/* Draws the map in the "game"'s "minimap" t_image pointer.
 * The "orientation" variable determines whether the map will be drawn in a
 * horizontal or vertical manner (map size dependant).
 */
void	t_game_draw_minimap_map(t_game *game, int orientation)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '0' && orientation)
				draw_tile_horizontal(game, x, y, LIME);
			else if (game->map->map[y][x] == '0' && !orientation)
				draw_tile_vertical(game, x, y, LIME);
			else if (game->map->map[y][x] == '1' && orientation)
				draw_tile_horizontal(game, x, y, SWAMP);
			else if (game->map->map[y][x] == '1' && !orientation)
				draw_tile_vertical(game, x, y, SWAMP);
			else if (game->map->map[y][x] == ' ' && orientation)
				draw_tile_horizontal(game, x, y, BLACK);
			else if (game->map->map[y][x] == ' ' && !orientation)
				draw_tile_vertical(game, x, y, BLACK);
			x++;
		}
		y++;
	}
}
