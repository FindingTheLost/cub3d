/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_render_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:44:56 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/26 17:49:07 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_render_struct.h"

t_render	*t_render_build(void)
{
	t_render	*render;

	render = malloc(sizeof(t_render));
	if (!render)
		return (t_render_malloc_error(), NULL);
	render->camera.x = 0;
	render->camera.y = 0;
	render->ray.x = 0;
	render->ray.y = 0;
	render->wall = W_NULL;
	render->distance = 0;
	render->wall_x = 0;
	render->tex_x = 0;
	render->current_tex = NULL;
	return (render);
}
