/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_cube_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:14:58 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/25 18:34:02 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* Function that sets a ray's 'x' and 'y' position based on the ratio of the
 * current ray in the perpendicular plane, starting from -1 and ending in 1.
 *
 * The "camera" variable expression's "2 *" and "- 1" transforms a ratio from
 * 0 to 1 (0 to 100) into 0 to 2 and then -1 to 1, respectively.
 * The ratio from the first ray to the last is calculated from dividing the
 * current index by the number of rays - 1. If "index" is 0 then it will result
 * in the ray 0 (the first and leftmost one, which, after "2 *" and "- 1" will
 * become -1). If the "index" is the last then it will result in the last ray.
 *
 * In the end, normalizes the vector (if 'x' or 'y' == 0, the opposite direction
 * can be larger than 1, and since no vector has such values, normalize it).
 */
static void	set_ray(t_game *game, size_t index, t_vector *ray)
{
	float	camera;

	camera = (float)2 * index / (RAY_AMOUNT - 1) - 1;
	ray->x = cos(game->player->r) + (game->camera_plane.x * camera);
	ray->y = sin(game->player->r) + (game->camera_plane.y * camera);
	if (ray->x == 0)
		ray->y = 1;
	else if (ray->y == 0)
		ray->x = 1;
}

/* Function that sets a perpendicular plane direction to the player's
 * rotation in a given frame and stores it into the "camera_plane" variable.
 *
 * To get the perpendicular plane, as well as define how long it is positively
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
static void	set_plane(t_game *game)
{
	t_player	*player;

	player = game->player;
	game->camera_plane.x = -(sinf(player->r)) * tanf(FOV / 2 * M_PI / 180);
	game->camera_plane.y = cosf(player->r) * tanf(FOV / 2 * M_PI / 180);
}

/* Function that draws the map in 3D to the game's "image" variable.
 *
 * It starts by defining a perpendicular plane to the player in the current
 * frame. It has the size of (or ratio) of FOV (or (FOV / 2) * 2), where its
 * positive side has FOV / 2 size and a negative side of also FOV / 2 size.
 *
 * Then, calculate the ray's direction based on the player's current direction
 * plus the perpendicular plane's current direction multiplied by it's current
 * ratio (from -1 to 1), which will define a ray direction.
 *
 * After this, calculate how long is the ray from the player's current position
 * to the first wall/blank space it hits, resulting in the ray's distance.
 * It uses the "DDA" algorithm to calculate it.
 *
 * Lastly, with the distance known, manipulate each column of the current image
 * by drawing pixels in the mid horizontal position of the screen based on the
 * distance returned by the ray, creating the illusion of 3 dimensions.
 */
void	t_game_cube_show(t_game *game)
{
	size_t		index;
	t_vector	ray;
	t_wall		type;
	float		distance;

	t_game_draw_ceiling_floor(game, game->image);
	set_plane(game);
	index = 0;
	while (index < RAY_AMOUNT)
	{
		set_ray(game, index, &ray);
		distance = t_game_cube_dda(game, ray, &type);
		if (!FISH_EYE)
			distance *= cosf(atan2f(ray.y, ray.x) - game->player->r);
		t_game_cube_draw(game, index, type, distance);
		index++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->image->image, 0, 0);
}
