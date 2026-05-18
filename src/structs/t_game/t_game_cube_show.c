/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_cube_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:14:58 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/18 20:47:46 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* To get the perpendicular plane, as well as define how long it is positively
 * and negatively (half fov for each side) which will define where the first
 * and last ray's direction will be.
 *
 * A perpendicular plane's direction will always be defined by the vector
 * pointing to the right of the player (positive) and left (negative). Just
 * like with strafing to the right, this plane will have the 'x' direction
 * of "-sinf(player->r)" and 'y' direction of "cosf(player->r)".
 *
 * Then, the ratio from -1 to 1 must be defined in this plane to understand
 * how the "cone" shape will be (the first and last ray). To do so, one can
 * multiply the direction of the plane with a number, but what will this
 * number be to represent an FOV of, say, 90 degrees?
 * 
 * This number must be the result of calculating the tangent of half an FOV
 * cone converted to radians, then one can get the ratio of how much to the
 * right or left will the direction of the rays be within it.
 *
 * First, split the FOV into two identical sides to prepare for a percentage
 * ratio:
 * 	"FOV / 2";
 *
 * Then, convert the half FOV from degrees to radians by multiplying the half
 * by "M_PI" (representing a half circle in radians) and then dividing by 180
 * (representing a half circle in degrees), this will result in 45 degrees in
 * radians:
 * 	"HALF_FOV * M_PI / 180";
 *
 * To convert a radian to degrees, multiply the radian by 180 and divide it by
 * "M_PI".
 *
 * Lastly, to get the ratio of the utmost right ray (1), that will cross through
 * the camera plane from the player, one must get the "tangent" ("sin" / "cos")
 * of this half FOV angle using the function "tanf()":
 * 	"tanf(HALF_FOV_RADIANS)";
 */

/* Fun
 */
static void	set_ray(t_game *game, size_t index, float *ray_x, float *ray_y)
{
	float	camera;

	camera = (float)2 * index / (RAY_AMOUNT - 1) - 1;
	*ray_x = cos(game->player->r) + (game->plane.x * camera);
	*ray_y = sin(game->player->r) + (game->plane.y * camera);
}

/* Function that sets a perpendicular plane direction from the player's
 * rotation in a given frame.
 */
static void	set_plane(t_game *game)
{
	game->plane.x = -(sinf(game->player->r)) * tanf(FOV / 2 * M_PI / 180);
	game->plane.y = cosf(game->player->r) * tanf(FOV / 2 * M_PI / 180);
}

void	t_game_cube_show(t_game *game)
{
	size_t	index;
	float	ray_x;
	float	ray_y;

	set_plane(game);
	index = 0;
	t_game_draw_background(game->image, W_WIDTH, W_HEIGHT, 0);
	t_game_draw_pixel(game->image, W_WIDTH / 2, W_HEIGHT / 2, 0x00FF0000);
	while (index < RAY_AMOUNT)
	{
		set_ray(game, index, &ray_x, &ray_y);
		t_game_draw_pixel(game->image, W_WIDTH / 2 + ray_x * 100, W_HEIGHT / 2 + ray_y * 100, 0x00FFFFFF);
		index++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->image->image, 0, 0);
}
