/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:14:24 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/23 19:43:54 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

static size_t	ft_strlen2(char *str)
{
	unsigned int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	total;
	unsigned int	index;
	unsigned int	index2;

	if (size <= ft_strlen2(dst))
		return (size + ft_strlen2((char *)src));
	else
	{
		total = (ft_strlen2(dst) + ft_strlen2((char *)src));
		index = ft_strlen2(dst);
		index2 = 0;
		while ((index < (size - 1)) && src[index2] != '\0')
		{
			dst[index++] = src[index2++];
		}
		dst[index] = '\0';
		return (total);
	}
}

/*int	main(void)
{
	char	src[] = "Born to code";
	char	dst[] = "1337 42";
	unsigned int	num = 6;
	char	src2[] = "Born to code";
	char	dst2[] = "1337 42";

	printf("Test ft_strlcat:\n");
	printf("%lu\n", ft_strlcat(dst, src, num));
	printf("%s\n\n", dst);
	printf("Test strlcat:\n");
	printf("%lu\n", strlcat(dst2, src2, num));
	printf("%s\n", dst2);
	return (0);
}*/
