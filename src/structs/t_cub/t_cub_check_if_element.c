/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_check_if_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:52:06 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/29 18:20:38 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_cub_struct.h"

int	t_cub_check_if_element(char *line)
{
	if (ft_strlen(line) >= 2)
	{
		if (line[0] == 'N' && line[1] == 'O')
			return (1);
		if (line[0] == 'S' && line[1] == 'O')
			return (1);
		if (line[0] == 'W' && line[1] == 'E')
			return (1);
		if (line[0] == 'E' && line[1] == 'A')
			return (1);
		if (line[0] == 'F' || line[0] == 'C')
			return (1);
	}
	return (0);
}
