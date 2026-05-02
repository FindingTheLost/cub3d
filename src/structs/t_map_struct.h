/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:00:50 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 02:01:17 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_STRUCT_H
# define T_MAP_STRUCT_H

# include "../../libft/libft.h"
# include "t_cub_struct.h"

typedef struct s_map
{
	size_t	map_width;
	size_t	map_height;
	char	**map;
}	t_map;

t_map	*t_map_build(void);
void	t_map_destroy(t_map *map);
void	t_map_malloc_error(void);
void	t_map_struct_error(void);
int		t_map_populate(t_cub *file, t_map **map_ref);

#endif
