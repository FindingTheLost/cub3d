/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:17:18 by pde-alme          #+#    #+#             */
/*   Updated: 2026/06/01 01:28:32 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Draws the current state of the game to the screen in a given frame. If in
 * minimap mode, draws the minimap window, if not, draws the player's raycasted
 * field of view.
 *
 * The fish_eye effect is set only if the FISH_EYE macro and the mask_on boolean
 * are both set to true.
 * Furthermore, it only draws the minimap if the player's helmet is equipped,
 * controlled by the mask_on boolean, which is set to true once the E key is 
 * pressed and the animation has played the amount of frames it has.
 * If the boolean is_playing is set to true it is only set to the opposite
 * once the whole animation has finished playing, and every frame it checks
 * if the mask_on boolean is active, to keep drawing the helmet's visor over
 * the player's raycasted field of view.
 *
 * The clamping to only draw if the animation frame is between 0 or frame_count
 * is needed because spamming E key will trigger a segfault by accessing an
 * out-of-bounds value of current_frame before it is reset when initialized.
 *
 * The t_anim variable "a" stands for animation, but has to be kept short in
 * order to complie with norminette rules. 
 */
static void	draw(t_game *game)
{
	t_anim	*a;

	a = game->helmet_anim;
	if (game->key->m && (a->current_frame == a->frame_count - 1))
		t_game_minimap_show(game);
	else
	{
		if (FISH_EYE)
		{
			if (a->mask_on && (a->current_frame < a->frame_count - 1))
				game->fish_eye = false;
			else if (a->mask_on || (a->current_frame == a->frame_count - 1))
				game->fish_eye = true;
			else
				game->fish_eye = false;
		}
		t_game_cube_show(game);
		if ((a->is_playing || a->mask_on) && a->current_frame >= 0
			&& a->current_frame <= a->frame_count - 1)
			t_game_draw_transparent(game, a->frames[a->current_frame]);
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
	t_game_update_animation(game);
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
	draw(game);
	return (0);
}
