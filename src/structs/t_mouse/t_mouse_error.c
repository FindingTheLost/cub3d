/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mouse_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:55:28 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/17 20:01:02 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_mouse_struct.h"

void	t_mouse_malloc_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Dynamic memory allocation failed for t_mouse struct!\n");
}

void	t_mouse_struct_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Struct t_mouse building stage failed!\n");
}
