/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:55:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 22:11:02 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static int	color_array_to_int(unsigned char color[3])
{
	int	converted;

	converted = 0;
	converted = ((converted >> 16) + color[0]) << 16;
	converted = ((converted >> 8) + color[1]) << 8;
	converted += color[2];
	return (converted);
}

void	t_game_init_colors(t_cub *file, t_game *game)
{
	game->f_color = color_array_to_int(file->f_color);
	game->c_color = color_array_to_int(file->c_color);
}
