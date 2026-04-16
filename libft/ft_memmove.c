/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:51:16 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 18:52:19 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	index;
	char			*dest_conv;
	char			*src_conv;

	index = 0;
	dest_conv = dest;
	src_conv = (char *)src;
	if (dest <= src)
	{
		while (index < n)
		{
			dest_conv[index] = src_conv[index];
			index++;
		}
	}
	else
	{
		while (n > index)
		{
			dest_conv[n - 1] = src_conv[n - 1];
			n--;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	*dest;
	char	*src;

	dest = malloc(7);
	src = malloc(7);
	src[0] = 'L';
	src[1] = 'i';
	src[2] = 's';
	src[3] = 'b';
	src[4] = 'o';
	src[5] = 'a';
	src[6] = '!';
	printf("%s\n", (char *)ft_memmove(dest, src, 7));
	return (0);
}*/
