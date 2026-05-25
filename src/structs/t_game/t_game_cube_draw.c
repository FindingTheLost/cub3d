/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_cube_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:04:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/25 18:34:54 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	draw_column(t_game *game, t_wall type, int col_height, size_t col_i)
{
	int	half_column;
	int	column_top;
	int	column_bottom;

	half_column = col_height / 2;
	if (half_column > W_HEIGHT / 2)
		half_column = W_HEIGHT / 2;
	column_top = W_HEIGHT / 2 - half_column;
	column_bottom = W_HEIGHT / 2 + half_column;
	while (column_top < column_bottom)
	{
		if (type == W_NO)
			t_game_draw_pixel(game->image, col_i, column_top, 0x00FF0000);
		else if (type == W_SO)
			t_game_draw_pixel(game->image, col_i, column_top, 0x0000FF00);
		else if (type == W_WE)
			t_game_draw_pixel(game->image, col_i, column_top, 0x000000FF);
		else
			t_game_draw_pixel(game->image, col_i, column_top, 0x00FFFF00);
		column_top++;
	}
}

/* Function that draws pixel columns in the "image" variable of "game" based on
 * the "distance" the current ray has.
 *
 * The 0.9 is an arbutrary value ratio to make cubes look square instead of
 * vertical rectangle blocks.
 */
void	t_game_cube_draw(t_game *game, size_t index, t_wall type, float dist)
{
	int		column_width;
	int		column_height;
	size_t	column_i;

	column_width = W_WIDTH / RAY_AMOUNT;
	column_height = W_HEIGHT * 0.9 / dist;
	column_i = column_width * index;
	while (column_i < column_width * (index + 1))
	{
		draw_column(game, type, column_height, column_i);
		column_i++;
	}
}
