/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 23:46:52 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/26 00:22:43 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static void	show_help_map(void)
{
	ft_printf(YEL_LINE YEL_BOLD "Map content:\n" DEF);
	ft_printf(" - A character " RED_BOLD "1" DEF " represents a wall;\n");
	ft_printf(" - A character " RED_BOLD "0" DEF " represents a traversable");
	ft_printf(" floor surface;\n");
	ft_printf(" - The characters " RED_BOLD "N" DEF "," RED_BOLD " S" DEF);
	ft_printf(", " RED_BOLD "W" DEF ", " RED_BOLD "E" DEF " represent ");
	ft_printf("a player and its orientation when initializing the map.\n");
	ft_printf(" - A map can have any shape and size, as long as it is ");
	ft_printf("properly surrounded by walls.\n");
	ft_printf(" - A map cannot possess an empty line mid map, however, ");
	ft_printf(RED_BOLD "spaces" DEF " are allowed.\n\n");
}

static void	show_help_elements(void)
{
	ft_printf(YEL_LINE YEL_BOLD "Wall orientation textures:\n" DEF);
	ft_printf(" - A " YEL_BOLD "NO" DEF " element, followed by a " RED_BOLD);
	ft_printf(".xpm" DEF " texture file;\n");
	ft_printf(" - A " YEL_BOLD "SO" DEF " element, followed by a " RED_BOLD);
	ft_printf(".xpm" DEF " texture file;\n");
	ft_printf(" - A " YEL_BOLD "WE" DEF " element, followed by a " RED_BOLD);
	ft_printf(".xpm" DEF " texture file;\n");
	ft_printf(" - A " YEL_BOLD "EA" DEF " element, followed by a " RED_BOLD);
	ft_printf(".xpm" DEF " texture file.\n\n");
	ft_printf(YEL_LINE YEL_BOLD "Ceiling and floor colors:\n" DEF);
	ft_printf(" - A " YEL_BOLD "C" DEF " element, followed by " RED_BOLD "3");
	ft_printf(DEF " comma separated values ranging from " RED_BOLD "0" DEF);
	ft_printf(DEF " - " RED_BOLD "255" DEF ";\n");
	ft_printf(" - A " YEL_BOLD "F" DEF " element, followed by " RED_BOLD "3");
	ft_printf(DEF " comma separated values ranging from " RED_BOLD "0" DEF);
	ft_printf(DEF " - " RED_BOLD "255" DEF ".\n\n");
}

static void	show_help_usage(void)
{
	ft_printf(YEL_BOLD "cub3D" DEF " is an introductory raycasting project. ");
	ft_printf("To launch it, input a " RED_BOLD ".cub" DEF " file as launch ");
	ft_printf("parameter:\n");
	ft_printf(YEL_BOLD "./cub3D [map_name].cub\n\n" DEF);
	ft_printf("A " RED_BOLD ".cub" DEF " file can be composed of the ");
	ft_printf("following elements in " RED_BOLD "any" DEF " given order:\n\n");
}

static void	show_help_header(void)
{
	ft_printf("\n");
	ft_printf(YEL " = = = " YEL_LIGH "=" YEL_BOLD " = = = = = = = = = = " DEF);
	ft_printf(YEL_LIGH "=" YEL " = = = \n" DEF);
	ft_printf(YEL_SLOW "!!!!!" DEF);
	ft_printf(YEL " =" YEL_LIGH "=" YEL_BOLD "=" DEF);
	ft_printf(YEL_BOLD " cub3D HELP SCREEN " DEF);
	ft_printf(YEL_BOLD "=" DEF YEL_LIGH "=" YEL "= " DEF);
	ft_printf(YEL_SLOW "!!!!!\n" DEF);
	ft_printf(YEL " = = = " YEL_LIGH "=" YEL_BOLD " = = = = = = = = = = " DEF);
	ft_printf(YEL_LIGH "=" YEL " = = = \n" DEF);
}

int	parse_input_help(char **argv)
{
	if (ft_strbcmp(argv[1], "-h") || ft_strbcmp(argv[1], "--help"))
	{
		show_help_header();
		show_help_usage();
		show_help_elements();
		show_help_map();
		ft_printf("This " CYA_SLOW CYA_BOLD "42" DEF " school project was ");
		ft_printf("created by " YEL_BOLD "pde-alme" DEF " and " YEL_BOLD);
		ft_printf("rogde-so" DEF ".\n");
		ft_printf(CYA_SLOW CYA_BOLD "42" DEF " Lisboa 2026, all rights ");
		ft_printf("reserved.\n\n");
		return (false);
	}
	return (true);
}
