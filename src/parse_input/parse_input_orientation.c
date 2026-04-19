/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_orientation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:16:13 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/19 20:12:12 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static void	output_error(char *element, int code)
{
	write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
	write(STDOUT_FILENO, element, ft_strlen(element));
	if (code == 0)
		write(STDOUT_FILENO, " element is missing from this '.cub' file!\n",
			43);
	else if (code == 1)
		write(STDOUT_FILENO, " element has two or more instances!\n", 36);
	else if (code == 2)
		write(STDOUT_FILENO, " element does not refer to a '.xpm' file!\n", 42);
	else if (code == 3)
	{
		write(STDOUT_FILENO, " element '.xpm' file does not exist or ", 39);
		write(STDOUT_FILENO, "permission denied!\n", 19);
	}
	else if (code == 4)
		write(STDOUT_FILENO, " element has no valid '.xpm' file!\n", 35);
	else
		write(STDOUT_FILENO, "Something went wrong!\n", 22);
}

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
		&& (line[2] == '\n' || line[2] == '\0'))
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
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (found)
		return (true);
	output_error(element, 0);
	return (false);
}
