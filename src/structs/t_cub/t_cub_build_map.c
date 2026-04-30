/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_build_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:55:43 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 21:18:36 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

/* Fills the map's empty space characters with the characters from their
 * respective position in the file descriptor passed as parameter.
 * Returns "void" although changes the map's characters directly through the
 * pointer.
 */
static void	t_cub_fill_map(int fd, char **map)
{
	char	*line;
	size_t	map_i;
	size_t	index;

	line = get_next_line(fd);
	map_i = 0;
	while (line && map[map_i])
	{
		index = 0;
		if (line[0] != '\n' && line[0] != '\0')
		{
			while (map[map_i][index] && line[index] && line[index] != '\n')
			{
				map[map_i][index] = line[index];
				index++;
			}
			while (map[map_i][index])
				map[map_i][index++] = ' ';
			map_i++;
		}
		free(line);
		line = get_next_line(fd);
	}
}

/* Takes a "width" and "height" as parameters, normally from a "t_cub" struct's
 * "map_width" and "map_height" attributes, and a file descriptor that points to
 * a ".cub" file whose padding (elements and colors) have already been scraped
 * leaving only the map element to be extracted.
 * Returns the memory allocated map with ' ' in all of its cells or "NULL" in
 * case of a memory allocation error.
 */
static char	**t_cub_alloc_map(size_t width, size_t height, int fd)
{
	char	**map;
	size_t	line;
	size_t	cell;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (t_cub_malloc_error(), NULL);
	line = 0;
	while (line < height)
	{
		cell = 0;
		map[line] = malloc(sizeof(char) * (width + 1));
		if (!map[line])
		{
			while (line-- > 0)
				free(map[line]);
			return (free(map), t_cub_malloc_error(), NULL);
		}
		while (cell < width)
			map[line][cell++] = ' ';
		map[line][cell] = '\0';
		line++;
	}
	map[line] = NULL;
	return (t_cub_fill_map(fd, map), map);
}

char	**t_cub_build_map(size_t width, size_t height, int fd)
{
	char	**map;
	char	*line;
	int		elements;

	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	elements = 0;
	while (elements < 6)
	{
		elements += t_cub_check_if_element(line);
		free(line);
		if (elements < 6)
			line = get_next_line(fd);
		else
			line = NULL;
	}
	map = t_cub_alloc_map(width, height, fd);
	if (!map)
		return (close(fd), NULL);
	return (close(fd), map);
}
