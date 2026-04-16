/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:01:17 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/23 20:17:02 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	index;
	char			*ptr;

	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen((char *)s);
	index = 0;
	ptr = (char *)malloc((sizeof(char) * size) + 1);
	if (ptr == NULL)
		return (NULL);
	while (index < size)
	{
		ptr[index] = f(index, s[index]);
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}

/*char	f(unsigned int index, char c)
{
	return (c + index);
}

int	main(void)
{
	printf("%s\n", ft_strmapi("HELLO", &f));
	return (0);
}*/
