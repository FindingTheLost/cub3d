/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:55:04 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 18:20:47 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

/* Destroys a memory allocated "t_cub" struct passed as parameter.
 */
void	t_cub_destroy(t_cub *file)
{
	size_t	index;

	if (file->no_file)
		free(file->no_file);
	if (file->so_file)
		free(file->so_file);
	if (file->ea_file)
		free(file->ea_file);
	if (file->we_file)
		free(file->we_file);
	if (file->map)
	{
		index = 0;
		while (file->map[index])
			free(file->map[index++]);
		free(file->map);
	}
	free(file);
}
