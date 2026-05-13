/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:17:18 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/13 18:53:36 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_update(t_game *game)
{
	t_game_check_keys(game);
	if (game->key->m)
		t_game_minimap_show(game);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->minimap_background->image, 0, 0);
	return (0);
}
