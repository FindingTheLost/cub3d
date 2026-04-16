/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:35:42 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/22 18:06:04 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}

/*int	main(void)
{
	int	a;

	a = 0;
	while (a <= 255)
	{
		printf("%i - %i vs %i\n", a, isalpha(a), ft_isalpha(a));
		a++;
	}
	return (0);
}*/
