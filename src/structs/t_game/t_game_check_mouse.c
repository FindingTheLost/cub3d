/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_check_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:20:22 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/18 22:20:20 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

void	t_game_check_mouse(t_game *game)
{
	t_player	*player;
	float		rat_ratio;
	float		rotation_delta;

	if (game->key->ctrl)
		return ;
	player = game->player;
	rat_ratio = (game->mouse->x - (W_WIDTH / 2)) / MOUSE_DIVISOR;
	rotation_delta = ROTATION * t_game_delta(game) * MOUSE_MULTIPLIER;
	player->r = t_game_clamp_rotation(player->r + rotation_delta * rat_ratio);
	mlx_mouse_move(game->mlx, game->mlx_window, W_WIDTH / 2, W_HEIGHT / 2);
}
