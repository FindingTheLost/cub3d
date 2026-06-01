/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:01:10 by rogde-so          #+#    #+#             */
/*   Updated: 2026/05/27 13:01:10 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ANIM_STRUCT_H
#define T_ANIM_STRUCT_H

# include "../../libft/libft.h"
# include "t_image_struct.h"

# define PATH "assets/animation/"
# define ANIM_FILE "Helmet_anim"

typedef struct s_anim
{
	int		mask_on;
	int		frame_count;
	int		current_frame;
	int		is_playing;
	int		direction;
	long	last_frame_time;
	t_image	**frames;
}	t_anim;

t_anim	*t_anim_build(void);
void	t_anim_destroy(void *mlx, t_anim *anim);
void	t_anim_debug(t_anim *anim);
void	t_anim_malloc_error(void);
void	t_anim_image_error(void);
void	t_anim_directory_error(void);
void	t_anim_path_error(void);
int		t_anim_populate(t_anim **anim_ref, int width, int height, void *mlx);
int		t_anim_resolution_directory(int *path_dir, int width, int height);
int		t_anim_init_texture(t_anim **anim, int width, int height, void *mlx);

#endif
