/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 00:47:04 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/28 21:28:54 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_IMAGE_STRUCT_H
# define T_IMAGE_STRUCT_H

# include "../../libft/libft.h"
# include "../../minilibx-linux/mlx.h"
# include "../../minilibx-linux/mlx_int.h"

/* Defines an image to be displayed in a window, in accordance to Xorg and
 * Minilibx.
 */
typedef struct s_image
{
	void	*image;
	char	*address;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

t_image	*t_image_build(void);
t_image	*t_image_texture_to_image(void *texture, int width, int height);
void	t_image_destroy(void *mlx, t_image *image);
void	t_image_malloc_error(void);
void	t_image_struct_error(void);
void	t_image_image_error(void);
void	t_image_address_error(void);
void	t_image_debug(t_image *image);
int		t_image_populate(void *mlx, int width, int height, t_image **image_ref);

#endif
