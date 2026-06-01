/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:07:01 by rogde-so          #+#    #+#             */
/*   Updated: 2026/05/27 13:07:01 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_anim_struct.h"

t_anim	*t_anim_build(void)
{
	t_anim *anim;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (t_anim_malloc_error(), NULL);
	anim->mask_on = false;
	anim->is_playing = false;
	anim->current_frame = 0;
	anim->direction = 0;
	anim->last_frame_time = 0;
	anim->frame_count = 14;
	anim->frames = malloc(sizeof(t_image *) * (14 + 1));
	if (!anim->frames)
		return (free(anim), t_anim_malloc_error(), NULL);
	return (anim);
}
