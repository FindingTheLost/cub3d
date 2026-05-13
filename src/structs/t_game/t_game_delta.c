/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_delta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:05:46 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/13 18:18:03 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

float	t_game_delta(t_game *game)
{
	time_t		seconds;
	suseconds_t	microseconds;

	seconds = game->new_delta.tv_sec - game->delta.tv_sec;
	microseconds = game->new_delta.tv_usec - game->delta.tv_usec;
	return ((float)(seconds * 1000 + microseconds / 1000) / 1000);
}
