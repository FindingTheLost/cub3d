/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mouse_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:54:55 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/17 19:58:01 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_mouse_struct.h"

t_mouse	*t_mouse_build(void)
{
	t_mouse	*mouse;

	mouse = malloc(sizeof(t_mouse));
	if (!mouse)
		return (t_mouse_malloc_error(), NULL);
	mouse->x = -1;
	mouse->y = -1;
	mouse->x_dir = 0;
	mouse->y_dir = 0;
	return (mouse);
}
