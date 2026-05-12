/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:10:18 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/11 16:39:07 by pde-alme         ###   ########.fr       */
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
		ft_printf("element does not refer to a color!\n");
	else if (code == 3)
		ft_printf("element syntax is incorrect!\n");
	else if (code == 4)
		ft_printf("element color is out of byte range!\n");
	else if (code == 5)
		ft_printf("element color's number is too large!\n");
	else if (code == 6)
		ft_printf("element color's bytes are not properly comma separated!\n");
	else
		ft_printf("Something went wrong!\n");
}

/* The type "ssize_t" is the same as "size_t", only with "SIZE_T MAX - 1" range,
 * due to also having ONE (and only one) negative number, "-1". It's range goes
 * from "-1" to "SIZE_T MAX - 1".
 */
static int	check_bytes(char *element, char *line, size_t *index, ssize_t cycle)
{
	size_t	large;

	while (++cycle < 3 && ft_isdigit(line[*index]))
	{
		large = 0;
		if (ft_atoi(&line[*index]) < 0 || ft_atoi(&line[*index]) > 255)
			return (output_error(element, 4), false);
		while (ft_isdigit(line[*index]) && ++large && large <= 3)
			(*index)++;
		if (large > 3)
			return (output_error(element, 5), false);
		while (cycle < 2 && line[*index] == ' ')
			(*index)++;
		if (cycle < 2)
		{
			if (line[*index] != ',')
				return (output_error(element, 6), false);
			(*index)++;
			while (line[*index] == ' ')
				(*index)++;
		}
	}
	if (cycle == 3)
		return (true);
	return (output_error(element, 3), false);
}

static int	check_color(char *element, char *line)
{
	size_t	index;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	index = 2;
	while (line[index] == ' ')
		index++;
	if (!line[index])
		return (output_error(element, 2), false);
	if (!check_bytes(element, line, &index, -1))
		return (false);
	if (line[index])
		return (output_error(element, 3), false);
	return (true);
}

static int	check_element(char *element, char *line, int *found)
{
	if (ft_strlen(line) < ft_strlen(element))
		return (true);
	if (line[0] == element[0] && line[1] == ' ')
	{
		if (*found)
			return (output_error(element, 1), false);
		if (!check_color(element, line))
			return (false);
		*found = true;
		return (true);
	}
	if (line[0] == element[0] && (line[1] == '\n' || line[1] == '\0'
			|| line[1] != ' '))
	{
		if (*found)
			output_error(element, 1);
		else
			output_error(element, 2);
		return (false);
	}
	return (true);
}

int	parse_input_color(int fd, char *element)
{
	char	*line;
	int		found;

	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	found = false;
	while (line)
	{
		if (!check_element(element, line, &found))
			return (free(line), ft_eof(fd), close(fd), false);
		free(line);
		line = get_next_line(fd);
	}
	if (found)
		return (close(fd), true);
	return (output_error(element, 0), close(fd), false);
}
