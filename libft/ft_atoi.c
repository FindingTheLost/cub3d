/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:24:38 by pde-alme          #+#    #+#             */
/*   Updated: 2026/02/13 00:23:24 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Already protected against 18446744071562067968 which overflows the "integer"
 * as well as the "long" types that makes both fall into the same number for,
 * at least, "UNSIGNED_INT_MAX" times from there up. This of course, if the
 * user retrieves the atoi number and stores it in a long type to compare
 * against the same number to int.
 */
int	ft_atoi(const char *nptr)
{
	size_t	index;
	size_t	limit;
	int		result;
	int		negative;

	index = 0;
	result = 0;
	negative = false;
	while ((nptr[index] == ' ') || (nptr[index] >= 9 && nptr[index] <= 13))
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index++] == '-')
			negative = true;
	}
	limit = index + 12;
	while (nptr[index] >= '0' && nptr[index] <= '9' && index < limit)
	{
		result = result * 10;
		result = result + (int)(nptr[index] - 48);
		index++;
	}
	if (negative)
		return (-result);
	return (result);
}

/*int	main(void)
{
	char	*str;

	str = " \n \r \t \v \f  22147483648ola";
	str = "2147483647";
	str = "2147483648";
	str = "-2147483648";
	str = "-2147483649";
	str = "18446744071562067968";
	printf("%i vs %i\n", atoi(str), ft_atoi(str));
	return (0);
}*/
