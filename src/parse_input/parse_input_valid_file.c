/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_valid_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:18:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/18 20:30:39 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	parse_input_valid_file(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
		write(STDOUT_FILENO, "File does not exist or permission denied!\n", 42);
		return (false);
	}
	close(fd);
	return (true);
}
