/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_populate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:54:47 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 02:17:55 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_map_struct.h"

static void	replace_player(char **map)
{
	size_t	line;
	size_t	column;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column])
		{
			if (map[line][column] == 'N' || map[line][column] == 'S'
				|| map[line][column] == 'W' || map[line][column] == 'E')
			{
				map[line][column] = '0';
				return ;
			}
			column++;
		}
		line++;
	}
}

/* This map copy is the same as the map from the "file" variable but with its
 * player location ('N', 'S', 'W', 'E') replaced with a '0'.
 */
static char	**get_map_copy(t_cub *file)
{
	char	**map;
	size_t	index;

	map = malloc(sizeof(char *) * (file->map_height + 1));
	if (!map)
		return (t_map_malloc_error(), NULL);
	index = 0;
	while (index < file->map_height)
	{
		map[index] = ft_strdup(file->map[index]);
		if (!map[index])
		{
			while (index-- > 0)
				free(map[index]);
			free(map);
			return (t_map_malloc_error(), NULL);
		}
		index++;
	}
	map[index] = NULL;
	replace_player(map);
	return (map);
}

int	t_map_populate(t_cub *file, t_map **map_ref)
{
	t_map	*map;

	*map_ref = malloc(sizeof(t_map));
	if (!*map_ref)
		return (false);
	map = *map_ref;
	map->map_width = file->map_width;
	map->map_height = file->map_height;
	map->map = get_map_copy(file);
	if (!map->map)
		return (false);
	return (true);
}
