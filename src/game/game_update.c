/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:12:16 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/08 23:15:54 by pde-alme         ###   ########.fr       */
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

static int	check_tile(t_map *map, int x, int y)
{
	if (map->map[y][x] == '1' || map->map[y][x] == ' ')
		return (true);
	return (false);
}

static int	check_collision(t_player *p, t_map *m, char *direction)
{
	if (ft_strbcmp(direction, "w"))
	{
		if (check_tile(m, p->x + cosf(p->r) * SPEED, p->y + sinf(p->r) * SPEED))
			return (false);
	}
	else if (ft_strbcmp(direction, "s"))
	{
		if (check_tile(m, p->x - cosf(p->r) * SPEED, p->y - sinf(p->r) * SPEED))
			return (false);
	}
	else if (ft_strbcmp(direction, "a"))
	{
		if (check_tile(m, p->x + sinf(p->r) * SPEED, p->y - cosf(p->r) * SPEED))
			return (false);
	}
	else if (ft_strbcmp(direction, "d"))
	{
		if (check_tile(m, p->x - sinf(p->r) * SPEED, p->y + cosf(p->r) * SPEED))
			return (false);
	}
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
	if (game->key->w && check_collision(game->player, game->map, "w"))
		player_movement_update(game->player, 'w');
	if (game->key->s && check_collision(game->player, game->map, "s"))
		player_movement_update(game->player, 's');
	if (game->key->a && check_collision(game->player, game->map, "a"))
		player_movement_update(game->player, 'a');
	if (game->key->d && check_collision(game->player, game->map, "d"))
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
