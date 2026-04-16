/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:13:08 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 19:37:39 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;
	unsigned int	n2;

	if (n == 0)
		return (0);
	index = 0;
	n2 = 1;
	while ((s1[index] != '\0') && (s1[index] == s2[index]) && (n2 < n))
	{
		index++;
		n2++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "HELLO WORLD!";
	str2 = "HELLO WORLD!";
	printf("%i vs %i\n", strncmp(str1, str2, 3), ft_strncmp(str1, str2, 3));
	return (0);
}*/
