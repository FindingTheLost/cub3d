/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:42:33 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 18:33:00 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	index;
	char			*converted;

	converted = s;
	index = 0;
	while (index < n)
	{
		converted[index] = '\0';
		index++;
	}
}

/*int	main(void)
{
	char	*ptr;
	int	index;

	ptr = malloc(10);
	ptr[0] = 'A';
	ptr[1] = ' ';
	ptr[2] = 't';
	ptr[3] = 'u';
	ptr[4] = 'a';
	ptr[5] = ' ';
	ptr[6] = 'm';
	ptr[7] = 'a';
	ptr[8] = 'e';
	ptr[9] = '!';
	//ptr = NULL;
	ft_bzero((void *)ptr, 5);
	index = 0;
	while (index < 10)
	{
		printf("%c", ptr[index]);
		index++;
	}
	printf("\n");

}*/
