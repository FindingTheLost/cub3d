/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:23:39 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/01 16:24:01 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index++;
	}
	if (s[index] == (unsigned char)c)
		return ((char *)&s[index]);
	return (NULL);
}

/*int	main(void)
{
	char	*str;

	str = "A tua mae!";
	printf("%p vs %p\n", strchr(str, 65), ft_strchr(str, 65));
	return (0);
}*/
