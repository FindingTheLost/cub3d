/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:12:16 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/08 05:36:03 by rogde-so         ###   ########.fr       */
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
			* SPEED)][(int)(game->player->x
				+ cosf(game->player->r) * SPEED)] == '1')
		return (false);
	else if (ft_strbcmp(direction, "s")
		&& map[(int)(game->player->y - sinf(game->player->r)
			* SPEED)][(int)(game->player->x
				- cosf(game->player->r) * SPEED)] == '1')
		return (false);
	else if (ft_strbcmp(direction, "a")
		&& map[(int)(game->player->y - cosf(game->player->r)
			* SPEED)][(int)(game->player->x
				+ sinf(game->player->r) * SPEED)] == '1')
		return (false);
	else if (ft_strbcmp(direction, "d")
		&& map[(int)(game->player->y + cosf(game->player->r)
			* SPEED)][(int)(game->player->x
				- sinf(game->player->r) * SPEED)] == '1')
		return (false);
	return (true);
}

static void	player_movement_update(t_player *player, char key)
{
	if (key == 'w')
	{
		player->x += cosf(player->r) * SPEED;
		player->y += sinf(player->r) * SPEED;
	}
	else if (key == 's')
	{
		player->x -= cosf(player->r) * SPEED;
		player->y -= sinf(player->r) * SPEED;
	}
	else if (key == 'a')
	{
		player->x += sinf(player->r) * SPEED;
		player->y -= cosf(player->r) * SPEED;
	}
	else if (key == 'd')
	{
		player->x -= sinf(player->r) * SPEED;
		player->y += cosf(player->r) * SPEED;
	}
}

static void	check_keys(t_game *game)
{
	if (game->key->w && check_collision(game, "w"))
		player_movement_update(game->player, 'w');
	if (game->key->s && check_collision(game, "s"))
		player_movement_update(game->player, 's');
	if (game->key->a && check_collision(game, "a"))
		player_movement_update(game->player, 'a');
	if (game->key->d && check_collision(game, "d"))
		player_movement_update(game->player, 'd');
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
