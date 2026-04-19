/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 20:05:43 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/19 20:45:51 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int	open_file(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDOUT_FILENO, "\033[91mError\n\033[0m", 6);
		write(STDOUT_FILENO, "Failed opening file!\n", 21);
	}
	return (fd);
}

static int	parse_input_map(char **argv)
{
	if (!parse_input_line(open_file(argv), true))
		return (false);
	return (true);
}

static int	parse_input_elements(char **argv)
{
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
	return (true);
}

static int	parse_input_file(int argc, char **argv)
{
	if (!parse_input_argc(argc))
		return (false);
	if (!parse_input_file_extension(argv))
		return (false);
	if (!parse_input_valid_file(argv))
		return (false);
	if (!parse_input_line(open_file(argv), false))
		return (false);
	return (true);
}

int	parse_input(int argc, char **argv)
{
	if (!parse_input_file(argc, argv))
		return (false);
	if (!parse_input_elements(argv))
		return (false);
	if (!parse_input_map(argv))
		return (false);
	return (true);
}
