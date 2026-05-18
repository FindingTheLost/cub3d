/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_delta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:05:46 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/18 17:02:46 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* If a computer is super fast and renders hundreds of thousands of frames per
 * second, delta will round to 0.0f, which, when multiplied by a number in the
 * player movement function, will not move the player at all.
 *
 * The macro "ZERO_DELTA" serves as a fine-tune variable that will set "delta"
 * to the smallest possible value that mimicks player movement between frames.
 * As a consequence to this, each fast computer will have to tune this number
 * (if and only if many frames are produced).
 */
float	t_game_delta(t_game *game)
{
	float		delta;
	time_t		seconds;
	suseconds_t	microseconds;

	seconds = game->new_delta.tv_sec - game->delta.tv_sec;
	microseconds = game->new_delta.tv_usec - game->delta.tv_usec;
	delta = (float)(seconds * 1000 + microseconds / 1000) / 1000;
	if (delta == 0.0)
		delta = ZERO_DELTA;
	return (delta);
}
