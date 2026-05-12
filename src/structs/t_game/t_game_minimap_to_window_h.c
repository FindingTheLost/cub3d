/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_minimap_to_window_h.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:26:30 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/12 20:45:59 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* These equations become mirrored when in "t_game_minimap_to_window_v"
 * (vertical). All 'x' positive and negative formulas become 'y's (with every
 * occcurrence of "width" turned to "height") and vice-versa.
 */
static void	odd_map_height(t_game *game, int *y, size_t tile)
{
	float	twocent_height;

	twocent_height = game->player->y / (float)(game->map->map_height / 2);
	if (twocent_height > 1)
		*y = -(fabs(((float)(2 - twocent_height)) - 1)
				* ((tile * (game->map->map_height - 1)) / 2));
	else
		*y = fabs((float)(twocent_height - 1))
			* ((tile * (game->map->map_height - 1)) / 2);
}

static void	even_map_height(t_game *game, int *y, size_t tile)
{
	float	twocent_height;

	twocent_height = game->player->y / (float)(game->map->map_height / 2);
	if (twocent_height > 1)
		*y = -(fabs(((float)(2 - twocent_height)) - 1)
				* ((tile * (game->map->map_height)) / 2));
	else
		*y = fabs((float)(twocent_height - 1))
			* ((tile * (game->map->map_height)) / 2);
}

static void	odd_map_width(t_game *game, int *x, int *y, size_t tile)
{
	float	twocent_width;

	twocent_width = game->player->x / (float)(game->map->map_width / 2);
	if (twocent_width > 1)
		*x = -(fabs(((float)(2 - twocent_width)) - 1)
				* ((tile * game->map->map_width - (W_WIDTH
							- (tile * game->map->map_width - tile))) / 2)) + (tile / 2);
	else
		*x = fabs((float)(twocent_width - 1))
			* ((tile * game->map->map_width - (W_WIDTH
						- (tile * game->map->map_width - tile))) / 2) + (tile / 2);
	if (game->map->map_height % 2 == 0)
		even_map_height(game, y, tile);
	else
		odd_map_height(game, y, tile);
}

static void	even_map_width(t_game *game, int *x, int *y, size_t tile)
{
	float	twocent_width;

	twocent_width = game->player->x / (float)(game->map->map_width / 2);
	if (twocent_width > 1)
		*x = -(fabs(((float)(2 - twocent_width)) - 1)
				* ((tile * game->map->map_width - (W_WIDTH
							- (tile * game->map->map_width))) / 2));
	else
		*x = fabs((float)(twocent_width - 1))
			* ((tile * game->map->map_width - (W_WIDTH
						- (tile * game->map->map_width))) / 2);
	if (game->map->map_height % 2 == 0)
		even_map_height(game, y, tile);
	else
		odd_map_height(game, y, tile);
}

void	t_game_minimap_to_window_h(t_game *game, int *x, int *y)
{
	size_t	tile;

	tile = W_WIDTH / game->map->map_width;
	if (game->map->map_width % 2 == 0)
		even_map_width(game, x, y, tile);
	else
		odd_map_width(game, x, y, tile);
}
