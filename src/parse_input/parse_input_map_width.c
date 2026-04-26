/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_map_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:38:20 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/26 23:00:57 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

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

size_t	parse_input_map_width(int fd)
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
		elements += check_if_element(line);
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
	return (width);
}
