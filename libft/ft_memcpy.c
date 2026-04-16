/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:48:27 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/03 16:45:01 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	index;
	const char		*src_conv;
	char			*dest_conv;

	dest_conv = dest;
	src_conv = src;
	index = 0;
	while (index < n)
	{
		dest_conv[index] = src_conv[index];
		index++;
	}
	return (dest);
}

/*int	main(void)
{
	char	*string1;
	char	*string2;
	void	*ptr1;
	void	*ptr2;

	string1 = malloc(4);
	string2 = malloc(4);
	string1[0] = 'H';
	string1[1] = 'E';
	string1[2] = 'L';
	string1[3] = 'L';
	ptr1 = string1;
	ptr2 = string2;
	//ptr1 = NULL;
	//ptr2 = NULL;
	printf("%s\n", (char *)(ft_memcpy(ptr2, ptr1, 4)));
	return (0);
}*/
