/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 01:12:41 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/05 01:46:57 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_image_struct.h"

void	t_image_destroy(void *mlx, t_image *image)
{
	if (image->image)
		mlx_destroy_image(mlx, image->image);
	free(image);
}
