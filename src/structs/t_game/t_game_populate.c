/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_populate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:26:54 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/21 20:46:26 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

int	t_game_populate(t_cub *file, t_game **game_ref)
{
	t_game	*game;

	*game_ref = t_game_build();
	if (!*game_ref)
		return (false);
	game = *game_ref;
	if (!t_game_init_mlx(game))
		return (t_game_destroy(game), false);
	if (!t_game_init_textures(file, game))
		return (t_game_destroy(game), false);
	t_game_init_colors(file, game);
	gettimeofday(&game->delta, NULL);
	gettimeofday(&game->new_delta, NULL);
	game->camera_plane.x = 0;
	game->camera_plane.y = 0;
	return (true);
}
