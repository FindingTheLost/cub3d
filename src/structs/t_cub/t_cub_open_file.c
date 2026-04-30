/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_open_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:12:24 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 18:21:30 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

int	t_cub_open_file(char **argv)
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
