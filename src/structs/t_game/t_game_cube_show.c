/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_cube_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:14:58 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/14 02:43:28 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* First, split the FOV into two identical sides to prepare for a percentage
 * ratio:
 * 	"FOV / 2";
 *
 * Then, convert the FOV split from degrees to radians by multiplying the FOV
 * by "M_PI" (representing a half circle in radians) and then dividing by 180
 * (representing a half circle in degrees), this will result in 45 degrees in
 * radians:
 * 	"FOV / 2 * M_PI / 180";
 *
 * To convert a radian to degrees, multiply the radian by 180 and divide it by
 * "M_PI".
 *
 * Lastly, to get the ratio of the utmost right ray (1), that will cross
 * through the camera plane, one must get the "tangent" ("sin" / "cos") of this
 * half FOV angle by doing:
 * 	"tanf(FOV / 2 * M_PI / 180)";
 */
void	t_game_cube_show(t_game *game)
{
	game->plane.x = -(sinf(game->player->r)) * tanf(FOV / 2 * M_PI / 180);
	game->plane.y = cosf(game->player->r) * tanf(FOV / 2 * M_PI / 180);
}
