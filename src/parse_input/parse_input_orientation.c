/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_orientation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:16:13 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 01:24:48 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static void	output_error(char *element, int code)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("%s ", element);
	if (code == 0)
		ft_printf("element is missing from this '.cub' file!\n");
	else if (code == 1)
		ft_printf("element has two or more instances!\n");
	else if (code == 2)
		ft_printf("element does not refer to a '.xpm' file!\n");
	else if (code == 3)
		ft_printf("element '.xpm' file does not exist or permission denied!\n");
	else if (code == 4)
		ft_printf("element has no valid '.xpm' file!\n");
	else
		ft_printf("element has serious issues!\n");
}

/* The path of the ".xpm" file in the ".cub" must be a relative path of the
 * program's current directory. Therefore, the path to the textures must be
 * accessible as if coming from the path where the "cub3D" executable is
 * found.
 */
static int	check_path(char *element, char *line)
{
	size_t	index;
	int		fd;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	index = 3;
	while (line[index] == ' ')
		index++;
	if (!line[index])
		return (output_error(element, 2), false);
	fd = open(&line[index], O_RDONLY);
	if (fd == -1)
		return (output_error(element, 3), false);
	close(fd);
	index = ft_strlen(line);
	if (line[index - 1] == 'm' && line[index - 2] == 'p'
		&& line[index - 3] == 'x' && line[index - 4] == '.')
		return (true);
	return (output_error(element, 4), false);
}

static int	check_symbol(char *element, char *line, int *found)
{
	if (ft_strlen(line) < ft_strlen(element))
		return (true);
	if (line[0] == element[0] && line[1] == element[1] && line[2] == ' ')
	{
		if (*found)
		{
			output_error(element, 1);
			return (false);
		}
		if (!check_path(element, line))
			return (false);
		*found = true;
		return (true);
	}
	if (line[0] == element[0] && line[1] == element[1]
		&& (line[2] == '\n' || line[2] == '\0' || line[2] != ' '))
	{
		if (*found)
			output_error(element, 1);
		else
			output_error(element, 2);
		return (false);
	}
	return (true);
}

int	parse_input_orientation(int fd, char *element)
{
	char	*line;
	int		found;

	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	found = false;
	while (line)
	{
		if (!check_symbol(element, line, &found))
			return (free(line), ft_eof(fd), close(fd), false);
		free(line);
		line = get_next_line(fd);
	}
	if (found)
		return (close(fd), true);
	output_error(element, 0);
	return (close(fd), false);
}
