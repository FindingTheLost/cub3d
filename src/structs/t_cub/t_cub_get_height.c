/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_get_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:49:36 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 18:21:16 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

size_t	t_cub_get_height(int fd)
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
		elements += t_cub_check_if_element(line);
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
	return (close(fd), height);
}
