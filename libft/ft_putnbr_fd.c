/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:37:34 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/23 19:03:56 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	number;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2", 2);
			n = 147483648;
		}
		else
		{
			write(fd, "-", 1);
			n = n * -1;
		}
	}
	if (n >= 10)
		ft_putnbr_fd((n / 10), fd);
	number = (n % 10) + 48;
	write(fd, &number, 1);
}

/*int	main(int argc, char *argv[])
{
	int	fd;

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
	ft_putnbr_fd(-2147483649, fd);
	close(fd);
	return (0);
}*/
