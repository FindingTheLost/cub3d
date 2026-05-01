/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:41:09 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 00:26:41 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*file;

	if (!parse_input(argc, argv))
		return (1);
	if (!t_cub_populate(argv, &file))
		return (2);
	t_cub_debug(file);
	t_cub_destroy(file);
	//init_cub3d(file);
	return (0);
}
