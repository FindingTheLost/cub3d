/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:07:48 by rogde-so          #+#    #+#             */
/*   Updated: 2026/05/27 13:07:48 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_anim_struct.h"

void	t_anim_debug(t_anim *anim)
{
	int	i;

	i = 0;
	ft_printf(RED_BOLD "T_ANIM STRUCT DEBUG:\n" DEF);
	if (anim)
		ft_printf("animation: present.\n");
	else
		ft_printf("animation: not present.\n");
	ft_printf("Mask On: %i\n", anim->mask_on);
	ft_printf("Direction: %i\n", anim->direction);
	ft_printf("Is playing: %i\n", anim->is_playing);
	ft_printf("Frame count: %i\n", anim->frame_count);
	ft_printf("Current frame: %i\n", anim->current_frame);
	ft_printf("Last fram time: %i\n", anim->last_frame_time);
	while (anim->frames[i])
		t_image_debug(anim->frames[i++]);
}
