/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_minimap_h.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 01:44:53 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/07 22:13:41 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	draw_player_horizontal(t_game *game)
{
	size_t	tile;
	int		player_x;
	int		player_y;
	int		i;

	tile = W_WIDTH / game->map->map_width;
	player_x = game->player->x * tile - 1;
	player_y = game->player->y * tile - 1;
	i = 0;
	while (i < 3)
	{
		t_game_draw_pixel(game->minimap, player_x, player_y + i, 0x000000FF);
		t_game_draw_pixel(game->minimap, player_x + 1, player_y + i, 0x000000FF);
		t_game_draw_pixel(game->minimap, player_x + 2, player_y + i, 0x000000FF);
		i++;
	}
}

static void	draw_tile_horizontal(t_game *game, int x, int y, int color)
{
	size_t	brush_x;
	size_t	brush_y;
	size_t	tile;

	tile = W_WIDTH / game->map->map_width;
	brush_x = 0;
	while (brush_x < tile)
		t_game_draw_pixel(game->minimap, x * tile + brush_x++, y * tile, color);
	brush_y = 1;
	while (brush_y < tile - 1)
	{
		brush_x = 0;
		while (brush_x < tile)
		{
			if (brush_x == 0 || brush_x == tile - 1)
				t_game_draw_pixel(game->minimap, x * tile + brush_x++, y * tile + brush_y, color);
			else
				t_game_draw_pixel(game->minimap, x * tile + brush_x++, y * tile + brush_y, 0);
		}
		brush_y++;
	}
	brush_x = 0;
	while (brush_x < tile)
		t_game_draw_pixel(game->minimap, x * tile + brush_x++, y * tile + brush_y, color);
}

/* Draws a map that has a large "map_width" to fit in a horizontal screen while
 * keeping perfect square aspect ratio.
 */
void	t_game_draw_minimap_h(t_game *game)
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
					draw_tile_horizontal(game, x, y, 0x00AA0000);
			else if (game->map->map[y][x] == '1')
					draw_tile_horizontal(game, x, y, 0x00DDDDDD);
			else
					draw_tile_horizontal(game, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	draw_player_horizontal(game);
}
