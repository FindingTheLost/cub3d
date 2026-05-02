/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:51:23 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 00:38:13 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_player_struct.h"

void	t_player_malloc_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Dynamic memory allocation failed for t_player struct!\n");
}

void	t_player_struct_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Struct t_player building stage failed!\n");
}
