/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:17:18 by pde-alme          #+#    #+#             */
/*   Updated: 2026/06/01 23:49:51 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Draws the current state of the game to the screen in a given frame. If in
 * minimap mode, draws the minimap window, if not, draws the player's raycasted
 * field of view.
 */
static void	draw(t_game *game, t_anim *helmet)
{
	if (game->key->m && (helmet->current_frame == helmet->frame_count - 1))
		t_game_minimap_show(game);
	else
	{
		t_game_cube_show(game);
		if ((helmet->is_playing || helmet->mask_on)
			&& helmet->current_frame <= helmet->frame_count - 1
			&& helmet->current_frame >= 0)
			t_game_draw_animation(game, helmet->frames[helmet->current_frame]);
	}
}

/* Updates the game's logic in a given frame. Starts by updating the time of
 * day (to perform calculations with frame delta - how long it took between the
 * previously drawn frame to the current one, in milliseconds) checking for key
 * and mouse inputs and then stores the current time in a variable so it can be
 * read in the next frame.
 */
static void	update(t_game *game)
{
	gettimeofday(&game->new_delta, NULL);
	t_game_check_keys(game);
	t_game_check_mouse(game);
	t_anim_update(game->helmet, game->new_delta);
	game->delta = game->new_delta;
}

/* Function that is called frame by frame by "minilibx"'s loop hook. Since
 * "minilibx" does not have vertical synchronization (v-sync) on linux, there
 * is no way to tightly limit the number of frames produced (logic and drawing)
 * to the monitor's refresh-rate.
 */
int	game_update(t_game *game)
{
	update(game);
	draw(game, game->helmet);
	return (0);
}
