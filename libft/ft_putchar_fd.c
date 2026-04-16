/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:29:06 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/23 18:32:41 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int	main(int argc, char *argv[])
{
	int	fd;
	int	count;

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
	count = 30;
	while (count != 0)
	{
		ft_putchar_fd('T', fd);
		count--;
	}
	close(fd);
	return (0);
}*/
