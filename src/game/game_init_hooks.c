/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:37:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 02:01:19 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	on_window_close(t_game *game)
{
	t_game_destroy(game);
	exit(0);
	return (0);
}

/* The "ON_KEYUP" event always sends an int as parameter to identify the key
 * code.
 */
static int	on_key_release(int key_symbol, t_game *game)
{
	if (key_symbol == ESC_KEY)
		on_window_close(game);
	return (0);
}

/* The "ON_KEYDOWN" event always sends an int as parameter to identify the key
 * code.
 */
static int	on_key_press(int key_symbol, t_game *game)
{
	if (key_symbol == UP_KEY)
		game->player->y -= 0.1f;
	if (key_symbol == DOWN_KEY)
		game->player->y += 0.1f;
	if (key_symbol == LEFT_KEY)
		game->player->x -= 0.1f;
	if (key_symbol == RIGHT_KEY)
		game->player->x += 0.1f;
	return (0);
}

/* The "second" parameter in "mlx_hook" is the hooking event.
 * The "third" parameter in "mlx_hook" is the event mask.
 * The "fourth" parameter is always a pointer to a function that returns int.
 */
void	game_init_hooks(t_game *game)
{
	mlx_hook(game->mlx_window, ON_DESTROY, NO_EVENT, &on_window_close, game);
	mlx_hook(game->mlx_window, ON_KEYUP, KEY_RELEASE, &on_key_release, game);
	mlx_hook(game->mlx_window, ON_KEYDOWN, KEY_PRESS, &on_key_press, game);
	mlx_loop_hook(game->mlx, &game_update, game);
}
