/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:13:24 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 02:06:15 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_map_struct.h"

void	t_map_destroy(t_map *map)
{
	size_t	index;

	if (map->map)
	{
		index = 0;
		while (map->map[index])
		{
			free(map->map[index]);
			index++;
		}
		free(map->map);
	}
	free(map);
}
