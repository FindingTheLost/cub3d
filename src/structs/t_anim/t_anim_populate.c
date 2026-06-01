/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_populate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:13:23 by rogde-so          #+#    #+#             */
/*   Updated: 2026/06/01 23:49:14 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_anim_struct.h"

int	t_anim_populate(void *mlx, int width, int height, t_anim **anim_ref)
{
	t_anim	*anim;

	*anim_ref = t_anim_build();
	if (!*anim_ref)
		return (false);
	anim = *anim_ref;
	if (!t_anim_init_textures(mlx, width, height, anim))
		return (false);
	return (true);
}
