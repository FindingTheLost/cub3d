/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:42:47 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 02:03:06 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_STRUCT_H
# define T_GAME_STRUCT_H

# include "../../libft/libft.h"
# include "../../minilibx-linux/mlx.h"
# include "../../minilibx-linux/mlx_int.h"
# include "t_cub_struct.h"

// Window related macros
# define W_TITLE "cub3D"
# define W_WIDTH 1600
# define W_HEIGHT 900

// Texture size macro
# define TEX_SIZE 64

/* Struct that stores everything minilibx related.
 */
typedef struct s_game
{
	void			*mlx;
	void			*mlx_window;
	void			*no_texture;
	void			*so_texture;
	void			*we_texture;
	void			*ea_texture;
	unsigned char	f_color[3];
	unsigned char	c_color[3];
}	t_game;

t_game	*t_game_build(void);
void	t_game_destroy(t_game *game);
void	t_game_malloc_error(void);
void	t_game_struct_error(void);
void	t_game_mlx_error(void);
void	t_game_texture_error(void);
void	t_game_window_error(void);
void	t_game_init_colors(t_cub *file, t_game *game);
int		t_game_init_textures(t_cub *file, t_game *game);
int		t_game_init_mlx(t_game *game);
int		t_game_populate(t_cub *file, t_game **game_ref);

#endif
