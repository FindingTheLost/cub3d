/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:41:09 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/18 20:20:18 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	//cub_t	file;

	if (!parse_input(argc, argv))
		return (1);
	//if (!build_struct(&file))
	//	return (2);
	//init_cub3d(file);
	return (0);
}
