/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:10:23 by pde-alme          #+#    #+#             */
/*   Updated: 2026/01/29 15:41:12 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Not part of the 42 curriculum. Same as "ft_strncmp" but for the entirety of
 * the "s1" string or until a character is different when comparing to "s2".
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	index;

	index = 0;
	while (s1[index] && s1[index] == s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "HELLO WORLD!";
	str2 = "HELLO WORLD!";
	printf("%i vs %i\n", strcmp(str1, str2), ft_strcmp(str1, str2));
	return (0);
}*/
