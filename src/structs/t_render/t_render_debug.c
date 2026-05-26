/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_render_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:49:27 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/26 19:14:09 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_render_struct.h"

static void	debug_wall_type(t_render *render)
{
	if (render->wall == W_NULL)
		ft_printf("Wall type: W_NULL\n");
	else if (render->wall == W_NOSO)
		ft_printf("Wall type: W_NOSO\n");
	else if (render->wall == W_WEEA)
		ft_printf("Wall type: W_WEEA\n");
	else if (render->wall == W_NO)
		ft_printf("Wall type: W_NO\n");
	else if (render->wall == W_SO)
		ft_printf("Wall type: W_SO\n");
	else if (render->wall == W_WE)
		ft_printf("Wall type: W_WE\n");
	else if (render->wall == W_EA)
		ft_printf("Wall type: W_EA\n");
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
