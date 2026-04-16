/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:41:29 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/01 20:42:45 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

static unsigned int	ft_strlen2(const char *str)
{
	unsigned int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	if (ft_strlen2(little) == 0)
		return ((char *)big);
	a = 0;
	while (a < len && big[a] != '\0')
	{
		b = 0;
		while (big[a + b] != '\0' && little[b] != '\0'
			&& big[a + b] == little[b] && (a + b) < len)
			b++;
		if (little[b] == '\0')
			return ((char *)&big[a]);
		a++;
	}
	return (NULL);
}

/*int	main(void)
{
	char str1[30] = "aaabcabcd";
	char str2[10] = "aabc";
	size_t size = 10;
	printf("%s vs %s\n", strnstr(str1, str2, size), 
		ft_strnstr(str1, str2, size));
	return (0);
}*/
