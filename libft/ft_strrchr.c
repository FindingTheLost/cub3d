/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:01:17 by pde-alme          #+#    #+#             */
/*   Updated: 2025/05/01 16:26:57 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	while (index != 0)
	{
		if (s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index--;
	}
	if (s[index] == (unsigned char)c)
		return ((char *)&s[index]);
	return (NULL);
}

/*int	main(void)
{
	char	*str;

	str = "XExample sentencE";
	printf("%p vs %p", strrchr(str, 32), ft_strrchr(str, 32));
	return (0);
}*/
