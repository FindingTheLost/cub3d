/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_cube_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:14:58 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/23 03:06:36 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* Variable names changed to accomodate norminette criteria:
 *  "g"     = "game";
 * 	"delta" = "xy_delta";
 * 	"inter" = "xy_inter";
 * 	"steps" = "xy_steps";
 *
 * This function houses the very own "DDA" algorithm to calculate each ray's
 * distance from the player/camera plane to a wall/space.
 *
 * It works by keeping track of the current player's position in the map (in
 * cells) and by incrementing either "xy_inter.x" or "xy_inter.y" depending on
 * whether "xy_inter.x" is smaller than or larger than "xy_inter.y",
 * respectively, by accumulating the respective "xy_delta.x" and "xy_delta.y" to
 * the total. It then also increments the current map position (not the real map
 * player position) with the appropriate step as if the player had moved a cell
 * in that direction so the calculations can continue.
 *
 * In the end, the last cycle will expose the type of wall to which the player
 * is looking and returns it, having also modified the variables "xy_inter.x"
 * and "xy_inter.y" (thus the pointer parameter) to keep track of the distance
 * in other functions.
 */
static int	calc_dda(t_game *g, t_vector delta, t_vector *inter, t_vector steps)
{
	int	orientation;
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
			orientation = WE;
		}
		else
		{
			inter->y += delta.y;
			m_y += steps.y;
			orientation = NS;
		}
		if (g->map->map[m_y][m_x] == '1' || g->map->map[m_y][m_x] == ' ')
			break ;
	}
	return (orientation);
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
 *
 * The last condition removes the last delta addition to the ray length due to
 * the last step always finding itself inside a wall or space (where the ray
 * stopped).
 */
static float	dda_ray(t_game *game, t_vector ray, int *orientation)
{
	t_vector	xy_delta;
	t_vector	xy_inter;
	t_vector	xy_steps;
	float		perp_distance;

	calc_xy_delta_inter(&xy_delta, ray);
	calc_xy_first_inter(game, &xy_inter, xy_delta, ray);
	calc_xy_steps(&xy_steps, ray);
	*orientation = calc_dda(game, xy_delta, &xy_inter, xy_steps);
	if (*orientation == WE)
	{
		if (ray.x < 0)
			*orientation = W;
		else
			*orientation = E;
		perp_distance = xy_inter.x - xy_delta.x;
	}
	else
	{
		if (ray.y < 0)
			*orientation = N;
		else
			*orientation = S;
		perp_distance = xy_inter.y - xy_delta.y;
	}
	return (perp_distance);
}

//------------------------------------------------------------------------------

static void	draw_column(t_game *game, int column_height, size_t column_i, int orientation)
{
	int	half_column;
	int	column_top;
	int	column_bottom;

	half_column = column_height / 2;
	if (half_column > W_HEIGHT / 2)
		half_column = W_HEIGHT / 2;
	column_top = W_HEIGHT / 2 - half_column;
	column_bottom = W_HEIGHT / 2 + half_column;
	while (column_top < column_bottom)
	{
		if (orientation == N)
			t_game_draw_pixel(game->image, column_i, column_top, 0x00FF0000);
		else if (orientation == S)
			t_game_draw_pixel(game->image, column_i, column_top, 0x0000FF00);
		else if (orientation == W)
			t_game_draw_pixel(game->image, column_i, column_top, 0x000000FF);
		else
			t_game_draw_pixel(game->image, column_i, column_top, 0x00FFFF00);
		column_top++;
	}
}

static void	draw_ray(t_game *game, float distance, size_t index, int orientation)
{
	int	column_width;
	int	column_height;
	size_t	column_i;

	column_width = W_WIDTH / RAY_AMOUNT;
	column_height = W_HEIGHT / distance;
	column_i = column_width * index;
	while (column_i < column_width * (index + 1))
	{
		draw_column(game, column_height, column_i, orientation);
		column_i++;
	}
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

void	t_game_cube_show(t_game *game)
{
	size_t		index;
	t_vector	ray;
	int			orientation;
	float		distance;

	t_game_draw_background(game->image, W_WIDTH, W_HEIGHT, 0);
	t_game_draw_ceiling_floor(game);
	set_plane(game);
	index = 0;
	while (index < RAY_AMOUNT)
	{
		set_ray(game, index, &ray);
		distance = dda_ray(game, ray, &orientation);
		draw_ray(game, distance, index, orientation);
		index++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->image->image, 0, 0);
}
