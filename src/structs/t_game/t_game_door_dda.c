/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_door_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:55:36 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 20:12:47 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* Variable names changed to accomodate norminette criteria:
 * 	"delta" = "xy_delta";
 * 	"inter" = "xy_inter";
 * 	"steps" = "xy_steps";
 *
 * Small variation of the "DDA" algorithm. This one stops if it finds anything
 * other than a ground tile ('0') or, if the player is standing within an opened
 * door tile, keep DDA'ing until it finds something else.
 *
 * Once it is done, it removes the last step from the distance before setting
 * it and sends to the function "t_game_door_interact()" to check if the
 * player is in door opening/closing distance, if inside a door and if the
 * ray stopped at a closed or opened door.
 */
static void	dda(t_game *game, t_vector delta, t_vector inter, t_vector steps)
{
	int	x;
	int	y;

	x = (int)game->player->x;
	y = (int)game->player->y;
	while (game->map->map[y][x] == '0' || (game->map->map[y][x] == 'O'
			&& x == (int)game->player->x && y == (int)game->player->y))
	{
		if (inter.x < inter.y)
		{
			inter.x += delta.x;
			x += steps.x;
			game->render->wall = W_V;
		}
		else
		{
			inter.y += delta.y;
			y += steps.y;
			game->render->wall = W_H;
		}
	}
	if (game->render->wall == W_V)
		t_game_door_interact(game, x, y, inter.x - delta.x);
	else
		t_game_door_interact(game, x, y, inter.y - delta.y);
}

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

/* This function opens and closes doors using a single "DDA" algorithm ray to
 * detect whether the player is looking at an opened/closed door or not.
 * It is mostly the same as the render's "DDA" algorithm in the file
 * "t_game_cube_dda.c" but with some addition and removals (all commented
 * throughout this file).
 *
 * It does not include instruction comments on how it works due to them already
 * being present in the file above.
 *
 * This function takes use of the "render" variable to store the direction the
 * player currently is facing even though it is not rendering anything, it is
 * just to save time and line space without modyfing an already familiar
 * function too much.
 *
 * First store the direction of the player, perform all of the pre-DDA data
 * calculation and launch the "DDA". This iteration does not store the distance
 *
 */
void	t_game_door_dda(t_game *game)
{
	t_vector	xy_delta;
	t_vector	xy_inter;
	t_vector	xy_steps;

	game->render->ray.x = cosf(game->player->r);
	game->render->ray.y = sinf(game->player->r);
	calc_xy_delta_inter(game, &xy_delta);
	calc_xy_first_inter(game, xy_delta, &xy_inter);
	calc_xy_steps(game, &xy_steps);
	dda(game, xy_delta, xy_inter, xy_steps);
}
