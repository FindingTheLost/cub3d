/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:20:13 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/05 01:50:32 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* In the second and third conditions, one can access the memory location of
 * a double-pointer struct member variable by using the "&(*struct)->variable".
 */
int	game_init_vars(t_cub *file, t_game **game)
{
	if (!t_game_populate(file, game))
	{
		t_cub_destroy(file);
		return (false);
	}
	if (!t_player_populate(file, &(*game)->player))
	{
		t_game_destroy(*game);
		t_cub_destroy(file);
		return (false);
	}
	if (!t_map_populate(file, &(*game)->map))
	{
		t_game_destroy(*game);
		t_cub_destroy(file);
		return (false);
	}
	if (!t_image_populate((*game)->mlx, W_WIDTH, W_HEIGHT, &(*game)->image))
	{
		t_game_destroy(*game);
		t_cub_destroy(file);
		return (false);
	}
	t_cub_destroy(file);
	return (true);
}
