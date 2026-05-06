/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:45:52 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 01:49:18 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_player_struct.h"

t_player	*t_player_build(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (t_player_malloc_error(), NULL);
	player->x = 0;
	player->y = 0;
	player->r = 0;
	return (player);
}
