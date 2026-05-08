/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:12:16 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/07 22:26:31 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_collision(t_game *game, char *direction)
{
	char	**map;

	map = game->map->map;
	if (ft_strbcmp(direction, "up"))
	{
		if (map[(int)(game->player->y - SPEED)][(int)game->player->x] == '1')
			return (false);
	}
	else if (ft_strbcmp(direction, "down"))
	{
		if (map[(int)(game->player->y + SPEED)][(int)game->player->x] == '1')
			return (false);
	}
	else if (ft_strbcmp(direction, "left"))
	{
		if (map[(int)game->player->y][(int)(game->player->x - SPEED)] == '1')
			return (false);
	}
	else if (ft_strbcmp(direction, "right"))
	{
		if (map[(int)game->player->y][(int)(game->player->x + SPEED)] == '1')
			return (false);
	}
	return (true);
}

static void	check_keys(t_game *game)
{
	if (game->key->up)
	{
		if (check_collision(game, "up"))
			game->player->y -= SPEED;
	}
	if (game->key->down)
	{
		if (check_collision(game, "down"))
			game->player->y += SPEED;
	}
	if (game->key->left)
	{
		if (check_collision(game, "left"))
			game->player->x -= SPEED;
	}
	if (game->key->right)
	{
		if (check_collision(game, "right"))
			game->player->x += SPEED;
	}
}

int	game_update(t_game *game)
{
	check_keys(game);
	t_game_minimap_show(game);
	return (0);
}
