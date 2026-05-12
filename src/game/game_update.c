/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:17:18 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/12 01:03:40 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* Function that slides the player to one of both the directions it is facing.
 * In case the player is facing a wall but slightly rotated (ex: 45 degrees to
 * the right of "north", "northeast" or "(M_PI * 3) / 2" radians) and depending
 * on the pressed keys, check if ONLY the "sine" or ONLY the "cos" coordenates
 * (along with the old opposite player's coordenate) point to a ground tile and
 * apply that "sine"/"cos" value to the player's 'x' or 'y' raw trignometric
 * value.
 *
 * Examples:
 *
 * 1
 * 1
 * 1º <- player facing "NW" and pressing "W".
 * 1
 * 1
 *
 * The "sine" is -0.7f and "cosine" is -0.7f. The player will knock on the wall
 * if the player's movement point to 'x' = "cos" | 'y' = player's old 'y'. But
 * will have the possibility to move up if 'x' = player's old 'x' | 'y' = "sin".
 * So in this case, negate moving the 'x', but move the 'y' coordenate.
 *
 * 11111111
 *     º <- player facing "NE" and pressing "W".
 *
 * The "sine" is -0.7f and "cosine" is 0.7f. The player will knock on the wall
 * if the player's movement point to 'x' = player's old 'x' | 'y' = "sin". But
 * will have the possibility to move right if 'x' = "cos" | 'y' = player's old
 * 'y'.
 * In this case, negate moving 'y', but move the 'x' coordenate.
 *
 * If both 'x' ("cos") and 'y' ("sin") are at a standoff being walls ('1') or
 * space (' '), the function will simply return "false", not moving the player.
 * If both are possible routes, ground ('0'), with a perfect 45 degree angle
 * and the next tile is the absolute corner of a tile, the first option will be
 * chosen (no more space to make a third option due to norminette, although a
 * sensible decision would be to not make the player move as well).
 */
static void	slide_tile(t_game *game, int x, int y, char *direction)
{
	if (game->map->map[y][(int)game->player->x] != '1'
		&& game->map->map[y][(int)game->player->x] != ' ')
	{
		if (ft_strbcmp(direction, "w"))
			game->player->y += sinf(game->player->r) * SPEED / SLIDE_DIVISOR;
		else if (ft_strbcmp(direction, "s"))
			game->player->y -= sinf(game->player->r) * SPEED / SLIDE_DIVISOR;
		else if (ft_strbcmp(direction, "a"))
			game->player->y -= cosf(game->player->r) * SPEED / SLIDE_DIVISOR;
		else if (ft_strbcmp(direction, "d"))
			game->player->y += cosf(game->player->r) * SPEED / SLIDE_DIVISOR;
	}
	if (game->map->map[(int)game->player->y][x] != '1'
		&& game->map->map[(int)game->player->y][x] != ' ')
	{
		if (ft_strbcmp(direction, "w"))
			game->player->x += cosf(game->player->r) * SPEED / SLIDE_DIVISOR;
		else if (ft_strbcmp(direction, "s"))
			game->player->x -= cosf(game->player->r) * SPEED / SLIDE_DIVISOR;
		else if (ft_strbcmp(direction, "a"))
			game->player->x += sinf(game->player->r) * SPEED / SLIDE_DIVISOR;
		else if (ft_strbcmp(direction, "d"))
			game->player->x -= sinf(game->player->r) * SPEED / SLIDE_DIVISOR;
	}
}

/* Checks whether the tile the player is trying to step is a good tile 
 * ground -> '0') or a not (a wall -> '1' or a space -> ' ').
 *
 * If not, returns "false", where the calling function will not move the player
 * due to either hitting a wall or being in a corner between two walls, trying
 * to move diagonally (prevents clipping between corners).
 *
 * If the next tile is a wall or an empty space, make the player slide in one
 * of both directions the directions its facing that does not point to a wall.
 * Here, the function also returns "false" because, although the player is moved
 * in the "slide_tile()" function, it must not be moved in the calling function,
 * which only does so if the function returns "true".
 */
static int	good_tile(t_game *game, int x, int y, char *direction)
{
	if (game->map->map[y][x] == '1' || game->map->map[y][x] == ' ')
		return (slide_tile(game, x, y, direction), false);
	if ((int)game->player->x == x - 1 && (int)game->player->y == y + 1
		&& game->map->map[y][x - 1] == '1' && game->map->map[y + 1][x] == '1')
		return (false);
	if ((int)game->player->x == x + 1 && (int)game->player->y == y - 1
		&& game->map->map[y][x + 1] == '1' && game->map->map[y - 1][x] == '1')
		return (false);
	if ((int)game->player->x == x + 1 && (int)game->player->y == y + 1
		&& game->map->map[y][x + 1] == '1' && game->map->map[y + 1][x] == '1')
		return (false);
	if ((int)game->player->x == x - 1 && (int)game->player->y == y - 1
		&& game->map->map[y][x - 1] == '1' && game->map->map[y - 1][x] == '1')
		return (false);
	return (true);
}

/* First checks if the next tile is ground ('0'), protecting from moving to
 * walls ('1') and blanks (' '), also impeding jumps from corners.
 * Then, if it is a wall, slide on it according to the "sin" and "cos" ratio
 * of the perpendicular axis of the wall.
 */
static int	check_collision(t_game *g, t_player *p, char *direction)
{
	if (ft_strbcmp(direction, "w"))
	{
		if (!good_tile(g, p->x + cosf(p->r) * SPEED,
			p->y + sinf(p->r) * SPEED, direction))
			return (false);
	}
	else if (ft_strbcmp(direction, "s"))
	{
		if (!good_tile(g, p->x - cosf(p->r) * SPEED,
			p->y - sinf(p->r) * SPEED, direction))
			return (false);
	}
	else if (ft_strbcmp(direction, "a"))
	{
		if (!good_tile(g, p->x + sinf(p->r) * SPEED,
			p->y - cosf(p->r) * SPEED, direction))
			return (false);
	}
	else if (ft_strbcmp(direction, "d"))
	{
		if (!good_tile(g, p->x - sinf(p->r) * SPEED,
			p->y + cosf(p->r) * SPEED, direction))
			return (false);
	}
	return (true);
}

/* Function that increases and decreases both player's coordenates 'x' and 'y',
 * using the "sine" and "cosine" functions based on the player's rotation and
 * multiplying it by the "SPEED" macro value.
 *
 * In "cosf" and "sinf", the parameter "rotation" asks for a float representing
 * the rotation of the angle in "radians" (since C is not capable of working
 * with degrees out of the box).
 *
 * Imagine a circle around the triangle below, where the center of this circle
 * is in point B and the hypotenuse is the radius of the circle.
 *
 * Now imagine that this hypotenuse can rotate inside and around the circle,
 * having its origin ALWAYS in B to one of the infinite points of the circle
 * itself.
 *
 * Finally, imagine that, as the hypotenuse rotates inside the circle as
 * described in the note above, the opposite and adjacent cathets will increase
 * and decrease their size, ranging from "MIN" to "MAX" lengths.
 *
 * If the opposite cathet is 0 it means the adjacent cathet is either at "MIN"
 * (all the way to the left) or "MAX" (all the way to the right) sizes (cosine
 * (cos) = -1 or 1, respectively).
 *
 * If the adjacent cathet is 0 it means the opposite cathet is either at "MIN"
 * (all the way down) or "MAX" (all the way up) sizes (sine (sin) = -1 or 1,
 * respectively).
 *
 * Think of the "cosine" ('x') and "sine" ('y') as ways to find the coordenates
 * of an abstract point, which, when connected with the center of the circle
 * 'B', draws a line which gives information about where someone might be
 * looking at (the abstract point 'p') and where it is looking from ('B'),
 * essentially giving the rotation of that person in a 2D space (looking from
 * above).
 *
 *                C
 *              /|
 *           o /-| o
 *          p /  | p
 *         i /   | p
 *        h /    | o
 *         /    _|
 *        /_\__|_|
 *       B  adja  A
 *
 * The angle in point 'B' will have the rotation value denoted by the "rotation"
 * variable.
 *
 * "AB" is the adjacent cathet of the triangle.
 * "AC" is the opposite cathet of the triangle.
 * "BC" is the hypotenuse of the triangle.
 *
 * To calculate the sine of 'B' (previously knowing 'B's angle), we must divide
 * the length of the opposite cathet by the length of the hypotenuse. The result
 * will be the ratio at which an abstract point 'p's (that has an 'x' and 'y'
 * coordenates) 'y' is in regards to the length of the opposite cathet (from -1
 * to 1).
 *
 * To calculate the cosine of 'B', we must divide the length of the adjacent
 * cathet by the length of the hypotenuse. The result will be the ratio at
 * which an abstract point 'p's 'x' is in regards to the length of the adjacent
 * cathet (from -1 to 1).
 *
 * Examples (also using the pythagoras theorem):
 * 	oppo = 13;
 * 	adja = 6;
 * 	hypo = (13 ^ 2) + (6 ^ 2) = hypo ^ 2 --> 169 + 36 = hypo ^ 2 --> sqrt(205) =
 * 	       hypo --> 14.3178;
 *
 * 	cosB = adja / hypo -->  6 / 14.3178 = 0.419058794;
 * 	sinB = oppo / hypo --> 13 / 14.3178 = 0.907960720;
 *
 * 	Point 'B' is "looking" from the center of the circle ('x': 0, 'y': 0) to the
 * 	abstract point 'p' ('x': 0.419058794, 'y': 0.907960720).
 *
 * 	In C, the functions "cos", "cosf", "sin" and "fsin" calculate cosine and
 * 	sine in a diferent way due to having no information about the triangle's
 * 	cathets lengths, having to work with only the "rotation" variable passed
 * 	as parameter (which contains the value of the angle in "radians").
 *
 * 	To use these functions, include the "math.h" library and compile the code
 * 	with the "-lm" linker flag after the specified object files.
 *
 * To strafe left and right, 'x' must now be modified by "sin" instead of "cos"
 * and vice-versa to 'y'. If a player is facing "south" and walks forward, its
 * "sin" will be 1 and "cos" will be 0 ("sin" and "cos" of 0 (south)).
 *
 * To put strafing in perspective, if a player hits the 'A' key to strafe left
 * while the player is facing "south", the player must strafe to the right (in
 * the minimap) which will be its left. So 'x' must be positive and 'y' must be
 * negative, to do so, since the "sin" and "cos" of 0 are, respectively, 1 and
 * 0, 'x' must now add the value of "sin" and 'y' "cos".
 *
 * If 'x' still refered to "cos" and 'y' to "sin" while the player strafed while
 * rotated to "south" (0 radians), 'x' would add 0 to its value due to "cos" of
 * 0 being 0, and 'y' would add 1 to its value due to "sin" of 0 being 1,
 * essentially making the player move "south" even when pressing the 'A' key.
 */
static void	move_player(t_player *player, char key)
{
	if (key == 'w')
	{
		player->x += cosf(player->r) * SPEED;
		player->y += sinf(player->r) * SPEED;
	}
	else if (key == 's')
	{
		player->x -= cosf(player->r) * SPEED;
		player->y -= sinf(player->r) * SPEED;
	}
	else if (key == 'a')
	{
		player->x += sinf(player->r) * SPEED;
		player->y -= cosf(player->r) * SPEED;
	}
	else if (key == 'd')
	{
		player->x -= sinf(player->r) * SPEED;
		player->y += cosf(player->r) * SPEED;
	}
}

/* Clamps the rotation of the player in case the "rotation" variable becomes
 * over-increased or over-decreased by the "ROTATION" macro.
 */
static float	clamp_rotation(float rotation)
{
	if (rotation >= M_PI * 2)
		rotation -= M_PI * 2;
	else if (rotation <= 0)
		rotation += M_PI * 2;
	return (rotation);
}

/* Checks the "t_key" struct in "t_game" for pressed keys and acts accordingly
 * to each one.
 */
static void	check_keys(t_game *game)
{
	if (game->key->w && check_collision(game, game->player, "w"))
		move_player(game->player, 'w');
	if (game->key->s && check_collision(game, game->player, "s"))
		move_player(game->player, 's');
	if (game->key->a && check_collision(game, game->player, "a"))
		move_player(game->player, 'a');
	if (game->key->d && check_collision(game, game->player, "d"))
		move_player(game->player, 'd');
	if (game->key->left)
		game->player->r = clamp_rotation(game->player->r - ROTATION);
	if (game->key->right)
		game->player->r = clamp_rotation(game->player->r + ROTATION);
}

int	game_update(t_game *game)
{
	check_keys(game);
	t_game_minimap_show(game);
	return (0);
}
