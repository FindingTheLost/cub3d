/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:53:28 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 18:30:24 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

/*int	main(void)
{
	char	*s;

	s = "HELLO!";
	//s = NULL;
	printf("%lu vs %lu\n", strlen(s), ft_strlen(s));
	return (0);
}*/
