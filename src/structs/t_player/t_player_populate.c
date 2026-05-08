/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_populate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:07:21 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/08 01:44:02 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_player_struct.h"

/* Returns the value of the rotation in radians, not degrees.
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
