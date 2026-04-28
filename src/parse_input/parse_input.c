/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:05:43 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/27 23:46:14 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int	parse_input_map(char **argv)
{
	if (!parse_input_line(open_file(argv), true))
		return (false);
	if (!parse_input_map_found(open_file(argv)))
		return (false);
	if (!parse_input_map_whole(open_file(argv)))
		return (false);
	if (!parse_input_map_player(open_file(argv)))
		return (false);
	if (!parse_input_map_surroundings(argv))
		return (false);
	return (true);
}

/* Series of checks that verify whether the passed ".cub" file is valid.
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
