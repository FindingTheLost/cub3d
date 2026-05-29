/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_texture_to_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:24:13 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/28 21:30:39 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_image_struct.h"

/* Function that converts a "void *" texture to a memory allocated "t_image"
 * pointer struct, with all the remaining data that weren't available in the
 * void pointer alone.
 *
 * Accepts any kind of texture that was, at least, opened with the function
 * "mlx_xpm_to_image()".
 */
t_image	*t_image_texture_to_image(void *texture, int width, int height)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (t_image_malloc_error(), NULL);
	image->image = texture;
	image->address = mlx_get_data_addr(image->image, &image->bpp,
			&image->line_length, &image->endian);
	if (!image->address)
		return (free(image), t_image_address_error(), NULL);
	image->width = width;
	image->height = height;
	return (image);
}
