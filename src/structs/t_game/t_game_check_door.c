/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_check_door.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:04:45 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 01:30:46 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void open_close_door(t_game *game, int map_x, int map_y)
{
	if (game->map->map[map_y][map_x] == 'D')
		game->map->map[map_y][map_x] = 'O';
	else if (game->map->map[map_y][map_x] == 'O')
		game->map->map[map_y][map_x] = 'D';
}

static void	check_door(t_game *game, int map_x, int map_y)
{
	if (map_x == (int)game->player->x + 1 && map_y == (int)game->player->y + 1)
	{
		if (game->player->r > M_PI_2 / 2)
			open_close_door(game, map_x - 1, map_y);
		else
			open_close_door(game, map_x, map_y - 1);
	}
	else if (map_x == (int)game->player->x - 1 && map_y == (int)game->player->y + 1)
	{
		if (game->player->r > M_PI - (M_PI_2 / 2))
			open_close_door(game, map_x, map_y - 1);
		else
			open_close_door(game, map_x + 1, map_y);
	}
	else if (map_x == (int)game->player->x - 1 && map_y == (int)game->player->y - 1)
	{
		if (game->player->r > M_PI + (M_PI_2 / 2))
			open_close_door(game, map_x + 1, map_y);
		else
			open_close_door(game, map_x, map_y + 1);
	}
	else if (map_x == (int)game->player->x + 1 && map_y == (int)game->player->y - 1)
	{
		if (game->player->r > (M_PI * 2) - (M_PI_2 / 2))
			open_close_door(game, map_x, map_y + 1);
		else
			open_close_door(game, map_x - 1, map_y);
	}
	else
		open_close_door(game, map_x, map_y);
}

void	t_game_check_door(t_game *game)
{
	float	map_x;
	float	map_y;

	map_x = game->player->x;
	map_y = game->player->y;
	check_door(game, map_x + roundf(cosf(game->player->r) / 1.6), map_y + roundf(sinf(game->player->r) / 1.6));
}
