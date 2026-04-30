/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:31:29 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/30 20:27:02 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

static void	debug_map(size_t width, size_t height, char **map)
{
	char	*result;
	size_t	line;

	write(STDOUT_FILENO, "Map width: ", 11);
	result = ft_itoa((int)width);
	write(STDOUT_FILENO, result, ft_strlen(result));
	free(result);
	write(STDOUT_FILENO, "\nMap height: ", 13);
	result = ft_itoa((int)height);
	write(STDOUT_FILENO, result, ft_strlen(result));
	free(result);
	write(STDOUT_FILENO, "\nMap content:\n", 14);
	line = 0;
	while (map[line])
	{
		write(STDOUT_FILENO, map[line], ft_strlen(map[line]));
		write(STDOUT_FILENO, "\n", 1);
		line++;
	}
}

static void	debug_color(unsigned char color[3], char *element)
{
	char	*result;
	size_t	index;

	write(STDOUT_FILENO, element, ft_strlen(element));
	write(STDOUT_FILENO, " color: ", 8);
	index = 0;
	while (index < 3)
	{
		result = ft_itoa((int)color[index]);
		write(STDOUT_FILENO, result, ft_strlen(result));
		if (index < 2)
			write(STDOUT_FILENO, ", ", 2);
		free(result);
		index++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

static void	debug_files(t_cub *file)
{
	write(STDOUT_FILENO, "North file: ", 12);
	write(STDOUT_FILENO, file->no_file, ft_strlen(file->no_file));
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "South file: ", 12);
	write(STDOUT_FILENO, file->so_file, ft_strlen(file->so_file));
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "East file: ", 11);
	write(STDOUT_FILENO, file->ea_file, ft_strlen(file->ea_file));
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "West file: ", 11);
	write(STDOUT_FILENO, file->we_file, ft_strlen(file->we_file));
	write(STDOUT_FILENO, "\n", 1);
}

void	t_cub_debug(t_cub *file)
{
	debug_files(file);
	debug_color(file->f_color, "Floor");
	debug_color(file->c_color, "Ceiling");
	debug_map(file->map_width, file->map_height, file->map);
}
