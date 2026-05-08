/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:52:52 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 22:10:36 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_player_struct.h"

/* Original "printf" function must be used to read float values.
 */
void	t_player_debug(t_player *player)
{
	ft_printf(RED_BOLD "T_PLAYER STRUCT DEBUG:\n" DEF);
	printf("X position: %f\n", player->x);
	printf("Y position: %f\n", player->y);
	printf("Rotation: %f\n", player->r);
}
