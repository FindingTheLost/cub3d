/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:41:09 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 20:17:13 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* To debug the "file" t_cub struct, call the "t_cub_debug()" function.
 */
int	main(int argc, char **argv)
{
	t_cub	*file;

	if (!parse_input(argc, argv))
		return (1);
	if (!t_cub_populate(argv, &file))
		return (2);
	if (!game(file))
		return (3);
	return (0);
}
