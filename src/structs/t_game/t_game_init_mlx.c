/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:08:05 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 02:12:55 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

int	t_game_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (t_game_mlx_error(), false);
	game->mlx_window = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	if (!game->mlx_window)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
		return (t_game_window_error(), false);
	}
	return (true);
}
