/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:07:13 by rogde-so          #+#    #+#             */
/*   Updated: 2026/05/27 13:07:13 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_anim_struct.h"

void	t_anim_destroy(void *mlx, t_anim *anim)
{
	int	i;

	i = 0;
	while (i < anim->frame_count)
		t_image_destroy(mlx, anim->frames[i++]);
	free(anim->frames);
	free(anim);
}
