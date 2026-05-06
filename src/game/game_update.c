/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:12:16 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 01:53:49 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_update(t_game *game)
{
	t_game_draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->image->image, 0, 0);
	return (0);
}
