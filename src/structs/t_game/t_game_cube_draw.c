/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_cube_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:04:37 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/27 00:26:03 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_game_struct.h"

/* This function calculates "tex_y" based on the current index multiplied by the
 * texture's height divided by the column's total pixels. It then accesses the
 * texture's buffer address based on it for vertical pixel coordenates and
 * "tex_x" for horizontal coordenates.
 *
 * It then converts the found pixel's first byte (the alpha) and converts its
 * char memory address to an integer pointer and dereferences it to output the
 * proper integer pixel color number.
 *
 * Can break if the image's "bpp" is different than 32 bits (int).
 */
static int	xpm_to_pixel(t_game *game, size_t index, int col_total)
{
	t_image	*texture;
	int		tex_x;
	int		tex_y;
	int		*color;

	texture = game->render->current_tex;
	tex_x = game->render->tex_x;
	tex_y = roundf(index * ((float)texture->height / col_total));
	if (tex_y > 0 && tex_y == texture->height)
		tex_y--;
	color = (int *)&texture->address[tex_y * texture->line_length + tex_x
		* (texture->bpp / 8)];
	return (*color);
}

/* For each column, the function will attempt to draw the column, pixel by
 * pixel and from top to bottom after it calls "xpm_to_pixel()" function
 * to retrieve the color to be drawn.
 *
 * If a player is standing close to a wall, where a column is larger than the
 * screen's height ("W_HEIGHT"), during the cycle (and since these pixels were
 * to be drawn outside of the "image" window), these larger points outside of
 * the window are not processed and thus ignored. If not, it will produce a
 * segmentation fault due to the program trying to access inexistant indexes
 * of the window image.
 *
 * If within the condition and a color is obtained, the function will then
 * draw a pixel of the respective retrieved color on the game's "image" screen.
 */
static void	draw_column(t_game *game, int col_height, size_t col_i)
{
	size_t	index;
	int		col_half;
	int		col_top;
	int		col_bot;
	int		color;

	col_half = col_height / 2;
	col_top = W_HEIGHT / 2 - col_half;
	col_bot = W_HEIGHT / 2 + col_half;
	index = 0;
	while (col_top < col_bot)
	{
		if (col_top >= 0 && col_top < W_HEIGHT)
		{
			color = xpm_to_pixel(game, index, col_half * 2);
			t_game_draw_pixel(game->image, col_i, col_top, color);
		}
		index++;
		col_top++;
	}
}

/* Determines the horizontal ratio where the ray hits the wall in the first
 * condition.
 *
 * In the second condition, determines the horizontal ratio of a texture using
 * the wall hit ratio to draw a column of said texture.
 *
 * To not have textures appear flipped if the wall is "W_SO" or "W_WE", reduce
 * the ratio of the texture by the texture's width. Example:
 *
 * If "W_NO" or "W_EA" and texture size is 64, 25% of 64 == 16, therefore, the
 * ray will attempt to draw at column 16.
 *
 * If "W_SO" or "W_WE" and texture size is 64, 25% of 64 == 16 but due to the
 * direction of the ray it should be 48. Therefore, abs(16 - 64) = 48 and it
 * will draw at column 48.
 */
static void	set_wall_tex_x(t_game *game)
{
	t_player	*player;
	t_render	*render;
	t_image		*texture;

	player = game->player;
	render = game->render;
	texture = render->current_tex;
	if (render->wall == W_WE || render->wall == W_EA)
		render->wall_x = player->y + (render->distance * render->ray.y);
	else
		render->wall_x = player->x + (render->distance * render->ray.x);
	render->wall_x -= (int)render->wall_x;
	if (game->render->wall == W_NO || game->render->wall == W_EA)
		render->tex_x = render->wall_x * render->current_tex->width;
	else
		render->tex_x = fabs(render->wall_x * texture->width - texture->width);
	if (render->tex_x > 0)
		render->tex_x--;
}

/* Determines which wall texture will be used to draw the current ray cast.
 */
static void	set_current_tex(t_game *game)
{
	t_render	*render;

	render = game->render;
	if (render->wall == W_NO)
		render->current_tex = game->no_texture;
	else if (render->wall == W_SO)
		render->current_tex = game->so_texture;
	else if (render->wall == W_WE)
		render->current_tex = game->we_texture;
	else
		render->current_tex = game->ea_texture;
}

/* Function that draws pixel columns in the "image" variable of "game" based on
 * the distance the current ray has and based on the wall the ray has hit.
 *
 * The 0.9 is an arbitrary value ratio to make cubes look square instead of
 * vertical rectangle blocks. A perspective correction value that must be
 * changed if one wishes to change FOV.
 *
 * If "RAY_AMOUNT" is inferior and divisor of "W_WIDTH", each ray will have many
 * repeated columns to mimick old games raycasting viewports, such as
 * "Wolfenstein".
 */
void	t_game_cube_draw(t_game *game, size_t index)
{
	int		col_width;
	int		col_height;
	size_t	col_i;

	col_width = W_WIDTH / RAY_AMOUNT;
	col_height = W_HEIGHT * 0.9f / game->render->distance;
	col_i = col_width * index;
	set_current_tex(game);
	set_wall_tex_x(game);
	while (col_i < col_width * (index + 1))
	{
		draw_column(game, col_height, col_i);
		col_i++;
	}
}
