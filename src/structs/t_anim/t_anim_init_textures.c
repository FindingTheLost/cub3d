/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_anim_init_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 20:22:32 by rogde-so          #+#    #+#             */
/*   Updated: 2026/06/01 23:16:52 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_anim_struct.h"

static int	check_texture(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(RED_LIGH "Error\n" DEF);
		ft_printf("\"%s\"\n", argv);
		ft_printf("File does not exist or permission denied!\n");
		return (false);
	}
	close(fd);
	return (true);
}

/* This function adds to the path of the animation frame. So far we already have
*  the full path name except the file name, which this function takes care of.
*  It first does itoa because frames go above the single digit value. It then
*  joins this new string to the ANIM_FILE macro "Helmet_anim", thus becoming
*  the correct animation frame number (1 to 14). After we add the .xpm extension
*  and lo and behold, the full path is formed, validated by check_texture above
*  before being transform from mlx_to_image bellow.
*/
static char	*get_frame_path(char *path, int frame)
{
	char	*frame_number;
	char	*file_name;
	char	*file_name_extension;
	char	*frame_path;

	frame_number = ft_itoa(frame);
	if (!frame_number)
		return (NULL);
	file_name = ft_strjoin(ANIM_FILE, frame_number);
	if (!file_name)
		return (free(frame_number), t_anim_path_error(), NULL);
	free(frame_number);
	file_name_extension = ft_strjoin(file_name, ".xpm");
	if (!file_name_extension)
		return (free(file_name), t_anim_path_error(), NULL);
	free(file_name);
	frame_path = ft_strjoin(path, file_name_extension);
	if (!frame_path)
		return (free(file_name_extension), t_anim_path_error(), NULL);
	free(file_name_extension);
	return (frame_path);
}

static int	set_image(t_image **frame, char *path, void *mlx)
{
	int		width;
	int		height;
	void	*texture;

	texture = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!texture)
		return (false);
	*frame = t_image_texture_to_image(texture, width, height);
	if (!*frame)
		return (mlx_destroy_image(mlx, texture), false);
	return (true);
}

/* This function first joins the PATH macro "../../assets/animation/" with the
*  previously validated resolution directory. It then creates the second part of
*  the frame path based on the index i. It then transforms the found mlx file
*  into a usable minilibx image. It loops through all the frames doing the same.
*/
static int	validate_frames(void *mlx, t_anim *anim, int path_dir)
{
	int		i;
	char	dir[3];
	char	*path;
	char	*frame_path;

	i = 0;
	dir[0] = (path_dir + '0');
	dir[1] = '/';
	dir[2] = '\0';
	path = ft_strjoin(PATH, dir);
	if (!path)
		return (t_anim_path_error(), false);
	while (i < anim->frame_count)
	{
		frame_path = get_frame_path(path, (i + 1));
		if (!frame_path)
			return (free(path), false);
		if (!check_texture(frame_path))
			return (free(path), free(frame_path), false);
		if (!set_image(&anim->frames[i], frame_path, mlx))
			return (free(path), free(frame_path), false);
		free(frame_path);
		i++;
	}
	return (free(path), true);
}

int	t_anim_init_textures(void *mlx, int width, int height, t_anim *anim)
{
	int	path_dir;

	path_dir = -1;
	if (!t_anim_init_resolution(&path_dir, width, height))
		return (false);
	if (!validate_frames(mlx, anim, path_dir))
		return (false);
	return (true);
}
