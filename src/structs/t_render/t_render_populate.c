/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_render_populate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:01:15 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/26 18:04:46 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_render_struct.h"

int	t_render_populate(t_render **render_ref)
{
	*render_ref = t_render_build();
	if (!*render_ref)
		return (false);
	return (true);
}
