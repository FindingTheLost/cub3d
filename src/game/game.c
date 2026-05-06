/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:26:44 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 01:47:12 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* To debug the "file" and "game" structs and all of its contents, use the
 * functions, respectively:
 * 		"t_cub_debug(file)";
 * 		"t_game_debug(game)";
 */
int	game(t_cub *file)
{
	t_game		*game;

	if (!game_init_vars(file, &game))
		return (false);
	game_init_hooks(game);
	mlx_loop(game->mlx);
	return (true);
}
