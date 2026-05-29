/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:29:58 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/28 21:28:20 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

static void	set_image(t_game *game, t_image *image, size_t index)
{
	if (index == 0)
		game->no_texture = image;
	else if (index == 1)
		game->so_texture = image;
	else if (index == 2)
		game->we_texture = image;
	else if (index == 3)
		game->ea_texture = image;
	else
		game->door_texture = image;
}

/* Variable names changed to accomodate Norminette:
 * 	"s" = "sizes";
 */
static void	*get_texture(t_cub *file, t_game *game, size_t index, int s[2])
{
	void	*texture;

	if (index == 0)
		texture = mlx_xpm_file_to_image(game->mlx, file->no_file, &s[0], &s[1]);
	else if (index == 1)
		texture = mlx_xpm_file_to_image(game->mlx, file->so_file, &s[0], &s[1]);
	else if (index == 2)
		texture = mlx_xpm_file_to_image(game->mlx, file->we_file, &s[0], &s[1]);
	else if (index == 3)
		texture = mlx_xpm_file_to_image(game->mlx, file->ea_file, &s[0], &s[1]);
	else
		texture = mlx_xpm_file_to_image(game->mlx, DOOR_TEX_PATH, &s[0], &s[1]);
	return (texture);
}

/* This function, not only opens a new image with the "mlx_xpm_file_to_image()"
 * minilibx function, but also prepares a "t_image" pointer with all of its
 * image information inside (it differs from the other "t_image"s in the game
 * because it goes through a different process, therefore, no "t_image" function
 * is used here.
 * 
 * Once all data regarding the images are set, save it in the respective
 * locations in the game struct and return "true". If anything wrong happens,
 * return "false".
 */
int	t_game_init_textures(t_cub *file, t_game *game)
{
	size_t	index;
	int		sizes[2];
	void	*texture;
	t_image	*image;

	index = 0;
	sizes[0] = 0;
	sizes[1] = 0;
	while (index < 5)
	{
		texture = get_texture(file, game, index, sizes);
		if (!texture)
			return (t_game_texture_error(), false);
		image = t_image_texture_to_image(texture, sizes[0], sizes[1]);
		if (!image)
		{
			mlx_destroy_image(game->mlx, texture);
			return (t_game_texture_error(), false);
		}
		set_image(game, image, index);
		index++;
	}
	return (true);
}
