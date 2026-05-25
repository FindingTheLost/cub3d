/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_ceiling_floor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:48:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/24 21:49:17 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	draw_floor(t_image *image, int color)
{
	size_t	x;
	size_t	y;

	y = W_HEIGHT / 2;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			t_game_draw_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_ceiling(t_image *image, int color)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < W_HEIGHT / 2)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			t_game_draw_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

void	t_game_draw_ceiling_floor(t_game *game, t_image *image)
{
	draw_ceiling(image, game->c_color);
	draw_floor(image, game->f_color);
}
