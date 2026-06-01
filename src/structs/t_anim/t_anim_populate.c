/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_populate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:13:23 by rogde-so          #+#    #+#             */
/*   Updated: 2026/05/27 13:13:23 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_anim_struct.h"

int	t_anim_populate(t_anim **anim_ref, int width, int height, void *mlx)
{
	*anim_ref = t_anim_build();
	if (!*anim_ref)
		return (false);
	if (!t_anim_init_texture(anim_ref, width, height, mlx))
		return (false);
	return (true);
}