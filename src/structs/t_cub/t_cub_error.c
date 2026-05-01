/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:50:44 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 01:35:35 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

void	t_cub_malloc_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Dynamic memory allocation failed!\n");
}

void	t_cub_struct_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Struct building stage failed!\n");
}
