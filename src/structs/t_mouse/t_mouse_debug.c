/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mouse_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:55:11 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/18 22:07:03 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_mouse_struct.h"

void	t_mouse_debug(t_mouse *mouse)
{
	ft_printf(RED_BOLD "T_MOUSE STRUCT DEBUG:\n" DEF);
	ft_printf("Key MOUSE_X: %i\n", mouse->x);
	ft_printf("Key MOUSE_Y: %i\n", mouse->x);
}
