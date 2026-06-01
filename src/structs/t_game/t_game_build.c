/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:32:18 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 20:25:42 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

t_game	*t_game_build(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (t_game_malloc_error(), NULL);
	game->mlx = NULL;
	game->mlx_window = NULL;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->door_texture = NULL;
	game->f_color = 0;
	game->c_color = 0;
	game->player = NULL;
	game->map = NULL;
	game->image = NULL;
	game->minimap = NULL;
	game->backgrd = NULL;
	game->key = NULL;
	game->mouse = NULL;
	game->render = NULL;
	gettimeofday(&game->delta, NULL);
	gettimeofday(&game->new_delta, NULL);
	return (game);
}
