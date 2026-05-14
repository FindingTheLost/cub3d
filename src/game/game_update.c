/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:17:18 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/14 02:25:39 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_update(t_game *game)
{
	gettimeofday(&game->new_delta, NULL);
	t_game_check_keys(game);
	t_game_check_mouse(game);
	game->delta = game->new_delta;
	if (game->key->m)
		t_game_minimap_show(game);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->minimap_background->image, 0, 0);
	return (0);
}
