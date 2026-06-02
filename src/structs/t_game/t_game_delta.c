/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_delta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:05:46 by pde-alme          #+#    #+#             */
/*   Updated: 2026/06/02 19:44:32 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* The "delta" variable must explicitely convert "seconds" and "microseconds" to
 * float before performing any multiplication or division.
 */
float	t_game_delta(t_game *game)
{
	float		delta;
	time_t		seconds;
	suseconds_t	microseconds;

	seconds = game->new_delta.tv_sec - game->delta.tv_sec;
	microseconds = game->new_delta.tv_usec - game->delta.tv_usec;
	delta = ((float)seconds * 1000 + (float)microseconds / 1000) / 1000;
	return (delta);
}
