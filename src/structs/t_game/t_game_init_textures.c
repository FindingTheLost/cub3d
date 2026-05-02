/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:29:58 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 02:05:32 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	destroy_image(t_game *game, int code)
{
	if (code > 0)
	{
		mlx_destroy_image(game->mlx, game->no_texture);
		game->no_texture = NULL;
	}
	if (code > 1)
	{
		mlx_destroy_image(game->mlx, game->we_texture);
		game->we_texture = NULL;
	}
	if (code > 2)
	{
		mlx_destroy_image(game->mlx, game->ea_texture);
		game->ea_texture = NULL;
	}
	t_game_texture_error();
}

int	t_game_init_textures(t_cub *file, t_game *game)
{
	int	s;

	s = TEX_SIZE;
	game->no_texture = mlx_xpm_file_to_image(game->mlx, file->no_file, &s, &s);
	if (!game->no_texture)
		return (destroy_image(game, 0), false);
	game->so_texture = mlx_xpm_file_to_image(game->mlx, file->so_file, &s, &s);
	if (!game->so_texture)
		return (destroy_image(game, 1), false);
	game->we_texture = mlx_xpm_file_to_image(game->mlx, file->we_file, &s, &s);
	if (!game->we_texture)
		return (destroy_image(game, 2), false);
	game->ea_texture = mlx_xpm_file_to_image(game->mlx, file->ea_file, &s, &s);
	if (!game->ea_texture)
		return (destroy_image(game, 3), false);
	return (true);
}
