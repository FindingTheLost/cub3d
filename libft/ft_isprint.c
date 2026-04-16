/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:45:12 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 18:13:54 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

/*int	main(void)
{
	int	a;

	a = -10;
	while (a <= 300)
	{
		printf("%i - %i vs %i\n", a, isprint(a), ft_isprint(a));
		a++;
	}
	return (0);
}*/
