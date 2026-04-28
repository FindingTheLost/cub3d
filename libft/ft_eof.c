/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eof.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:40:07 by pde-alme          #+#    #+#             */
/*   Updated: 2026/04/28 00:44:01 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function that forces "get_next_line" to reach the end of a file descriptor
 * (EOF) to clear any remains of the contents of the file pointed to by "fd"
 * from "get_next_line"'s static buffer.
 */
void	ft_eof(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
