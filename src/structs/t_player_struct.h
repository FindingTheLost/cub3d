/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:57:35 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/11 17:19:40 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_STRUCT_H
# define T_PLAYER_STRUCT_H

# include "../../libft/libft.h"
# include "t_cub_struct.h"

/* Defines a player's current position and rotation.
 */
typedef struct s_player
{
	float	x;
	float	y;
	float	r;
}	t_player;

t_player	*t_player_build(void);
void		t_player_destroy(t_player *player);
void		t_player_malloc_error(void);
void		t_player_struct_error(void);
void		t_player_debug(t_player *player);
int			t_player_populate(t_cub *file, t_player **player_ref);

#endif
