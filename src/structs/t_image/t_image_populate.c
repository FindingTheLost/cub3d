/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_populate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 01:30:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/26 01:48:12 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_image_struct.h"

/* In theory, there can be many images in a window. If an image is built with
 * the resolution's coordenates as image size and another image with 50 x 50,
 * with the function "mlx_put_image_to_window()" both can be drawn starting
 * from coordenates 0 x 0 (first the resolution image and then the 50 x 50)
 * and we can see that both images are displayed on the screen, with the
 * 50 x 50 image standing on the top left corner above the resolution one.
 */
int	t_image_populate(void *mlx, int width, int height, t_image **image_ref)
{
	t_image	*image;

	*image_ref = t_image_build();
	if (!*image_ref)
		return (false);
	image = *image_ref;
	image->image = mlx_new_image(mlx, width, height);
	if (!image->image)
		return (t_image_image_error(), false);
	image->address = mlx_get_data_addr(image->image, &image->bpp,
			&image->line_length, &image->endian);
	if (!image->address)
		return (t_image_address_error(), false);
	image->width = width;
	image->height = height;
	return (true);
}
