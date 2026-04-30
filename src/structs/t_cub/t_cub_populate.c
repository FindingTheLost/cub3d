/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_populate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:03:09 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 23:25:25 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

static void	set_index(size_t *index, unsigned char number)
{
	if (number > 99)
		*index = *index + 3;
	else if (number > 9)
		*index = *index + 2;
	else
		*index = *index + 1;
}

static int	set_color(unsigned char color[3], int fd, char element, size_t i)
{
	char	*line;
	size_t	color_i;

	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == element)
		{
			color_i = 0;
			while (color_i < 3)
			{
				while (line[i] == ' ' || line[i] == ',')
					i++;
				color[color_i] = ft_atoi(&line[i]);
				set_index(&i, color[color_i++]);
			}
			return (free(line), ft_eof(fd), close(fd), true);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (t_cub_struct_error(), close(fd), false);
}

static char	*alloc_xpm(int fd, char *element)
{
	char	*line;
	char	*copy;
	size_t	index;

	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, element, 2))
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			index = 2;
			while (line[index] == ' ')
				index++;
			copy = ft_strdup(&line[index]);
			if (!copy)
				t_cub_malloc_error();
			return (free(line), ft_eof(fd), close(fd), copy);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (t_cub_struct_error(), close(fd), NULL);
}

int	alloc_map(char **argv, t_cub *file)
{
	file->map_width = t_cub_get_width(t_cub_open_file(argv));
	file->map_height = t_cub_get_height(t_cub_open_file(argv));
	file->map = t_cub_build_map(file->map_width, file->map_height,
			t_cub_open_file(argv));
	if (!file->map)
		return (false);
	return (true);
}

int	t_cub_populate(char **argv, t_cub **file_ref)
{
	t_cub	*file;

	*file_ref = t_cub_build();
	if (!*file_ref)
		return (false);
	file = *file_ref;
	file->no_file = alloc_xpm(t_cub_open_file(argv), "NO");
	if (!file->no_file)
		return (t_cub_destroy(file), false);
	file->so_file = alloc_xpm(t_cub_open_file(argv), "SO");
	if (!file->so_file)
		return (t_cub_destroy(file), false);
	file->ea_file = alloc_xpm(t_cub_open_file(argv), "EA");
	if (!file->ea_file)
		return (t_cub_destroy(file), false);
	file->we_file = alloc_xpm(t_cub_open_file(argv), "WE");
	if (!file->we_file)
		return (t_cub_destroy(file), false);
	if (!set_color(file->f_color, t_cub_open_file(argv), 'F', 1))
		return (t_cub_destroy(file), false);
	if (!set_color(file->c_color, t_cub_open_file(argv), 'C', 1))
		return (t_cub_destroy(file), false);
	if (!alloc_map(argv, file))
		return (t_cub_destroy(file), false);
	return (true);
}
