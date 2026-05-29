/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_render_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:27:28 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/28 20:53:32 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RENDER_STRUCT_H
# define T_RENDER_STRUCT_H

# include "../../libft/libft.h"
# include "t_image_struct.h"

/* Defines a wall orientation type enumeration.
 *  - "H"	= "A horizontal line was touched (y interception)";
 *  - "V"	= "A vertical line was touched (x interception)";
 *  - "N"	= "North";
 *  - "S"	= "South";
 *  - "W"	= "West";
 *  - "E"	= "East";
 *  - "D"	= "Door";
 *  - "DH"	= "Door at y interception";
 *  - "DV"	= "Door at x interception";
 */
typedef enum e_wall
{
	W_NULL = 0,
	W_H,
	W_V,
	W_N,
	W_S,
	W_W,
	W_E,
	W_D,
	W_DH,
	W_DV
}	t_wall;

/* Defines a 2D vector direction or two distinct numbers related to 'x' or 'y'.
 */
typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

/* Defines a set of variables to be used while rendering one frame. */
typedef struct s_render
{
	t_vector	camera;
	t_vector	ray;
	t_wall		wall;
	float		distance;
	float		wall_x;
	int			tex_x;
	t_image		*current_tex;
}	t_render;

t_render	*t_render_build(void);
void		t_render_debug(t_render *render);
void		t_render_destroy(t_render *render);
void		t_render_malloc_error(void);
void		t_render_struct_error(void);
int			t_render_populate(t_render **render_ref);

#endif
