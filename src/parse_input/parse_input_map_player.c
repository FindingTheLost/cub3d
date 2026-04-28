/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_map_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:43:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/27 18:12:00 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static void	output_error(void)
{
	write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
	write(STDOUT_FILENO, "Map element does not include a", 30);
	write(STDOUT_FILENO, " player/orientation!\n", 21);
}

static int	check_player(char *line, int *found)
{
	size_t	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == 'N' || line[index] == 'S' || line[index] == 'E'
			|| line[index] == 'W')
		{
			if (*found)
			{
				write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
				write(STDOUT_FILENO, "Map player/orientation has two or", 33);
				write(STDOUT_FILENO, " more instances!\n", 17);
				return (false);
			}
			*found = true;
		}
		index++;
	}
	return (true);
}

int	parse_input_map_player(int fd)
{
	char	*line;
	int		elements;
	int		found;

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
	found = false;
	while (line)
	{
		if (!check_player(line, &found))
			return (free(line), close(fd), false);
		free(line);
		line = get_next_line(fd);
	}
	if (!found)
		return (output_error(), close(fd), false);
	return (close(fd), true);
}
