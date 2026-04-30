/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_map_surroundings.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 00:28:30 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 18:12:05 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static int	check_walls(char **map)
{
	size_t	line;
	size_t	i;

	line = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (map[line][i] == '0' || ft_isalpha(map[line][i]))
			{
				if (map[line][i + 1] == ' '
					|| (i > 0 && map[line][i - 1] == ' ')
					|| (map[line + 1] && map[line + 1][i] == ' ')
					|| (line > 0 && map[line - 1][i] == ' '))
					return (false);
			}
			i++;
		}
		line++;
	}
	return (true);
}

static int	check_left_right(size_t width, char **map)
{
	size_t	line;
	size_t	index;

	line = 0;
	index = width - 1;
	while (map[line])
	{ 
		if (map[line][0] == '0' || ft_isalpha(map[line][0]))
			return (false);
		if (index != 0)
		{
			if (map[line][index] == '0' || ft_isalpha(map[line][index]))
				return (false);
		}
		line++;
	}
	return (true);
}

static int	check_top_bottom(size_t height, char **map)
{
	size_t	line;
	size_t	index;

	index = 0;
	line = height - 1;
	while (map[0][index])
	{
		if (map[0][index] == '0' || ft_isalpha(map[0][index]))
			return (false);
		index++;
	}
	if (line != 0)
	{
		index = 0;
		while (map[line][index])
		{
			if (map[line][index] == '0' || ft_isalpha(map[line][index]))
				return (false);
			index++;
		}
	}
	return (true);
}

static int	check_map_surroundings(size_t width, size_t height, char **map)
{
	if (!check_top_bottom(height, map))
		return (false);
	if (!check_left_right(width, map))
		return (false);
	if (!check_walls(map))
		return (false);
	return (true);
}

int	parse_input_map_surroundings(char **argv)
{
	size_t	index;
	size_t	width;
	size_t	height;
	char	**map;
	int		result;

	width = t_cub_get_width(t_cub_open_file(argv));
	height = t_cub_get_height(t_cub_open_file(argv));
	map = t_cub_build_map(width, height, t_cub_open_file(argv));
	if (!map)
		return (false);
	result = check_map_surroundings(width, height, map);
	index = 0;
	while (map[index])
		free(map[index++]);
	free(map);
	if (!result)
	{
		write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
		write(STDOUT_FILENO, "Map element is not properly surrounded", 38);
		write(STDOUT_FILENO, " by walls!\n", 11);
		return (false);
	}
	return (true);
}
