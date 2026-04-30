/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:54:33 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 22:06:24 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

/* Memory allocates a new "file" variable of type "t_cub" and sets all of its
 * attributes to "NULL" before returning it.
 * Returns the "t_cub" variable or "NULL" in case of a memory allocation error.
 */
t_cub	*t_cub_build(void)
{
	t_cub	*file;
	size_t	index;

	file = malloc(sizeof(t_cub));
	if (!file)
		return (t_cub_malloc_error(), NULL);
	file->no_file = NULL;
	file->so_file = NULL;
	file->ea_file = NULL;
	file->we_file = NULL;
	index = 0;
	while (index < 3)
	{
		file->f_color[index] = 0;
		file->c_color[index] = 0;
		index++;
	}
	file->map = NULL;
	file->map_width = 0;
	file->map_height = 0;
	return (file);
}
