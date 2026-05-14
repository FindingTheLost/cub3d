/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:42:47 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/14 17:45:14 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_STRUCT_H
# define T_GAME_STRUCT_H

# include <sys/time.h>
# include "../../libft/libft.h"
# include "t_cub_struct.h"
# include "t_player_struct.h"
# include "t_map_struct.h"
# include "t_image_struct.h"
# include "t_key_struct.h"

/* Redefinition for misidentification of libmath */
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/* Window related macros: */
# define W_TITLE "cub3D"
# define W_WIDTH 1280
# define W_HEIGHT 720

/* Texture size: */
# define TEX_SIZE 64

/* X11/MLX event masks: */
# define NO_EVENT 0
# define KEY_PRESS 1
# define KEY_RELEASE 2
# define MOUSE_MOTION 64

/* X11/MLX events: */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17
# define MOUSE_MOVE 6

/* X11/MLX key codes: */
# define K_ESC 65307
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_SPACE 32
# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100
# define K_M 109

/* Player speed (float in cells per second) and rotation (in radians) per frame:
 *     (in case of a slow computer, increase these values) */
# define SPEED 2.0f
# define ROTATION 4.0f

/* Divisor of the wall slide speed. Increase to slide slower: */
# define SLIDE_DIVISOR 2

/* Multiplier of the mouse rotation speed. Increase to rotate faster: */
# define MOUSE_MULTIPLIER 16

/* Definition of minimap cell colors: */
# define BLACK 0
# define LIME 0x00A2CD5A
# define GREEN 0x00426F42
# define SWAMP 0x00548B54
# define OLIVE 0x002F4F2F

/* Definition of minimap player colors: */
# define YELLOW 0x00FFFF00
# define RED1 0x00FF7F00
# define RED2 0x00FF2400
# define RED3 0x00FFA500
# define RED4 0x00FF0000
# define RED5 0x00FF4500

/* Defines a complete execution instance of "cub3D", storing every crucial
 * game struct inside, as well as Minilibx instance attributes.
 */
typedef struct s_game
{
	struct timeval	delta;
	struct timeval	new_delta;
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
	t_image			*minimap;
	t_image			*minimap_background;
	t_key			*key;
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
void	t_game_draw_background(t_image *image, size_t w, size_t h, int color);
void	t_game_draw_ceiling_floor(t_game *game);
void	t_game_draw_minimap_h(t_game *game);
void	t_game_draw_minimap_v(t_game *game);
void	t_game_draw_minimap_player(t_game *game, int orientation);
void	t_game_minimap_to_window_h(t_game *game, int *x, int *y);
void	t_game_minimap_to_window_v(t_game *game, int *x, int *y);
void	t_game_minimap_show(t_game *game);
void	t_game_init_colors(t_cub *file, t_game *game);
void	t_game_check_keys(t_game *game);
void	t_game_check_mouse(t_game *game);
void	t_game_move_player(t_player *player, char key);
int		t_game_init_textures(t_cub *file, t_game *game);
int		t_game_init_mlx(t_game *game);
int		t_game_populate(t_cub *file, t_game **game_ref);
int		t_game_check_collisions(t_game *g, t_player *p, char *direction);
float	t_game_delta(t_game *game);

#endif
