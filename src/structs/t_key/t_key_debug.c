/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_key_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:54:39 by pde-alme          #+#    #+#             */
/*   Updated: 2026/05/29 02:58:26 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../t_key_struct.h"

void	t_key_debug(t_key *key)
{
	ft_printf(RED_BOLD "T_KEY STRUCT DEBUG:\n" DEF);
	ft_printf("Key W: %i\n", key->w);
	ft_printf("Key S: %i\n", key->s);
	ft_printf("Key A: %i\n", key->a);
	ft_printf("Key D: %i\n", key->d);
	ft_printf("Key M: %i\n", key->m);
	ft_printf("Key E: %i\n", key->e);
	ft_printf("Key LEFT: %i\n", key->left);
	ft_printf("Key RIGHT: %i\n", key->right);
	ft_printf("Key CTRL: %i\n", key->ctrl);
	ft_printf("Key SPACE: %i\n", key->space);
	ft_printf("Key SHIFT: %i\n", key->shift);
}
