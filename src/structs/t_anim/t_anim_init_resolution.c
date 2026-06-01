/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_init_resolution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:42:04 by rogde-so          #+#    #+#             */
/*   Updated: 2026/06/01 22:59:39 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_anim_struct.h"

/* Finds which directory is to be used for the animation frames depending on
 * the resolution. Each directory is named 0 to 8 in lowest to highest
 * resolution order and to achieve simplicity since joining a single itoa digit
 * to a full path is straightforward.
 */
int	t_anim_init_resolution(int *path_dir, int width, int height)
{
	if (width == 640 && height == 360)
		return (*path_dir = 0, true);
	else if (width == 960 && height == 540)
		return (*path_dir = 1, true);
	else if (width == 1280 && height == 720)
		return (*path_dir = 2, true);
	else if (width == 1366 && height == 768)
		return (*path_dir = 3, true);
	else if (width == 1600 && height == 900)
		return (*path_dir = 4, true);
	else if (width == 1920 && height == 1080)
		return (*path_dir = 5, true);
	else if (width == 2560 && height == 1440)
		return (*path_dir = 6, true);
	else if (width == 3840 && height == 2160)
		return (*path_dir = 7, true);
	else if (width == 7680 && height == 4320)
		return (*path_dir = 8, true);
	return (t_anim_directory_error(), false);
}
