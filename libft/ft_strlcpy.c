/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:45:31 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 19:00:21 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	index;
	unsigned int	length;

	index = 0;
	length = 0;
	while (src[length] != '\0')
		length++;
	if (size == 0)
		return (length);
	while ((index < (size - 1)) && (src[index] != '\0'))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (length);
}

/*int	main(void)
{
	unsigned int	size;
	char	*str1;
	char	*str2;
	char	strA[20];
	char	strB[20];

	size = 3;
	str1 = "Uma frase!";
	str2 = "Uma frase!";
	//str1 = NULL;
	//str2 = NULL;
	printf("%lu\n", ft_strlcpy(strA, str1, size));
	printf("%s\n", strA);
	printf("\n");
	printf("%lu\n", strlcpy(strB, str2, size));
	printf("%s\n", strB);
	return (0);
}*/
