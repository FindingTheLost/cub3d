/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:42:28 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/01 15:55:41 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*convert;
	unsigned int		index;

	convert = s;
	index = 0;
	while (index < n)
	{
		if (convert[index] == (unsigned char)c)
			return ((void *)&convert[index]);
		index++;
	}
	return (NULL);
}

/*int	main(void)
{
	char 	*str;

	str = malloc(10);
	str[0] = 'M';
	str[1] = 'y';
	str[2] = ' ';
	str[3] = 'P';
	str[4] = 'C';
	str[5] = '!';
	printf("%p vs %p", memchr(str, 121, 0), ft_memchr(str, 121, 0));
	return (0);
}*/
