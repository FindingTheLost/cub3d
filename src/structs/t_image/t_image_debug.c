/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:03:17 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/05 18:08:13 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_image_struct.h"

void	t_image_debug(t_image *image)
{
	ft_printf(RED_BOLD "T_IMAGE STRUCT DEBUG:\n" DEF);
	if (image->image)
		ft_printf("Image: present.\n");
	else
		ft_printf("Image: not present.\n");
	ft_printf("Address: %s\n", image->address);
	ft_printf("Bits per pixel: %i\n", image->bpp);
	ft_printf("Endian: %i\n", image->endian);
	ft_printf("Line length: %i\n", image->line_length);
}
