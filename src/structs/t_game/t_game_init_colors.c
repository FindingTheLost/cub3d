/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:55:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 23:57:09 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

void	t_game_init_colors(t_cub *file, t_game *game)
{
	size_t	index;

	index = 0;
	while (index < 3)
	{
		game->f_color[index] = file->f_color[index];
		game->c_color[index] = file->c_color[index];
		index++;
	}
}
