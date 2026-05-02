/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:32:18 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 00:44:05 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

t_game	*t_game_build(void)
{
	t_game	*game;
	size_t	index;

	game = malloc(sizeof(t_game));
	if (!game)
		return (t_game_malloc_error(), NULL);
	game->mlx = NULL;
	game->mlx_window = NULL;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	index = 0;
	while (index < 3)
	{
		game->f_color[index] = 0;
		game->c_color[index] = 0;
		index++;
	}
	return (game);
}
