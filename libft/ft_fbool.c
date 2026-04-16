/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fbool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:25:11 by pde-alme          #+#    #+#             */
/*   Updated: 2026/01/29 16:29:32 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Not part of the 42 curriculum. Returns the opposite value of a boolean
 * integer passed as an argument.
 */
int	ft_fbool(int boolean)
{
	if (boolean)
		return (false);
	else
		return (true);
}

/* Variables 'a' and 'b' can also hold the macros "TRUE" and "FALSE".
 */
/*int	main(void)
{
	int	a;
	int	b;

	a = true;
	b = false;
	a = ft_fbool(a);
	b = ft_fbool(b);
	if (a)
		printf("Variable 'a' is true.\n");
	else
		printf("Variable 'a' is false.\n");
	if (b)
		printf("Variable 'b' is true.\n");
	else
		printf("Variable 'b' is false.\n");
	return (0);
}*/
