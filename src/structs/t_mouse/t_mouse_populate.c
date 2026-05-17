/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mouse_populate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:55:35 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/17 20:03:24 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_mouse_struct.h"

int	t_mouse_populate(t_mouse **mouse_ref)
{
	*mouse_ref = t_mouse_build();
	if (!*mouse_ref)
		return (false);
	return (true);
}
