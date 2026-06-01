/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 02:55:07 by rogde-so          #+#    #+#             */
/*   Updated: 2026/06/01 23:32:53 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* We first check if the animation is playing, if it isn't we don't update.
 * If the animation is_playing flag was set to true once the E key was pressed
 * we first save the frames timing in a current_time variable based on the
 * games new delta variable previously updated, and we use this time to check if
 * we can draw the next frame of animation. The first frame is drawn immediately
 * because the value of last_frame_time was not yet updated, so the huge number
 * that is saved in current_time will always be bigger than the ANIMATION_SPEED
 * macro in it's first cycle.
 * The current frame being played is based on the direction the animations is
 * playing, either forward or backwards. If the animation has taken its course,
 * meaning that all frames were drawn it then flips the mask_on boolean, to
 * indicate that the helmet is either on or off, and it clamps the current_frame
 * to the correct position for future calls.
 */
void	t_anim_update(t_anim *anim, struct timeval new_delta)
{
	long	current_time;

	if (!anim->is_playing)
		return ;
	current_time = new_delta.tv_sec * 1000000 + new_delta.tv_usec;
	if (current_time - anim->last_frame_time < ANIMATION_SPEED)
		return ;
	anim->last_frame_time = current_time;
	anim->current_frame += anim->direction;
	if (anim->current_frame >= anim->frame_count || anim->current_frame < 0)
	{
		anim->is_playing = false;
		anim->mask_on = ft_fbool(anim->mask_on);
		if (anim->current_frame >= anim->frame_count)
			anim->current_frame = anim->frame_count - 1;
		else
			anim->current_frame = 0;
	}
}
