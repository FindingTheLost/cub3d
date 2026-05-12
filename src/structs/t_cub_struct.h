/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 23:26:17 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/11 17:23:09 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CUB_STRUCT_H
# define T_CUB_STRUCT_H

# include "../../libft/libft.h"

/* Defines a ".cub" file's contents after being parsed.
 */
typedef struct s_cub
{
	char			*no_file;
	char			*so_file;
	char			*ea_file;
	char			*we_file;
	char			**map;
	size_t			map_width;
	size_t			map_height;
	unsigned char	f_color[3];
	unsigned char	c_color[3];
}	t_cub;

t_cub	*t_cub_build(void);
char	**t_cub_build_map(size_t width, size_t height, int fd);
void	t_cub_destroy(t_cub *file);
void	t_cub_malloc_error(void);
void	t_cub_struct_error(void);
void	t_cub_debug(t_cub *file);
size_t	t_cub_get_width(int fd);
size_t	t_cub_get_height(int fd);
int		t_cub_check_if_element(char *line);
int		t_cub_open_file(char **argv);
int		t_cub_populate(char **argv, t_cub **file_ref);

#endif
