/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_map_surroundings.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 00:28:30 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/28 00:57:37 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	parse_input_map_surroundings(char **argv)
{
	size_t	width;
	size_t	height;
	char	**map;

	width = t_cub_get_width(open_file(argv));
	height = t_cub_get_height(open_file(argv));
	map = t_cub_create_map(width, height, open_file(argv));
	if (!map)
		return (false);
	//check_surroundings(map);
	return (true);
}
