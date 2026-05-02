/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_populate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:26:54 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 23:57:19 by pde-alme         ###   ########.fr       */
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
	return (true);
}
