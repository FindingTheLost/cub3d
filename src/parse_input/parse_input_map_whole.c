/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_map_whole.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:47:34 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/26 23:00:46 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int	check_map(char *line, int *map_start, int *map_end)
{
	if (line[0] == '\n' || line[0] == '\0')
	{
		if (*map_start)
			*map_end = true;
		return (true);
	}
	if (*map_end)
	{
		write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
		write(STDOUT_FILENO, "Map content must not be separated by", 36);
		write(STDOUT_FILENO, " empty lines!\n", 14);
		return (false);
	}
	*map_start = true;
	return (true);
}

/* This function will ignore all empty lines until it finds one that has, at
 * least, one map character. If one map character line is found, it keeps
 * track of it, as well as if a new empty line is found (that symbolizes the
 * end of the map).
 * If, after the end of map is found, a map character line is found again,
 * the function returns ("false").
 */
int	parse_input_map_whole(int fd)
{
	char	*line;
	int		elements;
	int		map_start;
	int		map_end;

	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	elements = 0;
	while (elements < 6)
	{
		elements += check_if_element(line);
		free(line);
		line = get_next_line(fd);
	}
	map_start = false;
	map_end = false;
	while (line)
	{
		if (!check_map(line, &map_start, &map_end))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	return (true);
}
