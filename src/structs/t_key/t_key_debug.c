/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_key_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:54:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/06 20:55:59 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_key_struct.h"

void	t_key_debug(t_key *key)
{
	ft_printf(RED_BOLD "T_KEY STRUCT DEBUG:\n" DEF);
	ft_printf("Key up: %i\n", key->up);
	ft_printf("Key down: %i\n", key->down);
	ft_printf("Key left: %i\n", key->left);
	ft_printf("Key right: %i\n", key->right);
}
