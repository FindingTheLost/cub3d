/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_minimap_to_window_v.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:27:24 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/13 19:28:19 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* These functions shall draw the image to the window in modified 'x' and 'y'
 * coordinates to create the illusion of the map moving in relation to the
 * player's location on the map.
 *
 * This works by dividing the player's "width" and "height" by their respective
 * "map_width / 2" and "map_height / 2".
 * This is so we can grab a ratio from 0 to 2 (two-hundred percent) from where
 * the window's half "width" and half "height" will be set.
 *
 * If in cell 'x' 16, it would be the right-most cell, therefore, the camera
 * must pan left, always having the player in the center. In opposition, in
 * in cell 'y' 9, the camera must pan up. Both of these examples will have
 * their own coordinate values negative. Since it's a ratio from negative to 0
 * to positive, there is no formula that can multiply the division of the screen
 * "width" or "height" and give this exact ratio (-1, 0, 1), for example:
 * 		16 / 16 = 1;
 * 		 8 / 16 = 0.5f;
 * 		 0 / 16 = 0;
 *
 * So a ratio of 0 to 1 is still not ideal, to counter this, one can use a ratio
 * of 0 to 2, where all the numbers larger than 1 can be treated as negative,
 * have the 1 behave as neutral and 0 as positive:
 * 		16 / 8 (half of the total) = 2;
 * 		 8 / 8 = 1;
 * 		 0 / 8 = 0;
 *
 * Now, we need to translate this formula to C and retrieve the ratio as result.
 * Since, in the examples above, the variable is the left-most number of the
 * equations, the player will be the modifier, since he can travel from cells
 * 0 to 15 (16 cells), where he can only walk upon cells 1 to 14 due to walls,
 * all this of course, in a case of 16 "map_width".
 * For example, in a case of 16 "map_width" and 9 "map_height":
 * 		"200%width"  = (float)player_x / (map_width / 2);
 * 		"200%height" = (float)player_y / (map_height / 2);
 *
 * If player's 'x' and 'y' were 1.6f and 5.6f, respectively, this would result:
 * 		"200%width"	 = 1.6f / 8 	= 0.2f;
 * 		"200%height" = 5.6f / 4.5f 	= 1.244f;
 *
 * Since the player's 'x' is at the left side of the screen width's half, the
 * camera must pan positively to the right.
 * In the case of 'y', it is in the lower half of the screen's height half,
 * which means that the camera must pan negatively up.
 *
 * To calculate the percentage modifications to 'x' and 'y':
 * If the number 'z' is larger than 1, first subtract 2 by 'z' to get the ratio
 * back to percentage. Then find the absolute value of 'z' subtracted by 1 to
 * invert the percentage into the correct one (0.6f turns to 0.4f). Then,
 * multiply 'z' by a negative "W_WIDTH / 2".
 * If the number is inferior or equal to 1, the first step of the previous
 * formula can be skipped, and only need to invert the percentage so 'z' can be
 * multiplied by a positive "W_WIDTH / 2". The same applies to 'y's case but
 * instead of using "W_WIDTH" it uses "W_HEIGHT".
 * Examples:
 *		x = fabs(((float)(2 - twocent_width)) - 1) * -(W_WIDTH / 2);
 *		x = fabs((float)(twocent_width - 1)) * (W_WIDTH / 2);
 *
 * The following formulas deviate slightly from this explanation due to not
 * using the entire mlx "image" to represent the map. This would only be correct
 * if the map was drawn from top to bottom, left to right in this window and
 * have it completely fullscreen in the "image". Since the minimap has to have
 * aspect ratio correct squares, depending on whether the map fits into 16:9 or
 * not, it will have blank spots inside the image unless it is a perfect 16:9
 * tiled map.
 *
 * A small change in the formula of 'x' is the sole reason of having two
 * functions for different map widths.
 */
static void	odd_map_height(t_game *game, int *y, size_t tile)
{
	float	twocent_height;

	twocent_height = game->player->y / (float)(game->map->map_height / 2);
	if (twocent_height > 1)
		*y = -(fabs(((float)(2 - twocent_height)) - 1)
				* ((tile * game->map->map_height - (W_HEIGHT
							- (tile * game->map->map_height))) / 2));
	else
		*y = fabs((float)(twocent_height - 1))
			* ((tile * game->map->map_height - (W_HEIGHT
						- (tile * game->map->map_height))) / 2);
}

/* When even, 'y' does not require to compensate the small missing screen field
 * that is lost due to dividing the screen by an odd number.
 */
static void	even_map_height(t_game *game, int *y, size_t tile)
{
	float	twocent_height;

	twocent_height = game->player->y / (float)(game->map->map_height / 2);
	if (twocent_height > 1)
		*y = -(fabs(((float)(2 - twocent_height)) - 1)
				* ((tile * game->map->map_height) / 2));
	else
		*y = fabs((float)(twocent_height - 1))
			* ((tile * game->map->map_height) / 2);
}

static void	odd_map_width(t_game *game, int *x, int *y, size_t tile)
{
	float	twocent_width;

	twocent_width = game->player->x / (float)(game->map->map_width / 2);
	if (twocent_width > 1)
		*x = -(fabs(((float)(2 - twocent_width)) - 1)
				* ((tile * (game->map->map_width - 1)) / 2));
	else
		*x = fabs((float)(twocent_width - 1))
			* ((tile * (game->map->map_width - 1)) / 2);
	if (game->map->map_height % 2 == 0)
		even_map_height(game, y, tile);
	else
		odd_map_height(game, y, tile);
}

static void	even_map_width(t_game *game, int *x, int *y, size_t tile)
{
	float	twocent_width;

	twocent_width = game->player->x / (float)(game->map->map_width / 2);
	if (twocent_width > 1)
		*x = -(fabs(((float)(2 - twocent_width)) - 1)
				* ((tile * (game->map->map_width)) / 2));
	else
		*x = fabs((float)(twocent_width - 1))
			* ((tile * (game->map->map_width)) / 2);
	if (game->map->map_height % 2 == 0)
		even_map_height(game, y, tile);
	else
		odd_map_height(game, y, tile);
}

void	t_game_minimap_to_window_v(t_game *game, int *x, int *y)
{
	size_t	tile;

	tile = W_HEIGHT / game->map->map_height;
	if (game->map->map_width % 2 == 0)
		even_map_width(game, x, y, tile);
	else
		odd_map_width(game, x, y, tile);
}
