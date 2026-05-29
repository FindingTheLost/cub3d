/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:37:44 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/28 19:00:26 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static void	output_error(int code)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	if (code == 0)
		ft_printf("Wrong character found!\n");
	else if (code == 1)
		ft_printf("Map content is not under its file elements!\n");
	else
		ft_printf("Something went wrong!\n");
}

/* The following characters refer to:
 * - ' ' = An empty space tile;
 * - '0' = A ground tile;
 * - '1' = A wall tile;
 * - 'N', 'S', 'W' and 'E' = A player spawning and orientation tile.
 * - 'D' = A door tile;
 */
static int	check_map_line(int map_mode, char *line, int *elements)
{
	size_t	index;

	index = 0;
	while (line[index])
	{
		if (line[index] != ' ' && line[index] != '0' && line[index] != '1'
			&& line[index] != 'N' && line[index] != 'S' && line[index] != 'W'
			&& line[index] != 'E' && line[index] != 'D' && line[index] != '\n')
		{
			output_error(0);
			return (false);
		}
		index++;
	}
	if (map_mode && *elements < 6)
	{
		output_error(1);
		return (false);
	}
	return (true);
}

static int	check_line(int map_mode, char *line, int *elements)
{
	if (ft_strlen(line) >= 2)
	{
		if (line[0] == 'N' && line[1] == 'O')
			return ((*elements)++, true);
		if (line[0] == 'S' && line[1] == 'O')
			return ((*elements)++, true);
		if (line[0] == 'W' && line[1] == 'E')
			return ((*elements)++, true);
		if (line[0] == 'E' && line[1] == 'A')
			return ((*elements)++, true);
		if (line[0] == 'F' || line[0] == 'C')
			return ((*elements)++, true);
		if (check_map_line(map_mode, line, elements))
			return (true);
		return (false);
	}
	if (line[0] == 'F' || line[0] == 'C' || line[0] == '\n' || line[0] == '\0')
		return (true);
	if (check_map_line(map_mode, line, elements))
		return (true);
	return (false);
}

/* The "map_mode" variable can be set to either "true" or "false" to distinguish
 * whether the function will attempt to identify "if parts of the map are
 * inputted before all of the remaining elements".
 *
 * When "false", the default behaviour of the function is used, which is to
 * identify if there are any illegal characters in the map and does not take
 * into account whether the map is fractured or written before all the other
 * elements.
 *
 * Behaviours:
 * 	- "false" - checks if there are any illegal characters in the map;
 * 	- "true" - checks if the map is written before all the other elements;
 */
int	parse_input_line(int fd, int map_mode)
{
	char	*line;
	int		elements;

	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	elements = 0;
	while (line)
	{
		if (!check_line(map_mode, line, &elements))
			return (free(line), ft_eof(fd), close(fd), false);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), true);
}
