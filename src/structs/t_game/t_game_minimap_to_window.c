/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_minimap_to_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:27:24 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/22 19:51:45 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

void	t_game_minimap_to_window(t_game *game, int *x, int *y, int orientation)
{
	float	tile;
	float	x_ratio;
	float	y_ratio;

	if (orientation)
		tile = W_WIDTH / game->map->map_width;
	else
		tile = W_HEIGHT / game->map->map_height;
	x_ratio = -(2 * game->player->x / game->map->map_width - 1);
	*x = x_ratio * (W_WIDTH - (W_WIDTH - (tile * game->map->map_width / 2)));
	y_ratio = -(2 * game->player->y / game->map->map_height - 1);
	*y = y_ratio * (W_HEIGHT - (W_HEIGHT - (tile * game->map->map_height / 2)));
}
