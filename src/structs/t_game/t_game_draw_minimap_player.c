/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_minimap_player.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:43:57 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/22 20:31:14 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"
#include <stddef.h>

/* This function draws a set of pixels protruding outward from the center of
 * the player's coordinates by multiplying "i" through "length", using "cosf"
 * and "sinf" to add to the direction the player is facing. "roundf" is used
 * to make the pixels not look so wobly by rounding up.
 */
static void	draw_player_nose(t_game *game, size_t tile, int color)
{
	int		x;
	int		y;
	size_t	i;

	x = game->player->x * tile;
	y = game->player->y * tile;
	i = 0;
	while (i <= (tile / 2))
	{
		t_game_draw_pixel(game->minimap,
			x + (int)roundf((cosf(game->player->r) * i)),
			y + (int)roundf((sinf(game->player->r) * i)), color);
		i++;
	}
}

/* This function draws the player as a circle by stepping pixel by pixel,
 * incrementing 'x' and 'y' as much as the given target angle
 * (M_PI * 2 a.k.a 360 degrees), and the ranges of coordinates it steps
 * through is -radius to radius.
 * Just like when drawing the nose, the radius extends the pixels outwards
 * while "cosf" and "sinf" add to the 'x' and 'y' position all the way through
 * a full circle.
 * The "roundf" function can be used but there are no pixels that skip with
 * a 5 radius, although there is an extra pixel drawn to the right of the
 * circle that "roundf" erases.
 * The increment 0.05f is of good quality, maximum should around 0.15f but
 * some quality can be lost.
 */
static void	draw_inner_circle(t_game *game, size_t tile, int rd, int color)
{
	float	angle;
	int		player_x;
	int		player_y;

	angle = 0.0f;
	player_x = game->player->x * tile;
	player_y = game->player->y * tile;
	while (angle < M_PI * 2)
	{
		t_game_draw_pixel(game->minimap,
			player_x + (int)roundf(cosf(angle) * rd),
			player_y + (int)roundf(sinf(angle) * rd), color);
		angle += 0.05f;
	}
}

void	t_game_draw_minimap_player(t_game *game, int orientation)
{
	size_t	i;
	size_t	tile;

	if (orientation)
		tile = W_WIDTH / game->map->map_width;
	else
		tile = W_HEIGHT / game->map->map_height;
	i = 1;
	while (i <= (tile / 4))
	{
		if (i <= ((tile / 4) / 6))
			draw_inner_circle(game, tile, i, YELLOW);
		else if (i <= ((tile / 4) / 6) * 2)
			draw_inner_circle(game, tile, i, RED1);
		else if (i <= ((tile / 4) / 6) * 3)
			draw_inner_circle(game, tile, i, RED2);
		else if (i <= ((tile / 4) / 6) * 4)
			draw_inner_circle(game, tile, i, RED3);
		else if (i <= ((tile / 4) / 6) * 5)
			draw_inner_circle(game, tile, i, RED4);
		else
			draw_inner_circle(game, tile, i, RED5);
		i++;
	}
	draw_player_nose(game, tile, RED6);
}
