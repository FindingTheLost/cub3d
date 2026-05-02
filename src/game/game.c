/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:26:44 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 02:20:20 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game(t_cub *file)
{
	t_game		*game;
	t_player	*player;
	t_map		*map;

	if (!game_init_vars(&file, &game, &player, &map))
		return (false);
	t_game_destroy(game);
	t_player_destroy(player);
	t_map_destroy(map);
	return (true);
}
