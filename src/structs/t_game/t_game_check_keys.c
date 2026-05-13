/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_check_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:55:31 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/13 19:27:23 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

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
static void	move_player(t_game *game, char key)
{
	t_player	*player;

	player = game->player;
	if (key == 'w')
	{
		player->x += cosf(player->r) * SPEED * t_game_delta(game);
		player->y += sinf(player->r) * SPEED * t_game_delta(game);
	}
	else if (key == 's')
	{
		player->x -= cosf(player->r) * SPEED * t_game_delta(game);
		player->y -= sinf(player->r) * SPEED * t_game_delta(game);
	}
	else if (key == 'a')
	{
		player->x += sinf(player->r) * SPEED * t_game_delta(game);
		player->y -= cosf(player->r) * SPEED * t_game_delta(game);
	}
	else if (key == 'd')
	{
		player->x -= sinf(player->r) * SPEED * t_game_delta(game);
		player->y += cosf(player->r) * SPEED * t_game_delta(game);
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
 * Now with "delta"!!! A function that returns the time passed in milliseconds
 * divided by 1000 since the previous frame and the new one.
 */
void	t_game_check_keys(t_game *game)
{
	float	rotation_delta;

	gettimeofday(&game->new_delta, NULL);
	rotation_delta = ROTATION * t_game_delta(game);
	if (game->key->w && t_game_check_collisions(game, game->player, "w"))
		move_player(game, 'w');
	if (game->key->s && t_game_check_collisions(game, game->player, "s"))
		move_player(game, 's');
	if (game->key->a && t_game_check_collisions(game, game->player, "a"))
		move_player(game, 'a');
	if (game->key->d && t_game_check_collisions(game, game->player, "d"))
		move_player(game, 'd');
	if (game->key->left)
		game->player->r = clamp_rotation(game->player->r - rotation_delta);
	if (game->key->right)
		game->player->r = clamp_rotation(game->player->r + rotation_delta);
	game->delta = game->new_delta;
}
