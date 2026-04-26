/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_map_found.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:17:54 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/26 23:00:06 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	parse_input_map_found(int fd)
{
	char	*line;
	int		elements;

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
	while (line)
	{
		if (line[0] != '\n' && line[0] != '\0')
			return (free(line), true);
		free(line);
		line = get_next_line(fd);
	}
	write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
	write(STDOUT_FILENO, "Map element is missing from this '.cub' file!\n", 46);
	return (false);
}
