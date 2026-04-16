/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:08:01 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 18:28:59 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	index;
	char			*converted;

	converted = s;
	index = 0;
	while (index < n)
	{
		converted[index] = c;
		index++;
	}
	return (s);
}

/*int	main(void)
{
	void	*ptr;
	void	*ptr2;
	
	ptr = malloc(100);
	ptr2 = malloc(100);
	//ptr = NULL;
	//ptr2 = NULL;
	memset(ptr, 122, 25);
	ft_memset(ptr2, 122, 25);
	printf("%s vs %s\n", (char *)(ptr), (char *)(ptr2));
	return (0);
}*/
