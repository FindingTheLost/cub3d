/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:08:56 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 22:10:57 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_map_struct.h"

t_map	*t_map_build(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (t_map_malloc_error(), NULL);
	map->map_width = 0;
	map->map_height = 0;
	map->map = NULL;
	return (map);
}

