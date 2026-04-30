/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:50:44 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 21:15:37 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

void	t_cub_malloc_error(void)
{
	write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
	write(STDOUT_FILENO, "Dynamic memory allocation failed!\n", 34);
}

void	t_cub_struct_error(void)
{
	write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
	write(STDOUT_FILENO, "Struct building stage failed!\n", 30);
}
