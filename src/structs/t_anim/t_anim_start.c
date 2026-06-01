/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 02:55:07 by rogde-so          #+#    #+#             */
/*   Updated: 2026/06/01 23:25:32 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* This function is called when the E key is pressed and if the is_playing bool
 * is set to false, this way the animation only plays once per press and allows
 * itself to finish all the frames without overlapping. It flips the E key bool
 * an acertains which direction the animation is being played, if the helmet is
 * being equipped or unequipped. The direction int is the step to the next frame
 * and the current_frame is set to where it should start playing.
 */
int	t_anim_start(t_anim *anim, int key)
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
