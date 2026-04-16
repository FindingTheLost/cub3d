/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:00:52 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 18:09:35 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

/*int	main(void)
{
	int	a;

	a = 0;
	while (a <= 255)
	{
		printf("%i - %i vs %i\n", a, isdigit(a), ft_isdigit(a));
		a++;
	}
	return (0);
}*/
