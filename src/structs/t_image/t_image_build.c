/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 01:08:49 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/05 01:10:54 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_image_struct.h"

t_image	*t_image_build(void)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (t_image_malloc_error(), NULL);
	image->image = NULL;
	image->address = NULL;
	image->bpp = 0;
	image->endian = 0;
	image->line_length = 0;
	return (image);
}
