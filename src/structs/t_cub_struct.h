/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 23:26:17 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/27 23:24:16 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CUB_STRUCT_H
# define T_CUB_STRUCT_H

# include "../../libft/libft.h"

typedef struct s_cub
{
	char	*no_file;
	char	*so_file;
	char	*ea_file;
	char	*we_file;
	char	f_color[3];
	char	c_color[3];
	char	**map;
	size_t	map_width;
	size_t	map_height;
}	t_cub;

t_cub	*t_cub_build(void);
void	t_cub_destroy(t_cub *file);
void	t_cub_malloc_error(void);
size_t	t_cub_get_width(int fd);
size_t	t_cub_get_height(int fd);
char	**t_cub_create_map(size_t width, size_t height, int fd);
int		t_cub_check_if_element(char *line);

#endif
