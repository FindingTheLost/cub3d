/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_draw_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 21:57:34 by rogde-so          #+#    #+#             */
/*   Updated: 2026/06/01 22:30:02 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* This function goes through the sent image "frame" pixel by pixel, checking
 *  the color in that pixel coordinate and writing the non transparent ones into
 *  the t_game image buffer (the screen's image). TRANSPARENT is an int value of
 *  0xFF000000. Because every image is a 1D array we have to transverse it as
 *  an abstraction of a 2D array, like so:
 *
 *  To the image's memory pointer we add how many rows to skip (y * line length)
 *  and how much to walk in that row (x * bits per pixel (normally 32bits)).
 *  We cast the first equation to an int pointer and dereference it to get the
 *  value stored in that location as an int. This color is checked against the
 *  macro, and if it is different, meaning it has some color, it is then drawn
 *  into the screen's image in the same position it was found, drawing on top of
 *  whatever was there before, thus creating the illusion of transparency!
 */
void	t_game_draw_animation(t_game *game, t_image *frame)
{
	int					x;
	int					y;
	unsigned int		color;

	y = 0;
	while (y < frame->height)
	{
		x = 0;
		while (x < frame->width)
		{
			color = *(int *)((frame->address) + (y * frame->line_length)
					+ (x * (frame->bpp / 8)));
			if (color != ALPHA)
				*(int *)(game->image->address + (y * game->image->line_length)
						+ (x * (frame->bpp / 8))) = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->image->image,
		0, 0);
}
