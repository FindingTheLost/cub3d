/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_animate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 02:55:07 by rogde-so          #+#    #+#             */
/*   Updated: 2026/05/29 02:55:07 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* We first check if the animation is playing, if it isn't we don't update.
*  If the animation is_playing flag was set to true once the E key was pressed
*  we first save the frames timing in a current_time variable based on the
*  games new delta variable previously updated, and we use this time to check if
*  we can draw the next frame of animation. The first frame is drawn immediately
*  because the value of last_frame_time was not yet updated, so the huge number
*  that is saved in current_time will always be bigger than the ANIMATION_SPEED
*  macro in it's first cycle.
*  The current frame being played is based on the direction the animations is
*  playing, either forward or backwards. If the animation has taken its course,
*  meaning that all frames were drawn it then flips the mask_on boolean, to
*  indicate that the helmet is either on or off, and it clamps the current_frame
*  to the correct position for future calls.
*/
void	t_game_update_animation(t_game *game)
{
	t_anim	*anim;
	long	current_time;

	anim = game->helmet_anim;
	if (!anim->is_playing)
		return ;
	current_time = (game->new_delta.tv_sec * 1000000) + game->new_delta.tv_usec;
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

/* This function is called when the E key is pressed and if the is_playing bool
*  is set to false, this way the animation only plays once per press and allows
*  itself to finish all the frames without overlapping. It flips the E key bool
*  an acertains which direction the animation is being played, if the helmet is
*  being equipped or unequipped. The direction int is the step to the next frame
*  and the current_frame is set to where it should start playing.
*/
int	t_game_init_animation(t_anim *anim, int key)
{
	anim->is_playing = true;
	if (!key)
	{
		anim->direction = 1;
		anim->current_frame = -1;
	}
	else
	{
		anim->direction = -1;
		anim->current_frame = anim->frame_count - 1;
	}
	return (ft_fbool(key));
}
