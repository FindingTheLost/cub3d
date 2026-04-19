/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_file_extension.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:09:27 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/18 20:28:03 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	parse_input_file_extension(char **argv)
{
	char	*file_extension;

	file_extension = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
	if (!file_extension)
	{
		write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
		write(STDOUT_FILENO, "Not a '.cub' file!\n", 19);
		return (false);
	}
	if (!ft_strbcmp(".cub", file_extension))
	{
		write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
		write(STDOUT_FILENO, "Not a '.cub' file!\n", 19);
		return (false);
	}
	return (true);
}
