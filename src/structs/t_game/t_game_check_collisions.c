/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_check_collisions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:52:45 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/19 00:47:44 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

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
 *
 * The function "slide_speed" does not make the player slide sprint due to not
 * having any more space in the function parameters.
 */
static float	slide_speed(t_game *game)
{
	return ((float)(SPEED * t_game_delta(game) / SLIDE_DIVISOR));
}

static void	slide_tile(t_game *game, int x, int y, char *direction)
{
	if (game->map->map[y][(int)game->player->x] != '1'
		&& game->map->map[y][(int)game->player->x] != ' ')
	{
		if (ft_strbcmp(direction, "w"))
			game->player->y += sinf(game->player->r) * slide_speed(game);
		else if (ft_strbcmp(direction, "s"))
			game->player->y -= sinf(game->player->r) * slide_speed(game);
		else if (ft_strbcmp(direction, "a"))
			game->player->y -= cosf(game->player->r) * slide_speed(game);
		else if (ft_strbcmp(direction, "d"))
			game->player->y += cosf(game->player->r) * slide_speed(game);
	}
	if (game->map->map[(int)game->player->y][x] != '1'
		&& game->map->map[(int)game->player->y][x] != ' ')
	{
		if (ft_strbcmp(direction, "w"))
			game->player->x += cosf(game->player->r) * slide_speed(game);
		else if (ft_strbcmp(direction, "s"))
			game->player->x -= cosf(game->player->r) * slide_speed(game);
		else if (ft_strbcmp(direction, "a"))
			game->player->x += sinf(game->player->r) * slide_speed(game);
		else if (ft_strbcmp(direction, "d"))
			game->player->x -= sinf(game->player->r) * slide_speed(game);
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
int	t_game_check_collisions(t_game *g, t_player *p, char *dir, float speed)
{
	if (ft_strbcmp(dir, "w"))
	{
		if (!good_tile(g, p->x + cosf(p->r) * speed * t_game_delta(g),
				p->y + sinf(p->r) * speed * t_game_delta(g), dir))
			return (false);
	}
	else if (ft_strbcmp(dir, "s"))
	{
		if (!good_tile(g, p->x - cosf(p->r) * speed * t_game_delta(g),
				p->y - sinf(p->r) * speed * t_game_delta(g), dir))
			return (false);
	}
	else if (ft_strbcmp(dir, "a"))
	{
		if (!good_tile(g, p->x + sinf(p->r) * speed * t_game_delta(g),
				p->y - cosf(p->r) * speed * t_game_delta(g), dir))
			return (false);
	}
	else if (ft_strbcmp(dir, "d"))
	{
		if (!good_tile(g, p->x - sinf(p->r) * speed * t_game_delta(g),
				p->y + cosf(p->r) * speed * t_game_delta(g), dir))
			return (false);
	}
	return (true);
}
