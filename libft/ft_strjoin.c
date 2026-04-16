/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:41:03 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/23 15:48:30 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	index;
	unsigned int	index_s;
	char			*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (ptr == NULL)
		return (NULL);
	index_s = 0;
	index = 0;
	while (s1[index] != '\0')
		ptr[index_s++] = s1[index++];
	index = 0;
	while (s2[index] != '\0')
		ptr[index_s++] = s2[index++];
	ptr[index_s] = '\0';
	return (ptr);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "My PC ha";
	str2 = "s fried!";
	printf("%s + %s -> %s\n", str1, str2, ft_strjoin(str1, str2));
	return (0);
}*/
