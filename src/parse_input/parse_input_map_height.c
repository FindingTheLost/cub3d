/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_map_height.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 22:34:13 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/26 23:00:16 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

size_t	parse_input_map_height(int fd)
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
		elements += check_if_element(line);
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
	return (height);
}
