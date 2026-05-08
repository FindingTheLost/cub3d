/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:12:16 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/08 01:58:52 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	clamp_rotation(t_player *player)
{
	if (player->r >= M_PI * 2)
		player->r -= M_PI * 2;
	else if (player->r <= 0)
		player->r += M_PI * 2;
}

static int	check_collision(t_game *game, char *direction)
{
	char	**map;

	map = game->map->map;
	if (ft_strbcmp(direction, "w")
		&& map[(int)(game->player->y + sinf(game->player->r)
			* SPEED)][(int)(game->player->x + cosf(game->player->r) * SPEED)] == '1')
		return (false);
	else if (ft_strbcmp(direction, "s")
		&& map[(int)(game->player->y - sinf(game->player->r)
			* SPEED)][(int)(game->player->x - cosf(game->player->r) * SPEED)] == '1')
		return (false);
	else if (ft_strbcmp(direction, "a")
		&& map[(int)(game->player->y + sinf(game->player->r)
			* SPEED)][(int)(game->player->x - cosf(game->player->r) * SPEED)] == '1')
		return (false);
	else if (ft_strbcmp(direction, "d")
		&& map[(int)(game->player->y - sinf(game->player->r)
			* SPEED)][(int)(game->player->x + cosf(game->player->r) * SPEED)] == '1')
		return (false);
	return (true);
}

static void	check_keys(t_game *game)
{
	if (game->key->w && check_collision(game, "w"))
	{
		game->player->x += cosf(game->player->r) * SPEED;
		game->player->y += sinf(game->player->r) * SPEED;
	}
	if (game->key->s && check_collision(game, "s"))
	{
		game->player->x -= cosf(game->player->r) * SPEED;
		game->player->y -= sinf(game->player->r) * SPEED;
	}
	if (game->key->a && check_collision(game, "a"))
	{
		game->player->x -= cosf(game->player->r) * SPEED;
		game->player->y += sinf(game->player->r) * SPEED;
	}
	if (game->key->d && check_collision(game, "d"))
	{
		game->player->x += cosf(game->player->r) * SPEED;
		game->player->y -= sinf(game->player->r) * SPEED;
	}
	if (game->key->left)
	{
		game->player->r -= ROTATION;
		clamp_rotation(game->player);
	}
	if (game->key->right)
	{
		game->player->r += ROTATION;
		clamp_rotation(game->player);
	}
}

int	game_update(t_game *game)
{
	check_keys(game);
	t_game_minimap_show(game);
	return (0);
}
