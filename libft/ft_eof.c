/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eof.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 00:40:07 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 00:51:21 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function that forces "get_next_line" to reach the end of a file descriptor
 * (EOF) to clear any remains of the contents of the file pointed to by "fd"
 * from "get_next_line"'s static buffer.
 * Note that "fd" is an already opened file descriptor.
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
