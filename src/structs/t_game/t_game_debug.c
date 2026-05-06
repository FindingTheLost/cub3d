/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:09:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/05 22:40:31 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	debug_textures(t_game *game)
{
	if (game->no_texture)
		ft_printf("North texture: present.\n");
	else
		ft_printf("North texture: not present.\n");
	if (game->so_texture)
		ft_printf("South texture: present.\n");
	else
		ft_printf("South texture: not present.\n");
	if (game->we_texture)
		ft_printf("West texture: present.\n");
	else
		ft_printf("West texture: not present.\n");
	if (game->ea_texture)
		ft_printf("East texture: present.\n");
	else
		ft_printf("East texture: not present.\n");
}

void	t_game_debug(t_game *game)
{
	ft_printf(RED_BOLD "T_GAME STRUCT DEBUG:\n" DEF);
	if (game->mlx)
		ft_printf("MLX: present.\n");
	else
		ft_printf("MLX: not present.\n");
	if (game->mlx_window)
		ft_printf("MLX window: present.\n");
	else
		ft_printf("MLX window: not present.\n");
	debug_textures(game);
	ft_printf("Floor color: %i\n", game->f_color);
	ft_printf("Ceiling color: %i\n", game->c_color);
	t_player_debug(game->player);
	t_map_debug(game->map);
	t_image_debug(game->image);
}
