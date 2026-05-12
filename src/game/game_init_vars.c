/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:20:13 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/11 17:34:17 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* It's possible to access the memory location of a double-pointer struct
 * member variable by doing "&(*struct)->variable".
 *
 * Creates a brand new instance of (in this order):
 * - "t_game"	- (the game);
 * - "t_player" - (the player);
 * - "t_map"	- (the map);
 * - "t_image"	- (the raycasted viewport);
 * - "t_image"	- (the minimap);
 * - "t_image"	- (the background for the minimap);
 *
 * Then paints the minimap's background image to black (0). And frees the
 * "t_cub" struct representing the ".cub" file passed as parameter.
 */
int	game_init_vars(t_cub *file, t_game **game)
{
	if (!t_game_populate(file, game))
		return (t_cub_destroy(file), false);
	if (!t_player_populate(file, &(*game)->player))
		return (t_game_destroy(*game), t_cub_destroy(file), false);
	if (!t_map_populate(file, &(*game)->map))
		return (t_game_destroy(*game), t_cub_destroy(file), false);
	if (!t_image_populate((*game)->mlx, W_WIDTH, W_HEIGHT, &(*game)->image))
		return (t_game_destroy(*game), t_cub_destroy(file), false);
	if (!t_image_populate((*game)->mlx, W_WIDTH, W_HEIGHT, &(*game)->minimap))
		return (t_game_destroy(*game), t_cub_destroy(file), false);
	if (!t_image_populate((*game)->mlx, W_WIDTH, W_HEIGHT,
			&(*game)->minimap_background))
		return (t_game_destroy(*game), t_cub_destroy(file), false);
	t_game_draw_background((*game)->minimap_background, W_WIDTH, W_HEIGHT, 0);
	if (!t_key_populate(&(*game)->key))
		return (t_game_destroy(*game), t_cub_destroy(file), false);
	t_cub_destroy(file);
	return (true);
}
