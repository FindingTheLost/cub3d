/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:22:00 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/03 16:59:22 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	index;
	char			*ptr;

	if (nmemb < 1 || size < 1)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if ((SIZE_MAX / size) < nmemb)
		return (NULL);
	else
	{
		ptr = malloc(nmemb * size);
		if (ptr == NULL)
			return (NULL);
		index = 0;
		while (index < (nmemb * size))
		{
			ptr[index] = '\0';
			index++;
		}
		return ((void *)ptr);
	}
}

/*int	main(void)
{
	printf("%s vs %s\n", (char *)calloc(0, 0), (char *)ft_calloc(0, 0));
	return (0);
}*/
