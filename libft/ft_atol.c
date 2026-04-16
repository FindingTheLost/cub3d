/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 23:31:14 by pde-alme          #+#    #+#             */
/*   Updated: 2026/02/13 00:31:58 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Already protected against 18446744071562067968 which overflows the "integer"
 * as well as the "long" types that makes both fall into the same number for,
 * at least, "UNSIGNED_INT_MAX" times from there up. This of course, if the
 * user retrieves the atoi number and stores it in a long type to compare
 * against the same number to int.
 */
long	ft_atol(const char *nptr)
{
	size_t	index;
	size_t	limit;
	long	result;
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
	limit = index + 19;
	while (nptr[index] >= '0' && nptr[index] <= '9' && index < limit)
	{
		result *= 10;
		result += (long)(nptr[index] - 48);
		index++;
	}
	if (negative)
		return (-result);
	return (result);
}

/* To see both overflowing, increase the "limit = index + 19" from 19 to 20 and
 * run "main".
 */
/*int	main(void)
{
	char	*str;
	long	long_number;
	int	int_number;

	str = "9223372036854775807";
	str = " \n \r \t \v \f 18446744071562067968ola";
	long_number = ft_atol(str);
	int_number = (int)long_number;
	printf("%li vs %li\n", atol(str), ft_atol(str));
	printf("Long: %li - Int: %i\n", long_number, int_number);
	return (0);
}*/
