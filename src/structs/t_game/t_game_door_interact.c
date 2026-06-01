/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_door_interact.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 19:50:24 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 20:13:22 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* Function that changes the state of the door if it's an opened or closed door
 * tile and if the player is not standing within it.
 */
void	t_game_door_interact(t_game *game, int x, int y, float dist)
{
	if (dist < DOOR_OPEN_DIST)
	{
		if (x != (int)game->player->x || y != (int)game->player->y)
		{
			if (game->map->map[y][x] == 'D')
				game->map->map[y][x] = 'O';
			else if (game->map->map[y][x] == 'O')
				game->map->map[y][x] = 'D';
		}
	}
}
