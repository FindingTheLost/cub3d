/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:49:06 by pde-alme          #+#    #+#             */
/*   Updated: 2026/01/29 17:42:21 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function that receives an unsigned int and converts it to lower case
 * hexadecimal, then writes it on screen using 'pf_write()'.
 * Returns the number of letters written.
 */
int	pf_lohex(unsigned int num)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (num >= 16)
		count += pf_lohex(num / 16);
	count += pf_write(base[num % 16]);
	return (count);
}

/* Function that receives an unsigned int and converts it to upper case
 * hexadecimal, then writes it on screen using 'pf_write()'.
 * Returns the number of letters written.
 */
int	pf_uphex(unsigned int num)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (num >= 16)
		count += pf_uphex(num / 16);
	count += pf_write(base[num % 16]);
	return (count);
}

/* I have tried simply using pf_lohex() but there were errors in the return
 * where the memory address returned incomplete. Apparently pf_lohex()
 * cannot be used to represent memory void pointers due to requiring
 * an unsigned int parameter (which loses data). So this function
 * had to be made to be able to hold such a large number as an argument.
 * Also 'size_t' comes to mind but the standard int library 'stdint.h' has
 * a type specifically for converting void pointers to int, wether signed
 * or unsigned, with 'intptr_t' and 'uintptr_t'.
 */
static int	pf_lohex_mem(uintptr_t num)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (num >= 16)
		count += pf_lohex_mem(num / 16);
	count += pf_write(base[num % 16]);
	return (count);
}

/* 'uintptr_t' is a type from 'stdint.h' that makes it reliable and safe
 * to convert void pointers to an integer type. There is also 'intptr_t'.
 * But why these instead of 'size_t'? Apparently, 'size_t' is limited
 * in range compared to 'uintptr_t'. Both have their uses. 'size_t' is
 * more suitable for accessing array indexes, whereas 'uintptr_t' is
 * better for memory convertion due to its larger range. 
 * If the memory pointer is null, it should write (nil) to the screen
 * and count the number of letters of the string literal '(nil)'.
 */
int	pf_memadd(void *mem)
{
	int	count;

	if (mem == NULL)
		return (pf_str("(nil)"));
	count = 0;
	count += pf_write('0');
	count += pf_write('x');
	count += pf_lohex_mem((uintptr_t)mem);
	return (count);
}
