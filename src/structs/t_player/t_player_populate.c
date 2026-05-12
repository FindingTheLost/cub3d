/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_populate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:07:21 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/11 20:10:02 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_player_struct.h"

/* Returns the value of the rotation in radians.
 *
 * Normally 'N' is "M_PI_2" (PI divided by 2), 'S' is "(M_PI * 3) / 2", 'E' is
 * 0 and 'W' is "M_PI".
 * Since, in computers, 'y' is inverted (positive is "south"), 'N' will have the
 * value of 'S' and 'S' the value of 'N'.
 *
 * The values of 'W' and 'E' remain the same, since positive 'x' is still to the
 * right and negative to the left.
 */
static float	get_rotation(char orientation)
{
	if (orientation == 'N')
		return ((M_PI * 3) / 2);
	else if (orientation == 'S')
		return (M_PI_2);
	else if (orientation == 'W')
		return (M_PI);
	else
		return (0);
}

static int	set_player_values(char **map, t_player *player)
{
	size_t	line;
	size_t	column;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column])
		{
			if (ft_isalpha(map[line][column]))
			{
				player->x = column + 0.5f;
				player->y = line + 0.5f;
				player->r = get_rotation(map[line][column]);
				return (true);
			}
			column++;
		}
		line++;
	}
	return (t_player_struct_error(), false);
}

int	t_player_populate(t_cub *file, t_player **player_ref)
{
	t_player	*player;

	*player_ref = t_player_build();
	if (!*player_ref)
		return (false);
	player = *player_ref;
	if (!set_player_values(file->map, player))
		return (t_player_destroy(player), false);
	return (true);
}
