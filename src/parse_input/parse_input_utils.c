/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:25:24 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/27 18:03:09 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	check_if_element(char *line)
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

int	open_file(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDOUT_FILENO, "\033[91mError\n\033[0m", 6);
		write(STDOUT_FILENO, "Failed opening file!\n", 21);
	}
	return (fd);
}
