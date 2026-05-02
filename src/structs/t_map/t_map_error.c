/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:11:13 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 22:17:59 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_map_struct.h"

void	t_map_malloc_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Dynamic memory allocation failed for t_map struct!\n");
}

void	t_map_struct_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Struct t_map building stage failed!\n");
}
