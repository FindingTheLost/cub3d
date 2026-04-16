/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:10:42 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/23 19:44:46 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen2(char *str)
{
	unsigned int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strdup(const char *s)
{
	unsigned int	index;
	char			*ptr;

	ptr = (char *)malloc((sizeof(char) * ft_strlen2((char *)s)) + 1);
	if (ptr == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		ptr[index] = s[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}

/*int	main(void)
{
	char	*str;

	str = "This is my sentence!";
	//str = NULL;
	printf("%s vs %s\n", strdup(str), ft_strdup(str));
	return (0);
}*/
