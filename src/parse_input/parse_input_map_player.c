/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_map_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:43:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 01:14:47 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static void	output_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Map element does not include a player/orientation!\n");
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
				ft_printf(RED_LIGH "Error\n" DEF);
				ft_printf("Map player/orientation has two or more instances!");
				ft_printf("\n");
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
		elements += t_cub_check_if_element(line);
		free(line);
		line = get_next_line(fd);
	}
	found = false;
	while (line)
	{
		if (!check_player(line, &found))
			return (free(line), ft_eof(fd), close(fd), false);
		free(line);
		line = get_next_line(fd);
	}
	if (!found)
		return (output_error(), close(fd), false);
	return (close(fd), true);
}
