/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 03:09:51 by rogde-so          #+#    #+#             */
/*   Updated: 2026/05/08 19:27:04 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/*
This function draws a set of pixels protruding outward from the center of the
player coordinates by multiplying by i through the length, using cosf and sinf
to add the direction the player is facing. roundf is used to make it look not so
woobly by rounding up.
*/
static	void	draw_player_nose(t_game *game, size_t tile, int color)
{
	int	i;
	int	length;
	int	x;
	int	y;

	x = game->player->x * tile;
	y = game->player->y * tile;
	i = 0;
	length = 10;
	while (i <= length)
	{
		t_game_draw_pixel(game->minimap, x
			+ (int)roundf((cosf(game->player->r) * i)),
			y + (int)roundf((sinf(game->player->r) * i)), color);
		i++;
	}
}

/*
This function draws the player as a circle by stepping pixel by pixel incrementing x and y
as much as the given target angle (M_PI * 2 aka 360), and the ranges of coordinates it steps
through is -radius to radius. Just like when drawing the nose, the * radius extends the pixels
outwards while the cosf and sinf add to the x and y position all the way through a full circle.
The roundf can be used but there are no pixels that skip with a 5 radius, although there is an extra
pixel drawn to the right of the circle that the roundf erases. The increment 0.05f is a good quality,
maximum should be like 0.15f but some quality might be lost.
*/
static	void	draw_inner_circle(t_game *game, size_t tile, int rd, int color)
{
	float	angle;
	int		player_x;
	int		player_y;

	player_x = game->player->x * tile;
	player_y = game->player->y * tile;
	angle = 0.0f;
	while (angle < M_PI * 2)
	{
		t_game_draw_pixel(game->minimap,
			player_x + (int)roundf(cosf(angle) * rd),
			player_y + (int)roundf(sinf(angle) * rd), color);
		angle += 0.05f;
	}
}

void    t_game_draw_player(t_game *game, size_t tile)
{
	draw_inner_circle(game, tile, 1, 0x00FFFF00);
	draw_inner_circle(game, tile, 2, 0x0000F5FF);
	draw_inner_circle(game, tile, 3, 0x0000C5CD);
	draw_inner_circle(game, tile, 4, 0x0000868B);
	draw_inner_circle(game, tile, 5, 0x0000868B);
	draw_inner_circle(game, tile, 6, 0x0000F5FF);
	draw_player_nose(game, tile, 0x00FFFF00);
}
