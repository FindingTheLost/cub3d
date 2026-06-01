/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:13:19 by rogde-so          #+#    #+#             */
/*   Updated: 2026/06/01 22:49:39 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_anim_struct.h"

void	t_anim_malloc_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Dynamic memory allocation failed for t_anim struct!\n");
}

void	t_anim_struct_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Struct t_anim building stage failed!\n");
}

void	t_anim_image_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Image creation failed for t_anim struct!\n");
}

void	t_anim_directory_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Directory does not exist for t_anim struct!\n");
}

void	t_anim_path_error(void)
{
	ft_printf(RED_LIGH "Error\n" DEF);
	ft_printf("Path allocation failed for t_anim struct!\n");
}
