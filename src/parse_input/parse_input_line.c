/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:37:44 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 01:30:05 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static void	output_error(int code)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	if (code == 0)
		ft_printf("File element syntax error!\n");
	else if (code == 1)
		ft_printf("Wrong character found!\n");
	else if (code == 2)
		ft_printf("Map characters are not under its file elements!\n");
	else
		ft_printf("Something went wrong!\n");
}

static int	check_map_line(int map_mode, char *line, int *elements)
{
	size_t	index;

	index = 0;
	while (line[index])
	{
		if (line[index] != ' ' && line[index] != '0' && line[index] != '1'
			&& line[index] != 'N' && line[index] != 'S' && line[index] != 'W'
			&& line[index] != 'E' && line[index] != '\n')
		{
			output_error(1);
			return (false);
		}
		index++;
	}
	if (map_mode && *elements < 6)
	{
		output_error(2);
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
 * inputted before all of the elements are set".
 * When "false", the default behaviour of the function is used instead which is
 * to identify if there are any illegal lines, not taking into account whether
 * the map is fractured or if it's drawn before all of the other elements of
 * the map.
 * Behaviours:
 * 	- "true" for the former;
 * 	- "false" for the latter.
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
