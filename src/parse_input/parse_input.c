/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:05:43 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/26 23:08:28 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int	parse_input_map(char **argv)
{
	size_t	width;
	size_t	height;

	if (!parse_input_line(open_file(argv), true))
		return (false);
	if (!parse_input_map_found(open_file(argv)))
		return (false);
	if (!parse_input_map_whole(open_file(argv)))
		return (false);
	if (!parse_input_map_player(open_file(argv)))
		return (false);
	width = parse_input_map_width(open_file(argv));
	height = parse_input_map_height(open_file(argv));
	printf("width: %lu | height: %lu\n", width, height);
	return (true);
}

/* Series of checks that verify whether the passed ".cub" file is valid before
 * passing the "file" struct variable onto the "t_cub" struct builder function.
 */
int	parse_input(int argc, char **argv)
{
	if (!parse_input_argc(argc))
		return (false);
	if (!parse_input_file_extension(argv))
		return (false);
	if (!parse_input_valid_file(argv))
		return (false);
	if (!parse_input_line(open_file(argv), false))
		return (false);
	if (!parse_input_orientation(open_file(argv), "NO"))
		return (false);
	if (!parse_input_orientation(open_file(argv), "SO"))
		return (false);
	if (!parse_input_orientation(open_file(argv), "WE"))
		return (false);
	if (!parse_input_orientation(open_file(argv), "EA"))
		return (false);
	if (!parse_input_color(open_file(argv), "F"))
		return (false);
	if (!parse_input_color(open_file(argv), "C"))
		return (false);
	if (!parse_input_map(argv))
		return (false);
	return (true);
}
