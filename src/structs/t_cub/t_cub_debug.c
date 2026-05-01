/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:31:29 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 01:43:50 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

static void	debug_map(size_t width, size_t height, char **map)
{
	char	*result;
	size_t	line;

	result = ft_itoa((int)width);
	ft_printf("Map width: %s\n", result);
	free(result);
	result = ft_itoa((int)height);
	ft_printf("Map height: %s\n", result);
	free(result);
	ft_printf("Map content:\n");
	line = 0;
	while (map[line])
		ft_printf("%s\n", map[line++]);
}

static void	debug_color(unsigned char color[3], char *element)
{
	char	*result;
	size_t	index;

	ft_printf("%s color: ", element);
	index = 0;
	while (index < 3)
	{
		result = ft_itoa((int)color[index]);
		ft_printf("%s", result);
		if (index < 2)
			ft_printf(", ");
		free(result);
		index++;
	}
	ft_printf("\n");
}

static void	debug_files(t_cub *file)
{
	ft_printf("North file: %s\n", file->no_file);
	ft_printf("South file: %s\n", file->so_file);
	ft_printf("East file: %s\n", file->ea_file);
	ft_printf("West file: %s\n", file->we_file);
}

void	t_cub_debug(t_cub *file)
{
	debug_files(file);
	debug_color(file->f_color, "Floor");
	debug_color(file->c_color, "Ceiling");
	debug_map(file->map_width, file->map_height, file->map);
}
