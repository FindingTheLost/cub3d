/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_struct_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 23:13:58 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/27 23:25:11 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cub_struct.h"

static size_t	get_width(char *line, size_t width)
{
	size_t	size;

	size = ft_strlen(line);
	if (size > width)
	{
		width = size;
		if (size > 0 && line[size - 1] == '\n')
			width--;
	}
	return (width);
}

size_t	t_cub_get_width(int fd)
{
	char	*line;
	int		elements;
	size_t	width;

	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	elements = 0;
	while (elements < 6)
	{
		elements += t_cub_check_if_element(line);
		free(line);
		line = get_next_line(fd);
	}
	width = 0;
	while (line)
	{
		width = get_width(line, width);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), width);
}

size_t	t_cub_get_height(int fd)
{
	char	*line;
	int		elements;
	size_t	height;

	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	elements = 0;
	while (elements < 6)
	{
		elements += t_cub_check_if_element(line);
		free(line);
		line = get_next_line(fd);
	}
	height = 0;
	while (line)
	{
		if (line[0] != '\n' && line[0] != '\0')
			height++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), height);
}

int	t_cub_check_if_element(char *line)
{
	if (ft_strlen(line) >= 2)
	{
		if (line[0] == 'N' && line[1] == 'O')
			return (1);
		if (line[0] == 'S' && line[1] == 'O')
			return (1);
		if (line[0] == 'W' && line[1] == 'E')
			return (1);
		if (line[0] == 'E' && line[1] == 'A')
			return (1);
		if (line[0] == 'F' || line[0] == 'C')
			return (1);
	}
	return (0);
}

void	t_cub_malloc_error(void)
{
	write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
	write(STDOUT_FILENO, "Dynamic memory allocation failed!\n", 34);
}
