/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_check_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 01:39:53 by rogde-so          #+#    #+#             */
/*   Updated: 2026/05/14 02:39:25 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"
#include "minilibx-linux/mlx.h"

/* Clamps the rotation of the player in case the "rotation" variable becomes
 * over-increased or over-decreased by the "ROTATION" macro.
 */
static float	clamp_rotation(float rotation)
{
	if (rotation >= M_PI * 2)
		rotation -= M_PI * 2;
	else if (rotation <= 0)
		rotation += M_PI * 2;
	return (rotation);
}

void	t_game_check_mouse(t_game *game)
{
	float	rotation_delta;
	int		x;
	int		y;

	rotation_delta = ROTATION * t_game_delta(game) * MOUSE_MULTIPLIER ;
	if (game->key->mouse_axis == 1)
		game->player->r = clamp_rotation(game->player->r + rotation_delta);
	else if (game->key->mouse_axis == -1)
		game->player->r = clamp_rotation(game->player->r - rotation_delta);
	else
		mlx_mouse_move(game->mlx, game->mlx_window, W_WIDTH / 2, W_HEIGHT / 2);
	mlx_mouse_get_pos(game->mlx, game->mlx_window, &x, &y);
	if (x == 0 || x == W_WIDTH || y == 0 || y == W_HEIGHT)
		mlx_mouse_move(game->mlx, game->mlx_window, W_WIDTH / 2, W_HEIGHT / 2);
	game->key->mouse_axis = 0;
}