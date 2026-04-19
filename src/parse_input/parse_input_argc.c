/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_argc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:09:20 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/18 20:28:35 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	parse_input_argc(int argc)
{
	if (argc != 2)
	{
		if (argc < 2)
		{
			write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
			write(STDOUT_FILENO, "Too few arguments were given!\n", 30);
		}
		else
		{
			write(STDOUT_FILENO, "\033[91mError\n\033[0m", 15);
			write(STDOUT_FILENO, "Too many arguments were given!\n", 31);
		}
		return (false);
	}
	return (true);
}
