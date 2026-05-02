/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:09:07 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 23:47:10 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

void	t_game_malloc_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Dynamic memory allocation failed for t_game struct!\n");
}

void	t_game_struct_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Struct t_game building stage failed!\n");
}

void	t_game_mlx_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Struct t_game could not initialize mlx!\n");
}

void	t_game_window_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Struct t_game could not initialize mlx window!\n");
}

void	t_game_texture_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Struct t_game could not initialize textures!\n");
}
