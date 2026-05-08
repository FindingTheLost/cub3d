/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_ceiling_floor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:48:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/07 22:17:07 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	draw_floor(t_game *game, int color)
{
	size_t	x;
	size_t	y;

	y = W_HEIGHT / 2;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			t_game_draw_pixel(game->image, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_ceiling(t_game *game, int color)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < W_HEIGHT / 2)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			t_game_draw_pixel(game->image, x, y, color);
			x++;
		}
		y++;
	}
}

void	t_game_draw_ceiling_floor(t_game *game)
{
	draw_ceiling(game, game->c_color);
	draw_floor(game, game->f_color);
}
