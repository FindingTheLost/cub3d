/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:15:06 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/23 18:12:05 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	size;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return ;
	size = ft_strlen(s);
	index = 0;
	while (index < size)
	{
		f(index, &s[index]);
		index++;
	}
}

/*void	f(unsigned int index, char *address)
{
	printf("%i - %p\n", index, address);
}

int	main(void)
{
	ft_striteri("OLA!", &f);
	return (0);
}*/
