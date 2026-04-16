/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:27:04 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/23 15:44:29 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* If 'start' is above or equal to our string's length, 'len' becomes 0 to
 * create a string worthy of 'free()'. If 'len' is superior to the string
 * starting from the 'start' index, 'len' is assigned the string's size
 * to protect it from reading bytes in front of 'null' (if 'len' isn't
 * already 0). */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		index;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen((char *)s))
		len = 0;
	if (len != 0)
	{
		if (ft_strlen((char *)&s[start]) < len)
			len = ft_strlen((char *)&s[start]);
	}
	ptr = (char *)malloc((sizeof(char) * len) + 1);
	if (ptr == NULL)
		return (NULL);
	index = 0;
	while (len-- > 0)
		ptr[index++] = s[start++];
	ptr[index] = '\0';
	return (ptr);
}

/*int	main(void)
{
	char	*str;

	str = "HELLO";
	printf("Test: %s\n", ft_substr(str, 4, 5));
	return (0);
}*/
