/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:18:32 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/01 16:14:31 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_conv;
	const unsigned char	*s2_conv;
	unsigned int		index;

	if (n == 0)
		return (0);
	s1_conv = s1;
	s2_conv = s2;
	index = 0;
	while (index < n)
	{
		if (s1_conv[index] != s2_conv[index])
			return (s1_conv[index] - s2_conv[index]);
		index++;
	}
	return (0);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = malloc(5);
	str2 = malloc(5);
	str1[0] = 'H';
	str1[1] = 'E';
	str1[2] = 'L';
	str1[3] = 'L';
	str1[4] = 'O';
	str2[0] = 'H';
	str2[1] = 'E';
	str2[2] = 'L';
	str2[3] = 'L';
	str2[4] = 'O';
	printf("%i vs %i", memcmp(str1, str2, 3), ft_memcmp(str1, str2, 3));
	return (0);
}*/
