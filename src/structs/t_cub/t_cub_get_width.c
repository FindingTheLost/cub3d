/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_get_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:48:02 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 18:21:08 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

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
