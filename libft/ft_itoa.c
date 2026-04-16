/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:38:09 by pde-alme          #+#    #+#             */
/*   Updated: 2025/04/26 16:35:52 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	decimal_places(int n)
{
	unsigned int	decimal_places;

	decimal_places = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			n = 2147483647;
		else
			n = n * -1;
	}
	while (n >= 10)
	{
		decimal_places++;
		n = n / 10;
	}
	return (decimal_places);
}

static char	*fill_string(int n, char *ptr, unsigned int index)
{
	long int	n_long;

	n_long = (long int)n;
	if (n_long < 0)
		n_long = n_long * -1;
	ptr[index--] = '\0';
	while (n_long >= 10)
	{
		ptr[index] = (n_long % 10) + 48;
		n_long = n_long / 10;
		index--;
	}
	ptr[index] = (n_long % 10) + 48;
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;

	if (n < 0)
		ptr = (char *)malloc((sizeof(char) * decimal_places(n)) + 2);
	else
		ptr = (char *)malloc((sizeof(char) * decimal_places(n)) + 1);
	if (ptr == NULL)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		ptr = fill_string(n, ptr, (decimal_places(n) + 1));
	}
	else
		ptr = fill_string(n, ptr, decimal_places(n));
	return (ptr);
}

/*int	main(void)
{
	printf("%s\n", ft_itoa(0));
	return (0);
}*/
