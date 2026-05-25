/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_minimap_to_center.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:27:24 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/24 22:09:38 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	add_horizontal_offset(t_game *game, int *x)
{
	size_t	tile;

	tile = (W_HEIGHT / game->map->map_height) * game->map->map_width;
	*x += (W_WIDTH - tile) / 2;
}

static void	add_vertical_offset(t_game *game, int *y)
{
	size_t	tile;

	tile = (W_WIDTH / game->map->map_width) * game->map->map_height;
	*y += (W_HEIGHT - tile) / 2;
}

/* After the minimap and player are drawn, manipulate the 'x' and 'y'
 * coordenates to determine where the minimap window will be presented in the
 * display window based on where the player is currently situated, giving the
 * illusion of minimap movement when the player moves.
 */
void	t_game_minimap_to_center(t_game *game, int *x, int *y, int orientation)
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
	if (orientation)
		add_vertical_offset(game, y);
	else
		add_horizontal_offset(game, x);
}
