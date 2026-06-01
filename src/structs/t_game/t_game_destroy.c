/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:38:26 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 02:59:44 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	destroy_inner_structs(t_game *game)
{
	if (game->player)
		t_player_destroy(game->player);
	if (game->map)
		t_map_destroy(game->map);
	if (game->image)
		t_image_destroy(game->mlx, game->image);
	if (game->minimap)
		t_image_destroy(game->mlx, game->minimap);
	if (game->backgrd)
		t_image_destroy(game->mlx, game->backgrd);
	if (game->key)
		t_key_destroy(game->key);
	if (game->mouse)
		t_mouse_destroy(game->mouse);
	if (game->render)
		t_render_destroy(game->render);
	if (game->helmet_anim)
		t_anim_destroy(game->mlx, game->helmet_anim);
}

void	t_game_destroy(t_game *game)
{
	destroy_inner_structs(game);
	if (game->no_texture)
		t_image_destroy(game->mlx, game->no_texture);
	if (game->so_texture)
		t_image_destroy(game->mlx, game->so_texture);
	if (game->we_texture)
		t_image_destroy(game->mlx, game->we_texture);
	if (game->ea_texture)
		t_image_destroy(game->mlx, game->ea_texture);
	if (game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
	if (game->mlx)
		(mlx_destroy_display(game->mlx), free(game->mlx));
	free(game);
}
