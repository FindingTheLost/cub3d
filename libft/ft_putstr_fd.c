/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:31:22 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/23 18:41:56 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	index;

	if (s == NULL)
		return ;
	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
}

/*int	main(int argc, char *argv[])
{
	int     fd;
	int     count;

	if (argc != 2)
	{
		if (argc < 2)
			write(1, "File name is missing.\n", 21);
		else
			write(1, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	ft_putstr_fd("HAHAHAH A TUA MAE!", fd);
	close(fd);
	return (0);
}*/
