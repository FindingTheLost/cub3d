/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_check_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:20:22 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/17 20:25:01 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

void	t_game_check_mouse(t_game *game)
{
	t_player	*player;
	float		rotation_delta;

	player = game->player;
	rotation_delta = ROTATION * t_game_delta(game) * MOUSE_MULTIPLIER;
	if (game->mouse->x_dir == 1)
		player->r = t_game_clamp_rotation(player->r + rotation_delta);
	else if (game->mouse->x_dir == -1)
		player->r = t_game_clamp_rotation(player->r - rotation_delta);
	else
		mlx_mouse_move(game->mlx, game->mlx_window, W_WIDTH / 2, W_HEIGHT / 2);
	game->mouse->x_dir = 0;
}
