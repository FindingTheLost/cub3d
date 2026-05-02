/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_populate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:07:21 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 00:52:04 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_player_struct.h"

/* Returns the value of the rotation in radians, not degrees.
 */
static float	get_rotation(char orientation)
{
	if (orientation == 'N')
		return (0);
	else if (orientation == 'S')
		return (M_PI);
	else if (orientation == 'W')
		return ((M_PI * 3) / 2);
	else
		return (M_PI_2);
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
				player->x_pos = column + 0.5f;
				player->y_pos = line + 0.5f;
				player->rotation = get_rotation(map[line][column]);
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
