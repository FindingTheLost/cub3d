/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:57:33 by pde-alme          #+#    #+#             */
/*   Updated: 2026/01/29 17:44:39 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This file was previously named "get_next_line_bonus.c" and was changed to
 * fit the libft library naming scheme. It's "get_next_line" with bonus.
 */

/* FOPEN_MAX is a macro from 'stdio.h' to represent the maximum number of file
 * descriptors in any given program. This number can be changed in the
 * operating system. 
 * 
 * About file descriptors, three are already reserved for other operations:
 * 0 - Represents the standard input;
 * 1 - Represents the standard output;
 * 2 - Represents the standard error;
 * 
 * Since FOPEN_MAX holds the number 16 in this machine, 's_ptr' will create 16
 * arrays of size BUFFER_SIZE + 1, and thus, only 13 of these are eligible for
 * valid file descriptors (3 to 15). 
 *
 * Lastly, once you initialize an integer variable with a file descriptor
 * using 'read()', it will hold the number 3 for the first file descriptor
 * opened, and +1 to the last opened file descriptor for the next one. Ex:
 * file descriptors for a, b, c, d, e, f, g, h, i == 3, 4, 5, 6, 7, 8, 9, 10
 * , 11. */
char	*get_next_line(int fd)
{
	static char	s_ptr[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	ptr = gnl_get_string(fd, s_ptr[fd]);
	if (ptr == NULL)
		return (NULL);
	ptr = gnl_trim_string(s_ptr[fd], ptr);
	return (ptr);
}

/*int	main(int argc, char *argv[])
{
	int	fda;
	int	fdb;
	char	*ptr;

	if (argc != 3)
	{
		write(1, "Wrong number of arguments!\n", 27);
		return (0);
	}
	fda = open(argv[1], O_RDONLY);
	fdb = open(argv[2], O_RDONLY);
	ptr = get_next_line(fda);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fdb);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fda);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fdb);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fda);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fdb);
	printf("%s", ptr);
	free(ptr);
	return (0);
}*/
