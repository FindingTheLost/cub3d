/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:20:13 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/07 22:25:38 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* In the second and third conditions, one can access the memory location of
 * a double-pointer struct member variable by using the "&(*struct)->variable".
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
