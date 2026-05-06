/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:42:47 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 01:45:40 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_STRUCT_H
# define T_GAME_STRUCT_H

# include "../../libft/libft.h"
# include "t_cub_struct.h"
# include "t_player_struct.h"
# include "t_map_struct.h"
# include "t_image_struct.h"

/* Window related macros: */
# define W_TITLE "cub3D"
# define W_WIDTH 960
# define W_HEIGHT 540

/* Texture size: */
# define TEX_SIZE 64

/* X11/MLX event masks: */
# define NO_EVENT 0
# define KEY_PRESS 1
# define KEY_RELEASE 2

/* X11/MLX events: */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17

/* X11/MLX key codes: */
# define ESC_KEY 65307
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100

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
	int				f_color;
	int				c_color;
	t_player		*player;
	t_map			*map;
	t_image			*image;
}	t_game;

t_game	*t_game_build(void);
void	t_game_destroy(t_game *game);
void	t_game_malloc_error(void);
void	t_game_struct_error(void);
void	t_game_mlx_error(void);
void	t_game_texture_error(void);
void	t_game_window_error(void);
void	t_game_debug(t_game *game);
void	t_game_draw_pixel(t_image *image, int x, int y, int color);
void	t_game_draw_background(t_game *game);
void	t_game_draw_minimap(t_game *game);
void	t_game_init_colors(t_cub *file, t_game *game);
int		t_game_init_textures(t_cub *file, t_game *game);
int		t_game_init_mlx(t_game *game);
int		t_game_populate(t_cub *file, t_game **game_ref);

#endif
