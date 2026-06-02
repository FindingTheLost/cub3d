/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:42:47 by pde-alme          #+#    #+#             */
/*   Updated: 2026/06/02 19:41:55 by pde-alme         ###   ########.fr       */
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
# include "t_mouse_struct.h"
# include "t_render_struct.h"
# include "t_anim_struct.h"

/* Defines window related macros: */
# define W_TITLE "cub3D"
# define W_WIDTH 960
# define W_HEIGHT 540

/* Defines X11/MLX event masks: */
# define NO_EVENT 0
# define KEY_PRESS 1
# define KEY_RELEASE 2
# define PTR_MOTION 64

/* Defines X11/MLX events: */
# define ON_DESTROY 17
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOTION 6

/* Defines X11/MLX key codes: */
# define K_ESC 65307
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_CTRL 65507
# define K_SHIFT 65505
# define K_SPACE 32
# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100
# define K_M 109
# define K_E 101

/* Defines the path for the door texture (relative path to cub3D): */
# define DOOR_TEX_PATH "assets/textures/debug/debug_door.xpm"

/* Defines the distance to which doors can be opened (float): */
# define DOOR_OPEN_DIST 1.2f

/* Defines the player's speed in cells per second (float): */
# define SPEED 2.0f

/* Defines the player's speed multiplier when sprinting (float): */
# define SPRINT 1.0f

/* Defines the rotation per frame (radians): */
# define ROTATION 4.0f

/* Defines a divisor of the wall slide speed. Raise to slide slower: */
# define SLIDE_DIVISOR 2

/* Defines a multiplier of the mouse rotation speed. Raise to rotate faster: */
# define MOUSE_MULTIPLIER 1

/* Defines a camera plane's side distance size: */
# define FOV 90

/* Defines a column's height ratio. Highly depends on FOV for results: */
# define FOV_COLUMN_RATIO 0.9f

/* Defines the amount of rays in the game's player view: */
# define RAY_AMOUNT 960

/* Defines the time between each animation frame. Raise to slow down: */
# define ANIMATION_SPEED 100000

/* Defines a set of minimap cell and player colors: */
# define BLACK 0
# define LIME 0x00A2CD5A
# define GREEN 0x00426F42
# define SWAMP 0x00003000
# define OLIVE 0x002F4F2F
# define YELLOW 0x00FFFF00
# define RED0 0x00FF7F00
# define RED1 0x00FF2400
# define RED2 0x00FFA500
# define RED3 0x00FF0000
# define RED4 0x00FF4500
# define RED5 0x00FF7777
# define RED6 0x00FF0000
# define RED7 0x00880000
# define BLUE0 0x000000FF
# define BLUE1 0x00000088
# define ALPHA 0xFF000000

/* Defines if fish-eye effect is enabled (can cause segfault, debug only!): */
# define FISH_EYE false

/* Defines a complete execution instance of "cub3D", storing every crucial
 * game struct inside, as well as Minilibx instance attributes:
 */
typedef struct s_game
{
	void			*mlx;
	void			*mlx_window;
	t_image			*no_texture;
	t_image			*so_texture;
	t_image			*we_texture;
	t_image			*ea_texture;
	t_image			*door_texture;
	int				f_color;
	int				c_color;
	t_player		*player;
	t_map			*map;
	t_image			*image;
	t_image			*minimap;
	t_image			*backgrd;
	t_key			*key;
	t_mouse			*mouse;
	t_render		*render;
	t_anim			*helmet;
	struct timeval	delta;
	struct timeval	new_delta;
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
void	t_game_draw_ceiling_floor(t_game *game, t_image *image);
void	t_game_draw_animation(t_game *game, t_image *frame);
void	t_game_minimap_show(t_game *game);
void	t_game_draw_minimap_map_h(t_game *game);
void	t_game_draw_minimap_map_v(t_game *game);
void	t_game_draw_minimap_player(t_game *game, int orientation);
void	t_game_minimap_to_center(t_game *game, int *x, int *y, int orientation);
void	t_game_cube_show(t_game *game);
void	t_game_cube_dda(t_game *game);
void	t_game_cube_draw(t_game *game, size_t index);
void	t_game_door_dda(t_game *game);
void	t_game_door_interact(t_game *game, int map_x, int map_y, float dist);
void	t_game_check_keys(t_game *game);
void	t_game_check_mouse(t_game *game);
void	t_game_init_colors(t_cub *file, t_game *game);
int		t_game_init_textures(t_cub *file, t_game *game);
int		t_game_init_mlx(t_game *game);
int		t_game_populate(t_cub *file, t_game **game_ref);
int		t_game_check_collisions(t_game *g, t_player *p, char *dir, float speed);
float	t_game_clamp_rotation(float rotation);
float	t_game_delta(t_game *game);

#endif
