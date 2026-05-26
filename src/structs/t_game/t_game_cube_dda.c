/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_cube_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:55:36 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/26 18:33:02 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* Variable names changed to accomodate norminette criteria:
 * 	"delta" = "xy_delta";
 * 	"inter" = "xy_inter";
 * 	"steps" = "xy_steps";
 *
 * This function houses the very own "DDA" algorithm to calculate each ray's
 * distance from the player/camera plane to a wall/space.
 *
 * It works by keeping track of the current player's position in the map ('x'
 * and 'y'in cells) and by incrementing either "xy_inter.x" or "xy_inter.y"
 * depending on whether "xy_inter.x" is smaller than or larger than "xy_inter.y"
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
static void	dda(t_game *game, t_vector delta, t_vector *inter, t_vector steps)
{
	int		map_x;
	int		map_y;

	map_x = (int)game->player->x;
	map_y = (int)game->player->y;
	while (game->map->map[map_y][map_x] != '1'
			&& game->map->map[map_y][map_x] != ' ')
	{
		if (inter->x < inter->y)
		{
			inter->x += delta.x;
			map_x += steps.x;
			game->render->wall = W_WEEA;
		}
		else
		{
			inter->y += delta.y;
			map_y += steps.y;
			game->render->wall = W_NOSO;
		}
	}
}

/* Function that calculates the step each cycle of the "DDA" algorithm
 * will increment/decrement when the ray is travelling through the map.
 *
 * If a ray's 'x' or 'y' coordenates equal to 0, the step does not matter since
 * the step will always be taken in the opposite coordenate.
 *
 * For example, if a ray's 'x' is 0 then it's not worth keeping track of it (or
 * store a signifcant number) because the steps will always be in the 'y' axis.
 */
static void	calc_xy_steps(t_game *game, t_vector *xy_steps)
{
	if (game->render->ray.x >= 0)
		xy_steps->x = 1;
	else
		xy_steps->x = -1;
	if (game->render->ray.y >= 0)
		xy_steps->y = 1;
	else
		xy_steps->y = -1;
}

/* Variable names changed to accomodate norminette criteria:
 * 	"delta" = "xy_delta";
 * 	"inter" = "xy_inter";
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
static void	calc_xy_first_inter(t_game *game, t_vector delta, t_vector *inter)
{
	int			map_x;
	int			map_y;

	map_x = (int)game->player->x;
	map_y = (int)game->player->y;
	if (game->render->ray.x < 0)
		inter->x = (game->player->x - map_x) * delta.x;
	else
		inter->x = (map_x - game->player->x + 1) * delta.x;
	if (game->render->ray.y < 0)
		inter->y = (game->player->y - map_y) * delta.y;
	else
		inter->y = (map_y - game->player->y + 1) * delta.y;
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
static void	calc_xy_delta_inter(t_game *game, t_vector *xy_delta)
{
	t_vector	ray;

	ray = game->render->ray;
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
 *
 * Sets the perpendicular distance (the distance minus the last step which
 * was found inside a wall) and sets the "type" variable to whichever set of
 * walls the ray hit ("W_NOSO"/"W_WEEA").
 */
void	t_game_cube_dda(t_game *game)
{
	t_vector	xy_delta;
	t_vector	xy_inter;
	t_vector	xy_steps;

	calc_xy_delta_inter(game, &xy_delta);
	calc_xy_first_inter(game, xy_delta, &xy_inter);
	calc_xy_steps(game, &xy_steps);
	dda(game, xy_delta, &xy_inter, xy_steps);
	if (game->render->wall == W_WEEA)
	{
		if (game->render->ray.x < 0)
			game->render->wall = W_WE;
		else
			game->render->wall = W_EA;
		game->render->distance = xy_inter.x - xy_delta.x;
	}
	else
	{
		if (game->render->ray.y < 0)
			game->render->wall = W_NO;
		else
			game->render->wall = W_SO;
		game->render->distance = xy_inter.y - xy_delta.y;
	}
}
