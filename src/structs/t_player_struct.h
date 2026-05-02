/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:57:35 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/02 00:52:58 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_STRUCT_H
# define T_PLAYER_STRUCT_H

# include "../../libft/libft.h"
# include "t_cub_struct.h"

typedef struct s_player
{
	float	x_pos;
	float	y_pos;
	float	rotation;
}	t_player;

t_player	*t_player_build(void);
void		t_player_destroy(t_player *player);
void		t_player_malloc_error(void);
void		t_player_struct_error(void);
int			t_player_populate(t_cub *file, t_player **player_ref);

#endif
