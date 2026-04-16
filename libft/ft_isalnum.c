/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:15:41 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 18:10:57 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (8);
	return (0);
}

/*int	main(void)
{
	int	a;

	a = 0;
	while (a <= 255)
	{
		printf("%i - %i vs %i\n", a, isalnum(a), ft_isalnum(a));
		a++;
	}
	return (0);
}*/
