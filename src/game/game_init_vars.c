/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:20:13 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 02:15:31 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_init_vars(t_cub **file, t_game **game, t_player **player, t_map **map)
{
	if (!t_game_populate(*file, game))
	{
		t_cub_destroy(*file);
		return (false);
	}
	if (!t_player_populate(*file, player))
	{
		t_game_destroy(*game);
		t_cub_destroy(*file);
		return (false);
	}
	if (!t_map_populate(*file, map))
	{
		t_player_destroy(*player);
		t_game_destroy(*game);
		t_cub_destroy(*file);
		return (false);
	}
	t_cub_destroy(*file);
	*file = NULL;
	return (true);
}
