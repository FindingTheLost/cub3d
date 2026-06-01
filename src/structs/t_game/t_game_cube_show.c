/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_cube_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:14:58 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/31 23:08:09 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* If the macro "FISH_EYE" is set to the value "false", "distance" will be
 * multiplied by the ratio of the cosine of the ray's angle minus the player's
 * angle which will always result in a number between 0.707(sin-) to 0 to
 * 0.707(sin+). To calculate a direction's angle when only given the size of
 * 'x' and 'y' sides or the ratio (sin/cos) of 'x' and 'y', calculate its
 * arctangent (the inverse of tangent, which will result in the angle) by
 * using the function "atan(z)" (where 'z' is a tangent) or by using the
 * "atan2(y, x)" function (where 'y' is the 'y' ratio of a direction and 'x' is
 * the 'x' ratio).
 *
 * This is so that directions whose rotation is different of 0º, 90º, 180º and
 * 270º have their distances reduced to match the distance ratios of the
 * previous angles.
 */
static void	set_fisheye(t_game *game)
{
	t_player	*player;
	t_render	*render;

	player = game->player;
	render = game->render;
	if (!game->fish_eye)
		render->distance *= cosf(atan2f(render->ray.y, render->ray.x)
				- player->r);
}

/* Function that sets a ray's 'x' and 'y' position based on the ratio of the
 * current ray in the perpendicular plane, starting from -1 and ending in 1.
 *
 * The "camera_ratio" variable expression's "2 *" and "- 1" transforms a ratio
 * from 0 to 1 (0 to 100) into 0 to 2 and then -1 to 1, respectively.
 * The ratio from the first ray to the last is calculated from dividing the
 * current index by the number of rays - 1. If "index" is 0 then it will result
 * in the ray 0 (the first and leftmost one, which, after "2 *" and "- 1" will
 * become -1). If the "index" is the last then it will result in the last ray.
 *
 * In the end, normalizes the vector (if 'x' or 'y' == 0, the opposite direction
 * can be larger than 1, and since no vector has such values, normalize it).
 */
static void	set_ray(t_game *game, size_t index)
{
	t_player	*player;
	t_render	*render;
	float		camera_ratio;

	player = game->player;
	render = game->render;
	camera_ratio = (float)2 * index / (RAY_AMOUNT - 1) - 1;
	render->ray.x = cos(player->r) + (render->camera.x * camera_ratio);
	render->ray.y = sin(player->r) + (render->camera.y * camera_ratio);
	if (render->ray.x == 0)
		render->ray.y = 1;
	else if (render->ray.y == 0)
		render->ray.x = 1;
}

/* Function that sets a perpendicular plane direction to the player's
 * rotation in a given frame and stores it into the "camera" variable of the
 * "render" struct.
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
static void	set_camera(t_game *game)
{
	t_player	*player;
	t_render	*render;

	player = game->player;
	render = game->render;
	render->camera.x = -(sinf(player->r)) * tanf(FOV / 2 * M_PI / 180);
	render->camera.y = cosf(player->r) * tanf(FOV / 2 * M_PI / 180);
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
	size_t	index;

	t_game_draw_ceiling_floor(game, game->image);
	set_camera(game);
	index = 0;
	while (index < RAY_AMOUNT)
	{
		set_ray(game, index);
		t_game_cube_dda(game);
		set_fisheye(game);
		t_game_cube_draw(game, index);
		index++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->image->image, 0, 0);
}
