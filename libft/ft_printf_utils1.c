/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:04:10 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/01 00:30:06 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* All of the function parameter types are in accordance to 'man 3 printf'. */

/* Function that receives an unsigned char, writes the char to the screen with
 * 'write()' and returns 1. The function 'write()' always returns the number
 * of characters written or -1 if it encounters an error.
 */
int	pf_write(unsigned char letter)
{
	return (write(STDOUT_FILENO, &letter, 1));
}

/* Function that receives an integer as parameter, and, similarly to
 * 'ft_putnbr.c', writes each decimal house of the number from first
 * to last digit using 'pf_write()'. Returns the number of decimal houses 
 * written to the screen.
 */
int	pf_int(int num)
{
	int	houses;

	houses = 0;
	if (num < 0)
	{
		pf_write('-');
		if (num == -2147483648)
		{
			pf_write('2');
			num = 147483648;
			houses++;
		}
		else
			num = num * -1;
		houses++;
	}
	if (num >= 10)
		houses += pf_int(num / 10);
	houses += pf_write((char)((num % 10) + 48));
	return (houses);
}

/* Function whose purpose is to return a -1 whenever a number is inferior
 * to 0. Returns the number passed as parameter or -1.
 */
int	pf_ucheck(int total)
{
	if (total < 0)
		return (-1);
	return (total);
}

/* Function that receives an unsigned int as parameter, writes it to the
 * screen from first to last digit using 'pf_write()' and returns the
 * number of decimal houses written.
 */
int	pf_uint(unsigned int num)
{
	int	houses;

	houses = 0;
	if (num >= 10)
		houses += pf_uint(num / 10);
	houses += pf_write((char)((num % 10) + 48));
	return (houses);
}

/* Function that receives a constant char pointer as parameter, writes
 * each char of the string to the screen using 'pf_write()' and returns
 * the number of letters written.
 * If the char pointer is null, it should display (null) to the screen
 * and count every character from the string literal '(null)'.
 */
int	pf_str(const char *str)
{
	int	index;

	index = 0;
	if (str == NULL)
		return (pf_str("(null)"));
	while (str[index] != '\0')
	{
		pf_write(str[index]);
		index++;
	}
	return (index);
}
