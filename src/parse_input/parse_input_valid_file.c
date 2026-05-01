/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_valid_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 19:18:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 01:26:52 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	parse_input_valid_file(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf(RED_LIGH "Error\n" DEF);
		ft_printf("File does not exist or permission denied!\n");
		return (false);
	}
	close(fd);
	return (true);
}
