/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_clamp_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:23:36 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/17 19:24:46 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* Clamps the rotation of the player in case the "rotation" variable becomes
 * over-increased or over-decreased by the "ROTATION" macro.
 */
float	t_game_clamp_rotation(float rotation)
{
	if (rotation >= M_PI * 2)
		rotation -= M_PI * 2;
	else if (rotation <= 0)
		rotation += M_PI * 2;
	return (rotation);
}
