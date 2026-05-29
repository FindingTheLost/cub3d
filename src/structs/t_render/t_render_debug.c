/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_render_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:49:27 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/28 21:08:42 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_render_struct.h"

static void	debug_wall_type(t_render *render)
{
	if (render->wall == W_NULL)
		ft_printf("Wall type: W_NULL\n");
	else if (render->wall == W_H)
		ft_printf("Wall type: W_H\n");
	else if (render->wall == W_V)
		ft_printf("Wall type: W_V\n");
	else if (render->wall == W_N)
		ft_printf("Wall type: W_N\n");
	else if (render->wall == W_S)
		ft_printf("Wall type: W_S\n");
	else if (render->wall == W_W)
		ft_printf("Wall type: W_W\n");
	else if (render->wall == W_E)
		ft_printf("Wall type: W_E\n");
	else if (render->wall == W_D)
		ft_printf("Wall type: W_D\n");
	else if (render->wall == W_DH)
		ft_printf("Wall type: W_DH\n");
	else if (render->wall == W_DV)
		ft_printf("Wall type: W_DV\n");
}

void	t_render_debug(t_render *render)
{
	ft_printf(RED_BOLD "T_RENDER STRUCT DEBUG:\n" DEF);
	printf("Camera plane X: %f\n", render->camera.x);
	printf("Camera plane Y: %f\n", render->camera.y);
	printf("Ray X: %f\n", render->ray.x);
	printf("Ray Y: %f\n", render->ray.y);
	debug_wall_type(render);
	printf("Distance: %f\n", render->distance);
	printf("Wall X: %f\n", render->wall_x);
	ft_printf("Texture X: %i\n", render->tex_x);
	t_image_debug(render->current_tex);
}
