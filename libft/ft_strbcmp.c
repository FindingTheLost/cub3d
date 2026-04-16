/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:35:41 by pde-alme          #+#    #+#             */
/*   Updated: 2026/01/29 16:39:11 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Compares two strings and returns a boolean value - "true" if both strings
 * contain the same characters up to "\0", "false" if either one or both strings
 * are "NULL" or if a character is not the same.
 * (not part of the 42 curriculum)
 */
int	ft_strbcmp(const char *s1, const char *s2)
{
	size_t	index;

	if (!s1 || !s2)
		return (false);
	index = 0;
	while (s1[index] && s1[index] == s2[index])
		index++;
	if (s1[index] != s2[index])
		return (false);
	return (true);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "Hello World!";
	str2 = "Hello World!";
	printf("%i\n", ft_strbcmp(str1, str2));
	return (0);
}*/
