/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_argc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:09:20 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 00:48:37 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	parse_input_argc(int argc)
{
	if (argc != 2)
	{
		if (argc < 2)
		{
			ft_printf(RED_LIGH "Error\n" DEF);
			ft_printf("Too few arguments were given!\n");
		}
		else
		{
			ft_printf(RED_LIGH "Error\n" DEF);
			ft_printf("Too many arguments were given!\n");
		}
		return (false);
	}
	return (true);
}
