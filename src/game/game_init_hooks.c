/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:37:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/06/02 00:35:41 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	on_window_close(t_game *game)
{
	t_game_destroy(game);
	exit(0);
	return (0);
}

/* The "ON_MOTION" (motion notify) event, always sends two ints as parameters
 * to identify 'x' and 'y' mouse positions in the window.
 */
static int	on_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (game->mouse->x == x)
		game->mouse->x = -1;
	else
		game->mouse->x = x;
	return (0);
}

/* The "ON_KEYUP" event always sends an int as parameter to identify the key
 * code.
 */
static int	on_key_release(int key_symbol, t_game *game)
{
	if (key_symbol == K_UP || key_symbol == K_W)
		game->key->w = false;
	else if (key_symbol == K_DOWN || key_symbol == K_S)
		game->key->s = false;
	else if (key_symbol == K_A)
		game->key->a = false;
	else if (key_symbol == K_D)
		game->key->d = false;
	else if (key_symbol == K_M)
		game->key->m = ft_fbool(game->key->m);
	else if (key_symbol == K_LEFT)
		game->key->left = false;
	else if (key_symbol == K_RIGHT)
		game->key->right = false;
	else if (key_symbol == K_CTRL)
		game->key->ctrl = false;
	else if (key_symbol == K_SHIFT)
		game->key->shift = false;
	else if (key_symbol == K_E && !game->helmet->is_playing)
		game->key->e = t_anim_start(game->helmet, game->key->e);
	return (0);
}

/* The "ON_KEYDOWN" event always sends an int as parameter to identify the key
 * code.
 */
static int	on_key_press(int key_symbol, t_game *game)
{
	if (key_symbol == K_ESC)
		on_window_close(game);
	else if (key_symbol == K_UP || key_symbol == K_W)
		game->key->w = true;
	else if (key_symbol == K_DOWN || key_symbol == K_S)
		game->key->s = true;
	else if (key_symbol == K_A)
		game->key->a = true;
	else if (key_symbol == K_D)
		game->key->d = true;
	else if (key_symbol == K_LEFT)
		game->key->left = true;
	else if (key_symbol == K_RIGHT)
		game->key->right = true;
	else if (key_symbol == K_CTRL)
		game->key->ctrl = true;
	else if (key_symbol == K_SPACE)
		t_game_door_dda(game);
	else if (key_symbol == K_SHIFT)
		game->key->shift = true;
	return (0);
}

/* The "second" parameter in "mlx_hook" is the hooking event.
 * The "third" parameter in "mlx_hook" is the event mask.
 * The "fourth" parameter is always a pointer to a function that returns int.
 *
 * Since minilibx does not possess key holding handlers, it had to be hard
 * coded with booleans. It becomes "true" when a key is held down and back
 * to "false" when released, for all four directions.
 *
 * The function "mlx_mouse_hide()" has leaks. A mouse_hide.supp file is provided
 * to suppress them. Test without the function to check if no leaks are
 * present.
 *
 * A fix was found and posted in the "minilibx" github page at:
 * "https://github.com/42paris/minilibx-linux/issues/48".
 * It involves commenting the previous code in two function of "mlx_mouse.c" and
 * adding "-lXfixes" to "cub3D"'s Makefile. Although fixed, the mouse becomes
 * hidden even when pressing the unhide mouse key of this project ("CTRL").
 * 
 * These minilibx changes were not applied to this project. Although the fix's
 * code lines are present but commented, for possible future use.
 */
void	game_init_hooks(t_game *game)
{
	mlx_hook(game->mlx_window, ON_DESTROY, NO_EVENT, &on_window_close, game);
	mlx_hook(game->mlx_window, ON_KEYDOWN, KEY_PRESS, &on_key_press, game);
	mlx_hook(game->mlx_window, ON_KEYUP, KEY_RELEASE, &on_key_release, game);
	mlx_hook(game->mlx_window, ON_MOTION, PTR_MOTION, &on_mouse_move, game);
	mlx_loop_hook(game->mlx, &game_update, game);
	mlx_mouse_hide(game->mlx, game->mlx_window);
}
