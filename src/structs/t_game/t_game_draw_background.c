/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:48:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/05 23:52:37 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	fill_low_half_screen(t_game *game, int color)
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

static void	fill_top_half_screen(t_game *game, int color)
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

void	t_game_draw_background(t_game *game)
{
	fill_top_half_screen(game, game->c_color);
	fill_low_half_screen(game, game->f_color);
}
