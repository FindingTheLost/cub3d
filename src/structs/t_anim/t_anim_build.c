/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:07:01 by rogde-so          #+#    #+#             */
/*   Updated: 2026/06/01 23:48:23 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_anim_struct.h"

t_anim	*t_anim_build(void)
{
	t_anim	*anim;
	int		i;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (t_anim_malloc_error(), NULL);
	anim->mask_on = false;
	anim->frame_count = 14;
	anim->current_frame = 0;
	anim->is_playing = false;
	anim->direction = 0;
	anim->last_frame_time = 0;
	anim->frames = malloc(sizeof(t_image *) * (anim->frame_count + 1));
	if (!anim->frames)
		return (free(anim), t_anim_malloc_error(), NULL);
	i = 0;
	while (i < anim->frame_count + 1)
		anim->frames[i++] = NULL;
	return (anim);
}
