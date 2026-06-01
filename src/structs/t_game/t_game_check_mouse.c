/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_check_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:20:22 by pde-alme          #+#    #+#             */
/*   Updated: 2026/06/02 00:43:29 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* In Debian, the function "mlx_mouse_move()" function does not seem to work,
 * it does not move the mouse to the center at all. A fix for this is to hide
 * the mouse with "mlx_mouse_hide()" function. Trouble is, this last function
 * leaks memory.
 *
 * Also, to test player orientation at game start in Debian, make sure the mouse
 * pointer does not become inside the window when booting the game, or else, it
 * will make the player look at the rotation value of the current mouse
 * position.
 *
 * In the "rat_ratio" expression, the divisor 100 can be changed for faster or
 * slower mouse movement.
 */
void	t_game_check_mouse(t_game *game)
{
	t_player	*player;
	float		rat_ratio;
	float		rotation_delta;

	if (game->mouse->x == -1 || game->key->ctrl)
		return ;
	player = game->player;
	rat_ratio = (game->mouse->x - (W_WIDTH / 2)) / ((float)W_WIDTH / 100);
	rotation_delta = ROTATION * t_game_delta(game) * MOUSE_MULTIPLIER;
	player->r = t_game_clamp_rotation(player->r + rotation_delta * rat_ratio);
	mlx_mouse_move(game->mlx, game->mlx_window, W_WIDTH / 2, W_HEIGHT / 2);
}
