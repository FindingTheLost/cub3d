/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_file_extension.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:09:27 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 01:07:36 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	parse_input_file_extension(char **argv)
{
	char	*file_extension;

	file_extension = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
	if (!file_extension || !ft_strbcmp(".cub", file_extension))
	{
		ft_printf(RED_LIGH "Error\n" DEF);
		ft_printf("Not a '.cub' file!\n");
		return (false);
	}
	return (true);
}
