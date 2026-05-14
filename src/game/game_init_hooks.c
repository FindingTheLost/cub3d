/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:37:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/14 02:34:03 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "src/structs/t_game_struct.h"

static int	on_window_close(t_game *game)
{
	t_game_destroy(game);
	exit(0);
	return (0);
}

static int	on_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (game->key->mouse_x != -1)
	{
		if (x > game->key->mouse_x)
			game->key->mouse_axis = 1;
		else if (x < game->key->mouse_x)
			game->key->mouse_axis = -1;
		else
			game->key->mouse_axis = 0;
	}
	game->key->mouse_x = x;
	return(0);
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
	else if (key_symbol == K_LEFT)
		game->key->left = false;
	else if (key_symbol == K_RIGHT)
		game->key->right = false;
	else if (key_symbol == K_SPACE)
		game->key->space = false;
	else if (key_symbol == K_M)
		game->key->m = ft_fbool(game->key->m);
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
	else if (key_symbol == K_SPACE)
		game->key->space = true;
	return (0);
}

/* The "second" parameter in "mlx_hook" is the hooking event.
 * The "third" parameter in "mlx_hook" is the event mask.
 * The "fourth" parameter is always a pointer to a function that returns int.
 *
 * Since minilibx does not posess holding key behaviours, it had to be hard
 * coded with booleans. It becomes "true" when a key is held down and back
 * to "false" when released, for all four directions.
 */
void	game_init_hooks(t_game *game)
{
	mlx_hook(game->mlx_window, ON_DESTROY, NO_EVENT, &on_window_close, game);
	mlx_hook(game->mlx_window, ON_KEYDOWN, KEY_PRESS, &on_key_press, game);
	mlx_hook(game->mlx_window, ON_KEYUP, KEY_RELEASE, &on_key_release, game);
	mlx_hook(game->mlx_window, ON_KEYUP, KEY_RELEASE, &on_key_release, game);
	mlx_hook(game->mlx_window, MOUSE_MOVE, MOUSE_MOTION, &on_mouse_move, game);
	mlx_loop_hook(game->mlx, &game_update, game);
	//mlx_mouse_hide(game->mlx, game->mlx_window);
}
