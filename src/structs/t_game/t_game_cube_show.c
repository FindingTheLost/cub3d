/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_cube_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:14:58 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/22 18:56:09 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* Variable names changed to accomodate norminette criteria:
 *  "g"     = "game";
 * 	"delta" = "xy_delta";
 * 	"inter" = "xy_inter";
 * 	"steps" = "xy_steps";
 */
static int	calc_dda(t_game *g, t_vector delta, t_vector *inter, t_vector steps)
{
	int	wall_orientation;
	int	m_x;
	int	m_y;

	m_x = (int)g->player->x;
	m_y = (int)g->player->y;
	while (true)
	{
		if (inter->x < inter->y)
		{
			inter->x += delta.x;
			m_x += steps.x;
			wall_orientation = WE_WALL;
		}
		else
		{
			inter->y += delta.y;
			m_y += steps.y;
			wall_orientation = NS_WALL;
		}
		if (g->map->map[m_y][m_x] == '1' || g->map->map[m_y][m_x] == ' ')
			break ;
	}
	return (wall_orientation);
}

/* Function that calculates the step each cycle of the "DDA" algorithm
 * will increment when the ray is travelling through the map.
 *
 * If a ray's 'x' or 'y' coordenates equal to 0, it won't matter since the step
 * will always be taken in the opposite direction.
 * For example, if a ray's 'x' is 0 then it's not worth to keep track of it (or
 * store a signifcant number) because the steps will always be in the 'y' axis.
 */
static void	calc_xy_steps(t_vector *xy_steps, t_vector ray)
{
	if (ray.x >= 0)
		xy_steps->x = 1;
	else
		xy_steps->x = -1;
	if (ray.y >= 0)
		xy_steps->y = 1;
	else
		xy_steps->y = -1;
}

/* Variable names changed to accomodate norminette criteria:
 * 	"g" = "game";
 *
 * Function that calculates the first interception with the 'x' and 'y' axis
 * starting from the player's location.
 *
 * Take as an example the player's position at 'x': 3.7f, 'y': 3.3f.
 *
 * If a ray's 'x' (or 'y') is inferior to 0, therefore negative, it means the
 * current ray coming from the player's position has to take into account the
 * distance coming from the player's 'x' position (3.7f) to its left. The
 * result should be 0.7f but if both formulas were the same there would be
 * different results.
 *
 * Therefore, for negative coordenate directions, the formula should be
 * "(px - mx) * dx" or "(3.7 - 3) * dx".
 * And for positive coordenate directions "(mx - px + 1) * dx" or
 * "(3 - 3.7 + 1) * dx".
 *
 * The first will result in the correct distance to the player's left, which is
 * "0.7 * dx" and the second to the player's right "0.3 * dx".
 */
static void	calc_xy_first_inter(t_game *g, t_vector *i, t_vector d, t_vector r)
{
	t_vector	*xy_inter;
	t_vector	xy_delta;
	t_vector	ray;
	int			map_x;
	int			map_y;

	xy_inter = i;
	xy_delta = d;
	ray = r;
	map_x = (int)g->player->x;
	map_y = (int)g->player->y;
	if (ray.x < 0)
		xy_inter->x = (g->player->x - map_x) * xy_delta.x;
	else
		xy_inter->x = (map_x - g->player->x + 1) * xy_delta.x;
	if (ray.y < 0)
		xy_inter->y = (g->player->y - map_y) * xy_delta.y;
	else
		xy_inter->y = (map_y - g->player->y + 1) * xy_delta.y;
}

/* Function that calculates the delta distance of 'x' and 'y' from the current
 * 'x' intercept to the next one and the current 'y' intercept to the next of a
 * given ray direction.
 *
 * Note that this function calculates from the player's first 'x' and 'y' ray
 * interceptions to the next ones, not from the player's position to the first
 * 'x'/'y' intercepts. That is calculated in "calc_xy_first_inter()" function.
 *
 * If the direction of 'x' or 'y' in a ray is 0, it means it will never have
 * an interception with the respective axis, but theoretically, it can intercept
 * it somewhere in "INFINITY".
 *
 * To calculate the hypotenuse of the continuous, same sized delta jumps of the
 * 'x' and 'y' interceptions, one must find the size of the hypotenuse, which is
 * through the "pythagorean theorem" (c^2 = a^2 + b^2).
 *
 * Tracking the ray direction (the hypotenuse) through a square grid will grant
 * various interceptions on the 'x' axis (the vertical lines) and 'y' axis
 * (the horizontal lines). Keeping track of these interceptions (with 'x' and
 * 'y' interceptions separated) will result in a same pattern between 'x' jumps
 * and the next ones and 'y' jumps and the next ones, resulting in the various
 * triangles composed of the ray (as the hypotenuse), with the respective
 * interception forming a straight line to the left or right ('x') or up or down
 * ('y') which will have size 1 because all cells in the map have size 1 and
 * by an unknown sized vertical line ('x') or horizontal ('y').
 *
 * Since one side's size is already known, all that is left is to know the size
 * of the remaining non-hypotenuse line, which will be the result of the ratio
 * of the ray's 'y' divided by ray's 'x' ('x') and ray's 'x' divided by
 * ray's 'y' ('y').
 *
 * In an "x-interception", the size of the triangle side that is horizontal
 * will always be 1. The same can be said about the size of the side of a the
 * triangle that is vertical in an "y-interception".
 */
static void	calc_xy_delta_inter(t_vector *xy_delta, t_vector ray)
{
	if (ray.x == 0)
		xy_delta->x = INFINITY;
	else
		xy_delta->x = sqrtf(1 + ((ray.y / ray.x) * (ray.y / ray.x)));
	if (ray.y == 0)
		xy_delta->y = INFINITY;
	else
		xy_delta->y = sqrtf(1 + ((ray.x / ray.y) * (ray.x / ray.y)));
}

/* Function that calculates the first 'x' and 'y' interceptions of the ray in
 * the map as well as the subsequent 'x' and 'y' interceptions (delta) which
 * will always have the same size. Also calculates whether the algorithm will
 * step forward or backward in the 'x' and 'y' axis of the map.
 *
 * Lastly, it proceeds to use the "Digital Differential Analyzer" or "DDA"
 * algorithm to check when a ray hits a wall and at what distance from the
 * player/camera plane so it can then proceed to draw the correct texture
 * column at the correct size, creating the illusion of distance.
 */
static void	dda_ray(t_game *game, t_vector ray)
{
	t_vector	xy_delta;
	t_vector	xy_inter;
	t_vector	xy_steps;
	float		perp_distance;
	int			wall_orientation;

	calc_xy_delta_inter(&xy_delta, ray);
	calc_xy_first_inter(game, &xy_inter, xy_delta, ray);
	calc_xy_steps(&xy_steps, ray);
	wall_orientation = calc_dda(game, xy_delta, &xy_inter, xy_steps);
	if (wall_orientation == WE_WALL)
		perp_distance = (xy_inter.x - xy_delta.x);
	else
		perp_distance = (xy_inter.y - xy_delta.y);
	(void)perp_distance;
}

//------------------------------------------------------------------------------

/* Function that sets a ray's 'x' and 'y' position based on the ratio of the
 * current ray in the perpendicular plane, starting from -1 and ending in 1.
 *
 * The "camera" variable expression's "2 *" and "- 1" transforms a ratio from
 * 0 to 1 (0 to 100) into 0 to 2 and then -1 to 1, respectively.
 * The ratio from the first ray to the last is calculated from dividing the
 * current index by the number of rays - 1. If "index" is 0 then it will result
 * in the ray 0 (the first and leftmost one, which, after "2 *" and "- 1" will
 * become -1). If the "index" is the last then it will result in the last ray.
 */
static void	set_ray(t_game *game, size_t index, t_vector *ray)
{
	float	camera;

	camera = (float)2 * index / (RAY_AMOUNT - 1) - 1;
	ray->x = cos(game->player->r) + (game->camera_plane.x * camera);
	ray->y = sin(game->player->r) + (game->camera_plane.y * camera);
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

void	t_game_cube_show(t_game *game)
{
	size_t		index;
	t_vector	ray;

	set_plane(game);
	index = 0;
	while (index < RAY_AMOUNT)
	{
		set_ray(game, index, &ray);
		dda_ray(game, ray);
		index++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->image->image, 0, 0);
}
