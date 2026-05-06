/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:58:44 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/05 18:02:58 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_map_struct.h"

void	t_map_debug(t_map *map)
{
	size_t	index;

	ft_printf(RED_BOLD "T_MAP STRUCT DEBUG:\n" DEF);
	ft_printf("Map width: %u\n", map->map_width);
	ft_printf("Map height: %u\n", map->map_height);
	ft_printf("Map content:\n");
	index = 0;
	while (index < map->map_height)
	{
		ft_printf("%s\n", map->map[index]);
		index++;
	}
}
