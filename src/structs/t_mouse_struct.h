/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mouse_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:48:22 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/17 20:05:20 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MOUSE_STRUCT_H
# define T_MOUSE_STRUCT_H

# include "../../libft/libft.h"

/* Defines a set of mouse actions that can be recorded in a given frame.
 */
typedef struct s_mouse
{
	int	x;
	int	y;
	int	x_dir;
	int	y_dir;
}	t_mouse;

t_mouse	*t_mouse_build(void);
void	t_mouse_debug(t_mouse *mouse);
void	t_mouse_destroy(t_mouse *mouse);
void	t_mouse_malloc_error(void);
void	t_mouse_struct_error(void);
int		t_mouse_populate(t_mouse **mouse_ref);

#endif
